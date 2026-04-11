Proses merupakan program yang sedang dieksekusi,. Status dari aktivitas proses ini direpresentasikan oleh nilai dari *program counter* dan konten dari *processor's registers*. Tata letak memori dari sebuah proses biasanya dibagi menjadi beberapa seksi, yaitu sebagai berikut:
1. *Text section*, kode yang dieksekusi
2. *Data section*, variabel global
3. *Heap section*, memori yang dialokasikan secara dinamis
4. *Stack section*, penyimpanan data sementara saat mengeksekusi fungsi

>[!img-caption] ![[Pasted image 20251020023207.png]]

# Process State
Saat proses dieksekusi, *state* dari proses tersebut berubah. Proses dapat memiliki *state* di antara berikut:
1. *New*, proses sedang dibuat
2. *Running*, instruksi sedang dieksekusi
3. *Waiting*, proses sedang menunggu sebuah *event* terjadi (I/O atau diterimanya sebuah sinyal)
4. *Ready*, proses sedang menunggu ditugaskan kepada sebuah *processor*.
5. *Terminated*, proses sudah selesai dieksekusi

>[!img-caption] ![[Pasted image 20251020024026.png]]

# Process Control Block
Setiap proses direpresentasikan pada OS dengan *process control block* (PCB) atau bisa juga disebut *task control block*. PCV mengandung informasi yang diasosiasikan dengan proses spesifik termasuk: 
1. *Process state*
2. *Program counter*. Alamat dari instruksi berikutnya yang akan dieksekusi oleh proses.
3. Register CPU. Nilai-nilai register (seperti akumulator, register indeks, _stack pointer_, dll.) yang harus disimpan ketika _interrupt_ terjadi agar proses dapat dilanjutkan kembali dengan benar.
4. Informasi *CPU-scheduling*. Prioritas proses, penunjuk (_pointer_) ke antrian penjadwalan, dan parameter penjadwalan lainnya.
5. Informasi *memory-management*. Informasi alokasi memori, seperti nilai _base_ dan _limit registers_, tabel halaman (_page tables_), atau tabel segmen.
6. Informasi *accounting*. Jumlah waktu CPU dan waktu riil yang telah digunakan, batas waktu, ID proses, dll.
7. Informasi I/O status. Daftar perangkat I/O yang dialokasikan ke proses dan daftar file yang sedang dibuka.
>[!img-caption] ![[Pasted image 20251020024203.png]]


