---
cssclasses:
  - callouts-outlined
---
**Data** adalah representasi tersimpan dari objek atau peristiwa yang memiliki makna. Sedangkan, **Informasi** adalah hasil proses dari data yang digunakan untuk meningkatkan pengetahuan (*knowledege*) seseorang yang menggunakan data.

Data dapat digolongkan menjadi data yang terstruktur dan data tidak terstruktur. 
- Data terstruktur (*structured data*) merupakan data yang memiliki format tetap, seperti angka, teks, tanggal, dan lain-lain
- Data tidak terstruktur (*unstructured data*) merupakan data yang tidak memiliki format tetap, seperti gambar, video, dokumen teks panjang, dan lain-lain.

**Basis data** merupakan kumpulan data yang saling berelasi dan diorganisasi untuk kemudahan akses serta pengelolaan. Pengelolaannya dilakukan oleh perangkat lunak yang disebut _Database Management System_ (DBMS). DBMS bertindak sebagai lapisan perantara antara pengguna dengan data fisik, memastikan pengelolaan data skala besar berjalan efisien dan aman, seperti yang dilakukan oleh sistem populer macam MySQL atau PostgreSQL.

**Metadata** adalah data yang digunakan untuk mendeskripsikan properti dan konteks dari data pengguna, termasuk tipe data, ukuran isi data (*panjang, nilai minimal, nilai maksimal*), nilai yang diperbolehkan, dan konteks data.

>[!abstract] Narasi
> Sebelum adanya *database*, data disimpan dalam sistem pemrosesan berkas di mana setiap program/aplikasi mengelola berkas datanya sendiri. Pendekatan ini memicu berbagai kekurangan, sebagai berikut:
> 1. Setiap program harus menyimpan metadata dari tiap *file* yang digunakan
> 2. Program yang berbeda harus menggunakan *copies* untuk data yang sama.
> 3. Kontrol data tidak tersentralisasi dan tidak konkuren, sehingga bisa terjadi inkonsistensi
> 4. Format file yang tidak terstandardisasi
> 5. Sulit untuk menambah atau mengubah *constrain* dari tiap *file*, karena harus diubah di tiap sistem
> 6. Sulit untuk memberikan akses kepada pengguna

*Database* menjadi solusi dari permasalahan di atas, karena *database* menggunakan repositori pusat dari data yang dibagikan, data distandardisasi, dan akses/manajemennya lebih baik dan terbagi.

**DBMS** merupakan sistem perangkat lunak yang digunakan untuk membuat, mengelola, dan memberikan akses terkontrol kepada pengguna database. DBMS mengelola *data resource*, seperti OS mengelola *hardware resource*. 
![[Pasted image 20260210145029.png]]


Pendekatan *database* memiliki beberapa kelebihan, diiringi dengan kekurangan dan resikonya.

Kelebihan:
- Pengguna yang berbeda dapat diberikan tampilan/*view* yang berbeda terhadap suatu data
- Setiap data diakses dengan cara yang sama, menggunakan *data query language*, seperti SQL.
- Validasi data, aturan, dan *constraint* distandardisasi untuk menjaga kualitas data
- *Recovery* data lebih mudah.

Kekurangan dan Resiko:
1. Biaya instalasi dan konversi dari sistem yang lama
2. Membutuhkan spesialisasi baru untuk mengelola data
3. Kebiasaan lama sulit diubah

- Buat ER diagram
- Buat relational diagram
- buat databasenya
- query

## Database Application
Terdapat beberapa komponen dalam *database environment* yang digunakan:
- CASE Tools, 
- Repository, tempat menyimpan seluruh metadata
- DBMS, perangkat lunak untuk mengatur *database*
- Database, tempat menyimpan data
- Application Program, perangkat lunak untuk menggunakan data
- User Interface, tampilan grafik untuk pengguna
- Data Administrator, aktor yang bertanggung jawab untuk mengelola *database*
- System Developers, aktor yang mendesain *database* dan perangkat lunak
- End Users, aktor yang menggunakan aplikasi dan *database*

![[Pasted image 20260212132315.png]]

![[Pasted image 20260212132322.png]]

