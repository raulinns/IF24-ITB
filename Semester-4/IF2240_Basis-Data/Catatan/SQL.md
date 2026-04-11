## Pendahuluan  SQL
SQL (_Structured Query Language_) adalah bahasa standar yang digunakan untuk berkomunikasi dengan sistem manajemen basis data relasional (RDBMS).

 Awalnya dikembangkan oleh IBM dalam proyek _System R_ pada awal 1970-an dengan nama _Sequel_. Kemudian namanya diubah menjadi SQL. SQL telah melewati berbagai tahap standarisasi oleh ANSI dan ISO, mulai dari SQL-86, SQL-92 (standar yang paling banyak didukung), hingga SQL:2016.

Dalam praktiknya, SQL dibagi menjadi beberapa bagian fungsional, yaitu:    
1. *Data-Definition Language* (DDL): Berfokus pada pendefinisian struktur atau skema basis data serta batasan integritasnya.
2. *Data-Manipulation Language* (DML): Digunakan untuk melakukan kueri informasi serta modifikasi data seperti penyisipan, penghapusan, dan pembaruan.
3. *Integrity & Authorization*: Bagian ini mengatur spesifikasi batasan data dan hak akses pengguna untuk keamanan data.

## SQL Data Definition (DDL)
Dalam tahap perancangan, kita menggunakan DDL untuk membangun kerangka tabel. Hal ini melibatkan pemilihan tipe data yang tepat dan penentuan batasan agar data tetap konsisten. Berikut adalah aspek-aspek penting dalam DDL:

SQL mendukung berbagai tipe data untuk merepresentasikan informasi secara akurat:
- `char(n)`: Digunakan untuk string dengan panjang tetap sebesar $n$.        
- `varchar(n)`: Digunakan untuk string dengan panjang bervariasi hingga maksimal $n$, yang lebih efisien dalam penggunaan memori.	
- `int`: Untuk menyimpan bilangan bulat.
- `numeric(p, d)`: Untuk bilangan presisi tetap dengan total $p$ digit dan $d$ angka di belakang koma.	
- `real` dan `float(n)`: Untuk bilangan titik kambang (_floating point_).
 
Untuk menjaga validitas data, kita harus menerapkan batasan pada saat pembuatan tabel:
- `primary key (A)`: Menjamin bahwa atribut $A$ unik dan tidak boleh bernilai kosong (_not null_).
- `not null`: Menegaskan bahwa suatu kolom wajib diisi.
- `foreign key (A) references B`: Memastikan referensi antar tabel tetap terjaga melalui kunci tamu.

## Struktur Dasar Query
Operasi pengambilan data di SQL didasarkan pada tiga klausa utama yang mirip dengan operasi aljabar relasional.
1. Klausa `select`: Digunakan untuk menentukan kolom apa saja yang ingin ditampilkan.
    - Gunakan `distinct` untuk menghapus duplikasi data pada hasil keluaran.
    - Simbol `*` digunakan untuk menampilkan seluruh kolom.
2. Klausa `from`: Menentukan tabel-tabel yang menjadi sumber data. Jika lebih dari satu tabel, SQL secara teoretis melakukan _Cartesian Product_.
3. Klausa `where`: Berfungsi sebagai filter untuk baris-baris yang memenuhi kondisi tertentu. Di dalam klausa ini, kita dapat menggabungkan berbagai predikat menggunakan operator logika dan jangkauan:
    - `AND`: Memastikan semua kondisi yang digabungkan harus bernilai benar (_true_).      
    - `OR`: Menghasilkan nilai benar jika salah satu kondisi terpenuhi.
    - `BETWEEN`: Mempermudah penyaringan data dalam rentang nilai tertentu (inklusif), misalnya `where salary between 50000 and 100000`.
``
Selain kueri standar, SQL juga menyediakan fitur tambahan untuk fleksibilitas pencarian dan penyajian data:
- **Operasi Rename (`as`):** SQL memungkinkan kita mengganti nama atribut maupun tabel dalam hasil kueri menggunakan klausa `as`.
    - *Rename* Atribut: Digunakan untuk memberikan nama yang lebih deskriptif pada kolom hasil atau hasil operasi aritmatika (contoh: `select name as instructor_name`).
    - *Rename* Tabel: Sering disebut sebagai _tuple variables_ atau _aliases_, digunakan untuk memperpendek penulisan kueri atau saat melakukan kueri pada tabel yang sama (contoh: `from instructor as T, instructor as S`).
- Pencocokan Pola (`like`): Digunakan untuk mencari string berdasarkan pola tertentu dengan bantuan karakter khusus `%` (mewakili sebarang string, nol atau lebih karakter) dan `_` (mewakili tepat satu karakter). Contoh: `Kar%`, mencari string dengan awalan `Kar`, misal `Karpet`.
- Pengurutan (`order by`): Hasil kueri dapat diurutkan secara menaik (`asc`) atau menurun (`desc`) berdasarkan atribut tertentu.

## Operasi Himpunan (Set Operations)
SQL menyediakan cara untuk menggabungkan hasil dari dua atau lebih kueri yang memiliki struktur kolom yang kompatibel.
- `union`: Menggabungkan hasil dan menghapus duplikasi. Gunakan `union all` jika ingin mempertahankan duplikasi.
- `intersect`: Mengambil irisan data yang ada di kedua kueri.
- `except`: Mengambil data yang ada di kueri pertama namun tidak ada di kueri kedua.

## Nilai Null
Dalam basis data nyata, seringkali terdapat data yang hilang atau tidak diketahui, yang direpresentasikan sebagai `null`. Perbandingan dengan `null` menghasilkan nilai `unknown`. SQL menggunakan logika:
- `true and unknown = unknown`
- `false and unknown = false`
- `true or unknown = true`
- `false or unknown = unknown`

## Fungsi Agregat
 - Fungsi agregat digunakan untuk melakukan perhitungan pada sekumpulan nilai dalam satu kolom.    
	- `avg` (rata-rata), `min` (minimum), `max` (maksimum), `sum` (total), `count` (jumlah baris).    
- Pengelompokan (`group by`): Membagi data ke dalam kelompok-kelompok sebelum fungsi agregat diterapkan.
- Klausa `having`: Mirip dengan `where`, namun digunakan khusus untuk memfilter kelompok (setelah `group by`).