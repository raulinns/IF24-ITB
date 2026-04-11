Desain arsitektur (*Architectural Design*) berkaitan dengan pemahaman tentang bagaimana sistem perangkat lunak harus diorganisasi dan merancang struktur keseluruhannya. Ini adalah hubungan kritis antara desain dan rekayasa kebutuhan, karena mengidentifikasi komponen struktural utama dalam sistem dan hubungan antar komponen tersebut.

Hasil akhir dari desain arsitektur adalah model arsitektur (*architectural model*) yang mendeskripsikan bagaimana sistem terorganisasi sebagai komponen yang saling berkomunikasi.

Arsitektur sistem secara keseluruhan biasanya dirancang pada tahap awal proses _agile_. *Refactoring* arsitektur cenderung mahal karena memengaruhi banyak komponen.

Arsitektur dibagi menjadi dua tingkat abstraksi:
1. **Architecture in the small:** Berkaitan dengan arsitektur program individu dan cara dekomposisinya menjadi komponen.

2. **Architecture in the large:** Berkaitan dengan arsitektur sistem perusahaan yang kompleks yang mencakup sistem, program, dan komponen lain, dan didistribusikan di berbagai komputer yang mungkin dimiliki oleh perusahaan berbeda

Keuntungan memiliki arsitektur yang eksplisit antara lain:
- Komunikasi Stakeholder: Arsitektur dapat digunakan sebagai fokus diskusi bagi para pemangku kepentingan sistem.

- Analisis Sistem: Memungkinkan analisis apakah sistem dapat memenuhi kebutuhan non-fungsionalnya (Non-Functional Requirements/NFR).

- Reuse Skala Besar: Arsitektur dapat digunakan kembali di berbagai sistem, dan arsitektur lini produk (_product-line architectures_) dapat dikembangkan.

# Representasi Arsitektur
Representasi yang paling sering digunakan adalah diagram balok informal (block diagrams) yang menunjukkan entitas dan hubungan. Namun, ini dikritik karena kurangnya semantik (tidak menunjukkan jenis hubungan atau properti yang terlihat). 

Diagram kotak dan garis (_Box and line diagrams_) sangat abstrak tetapi berguna untuk komunikasi dengan _stakeholder_ dan perencanaan proyek.

Meskipun proses desain arsitektur bersifat kreatif dan berbeda tergantung jenis sistem, sejumlah keputusan umum akan memengaruhi karakteristik non-fungsional sistem.

Karakteristik Arsitektur dan Sistem (NFR):

   - Kinerja (*Performance*): Lokalisasi operasi kritis dan minimalkan komunikasi. Gunakan komponen yang besar (_large-grain_).

- Keamanan (*Security*): Gunakan arsitektur berlapis (layered) dengan aset kritis di lapisan dalam.

-  Keselamatan (*Safety*): Lokalisasi fitur kritis keselamatan dalam sejumlah kecil subsistem.

 - Ketersediaan (*Availability*): Sertakan komponen redundan dan mekanisme toleransi kesalahan (_fault tolerance_)

   - _Maintainability:_ Gunakan komponen yang dapat diganti dan memiliki butir halus (_fine-grain_)

# Architectural Views
Untuk perancangan dan dokumentasi, biasanya diperlukan beberapa perspektif (views):

1. **Logical View:** Menunjukkan abstraksi kunci dalam sistem sebagai objek atau kelas objek. Dapat menggunakan **Class Diagram** atau **Object Diagram**

2. **Process View:** Menunjukkan bagaimana sistem terdiri dari proses yang berinteraksi saat _run-time_ (berguna untuk menilai kinerja dan ketersediaan). Dapat menggunakan **Activity Diagram**

3. **Development View:** Menunjukkan bagaimana perangkat lunak didekomposisi untuk pengembangan (pemecahan menjadi komponen untuk tim). Dapat menggunakan **Componen Diagram** atau **Package Diagram**

4. **Physical View:** Menunjukkan perangkat keras sistem dan bagaimana komponen perangkat lunak didistribusikan di seluruh prosesor (berguna untuk perencanaan _deployment_). Dapat menggunakan **Deployment Diagram**

5. **+1:** Dihubungkan menggunakan _use cases_ atau skenario.

Representasi *architectural views* dapat menggunakan *Unified Modeling Language* UML atau *Architectural Description Languages* (ADL).

# Pola Arsitektur (Architectural Patterns)
Pola arsitektur adalah deskripsi praktik desain yang baik, yang telah diuji dan dapat digunakan kembali untuk memecahkan masalah desain tertentu.

| Pola Arsitektur                 | Deskripsi Singkat                                                                                                                                                     | Keuntungan Utama                                                                                                    | Kerugian Utama                                                                                                                    |
| :------------------------------ | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------ | :-------------------------------------------------------------------------------------------------------------------------------- |
| **Model-View-Controller (MVC)** | Memisahkan data sistem (Model) dari representasi data (View) dan interaksi pengguna (Controller).                                                                     | Data dapat berubah terlepas dari representasinya; mendukung penyajian data yang sama dengan cara berbeda.           | Melibatkan kode dan kompleksitas tambahan jika model data sederhana.                                                              |
| **Layered Architecture**        | Mengatur sistem menjadi lapisan (abstract machines), di mana setiap lapisan menyediakan layanan ke lapisan di atasnya. Lapisan paling bawah menyediakan layanan inti. | Lapisan dapat diganti selama antarmuka dipertahankan; baik untuk pengembangan inkremental dan keamanan multi-level. | Sulit memisahkan lapisan dengan bersih; kinerja bisa menjadi masalah karena interpretasi bertingkat.                              |
| **Repository**                  | Semua data dikelola dalam repositori pusat yang dapat diakses oleh semua komponen; komponen tidak berinteraksi langsung.                                              | Komponen dapat independen; data dapat dikelola secara konsisten (misalnya _backup_).                                | Repositori adalah satu titik kegagalan (_single point of failure_); distribusi repositori sulit; inefisiensi komunikasi.          |
| **Client-Server**               | Fungsionalitas diorganisasi menjadi layanan yang dikirimkan dari server terpisah; klien mengakses layanan ini melalui jaringan.                                       | Server dapat didistribusikan; fungsionalitas umum tersedia untuk semua klien.                                       | Setiap layanan adalah satu titik kegagalan (rentan serangan DoS); kinerja tidak terduga (bergantung jaringan); masalah manajemen. |
| **Pipe and Filter**             | Pemrosesan data diorganisasi sehingga setiap komponen (filter) melakukan satu jenis transformasi data diskrit; data mengalir (pipe) secara sekuensial.                | Mudah dipahami; mendukung penggunaan kembali transformasi; evolusi mudah dengan menambah transformasi.              | Format transfer data harus disepakati antar transformasi (menambah _overhead_ sistem).                                            |

# Application Architectures
Arsitektur generik untuk jenis sistem perangkat lunak yang dapat dikonfigurasi dan diadaptasi untuk memenuhi kebutuhan spesifik.

Contoh Jenis Aplikasi Umum:
- **Transaction Processing Systems:** Memproses permintaan pengguna untuk informasi atau pembaruan database (misalnya sistem e-commerce, sistem reservasi). Dari sudut pandang pengguna, transaksi adalah urutan operasi yang koheren yang memenuhi tujuan.

- **Information Systems:** Memiliki arsitektur generik yang dapat diorganisasi sebagai arsitektur berlapis (User Interface, User Communications, Information Retrieval, System Database).

- **Web-based Information Systems:** Biasanya diimplementasikan sebagai arsitektur _multi-tier client-server_ (Web Server, Application Server, Database Server).

- **Language Processing Systems:** Menerima bahasa (natural atau artifisial) sebagai input dan menghasilkan representasi lain (misalnya _compiler_, penerjemah perintah).

# UML 2.0
## Component Diagrams
Inti dari desain arsitektur modern adalah konsep **Komponen**. Dalam UML 2.0, komponen didefinisikan sebagai unit modular yang otonom, memiliki _interface_ yang terdefinisi dengan baik, dan dapat diganti (_replaceable_) dalam lingkungannya. Komponen menyembunyikan detail internalnya (enkapsulasi). Komponen digambarkan sebagai persegi panjang dengan kata kunci `<<component>>` dan terkadang sebuah ikon komponen standar.

Komponen memiliki beberapa elemen kunci:
1. **Interface (Antarmuka)**: Ini adalah elemen terpenting yang mendefinisikan sekumpulan operasi. Ada dua jenis utama:
    - **Provided Interface**: Merepresentasikan layanan yang _ditawarkan_ oleh komponen. Notasinya menggunakan simbol "ball" (atau lolipop).
        
    - **Required Interface**: Merepresentasikan layanan yang _dibutuhkan_ oleh komponen dari lingkungannya. Notasinya menggunakan simbol "socket" (atau mangkuk).
        
2. **Port**: Ini adalah titik interaksi spesifik (digambarkan sebagai kotak kecil di tepi komponen) yang menghubungkan _interface_ komponen dengan lingkungannya. Port mengisolasi internal komponen dari dunia luar.
    
3. **Views (Internal vs. Eksternal)**: Komponen dapat dilihat sebagai **External View** (_black box_), yang hanya menunjukkan _interface_ publiknya, atau sebagai **Internal View** (_white box_), yang menunjukkan kelas atau komponen lain di dalamnya yang merealisasikan perilakunya.
    
4. **Konektor (Connector)**: Ada dua jenis konektor utama untuk merakit komponen. **Assembly Connector** adalah koneksi "ball-and-socket" standar yang menghubungkan _provided interface_ satu komponen ke _required interface_ komponen lain. **Delegation Connector** digunakan dalam _internal view_ untuk mendelegasikan panggilan dari port eksternal komponen ke bagian internalnya, yang penting untuk dekomposisi hierarkis.

## Deployment Diagrams

Diagram Deployment terkait erat dengan Diagram Komponen, namun berfokus pada _Physical View_. Diagram ini menunjukkan hubungan fisik antara perangkat keras dan perangkat lunak dalam sistem dan di mana komponen akan berada saat _run-time_.

Elemen utamanya adalah:
- **Node**: Mewakili sumber daya perangkat keras seperti server, klien, atau perangkat lain. Node digambarkan sebagai boks tiga dimensi.
    
- **Artifact**: Mewakili bagian fisik dari informasi, seperti file `.java`, file `.jar`, file eksekutabel, atau tabel database. Notasinya adalah persegi panjang dengan `<<artifact>>` dan ikon halaman.
    
- **Manifestation**: Ini adalah hubungan yang menunjukkan bahwa sebuah _artifact_ merupakan implementasi fisik dari sebuah _komponen_. Ini digambarkan sebagai panah putus-putus berlabel `<<manifest>>` dari _artifact_ ke _komponen_.

## Pemetaan dari Data Flow
Selain pemodelan berbasis komponen, salindia juga menyinggung teknik _structured design_ yang memetakan arsitektur dari Data Flow Diagram (DFD). Proses ini melibatkan identifikasi jenis aliran data dan pemetaannya ke dalam struktur program (seperti _Structured Chart_) menggunakan dua teknik utama: **Transform Mapping** dan **Transaction Mapping**.