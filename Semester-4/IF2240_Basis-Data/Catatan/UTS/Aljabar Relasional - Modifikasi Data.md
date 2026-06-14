## Generalized Projection ($\Pi$)
**Generalized Projection** berfungsi untuk memperluas operasi _projection_ (proyeksi) dasar dengan mengizinkan penggunaan fungsi aritmetika di dalam daftar atribut yang diproyeksikan.

Generalized Projection didefinisikan dengan
$$
\Pi_{F_1, F_2, \dots, F_n}(E)
$$

di mana $E$ adalah ekspresi aljabar relasional apa pun, dan masing-masing $F_1, F_2, \dots, F_n$ adalah ekspresi aritmetika yang melibatkan konstanta dan atribut-atribut pada skema dari ekspresi $E$.

## Aggregation ($\mathcal{G}$)
**Aggregation** (Agregasi) berfungsi untuk mengoperasikan sekumpulan nilai dari beberapa baris data dan mengembalikan sebuah nilai tunggal. Operasi ini juga dapat dipadukan dengan pengelompokan baris data (_grouping_). Fungsi agregasi standar yang didukung meliputi _sum_ (jumlah), _count_ (cacah/banyaknya), _average_ (rata-rata), _max_ (nilai maksimum), dan _min_ (nilai minimum).

Aggregation didefinisikan dengan
$$
_{G_1, G_2, \dots, G_n} \mathcal{G}_{F_1(A_1), F_2(A_2), \dots, F_m(A_m)} (E)
$$
di mana $E$ adalah ekspresi aljabar relasional, $G_1, G_2, \dots, G_n$ adalah daftar atribut yang digunakan untuk mengelompokkan data (bisa dikosongkan jika tidak ada pengelompokan), setiap $F_i$ adalah fungsi agregasi, dan setiap $A_i$ adalah nama atribut yang dihitung.

## Deletion ($-$)
**Deletion** (Penghapusan) berfungsi untuk menghapus baris-baris data dari sebuah relasi (tabel). Sebuah kueri aljabar relasional dievaluasi untuk menemukan baris-baris data yang memenuhi kondisi untuk dihapus.

Deletion didefinisikan dengan ekspresi penugasan:
$$
r \leftarrow r - E
$$
di mana $r$ adalah relasi target dan $E$ adalah ekspresi aljabar relasional yang mengevaluasi himpunan baris data yang akan dihapus dari $r$.

## Insertion ($\cup$)
**Insertion** (Penyisipan) berfungsi untuk menambahkan baris-baris data baru ke dalam sebuah relasi (tabel). Baris data yang akan disisipkan dapat ditentukan secara spesifik (konstanta) atau didapatkan dari hasil evaluasi sebuah kueri aljabar relasional.

Insertion didefinisikan dengan ekspresi penugasan:
$$
r \leftarrow r \cup E
$$
di mana $r$ adalah relasi target dan $E$ adalah ekspresi aljabar relasional yang menghasilkan sekumpulan baris data yang kompatibel untuk dimasukkan ke dalam relasi $r$.

## Updating ($\Pi$)
**Updating** (Pembaruan) berfungsi untuk mengubah sebuah nilai, atau sebagian nilai, di dalam sebuah baris data tanpa harus mengubah atau menghapus baris data tersebut secara keseluruhan. Pembaruan direpresentasikan menggunakan operator _generalized projection_.

Updating didefinisikan dengan ekspresi penugasan:
$$
r \leftarrow \Pi_{F_1, F_2, \dots, F_n}(r)
$$
di mana hasil proyeksi menggantikan relasi asli $r$, dan setiap $F_i$ dapat berupa:
- Atribut ke-$i$ dari $r$, jika atribut tersebut tidak diperbarui (nilainya tetap).
- Sebuah ekspresi aritmetika yang melibatkan hanya konstanta dan atribut-atribut dari $r$, yang berfungsi memberikan nilai baru untuk atribut yang sedang diperbarui.

$$
\Pi_{\text{course\_id, title, credits}}(\sigma_{\text{dept\_name = "Comp. Sci"}}(\text{course}))
$$

$$
E \gets \sigma_{\text{dept\_name = "Comp. Sci"}}(\text{course})
$$
