*System calls* menyediakan antarmuka ke layanan yang disediakan oleh OS. Panggilan ini umumnya tersedia dalam bentuk fungsi yang ditulis dalam bahasa C dan C++, meskipun tugas tingkat rendah yang memerlukan akses langsung ke _hardware_ mungkin ditulis menggunakan instruksi bahasa _assembly_. 

Program pengguna biasa tidak diizinkan mengakses perangkat keras atau melakukan operasi-operasi kritis secara langsung demi keamanan, mereka harus _meminta_ kernel untuk melakukannya melalui system call.

# Application Programming Interface
Sering kali, sistem mengeksekusi ribuan *system call*/detik. Kebanyakan pemrograman tidak melihat detail ini. Tetapi, pemrogram aplikasi mendesain program berdasarkan *application programming interface* (API). API menentukan serangkaian fungsi yang tersedia bagi pemrogram aplikasi, termasuk parameter yang dilewatkan ke setiap fungsi dan nilai kembalian (_return values_) yang diharapkan. Tiga API yang paling umum untuk pemrogrman aplikasi adalah Windows API, POSIX API (untuk sistem *POSIX-based*, seperti semua versi UNIX), dan Java API (untuk program yang beralan di **Java Virtual Machine**). Pengembang lebih memilih menggunakan API karena alasan portabilitas program (program dapat dikompilasi dan dijalankan di sistem mana pun yang mendukung API yang sama) dan karena _system calls_ yang sebenarnya seringkali lebih detail dan sulit digunakan dibandingkan API.

Dalam menangani *system call* salah satu hal yang penting adalah *run-time environment* (RTE). **RTE** adalah paket lengkap perangkat lunak (*full suite of software*) yang diperlukan untuk mengeksekusi aplikasi yang ditulis dalam bahasa pemrograman tertentu. RTE menyediakan *system-call interface* yang menyediakan tautan ke *system call* yang disediakan oleh OS. Antarmuka ini mencegat panggilan fungsi dalam API dan memanggil _system calls_ yang diperlukan di dalam OS. Biasanya, setiap _system call_ memiliki nomor yang terkait, dan antarmuka ini mengelola tabel yang diindeks berdasarkan nomor-nomor tersebut. Antarmuka kemudian memanggil _system call_ yang dimaksud di dalam _kernel_ OS dan mengembalikan status _system call_ tersebut. Pemanggil tidak perlu tahu bagaimana _system call_ diimplementasikan; ia hanya perlu mematuhi API dan memahami hasil dari eksekusi _system call_.

Ketika _system call_ dijalankan, ia biasanya diperlakukan oleh _hardware_ sebagai interupsi software (software interrupt*) yang disebut *trap*. Kontrol dialihkan melalui _interrupt vector_ ke rutin layanan (_service routine_) di OS, dan _mode bit_ diatur ke **mode** **kernel**. Rutin layanan _system call_ memeriksa instruksi yang menginterupsi untuk menentukan _system call_ apa yang terjadi dan layanan apa yang diminta. Tiga metode umum digunakan untuk melewatkan parameter ke OS:
1. **Melalui** **Register**: Metode paling sederhana, tetapi terbatas oleh jumlah _register_
2. **Melalui** **Blok/Tabel**: Parameter disimpan dalam blok atau tabel di memori, dan alamat blok tersebut dilewatkan dalam _register_
3. **Melalui** **Stack**: Parameter didorong (_pushed_) ke _stack_ oleh program dan ditarik (_popped_) dari _stack_ oleh OS. Metode ini tidak membatasi jumlah atau panjang parameter

Linux menggunakan kombinasi: lima parameter atau kurang dilewatkan melalui _register_; lebih dari lima parameter menggunakan metode blok.

> [!img-caption] ![[Pasted image 20251020014904.png]]

# Tipe-Tipe System Call
_System call_ dapat dikelompokkan berdasarkan fungsinya:
- **Kontrol Proses**: `create`, `terminate`, `load`, `execute`, `wait`.
- **Manajemen File**: `create`, `delete`, `open`, `close`, `read`, `write`.
- **Manajemen Perangkat**: `request device`, `release device`, `read`, `write`.    
- **Pemeliharaan Informasi**: `get_time`, `set_time`, `get_system_data`.
- **Komunikasi**: `create_connection`, `send_message`, `shm_create` (shared memory).
- **Proteksi**: `chmod`, `set_permissions`.

