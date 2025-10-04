module CountOccurrence where

-- count(ListOfList, n) menghitung berapa kali integer n muncul di dalam sebuah list of list.
-- CONTOH: count [[1,2,1],[3],[1,4]] 1 menghasilkan 3
count :: [[Int]] -> Int -> Int
-- TODO : implementasi fungsi count
count li n =
    let
        a = [drop 1 (head li)] ++ drop 1 li
     in
        if null li then
            0
        else
            if null (head li) then
                count (tail li) n
            else
                if head (head li) == n then
                    1 + count a n
                else
                    count a n
