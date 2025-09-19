module SecondLargest where

largestInt::[Int] -> Int
largestInt l =
    if length l == 1 then
        head l
    else max (head l) (largestInt (tail l))

deleteNum::Int -> [Int] -> [Int]
deleteNum n l
  | null l = []
  | head l == n = deleteNum n (tail l)
  | otherwise = [head l] ++ deleteNum n (tail l)

secondLargest::[Int] -> Int
secondLargest l = largestInt (deleteNum (largestInt l) l)
