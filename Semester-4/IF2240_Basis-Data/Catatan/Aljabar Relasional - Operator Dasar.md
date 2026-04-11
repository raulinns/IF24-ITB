## Pengenalan Bahasa Kueri
Bahasa kueri adalah bahasa khusus yang digunakan oleh pengguna untuk meminta informasi atau mengekstrak data dari sebuah basis data. Bahasa ini memiliki tingkat abstraksi yang lebih tinggi dibandingkan bahasa pemrograman standar karena difokuskan sepenuhnya pada manipulasi data. Secara konseptual, bahasa kueri dibagi menjadi dua paradigma utama, yaitu fungsional/prosedural dan deklaratif/non-prosedural. 

## Aljabar Relasional
Aljabar relasional merupakan pondasi utama dari bahasa kueri prosedural formal. Aljabar relasional memiliki enam operator dasar yang mengambil satu atau dua tabel sebagai masukan dan menghasilkan tabel baru sebagai keluaran. Enam operator dasar ini adalah sebagai berikut.
1. `select` ($\sigma$)
2. `project` ($\Pi$)
3. `union` ($\cup$)
4. `set difference` ($-$)
5. `cartessian product` ($\times$)
6. `rename` ($\rho$)

Selain operator dasar, terdapat juga *additional operator*, yaitu `intersection`, `natural join`, `assignment`, `outer join`, dan `division` dan *extended operator*, yaitu `generalized projection` dan `aggregation`.

## Select ($\sigma$)
**Select** berfungsi untuk menyaring baris-baris data dari sebuah tabel berdasarkan kondisi tertentu.

Select didefinisikan dengan 
$$
\sigma_p(r) = \{ t | t \in r \land p(t) \}
$$
di mana $p$ adalah formula dalam kalkulus proposisional, yaitu kalimat yang dihubungkan dengan $\land$ (*and*), $\lor$ (*or*), dan $\lnot$ (*not*). 

## Project ($\Pi$)
**Project** berfungsi untuk mengembalikan relasi argumennya dengan hanya menyisakan atribut-atribut tertentu dan menghilangkan atribut lainnya.

Project didefinisikan dengan

$$\Pi_{A_1, A_2, \ldots, A_k}(r) = \{ t[A_1, A_2, \ldots, A_k] \mid t \in r \}$$

di mana $A_1, A_2, \ldots, A_k$ adalah daftar atribut yang ingin dipertahankan, dan $t[A_1, A_2, \ldots, A_k]$ adalah nilai _tuple_ $t$ yang diproyeksikan hanya pada atribut-atribut tersebut. Karena relasi adalah himpunan, baris duplikat akan otomatis dihilangkan.

## Union ($\cup$)
**Union** berfungsi untuk menggabungkan dua relasi yang kompatibel menjadi satu relasi baru.

Union didefinisikan dengan

$$r \cup s = \{ t \mid t \in r \lor t \in s \}$$

di mana $r$ dan $s$ adalah dua relasi yang harus memenuhi syarat kompatibilitas (memiliki aritas yang sama dan domain atribut yang bersesuaian pada setiap urutannya).

## Set Difference ($-$)
**Set Difference** berfungsi untuk menemukan tuple-tuple yang berada dalam satu relasi tetapi dipastikan tidak berada dalam relasi lainnya.

Set Difference didefinisikan dengan

$$r - s = \{ t \mid t \in r \land t \notin s \}$$

di mana $r$ dan $s$ adalah dua relasi masukan yang juga harus bersifat kompatibel satu sama lain agar operasi dapat dieksekusi.

## Cartesian Product ($\times$)
**Cartesian Product** berfungsi untuk menggabungkan informasi dari dua relasi dengan memadukan setiap _tuple_ dari relasi pertama dengan setiap _tuple_ dari relasi kedua.

Cartesian Product didefinisikan dengan

$$r \times s = \{ t \cdot q \mid t \in r \land q \in s \}$$

di mana $t \cdot q$ merepresentasikan penyambungan (_concatenation_) dari _tuple_ $t$ yang berasal dari relasi $r$ dan _tuple_ $q$ yang berasal dari relasi $s$.

## Rename ($\rho$)
**Rename** berfungsi untuk memberikan nama baru pada hasil dari suatu ekspresi aljabar relasional agar dapat dirujuk kembali.

Rename didefinisikan dengan

$$\rho_x(E)$$

di mana operasi ini mengembalikan hasil dari ekspresi aljabar relasional $E$ dengan nama relasi yang baru yaitu $x$. Terdapat juga bentuk $\rho_{x(A_1, A_2, \ldots, A_n)}(E)$ yang sekaligus mengganti nama atribut-atributnya menjadi $A_1, A_2, \ldots, A_n$.

## Definisi Formal
Sebuah ekspresi dasar dalam aljabar relasional terdiri salah satu di antara berikut.
1. Sebuah relasi dalam basis data
2. Sebuah relasi konstan