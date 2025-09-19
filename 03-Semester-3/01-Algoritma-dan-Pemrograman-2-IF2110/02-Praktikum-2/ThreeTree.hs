module ThreeTree where

threeTree::[Int] -> [Int]
threeTree li =
    if null li == True then
        []
    else if (mod (head li) 3) == 0 then
        [head li] ++ threeTree (tail li)
    else
        threeTree (tail li)
        