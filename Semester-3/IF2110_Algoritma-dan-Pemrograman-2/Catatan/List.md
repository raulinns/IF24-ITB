Melanjutkan dari bab [[Tipe Bentukan]], sebuah tipe bentukan juga dapat berbentuk tipe rekursif. Tipe rekursif adalah tipe yang mengandung referensi terhadap dirinya sendiri. Dengan kata lain, tipe tersebut dibentuk dengan komponen yang merupakan tipenya sendiri. 

List merupakan sebuah tipe rekursif. List adalah sekumpulan elemen yang bertipe sama, atau disebut juga sequence/series. List merupakan tipe rekursif, karena
- Basis 0, list kosong adalah sebuah list
- Rekurens, list terdiri dari sebuah elemen dan sebuah sublist (di mana sublist juga bertipe list)

Dalam konstruktor, List dapat dibentuk dengan menambahkan elemen pada list di depan ataupun di belakang list.

![[Pasted image 20250920052128.png]]


Atau dalam notasi fungsionalnya:

![[Pasted image 20250920052145.png]]

Sedangkan dalam selektornya, kita tidak dapat mengambil elemen di tengah list secara langsung, kita hanya punya akses ke pada elemen pertama (dan sublist berisi sisa elemen setelahnya) atau elemen terakhir (dan sublist berisi sisa elemen sebelumnya). Untuk mengakses elemen list selain yang pertama dan terakhir, kita harus menggunakan rekursif.

Dalam notasi fungsional, selektornya adalah sebagai berikut:

| Fungsi      | Deskripsi                                                        |
| ----------- | ---------------------------------------------------------------- |
| FirstElmt() | Mengembalikan elemen pertama                                     |
| Tail()      | Mengembalikan sublist berisi semua elemen selain elemen pertama  |
| LastElmt()  | Mengembalikan elemen terakhir                                    |
| Head()      | Mengembalikan sublist berisi semua elemen selain elemen terakhir |

### Translasi ke Haskell
List dalam Haskell dinotasikan dengan `[]`. Misalkan:
- List of Integer -> `[Int]`
- List of Char -> `[Char]`

![[Pasted image 20250920053007.png]]

![[Pasted image 20250920053017.png]]

Sedangkan, untuk selektornya memiliki definisi yang berbeda dengan Notasi Fungsional. Notes: Awas terkecoh!!!

![[Pasted image 20250920053055.png]]

Terdapat beberapa operator "bawaan" untuk list dari Notasi Fungsional yang langsung dapat digunakan tanpa perlu diimplementasikan terlebih dahulu:

| Fungsi                                                        | Deskripsi                                                                |
| ------------------------------------------------------------- | ------------------------------------------------------------------------ |
| NbElmt: List -> integer                                       | Menghasilkan banyaknya elemen list                                       |
| isMember: elemen, List -> boolean                             | Mengecek apakah suatu elemen adalah member dari suatu list               |
| Copy: List -> List                                            | Menyalin list                                                            |
| isEqual: 2 List -> boolean                                    | Mengecek apakah l1 dan l2 memiliki elemen yang sama pada posis yang sama |
| Konkat: 2 List -> List                                        | Mengkonkatenasi l1 dengan l2, l2 di belakang l1                          |
| ElmtKeN: integer > 0, List tidak kosong -> elemen             | Mengembalikan elemen ke-N dari list                                      |
| isXElmtkeN: elemen, integer > 0, List tidak kosong -> boolean | Mengecek apakah X merupakan elemen ke N dari sebuah list                 |
