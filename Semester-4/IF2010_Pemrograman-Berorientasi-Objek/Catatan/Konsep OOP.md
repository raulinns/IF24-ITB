---
cssclasses:
  - callouts-outlined
---
>[!notes] Definisi OOP
>[Meyer98]: Sebuah sistem yang dibangun berdasarkan metoda berorientasi objek adalah sebuah sistem yang komponennya di-enkapsulasi menjadi kelompok data dan fungsi, yang dapat mewarisi atribut dan sifat dari komponen lainnya, dan komponen-komponen tersebut saling berinteraksi satu sama lain.

Pemrograman Berorientasi Objek (OOP) pada dasarnya adalah sebuah metode pembangunan sistem perangkat lunak yang secara fundamental berbeda dari pendekatan struktural tradisional. Jika pemrograman struktural memecah masalah menjadi kumpulan data dan fungsi secara terpisah, OOP memecah masalah menjadi entitas-entitas mandiri yang disebut objek. Setiap objek dirancang untuk memiliki peran dan tanggung jawab masing-masing, layaknya pembagian tugas di dunia nyata. 

Menurut Bertrand Meyer, sistem OOP yang baik terdiri dari komponen-komponen yang membungkus data dan fungsi menjadi satu kesatuan (enkapsulasi), mampu mewarisi sifat dari komponen lain, dan saling berinteraksi untuk mencapai tujuan bersama. Berpikir dalam sudut pandang objek ini akan sangat memudahkan perancangan program karena struktur kode akan mencerminkan secara langsung bagaimana benda-benda di dunia nyata saling bekerja sama.

Baca: [[Pengenalan Paradigma OO]]

## Objek
Objek adalah benda atau sebuah entitas. Objek dapat berupa entitas apapun yang menyusun sistem dalam pemrograman. Objek bisa mewakili benda fisik seperti mobil dan buku, komponen antarmuka seperti tombol dan menu layar, hingga hal tak berwujud seperti lagu atau akun bank.

>[!notes]
>Objek dapat terbentuk atas objek-objek lain
>Contoh: Objek mobil terdiri atas objek mesin, chassis, body, dan seterusnya. Lalu, objek mesin dapat terdiri atas objek blok silinder, busi, piston, dan seterusnya.
>
> Dalam konsep OO, semua hal merupakan objek, termasuk tipe data, seperti integer, *character*, dan lain-lain. Namun, kebanyakan bahasap emrograman menganggap integer, dan seterusnya, sebagai tipe data primitif (bukan objek) untuk alasan kinerja.

Objek memiliki perilaku tertentu untuk memenuhi tanggung jawab atau layanan yang ia miliki. Tanggung jawab sebuah objek dapat berupa:
- Memberi informasi tertentu bagi objek lain yang meminta.
- Melakukan perhitungan
- Memberi tahu perubahan *state* dirinya. 
- Mengkoordinir objek-objek lain

Untuk menjalankan tanggung jawab ini, sebuah objek didefinisikan dengan sekelompok atribut dan metode. **Atribute** adalah informasi yang disimpan oleh objek untuk mengingat kondisinya (*state*). Pada ADT di prosedural, atribut ini dapat dilihat sebagai data dengan atribut sebagai *data type* dan *state* sebagai  *data value*. 

Selanjutnya, **method** adalah aksi atau perilaku yang dapat dilakukan suatu objek. 

>[!notes] Perbedaan antara Objek dengan ADT
>Sebuah objek yang dirancang dengan baik tidak memberikan informasi terkait isi objeknya ke objek lain. Objek lain tidak boleh mengetahui bagaimana sebuah objek mengelola informasi.

Perancangan objek dimulai dari tanggung jawab (*method*) apa yang dimiliki suatu objek, dilanjutkan dengan memutuskan informasi (*attribute*) apa yang diperlukan untuk menjalankan tanggung jawab tersebut.

### Message dan Protocol
**Message** adalah komunikasi formal yang dikirim oleh sebuah objek ke objek lainnya untuk meminta sebuah layanan. *Message* diperlukan karena  setiap objek bekerja secara mandiri dan datanya tertutup, sehingga mereka harus berkomunikasi untuk menyelesaikan masalah yang lebih besar. Beberapa jenis pesan yang ada adalah sebagai berikut.
- *Imperative*, menginstruksikan objek melakukan perubahan objek.
- *Informational*, memberitahu objek lain, tidak mengharapkan adanya perubahan *state*.
- *Interrogatory*, meminta informasi.

Objek menginvokasi *method* yang bersesuaian dengan *message* yang diterima, misal: `Stack.push(10);`. Artinya mengirim messag *push* dengan argumen `10` ke objek `Stack`. Objek `Stack` menginvokasi *method* `void push(int item)`.

**Protocol** atau *interface* adalah spesifikasi *message* apa saja yang dapat ditangani oleh sebuah objek. 

Saat sebuah objek menerima pesan yang sesuai dengan protokolnya, ia akan merespons dengan secara otomatis memicu atau menjalankan metode internal yang bersesuaian dengan pesan tersebut.

## Kelas
**Kelas** adalah *blueprint* atau rancangan statis yang mendeskripsikan objek-objek pada kode sumber. Namun, dikarenakan "semua hal adalah objek", secara konseptual Kelas pun adalah sebuah objek yang bertanggung jawab menciptakan objek-objek yang sesuai spesifikasi yang dimilikinya. Tetapi, dalam bahasa pemrograman, umumnya kelas bukan objek. 

Objek adalah instansiasi dari kelas. Maksudnya, objek adalah wujud nyata dari *blueprint* yang hidup pada program saat dijalankan.

Jika dibandingkan dengan prosedural, maka kita dapat menganggap bahwa Kelas sebagai tipe data dan objek adalah variabel terhadap tipe data tersebut. 

Proses penciptaan objek dari sebuah kelas ini memanggil sebuah metode khusus yang dinamakan konstruktor (_constructor_), yang bertugas mengalokasikan memori dan memberikan nilai awal bagi atribut-atribut objek yang baru lahir tersebut.

## Object Comparison
Dalam paradigma ini, terdapat perbedaan penting antara pembandingan referensi (*reference comparison*) dan pembandingan objek (*object comparison*). 

*Reference comparison* hanya mengecek apakah dua nama *reference* menunjuk pada satu wujud objek yang sama persis di dalam memori. Di sisi lain, pembandingan objek menelusuri isi atributnya untuk melihat apakah dua wujud objek yang fisiknya terpisah kebetulan memiliki nilai data yang sama persis

## Enkapsulasi 
Enkapsulasi adalah konsep membungkus data dan proses di dalam kelas, sehingga akses kepada data tersebut hanya dapat dilakukan melalui *method* atau *interface*.