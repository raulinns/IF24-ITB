---
cssclasses:
  - callouts-outlined
---
Untuk menyembunyikan kompleksitas penyimpanan, DBMS menerapkan tiga level abstraksi. 
- Level fisik (*physical level*) menjelaskan detail teknis penyimpanan data
- Level logis (*logical level*) mendeskripsikan struktur data serta hubungan antar data (tempat administrator bekerja)
- Level pandangan (_view level_) hanya menampilkan sebagian data yang relevan bagi pengguna tertentu demi keamanan dan penyederhanaan interaksi.

*Schema* adalah struktur dari sebuah database. *Instance* adalah konten aktual data yang tersimpan pada suatu waktu. *Schema* diharapkan jarang berubah dan bersifat statis. Sedangkan, *instance* akan sering berubah setiap terjadi transaksi data dan bersifat dinamis.

>[!notes]
>*Physical Data Independence* adalah kemampuan untuk mengubah skema fisik, tanpa mengubah skema logisnya. Secara umum, *interface* antara level dan komponen harus didefinisikan dengan baik sehingga perubahan dalam beberapa komponen tidak mengubah komponen lain

## DDL dan DML
Untuk berinteraksi dengan data dan *database*, kita menggunakan dua konsep bahasa, yaitu Data Definition Language (DDL) dan Data Manipulation Language (DML). 

DDL digunakan untuk membuat dan mendefinisikan *database schema*. Hasilnya akan disimpan sebagai *metadata*.
```sql
create table instructor {
	ID char(5),
	name varchar(20),
	dept_name varchar(20),
	salary numeric(8,2)
}
```

DML digunakan untuk memanipulasi isi data (kueri, penyisipan, penghapusan, pembaruan). Secara umum, terdapat dua tipe DML.
1. Prosedural DML, membutuhkan pengguna untuk menspesifikasikan data apa yang dibutuhkan dan bagaimana cara mendapatkan datanya.
2. Deklaratif DML, membutuhkan pengguna untuk menspesifikasikan data apa yang dibutuhkan tanpa menspesifikan bagaimana cara mendapatkan datanya.

## SQL
SQL merupakan bahasa kueri nonprosedural. SQL mengambil satu atau beberapa tabel sebagai input, tetapi akan selalu mengembalikan satu tabel sebagai output.

Misal, untuk mencari seluruh `instructor` dalam departemen `Comp. Sci.`, kita dapat melakukan kueri:
```sql
select name
from instructor
where dept_name = 'Comp. Sci.'
```

## Arsitektur dan Pengguna  Database
Sistem basis data dapat disusun dalam berbagai arsitektur, paling umum adalah _Two-tier_ dan _Three-tier_. 

Pada arsitektur dua lapis, aplikasi pengguna berinteraksi langsung dengan sistem basis data di server. Sedangkan pada arsitektur tiga lapis, terdapat lapisan tambahan berupa _application server_ yang menangani logika bisnis sebelum akhirnya mengakses basis data.

Pengguna sistem ini pun bervariasi, mulai dari _naive users_ yang hanya menggunakan antarmuka aplikasi, _application programmers_ yang menulis kode program, hingga _Database Administrator_ (DBA). DBA memegang peran krusial sebagai pemegang kendali pusat yang bertanggung jawab atas pengelolaan struktur, otorisasi akses pengguna, serta pemeliharaan performa sistem secara keseluruhan.