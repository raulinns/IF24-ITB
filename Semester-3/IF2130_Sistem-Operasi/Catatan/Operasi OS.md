Untuk sebuah komputer dapat berjalan, ia memerlukan program awal untuk dijalankan. Program awal ini, yang disebut *program bootstrap* atau *boot loader*, cenderung sederhana dan biasanya disimpan dalam _firmware_ perangkat keras komputer. Tugas _bootstrap_ adalah menginisialisasi semua aspek sistem (mulai dari register CPU hingga pengontrol perangkat dan konten memori). *Bootstrap* harus tahu bagaimana cara memuat OS dan mulai mengeksekusi sistem. Untuk itu, *bootstrap* harus mengetahui lokasi kernel OS dan memuatnya ke memori. 

Setelah _kernel_ dimuat dan berjalan, ia mulai menyediakan layanan. Beberapa layanan disediakan di luar kernel oleh *system programs* dan mengunggahnya ke memori saat waktu *boot* untuk menjadi *system daemons* yang berjalan sepanjang waktu selama kernel dijalankan. Setelah fase ini selesai, sistem dianggap telah sepenuhnya _booting_ dan akan **menunggu terjadinya suatu peristiwa** (*event*). 

# Multiprogramming dan Multitasking
Salah satu aspek penting dari OS adalah harus dapat menjalankan berbagai program sekaligus untuk meningkatkan utilisasi CPU. Dalam sistem *multiprogram*, sebuah program yang dalam proses eksekusi dinamakan sebagai proses. 

Sistem operasi dapat menjaga beberapa proses dalam memori secara bersamaan. OS dapat memilih dan mulai mengeksekusi proses satu per satu. Akhirnya, proses mungkin harus menunggu suatu tugas untuk selesai (misalnya operasi I/O).  Dalam sebuah lingkungan *non-multiprogram*, dalam kasus ini CPU akan menunggu (*idle*). Sedangkan, pada lingkungan *multiprogram*, OS dapat berpindah dan mengeksekusi proses lain, dan seterusnya. Pada akhirnya, proses pertama tadi sudah selesai menunggu dan dapat menggunakan CPU kembali. Selama terdapat setidaknya satu proses untuk dieksekusi, CPU tidak akan pernah *idle*. 

>[!img-caption] ![[Pasted image 20251019221823.png]]

*Multitasking* adalah perpanjangan logis dari *multiprogramming*. _Multitasking_ memungkinkan CPU mengeksekusi banyak proses dengan beralih di antara mereka dengan frekuensi tinggi (sering). Peralihan yang cepat ini memberikan ilusi kepada pengguna bahwa setiap program berjalan secara bersamaan (_concurrently_), sehingga memberikan _response time_ yang cepat.Peralihan antar proses ini dinamakan *context switching*. Waktu yang dibutuhkan untuk _context switching_ ini dianggap sebagai _overhead_ murni karena selama waktu tersebut, sistem tidak melakukan pekerjaan yang bermanfaat bagi pengguna. Multitasking sangat penting untuk I/O interaktif (misalnya, input dari _keyboard_), karena I/O ini berjalan pada "kecepatan manusia" (_people speeds_) yang sangat lambat bagi CPU. Daripada membiarkan CPU diam menunggu input yang lambat, sistem akan dengan cepat mengalihkan CPU ke proses lain.

Sistem _multitasking_ sering menggunakan **memori virtual** untuk memungkinkan eksekusi proses yang tidak sepenuhnya berada di memori utama, yang memungkinkan pengguna menjalankan program yang lebih besar daripada memori fisik yang tersedia.

# Dual-Mode dan Multimode
_Dual-mode_ (mode ganda) dan _multimode_ adalah mekanisme perlindungan mendasar yang didukung oleh _hardware_ komputer dan diatur oleh sistem operasi (OS) untuk memastikan integritas dan keamanan sistem. Tujuan utama adanya mode operasi adalah untuk **membedakan antara eksekusi kode sistem operasi dan kode yang ditentukan pengguna**, sehingga memberikan perlindungan dasar

ada dasarnya, setiap sistem operasi membutuhkan setidaknya dua mode operasi yang terpisah: _user mode_ dan _kernel mode_ (juga disebut _supervisor mode_, _system mode_, atau _privileged mode_). Perbedaan mode ini ditunjukkan oleh **mode bit**, sebuah _bit_ yang ditambahkan ke _hardware_ komputer.    
- Kernel Mode (atau supervisor mode/privileged mode): Mode di mana OS mengeksekusi instruksi. Jika terjadi trap atau interrupt, hardware beralih ke kernel mode.
- User Mode: Mode di mana sistem mengeksekusi atas nama aplikasi pengguna. Sistem beralih ke user mode sebelum menyerahkan kontrol ke program pengguna. Dalam x86, mode disimpan di EFLAGS, sedangkan MIPS di status register

>[!img-caption] ![[Pasted image 20251019232928.png]]

Instruksi-instruksi yang dapat menyebabkan kerusakan (seperti kontrol I/O, manajemen _timer_, atau peralihan ke _kernel mode_) ditetapkan sebagai _privileged instructions_ dan **hanya boleh dieksekusi di** **kernel mode**. Jika program mencoba mengeksekusi instruksi istimewa di _user mode_, _hardware_ akan memicu _trap_ ke sistem operasi. 

Ketika sebuah aplikasi pengguna meminta layanan dari sistem operasi (melalui _system call_), sistem harus melakukan **transisi dari** **user mode** **ke** **kernel mode** untuk memenuhi permintaan tersebut.

Ketika sistem dinyalakan (_boot time_), _hardware_ dimulai di _kernel mode_. OS kemudian dimuat dan mulai menjalankan aplikasi pengguna di _user mode_. Kapan pun terjadi _trap_ atau _interrupt_, _hardware_ secara otomatis beralih dari _user mode_ ke _kernel mode_ (mengubah _mode bit_ menjadi 0). Sistem selalu beralih kembali ke _user mode_ (mengatur _mode bit_ menjadi 1) sebelum mengembalikan kontrol ke program pengguna.

# Timer
Timer merupakan mekanisme penting dalam operasi sistem operasi, terutama untuk **memastikan sistem operasi mempertahankan kontrol penuh atas CPU**. Fungsi utama _timer_ adalah untuk mencegah program pengguna agar tidak terjebak dalam _loop_ tak terbatas (_infinite loop_) atau gagal mengembalikan kontrol ke sistem operasi. 

Timer dapat diatur untuk menginterupsi komputer setelah periode waktu tertentu. Timer dapat bersifat tetap atau variabel. Timer Tetap, misalnya, dapat diatur untuk menginterupsi setiap 1/60 detik. Timer variabel  Biasanya diimplementasikan dengan menggunakan jam (_fixed-rate clock_) dan penghitung (_counter_). OS mengatur nilai awal *counter*, lalu setiap kali jam berdetak, *counter* akan berkurang nilainya. Ketika *counter* mencapai 0, *interrupt* terjadi. 

Sebelum menyerahkan kontrol kepada program pengguna, **sistem operasi harus memastikan** **timer** **diatur untuk menghasilkan** **interrupt**. Jika _timer_ memicu _interrupt_, **kontrol secara otomatis berpindah ke sistem operasi**. Sistem operasi kemudian dapat memutuskan apakah akan menganggap _interrupt_ tersebut sebagai **kesalahan fatal** atau memberikan **waktu tambahan** kepada program untuk dieksekusi.