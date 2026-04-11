*Thread* adalah unit dasar dari utilisasi CPU. *Thread* terdiri dari *thread* ID, *program counter*, register, dan *stack*. *Thread* berbagi sumber daya tertentu dengan *thread* lain yang dimiliki oleh proses yang sama, termasuk: bagian kode, bagian data, dan sumber daya OS lainnya (seperti sinyal dan *file* yang terbuka). Sebuah proses tradisional memiliki satu _thread_ kontrol tunggal (_single thread of control_), ini yang dibahas di bab-bab sebelum **Chapter 4** (menganggap bahwa tiap proses adalah *single-threaded process*). Namun, nyatanya proses _multithreaded_ dapat menjalankan lebih dari satu tugas dalam satu waktu.

Dalam praktiknya, sebuah CPU hanya dapat mengeksekusi *thread*. Proses di sisi lain, merupakan unit kepemilikan sumber daya dan proteksi. Ia memiliki ruang alamat, file, dan sumber daya lainnya. Sedangkan, *thread* adalah unit untuk penjadwalan yang akan diproses CPU. 

Sebagian besar aplikasi _software_ modern bersifat _multithreaded_, diimplementasikan sebagai proses terpisah dengan beberapa _thread_ kontrol.

>[!img-caption] ![[Pasted image 20251020063248.png]]

Manfaat utama dari pemrograman _multithreaded_ dikategorikan sebagai berikut:

| Kategori Manfaat                     | Penjelasan                                                                                                                           |
| ------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| *Responsiveness* (Responsivitas) | Memungkinkan program interaktif untuk terus berjalan dan tetap responsif kepada pengguna meskipun sebagian darinya diblokir atau sedang melakukan operasi yang memakan waktu lama |
| *Resource* Sharing (Berbagi Sumber Daya) | _Thread_ secara _default_ berbagi memori dan sumber daya proses tempat mereka berada. Hal ini memungkinkan aplikasi memiliki beberapa aktivitas berbeda dalam ruang alamat (_address space_) yang sama |
|*Economy* (Ekonomi/Penghematan)|Pembuatan dan _context switch_ _thread_ lebih murah dan cepat dibandingkan dengan pembuatan dan _context switch_ proses, karena _thread_ berbagi sumber daya proses|
|*Scalability* (Skalabilitas)|Memungkinkan _thread_ berjalan secara **paralel** pada arsitektur _multiprocessor_ atau _multicore_, memaksimalkan penggunaan _core_ pemrosesan|

# Multicore Programming
Konkurensi (*Concurrency*) diartikan sebagai sistem yang mendukung lebih dari satu tugas dengan mengizinkan semua tugas untuk membuat kemajuan. Pada sistem _single-core_, ini dicapai dengan _context switching_ yang cepat (ilusi berjalan bersamaan). 

Sedangkan, paralelisme (*Parallelism*) diartikan sebagai sistem yang dapat melakukan lebih dari satu tugas secara harfiah pada saat yang bersamaan. Ini memerlukan perangkat keras _multi-core_ atau _multi-processor_.

Oleh karena itu, dimungkinkan untuk memiliki *concurrency* tanpa *parallelism* (misalnya, pada sistem single-core yang menjalankan banyak thread)

Tren menuju sistem _multicore_ memberikan tekanan pada pengembang untuk memanfaatkan _core_ pemrosesan ganda secara efektif. Dua jenis utama _parallelism_ adalah:
1. *Data Parallelism*: Berfokus pada pendistribusian subset data yang sama ke beberapa _core_ komputasi dan melakukan operasi yang sama pada setiap _core_.
2. *Task Parallelism*: Melibatkan pendistribusian tugas (_threads_) ke beberapa _core_ komputasi. Setiap _thread_ menjalankan operasi unik.

>[!img-caption] ![[Pasted image 20251020070208.png]]

# Multithreading Model
Bantuan untuk *thread* dapat diberikan pada *user level* untuk *user thread* atau pada *kernel level* untuk *kernel thread*. *User thread* dikelola sepenuhnya di atas kernel tanpa bantuan dari kernel. Sedangkan, *kernel thread* dikelola secara langsung oleh OS. 

| Model        | Pemetaan                                                             | + Pros                                                                  | - Cons                                                                                            |
| ------------ | -------------------------------------------------------------------- | ----------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| Many-to-One  | Banyak user thread → Satu kernel thread                              | Efisien karena manajemen thread di user space                           | Jika satu thread memanggil blocking system call, seluruh proses terblokir. (tidak bisa multicore) |
| One-to-One   | Satu user thread → Satu kernel thread                                | Lebih banyak concurrency dan memungkinkan parallelism di multiprocessor | Pembuatan thread mahal karena setiap user thread memerlukan kernel thread yang sesuai             |
| Many-to-Many | Banyak user thread → Jumlah kernel thread yang lebih kecil atau sama | Programmer bisa membuat banyak thread, dan dapat berjalan paralel       | Sulit diimplementasikan.                                                                          |

>[!img-caption] ![[Pasted image 20251020070328.png]]
>![[Pasted image 20251020070335.png]]
>![[Pasted image 20251020070345.png]]


# Thread Libraries (Bab 4.4)
Pustaka thread menyediakan **API** (Application Programming Interface) bagi programmer untuk membuat dan mengelola thread.

### Pendekatan Implementasi Pustaka
1.  **Pustaka Tingkat Pengguna (User-Level Library):**
    * Berjalan sepenuhnya di **user space**.
    * Tidak memerlukan dukungan kernel.
    * Memanggil fungsi pustaka **tidak menghasilkan system call** (hanya panggilan fungsi lokal).

2.  **Pustaka Tingkat Kernel (Kernel-Level Library):**
    * Didukung langsung oleh Sistem Operasi (Kernel).
    * Memanggil fungsi pustaka **akan menghasilkan system call** ke kernel.

### Tiga Pustaka Thread Utama

1.  **Pthreads (POSIX Threads):**
    * Sebuah **standar API** (IEEE 1003.1c), bukan implementasi.
    * Dapat diimplementasikan sebagai *user-level* atau *kernel-level*.
    * Umum digunakan di sistem UNIX-type (Linux, macOS).

2.  **Windows Threads:**
    * Pustaka **tingkat kernel** yang spesifik untuk sistem operasi Windows.

3.  **Java Threads:**
    * API untuk membuat dan mengelola thread di dalam program Java.
    * Dijalankan di atas **Java Virtual Machine (JVM)**.
    * JVM (di belakang layar) akan menggunakan pustaka thread milik sistem *host* (misal: Pthreads di Linux, Windows Threads di Windows).

---

	## Implicit Threadingq
### Tujuan dan Strategi

* **Masalah:** Mengelola ratusan atau ribuan thread secara manual di era *multicore* sangat sulit bagi developer.
* **Strategi (Implicit Threading):** Memindahkan tugas pembuatan dan manajemen thread dari **developer** ke **compiler dan pustaka run-time**.
* **Tugas Developer:** Developer hanya perlu mengidentifikasi **tugas (tasks)** yang bisa berjalan paralel, bukan mengelola *thread*-nya secara langsung.

### Pendekatan Implicit Threading
1.  **Thread Pools (Kumpulan Thread):**
    * **Konsep:** Sejumlah thread dibuat saat *startup* dan "tidur" di dalam *pool*.
    * **Alur Kerja:** Ketika *task* (pekerjaan) baru datang, *task* itu diserahkan ke *pool*. Thread yang sedang menganggur akan "bangun", mengambil *task*, mengerjakannya, lalu kembali tidur.
    * **Keuntungan:** Menghindari *overhead* (biaya) pembuatan thread baru terus-menerus dan membatasi jumlah thread yang aktif.
    * **Contoh:** Java `ExecutorFramework`.

2.  **Fork-Join Parallelism:**
    * **Model:** Sinkron. Sebuah thread induk (parent) membuat (*forks*) beberapa thread anak untuk mengerjakan sub-tugas. Thread induk kemudian **menunggu (joins)** sampai semua anak selesai untuk menggabungkan hasilnya.
    * **Penggunaan:** Sangat cocok untuk algoritma *divide-and-conquer* (misal: Quicksort).
    * **Contoh:** Java `ForkJoinPool`.

3.  **OpenMP:**
    * **Konsep:** Sebuah API dan arahan *compiler* (`#pragma omp parallel`) untuk C, C++, dan FORTRAN.
    * **Alur Kerja:** Developer menandai blok kode yang bisa berjalan paralel. *Compiler* dan *library* OpenMP akan secara otomatis membuat thread (biasanya sejumlah *core* CPU) untuk menjalankan blok tersebut.

4.  **Grand Central Dispatch (GCD):**
    * **Konsep:** Teknologi Apple untuk macOS dan iOS.
    * **Alur Kerja:** Developer menempatkan *task* (dalam bentuk *block* kode) ke dalam **antrian (dispatch queue)**.
        * *Serial Queue:* Menjalankan *task* satu per satu (FIFO).
        * *Concurrent Queue:* Menjalankan *task* secara paralel.
    * GCD kemudian yang mengelola *thread pool* internalnya (yang berbasis Pthreads) secara dinamis untuk mengeksekusi *task* di antrian tersebut.

# Isu pada Multithreading
Pemrograman _multithreaded_ menimbulkan beberapa tantangan khusus, sebagai berikut:
• **Context Switch**: Peralihan konteks (_context switch_) antara _thread-thread_ dalam proses yang sama (khususnya _user-level thread_) umumnya lebih cepat dan lebih murah daripada _context switch_ antar proses yang berbeda.

• **fork() dan exec()**: Jika satu _thread_ memanggil `fork()`, apakah proses baru menduplikasi **semua** **thread** atau **hanya** **thread** **yang memanggil** `fork()`? Jika `exec()` dipanggil segera setelah `fork()`, menduplikasi semua _thread_ tidak perlu.

• **Signal Handling**: Di mana sinyal harus dikirim dalam proses _multithreaded_? Opsi termasuk mengirim ke _thread_ yang berlaku, ke setiap _thread_, ke _thread_ tertentu, atau menunjuk satu _thread_ untuk menerima semua sinyal.

• **Thread Cancellation**: Mengakhiri _thread_ sebelum selesai. Ada **asynchronous cancellation** (segera mengakhiri) dan **deferred cancellation** (memeriksa secara berkala apakah harus diakhiri), dengan _deferred cancellation_ yang lebih disukai karena memungkinkan penghentian yang tertib.

• **Thread-Local Storage (TLS)**: Menyediakan setiap _thread_ dengan **salinan data sendiri** yang unik, meskipun _thread_ lain dalam proses yang sama berbagi data proses. TLS berbeda dari variabel lokal karena data TLS terlihat di seluruh pemanggilan fungsi.

• **Implisit Threading**: Strategi di mana pembuatan dan pengelolaan _threading_ diserahkan dari pengembang ke _compiler_ dan _run-time libraries_ (contoh: _Thread Pools_, _Fork Join_, OpenMP, GCD). Tujuannya adalah pengembang hanya perlu mengidentifikasi _task_ yang dapat berjalan paralel, bukan detail _thread_.