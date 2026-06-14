**Relation** adalah tabel dua dimensi dari data

Model Relasional diperkenalkan oleh E. F. Codd pada tahun 1970 yang merubah cara pengelolaan data yang berlandaskan teori himpunan. Dalam model ini, sebuah basis data dilihat sebagai kumpulan tabel dua dimensi yang disebut relasi. Setiap relasi terdiri dari baris yang disebut *record* atau *tuple* dan kolom yang berisi atribut. *Record* adalah satu kesatuan fakta atau data yang spesifik. Sedangkan, atribut berfungsi mendeskripsikan karakteristik atau properti dari data tersebut.

Sebuah tabel dapat disebut sebagai relasi, jika memenuhi seluruh kriteria berikut.
1. Memiliki nama yang unik.
2. Setiap atribut *value* harus atomik (tidak boleh, *multi-value* atau komposit).
3. Setiap baris harus unik (tidak boleh duplikat/setiap nilai).
4. Atribut dalam tabel harus memiliki nama.
5. Urutan dari kolom dan baris boleh tidak terurut.\

Setiap atribut dari sebuah relasi memiliki nama. Himpunan dari *value* yang dibolehkan dalam sebuah attribut dinamakan *domain of attribute*. Terdapat nilai spesial *null* yang merupakan anggota setiap domain. *Null value* akan menyebabkan komplikasi dalam banyak operasi, sehingga *null value* harus dihiraukan dan dipertimbangkan efeknya. *Null value* dapat berarti *value* tidak diketahui, *value* ada tetapi tidak tersedia, atribut tidak terdefinisi untuk *tuple* ini.

## Skema dan Instansi
Jika, $A_1, A_2, \dots, A_n$ merupakan atribut, maka $R = (A_1, A_2, \dots, A_n)$ merupakan skema relasi. Misal:
```
instructor = (ID, name, dept_name, salary)
```

Nilai dari sebuah relasi akan dispesifikasi dalam sebuah tabel. Sebuah elemen $t$ dalam sebuah relasi $r$ disebut *tuple* dan direpresentasikan dalam baris.

Skema Basis Data adalah struktur logis dari sebuah basis data. Sedangkan, Instansi Basis Data merupakan data aktual yang ditangkap dalam sebuah basis data dalam suatu waktu. 

```
Skema Relasi: instructor(ID, name, dept_name, salary)

Instansi Relasi (Contoh pada waktu T):
+-------+-----------+-------------+--------+
|   ID  |   name    |  dept_name  | salary |  <-- Atribut (Schema)
+-------+-----------+-------------+--------+
| 22222 | Einstein  | Physics     |  95000 |  <-- Tuple 1
| 12121 | Wu        | Finance     |  90000 |  <-- Tuple 2
| 32343 | El Said   | History     |  60000 |  <-- Tuple 3
+-------+-----------+-------------+--------+   (Instance)
```

Menyimpan semua informasi dalam satu *relation* akan menyebabkan beberapa kekurangan, seperti informasi yang direpetisi dan penggunaan *null value*. Teori normalisasi akan dapat mengatasi bagaimana cara mendesain skema relasional. 

$$
\Pi_{title}(course \bowtie (\Pi_{course\_id, semester, year}(\text{section}) \div \Pi_{semester,year} (section)))
$$