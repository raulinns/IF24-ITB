Sebagian besar kode dari OS didedikasikan untuk mengelola *input/output* (I/O). Hal ini dikarenakan I/O penting untuk keandalan dan kinerja sistem; dan sifat perangkat I/O yang beragam. Dari [[Interrupt]] kita tahu bahwa memindahkan data dapat dilakukan menggunakan mekanisme *interrupt*, tetapi metode ini hanya dapat dilakukan untuk memindahkan data dalam jumlah kecil. Memindahkan data yang besar dapat mengakibatkan masalah *overhead* (biaya atau waktu tambahan). Untuk menyelesaikan masalah ini. kita dapat menggunakan *direct memory access* (DMA). 

Cara kerja DMA adalah sebagai berikut:
1.  Menyiapkan _buffer_, _pointer_, dan _counter_ untuk perangkat I/O,
2. _Device controller_ mentransfer **seluruh blok data** secara langsung ke atau dari perangkat dan memori utama (_main memory_). Proses ini terjadi **tanpa campur tangan CPU**
3. Hanya **satu** **interrupt** **yang dihasilkan per blok** untuk memberi tahu _device driver_ bahwa operasi telah selesai. Hal ini berbeda dari I/O perangkat berkecepatan rendah yang menghasilkan satu _interrupt_ per _byte_
4. Saat _device controller_ melakukan operasi DMA ini, **CPU tetap tersedia** untuk menyelesaikan pekerjaan lain

Dalam sistem komputer terkini (*high-end*), sistem menggunakan arsitektur *switch* dibanding arsitektur bus. Dalam sistem ini, berbagai komponen dapat berinteraksi satu sama lain secara konkuren, dibandingkan berkompetisi untuk siklus pada *shared bus*. Dalam kasus ini. penggunaan DMA lebih efektif lagi.

>[!notes] Perbedaan Bus dan Switch
>Arsitektur **bus** (arsitektur klasik) menggunakan satu **jalur komunikasi bersama**untuk semua komponen seperti CPU, memori, dan I/O, yang menciptakan _bottleneck_ karena semua perangkat harus bergantian menggunakannya. Sebaliknya, arsitektur **switch** (arsitektur modern) menggunakan **koneksi langsung _point-to-point_** , yang memungkinkan banyak transfer data terjadi secara paralel dan simultan, sehingga menghilangkan _bottleneck_ dan memberikan kinerja yang jauh lebih tinggi.