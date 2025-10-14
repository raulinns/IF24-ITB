module Test where

plus2 = (+ 2)

offsetList :: [Int] -> (Int -> Int) -> [Int]
offsetList li f =
    if null li then
        []
    else
        f (head li) : offsetList (tail li) f

sigma :: Int -> Int -> (Int -> Float) -> (Int -> Int) -> Float
sigma a b f s =
    if a > b then
        0
    else
        f (fromIntegral a) + sigma (s a) b f s

evenF = (\x -> (mod x 2) == 0)
oddF = (\x -> (mod x 2) /= 0)

sumEvenOdd :: [Int] -> (Int -> Bool) -> Int
sumEvenOdd li f
  | null li = 0
  | f (head li) = 1 + sumEvenOdd (tail li) f
  | otherwise = sumEvenOdd (tail li) f

isPrime :: Int -> Bool
isPrime n
    | n <= 1 = False
    | n == 2 = True
    | mod n 2 == 0 = False
    | otherwise = isDiv n 3

isDiv :: Int -> Int -> Bool
isDiv n i
  | i * i > n = True
  | mod n i == 0 = False
  | otherwise = isDiv n (i + 1)

filterPrime :: [Int] -> (Int -> Bool) -> [Int]
filterPrime li f
  | null li = []
  | f (head li) = [head li] ++ filterPrime (tail li) f
  | otherwise = filterPrime (tail li) f

isPrimeSimple :: Int -> Bool
isPrimeSimple k = length [ x | x <- [2..(k-1)], (mod k x) == 0] == 0
