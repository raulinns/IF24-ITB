Penjadwalan CPU adalah proses memilih sebuah proses (_thread_ pada sistem modern) dari _ready queue_ untuk dialokasikan ke _core_ CPU. Eksekusi proses terdiri dari siklus eksekusi CPU (_CPU burst_) dan menunggu I/O (_I/O wait_ atau _I/O burst_) yang saling bergantian, seperti yang dituliskan pada [[Process Scheduling]].Eksekusi sebuah proses adalah siklus yang bergantian antara:
1. **CPU Burst**: Periode di mana proses melakukan komputasi di CPU.
2. **I/O Burst**: Periode di mana proses menunggu operasi I/O (misalnya membaca dari disk, menunggu input keyboard) selesai.

Penjadwalan CPU fokus pada pengelolaan alokasi CPU selama periode _CPU Burst_. Distribusi durasi _CPU Burst_ umumnya menunjukkan banyak _burst_ singkat dan sedikit _burst_ yang sangat panjang. Salah satu alternatif sebuah proses di antara kedua siklus ini ialah sebagai berikut:

>[!img-caption]  ![[Pasted image 20251020084245.png]]

*CPU Scheduler* (*Short-Term Scheduler*): Bertugas memilih proses dari _ready queue_. Penjadwal ini harus dijalankan sesering mungkin. Keputusan penjadwalan terjadi ketika sebuah proses:
1. Beralih dari _Running_ ke _Waiting_ (misalnya, meminta I/O).
2. Beralih dari _Running_ ke _Ready_ (misalnya, karena interupsi timer).
3. Beralih dari _Waiting_ ke _Ready_ (misalnya, I/O selesai).
4. Berhenti (_Terminates_).

Untuk kasus 1 dan 4, tidak ada pilihan untuk mengambil keputusan penjadwalan. Sebuah proses baru (jika tersedia) harus dipilih untuk eksekusi. Kejadian ini dinamakan *nonpreemptive*. Dalam *nonpreemptive*, setelah CPU dialokasikan ke dalam proses, CPU mempertahankan proses hingga ia berhenti secara suka rela karena *terminating* atau berpindah status menjadi *waiting*. Sedangkan sebaliknya, untuk kasus 1 dan 3, *preemptive* adalah berarti CPU dapat diambil paksa dari proses yang sedang berjalan (misalnya karena interrupt atau waktu kuantum habis). Hampir semua sistem operasi modern menggunakan penjadwalan preemptive.

*Dispatcher* merupakan modul yang memberikan kontrol _core_ CPU kepada proses yang dipilih oleh _scheduler_. *Dispatcher* ini termasuk:
1. Berpindah *context* dari satu proses ke proses lain
2. Berpindah ke *user mode*
3. Pergi ke lokasi yang tepat di *user program* untuk melanjutkan program

*Dispatch Latency* adalah waktu yang dibutuhkan _dispatcher_ untuk menghentikan satu proses dan memulai proses lain, merupakan _overhead_ murni yang harus diminimalkan

# Scheduling Criteria
Tiap algoritma *CPU-scheduling* memiliki properti yang berbeda untuk memberikan perbandingan antar algoritma. Kriteria yang digunakan adalah sebagai berikut:
1. [MAX] CPU Utilization, menjaga CPU sesibuk mungkin (konseptual antara 0%–100%).
2. [MAX] Throughput, karena CPU sibuk, maka jumlah proses yang selesai per satuan waktu juga besar.
3. [MIN] Turnaround Time, meminimmalkan total waktu dari proses diserahkan hingga selesai (termasuk menunggu, eksekusi CPU, dan I/O).
4. [MIN] Waiting Time, meminimalkan total waktu yang dihabiskan proses menunggu di ready queue.
5. [MIN] Response Time, meminimalkan waktu dari permintaan diserahkan hingga respons pertama dihasilkan (penting untuk sistem interaktif).