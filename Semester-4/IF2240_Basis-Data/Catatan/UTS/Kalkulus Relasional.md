---
cssclasses:
  - callouts-outlined
---
##  Aljabar Multiset Relasional
Teori aljabar relasional murni memandang tabel dalam basis data sebagai sebuah himpunan matematika, di mana tidak boleh ada satupun baris data yang duplikat. Namun, dalam penerapan nyata di dunia industri, menyimpan data kembar sering kali menjadi kebutuhan yang krusial untuk mencatat transaksi atau kejadian yang berulang. Oleh karena itu, kita menggunakan adaptasi teori yang disebut *multiset* atau *bag*, yang mengizinkan adanya baris-baris data yang identik dalam satu tabel. 

Aljabar Multiset Relasional didefinisikan sebagai berikut.
1. **Selection (Seleksi)**: Mempertahankan jumlah duplikasi baris data sebanyak yang ada pada tabel asal (input), asalkan baris tersebut memenuhi kriteria seleksi.
2. **Projection (Proyeksi)**: Menghasilkan satu baris keluaran untuk setiap baris input, sehingga duplikasi tetap dipertahankan secara penuh meskipun hasil proyeksinya identik.
3. **Cross Product (Produk Silang)**: Jika terdapat _m_ salinan baris _t1_ di tabel _r_, dan _n_ salinan baris _t2_ di tabel _s_, maka akan dihasilkan _m x n_ salinan baris kombinasi _t1.t2_ pada hasil _r x s_.
4. **Multiset Union (Gabungan)**: Menggabungkan dua tabel dengan menghasilkan total _m + n_ salinan baris data.
5. **Multiset Intersection (Irisan)**: Mencari irisan data dengan mempertahankan jumlah salinan paling sedikit, menghasilkan _min(m, n)_ salinan baris data.
6. **Multiset Difference (Selisih)**: Melakukan pengurangan antartabel yang menghasilkan _max(0, m - n)_ salinan baris data (dengan ketentuan hasil pengurangan tidak akan pernah berada di bawah angka nol).

## Kalkulus Relasional Tuple
Kalkulus Relasional Tuple merupakan bahasa kueri deklaratif. Dalam pendekatan deklaratif ini, pengguna hanya dituntut untuk menjelaskan dengan rinci informasi seperti apa yang ingin mereka dapatkan, tanpa perlu memikirkan urutan langkah tentang bagaimana sistem komputer harus mencari data tersebut di balik layar. 

Struktur dasar dari bahasa ini dituliskan dalam format himpunan matematika, yaitu $\{t | P(t)\}$, di mana kita mendefinisikan variabel _tuple_ (disimbolkan dengan huruf $t$) dan memberikan kondisi atau syarat pencarian yang disebut predikat atau formula ($P(t)$). Untuk membangun predikat syarat yang lebih kompleks, kita menggunakan formula logika matematika standar. Berikut adalah predikat yang digunakan:
1. Konjungsi: Menghubungkan dua syarat yang keduanya harus terpenuhi secara bersamaan (Operator: DAN / $\wedge$).
2. Disjungsi: Menghubungkan dua syarat di mana setidaknya salah satu syarat harus terpenuhi (Operator: ATAU / $\vee$).
3. Negasi: Menyangkal atau membalikkan kondisi dari sebuah syarat (Operator: TIDAK / $\neg$).
4. Kuantifikator Eksistensial: Memeriksa keberadaan data, mensyaratkan bahwa terdapat setidaknya satu _tuple_ terkait yang memenuhi kondisi (Operator: $\exists$).
5. Kuantifikator Universal: Memeriksa keseluruhan data, mensyaratkan bahwa semua _tuple_ dalam semesta pembicaraan harus memenuhi kondisi (Operator: $\forall$).

>[!notes]
>Untuk materi ini sangat disarankan untuk melihat contoh soal pada *slide* [[07-Relational-Calculus.pdf]] dan memperbanyak latihan soal pula

## Keamanan Ekspresi
Ketika merancang sebuah kueri, sangat mungkin untuk menulis ekspresi yang menghasilkan hasil yang jumlahnya tak hingga. Oleh karena itu, setiap kueri yang ditulis dalam kalkulus relasional wajib bersifat aman (*safe expression*). Sebuah ekspresi dinyatakan aman apabila seluruh nilai yang muncul sebagai hasil akhirnya murni berasal dari data yang memang sudah ada dan tercatat di dalam tabel-tabel basis data itu sendiri (bukan dibuat-buat). 

## Kalkulus Relasional Domain
Sebagai alternatif dari Kalkulus Relasional Tuple, terdapat pendekatan lain yang disebut Kalkulus Relasional Domain. Perbedaan utama di antara keduanya terletak pada cara kita mendefinisikan variabel pencarian. Jika kalkulus tuple mengevaluasi satu baris utuh secara bersamaan, kalkulus domain memecah baris tersebut dan berfokus pada variabel-variabel yang mewakili nilai dari masing-masing kolom atau atribut secara individu.
$$
\{
\langle x_{1}, x_{2}, \dots, x_{n} \rangle | P(x_{1}, x_{2}, \dots, x_{n})
\}
$$
dengan $x_{1}, x_{2}, \dots, x_{n}$ merepresentasikan variabel domain dan $P$ merepresentasikan sebuah formula seperti kalkulus predikat. 