module SumDeepestLeaves where

data BinTree a = Empty | Node a (BinTree a) (BinTree a)
  deriving (Show, Eq)

-- KONSTRUKTOR
-- Definisi dan Spesifikasi utama
makeBinTree :: Int -> (BinTree Int) -> (BinTree Int) -> (BinTree Int)
-- Realisasi
makeBinTree a l r = Node a l r

-- SELEKTOR
-- Definisi dan Spesifikasi utama
akar  :: BinTree Int -> Int
left  :: BinTree Int -> BinTree Int
right :: BinTree Int -> BinTree Int

-- Realisasi
akar Empty          = error "akar: pohon kosong tidak punya akar"
akar (Node v _ _)   = v

left Empty          = error "left: pohon kosong tidak punya subpohon kiri"
left (Node _ l _)   = l

right Empty         = error "right: pohon kosong tidak punya subpohon kanan"
right (Node _ _ r)  = r

-- PREDIKAT
-- Definisi dan Spesifikasi utama
isTreeEmpty  :: BinTree a -> Bool
isOneElmt    :: BinTree a -> Bool    
isExistLeft  :: BinTree a -> Bool
isExistRight :: BinTree a -> Bool
isUnerLeft   :: BinTree a -> Bool    
isUnerRight  :: BinTree a -> Bool     
isBiner      :: BinTree a -> Bool     

-- Realisasi
isTreeEmpty Empty                = True
isTreeEmpty _                    = False

isOneElmt (Node _ Empty Empty)   = True
isOneElmt _                      = False

isExistLeft (Node _ l _)         = not (isTreeEmpty l)
isExistLeft _                    = False

isExistRight (Node _ _ r)        = not (isTreeEmpty r)
isExistRight _                   = False

isUnerLeft (Node _ l r)          = not (isTreeEmpty l) && isTreeEmpty r
isUnerLeft _                     = False

isUnerRight (Node _ l r)         = isTreeEmpty l && not (isTreeEmpty r)
isUnerRight _                    = False

isBiner (Node _ l r)             = not (isTreeEmpty l) && not (isTreeEmpty r)
isBiner _                        = False

-- FUNGSI HELPER LEVELS
atLevel :: Int -> (BinTree Int) -> [Int]
atLevel l t =
    if l == 1 then
        [akar t]
    else if isExistLeft t && isExistRight t then
        atLevel (l - 1) (left t) ++ atLevel (l - 1) (right t)
        else if isExistRight t && not (isExistLeft t) then
            atLevel (l - 1) (right t)
            else if not (isExistRight t) && isExistLeft t then
                atLevel (l - 1) (left t)
                else
                    []

depth :: BinTree Int -> Int
depth t =
    if isTreeEmpty t then
        0
    else if isOneElmt t then
        1
        else
            1 + max (depth (right t)) (depth (left t))

-- DEFINISI DAN SPESIFIKASI UTAMA
-- sumDeepestLeaves :: (BinTree Int) -> Int
-- { sumDeepestLeaves(t) mengembalikan jumlah nilai semua daun yang berada
--   pada kedalaman (level) maksimum dari pohon biner t. }
sumDeepestLeaves :: (BinTree Int) -> Int
sumDeepestLeaves t =
    let
        deepest = depth t
    in
        sum (atLevel deepest t)
    

-- TODO: Implementasikan fungsi sumDeepestLeaves secara rekursif

-- CONTOH APLIKASI FUNGSI
-- ghci> let tree1 = Node 1 (Node 2 (Node 4 (Node 7 Empty Empty) Empty) (Node 5 Empty Empty)) (Node 3 Empty (Node 6 Empty (Node 8 Empty Empty)))
-- ghci> sumDeepestLeaves tree1
-- 15
--    Penjelasan tree1:
--        1      <- level 1
--       / \
--      2   3    <- level 2
--     / \   \
--    4   5   6  <- level 3
--   /         \
--  7           8 <- level 4 (daun terdalam)
--  Daun terdalam: [7, 8], jumlah = 7 + 8 = 15

-- ghci> let tree2 = Node 6 (Node 7 (Node 2 (Node 9 Empty Empty) Empty) (Node 7 (Node 1 Empty Empty) (Node 4 Empty Empty))) (Node 8 (Node 1 Empty Empty) (Node 3 Empty (Node 5 Empty Empty)))
-- ghci> sumDeepestLeaves tree2
-- 19
--    Penjelasan tree2:
--        6      <- level 1
--       / \
--      7   8    <- level 2
--     / \ / \
--    2  7 1  3  <- level 3
--   /  / \    \
--  9  1   4    5 <- level 4 (daun terdalam)
--  Daun terdalam: [9, 1, 4, 5], jumlah = 9 + 1 + 4 + 5 = 19