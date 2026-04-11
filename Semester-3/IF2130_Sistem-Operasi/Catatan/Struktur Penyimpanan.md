CPU hanya dapat memuat instruksi dari memori, sehingga setiap program harus dimuat ke memori sebelum dijalankan. Biasanya, komputer menjalankan mayoritas programnya dari *rewritable memory* atau yang biasa disebut *random-access  memory*/RAM. Memori ini diimplementasikan menggunakan teknologi semkonduktor bernama *dynamic random-access memory* (DRAM). 

# Volatile vs Nonvolatile
Program pertama yang dijalankan pada komputer adalah *bootstrap program*, yang nantinya akan menjalankan sistem operasi. RAM bersifat *volatile* artinya kehilangan kontennya ketika dayanya dimatikan atau diputus, karena ini kita tidak dapat menyimpan *bootstrap program* di RAM. Untuk memenuhi kebutuhan, kita dapat menggunakan penyimpanan yang bersifat nonvolatile, misalnya *electrically erasable programmable read-only memory* (EEPROM) atau *firmware* lain. EEPROM dapat diubah, tetapi tidak dapat diubah terlalu sering, serta kecepatan aksesnya rendah. EEPROM biasanya mengandung program statis dan data yang tidak sering digunakan. 

>[!notes] Unit Penyimpanan
>Unit dasar penyimpanan komputer adalah **bit**, yang bernilai 0 atau 1. Meski begitu, unit terkecil yang praktis digunakan adalah **byte**, yang terdiri dari 8 bit. Komputer umumnya memiliki instruksi untuk memindahkan data per byte, bukan per bit.
>
> Penyimpanan dan _throughput_ komputer umumnya diukur dalam **byte**. Standar pengukurannya adalah: 
> **Kilobyte (KB):** 1.024 byte, **Megabyte (MB):** 1.024² byte (1.048.576 byte), **Gigabyte (GB):** 1.024³ byte, **Terabyte (TB):** 1.024⁴ byte, **Petabyte (PB):** 1.024⁵ byte.

Hanya menggunakan RAM yang bersifat *volatile* terkadang tidak dimungkinkan untuk menjalankan sistem komputer, sehingga dibutuhkan *secondary storage* dengan alasan sebagai berikut. 
1. Memori utama terlalu kecil untuk menyimpan semua program dan data secara permanen.
2. Memori utama bersifat *volatile* sehingga kontennya hilang saat dayanya dimatikan.

*Secondary storage* biasanya menggunakan *device*, seperti *hard-disk drive* (HDD) dan *nonvolatile memory device* (NVM). Penyimpanan sekunder harus mampu menampung sejumlah besar data secara permanen. Sebagian besar program (sistem dan aplikasi) disimpan dalam penyimpanan sekunder hingga dimuat ke memori.

Terdapat juga **Penyimpanan Tersier** (**Tertiary Storage***), ini adalah penyimpanan yang lebih lambat dan lebih besar (seperti _magnetic tape_ atau _optical disk_) yang digunakan untuk tujuan khusus, seperti salinan cadangan (_backup_)

>[!img-caption] ![[Pasted image 20251019175220.png]]

# Eksekusi Instruksi
Setiap bentuk memori menyediakan *array of bytes* dan setiap *byte* memiliki alamatnya sendiri. Interaksi kepada memori dapat dilakukan dengan urutan **load or store instruction** kepada alamat memori. `load` *instruction* memindahkan *byte* dari memori utama ke register internal d CPU. Sedangkan, `store` *instruction* memindahkan konten dari register ke memori utama. 

Siklus mengeksekusi instruksi dilakukan dengan menggunakan arsiktektur **von Neumann**. 
1. **Fetch (Ambil):** Mengambil instruksi dari memori utama.
2. **Decode (Dekode):** Menerjemahkan instruksi tersebut.
3. **Execute (Eksekusi):** Menjalankan instruksi. Ini mungkin melibatkan pengambilan _operand_ (data) dari memori, melakukan perhitungan, dan kemudian **menyimpan (Store)** hasilnya kembali ke memori.

