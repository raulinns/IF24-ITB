## Database Design

### Hubungan dengan CPMK

> **CPMK 02** — Materi ini memakai model relasional dan *functional dependencies* untuk menilai kualitas skema relasi.  
> **CPMK 04** — Materi ini langsung berkaitan dengan perancangan skema basis data relasional yang baik.  
> **CPMK 05** — Skema hasil desain menjadi dasar implementasi basis data di DBMS relasional.

### Outline Konsep Fundamental

1. **Tujuan desain basis data relasional**
   - Mengurangi redundansi
   - Menjaga integritas informasi
   - Menghasilkan dekomposisi yang *lossless*
   - Mempertahankan *dependency preservation*

2. **Functional Dependencies**
   - Definisi FD: `alpha -> beta`
   - FD sebagai generalisasi konsep *key*
   - *Trivial dependency*
   - *Legal relation instance*

3. **Key dalam desain relasional**
   - *Superkey*
   - *Candidate key*
   - Hubungan key dengan FD

4. **Dekomposisi relasi**
   - *Lossless decomposition*
   - *Lossy decomposition*
   - *Dependency preservation*

5. **Teori FD**
   - *Closure* himpunan FD: `F+`
   - *Attribute closure*: `alpha+`
   - Armstrong's axioms
   - *Extraneous attributes*
   - *Canonical cover*: `Fc`

6. **Normal Forms**
   - 1NF
   - 2NF
   - 3NF
   - BCNF
   - Perbandingan 3NF dan BCNF

7. **Algoritma desain**
   - Pengujian BCNF
   - Pengujian 3NF
   - Algoritma dekomposisi BCNF
   - Algoritma dekomposisi 3NF

8. **Proses desain keseluruhan**
   - Dari ER Diagram
   - Dari *universal relation*
   - Dari desain *ad hoc*
   - Denormalisasi dan *materialized view*

### Penjelasan Materi

#### Tujuan Desain Basis Data Relasional

> **TL;DR:** Desain basis data yang baik bertujuan menghasilkan skema relasional yang minim redundansi, tidak kehilangan informasi, dan tetap menjaga dependensi penting.

Desain basis data relasional berfokus pada penyusunan skema tabel agar data dapat disimpan secara konsisten, efisien, dan mudah divalidasi. Menurut sumber NotebookLM, tujuan ideal desain basis data adalah mencapai **BCNF**, menjamin **lossless join**, dan menjaga **dependency preservation**.

Jika ketiga tujuan tersebut tidak dapat dicapai secara bersamaan, kompromi yang umum dipilih adalah menggunakan **3NF**, karena 3NF tetap dapat menjamin dekomposisi *lossless* dan *dependency preserving*, meskipun mungkin masih menyisakan sedikit redundansi.

- Tujuan utama desain:
  - Menghindari redundansi data yang tidak perlu
  - Mencegah anomali saat *insert*, *update*, dan *delete*
  - Menjamin tabel hasil dekomposisi dapat digabungkan kembali tanpa informasi palsu
  - Memastikan aturan dependensi tetap dapat dicek tanpa join yang mahal

#### Functional Dependencies

> **TL;DR:** *Functional dependency* menyatakan bahwa nilai satu kumpulan atribut menentukan nilai atribut lain secara unik.

*Functional dependency* atau FD adalah batasan pada *legal relation* yang menyatakan bahwa jika dua tuple memiliki nilai sama pada atribut `alpha`, maka keduanya harus memiliki nilai sama pada atribut `beta`. Secara formal ditulis sebagai:

```text
alpha -> beta
```

Artinya, `alpha` secara fungsional menentukan `beta`.

FD penting karena menjadi dasar untuk menentukan key, menguji bentuk normal, mencari dekomposisi, dan menilai apakah suatu desain relasional mengandung redundansi.

- Jenis penting FD:
  - **Non-trivial FD**: `alpha -> beta` dengan `beta` tidak seluruhnya termasuk dalam `alpha`
  - **Trivial FD**: `alpha -> beta` dengan `beta` termasuk dalam `alpha`, sehingga selalu benar
  - **FD pada legal instance**: FD dianggap berlaku jika seluruh instance relasi yang valid memenuhi aturan tersebut

#### Key, Superkey, dan Candidate Key

> **TL;DR:** Key adalah atribut atau himpunan atribut yang dapat mengidentifikasi tuple secara unik.

Dalam desain relasional, key digunakan untuk menentukan apakah suatu atribut cukup kuat untuk mengidentifikasi seluruh atribut dalam relasi. Konsep ini sangat penting karena syarat BCNF dan 3NF banyak bergantung pada apakah sisi kiri FD merupakan *superkey* atau bukan.

- **Superkey**
  - Himpunan atribut `K` disebut *superkey* untuk relasi `R` jika `K -> R`.
  - Artinya, `K` dapat menentukan seluruh atribut dalam relasi.

- **Candidate key**
  - *Superkey* minimal.
  - Tidak ada subset sejati dari candidate key yang masih dapat menjadi superkey.

- Hubungan dengan normalisasi:
  - Pada **BCNF**, setiap FD non-trivial harus memiliki sisi kiri berupa superkey.
  - Pada **3NF**, jika sisi kiri bukan superkey, atribut di sisi kanan masih dapat diterima jika merupakan bagian dari candidate key.

#### Lossless dan Lossy Decomposition

> **TL;DR:** Dekomposisi yang baik harus *lossless*, yaitu tidak menghasilkan kehilangan atau tambahan informasi palsu saat tabel digabungkan kembali.

Dekomposisi adalah proses memecah satu relasi besar menjadi beberapa relasi yang lebih kecil. Tujuan dekomposisi adalah mengurangi redundansi, tetapi pemecahan ini tidak boleh merusak makna data.

Dekomposisi disebut **lossless** jika hasil join dari tabel-tabel pecahan menghasilkan kembali relasi awal secara tepat. Sebaliknya, dekomposisi disebut **lossy** jika join menghasilkan tuple tambahan yang tidak ada pada data asli.

- **Lossless decomposition**
  - Tidak ada informasi hilang.
  - Tidak menghasilkan tuple palsu setelah join.
  - Secara formal: hasil join proyeksi tabel pecahan sama dengan relasi awal.
  - Untuk dekomposisi biner `R` menjadi `R1` dan `R2`, syarat lossless dapat diuji menggunakan FD:
    - `(R1 intersection R2) -> R1`, atau
    - `(R1 intersection R2) -> R2`
  - Artinya, atribut yang menjadi irisan kedua relasi harus menjadi superkey bagi minimal salah satu relasi hasil dekomposisi.

- **Lossy decomposition**
  - Dekomposisi buruk.
  - Join tabel pecahan dapat menghasilkan informasi palsu.
  - Harus dihindari dalam desain basis data.

#### Dependency Preservation

> **TL;DR:** *Dependency preservation* memastikan FD asli tetap bisa diperiksa pada tabel hasil dekomposisi tanpa harus melakukan join.

Selain *lossless*, dekomposisi yang baik sebaiknya juga mempertahankan dependensi. Artinya, aturan FD yang berlaku pada relasi awal tetap dapat dicek melalui tabel-tabel hasil dekomposisi.

Konsep ini penting secara praktis karena pengecekan constraint melalui join bisa mahal secara komputasi. Jika dependensi tidak terjaga, DBMS atau aplikasi mungkin harus melakukan join beberapa tabel hanya untuk memastikan suatu aturan data tidak dilanggar.

- Cara berpikir:
  - Relasi awal memiliki himpunan FD `F`
  - Setelah dekomposisi, setiap tabel pecahan memiliki FD lokal
  - Dekomposisi *dependency preserving* jika gabungan FD lokal dapat menghasilkan kembali FD awal

- Algoritma pengujian untuk satu FD `alpha -> beta`:
  - Inisialisasi `result = alpha`
  - Untuk setiap relasi hasil dekomposisi `Ri`, hitung:
    - `t = (result intersection Ri)+ intersection Ri`
  - Perbarui:
    - `result = result union t`
  - Ulangi sampai `result` tidak berubah
  - Jika `result` memuat seluruh atribut dalam `beta`, maka FD `alpha -> beta` terjaga

#### Functional Dependency Theory

> **TL;DR:** Teori FD menyediakan aturan formal untuk menurunkan FD baru, menghitung closure, dan menyederhanakan himpunan FD.

`F+` adalah seluruh FD yang dapat diturunkan secara logis dari himpunan FD awal `F`. Sementara itu, `alpha+` atau *attribute closure* adalah himpunan atribut yang dapat ditentukan oleh `alpha` berdasarkan FD yang tersedia.

Konsep ini digunakan untuk menentukan superkey, mencari candidate key, menguji FD, dan menjalankan algoritma normalisasi.

Aturan inferensi dasar dalam teori FD disebut **Armstrong's axioms**. Aturan ini bersifat benar secara logis dan menjadi dasar untuk menghitung closure.

- **Reflexivity rule**
  - Jika `beta` merupakan subset dari `alpha`, maka `alpha -> beta`
  - Aturan ini menjelaskan mengapa trivial FD selalu benarq

- **Augmentation rule**
  - Jika `alpha -> beta`, maka `gamma alpha -> gamma beta`
  - Artinya, menambahkan atribut yang sama pada sisi kiri dan kanan FD tidak merusak kebenaran FD

- **Transitivity rule**
  - Jika `alpha -> beta` dan `beta -> gamma`, maka `alpha -> gamma`
  - Artinya, dependensi dapat diturunkan secara berantai

- Prosedur umum menghitung `F+`:
  - Inisialisasi `F+ = F`
  - Terapkan reflexivity, augmentation, dan transitivity pada FD yang ada
  - Tambahkan FD baru yang berhasil diturunkan
  - Ulangi sampai tidak ada FD baru yang dapat ditambahkan

#### Closure, Extraneous Attributes, dan Canonical Cover

> **TL;DR:** *Closure* dan *canonical cover* digunakan untuk menyederhanakan FD sebelum melakukan normalisasi dan dekomposisi.

- **Attribute closure `alpha+`**
  - Mulai dari atribut awal `alpha`
  - Tambahkan atribut yang dapat ditentukan oleh FD
  - Ulangi sampai tidak ada atribut baru yang bisa ditambahkan

- **Extraneous attribute**
  - Atribut berlebih dalam sisi kiri atau sisi kanan FD
  - Dapat dihapus tanpa mengubah makna logis himpunan FD
  - Pengujian atribut berlebih pada sisi kiri:
    - Untuk FD `alpha -> beta`, misalkan atribut `A` berada di `alpha`
    - Bentuk `gamma = alpha - {A}`
    - Hitung `gamma+` menggunakan `F`
    - Jika `gamma+` memuat seluruh atribut dalam `beta`, maka `A` extraneous pada sisi kiri
  - Pengujian atribut berlebih pada sisi kanan:
    - Untuk FD `alpha -> beta`, misalkan atribut `C` berada di `beta`
    - Bentuk `F' = (F - {alpha -> beta}) union {alpha -> (beta - C)}`
    - Hitung `alpha+` menggunakan `F'`
    - Jika `alpha+` memuat `C`, maka `C` extraneous pada sisi kanan

- **Canonical cover `Fc`**
  - Bentuk sederhana dari himpunan FD
  - Ekuivalen dengan FD awal
  - Tidak mengandung atribut berlebih
  - Digunakan sebagai dasar algoritma dekomposisi 3NF

#### 1NF, 2NF, 3NF, dan BCNF

> **TL;DR:** 1NF dan 2NF adalah tahap dasar normalisasi, sedangkan 3NF dan BCNF menjadi fokus utama untuk mengendalikan redundansi berbasis FD.

Normal form adalah kriteria formal untuk menilai kualitas skema relasi. Dalam konteks desain relasional berbasis FD, 3NF dan BCNF menjadi pusat pembahasan karena keduanya secara langsung berkaitan dengan ketergantungan fungsional, dekomposisi, dan redundansi.

- **1NF**
  - Suatu skema relasi berada pada 1NF jika domain seluruh atributnya bersifat atomik.
  - Artinya, setiap nilai atribut tidak boleh berupa himpunan, daftar, atau struktur majemuk yang seharusnya dipecah lagi.

- **2NF**
  - Suatu skema relasi berada pada 2NF jika setiap atribut memenuhi salah satu kondisi:
    - Atribut tersebut merupakan bagian dari candidate key, atau
    - Atribut tersebut tidak bergantung secara parsial pada candidate key.
  - Fokus utama 2NF adalah menghindari *partial dependency*, terutama pada relasi dengan candidate key gabungan.

- **BCNF**
  - Untuk setiap FD non-trivial `alpha -> beta`, `alpha` harus merupakan superkey.
  - Lebih ketat daripada 3NF.
  - Dekomposisinya selalu dapat dibuat *lossless*.
  - Namun, tidak selalu *dependency preserving*.

- **3NF**
  - Lebih longgar daripada BCNF.
  - Dapat menjamin dekomposisi *lossless* dan *dependency preserving*.
  - Masih mungkin menyisakan sedikit redundansi.
  - Pengujian 3NF lebih mahal secara komputasi karena membutuhkan pencarian candidate key; dalam sumber disebut sebagai persoalan yang dapat menjadi NP-hard.
  - Walaupun begitu, algoritma dekomposisi ke 3NF dapat dilakukan dalam waktu polinomial.

- Perbandingan inti:
  - **BCNF**: lebih ideal untuk menghilangkan redundansi.
  - **3NF**: lebih aman jika dependensi harus tetap mudah dicek.
  - Jika BCNF menghilangkan *dependency preservation*, 3NF sering dipilih sebagai kompromi.

#### Algoritma Dekomposisi BCNF

> **TL;DR:** Dekomposisi BCNF memecah relasi berdasarkan FD yang melanggar syarat BCNF sampai semua relasi memenuhi BCNF.

Algoritma BCNF bekerja secara iteratif. Setiap kali ditemukan FD non-trivial `alpha -> beta` dengan `alpha` bukan superkey, relasi dipecah menjadi dua relasi baru.

- Langkah umum:
  - Mulai dari relasi awal `R`
  - Cari FD non-trivial `alpha -> beta` yang melanggar BCNF
  - Pecah relasi menjadi:
    - Relasi yang memuat `alpha` dan `beta`
    - Relasi sisa yang mengurangi atribut penyebab pelanggaran
  - Ulangi sampai semua relasi hasil dekomposisi memenuhi BCNF

- Catatan penting:
  - Hasil dekomposisi BCNF dijamin *lossless*
  - Namun, belum tentu *dependency preserving*
  - Untuk tabel hasil dekomposisi, pengujian BCNF tidak cukup hanya memakai FD awal; perlu memperhatikan FD yang berlaku pada relasi pecahan
  - Pengujian BCNF yang disederhanakan menggunakan `F` awal valid untuk relasi awal, tetapi tidak cukup untuk relasi pecahan `Ri`
  - Untuk setiap subset atribut `alpha` dalam `Ri`, periksa `alpha+`:
    - Jika `alpha+` tidak memuat atribut apa pun dari `Ri - alpha`, maka tidak ada pelanggaran dari `alpha`
    - Jika `alpha+` memuat seluruh atribut `Ri`, maka `alpha` adalah superkey untuk `Ri`
    - Jika `alpha+` memuat sebagian atribut dari `Ri - alpha` tetapi tidak seluruh `Ri`, maka terdapat pelanggaran BCNF
  - Jika pelanggaran ditemukan, FD formal untuk dekomposisi lanjutan dapat ditulis sebagai:

```text
alpha -> (alpha+ - alpha) intersection Ri
```

#### Algoritma Dekomposisi 3NF

> **TL;DR:** Dekomposisi 3NF berbasis *canonical cover* dan menjamin hasil yang *lossless* serta *dependency preserving*.

Algoritma 3NF dimulai dengan mencari *canonical cover* dari FD awal. Setelah itu, setiap FD dalam canonical cover digunakan untuk membentuk skema relasi.

- Langkah umum:
  - Cari `Fc`, yaitu *canonical cover* dari `F`
  - Untuk setiap FD `alpha -> beta` dalam `Fc`, buat relasi yang memuat `alpha` dan `beta`
  - Jika belum ada relasi yang memuat candidate key dari relasi awal, tambahkan relasi khusus berisi candidate key
  - Hapus relasi yang seluruh atributnya merupakan subset dari relasi lain

- Karakteristik penting:
  - Selalu dapat menghasilkan dekomposisi *lossless*
  - Selalu dapat menjaga *dependency preservation*
  - Urutan pemrosesan FD dalam canonical cover tidak memengaruhi hasil akhir secara substantif

#### Overall Database-Design Process

> **TL;DR:** Skema relasional dapat berasal dari ER Diagram, universal relation, atau desain ad hoc yang kemudian diuji dan dinormalisasi.

Desain basis data tidak selalu dimulai dari normalisasi. Dalam praktik, skema awal dapat muncul dari beberapa jalur. Jika ER Diagram dibuat dengan hati-hati, tabel hasil konversinya sering kali sudah cukup baik dan tidak memerlukan normalisasi tambahan besar.

- Sumber skema relasional:
  - **Dari ER Diagram**
    - Skema diperoleh dari pemetaan entitas dan relasi ke tabel
    - Jika desain ER baik, kebutuhan normalisasi biasanya berkurang

  - **Dari universal relation**
    - Semua atribut awalnya ditempatkan dalam satu relasi besar
    - Relasi kemudian dipecah melalui normalisasi

  - **Dari desain ad hoc**
    - Skema dibuat secara kasar
    - Setelah itu diuji terhadap FD dan bentuk normal

- Desain buruk yang perlu dihindari:
  - Membuat tabel berbeda untuk tahun berbeda, misalnya `earnings_2014`, `earnings_2015`
  - Membuat kolom berbeda untuk tahun berbeda, misalnya `earnings_2014`, `earnings_2015`
  - Desain yang lebih baik: `Earnings(company_id, year, amount)`

#### Denormalization

> **TL;DR:** Denormalisasi adalah penggabungan kembali data yang sudah ternormalisasi demi performa, dengan risiko redundansi dan anomali update.

Denormalisasi dilakukan secara sengaja ketika performa pembacaan lebih penting daripada kemurnian desain normal. Misalnya, beberapa atribut dari tabel lain disimpan ulang agar query tidak perlu melakukan join yang mahal.

- Keuntungan:
  - Query tertentu menjadi lebih cepat
  - Mengurangi kebutuhan join

- Kerugian:
  - Menambah redundansi
  - Membutuhkan ruang penyimpanan lebih besar
  - Memperbesar risiko inkonsistensi saat update
  - Membutuhkan logika tambahan di aplikasi atau DBMS

- Alternatif:
  - Menggunakan **materialized view** untuk menyimpan hasil query atau join tertentu tanpa sepenuhnya merusak desain dasar.

### Komponen Kunci

- **Functional Dependency (FD)** — Aturan `alpha -> beta` yang menyatakan bahwa nilai `alpha` menentukan nilai `beta`.
- **Legal Relation Instance** — Instance relasi yang memenuhi seluruh constraint dunia nyata.
- **Superkey** — Himpunan atribut yang dapat menentukan seluruh atribut dalam relasi.
- **Candidate Key** — Superkey minimal.
- **Closure `F+`** — Semua FD yang dapat diturunkan dari himpunan FD awal.
- **Attribute Closure `alpha+`** — Semua atribut yang dapat ditentukan oleh atribut `alpha`.
- **Armstrong's Axioms** — Tiga aturan inferensi FD: reflexivity, augmentation, dan transitivity.
- **Extraneous Attribute** — Atribut berlebih dalam FD yang dapat dihapus tanpa mengubah closure.
- **Canonical Cover `Fc`** — Himpunan FD ekuivalen yang sudah disederhanakan.
- **Lossless Decomposition** — Dekomposisi yang tidak kehilangan atau menambah informasi saat join.
- **Lossy Decomposition** — Dekomposisi yang menghasilkan informasi palsu saat join.
- **Dependency Preservation** — Kondisi ketika FD awal tetap dapat dicek pada tabel hasil dekomposisi.
- **1NF** — Bentuk normal yang mensyaratkan domain atribut bersifat atomik.
- **2NF** — Bentuk normal yang menghilangkan ketergantungan parsial terhadap candidate key.
- **3NF** — Bentuk normal yang menjamin *lossless* dan *dependency preserving*, tetapi mungkin masih menyisakan redundansi.
- **BCNF** — Bentuk normal lebih ketat; mengurangi redundansi lebih kuat, tetapi bisa kehilangan *dependency preservation*.
- **Denormalization** — Penggabungan kembali data demi performa dengan mengorbankan sebagian kualitas normalisasi.

### Checklist Pemahaman

1. **Sub-materi yang dibahas**
   - Tujuan desain basis data relasional
   - Functional dependencies
   - Superkey dan candidate key
   - Closure dan attribute closure
   - Armstrong's axioms
   - Lossless dan lossy decomposition
   - Dependency preservation
   - Extraneous attributes
   - Canonical cover
   - 1NF, 2NF, 3NF, dan BCNF
   - Algoritma dekomposisi BCNF
   - Algoritma dekomposisi 3NF
   - Overall database-design process
   - Denormalization

2. **Prioritas belajar**

🔴 **Wajib dikuasai**
- Menentukan `alpha+`
- Menggunakan Armstrong's axioms untuk menurunkan FD
- Menentukan superkey dan candidate key
- Memahami dan memakai FD `alpha -> beta`
- Membedakan *lossless* dan *lossy decomposition*, termasuk syarat `(R1 intersection R2) -> R1` atau `(R1 intersection R2) -> R2`
- Menguji *dependency preservation* dengan algoritma iteratif `result`
- Mencari *extraneous attributes*
- Menentukan *canonical cover*
- Membedakan 1NF, 2NF, 3NF, dan BCNF
- Menjalankan algoritma dekomposisi 3NF dan BCNF

🟡 **Cukup paham konsep**
- Overall database-design process
- Hubungan ER Model dengan normalisasi
- Denormalization
- Materialized view
- Contoh desain buruk seperti tabel per tahun atau kolom per tahun

✅ **Sudah dikuasai**
- Introduction to Database
- Data Model
- Relational Algebra, Relational Calculus
- SQL
- Database Design Entity Relation Model
- Reducing ER to Relational Scheme
