module Tanggal where

-- TYPE TANGGAL
-- DEFINISI TYPE
-- type tanggal: <h: Int, b: Int, t: Int>
-- {<h,b,t> adalah sebuah tanggal dengan h adalah hari, b adalah bulan (1..12), t adalah tahun}

-- DESKRIPSI SOAL
-- Implementasikan modul Tanggal dengan fungsi utama isValid untuk memvalidasi
-- tanggal pada kalender Gregorian.
--
-- ATURAN KALENDER GREGORIAN (KABISAT)
-- - Suatu tahun adalah tahun kabisat jika dan hanya jika:
--   * tahun habis dibagi 400, ATAU
--   * tahun habis dibagi 4 tetapi TIDAK habis dibagi 100.
-- - Dampak ke Februari:
--   * Februari memiliki 29 hari pada tahun kabisat.
--   * Selain itu, Februari memiliki 28 hari.
--
-- JUMLAH HARI PER BULAN
-- - 31 hari: 1, 3, 5, 7, 8, 10, 12
-- - 30 hari: 4, 6, 9, 11
-- - 28/29 hari: 2 (Februari, sesuai aturan kabisat di atas)
--
-- KETENTUAN VALIDASI
-- - Tahun minimal 1 (tahun >= 1)
-- - Bulan berada pada rentang 1..12
-- - Hari berada pada rentang 1..(hariDalamBulan(bulan,tahun))

data Tanggal = Tanggal Int Int Int
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- hari: tanggal -> Int
-- {hari(T) memberikan hari dari tanggal T}
hari :: Tanggal -> Int
hari (Tanggal d _ _) = d

-- bulan: tanggal -> Int
-- {bulan(T) memberikan bulan dari tanggal T}
bulan :: Tanggal -> Int
bulan (Tanggal _ m _) = m

-- tahun: tanggal -> Int
-- {tahun(T) memberikan tahun dari tanggal T}
tahun :: Tanggal -> Int
tahun (Tanggal _ _ y) = y
-- TODO

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makeTanggal: 3 Int -> tanggal
-- {makeTanggal(h,b,t) membentuk sebuah tanggal dari hari h, bulan b, dan tahun t}
makeTanggal :: Int -> Int -> Int -> Tanggal
makeTanggal d m y = Tanggal d m y

-- DEFINISI DAN SPESIFIKASI PREDIKAT & FUNGSI BANTU
-- isKabisat: Int -> Bool
-- {isKabisat(t) benar jika t adalah tahun kabisat menurut aturan Gregorian}
isKabisat :: Int -> Bool
isKabisat y = (mod y 4 == 0 && mod y 100 /= 0) || (mod y  400 == 0)

-- hariDalamBulan: Int -> Int -> Int
-- {hariDalamBulan(b,t) memberikan jumlah hari pada bulan b di tahun t}
hariDalamBulan :: Int -> Int -> Int
hariDalamBulan m y = if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) then 31 else if (m == 4 || m == 6 || m == 9 || m == 11) then 30 else if (isKabisat y) then 29 else 28

-- isValid: tanggal -> Bool
-- {isValid(T) benar jika T adalah tanggal valid:
--  tahun >= 1, 1 <= bulan <= 12, 1 <= hari <= hariDalamBulan(bulan,tahun)}
isValid :: Tanggal -> Bool
isValid t = tahun(t) >= 1 && (1 <= bulan(t) && bulan(t) >= 12) && (1 <= hari(t) && hari(t) >= hariDalamBulan (bulan t) (tahun t))

