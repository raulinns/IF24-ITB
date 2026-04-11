## Thread Scheduling
- *Process-Contention Scope* (PCS): Kompetisi CPU terjadi di antara thread dalam proses yang sama untuk mendapatkan LWP (*Lightweight Process*) yang tersedia. Digunakan pada model *Many-to-One* dan *Many-to-Many*.
- *System-Contention Scope* (SCS): Kompetisi CPU terjadi di antara semua thread dalam sistem. Kernel yang memutuskan kernel thread mana yang akan dijadwalkan ke CPU fisik. Digunakan pada model *One-to-One* (seperti Windows dan Linux)

## Multiprocessing Scheduling
- *Symmetric Multiprocessing* (SMP): Setiap prosesor mengatur dirinya sendiri (self-scheduling).
- *Shared Ready Queue*: Semua thread berada dalam satu antrian umum (rawan race condition dan bottleneck).
- *Per-Processor Private Queue*: Setiap prosesor memiliki antrian pribadinya sendiri (lebih umum dan efisien karena memanfaatkan Processor Affinity)
- *Load Balancing*: Upaya untuk menjaga beban kerja terdistribusi secara merata di semua prosesor pada sistem SMP yang menggunakan antrian pribadi.
- *Push Migration*: Tugas spesifik memindahkan thread dari prosesor yang kelebihan beban ke processor yang idle.
- *Pull Migration*: Processor idle "menarik" tugas yang menunggu dari prosesor yang sibuk.
- *Processor Affinity:* Kecenderungan OS untuk menjaga thread berjalan pada prosesor yang sama untuk memanfaatkan Warm Cache (data yang diakses thread ada di cache prosesor).
- *Non-Uniform Memory Access* (NUMA): Arsitektur di mana CPU memiliki akses yang lebih cepat ke memori lokalnya daripada memori yang jauh (memori CPU lain). Penjadwalan harus NUMA-aware untuk meminimalkan penalti latency memori, tetapi ini sering bertentangan dengan load balancing.
- *Heterogeneous Multiprocessing* (HMP): Sistem menggunakan core yang menjalankan instruction set yang sama tetapi memiliki perbedaan dalam kecepatan dan manajemen daya (misalnya, arsitektur big.LITTLE). Tugas dialokasikan ke core berdasarkan tuntutan daya/kinerja tugas.

## Real-Time Scheduling
Penjadwalan di sistem real-time memiliki persyaratan waktu yang ketat.
- *Soft Real-Time Systems*: Memberikan preferensi pada proses real-time di atas proses non-kritis, tetapi tidak memberikan jaminan waktu. Membutuhkan penjadwalan *preemptive*, *priority-based*.
- *Hard Real-Time Systems*: Memiliki persyaratan yang lebih ketat, tugas harus diselesaikan sesuai tenggat waktu (deadline) yang ditentukan, atau dianggap gagal.

Proses juga mempunyai karakteristik baru: periodic $p$ (membutuhkan CPU dalam interval konstan, tiap periode disebut periodic process), processing time $t$, dan deadline $d$, dimana $0 \le t \le d \le p$, dengan rate periodiknya $\frac{1}{p}$.    

Tipe latency yang berpengaruh pada performa:
- Interrupt Latency: waktu dari tibanya interrupt pada PC hingga mulainya service routine sebagai handler dari interrupt.
- Dispatch Latency: waktu untuk dispatcher berpindah antara process

>[!img-caption] ![[Pasted image 20251020095104.png]]
>![[Pasted image 20251020095115.png]]

Algoritma umum untuk *Real-Time Scheduling*:
1. Rate Monotonic Scheduling (RMS)
	- Kebijakan prioritas statis berdasarkan inversi periode (period). Periode yang lebih pendek, prioritas lebih tinggi.
	- Optimal di antara algoritma prioritas statis, tetapi utilisasi CPU maksimum dibatasi (misalnya, 83% untuk dua proses)

2. Earliest-Deadline-First (EDF) Scheduling
	- Kebijakan prioritas dinamis berdasarkan deadline. Deadline yang lebih awal → prioritas lebih tinggi
	- Secara teoritis optimal, dapat menjadwalkan process agar memenuhi deadline selama utilisasi CPU total 100% atau kurang (meskipun dalam praktik tidak tercapai karena overhead)