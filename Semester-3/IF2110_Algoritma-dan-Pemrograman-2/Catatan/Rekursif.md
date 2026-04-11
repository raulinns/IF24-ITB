Sebuah entitas dapat disebut rekursif jika pada definisinya terkandung terminologi dirinya sendiri. Ekspresi rekursif direalisasikan dengan membuat fungsi rekursif dan didasari analisis rekurens. 

Solusi dari sebuah permasalahan rekursif terdiri dari dua bagian, yaitu
- Basis, kasus yang menyebabkan fungsi berhenti karena jawaban sudah dapat diperoleh
- Rekurens, mengandung *call* terhadap fungsi tersebut, dengan parameter berubah nilainya menuju basis. 

Solusi rekursif memiliki sekurang-kurangnya satu kasus basis dan satu kasus rekursif. 

Kerangka fungsi rekursif untuk Pemrograman Fungsional adalah menggunakan ekspresi kondisional.

Notasi Fungsional

![[Pasted image 20250920050956.png]]

Haskell

```haskell
<fungsi> <list-parameter> = 
	if <kondisi-basis> then <ekspresi_1> -- basis
	else <fungsi> (<ekspresi_2>) -- kondisi rekurens
```