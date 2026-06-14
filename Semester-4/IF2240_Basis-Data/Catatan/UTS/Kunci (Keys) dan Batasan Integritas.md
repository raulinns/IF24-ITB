---
cssclasses:
  - callouts-outlined
---
Untuk membedakan satu baris dengan baris lainnya dari ribuan data yang ada, model relasional menggunakan sistem Kunci (*Keys*). 

Proses identifikasinya dimulai dari *superkey*, yaitu satu atribut (atau gabungan atribut) yang mampu membedakan sebuah *tuple* atau baris secara unik. Dari sekian banyak kombinasi tersebut, kita menyeleksi bentuk yang paling ringkas dan minimal yang disebut _Candidate Key_. Dari pilihan-pilihan yang ada, dipilih satu *Candidate Key* yang paling ideal untuk dijadikan *Primary Key*. *Primary Key* yang dipilih harus merupakan atribut yang nilainya tidak pernah atau jarang berubah.

Selain itu, penggunaan *keys* juga dapat digunakan untuk menghubungkan data antar tabel. Skema relasiional mungkin dapat memiliki atribut yang berkoresponden dengan *primary key* dari relasi lain. Atribut ini dipanggil *foreign key*. 

```md
[ Tabel Induk: PROGRAM_STUDI ]
+---------------+--------------------+
| ID_Prodi (PK) | Nama_Prodi         |
+---------------+--------------------+
| IF            | Teknik Informatika |
| SI            | Sistem Informasi   |
+---------------+--------------------+
        ^
        | (Foreign Key merujuk kepada Primary Key)
        |
[ Tabel Anak: MAHASISWA ]
+----------+----------------+---------------+
| NIM (PK) | Nama_Mahasiswa | ID_Prodi (FK) |
+----------+----------------+---------------+
| 13521001 | Budi Santoso   | IF            |
| 18221002 | Siti Aminah    | SI            |
| 13521003 | Andi Wijaya    | IF            |
+----------+----------------+---------------+
```

## Integrity Constrain
 Agar data yang saling terhubung antartabel tidak berantakan, model ini dikawal oleh dua aturan batasan integritas yang sangat ketat. 

 Aturan pertama adalah *Domain Constraint* yang berarti setiap nilai dalam suatu kolom harus sesuai dengan domain (tipe data, format, dan *range* nilai yang sudah ditetapkan). 
 
Aturan Kedua adalah _Entity Integrity_ yang menetapkan bahwa tidak ada satupun bagian dari _Primary Key_ yang boleh bernilai kosong (_Null_).
 
Aturan ketiga adalah *Referential Integrity* yang menetapkan bahwa setiap nilai dalam *foreign key* harus cocok dengan nillai *primary key* yang ada di tabel yang dirujuk (atau *foreign key* bernilai `NULL` jika diizinkan). 

Untuk memenuhi aturan ketiga, terdapat beberapa aturan untuk menghapus baris di dalam tabel.
- **Restrict:** Mencegah penghapusan baris induk jika masih ada baris anak yang merujuk padanya. 
- **Cascade:** Jika baris induk dihapus, maka semua baris anak yang terkait dengannya akan ikut terhapus secara otomatis. 
- **Set-to-Null:** Jika baris induk dihapus, nilai foreign key pada baris-baris anak yang terkait akan diubah menjadi `NULL`.