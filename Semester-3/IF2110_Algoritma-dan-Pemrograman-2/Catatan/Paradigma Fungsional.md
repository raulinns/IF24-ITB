Paradigma Fungsional dasarnya adalah konsep pemetaan dan fungsi di matematika. Paradigma fungsional memiliki pendekatan berpikir melalui fungsi apa yang akan direalisasikan, serta **bebas memori** dan **tidak mementingkan urutan instruksi**. *Programmer* juga tidak dituntut untuk mengetahui bagaimana mesin melakukan eksekusi.

![[Pasted image 20250920041905.png]]

# Ekspresi Dasar
## Operator dan Ekspresi
Komputer memilik *Arithmetic and Logic Unit* (ALU), ini yang mengakibatkan komputer mampu melakukan perhitungan numerik dan logika. Operator hanya dapat beroperasi pada tipe dasar (integer, real, character, dan boolean). 

Ekspresi adalah gabungan dari operan dan operator. Operan dapat berupa suatu nilai yang bertipe sesuai dengan operator atau hasil aplikasi fungsi. Ekspresi pada Paradigma Fungsional adalah ekspresi aritmatika, ekspresi logika, ekspresi kondisional, dan ekspresi rekursif. 

Operator Aritmatika Dasar dari:
- (\*) Kali
- (\/) Bagi
- (\+) Tambah
- (\-) Kurang
- (**mod**) Hasil bagi
- (**div**) Pembagian integer

Operator Relasional terdiri dari $>$, $<$, $=$, $\ge$, $\le$, $\ne$. Terdapat juga Operator Boolean, seperti **and**, **or**, dan **not**.

Ada pula penulisan ekspresi, yaitu infix, prefix, dan postfix. 
- Infix berarti ekspresi terdiri dari \[operan\] \[operator\] \[operan\]
- Prefix berarti ekspersi terdiri dari  \[operator\] \[operan\] \[operan\]
- Postfix berarti ekspresi terdiri dari \[operan\] \[operan\] \[operator\]

![[Pasted image 20250920043257.png]]

## Tipe
Domain dan Range dari sebuah fungsi didefinisikan dalam bentuk tipe. Tipe adalah himpunan nilai dan sekumpulan operator yang terdefinisi terhadap tipe tersebut. Terdapat dua tipe, yaitu tipe dasar dan tipe bentukan. Tipe dasar adalah tipe yang sudah tersedia, termasuk integer, real, character, string, dan boolean. Sedangkan, tipe bentukan adalah tipe yang dibentuk sendiri dari tipe dasar yang sudah disediakan.

## Notasi Fungsional
Template Notasi Fungsional

![[Pasted image 20250920043922.png]]

Dalam Notasi Fungsional, dapat digunakan ekspresi antara untuk mempermudah pembentukan fungsi. Ekspresi antara adalah nama yang digunakan sementara dalam fungsi, hanya berlaku dalam fungsi, tidak di dunia luar. 

![[Pasted image 20250920044118.png]]

## Translasi ke Haskell
Dalam Haskell, penulisannya kurang lebih mirip. Perbedaannya adalah
- **mod** dan **div** adalah sebuah fungsi yang menerima dua integer (jadi penulisannya infix, seperti fungsi lainnya)
- Operator relasional $=$ menjadi `==` dan $\ne$ menjadi `/=`
- Operator boolean **and** menjadi `&&` dan **or** menjadi `||`
- Tipe dasarnya bernama Int, Float, Char, String, dan Bool

Template Notasi Fungsional

```haskell
-- DEFINISI DAN SPESIFIKASI
<Nama-Fungsi>:: <domain> -> <range>
	-- SPESIFIKASI FUNGSI
<Nama-Fungsi> <list-parameter> = <ekspresi-fungsional>
```