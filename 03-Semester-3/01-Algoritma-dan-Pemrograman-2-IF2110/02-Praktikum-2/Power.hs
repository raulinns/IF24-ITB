module Power where

-- isPowerOf n base bernilai True jika n = base ^ k
-- dengan n dan base adalah bilangan asli
-- dan k adalah bilangan bulat nonnegatif
-- contoh: isPowerOf 27 3 = True (3^3 = 27)
-- contoh: isPowerOf 1 5 = True (5^0 = 1)
-- contoh: isPowerOf 5 10 = False

-- DEFINISI DAN SPESIFIKASI UTAMA
isPowerOf :: Int -> Int -> Bool
isPowerOf n base
  | n == 1 = True
  | mod n base /= 0 || n < 1 = False
  | otherwise = isPowerOf (div n base) base

