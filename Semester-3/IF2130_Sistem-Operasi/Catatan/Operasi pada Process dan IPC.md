Proses pada kebanyakan sistem dapat tereksekusi secara konkuren dan dapat dibuat/dihapus secara dinamis.
# Penciptaan Proses
Selama proses eksekusi, sebuah *process* dapat membuat beberapa *process* baru. Proses yang menciptakan disebut proses induk (*parent process*), dan proses baru disebut proses anak (*child processes*). Penciptaan proses ini membentuk *tree of processes*.  

Setiap proses diidentifikasi oleh pengenal proses unik (PID), yang biasanya berupa bilangan bulat. PID ini digunakan sebagai indeks untuk mengakses berbagai atribut proses di dalam _kernel_. Pada sistem Linux, proses `systemd` (yang selalu memiliki PID 1) berfungsi sebagai akar (_root parent process_) untuk semua proses pengguna dan merupakan proses pengguna pertama yang dibuat saat sistem melakukan _boot_.

>[!img-caption] ![[Pasted image 20251020051248.png]]

Secara umum, ketika sebuah proses menciptakan *child process*, proses itu akan mendapatkan beberapa sumber daya tertentu (CPU *time*, memori, *file*, perangkat I/O) untuk menyelesaikan tugasnya. Proses anak dapat memperoleh sumber daya langsung dari sistem operasi atau dibatasi pada subset sumber daya dari proses induknya. Membatasi proses anak pada subset sumber daya induk dapat mencegah proses membebani sistem dengan menciptakan terlalu banyak proses anak. Data inisialisasi (_input_) juga dapat diteruskan dari proses induk ke proses anak. 

Saat proses menciptakan proses baru, ada dua kemungkinan untuk eksekusinya, yaitu:
1. *Parent process* melanjutkan eksekusinya bersamaan dengan *child process*-nya.
2. *Parent process* menunggu hingga sebagian atau seluruh *child process*-nya diterminasi (*terminated*).

Di sistem UNIX/Linux, penciptaan proses, seperti di atas menggunakan dua _system call_ utama:
1. `fork()`: Membuat proses anak baru yang merupakan duplikat identik dari proses induk. Proses anak ini memiliki ruang alamat yang sama, tetapi PID yang berbeda. Setelah `fork()`, ada dua proses yang menjalankan kode yang sama dari titik di mana `fork()` dipanggil.
2. `exec()`: Digunakan setelah `fork()` oleh proses anak untuk mengganti seluruh ruang memorinya dengan program baru. `exec()` memuat program baru dan mulai menjalankannya dari awal.

Selain itu, terdapat dua kemungkinan *address-space* untuk proses baru:
1. *Child process* adalah duplikat dari *parent process* dan memiliki program dan data yang sama dengan *parent*-nya.
2. *Child process* memiliki program baru yang dimuatnya.

Pada Windows, pembuatan child process dilakukan menggunakan fungsi CreateProcess() dalam API Windows, yang membutuhkan parameter lebih banyak dan biasanya memuat program yang ditentukan ke address space proses anak saat pembuatan.

# Terminasi Proses
Proses berakhir ketika ia menyelesaikan eksekusi pernyataan terakhirnya dan meminta sistem operasi untuk menghapusnya menggunakan panggilan sistem  `exit()`. Proses dapat mengembalikan nilai status (biasanya bilangan bulat) kepada proses induk yang menunggunya (melalui panggilan `wait()`). Semua sumber daya proses—termasuk memori fisik dan virtual, _file_ terbuka, dan _buffer_ I/O—didealokasikan dan diklaim kembali oleh sistem operasi.

*Parent process* dapat menterminasi  (*terminate* ) eksekusi dari *child process*-nya dengan alasan berikut:
1. *Child process* menggunakan *resource* yang berlebihan dari yang sudah dialokasikan.
2. Tugas yang ditujukan kepada *child* sudah tidak dibutuhkan.
3. *Parent process* sedang diterminasi dan OS tidak mengizinkan *child process*-nya melanjutkan jika *parent process*-nya diterminasi.

>[!info] Cascading Termination
> *Cascading termination* adalah keadaan di mana sebuah proses induk berhenti, beberapa sistem operasi akan secara otomatis menghentikan semua proses anaknya.

Proses yang telah berakhir tetapi proses induknya belum memanggil **wait()****, dikenal sebagai *zombie process*. Setelah induk memanggil `wait()`, pengenal proses (_PID_) dari proses _zombie_ dan entri prosesnya di tabel proses dirilis. Pelepasan entri ini sangat penting agar sumber daya kernel (ruang dalam tabel proses) dapat digunakan kembali.

Jika proses induk tidak memanggil `wait()` dan malah berakhir (_terminate_), maka proses anak yang ditinggalkan (_abandoned_) disebut *orphan process*.

# Interprocess Communication
Proses yang berjalan secara konkuren dalam OS, dapat bersifat sebagai berikut:
1. *Independent Process*: Tidak dapat memengaruhi atau dipengaruhi oleh proses lain.
2. *Cooperating Process*: Dapat memengaruhi atau dipengaruhi oleh proses lain. Keuntungannya: berbagi informasi, mempercepat komputasi, modularitas.

*Cooperating process* membutuhkan mekanisme *interprocess communication* (IPC) yang memungkinkan mereka untuk bertukar data (mengirim atau menerima data dari satu sama lain). Terdapat dua model fundamental dari sebuah IPC, yaitu:
1. *Shared Memory*, Dalam model ini, suatu wilayah memori (_region of memory_) ditetapkan dan dibagi oleh proses-proses yang ingin berkomunikasi. Proses dapat bertukar informasi dengan membaca dan menulis data ke wilayah bersama ini. _System call_ hanya diperlukan untuk membangun (menetapkan) wilayah memori bersama tersebut. Setelah memori bersama ditetapkan, akses selanjutnya (membaca dan menulis data) diperlakukan sebagai akses memori rutin dan tidak memerlukan bantuan *kernel*
	- Keuntungan: Sangat cepat (tidak ada overhead kernel setelah setup).
	- Kelemahan: Programmer bertanggung jawab penuh untuk memastikan sinkronisasi agar tidak terjadi _race condition_ (menulis secara bersamaan pada *shared memory*).

2. *Message Passing*. Dalam model ini, komunikasi dilakukan melalui pesan yang dipertukarkan antara proses-proses yang bekerja sama. Fasilitas _message passing_ menyediakan setidaknya dua operasi: `send(message)` dan `receive(message)`. Model ini biasanya diimplementasikan dengan menggunakan _system call_, sehingga **memerlukan intervensi** **kernel** untuk setiap operasi pengiriman dan penerimaan.
	- Keuntungan:  Lebih mudah diimplementasikan dalam sistem terdistribusi di mana proses mungkin berada di komputer yang berbeda.

>[!img-caption] ![[Pasted image 20251020055716.png]]

Untuk mengimplementasikan `send()` atau  `receive()` secara logis dapat dilakukan dengan memerhatikan beberapa isu, seperti berikut:
### Naming
Proses yang ingin berkomunikasi harus memiliki cara untuk mengacu pada satu sama lain. Dalam *direct communication*, tiap proses harus menyebutkan secara eksplisit nama dari penerima atau pengirim dari komunikasi tersebut. `send(P, message)` untuk mengirim pesan ke proses $P$ atau `receive(Q, message)` untuk menerima pesan dari proses $Q$.

Untuk *indirect communication*, pesan dikirim dan diterima melalui *port*. Pesan dikirim dan diterima melalui kotak surat (*mailbox*) atau *port* yang memiliki identifikasi unik (misalnya, `send(A, message)`). Komunikasi terjadi jika proses berbagi _mailbox_ yang sama. OS harus menyediakan mekanisme yang memungkinkan proses untuk membuat *mailbox*, menerima dan mengirim pesan melalui *mailbox*, lalu menghapus *mailbox*).	
	
### Synchronization
Dalam konteks ini, *message passing* dapat berupa *blocking* atau *nonblocking*; dapat dikatakan sebagai *synchronous* dan *asynchronous*.  Operasi *send* dan *receive* dibagi menjadi *blocking* (sender di-*block* oleh *receiver* hingga *message* diterima) atau *nonblocking* (*sender* mengirimkan *message* dan melanjutkan operasinya, dengan *receiver* dapat menerima message yang *valid* atau *null*). Berbagai kombinasi dari `send()` dan `receive()` memungkinkan. Ketika dua-duanya *blocking*, maka disebut *rendezvous* antara *sender* dan *receiver*. 


### Buffer
Pesan berada dalam antrian sementara (_temporary queue_) yang dapat diimplementasikan dalam tiga cara:
- Kapasitas Nol (*Zero capacity*): Panjang antrian nol. Pengirim harus memblokir (_blocking_) sampai penerima menerima pesan.
- Kapasitas Terbatas (*Bounded capacity*): Antrian memiliki panjang tetap (_n_). Jika antrian penuh, pengirim harus memblokir.
- Kapasitas Tidak Terbatas (*Unbounded capacity*): Panjang antrian berpotensi tidak terbatas. Pengirim tidak pernah memblokir.

## Mekanisme Komunikasi Lainnya
- **Pipes**: Saluran komunikasi searah (_unidirectional_) antara proses-proses yang memiliki hubungan (misalnya, parent-child).
- **Sockets**: Titik akhir (_endpoint_) untuk komunikasi jaringan. Sebuah soket diidentifikasi oleh alamat IP dan nomor port. Memungkinkan komunikasi antar proses di mesin yang berbeda.
- **Remote Procedure Calls (RPC)**: Mekanisme tingkat tinggi yang menyembunyikan detail komunikasi jaringan. Sebuah proses dapat memanggil fungsi/prosedur yang sebenarnya dieksekusi di mesin lain seolah-olah itu adalah pemanggilan fungsi lokal.