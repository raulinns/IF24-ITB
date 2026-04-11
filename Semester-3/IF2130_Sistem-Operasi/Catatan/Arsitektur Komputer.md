Sebuah sistem komputer dapat diorganisasikan dengan beberapa cara yang berbeda, yang kita kategorikan berdasarkan jumlah prosesor yang digunakan.

# Single-Processor Systems
Sistem prosesor tunggal tradisional hanya menggunakan satu prosesor yang berisi satu CPU dengan satu _core_ pemrosesan. _Core_ adalah unit komputasi dasar CPU. CPU utama ini mampu mengeksekusi _instruction set_ tujuan umum, termasuk instruksi dari proses. Sistem ini mungkin memiliki prosesor tujuan khusus lainnya, seperti _controller_ untuk disk, _keyboard_, dan tampilan grafis. Prosesor khusus ini menjalankan _instruction set_ terbatas, tidak menjalankan proses, dan mungkin dikelola oleh sistem operasi (OS), atau bisa juga merupakan komponen tingkat rendah yang dibuat langsung dalam _hardware_ tanpa interaksi OS. Meskipun prosesor khusus banyak digunakan, hal itu tidak mengubah sistem prosesor tunggal menjadi _multiprocessor_. Jika, hanya terdapat satu *general-purpose* CPU dengan satu *core* pemrosesan, maka sistem ini tetap tergolong *single-processor system*. Namun, sangat sedikit sistem komputer kontemporer yang masih diklasifikasikan sebagai sistem prosesor tunggal berdasarkan definisi ini.

# Multiprocessor Systems
Saat ini, sistem _multiprocessor_ mendominasi lanskap komputasi, mulai dari perangkat seluler hingga _server_. Sistem ini memiliki dua (atau lebih) prosesor, yang masing-masing secara tradisional memiliki CPU _single-core_, yang berbagi _bus_ komputer dan terkadang berbagi _clock_, memori, dan perangkat periferal. Keuntungan utama dari sistem _multiprocessor_ adalah peningkatan _throughput_ (diharapkan lebih banyak pekerjaan selesai dalam waktu yang lebih singkat). Namun, rasio _speed-up_ dengan $N$ prosesor selalu kurang dari $N$ karena adanya _overhead_ yang timbul dalam menjaga semua bagian bekerja dengan benar, ditambah persaingan untuk sumber daya bersama.

## Symmetric Multiprocessing (SMP)
SMP merupakan sistem _multiprocessor_ yang paling umum. Setiap prosesor CPU adalah sejawat (_peer_) yang menjalankan semua tugas, termasuk fungsi sistem operasi dan proses pengguna. Tiap CPU memiliki *register* dan *cache*-nya sendiri (baik lokal, maupun *private*). Namun,  semua *processor* menggunakan memori fisik yang sama melalui *system bus*. 

 Dalam arsitektur SMP, banyak proses dapat berjalan secara bersamaan ($N$ proses dapat berjalan jika ada $N$ CPU) tanpa kinerja memburuk secara signifikan. Sistem ini memungkinkan proses dan sumber daya (seperti memori) untuk dibagi secara dinamis di antara berbagai prosesor. Meskipun prosesor-prosesor terpisah, ada kemungkinan satu prosesor menganggur (*idle*) sementara prosesor lain kelebihan beban (*overloaded*), yang dapat mengakibatkan inefisiensi. Inefisiensi dapat dihindari jika prosesor berbagi struktur data tertentu. 

>[!img-caption] ![[Pasted image 20251019192904.png]]

## Multicore System
_Multicore_ berarti menyertakan banyak core komputasi pada chip CPU yang sama. Sumber lain juga mendefinisikan _multicore_ sebagai menyertakan banyak _computing core_ pada _chip_ tunggal. *Multicore system* dapat menjadi lebih efisien dibanding *chip* yang banyak, tetapi dengan *single core*, karena komunikasi *on-chip* lebih cepat dibanding komunikasi *between-chip*.

Dalam gambar di bawah adalah *dual-core* dengan dua *core* di dalam *chip processor* yang sama. Untuk tiap *core* memiliki register dan L1 *cache*. Namun, untuk L2 *cache* adalah lokal terhadap *chip* dan digunakan secara bersama. Terlepas dari konsiderasi arsitektur, seperti *cache*, memori, dan penggunaan *bus*, *multicore processor* dengan $N$ *core* tampil di OS sebagai $N$ CPU.  
>[!img-caption] ![[Pasted image 20251019194159.png]]\

>[!notes] Definisi Komponen Sistem Komputer
>- **CPU**— Perangkat keras yang mengeksekusi instruksi. 
>- **Prosesor (Processor)**— Sebuah chip fisik yang berisi satu atau lebih CPU.
>- **Core (Inti)**— Unit komputasi dasar dari CPU.
>- **Multicore**— Menyertakan beberapa _core_ komputasi pada CPU yang sama.
>- **Multiprocessor**— Menyertakan beberapa prosesor.

## Non-Uniform Memory Access (NUMA)
Ini adalah pendekatan alternatif untuk _multiprocessing_ skala besar, di mana setiap CPU (atau kelompok CPU) memiliki **memori lokalnya sendiri** yang diakses melalui _bus_ lokal yang kecil dan cepat

   Semua CPU terhubung oleh _interconnect_ sistem bersama (_shared system interconnect_), sehingga semua CPU berbagi satu ruang alamat fisik (_physical address space_). Keuntungannya adalah akses ke memori lokal sangat cepat dan tidak ada perebutan di _system interconnect_. NUMA dapat _scale_ lebih efektif seiring bertambahnya prosesor, tetapi memiliki potensi kelemahan berupa peningkatan latensi ketika sebuah CPU harus mengakses memori jarak jauh (_remote memory_) melintasi _system interconnect_

>[!img-caption] ![[Pasted image 20251019204442.png]]

**Blade Servers:** Ini adalah sistem di mana beberapa _processor board_, _I/O board_, dan _networking board_ ditempatkan dalam _chassis_ yang sama. Setiap _board_ _blade-processor_ _boot_ secara independen dan menjalankan OS-nya sendiri. Intinya, mereka terdiri dari beberapa sistem _multiprocessor_ independen

# Clustered Systems
Komponen: _Clustered systems_ mengumpulkan **beberapa CPU** atau beberapa sistem individu yang disebut _node_.  _Clustered systems_ berbeda dari sistem _multiprocessor_ tradisional (_Symmetric Multiprocessing_ atau _Multicore Systems_) karena mereka terdiri dari **dua atau lebih sistem individu** (_node_) yang digabungkan. Setiap _node_ ini biasanya merupakan sistem _multicore_. Sistem berklaster dianggap sebagai sistem yang terkopel secara longgar (*loosely coupled*). 

Secara sederhana, _clustered systems_ adalah kumpulan komputer-komputer terpisah yang terhubung dalam satu jaringan dan beroperasi seolah-olah mereka adalah satu sistem tunggal yang sangat kuat. Mereka berbagi penyimpanan (_storage_) dan terhubung erat melalui jaringan lokal berkecepatan tinggi.

Tujuan dari *clustering* adalah sebagai berikut:

1. High Availability (Ketersediaan Tinggi).  High availability berarti layanan akan tetap beroperasi meskipun salah satu komputer (disebut _node_) dalam klaster mengalami kegagalan.

2. Load Balancing (Penyeimbangan Beban). Klaster dapat mendistribusikan beban kerja (permintaan layanan) secara merata ke semua _node_ yang ada. Hal ini memastikan tidak ada satu pun _node_ yang kelebihan beban sementara yang lain menganggur, sehingga meningkatkan kinerja dan responsivitas sistem secara keseluruhan.

3. High-Performance Computing (HPC). Untuk tugas-tugas komputasi yang sangat berat (misalnya, simulasi ilmiah atau permodelan cuaca), klaster dapat memecah satu tugas besar menjadi bagian-bagian kecil dan menjalankannya secara paralel di banyak _node_ sekaligus. Ini secara dramatis mengurangi waktu yang dibutuhkan untuk menyelesaikan komputasi.

Clustering dapat disusun secara asimetris atau simetris:
1. **Asymmetric Clustering:** Satu mesin berada dalam mode **hot-standby** dan hanya memantau _server_ aktif. Jika _server_ aktif gagal, _host hot-standby_ menjadi _server_ aktif.
2. **Symmetric Clustering:** Dua atau lebih _host_ menjalankan aplikasi dan saling memantau. Struktur ini lebih efisien karena menggunakan semua _hardware_ yang tersedia, tetapi memerlukan lebih dari satu aplikasi untuk dapat berjalan
