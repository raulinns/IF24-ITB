module ColumnOperations where

konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

-- REALISASI
konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l

-- Lengkapi Fungsi di bawah ini
columnOperations :: [[Int]] -> [Int]
columnOperations li =
    let
        maxL = maximum (map head li)
        minL = minimum (map head (map tail li))
        sumL = sum (map head (map tail (map tail li)))
     in
        if null li then
            []
        else
            if null (head li) then
                []
            else
                if length (head li) == 1 then
                    [maxL]
                else
                    if length (head li) == 2 then
                        [maxL] ++ [minL]
                    else
                        [maxL] ++ [minL] ++ [sumL] ++ columnOperations (map tail (map tail (map tail li)))
