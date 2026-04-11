*Interrupt* adalah kunci dari interaksi antara OS dengan *hardware*. Perangkat keras mungkin dapat melakukan *interrupt* pada tiap waktu dengan mengirimkan sinyal kepada CPU, biasanya melalui *system bus*. *Interrupt* adalah mekanisme  yang digunakan _hardware_ untuk memberi sinyal kepada CPU tentang peristiwa yang memerlukan perhatian. 

Saat *interrupt* dilakukan, CPU  berhenti melakukan pekerjaan yang sedang dilakukan dan mentransfer eksekusi ke lokasi yang sudah ditentukan. Lokasi ini biasanya mengandung *starting address* di mana *service routine* untuk *interrupt* akan dilakukan. Setelah itu, CPU mengeksekusi fungsi *interupt handler* sesuai dengan *service routine* (ISR) dan kode *interrupt* yang diterima. Setelah itu selesai, CPU kembali melanjutkan pekerjaannya.

>[!img-caption] ![[Pasted image 20251019152246.png]]

Setiap desain komputer memiliki mekanisme *interrupt*-nya sendiri, tetapi beberapa fungsi memiliki kesamaan. *Interrupt* harus mentransfer kontrol ke *interrupt service routine* (ISR) yang tepat.  

Singkatnya, cara "cepat" dalam mengelola transfer ini adalah dengan memanggil *interrupt-spesific handler* secara bergantian. *Interrupt* harus ditangani secara cepat, karena *interrupt* terjadi sangat sering. Untuk memungkinkan transfer kontrol yang cepat ke _handler_ yang tepat, digunakan tabel alamat yang disebut **interrupt vector**. Vektor ini biasanya disimpan di memori rendah (sekitar seratus lokasi pertama) dan diindeks oleh nomor unik yang diberikan bersama permintaan _interrupt_ untuk menyediakan alamat _interrupt service routine_ untuk perangkat yang menginterupsi. Sistem operasi yang berbeda, seperti Windows dan UNIX, mengirimkan _interrupt_ dengan cara ini.

>[!notes] Cara Kerja Interrupt
>Dasarnya, mekanisme *interrupt* dasar bekerja sebagai berikut:  
>1. CPU merasakan sinyal *interrupt* melalui sebuah saluran bernama *interrupt-request line*. 
>2. CPU menghentikan apa yang sedang dilakukan dan membaca *interrupt number* dan masuk ke dalam *interrupt-handler routine* dengan menggunakan *interrupt number* sebagai indeks pada *interrupt vector*
>3. ISR akan dieksekusi berdasarkan *address* yang diasosiasikan dengan indeks tersebut
>4. *Interrupt handler* menyimpan *state* yang berubah dari operasi tersebut, menentukan sebab dari *interrupt*, melakukan pemrosesan yang diperlukan, dan membersihkan interrupt dengan melayani perangkat.
>5. Setelah selesai, CPU memulihkan _state_ yang disimpan (_state restore_) dan mengeksekusi instruksi kembali dari _interrupt_. Komputasi yang terinterupsi dilanjutkan seolah-olah _interrupt_ tidak pernah terjadi

## Modern Interrupt Handling
Menaisme *interrupt* dasar memungkinkan CPU untuk merespon kepada *asynchronous event*, sebagai mana ketika *device controller* siap untuk pekerjaan. Dalam OS modern, kita butuh fitur *interrupt handling* yang lebih canggih:
1. Kemampuan untuk menunda penanganan interrupt selama pemrosesan kritis
2. Cara yang efisien untuk mengirimkan interrupt ke handler yang tepat untuk suatu perangkat
3. Prioritas interrupt multilevel (_multilevel interrupts_), memungkinkan sistem operasi membedakan antara _interrupt_ prioritas tinggi dan rendah dan merespons dengan urgensi yang sesuai

Dalam *hardware* komputer yang modern, tiga fitur ini disediakan oleh CPU dan *interrupt-controller hardware*.

>[!img-caption] ![[Pasted image 20251019155730.png]]

Mayoritas CPU memiliki dua *interrupt-request line*, yaitu:
1. *nonmaskable interrupt* (NMI), yang dicadangkan untuk peristiwa, seperti error memori yang tidak dapat dikembalikan atau kegagalan yang harus segera ditangani. Dalam hal ini, NMI harus langsung menanganinya
2. *maskable interrupt*, yang dapat dimatikan oleh CPU sebelum eksekusi yang kritikal yang tidak boleh diinterupsi. *Maskable interrupt* digunakan oleh _device controller_ untuk meminta layanan. CPU dapat mematikan _interrupt_ ini sebelum mengeksekusi urutan instruksi kritis yang tidak boleh diinterupsi.

## Interrupt Vector
*Interrupt vector* merupakan sebuah tabel *pointer* yang bertujuan untuk mengurangi kemungkinan *interrupt handler* mencari mana yang dibutuhkan untuk sebuah *interrupt*. Dalam praktiknya, sebuah komputer memiliki lebih banyak *devices* dan *interrupt handler* dibanding mereka mmiliki elemen *address* dalam *interrupt vector*. Untuk menyelesaikan masalah ini, kita menggunakan *interrupt chaining*. Di mana tiap elemen pada *interrupt vector*, mengarah ke sebuah *list of interrupt handler*. 

Ilustrasi dari *interrupt vector* pada prosesor Intel dapat dilihat pada gambar berikut. Untuk *vector number* 0-31 merupakan *vector number* untuk *nonmaskable* dan digunakan secara spesfiik untuk kondisi error. Sedangkan, dari nomor 32-255 merupakan *vector number* untuk *maskable* dan digunakan secara umum untuk interupsi yang dibuat oleh perangkat keras lain. Mekanisme ini juga menggunakan sistem *priority level* untuk menangani peristiwa-peristiwa mendesak dengan tingkat urgensi yang sesuai. 

>[!img-caption] ![[Pasted image 20251019162517.png]]