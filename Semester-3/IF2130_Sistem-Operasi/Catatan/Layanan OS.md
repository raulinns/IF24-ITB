Sebuah OS menyediakan lingkungan untuk mengeksekusi program. Ini membuat beberapa layanan tersedia untuk program dan pengguna dari program tersebut. Layanan ini bisa berbeda antar sistem, tetapi secara umum terbagi menjadi dua, yaitu layanan yang membantu pengguna dan layanan yang mengefisensikan sistem. 
>[!img-caption] ![[Pasted image 20251020001412.png]]

Berdasarkan sumber, Bab 2.1 membahas tentang **Layanan Sistem Operasi (_Operating-System Services_)**, yaitu berbagai fungsi yang disediakan oleh sistem operasi (OS) bagi program dan penggunanya. Layanan-layanan ini dirancang untuk mempermudah tugas pemrograman bagi pengembang.

Secara umum, layanan OS dibagi menjadi dua kelompok utama: yang membantu pengguna dan yang memastikan operasi sistem yang efisien.

## Layanan yang Membantu Pengguna

Kelompok layanan ini menyediakan fungsi-fungsi yang secara langsung membantu interaksi pengguna dan eksekusi program.

|Layanan|Deskripsi dan Contoh|
|:--|:--|
|**Antarmuka Pengguna (_User Interface/UI_)**|Hampir semua OS memiliki UI, yang bisa berupa: **GUI** (sistem jendela dengan _mouse_ dan _keyboard_), **CLI** (_Command-Line Interface_) yang menggunakan perintah teks, atau antarmuka **layar sentuh** (_touch-screen_) pada perangkat seluler.|
|**Eksekusi Program (_Program Execution_)**|OS harus mampu memuat program ke memori dan menjalankannya. Program harus dapat mengakhiri eksekusinya, baik secara normal maupun abnormal (menunjukkan kesalahan).|
|**Operasi I/O (_I/O Operations_)**|Program yang berjalan mungkin memerlukan I/O, yang melibatkan perangkat I/O atau _file_. Demi efisiensi dan perlindungan, pengguna umumnya tidak dapat mengontrol perangkat I/O secara langsung; oleh karena itu, OS menyediakan mekanisme untuk melakukan I/O melalui _system call_.|
|**Manipulasi Sistem File (_File-System Manipulation_)**|Program perlu membaca, menulis, membuat, dan menghapus _file_ dan direktori. OS juga dapat menyertakan manajemen izin (_permissions_) untuk mengontrol akses ke _file_ atau direktori berdasarkan kepemilikan.|
|**Komunikasi (_Communications_)**|Memungkinkan pertukaran informasi antarproses, baik yang berada di komputer yang sama maupun di sistem yang berbeda melalui jaringan. Ini dapat diimplementasikan melalui **memori bersama (_shared memory_)** atau **pengiriman pesan (_message passing_)**.|
|**Deteksi Kesalahan (_Error Detection_)**|OS perlu mendeteksi dan mengoreksi kesalahan yang mungkin terjadi di _hardware_ (CPU, memori, I/O) maupun pada program pengguna (misalnya, _arithmetic overflow_). Tindakan yang diambil OS bervariasi, mulai dari menghentikan sistem hingga menghentikan proses yang menyebabkan kesalahan.|

## Layanan untuk Efisiensi Sistem

Kelompok layanan ini ada untuk memastikan operasi sistem itu sendiri berjalan secara efisien, terutama dalam sistem _multiprocess_.

|Layanan|Deskripsi dan Contoh|
|:--|:--|
|**Alokasi Sumber Daya (_Resource Allocation_)**|Ketika banyak proses berjalan, sumber daya seperti siklus CPU, memori utama, dan penyimpanan _file_ harus dialokasikan secara adil. OS menggunakan rutin penjadwalan CPU (_CPU scheduling_) untuk menentukan penggunaan CPU dan juga rutin untuk mengalokasikan perangkat periferal.|
|**Pencatatan (_Logging_)**|OS melacak penggunaan berbagai jenis sumber daya komputer oleh program. Catatan ini dapat digunakan untuk tujuan akuntansi (penagihan pengguna) atau untuk mengumpulkan statistik penggunaan yang berguna bagi administrator sistem.|
|**Proteksi dan Keamanan (_Protection and Security_)**|**Proteksi** melibatkan pengendalian semua akses ke sumber daya sistem untuk mencegah satu proses mengganggu proses lain atau OS itu sendiri. **Keamanan** melibatkan pertahanan sistem dari ancaman eksternal dan internal, dimulai dari autentikasi pengguna (biasanya dengan kata sandi) dan meluas ke pertahanan perangkat I/O eksternal.|
