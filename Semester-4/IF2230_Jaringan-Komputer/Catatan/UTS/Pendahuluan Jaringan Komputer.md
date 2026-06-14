---
cssclasses:
  - callouts-outlined
---
Jaringan komputer dibangun dengan sebuah kumpulan dari *node* yang dihubungkan oleh *link*. *Node* (titik simpul) merupakan sebuah *end point* yang menerima jaringan. Sedangkan, *links* adalah tautan fisik, seperti kabel, serat optik, dan lain-lain yang menghubungkan antar *node*. 

>[!notes]
>Secara fundamental, jaringan komputer bukan sekadar kumpulan perangkat keras. Mengutip _Peterson & Davie_, kita mendefinisikan jaringan sebagai sebuah sistem komunikasi yang menghubungkan sistem otonom (komputer/host) untuk saling bertukar data. Definisi ini menekankan pada **Konektivitas**, di mana tujuannya adalah menciptakan ilusi bahwa setiap komputer terhubung langsung satu sama lain, meskipun secara fisik terpisah jauh.
>
>Konektivitas ini dilakukan secara **End-to-End**. Artinya, jaringan harus menyediakan saluran komunikasi dari aplikasi di satu ujung ke aplikasi di ujung lain tanpa peduli kerumitan perangkat. Abstraksi ini disebut **"The Cloud"** yang digunakan untuk menyembunyikan detail teknis infrastruktur dari pengguna.

## Pengelompokan Jaringan
Jaringan komputer umumnya dikelompokkan berdasarkan dua kriteria utama: teknologi transmisi dan skala jarak.

Berdasarkan **Teknologi Transmisi**, jaringan dibagi menjadi _Broadcast Links_ (satu saluran komunikasi dibagi oleh banyak mesin) dan _Point-to-Point Links_ (koneksi antar sepasang mesin individu).

Sedangkan, berdasarkan **Skala/Jarak**, kita mengenal hierarki sebagai berikut:
- **LAN (Local Area Network):** Mencakup area kecil seperti ruangan atau gedung (jarak ~10m - 1km). LAN biasanya memiliki _bandwidth_ tinggi dan _latency_ (keterlambatan) rendah.
- **MAN (Metropolitan Area Network):** Mencakup area kota (jarak ~10km), contohnya jaringan TV kabel kota.
- **WAN (Wide Area Network):** Mencakup negara atau benua (jarak >100km). WAN menghadapi tantangan fisik yang lebih besar, sehingga _latency_-nya lebih tinggi dan manajemen kesalahannya lebih kompleks.

Kumpulan dari jaringan-jaringan yang berbeda (LAN, WAN) yang saling terhubung disebut **Internetwork** atau Internet. Di sinilah tantangan **Skalabilitas** muncul: bagaimana merancang jaringan yang tetap efisien saat jumlah pengguna tumbuh dari sepuluh menjadi miliaran.

![[Pasted image 20260213095342.png]]

## Elemen Jaringan Komputer
Setiap jaringan memiliki 4 komponen dasar, yang terbagi dalam perangkat keras dan perangkat lunak:
1. Perangkat
2. *Medium*, adalah kanal tempat *message* berpindah, seperti kabel tembaga, serat optik, dan *wireless*. 
3. *Message*, merupakan istilah umum yang mencangkup *web page*, *email*, dan layanan internet lainnya.
4. *Rules*/*Agreement*, skema pemberian alamat (*addressing schemes*), protokol.

## Layer
Jaringan diorganisasikan ke dalam lapisan *layer*. Setiap *layer* memberikan layanan kepada *layer* di atasnya dan menggunakan layanan dari *layer* di bawahnya. Antar *layer* berkomunikasi dengan menggunakan aturan/protokol tertentu.  *Interface* (Antarmuka) merupakan mekanisme komunikasi antara lapisan yang _bersebelahan_ pada mesin yang sama (komunikasi vertikal).

*Layer* digunakan untuk menyembunyikan implementasi, sehingga *layer* dapat diubah tanpa mengganggu *layer* lain (Konsep Abstraksi).

![[Pasted image 20260213100120.png]]

Terdapat juga dua layanan utama yang disediakan oleh perangkat lunak, yaitu:
- **Connection-Oriented Service:** Seperti telepon, koneksi harus dibangun (_handshake_) sebelum data dikirim. Menjamin urutan dan keandalan data (contoh: TCP).
- **Connectionless Service:** Seperti sistem pos, data dikirim langsung tanpa permisi. Tidak ada jaminan urutan atau sampai tidaknya data, namun lebih cepat (contoh: UDP/IP)

## OSI Layer Model
OSI dikembangkan di tahun 1977 oleh International Organization for Standardization (ISO). Tujuan dari OSI adalah menciptakan standar internasional agar komputer dari berbagai merk bisa saling berkomunikasi. Arsitektur OSI memiliki dua komponen utama, yaitu:
- Jaringan model abstrak dengan fungsi spesifik antar *layer*.
- Protokol spesifik yang diasosiasikan dengan sebuah *layer*.

![[Pasted image 20260213101750.png]]

![[Pasted image 20260218153858.png]]

### Physical Layer (Layer 1)
Layer ini merupakan lapisan terbawah dan langsung berhubungan dengan perangkat keras. Layer 1 ini mengatur spesifikasi elektrikal, mekanikal, prosedural, dan fungsional. Pada layer ini kita akan berbicara tentang voltase kabel, frekuensi radio, dan aliran bit lainnya.

### Data Link Layer (Layer 2)
Lapisan ini menyediakan layanan transmisi data yang bebas dari error antara 2 *node* yang tersambung melalui physical layer. Layer ini memecah data dari layer *network* menjadi *frame-frame* dan mengirimkannya ke *node* lain yang kemudian digabung kembali. Fungsi utamanya adalah *physical addressing* (MAC Address) dan mendeteksi dan mengoreksi eror yang terjadi di kabel.

### Network Layer (Layer 3)
Layer ini mengontrol bagaimana sebuah paket diteruskan dari komputer asal ke tujuan dalam sebuah jaringan. Layer ini memiliki tugas utama, **routing**, yaitu menentukan jalur terbaik bagi paket data untuk sampai dari sumber ke tujuan akhir. Protokol utamanya adalah IP (*Internet Protocol*), unit datanya disebut *package*.

### Transport Layer (Layer 4)
Layer ini merupakan jembatan antara *media layer* dengan *host layer*. Layer ini menjamin pengiriman data secara *end-to-end*. Beberapa fungsinya di antara lain adalah *end-to-end flow control*, *end-to-end error detection & correction*, dan *congestion control* tambahan.  

### Session Layer (Layer 5)
Layer ini mengelola interaksi/sesi antara dua komputer. Ia mengatur kapan koneksi dimulai, siapa yang boleh berbicara (*dialogue control*), siapa yang memiliki akses (*token management*), sinkronisasi data (jika koneksi terputus tetap dapat dilanjutkan dari titik terakhir),  dan lain-lain. 

### Presentation Layer (Layer 6)
Layer ini berkaitan dengan sintaks dan semantik data yang dikirimkan (bukan terkait transmisi data). Ia bertindak sebagai penerjemah agar data yang dikirim oleh satu aplikasi dapat dibaca oleh aplikasi lain. 

### Application Layer (Layer 7)
Layer ini yang berinteraksi langsung dengan pengguna. Layer ini bukan tentang aplikasinya, seperti *web browser*, tetapi protokol yang memungkinkan apllikasi tersebut berjalan dan menggunakan jaringan (HTTP untuk *web*, SMTP untuk *email*, FTP untuk *transfer file*)

## TCP/IP
Walaupun OSI model, secara teori, merupakan model yang lengkap dan baik, TCP/IP merupakan model yang lebih populer dan diaplikasikan di internet secara menyeluruh. TCP/IP tidak berbasis sepenuhnya pada OSI Model, tetapi mengambil beberapa konsep pada OSI.

TCP/IP merupakan arsitektur protokol dari internet. TCP/IP Suite memiliki empat layer, yaitu *Application*, *Transport*, *Network*, dan *Data Link Layer*. *End system* mengimplementasi keempat layer. Sedangkan, *gateaway* (*router*) hanya memiliki dua layer paling bawah (*Network* dan *Data Link*).

![[Pasted image 20260218163139.png]]

![[Pasted image 20260218163210.png]]

## Internet Layered Model
![[Pasted image 20260218163327.png]]

![[Pasted image 20260218163334.png]]

## Protokol
Protokol merupakan kesepakatan (konvensi) antara pihak-pihak terkait tentang bagaimana komunikasi harus dilakukan. Setiap layer memiliki protokolnya masing-masing, misal:
- *Applicaton Layer*: HTTP, FTP, DNS, DHCP
- *Transport Layer*: TCP, UDP
- *Network Layer*: IP, ICMP, RIP
- *Data Link*: ARP, Ethernet

Kompleksitas *communication task* dikurangi dengan menggunakan *multiple protocol layer*, di mana setiap protokol diimplementasi secara independen, setiap protokol bertanggung jawab pada satu subtugas, dan protokol dikelompokkan dalam sebuah hierarki.

Protokol harus mendefinisikan *interface* ke layer yang di atasnya (API) dan *interface* ke satu sama lain (sintaks dan semantik, seperti format dan urutan dari sebuah *message*, *error handling*, *termination*, *request*, dan lain-lain). 
![[Pasted image 20260218163846.png]]

## KEY TAKEAWAY
![[Pasted image 20260218163905.png]]


