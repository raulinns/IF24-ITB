module ConditionalChain where

-- Deskripsi:
-- Fungsi `conditionalChain` menerima sebuah pasangan aturan yang terdiri dari
-- kondisi dan fungsi transformasi, serta sebuah list (bisa kosong).
-- Setiap elemen pada list akan dicek terhadap kondisi tersebut.
-- Jika elemen memenuhi kondisi, maka elemen tersebut akan diubah
-- menggunakan fungsi transformasi. Jika tidak, elemen dibiarkan tetap.

-- Contoh:
-- conditionalChain ((\x -> x < 0), (\x -> x - 1)) [-2, 0, 4] => [-3, 0, 4]

conditionalChain :: (a -> Bool, a -> a) -> [a] -> [a]
conditionalChain (fb, fx) li =
    if null li then
        []
    else if fb (head li) then
        [fx (head li)] ++ (conditionalChain (fb, fx) (tail li))
    else 
        [head li] ++ (conditionalChain ((fb, fx)) (tail li))

-- TODO
-- Note: Dilarang menggunakan map