## First-Come, First-Served (FCFS)
- Proses yang meminta CPU lebih dulu akan dilayani lebih dulu.
- FCFS menggunakan antrian FIFO (*First-In, First-Out*). 
- FCFS ini bersifat *non-preemptive*
	- Kelebihan: Sangat sederhana untuk diimplementasikan (menggunakan antrian FIFO).
- Kekurangan:
    - _Average waiting time_ (waktu tunggu rata-rata) bisa menjadi sangat tinggi.
    - Sangat buruk jika proses dengan _CPU burst_ panjang datang lebih dulu, karena semua proses pendek di belakangnya harus menunggu lama.

>[!img-caption] ![[Pasted image 20251020091204.png]]

Algoritma FCFS ini bersifat *nonpreemptive*, sehingga proses yang lain tidak boleh menyerobot proses yang sedang berjalan, mengakibatkan *convoy effect*. *Convoy effect* adalah fenomena dimana beberapa thread menunggu sebuah thread yang sangat lama dieksekusi (layaknya konvoi) hingga selesai. Hal ini mengakibatkan penggunaan CPU dan device yang tidak maksimal.

## Shortest-Job-First Scheduling (SJF)
- **Cara Kerja**: CPU dialokasikan ke proses yang memiliki durasi _CPU burst_ berikutnya yang paling pendek.
- **Optimalitas**: Terbukti optimal dalam memberikan _average waiting time_ minimum.
- **Variasi**:
    1. **Non-Preemptive SJF**: Jika sebuah proses mulai berjalan, ia akan berjalan sampai _CPU burst_-nya selesai.
    2. **Preemptive SJF (Shortest-Remaining-Time-First, SRTF)**: Jika proses baru datang dengan _burst_ yang lebih pendek dari sisa waktu proses yang sedang berjalan, OS akan melakukan _preempt_ dan menjalankan proses baru tersebut.

- **Kelemahan Utama**: Tidak mungkin mengetahui panjang _CPU burst_ berikutnya secara pasti. Solusinya adalah dengan **memprediksi** berdasarkan histori _burst_ sebelumnya menggunakan _exponential averaging_.
$$
\tau_{n+1} = \alpha t_{n} + (1 - \alpha) \tau_{n}
$$

$\tau_{n+1}$ adalah prediksi *CPU burst* selanjutnya, $t_n$ adalah panjang *CPU burst* yang baru saja diukur, $\tau_n$ adalah nilai prediksi sebelumnya (riwayat masa lalu), dan $\alpha$ adalah parameter pemberi bobot.
 
>[!img-caption] ![[Pasted image 20251020091915.png]]

## Round-Robin Scheduling
Round-robin (RR) mirip dengan algoritma FCFS, tetapi *preemption* ditambahkan untuk membuat sistem berpindah antar proses. Di sini didefinisikan *time quantum* atau *time slice*, biasanya berukuran 10-100 ms. 

- Kinerja sangat bergantung pada ukuran _time quantum_ (q).
	- Jika q terlalu besar, RR menjadi FCFS.
	- Jika q terlalu kecil, _context switch overhead_ meningkat (menjadi tidak efisien)

• **Keuntungan:** Memberikan _response time_ yang baik, menjamin setiap proses mendapatkan jatah waktu CPU secara berkala.

>[!img-caption] ![[Pasted image 20251020093418.png]]

## Priority Scheduling
- Setiap proses diberi prioritas; CPU dialokasikan ke proses dengan **prioritas tertinggi** (misalnya, angka yang lebih rendah). Proses dengan prioritas yang sama biasanya dijadwalkan FCFS.
- SJF adalah kasus khusus dari penjadwalan prioritas, di mana prioritas adalah kebalikan dari _CPU burst_ yang diprediksi
- Dapat didefinisikan secara _internal_ (berdasarkan kuantitas yang terukur seperti batas waktu atau rasio I/O ke CPU) atau _eksternal_ (berdasarkan kriteria di luar OS, seperti kepentingan pekerjaan).
-  Kelemahan: dapat terjadi *Starvation* (_indefinite blocking_), di mana proses berprioritas rendah mungkin tidak pernah dieksekusi.
- Solusinya yaitu **aging**, yang secara bertahap meningkatkan prioritas proses yang menunggu terlalu lama.

## Multilevel Queue Scheduling
-  _Ready queue_ dibagi menjadi **beberapa antrian terpisah** (misalnya, proses _real-time_, _sistem_, _interaktif_, _batch_).
- Setiap _queue_ dapat memiliki algoritma penjadwalan sendiri (misalnya, RR untuk _foreground/interaktif_, FCFS untuk _background/batch_).
-  Menggunakan penjadwalan _fixed-priority preemptive_ (prioritas absolut) atau _time-slice_ antar _queue_

>[!img-caption] ![[Pasted image 20251020093839.png]]
>![[Pasted image 20251020093853.png]]

## Multilevel Feedback Queue Scheduling
-  Memungkinkan proses **berpindah** antar _queue_ (tidak terikat permanen pada satu _queue_).
- Mengelompokkan proses berdasarkan karakteristik _CPU burst_ (proses yang menggunakan CPU terlalu banyak didemostrasikan ke _queue_ prioritas lebih rendah; _aging_ mempromosikan proses yang menunggu terlalu lama)
- Algoritma paling umum dan fleksibel, tetapi juga paling kompleks untuk dikonfigurasi karena banyaknya parameter yang harus diatur.

>[!img-caption] ![[Pasted image 20251020094043.png]]