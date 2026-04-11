Ada beberapa jenis tipe bentukan tergantung implementasinya:
1. Tipe yang memberikan nama baru atau membatasi domain tipe lain.
		**type** bilbulat: **integer** { Memberikan nama baru pada sebuah tipe }
		**type** IntPost: **integer** > 0 { Membatasi domain integer positif dengan > 0}
2. Tipe yang terdiri atas komponen bertipe lain
		**type** Point: \<x: integer, y: integer\>
3. Tipe bentukan tanpa nama. Domain atau range dari sebuah fungsi.
		HHMMDD: **integer**\[0..99999\] -> \<**integer** >= 0, **integer**\[0..23\], **integer** \[0..59], **integer**\[0..59\]

Dalam konteks fungsional, mendefinisikan sebuah tipe adalah mendefinisikan:
- Nama dan struktur tipe (komponen-komponennya)
- Selektor (Mengakses komponen tipe)
- Konstruktor (Membentuk tipe)
- Predikat (Menentukan karakteristik dan pemeriksaan besaran)
- Fungsi-fungsi lain

Contoh definisi tipe adalah:

![[Pasted image 20250920045950.png]]

![[Pasted image 20250920045957.png]]

Translasi ke Haskell:

```haskell
-- Definisi tipe
data Point = Pt Float Float
```

Pt merupakan konstruktor yang dijadikan internal representation dari tipe bentukan. Jika ingin tipe dapat ditampilkan melalui fungsi print sebagai string, tambahkan `deriving (Show)` di akhir baris

```haskell
-- Konstruktor
makePoint:: Float -> Float -> Point
makePoint x y = Pt x y
```

Di sini fungsi `makePoint` hanya sebagai wrapper atau pembungkus dari konstruktor `Pt`. Menggunakan `Pt` secara langsung juga sah-sah saja secara eksekusi.

```haskell
-- Selektor
absis:: Point -> Float
absis (Pt x _) = x

ordinat:: Point -> Float
ordinat (Pt _ y) = y
```

```haskell
-- Predikat
isOrigin:: Point -> Bool
isOrigin p = absis p == 0 && ordinat p == 0
```

Untuk lebih banyak contoh bisa melihat slide.