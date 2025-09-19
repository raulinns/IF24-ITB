module RunLengthEncoding where

countSameChar:: String -> Int
countSameChar s
    | null s = 0
    | length s == 1 = 1
    | head s /= head (tail s) = 1
    | otherwise = 1 + countSameChar (tail s)

generateTuple:: String -> (Char, Int)
generateTuple s =
    if length s == 1 then
        (head s, 1)
    else 
        (head s, countSameChar s)

runLengthEncoding:: String -> [(Char, Int)]
runLengthEncoding s
    | null s = []
    | length s == 1 = [(head s, 1)]
    | otherwise = [generateTuple s] ++ runLengthEncoding (drop (countSameChar s) s)

