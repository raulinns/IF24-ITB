Pemodelan Berbasis Kelas menggunakan Pendekatan Berorientasi Objek (_Object-Oriented/OOP_). Pendekatan OOP mengintegrasikan data dan prosedur/fungsi yang terkait secara semantik, berlawanan dengan pendekatan terstruktur yang memisahkan keduanya.

Pemodelan ini merepresentasikan manipulasi terhadap objek, operasi yang diaplikasikan pada objek, dan kolaborasi yang terjadi antar kelas dari objek

# Objek
Teknik *Object-Oriented* didasarkan pada penggunaan kelas yang bertindak sebagai abstraksi data dan seperangkat prosedur yang bertindak atas data tersebut. Sistem OOP memanfaatkan abstraksi untuk membantu membuat perangkat lunak menjadi tidak terlalu rumit. Abstraksi adalah sesuatu yang membebaskan dari keharusan berurusan dengan detail.  Sistem OOP menggabungkan abstraksi prosedural dengan abstraksi data. 

Paradigma berorientasi objek adalah pendekatan untuk solusi masalah di mana semua perhitungan dilakukan dalam konteks objek. 

Objek adalah contoh konstruksi pemrograman, biasanya disebut kelas, yang merupakan abstraksi data dan yang berisi abstraksi prosedural yang beroperasi pada objek. Dalam paradigma berorientasi objek, program yang berjalan dapat dilihat sebagai kumpulan objek yang berkolaborasi untuk melakukan tugas yang diberikan. 


>[!img-caption] ![[Pasted image 20251022043919.png]]

Objek dapat berisi dua hal:
1. Properti mencirikan objek, menggambarkan keadaan saat ini.
2. Perilaku adalah cara objek bertindah dan bereaksi, mungkin mengubah kondisinya.

# Kelas
Kelas adalah unit abstraksi data dalam OOP. Kelas adalah modul perangkat lunak yang mewakili dan mendefinisikan set objek yang sama. Semua objek dengan properti dan perilaku yang sama adalah contoh dari satu kelas. 

Dua aturan untuk membantu memutuskan apa yang harus menjadi kelas dan apa yang harus menjadi instance:
- Secara umum, sesuatu harus berupa kelas jika dapat memiliki instance.
- Secara umum, sesuatu harus menjadi contoh jika itu jelas merupakan anggota tunggal dari set yang ditentukan oleh kelas.
>[!img-caption] ![[Pasted image 20251022044354.png]]

# Pemodelan Berbasis Kelas
Pemodelan ini merepresentasikan manipulasi terhadap objek, operasi yang diaplikasikan pada objek dan kolaborasi yang terjadi antara kelas dari objek. Elemen yang digunakan pada pemodelan ini adalah:
1. Kelas
2. Objek
3. Atribut
4. Operasi
5. Kolaborasi
6. Paket

## Tahapan Pembuatan Diagram Kelas
Proses pembuatan Diagram Kelas (tahap analisis) meliputi enam langkah utama:
1. **Identifikasi Kelas:** Mengenali kata benda (*noun*) yang terkait dengan keluar/masuk informasi dalam masalah (misalnya: entitas eksternal, laporan, peran, kejadian, tempat/lokasi, atau struktur).
2. Penentuan Atribut: Memilih karakteristik atau item data yang mendefinisikan kelas sesuai konteks masalah.
3. Penentuan Operasi: Mengidentifikasi kata kerja (*verb*) yang terkait dengan manipulasi data, komputasi, pertanyaan tentang _state_ objek, atau pemantauan _event_.
4. Penentuan Hubungan (Asosiasi) Antar Kelas: Mendefinisikan keterkaitan semantik (Asosiasi, Agregasi, Komposisi, Dependensi, Generalisasi/Inheritance).
5. Membuat Diagram Kelas.
6. Membuat Diagram Paket (jika perlu).

## Jenis-Jenis Kelas
Kelas Entitas (*Entitity Class*)/Kelas Model/Kelas Bisnis diambil dari masalah yang akan dipecahkan. Biasanya disimpan di basis data dan digunakan selama aplikasi berjalan.

Kelas Batas (*Boundary Class*)  digunakan sebagai *interface*/antarmuka yang dilihat atau digunakan sebagai interaksi dengan/oleh pengguna.

Kelas Pengendali (*Controller Class*) menangani suatu unit pekerjaan dari awal hingga selesai
- *Create* / *Update* objek entitas
- Instansiasi objek batas 
- Melakukan komunikasi antara sekumpulan objek 
- Validasi komunikasi data antar aktor

## Jenis-Jenis Hubungan Antar Kelas
1. Asosiasi (_Association_).  Asosiasi menunjukkan keterkaitan semantik antara dua kelas. Ini adalah jenis hubungan yang paling umum. Ditandai dengan garis.

2. *Multiplicity* (Kardinalitas). Hubungan asosiasi diperjelas dengan Multiplicity (sering disebut kardinalitas dalam _ER Diagram_). Multiplicity digunakan untuk menunjukkan jumlah instansiasi yang mungkin terjadi pada suatu asosiasi. Ditandai dengan garis dan angka di ujung kelas untuk menunjukkan instansiasi yang mungkin terjadi dalam hubungan tersebut.

3. Agregasi (_Aggregation_). Agregasi adalah jenis hubungan khusus yang menunjukkan hierarki **"whole-part"** (keseluruhan-bagian). Ini menunjukkan bahwa satu kelas (bagian, _part_) adalah bagian dari kelas lain (keseluruhan, _whole_). Agregasi menggambarkan bahwa bagian tersebut dapat eksis secara independen di luar keseluruhan. Ditandai dengan belah ketupat putih (kosong) di ujung yang merupakan *whole* dari *part*. 

4. Komposisi (_Composition_).  Komposisi adalah bentuk agregasi yang lebih kuat. Ini menunjukkan bahwa bagian tersebut **tidak dapat eksis** tanpa adanya keseluruhan. **Sifat:** Dalam komposisi, objek bagian harus ada untuk membentuk objek keseluruhan. Ditandai dengan belah ketupat hitam (solid) di ujung yang merupakan *whole*.

5. Generalisasi (_Generalization_). Generalisasi, juga dikenal sebagai *Inheritance* (Pewarisan) atau hubungan "is-a", menunjukkan bahwa satu kelas merupakan spesialisasi dari kelas lain. Kelas anak (subkelas) mewarisi semua tanggung jawab (atribut dan operasi) dari kelas induk (superkelas). Ditandai dengan segitiga kosong/putih pada ujung kelas induk.

6. Dependensi (_Dependency_).  Dependensi menunjukkan hubungan ketergantungan (*client-server*) antar kelas. Kelas _Client_ bergantung pada Kelas _Server_. Kelas _Client_ membutuhkan Kelas _Server_ untuk implementasi penuhnya, namun ketergantungan ini bersifat sementara atau tidak permanen. Direpresentasikan dengan garis putus-putus dan memiliki ujung segitiga hitam kepada kelas yang digantungi.

