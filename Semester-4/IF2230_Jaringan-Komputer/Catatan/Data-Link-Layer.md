# Data Link Layer

## Hubungan dengan CPMK

> **CPMK1** — Data Link Layer adalah Layer 2 dari model OSI, menjembatani Physical Layer dengan Network Layer dalam arsitektur berlapis.
> **CPMK2** — Materi *multiple access protocols* (CSMA/CD, CSMA/CA) secara langsung mencakup prinsip dasar Medium Access Layer.
> **CPMK3** — Materi *reliable delivery* (ARQ protocols, error detection/correction) dan *switching* (bridging, STP) secara langsung mencakup CPMK3 tentang switched networks dan reliable message delivery.
> **CPMK5** — Konsep MAC address, Ethernet frame, dan LAN switching menjadi dasar konfigurasi LAN.

---

## Outline Konsep Fundamental

- **Data Link Layer**
  - Framing
    - Byte-Oriented (Sentinel, Byte Counting)
    - Bit-Oriented (HDLC)
    - Clock-based (SONET)
  - Error Handling
    - Error Detection
      - Parity Bit (1D, 2D)
      - Checksum (1's complement)
      - CRC (polynomial division mod-2)
    - Error Correction
      - Hamming Code (FEC)
  - Reliable Delivery
    - ARQ Protocols
      - Stop-and-Wait
      - Sliding Window
        - Go-Back-N (RWS = 1)
        - Selective Repeat (RWS = SWS)
  - Multiple Access (Shared Medium)
    - ALOHA (Pure & Slotted)
    - CSMA
    - CSMA/CD (Ethernet)
    - CSMA/CA (Wi-Fi 802.11) — RTS/CTS, Hidden Node Problem
  - Ethernet & MAC
    - MAC Address (6 bytes)
    - Ethernet Frame Structure
  - Bridging & Switching
    - Hub vs Bridge/Switch vs Router
    - Learning Algorithm
    - Spanning Tree Protocol (STP)

---

## Penjelasan Materi

### Framing

**TL;DR:** *Framing adalah proses memecah aliran bit dari Physical Layer menjadi blok-blok diskret (frame) agar penerima bisa menentukan batas awal dan akhir setiap unit data.*

Physical Layer hanya menyampaikan bit mentah tanpa tahu di mana satu "pesan" berakhir dan pesan berikutnya dimulai. Data Link Layer menyelesaikan masalah ini melalui *framing*. Framing juga berguna untuk membatasi dampak error (error hanya merusak satu frame, bukan seluruh data), menyesuaikan dengan kapasitas buffer penerima, dan menyinkronkan kedua sisi komunikasi.

Terdapat tiga pendekatan framing:

- **Byte-Oriented**
  - *Sentinel Approach* (BISYNC, PPP): Menambahkan karakter khusus `START` dan `END` (flag `01111110`). Jika karakter `END` muncul di dalam data, digunakan *character stuffing* dengan menyisipkan karakter DLE (*Data Link Escape*) sebelumnya.
  - *Byte Counting* (DDCMP): Menyisipkan panjang frame di header. Rentan terhadap *framing error* jika field penghitung rusak.

- **Bit-Oriented**
  - *HDLC*: Menggunakan flag `01111110` sebagai pembatas. Untuk menghindari flag palsu di dalam data, digunakan *bit stuffing*: pengirim menyisipkan bit `0` setiap kali menemukan lima bit `1` berurutan. Penerima membuang bit `0` setelah lima bit `1`.

- **Clock-based**
  - *SONET*: Menggunakan frame berukuran tetap (810 bytes) dan sinkronisasi berbasis clock/pewaktuan. Dipakai pada jaringan optik berkecepatan sangat tinggi.

---

### Error Detection

**TL;DR:** *Error detection menambahkan bit redundan ke frame agar penerima dapat mendeteksi apakah ada bit yang rusak selama transmisi.*

Dunia fisik rentan terhadap *noise* yang menyebabkan *single-bit error* maupun *burst error*. Error detection tidak memperbaiki error, melainkan hanya mendeteksinya — frame yang error biasanya langsung dibuang dan diminta kirim ulang.

#### Parity Bit

- Menambahkan 1 bit ekstra sehingga total bit `1` dalam data berjumlah genap (*even parity*) atau ganjil (*odd parity*).
- *2D Parity (Two-Dimensional Parity)*: Melakukan cek paritas per baris DAN per kolom, sehingga mampu mendeteksi lebih banyak kombinasi error dan bahkan dapat melokalisasi bit yang error.

#### Checksum

- Digunakan di TCP/IP.
- **Cara kerja:**
  1. Data dibagi menjadi blok-blok *n* bit.
  2. Semua blok dijumlahkan menggunakan aritmatika *1's complement*.
  3. Hasil penjumlahan di-*komplemen* (bit-flip) → hasilnya adalah *checksum* yang dikirim bersama data.
  4. Penerima menjumlahkan semua blok data + checksum. Jika hasilnya (setelah dikomplemen) = `0`, data dianggap bebas error.

#### CRC (Cyclic Redundancy Check)

- Paling tangguh untuk mendeteksi *burst error*. Diimplementasikan di perangkat keras menggunakan *shift register*.
- **Cara kerja (polynomial division mod-2 / XOR):**
  1. Tentukan *generator polynomial* `P` sepanjang `n-k+1` bit (disepakati oleh kedua sisi).
  2. Data `D` (k bit) digeser kiri sebanyak `n-k` bit → `2^(n-k) × D`.
  3. Hitung sisa bagi (mod-2): `R = (2^(n-k) × D) mod P` → ini adalah *Frame Check Sequence (FCS)*.
  4. Frame yang dikirim: `T = 2^(n-k) × D + R`.
  5. Penerima membagi `T` dengan `P`. Jika sisa = `0`, tidak ada error.

---

### Error Correction

**TL;DR:** *Forward Error Correction (FEC) menambahkan kode redundan yang cukup untuk memungkinkan penerima menemukan dan memperbaiki sendiri bit yang salah tanpa retransmisi.*

Berbeda dengan error *detection*, error *correction* (FEC) menghilangkan kebutuhan untuk meminta kirim ulang. Ini penting untuk media satu arah atau media dengan RTT sangat besar (misal: komunikasi satelit).

#### Hamming Code

- Bit-bit redundansi (bit paritas) ditempatkan pada posisi yang merupakan pangkat dari 2: **posisi 1, 2, 4, 8, 16, ...**
- Setiap bit paritas bertanggung jawab mengecek kombinasi bit data tertentu.
- Jika terjadi error, kombinasi bit paritas yang **gagal** akan membentuk angka yang langsung menunjuk pada **indeks bit yang salah** → bit tersebut dibalik untuk koreksi.

---

### Flow Control & ARQ Protocols

**TL;DR:** *ARQ (Automatic Repeat Request) memastikan pengiriman yang andal menggunakan acknowledgment dan timeout untuk meminta retransmisi frame yang hilang.*

Reliable delivery di Data Link Layer bergantung pada dua mekanisme:
- **ACK (Acknowledgment):** Penerima memberitahu pengirim bahwa frame telah diterima dengan benar.
- **Timeout:** Jika ACK tidak datang dalam batas waktu tertentu, pengirim mengasumsikan frame hilang dan mengirim ulang.

#### Stop-and-Wait

- Pengirim mengirim **satu frame**, lalu **berhenti** menunggu ACK sebelum mengirim frame berikutnya.
- Menggunakan **1-bit sequence number** (bergantian antara 0 dan 1) untuk mencegah kebingungan akibat frame duplikat.
- **Kelemahan:** Utilization sangat rendah pada link berkecepatan tinggi dengan propagation delay besar.

**Rumus Utilization Stop-and-Wait:**

```
Max Sending Rate = Bits per Frame / RTT
Utilization      = Max Sending Rate / Bandwidth
```

*Contoh:* Bandwidth = 10 Gbps, RTT = 20 ms, Frame = 1500 Bytes (12.000 bit)
- Max Sending Rate = 12.000 bit / 20 ms = 600 Kbps
- Utilization = 600 Kbps / 10 Gbps = **0,006%** ← sangat tidak efisien

#### Sliding Window

- Pengirim diperbolehkan mengirim beberapa frame sekaligus (sebanyak *window size*) sebelum menerima ACK → prinsip **"keeping the pipe full"**.
- **SWS** (*Send Window Size*): jumlah maksimal frame yang dikirim tapi belum di-ACK.
- **RWS** (*Receive Window Size*): jumlah maksimal frame out-of-order yang bisa di-buffer penerima.

**Rumus Window Size Ideal:**
```
Window Size ≥ RTT × Bandwidth   (dalam satuan bit atau frame)
```

**Go-Back-N (RWS = 1):**
- Penerima **tidak mem-buffer** frame out-of-order. Jika frame ke-`i` hilang, frame `i+1`, `i+2`, ... semuanya dibuang dan pengirim harus mengirim ulang dari frame `i`.
- Batasan SWS: `MaxSeqNum ≥ SWS + 1`

**Selective Repeat (RWS = SWS):**
- Penerima **mem-buffer** frame out-of-order. Pengirim hanya perlu mengirim ulang frame spesifik yang hilang.
- Batasan SWS: `SWS < (MaxSeqNum + 1) / 2`
- *Mengapa?* SWS tidak boleh ≥ separuh MaxSeqNum agar penerima tidak bingung membedakan frame baru vs retransmisi frame lama ketika banyak ACK hilang sekaligus.

| Aspek | Stop-and-Wait | Go-Back-N | Selective Repeat |
|---|---|---|---|
| Frame in-flight | 1 | SWS frame | SWS frame |
| Buffer penerima | 1 | 1 | SWS frame |
| Retransmisi saat error | 1 frame | Frame hilang + semua setelahnya | Hanya frame yang hilang |
| Kompleksitas | Rendah | Menengah | Tinggi |

---

### Multiple Access Protocols

**TL;DR:** *Multiple access protocols mengatur bagaimana beberapa node berbagi satu medium transmisi tanpa menabrak data satu sama lain.*

Pada *shared/broadcast medium*, jika dua node mengirim bersamaan terjadi **collision** (tabrakan) yang merusak kedua frame.

#### ALOHA

- *Pure ALOHA*: Kirim kapan saja, jika collision tunggu waktu acak lalu coba lagi.
- *Slotted ALOHA*: Waktu dibagi menjadi slot, node hanya boleh mulai kirim di awal slot → efisiensi lebih tinggi (teoritis maks ~37%).

#### CSMA (Carrier Sense Multiple Access)

- Sebelum mengirim, node **"mendengarkan"** medium terlebih dahulu (*carrier sense*).
- Jika medium kosong, baru mengirim.
- Jika medium sibuk, tunggu hingga kosong.

#### CSMA/CD (Collision Detection) — Ethernet

- Digunakan pada **jaringan Ethernet (kabel)**.
- Node tetap memantau medium **saat mengirim**. Jika mendeteksi collision (perubahan voltase):
  1. Hentikan transmisi segera.
  2. Kirim *jam signal* untuk memberitahu semua node bahwa terjadi collision.
  3. Terapkan **Exponential Backoff**: tunggu selama `K × 51.2 μs`, di mana K dipilih acak dari `{0, 1, ..., 2^m - 1}` (m = jumlah percobaan yang gagal).
  4. Coba kirim lagi.

#### CSMA/CA (Collision Avoidance) — Wi-Fi 802.11

- Digunakan pada **jaringan nirkabel (Wi-Fi)**.
- Collision **sulit dideteksi** di wireless karena sinyal pengirim sendiri menutupi sinyal datang → strategi berubah dari *detect* ke *avoid*.

**Hidden Node Problem:**
- Node A dan C sama-sama dalam jangkauan Node B, tetapi **A dan C tidak saling terjangkau**.
- Jika A dan C kirim ke B bersamaan → collision di B, tapi A dan C tidak sadar karena tidak bisa saling mendengar.

**Solusi: RTS/CTS**
1. **RTS (Ready to Send):** Pengirim (A) mengirim paket kecil RTS ke penerima (B) berisi estimasi durasi transmisi.
2. **CTS (Clear to Send):** Jika saluran bebas, B merespons dengan CTS.
3. Node C **mendengar CTS dari B** (meskipun tidak mendengar RTS dari A) dan tahu bahwa ia harus diam selama durasi yang tertera.
4. A mengirim data utama tanpa gangguan dari C.

---

### MAC Address & Ethernet Frame

**TL;DR:** *MAC address adalah identitas fisik 48-bit unik pada setiap network interface, digunakan Ethernet untuk mengalamatkan frame di dalam satu jaringan lokal.*

MAC address tertanam pada Network Interface Card (NIC). Berbeda dengan IP address yang bersifat logis dan bisa berubah, MAC address bersifat fisik dan permanen (meski bisa di-*spoof*).

**Struktur Ethernet Frame:**

| Field | Ukuran | Keterangan |
|---|---|---|
| Destination Address | 6 bytes | MAC tujuan |
| Source Address | 6 bytes | MAC pengirim |
| Type / Length | 2 bytes | Protokol L3 (misal 0x0800 = IPv4) atau panjang data |
| Data / Payload | hingga 1500 bytes | Paket dari Network Layer |
| CRC | 4 bytes | CRC-32 untuk error detection; frame dibuang jika error |

---

### Bridging & Switching

**TL;DR:** *Bridge dan switch bekerja di Layer 2 untuk mengisolasi collision domain dan meneruskan frame berdasarkan MAC address, sedangkan Spanning Tree Protocol mencegah loop pada topologi berlebih.*

#### Perbandingan Perangkat Jaringan

| Perangkat       | Layer | Basis Forwarding          | Collision Domain              |
| --------------- | ----- | ------------------------- | ----------------------------- |
| Hub / Repeater  | L1    | Sinyal fisik (semua port) | Satu domain (semua tergabung) |
| Bridge / Switch | L2    | MAC Address               | Terisolasi per port           |
| Router          | L3    | IP Address                | Terisolasi, antar-jaringan    |

Bridge dan switch menggunakan metode **store-and-forward**: frame diterima sepenuhnya, dicek CRC, baru diteruskan. Ini memungkinkan isolasi collision domain.

#### Learning Algorithm

Bridge/switch **mempelajari topologi secara dinamis** tanpa konfigurasi manual:

1. Tabel forwarding awalnya **kosong**.
2. Saat menerima frame, bridge membaca **source MAC address** dan mencatat: "MAC X berada di port Y" → masuk ke tabel.
3. Untuk meneruskan frame:
   - Jika **destination MAC ada di tabel** → kirim hanya ke port yang sesuai.
   - Jika **destination MAC belum dikenal** → **flooding** (kirim ke semua port kecuali port asal).
4. Setiap entri memiliki **timeout (TTL)**; entri yang kadaluarsa dihapus agar tabel tetap relevan saat perangkat berpindah.

#### Spanning Tree Protocol (STP)

Jaringan dengan banyak bridge/switch sering memiliki jalur redundan → tanpa STP, terjadi **broadcast storm** (loop tak terhingga). STP dijalankan secara *terdistribusi* untuk membentuk topologi pohon (*tree*) bebas loop.

**Langkah STP:**
1. **Pilih Root Bridge:** Setiap bridge punya ID unik. Bridge dengan **ID terkecil** menjadi *Root Bridge*. Root bridge meneruskan ke semua port-nya.
2. **Hitung jalur terpendek ke Root:** Setiap bridge menentukan *preferred port* (port yang mengarah ke Root dengan cost terendah).
3. **Pilih Designated Bridge per segmen:** Pada setiap segmen LAN yang terhubung ke beberapa bridge, satu *Designated Bridge* dipilih (yang paling dekat ke Root; jika sama, ID lebih kecil menang).
4. **Nonaktifkan port redundan:** Port yang tidak terpilih sebagai *preferred* maupun *designated* dimatikan → topologi menjadi pohon tanpa siklus.

---

## Komponen Kunci

| Istilah | Definisi Singkat |
|---|---|
| **Frame** | Unit data di Data Link Layer; berisi header, payload, dan trailer |
| **Framing** | Proses membagi aliran bit menjadi frame dengan batas yang jelas |
| **Bit Stuffing** | Menyisipkan bit `0` setelah 5 bit `1` berurutan untuk menghindari flag palsu (HDLC) |
| **Character Stuffing** | Menyisipkan DLE sebelum karakter END yang muncul di dalam data |
| **Parity Bit** | Bit tambahan untuk memastikan jumlah bit `1` genap/ganjil |
| **Checksum** | Hasil komplementasi penjumlahan 1's complement dari semua blok data |
| **CRC** | Sisa pembagian polinomial mod-2; sangat andal untuk burst error |
| **FCS** | Frame Check Sequence — nilai CRC yang disertakan di akhir frame |
| **Hamming Code** | Kode FEC yang menempatkan bit paritas di posisi pangkat-2 untuk koreksi error |
| **ARQ** | Automatic Repeat Request — mekanisme reliable delivery via ACK + timeout |
| **Stop-and-Wait** | ARQ dengan satu frame in-flight; seq number 1-bit |
| **SWS** | Send Window Size — jumlah frame yang boleh dikirim sebelum ACK |
| **RWS** | Receive Window Size — jumlah frame out-of-order yang bisa di-buffer penerima |
| **Go-Back-N** | Sliding window dengan RWS=1; error menyebabkan retransmisi dari frame yang hilang ke depan |
| **Selective Repeat** | Sliding window dengan RWS=SWS; hanya frame yang hilang yang diretransmisi |
| **Collision** | Tabrakan data ketika dua node kirim bersamaan di shared medium |
| **CSMA/CD** | Protokol Ethernet; deteksi collision, lalu exponential backoff |
| **CSMA/CA** | Protokol Wi-Fi; hindari collision dengan RTS/CTS |
| **Hidden Node Problem** | Dua node tidak saling terjangkau, keduanya bisa menyebabkan collision di penerima |
| **RTS/CTS** | Handshake kecil sebelum transmisi data besar pada Wi-Fi untuk cegah hidden node |
| **MAC Address** | Alamat fisik 48-bit unik pada NIC; digunakan untuk pengalamatan Layer 2 |
| **Broadcast** | Frame dikirim ke semua node di jaringan (MAC tujuan: `FF:FF:FF:FF:FF:FF`) |
| **Store-and-Forward** | Bridge/switch menerima frame penuh, cek CRC, lalu teruskan |
| **Flooding** | Bridge meneruskan frame ke semua port (kecuali asal) saat MAC tujuan belum dikenal |
| **Learning Algorithm** | Mekanisme bridge membangun tabel MAC-port secara dinamis dari source address frame masuk |
| **STP** | Spanning Tree Protocol; mencegah loop dengan menonaktifkan port redundan |
| **Root Bridge** | Bridge dengan ID terkecil yang menjadi pusat topologi pohon di STP |
| **Designated Bridge** | Bridge terpilih per segmen LAN untuk meneruskan frame ke Root Bridge |

---

## Rumus Kunci

```
# Stop-and-Wait Utilization
Max Sending Rate = Bits per Frame / RTT
Utilization      = Max Sending Rate / Bandwidth

# Sliding Window - Window Size Ideal
Window Size ≥ RTT × Bandwidth

# Go-Back-N - Batasan SWS
MaxSeqNum ≥ SWS + 1

# Selective Repeat - Batasan SWS
SWS < (MaxSeqNum + 1) / 2

# CRC
Frame yang dikirim: T = 2^(n-k) × D + R
FCS: R = (2^(n-k) × D) mod P
Cek: T mod P = 0 → bebas error
```

---

## Checklist Pemahaman

### Sub-materi yang Dibahas
1. Framing (Byte-Oriented, Bit-Oriented, Clock-based)
2. Error Detection — Parity Bit, Checksum, CRC
3. Error Correction — Hamming Code
4. ARQ Protocols — Stop-and-Wait, Go-Back-N, Selective Repeat
5. Multiple Access — ALOHA, CSMA, CSMA/CD, CSMA/CA + RTS/CTS
6. MAC Address & Ethernet Frame Structure
7. Bridging & Switching — Learning Algorithm, STP

### Prioritas Belajar

🔴 **Wajib dikuasai:**
- CRC: cara kerja (polynomial division mod-2), formula `T = 2^(n-k)D + R`
- ARQ: perbedaan Stop-and-Wait vs Go-Back-N vs Selective Repeat
- Rumus utilization Stop-and-Wait dan window size sliding window
- Batasan SWS untuk Go-Back-N (`MaxSeqNum ≥ SWS + 1`) dan Selective Repeat (`SWS < (MaxSeqNum+1)/2`)
- CSMA/CD vs CSMA/CA: cara kerja dan konteks penggunaannya
- Hidden Node Problem + solusi RTS/CTS
- Learning Algorithm pada bridge/switch
- STP: mekanisme pemilihan Root Bridge dan Designated Bridge

🟡 **Cukup paham konsep:**
- Framing: tahu 3 pendekatan dan contoh protokolnya (PPP, HDLC, SONET)
- Bit stuffing dan character stuffing (tahu tujuan, tidak perlu hafal detail)
- Checksum: tahu prosedur 1's complement
- Hamming Code: tahu posisi bit paritas di power-of-2, tidak perlu hafal perhitungan detail
- Parity Bit (1D dan 2D)
- ALOHA: tahu konsep pure vs slotted, tidak perlu rumus throughput
- Ethernet frame structure: urutan field dan ukurannya
- Perbandingan Hub/Bridge-Switch/Router

✅ **Sudah dikuasai:**
- Physical Layer (seluruh materi)
