Tujuan dari *multiprogramming* adalah untuk memiliki sejumlah proses yang berjalan di tiap waktu untuk memaksimalkan *CPU utilization*. Tujuan dari *timesharing* adalah untuk mengalihkan *CPU core* di antara proses-proses dengan frekuensi tinggi sehingga pengguna dapat **berinteraksi dengan setiap program** saat program itu berjalan. 

Untuk memenuhi kedua tujuan ini, *process scheduler* memilih dari proses yang tersedia untuk dieksekusi dalam sebuah *core*. Tiap *CPU core* dapat mengerjakan satu proses dalam satu waktu. Jika jumlah proses melebihi jumlah _core_ yang tersedia, proses yang berlebihan harus menunggu hingga _core_ CPU bebas dan dapat dijadwalkan kembali. Jumlah proses yang sekarang berada pada memori disebut *degree of multiprogramming*. 

Secara umum. sebuah proses dapat dideskripsikan antara *I/O bound* atau *CPU bound*. *I/O bound* adalah sebuah proses yang mengambil waktu lebih lama melakukan I/O dibanding komputasi. Sedangkan, *CPU-bound* adalah proses yang lebih banyak menghabiskan waktu melakukan komputasi. 

# Scheduling Queue
Antrian Penjadwalan (_Scheduling Queues_) berfungsi sebagai daftar terorganisir yang menampung _Process Control Block_ (PCB) dari berbagai proses yang berada dalam status tertentu. Dalam implementasi, antrian ini biasanya diwujudkan sebagai daftar berantai (_linked list_). Ketika proses memasuki sistem dan saat mereka berpindah status selama eksekusi (_migrates_), mereka akan ditempatkan di antrian yang sesuai. 

Ada beberapa jenis antrian utama yang digunakan oleh sistem operasi untuk mengelola proses:
1. *Ready queue*.antrian tempat semua proses yang siap (_ready_) dan menunggu untuk dieksekusi oleh _core_ CPU ditempatkan. _Header_ dari _ready queue_ berisi _pointer_ ke PCB pertama, dan setiap PCB memiliki _pointer_ yang menunjuk ke PCB proses berikutnya dalam antrian
2. *Wait queue/Device queue*. Ketika sebuah proses harus menunggu suatu peristiwa tertentu terjadi—seperti penyelesaian operasi I/O atau penerimaan sinyal—proses tersebut dipindahkan dari CPU dan ditempatkan di antrian tunggu yang relevan. Setelah peristiwa yang ditunggu selesai, proses dipindahkan dari status _waiting_ kembali ke status _ready_ dan dikembalikan ke _ready queue_ untuk menunggu eksekusi CPU selanjutnya
	- Harus menunggu sinyal I/O,    
	- Menghasilkan sebuah child process, atau
	- Terjadi interrupt atau habisnya time slice yang mengeluarkan process dari wait queue dan dimasukkan kembali ke ready queue.

3. *Job queue*. Antrian ini secara historis atau umum dapat merujuk pada semua proses yang ada dalam sistem. Proses secara dinamis berpindah antar berbagai antrian sepanjang siklus hidupnya, yang dapat digambarkan dalam diagram antrian.

>[!img-caption] ![[Pasted image 20251020043635.png]]

>[!img-caption] ![[Pasted image 20251020043657.png]]

Penjadwalan CPU (_CPU scheduling_) adalah fungsi mendasar dari sistem operasi modern yang bertanggung jawab untuk memutuskan proses mana yang akan dialokasikan ke _core_ CPU. OS menggunakan beberapa jenis _scheduler_ untuk mengelola alur proses:
- Long-Term Scheduler (Job Scheduler): Memilih proses-proses dari _job pool_ di disk untuk dimuat ke dalam memori (_ready queue_). Scheduler ini mengontrol tingkat multiprogramming (jumlah proses di memori). Jarang dieksekusi.
- Short-Term Scheduler (CPU Scheduler): Memilih proses berikutnya yang akan dieksekusi dari _ready queue_ dan mengalokasikan CPU untuknya. Sangat sering dieksekusi (setiap beberapa milidetik).
- Medium-Term Scheduler (Swapper): Kadang-kadang digunakan untuk memindahkan proses dari memori ke disk (_swapping out_) untuk mengurangi tingkat multiprogramming dan membebaskan memori. Proses yang di-_swap out_ dapat dimasukkan kembali ke memori nanti.

# Context Switch
Ketika terjadi _interrupt_ atau _system call_ (seperti _page fault_ atau habisnya _time slice_), sistem harus **menghentikan eksekusi proses yang sedang berjalan** dan **menyimpan statusnya** sebelum menjalankan rutin kernel yang baru (atau proses/thread lain). Proses _context switch_ melibatkan dua langkah utama:
1. Penyimpanan Status (_State Save_): Kernel menyimpan _context_ proses lama yang sedang berjalan pada *CPU core* ke dalam _Process Control Block_ (PCB) milik proses tersebut.
2. Pemulihan Status (*State Restore*): Kernel memuat konteks yang tersimpan dari PCB proses baru yang dijadwalkan untuk berjalan ke *CPU core*.

>[!img-caption] ![[Pasted image 20251020045335.png]]