**SQL (Structured Query Language)** adalah bahasa standar yang digunakan untuk berinteraksi dengan Sistem Manajemen Basis Data Relasional (RDBMS). SQL tidak hanya digunakan untuk mengambil data, tetapi juga untuk mendefinisikan struktur basis data, memanipulasi data, dan mengatur hak akses.

SQL terdiri dari beberapa bagian fungsional:

**DML (Data Manipulation Language)** — menyediakan kemampuan untuk melakukan kueri (_query_) terhadap basis data serta menyisipkan (_insert_), menghapus (_delete_), dan memodifikasi (_update_) tuple di dalam relasi.

**DDL (Data Definition Language)** — menyediakan perintah untuk mendefinisikan skema relasi, termasuk tipe data, _integrity constraints_, dan definisi _view_.

**Transaction Control** — mencakup perintah untuk menandai awal dan akhir sebuah transaksi.

**Embedded & Dynamic SQL** — mendefinisikan bagaimana perintah SQL dapat disematkan di dalam bahasa pemrograman umum (seperti Java, C, Python).

**Authorization** — mencakup perintah untuk mendefinisikan hak akses terhadap relasi dan _view_.

---

## 2. Struktur Kueri Dasar (Basic Query Structure)

Setiap kueri SQL memiliki bentuk dasar sebagai berikut:

```sql
SELECT A1, A2, ..., An
FROM   r1, r2, ..., rm
WHERE  P
```

Keterangan:

- `Ai` merepresentasikan **atribut** (kolom) yang ingin ditampilkan.
- `ri` merepresentasikan **relasi** (tabel) yang menjadi sumber data.
- `P` adalah **predikat** (kondisi) penyaring baris.

Hasil dari sebuah kueri SQL selalu berupa **relasi** (tabel).

---

## 3. Klausa SELECT

Klausa `SELECT` mendaftar atribut yang diinginkan dalam hasil kueri. Secara konseptual, `SELECT` berkorespondensi dengan **operasi proyeksi** (π) pada aljabar relasional.

**Contoh — Tampilkan nama seluruh instruktur:**

```sql
SELECT name
FROM   instructor
```

**Catatan penting:** SQL bersifat _case-insensitive_ untuk nama relasi dan atribut. `Name`, `NAME`, dan `name` dianggap identik.

### 3.1 DISTINCT — Menghilangkan Duplikat

SQL secara _default_ **mengizinkan duplikat** dalam hasil kueri (berbeda dengan aljabar relasional). Untuk menghilangkan duplikat, gunakan kata kunci `DISTINCT`:

```sql
SELECT DISTINCT dept_name
FROM   instructor
```

Sebaliknya, `ALL` secara eksplisit menyatakan bahwa duplikat **tidak** dihapus (ini adalah perilaku _default_):

```sql
SELECT ALL dept_name
FROM   instructor
```

### 3.2 Tanda Bintang (*) dan Literal

Tanda bintang (`*`) pada klausa `SELECT` berarti "semua atribut":

```sql
SELECT *
FROM   instructor
```

Sebuah atribut juga dapat berupa **literal** (nilai tetap). Jika tidak ada klausa `FROM`, hasilnya adalah tabel dengan satu kolom dan satu baris:

```sql
SELECT '437'
-- atau diberi nama kolom:
SELECT '437' AS FOO
```

Jika literal digunakan bersama `FROM`, hasilnya adalah tabel dengan satu kolom dan N baris (sebanyak tuple dalam relasi tersebut), di mana setiap baris bernilai literal tersebut:

```sql
SELECT 'A'
FROM   instructor
```

### 3.3 Ekspresi Aritmetika

Klausa `SELECT` dapat memuat ekspresi aritmetika menggunakan operator `+`, `-`, `*`, `/` terhadap konstanta maupun atribut bertipe numerik:

```sql
SELECT ID, name, salary / 12 AS monthly_salary
FROM   instructor
```

---

## 4. Klausa WHERE

Klausa `WHERE` menentukan kondisi yang harus dipenuhi oleh setiap baris hasil kueri. Klausa ini berkorespondensi dengan **operasi seleksi** (σ) pada aljabar relasional.

**Contoh — Cari nama instruktur dari departemen Comp. Sci.:**

```sql
SELECT name
FROM   instructor
WHERE  dept_name = 'Comp. Sci.'
```

**Contoh — Dengan kondisi majemuk (AND):**

```sql
SELECT name
FROM   instructor
WHERE  dept_name = 'Comp. Sci.' AND salary > 70000
```

SQL mendukung operator logika: `AND`, `OR`, `NOT`. Operator pembanding yang tersedia: `<`, `<=`, `>`, `>=`, `=`, `<>` (tidak sama dengan).

---

## 5. Klausa FROM

Klausa `FROM` mendaftar relasi yang terlibat dalam kueri. Klausa ini berkorespondensi dengan **operasi Cartesian product** (×) pada aljabar relasional.

Jika lebih dari satu relasi disebutkan, SQL menghasilkan semua kombinasi tuple yang mungkin dari relasi-relasi tersebut:

```sql
SELECT *
FROM   instructor, teaches
```

Kueri di atas menghasilkan _Cartesian product_ dari `instructor` dan `teaches`. Untuk atribut yang memiliki nama sama di kedua relasi (misal `ID`), hasilnya diberi nama kualifikasi: `instructor.ID` dan `teaches.ID`.

_Cartesian product_ sendiri tidak terlalu berguna secara langsung, tetapi menjadi sangat berguna ketika dikombinasikan dengan klausa `WHERE` untuk menghasilkan operasi _join_:

```sql
SELECT name, course_id
FROM   instructor, teaches
WHERE  instructor.ID = teaches.ID
```

---

## 6. Operasi Rename — AS

SQL memungkinkan penggantian nama atribut maupun relasi menggunakan kata kunci `AS` (_alias_). Teknik ini disebut **rename operation**, yang berkorespondensi dengan operasi ρ (rho) pada aljabar relasional.

```sql
-- Mengubah nama kolom pada hasil
SELECT name AS instructor_name, course_id
FROM   instructor, teaches
WHERE  instructor.ID = teaches.ID
```

Alias juga dapat digunakan untuk relasi (_table alias_), yang sangat berguna saat melakukan **self-join** (join suatu tabel dengan dirinya sendiri):

```sql
SELECT DISTINCT T.name
FROM   instructor AS T, instructor AS S
WHERE  T.salary > S.salary AND S.dept_name = 'Comp. Sci.'
```

Pada contoh di atas, `T` dan `S` adalah dua salinan (alias) dari relasi `instructor` yang dibandingkan satu sama lain.

---

## 7. Operasi String

SQL menyediakan sejumlah operasi untuk memproses nilai bertipe string:

### 7.1 LIKE — Pencocokan Pola

Operator `LIKE` digunakan untuk pencocokan pola (_pattern matching_) pada string, dengan dua karakter khusus:

- `%` — cocok dengan sembarang substring (termasuk string kosong).
- `_` — cocok dengan tepat satu karakter apa pun.

```sql
-- Cari instruktur yang namanya mengandung kata 'dar'
SELECT name
FROM   instructor
WHERE  name LIKE '%dar%'

-- Nama yang terdiri dari tepat 5 karakter dan diawali 'Mo'
WHERE  name LIKE 'Mo___'
```

Untuk mencocokkan karakter `%` atau `_` secara literal, gunakan karakter _escape_:

```sql
WHERE  name LIKE '100\%' ESCAPE '\'
```

---

## 8. Pengurutan Hasil — ORDER BY

Secara _default_, SQL tidak menjamin urutan tuple dalam hasil kueri. Untuk mengurutkan, gunakan klausa `ORDER BY`:

```sql
SELECT DISTINCT name
FROM   instructor
ORDER BY name
```

Urutan _default_ adalah **ASC** (menaik/_ascending_). Gunakan **DESC** untuk urutan menurun (_descending_):

```sql
SELECT name, salary
FROM   instructor
ORDER BY salary DESC, name ASC
```

Pengurutan dapat dilakukan berdasarkan beberapa atribut secara berurutan (multi-level sorting).

---

## 9. Operasi Himpunan — UNION, INTERSECT, EXCEPT

SQL mendukung operasi himpunan yang berkorespondensi langsung dengan operasi pada aljabar relasional:

|Operasi SQL|Aljabar Relasional|Deskripsi|
|---|---|---|
|`UNION`|∪|Gabungan dua hasil kueri|
|`INTERSECT`|∩|Irisan dua hasil kueri|
|`EXCEPT`|−|Selisih dua hasil kueri|

**Catatan penting:** Secara _default_, operasi himpunan ini **otomatis menghilangkan duplikat**. Untuk mempertahankan duplikat, gunakan `UNION ALL`, `INTERSECT ALL`, atau `EXCEPT ALL`.

**Contoh UNION:**

```sql
-- Cari semua instruktur yang mengajar di semester Fall 2017 ATAU Spring 2018
(SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2017)
UNION
(SELECT course_id FROM section WHERE semester = 'Spring' AND year = 2018)
```

**Contoh INTERSECT:**

```sql
-- Cari course_id yang diajarkan di KEDUA semester
(SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2017)
INTERSECT
(SELECT course_id FROM section WHERE semester = 'Spring' AND year = 2018)
```

**Contoh EXCEPT:**

```sql
-- Cari course_id yang diajarkan di Fall 2017 tetapi TIDAK di Spring 2018
(SELECT course_id FROM section WHERE semester = 'Fall' AND year = 2017)
EXCEPT
(SELECT course_id FROM section WHERE semester = 'Spring' AND year = 2018)
```

---

## 10. Nilai NULL

Nilai **NULL** dalam SQL merepresentasikan nilai yang tidak diketahui atau tidak ada. Null memiliki semantik khusus:

Operasi aritmetika apa pun yang melibatkan NULL menghasilkan NULL (misal: `5 + NULL = NULL`).

Perbandingan dengan NULL menggunakan `=` atau `<>` tidak menghasilkan `TRUE` atau `FALSE`, melainkan **UNKNOWN**. Untuk menguji apakah suatu nilai adalah NULL, gunakan:

```sql
WHERE salary IS NULL
WHERE salary IS NOT NULL
```

**Logika tiga nilai (Three-valued Logic):**

- `TRUE AND UNKNOWN = UNKNOWN`
- `FALSE AND UNKNOWN = FALSE`
- `TRUE OR UNKNOWN = TRUE`
- `FALSE OR UNKNOWN = UNKNOWN`
- `NOT UNKNOWN = UNKNOWN`

Klausa `WHERE` hanya mengembalikan baris yang kondisinya bernilai **TRUE** (bukan UNKNOWN atau FALSE).

---

## 11. Fungsi Agregasi (Aggregate Functions)

Fungsi agregasi beroperasi pada **sekumpulan nilai** dalam suatu kolom dan menghasilkan **satu nilai tunggal** sebagai output.

Fungsi agregasi standar SQL:

|Fungsi|Keterangan|
|---|---|
|`AVG(col)`|Rata-rata nilai numerik|
|`MIN(col)`|Nilai minimum|
|`MAX(col)`|Nilai maksimum|
|`SUM(col)`|Jumlah total nilai numerik|
|`COUNT(col)`|Jumlah baris (non-NULL)|
|`COUNT(*)`|Jumlah seluruh baris (termasuk NULL)|

**Contoh:**

```sql
-- Rata-rata gaji instruktur di departemen Comp. Sci.
SELECT AVG(salary)
FROM   instructor
WHERE  dept_name = 'Comp. Sci.'

-- Jumlah instruktur yang mengajar di Spring 2010
SELECT COUNT(DISTINCT ID)
FROM   teaches
WHERE  semester = 'Spring' AND year = 2010
```

### 11.1 GROUP BY

Klausa `GROUP BY` digunakan untuk **mengelompokkan tuple** berdasarkan nilai satu atau lebih atribut, lalu menerapkan fungsi agregasi pada setiap kelompok:

```sql
-- Rata-rata gaji per departemen
SELECT dept_name, AVG(salary) AS avg_salary
FROM   instructor
GROUP BY dept_name
```

**Aturan kritis:** Setiap atribut yang muncul di klausa `SELECT` **harus** merupakan bagian dari klausa `GROUP BY`, kecuali jika atribut tersebut berada di dalam fungsi agregasi.

### 11.2 HAVING

Klausa `HAVING` berfungsi seperti `WHERE`, tetapi diterapkan **setelah pengelompokan** (post-aggregation filtering). `HAVING` digunakan untuk memfilter kelompok berdasarkan hasil fungsi agregasi:

```sql
-- Tampilkan departemen dengan rata-rata gaji > 42000
SELECT dept_name, AVG(salary) AS avg_salary
FROM   instructor
GROUP BY dept_name
HAVING AVG(salary) > 42000
```

**Perbedaan WHERE dan HAVING:**

- `WHERE` memfilter baris **sebelum** pengelompokan.
- `HAVING` memfilter kelompok **setelah** pengelompokan.

---

## 12. Subkueri (Subquery)

Subkueri adalah kueri yang disisipkan di dalam kueri lain. Subkueri dapat digunakan di klausa `WHERE`, `FROM`, maupun `SELECT`.

### 12.1 Subkueri di Klausa WHERE — IN / NOT IN

Operator `IN` memeriksa apakah suatu nilai **terdapat dalam** himpunan yang dihasilkan oleh subkueri:

```sql
-- Cari course_id yang diajarkan di Fall 2017 DAN Spring 2018
SELECT DISTINCT course_id
FROM   section
WHERE  semester = 'Fall' AND year = 2017
  AND  course_id IN (
         SELECT course_id FROM section
         WHERE semester = 'Spring' AND year = 2018
       )
```

### 12.2 Perbandingan Himpunan — SOME / ALL

`SOME` (setara dengan `ANY`) mengembalikan TRUE jika kondisi terpenuhi untuk **setidaknya satu** elemen dalam himpunan:

```sql
-- Cari instruktur dengan gaji lebih besar dari SEBAGIAN instruktur di Biology
SELECT name
FROM   instructor
WHERE  salary > SOME (
         SELECT salary FROM instructor WHERE dept_name = 'Biology'
       )
```

`ALL` mengembalikan TRUE jika kondisi terpenuhi untuk **semua** elemen dalam himpunan:

```sql
-- Cari instruktur dengan gaji lebih besar dari SEMUA instruktur di Biology
SELECT name
FROM   instructor
WHERE  salary > ALL (
         SELECT salary FROM instructor WHERE dept_name = 'Biology'
       )
```

### 12.3 EXISTS / NOT EXISTS

`EXISTS` mengembalikan TRUE jika subkueri menghasilkan **setidaknya satu tuple**:

```sql
-- Cari instruktur yang mengajar setidaknya satu mata kuliah di Fall 2017
SELECT name
FROM   instructor
WHERE  EXISTS (
         SELECT * FROM teaches
         WHERE teaches.ID = instructor.ID
           AND semester = 'Fall' AND year = 2017
       )
```

### 12.4 Subkueri di Klausa FROM

Subkueri juga dapat digunakan sebagai relasi sementara dalam klausa `FROM` (harus diberi _alias_):

```sql
SELECT dept_name, avg_salary
FROM   (SELECT dept_name, AVG(salary) AS avg_salary
        FROM   instructor
        GROUP BY dept_name) AS dept_avg
WHERE  avg_salary > 42000
```

### 12.5 WITH — Common Table Expression (CTE)

Klausa `WITH` mendefinisikan relasi sementara yang bernama, yang berlaku hanya untuk satu kueri:

```sql
WITH dept_total(dept_name, value) AS (
    SELECT dept_name, SUM(salary)
    FROM   instructor
    GROUP BY dept_name
),
dept_total_avg(value) AS (
    SELECT AVG(value) FROM dept_total
)
SELECT dept_name
FROM   dept_total, dept_total_avg
WHERE  dept_total.value >= dept_total_avg.value
```

---

## 13. Modifikasi Data — DML

### 13.1 DELETE

Menghapus tuple dari relasi yang memenuhi kondisi tertentu:

```sql
-- Hapus semua instruktur dari departemen Finance
DELETE FROM instructor
WHERE dept_name = 'Finance'

-- Hapus instruktur dengan gaji di bawah rata-rata
DELETE FROM instructor
WHERE salary < (SELECT AVG(salary) FROM instructor)
```

### 13.2 INSERT

Menyisipkan satu atau lebih tuple baru ke dalam relasi:

```sql
-- Sisipkan satu tuple
INSERT INTO course
VALUES ('CS-437', 'Database Systems', 'Comp. Sci.', 4)

-- Sisipkan dengan nama atribut eksplisit (urutan bebas)
INSERT INTO course (title, course_id, credits, dept_name)
VALUES ('Database Systems', 'CS-437', 4, 'Comp. Sci.')

-- Sisipkan hasil dari subkueri
INSERT INTO instructor
SELECT ID, name, dept_name, 18000
FROM   student
WHERE  dept_name = 'Music' AND total_credits > 144
```

### 13.3 UPDATE

Memperbarui nilai atribut pada tuple yang memenuhi kondisi:

```sql
-- Naikkan gaji semua instruktur 5%
UPDATE instructor
SET salary = salary * 1.05

-- Naikkan gaji instruktur dengan gaji < 70000 sebesar 5%
UPDATE instructor
SET salary = salary * 1.05
WHERE salary < 70000
```

**UPDATE dengan CASE:**

Digunakan untuk menerapkan logika kondisional dalam satu perintah UPDATE:

```sql
UPDATE instructor
SET salary = CASE
                WHEN salary <= 100000 THEN salary * 1.05
                ELSE salary * 1.03
             END
```

---

## 14. JOIN — Operasi Penggabungan

Join menggabungkan tuple dari dua atau lebih relasi berdasarkan kondisi tertentu. SQL menyediakan beberapa jenis join:

### 14.1 INNER JOIN (JOIN)

Hanya mengembalikan tuple yang memiliki kecocokan di **kedua** relasi:

```sql
SELECT name, course_id
FROM   instructor
JOIN   teaches ON instructor.ID = teaches.ID
```

### 14.2 NATURAL JOIN

Secara otomatis menggabungkan berdasarkan seluruh atribut yang **memiliki nama sama** di kedua relasi, dan mengeliminasi kolom duplikat:

```sql
SELECT name, course_id
FROM   instructor NATURAL JOIN teaches
```

**Perhatian:** `NATURAL JOIN` dapat menghasilkan hasil yang tidak diinginkan jika ada atribut dengan nama sama yang seharusnya tidak dijadikan kondisi join. Gunakan dengan hati-hati.

### 14.3 LEFT OUTER JOIN

Mengembalikan semua tuple dari relasi **kiri**, dan mencocokkannya dengan relasi kanan. Jika tidak ada kecocokan, atribut dari relasi kanan diisi dengan NULL:

```sql
SELECT *
FROM   student LEFT OUTER JOIN takes ON student.ID = takes.ID
```

### 14.4 RIGHT OUTER JOIN

Kebalikan dari LEFT OUTER JOIN — semua tuple dari relasi **kanan** dipertahankan:

```sql
SELECT *
FROM   student RIGHT OUTER JOIN takes ON student.ID = takes.ID
```

### 14.5 FULL OUTER JOIN

Mempertahankan semua tuple dari **kedua** relasi. Jika tidak ada kecocokan, sisi yang tidak cocok diisi NULL:

```sql
SELECT *
FROM   student FULL OUTER JOIN takes ON student.ID = takes.ID
```

---

## 15. View

**View** adalah relasi virtual yang tidak secara fisik disimpan di basis data, melainkan didefinisikan melalui sebuah kueri. View menyederhanakan akses terhadap data yang kompleks dan dapat menyembunyikan detail tertentu dari pengguna.

### 15.1 Mendefinisikan View

```sql
CREATE VIEW faculty AS
SELECT ID, name, dept_name
FROM   instructor
```

Setelah didefinisikan, `faculty` dapat digunakan seperti relasi biasa:

```sql
SELECT name
FROM   faculty
WHERE  dept_name = 'Biology'
```

### 15.2 View Expansion

Setiap penggunaan _view_ akan secara transparan digantikan oleh definisi kueri di baliknya oleh DBMS — proses ini disebut **view expansion**.

### 15.3 Materialized View

Beberapa DBMS mendukung **materialized view**, yakni view yang hasilnya secara fisik disimpan dan diperbarui secara berkala ketika relasi dasarnya berubah.

---

## 16. DDL — Definisi Skema

### 16.1 CREATE TABLE

```sql
CREATE TABLE department (
    dept_name  VARCHAR(20) NOT NULL,
    building   VARCHAR(15),
    budget     NUMERIC(12,2),
    PRIMARY KEY (dept_name)
)
```

### 16.2 Integrity Constraints (Batasan Integritas)

Batasan integritas memastikan data yang disimpan valid secara semantik:

|Constraint|Keterangan|
|---|---|
|`NOT NULL`|Atribut tidak boleh bernilai NULL|
|`PRIMARY KEY (A)`|A adalah kunci primer (unik dan tidak NULL)|
|`FOREIGN KEY (A) REFERENCES r`|A merujuk kunci primer relasi r|
|`UNIQUE (A1, A2)`|Kombinasi A1, A2 harus unik|
|`CHECK (P)`|Nilai atribut harus memenuhi predikat P|

**Contoh FOREIGN KEY:**

```sql
CREATE TABLE teaches (
    ID          VARCHAR(5),
    course_id   VARCHAR(8),
    PRIMARY KEY (ID, course_id),
    FOREIGN KEY (ID) REFERENCES instructor (ID)
        ON DELETE CASCADE
)
```

### 16.3 ALTER TABLE dan DROP TABLE

```sql
-- Menambahkan atribut baru
ALTER TABLE instructor ADD COLUMN office VARCHAR(20)

-- Menghapus atribut
ALTER TABLE instructor DROP COLUMN office

-- Menghapus seluruh tabel
DROP TABLE instructor
```

---

## Rangkuman Hierarki Perintah SQL

```
SQL
├── DDL (Data Definition Language)
│   ├── CREATE TABLE
│   ├── ALTER TABLE
│   └── DROP TABLE
├── DML (Data Manipulation Language)
│   ├── SELECT ... FROM ... WHERE
│   ├── INSERT INTO
│   ├── UPDATE ... SET
│   └── DELETE FROM
├── DCL (Data Control Language)
│   └── GRANT / REVOKE
└── TCL (Transaction Control Language)
    ├── COMMIT
    └── ROLLBACK
```

---

Materi di atas mencakup seluruh topik SQL yang terdapat dalam slide kuliah IF2240. Apabila Anda ingin pembahasan lebih mendalam pada topik tertentu (misalnya subkueri lanjutan, fungsi agregasi, atau join), silakan tanyakan.