# Internetworking & Network Layer

## Hubungan dengan CPMK

> **CPMK1** — Network Layer adalah Layer 3 OSI, lapisan yang menyatukan seluruh arsitektur internetwork.
> **CPMK4** — Routing protocols (DV, LS, BGP), forwarding, dan longest prefix matching secara langsung mencakup prinsip routing dan packet forwarding pada jaringan IP.
> **CPMK5** — IP addressing, subnetting, ARP, dan NAT adalah fondasi konfigurasi LAN dan jaringan IP.

---

## Outline Konsep Fundamental

- **Internetworking & Network Layer**
  - Fungsi Network Layer
  - Model Layanan Switching
    - Datagram (Connectionless)
    - Virtual Circuit (Connection-oriented)
  - IP Addressing
    - Format IPv4 (32-bit)
    - Classful Addressing (Kelas A/B/C/D/E)
    - CIDR / Classless
  - Subnetting
    - Network Address, Broadcast, Range Host
    - Jumlah Subnet (2^n), Jumlah Host (2^h − 2)
  - IP Packet Header
    - Field-field penting
    - Fragmentasi (Identification, Flags, Fragment Offset)
  - Forwarding vs Routing
    - Routing Table vs Forwarding Table
    - Longest Prefix Matching
  - Routing Protocols
    - Distance Vector (Bellman-Ford, RIP, count-to-infinity, split horizon)
    - Link State (Dijkstra, OSPF, LSA flooding)
    - BGP (inter-AS, Autonomous System)
  - Protokol Pendukung
    - ARP (IP → MAC)
    - ICMP (error reporting, ping, traceroute)
    - NAT (private → public IP)

---

## Penjelasan Materi

### Fungsi Network Layer & Internetworking

**TL;DR:** *Network Layer menghubungkan berbagai jaringan heterogen menjadi satu internetwork yang menyediakan layanan pengiriman paket host-to-host menggunakan pengalamatan logis global.*

Dunia nyata terdiri dari beragam jaringan fisik dengan teknologi berbeda — Ethernet, WiFi, jaringan seluler, dan lain-lain. *Internetworking* adalah konsep menghubungkan kumpulan jaringan beragam ini secara *ad-hoc* sehingga setiap host dapat berkomunikasi dengan host lain di jaringan mana pun. Kumpulan jaringan yang terhubung disebut *internetwork* atau Internet.

Network Layer (Layer 3 OSI) menjadi jembatan standar yang menyembunyikan keberagaman fisik di bawahnya dengan tiga fungsi utama:
- **Routing:** Menentukan jalur terbaik yang akan dilalui paket dari sumber ke tujuan melintasi router-router.
- **Forwarding:** Aksi lokal memindahkan paket dari port masuk ke port keluar di sebuah router berdasarkan tabel.
- **Interkoneksi heterogen:** Menangani komunikasi antar subnet yang memiliki protokol Data Link dan medium fisik berbeda.

---

### Model Layanan: Datagram vs Virtual Circuit

**TL;DR:** *Datagram meneruskan setiap paket secara independen tanpa setup koneksi; Virtual Circuit membangun jalur logis terlebih dahulu sebelum data dikirim.*

| Aspek | Datagram (Connectionless) | Virtual Circuit (Connection-oriented) |
|---|---|---|
| **Setup** | Tidak ada | Wajib ada sebelum kirim data |
| **Per-paket** | Bawa alamat tujuan lengkap | Bawa VCI (identifier pendek) |
| **State di router** | Tidak ada | Menyimpan state per koneksi |
| **Robustness** | Tinggi — rute alternatif otomatis | Rendah — satu link putus, koneksi mati |
| **QoS** | Sulit dijamin | Bisa dijamin (alokasi bandwidth) |
| **Overhead header** | Besar (alamat lengkap) | Kecil (hanya VCI) |
| **Contoh** | IP (Internet) | ATM, X.25 |

**Kelebihan Datagram:** Jika router/tautan mati, paket berikutnya otomatis dialihkan ke rute lain. Host langsung kirim tanpa jeda setup.

**Kelebihan Virtual Circuit:** QoS dapat dijamin karena bandwidth dialokasikan eksklusif. Overhead header kecil per paket.

---

### IP Addressing (IPv4)

**TL;DR:** *IPv4 menggunakan alamat logis 32-bit yang ditulis dalam notasi desimal bertitik, dibagi secara historis berdasarkan kelas, dan kini dialokasikan secara fleksibel dengan CIDR.*

Alamat IP adalah identitas logis 32-bit pada setiap *network interface*. Ditulis dalam *dotted decimal notation* — empat angka desimal (masing-masing 1 byte) dipisah titik, misal `192.168.1.1`.

Struktur hierarki: **Network Part | Host Part** — dipisahkan oleh *subnet mask*.

#### Classful Addressing

| Kelas | Range Pertama Oktet | Default Mask | Keterangan |
|---|---|---|---|
| **A** | 1 – 126 | /8 | Jaringan raksasa; 24 bit untuk host |
| **B** | 128 – 191 | /16 | Jaringan menengah-besar; 16 bit untuk host |
| **C** | 192 – 223 | /24 | Jaringan kecil; 8 bit untuk host (maks 254 host) |
| **D** | 224 – 239 | — | Multicast |
| **E** | 240 – 255 | — | Reserved/eksperimental |

> `127.x.x.x` = loopback (localhost), bukan kelas A yang valid untuk host.

#### CIDR (Classless InterDomain Routing)

Diciptakan untuk mengatasi kehabisan alamat IPv4 dan ledakan ukuran tabel routing. CIDR menghapus batasan kaku kelas dan memungkinkan alokasi blok fleksibel dalam kelipatan pangkat 2.

- Notasi: `a.b.c.d/x` — `x` adalah panjang prefix jaringan dalam bit.
- Contoh: `200.23.16.0/23` artinya 23 bit pertama = network, 9 bit = host.

---

### Subnetting

**TL;DR:** *Subnetting meminjam bit dari porsi host untuk memecah satu blok jaringan besar menjadi beberapa sub-jaringan yang lebih kecil dan lebih mudah dikelola.*

Router menggunakan *subnet mask* untuk menentukan apakah alamat tujuan berada di subnet lokal atau harus di-forward ke router lain.

#### Langkah Kalkulasi

1. **Network Address** = IP `AND` Subnet Mask (bitwise)
2. **Broadcast Address** = Network Address `OR` inverse(Subnet Mask) — semua bit host menjadi `1`
3. **Range Host Valid** = (Network Address + 1) hingga (Broadcast Address − 1)
4. **Jumlah Subnet** = 2^n, di mana n = bit yang "dipinjam" dari porsi host
5. **Jumlah Host per Subnet** = 2^h − 2, di mana h = sisa bit host (-2 karena network dan broadcast address tidak bisa dipakai)

#### Contoh

IP: `128.96.34.15`, Mask: `255.255.255.128` (/25)

```
IP biner   : 10000000.01100000.00100010.00001111
Mask biner : 11111111.11111111.11111111.10000000

Network    : 128.96.34.0     (hasil AND)
Broadcast  : 128.96.34.127   (semua bit host = 1)
Range host : 128.96.34.1  –  128.96.34.126
Jumlah host: 2^7 − 2 = 126
```

---

### IP Packet Header

**TL;DR:** *Header IPv4 berukuran minimum 20 byte berisi metadata routing dan kontrol, termasuk TTL untuk mencegah loop dan field fragmentasi untuk memecah paket besar.*

```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|Version|  IHL  |Type of Service|          Total Length         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|         Identification        |Flags|      Fragment Offset    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Time to Live |    Protocol   |         Header Checksum       |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                       Source Address                          |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Destination Address                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

| Field | Ukuran | Fungsi |
|---|---|---|
| **Version** | 4 bit | Versi IP; bernilai 4 untuk IPv4 |
| **IHL** | 4 bit | Header length dalam satuan 32-bit word (biasanya 5 = 20 byte) |
| **TOS** | 8 bit | Type of Service; prioritas / QoS |
| **Total Length** | 16 bit | Ukuran total datagram (header + data); maks 65.535 byte |
| **Identification** | 16 bit | ID unik untuk mengelompokkan semua fragmen dari satu datagram |
| **Flags** | 3 bit | **DF** (Don't Fragment) dan **MF** (More Fragments — masih ada fragmen berikutnya) |
| **Fragment Offset** | 13 bit | Posisi fragmen dalam datagram asli (dalam satuan 8 byte) |
| **TTL** | 8 bit | Dikurangi 1 tiap melewati router; paket dibuang jika TTL = 0 → cegah loop |
| **Protocol** | 8 bit | Protokol layer atas: `6` = TCP, `17` = UDP |
| **Header Checksum** | 16 bit | 1's complement checksum untuk header; paket dibuang jika error |
| **Source Address** | 32 bit | IP pengirim |
| **Destination Address** | 32 bit | IP tujuan; basis keputusan routing |

#### Fragmentasi

Setiap medium fisik punya batas **MTU** (*Maximum Transmission Unit*). Jika paket lebih besar dari MTU link yang akan dilalui, router memecahnya menjadi fragmen-fragmen menggunakan field Identification, Flags (MF), dan Fragment Offset. **Reassembly hanya dilakukan oleh host tujuan**, bukan router di tengah jalan — agar router tetap sederhana.

---

### Forwarding vs Routing

**TL;DR:** *Forwarding adalah aksi lokal memindahkan paket berdasarkan tabel; Routing adalah proses terdistribusi antar-router untuk membangun tabel tersebut.*

|               | Forwarding                      | Routing                            |
| ------------- | ------------------------------- | ---------------------------------- |
| **Sifat**     | Lokal (per-router)              | Terdistribusi (antar-router)       |
| **Kecepatan** | Harus cepat (hardware)          | Bisa lambat (software)             |
| **Input**     | Forwarding table + paket datang | Topologi jaringan + algoritma      |
| **Output**    | Paket diteruskan ke port keluar | Routing/forwarding table terbangun |

**Routing Table** — dibangun oleh algoritma routing (RIP, OSPF); berisi pemetaan prefiks → next hop + metrik.

**Forwarding Table** — dioptimalkan untuk kecepatan lookup; berisi pemetaan prefiks → interface fisik (+ MAC untuk L2).

#### Longest Prefix Matching

Ketika beberapa entri tabel cocok dengan alamat tujuan, dipilih entri dengan **prefix terpanjang** (paling spesifik).

*Contoh:* tabel punya `171.69.0.0/16` dan `171.69.10.0/24`.
- Paket ke `171.69.10.5` → cocok dengan `/24` ✓ (lebih spesifik)
- Paket ke `171.69.20.5` → cocok dengan `/16` saja

---

### Routing Protocols — Distance Vector

**TL;DR:** *Setiap router berbagi seluruh tabel rutenya hanya kepada tetangga langsung; rute terbaik dihitung menggunakan Bellman-Ford secara iteratif.*

**Prinsip kerja:**
- Setiap router menyimpan *vektor* berisi estimasi jarak ke semua node.
- Secara berkala, router mengirimkan seluruh tabelnya ke tetangga langsung.
- Setiap router memperbarui tabelnya berdasarkan info dari tetangga: `d(x,y) = min_v { c(x,v) + d(v,y) }`

**Bellman-Ford:** `D(x,y) = min_v { cost(x,v) + D(v,y) }`

#### Masalah: Count-to-Infinity

Jika tautan putus, router yang kehilangan rute masih melihat tetangganya "menawarkan" rute lama (yang sebenarnya melalui dirinya sendiri). Keduanya saling menambah metrik tanpa ujung hingga batas "infinity".

**Solusi:**
- **Split Horizon:** Router tidak mengirim rute kembali ke tetangga tempat rute itu dipelajari.
- **Poison Reverse:** Rute tetap dikirim kembali ke sumber, tapi dengan metrik = ∞ — agar sumber tidak pernah menggunakannya.

#### RIP (Routing Information Protocol)

- Implementasi Distance Vector murni.
- Metrik: **hop count** (maks 15; nilai 16 = ∞ / unreachable).
- Update setiap **30 detik**.

---

### Routing Protocols — Link State

**TL;DR:** *Setiap router menyebarkan info tautan lokalnya ke seluruh jaringan (bukan hanya ke tetangga), lalu setiap router secara mandiri menghitung jalur terpendek menggunakan Dijkstra.*

**Prinsip kerja:**
1. Setiap router membuat **LSP/LSA** (*Link State Packet/Advertisement*) berisi: ID router, biaya ke setiap tetangga, sequence number, TTL.
2. LSP disebarkan ke seluruh jaringan via **Reliable Flooding**: terima LSP baru → simpan → teruskan ke semua port kecuali asal.
3. Setiap router mengumpulkan semua LSP → memiliki **peta topologi lengkap**.
4. Jalankan **algoritma Dijkstra** secara independen → hitung shortest path ke semua tujuan.

#### OSPF (Open Shortest Path First)

- Implementasi Link State yang populer.
- Fitur tambahan: autentikasi, multi-metrik (TOS), hierarki area (backbone + area lokal).

---

### Perbandingan DV vs LS

| Aspek                | Distance Vector                | Link State                          |
| -------------------- | ------------------------------ | ----------------------------------- |
| **Info yang dibagi** | Seluruh tabel rute ke tetangga | Info tautan lokal ke semua router   |
| **Konvergensi**      | Lambat, O(k) ronde             | Cepat                               |
| **Overhead pesan**   | Rendah (update periodik)       | Tinggi di awal (O(n²×e))            |
| **Memori router**    | Hanya tabel sendiri            | Seluruh peta topologi               |
| **Robustness**       | Rentan — error propagates      | Tinggi — tiap router hitung sendiri |
| **Loop**             | Rentan (count-to-infinity)     | Bebas loop (Dijkstra)               |
| **Contoh**           | RIP                            | OSPF                                |

---

### BGP (Border Gateway Protocol)

**TL;DR:** *BGP adalah protokol routing antar-AS (inter-domain) yang menitikberatkan kebijakan administratif, bukan sekadar jalur terpendek — fondasi routing di seluruh Internet.*

**Autonomous System (AS):** Sekelompok jaringan dan router di bawah satu otoritas administratif (ISP, kampus, perusahaan) yang menggunakan protokol routing internal (IGP) yang sama. Setiap AS diberi nomor unik (ASN).

| | IGP (OSPF/RIP) | BGP |
|---|---|---|
| **Scope** | Intra-AS (dalam satu AS) | Inter-AS (antar AS) |
| **Tujuan** | Performa (jalur terpendek) | Kebijakan administratif |
| **Contoh** | OSPF, RIP | BGP |

**eBGP** (external BGP): Sesi BGP antar router di AS yang berbeda.
**iBGP** (internal BGP): Sesi BGP antar router dalam satu AS yang sama, untuk menyebarkan info yang dipelajari dari eBGP.

---

### ARP (Address Resolution Protocol)

**TL;DR:** *ARP menerjemahkan IP address ke MAC address agar paket bisa dikirimkan di level fisik (Ethernet).*

**Mengapa diperlukan?** Network interface (Ethernet) tidak memahami IP address — hanya mengenal MAC address. Sebelum mengirim frame, pengirim harus tahu MAC address tujuan.

**Cara kerja:**
1. Host A ingin kirim ke IP Host B, tapi tidak tahu MAC-nya.
2. A mengirim **ARP Request** secara **broadcast** ke seluruh LAN: *"Siapa yang punya IP 192.168.1.5? Beritahu saya (MAC A)."*
3. Semua host menerima, tapi hanya B yang merespons.
4. B mengirim **ARP Reply** secara **unicast** langsung ke A: *"IP 192.168.1.5 ada di MAC B."*
5. A menyimpan pemetaan `IP B → MAC B` di **ARP cache/table**.

**ARP Cache:** Bersifat dinamis dengan TTL (~15 menit). Entri dihapus jika kadaluarsa agar tabel tetap relevan saat perangkat berpindah atau alamat berubah.

---

### ICMP (Internet Control Message Protocol)

**TL;DR:** *ICMP adalah protokol pendamping IP untuk pelaporan error dan diagnostik jaringan; menjadi dasar utility ping dan traceroute.*

IP bersifat *best-effort* — tidak ada jaminan pengiriman. ICMP digunakan untuk memberitahu pengirim ketika ada masalah dalam pengiriman paket.

**Tipe pesan ICMP penting:**

| Type | Nama | Kegunaan |
|---|---|---|
| **0** | Echo Reply | Respons terhadap ping |
| **8** | Echo Request | Request ping ke tujuan |
| **3** | Destination Unreachable | Paket tidak bisa diteruskan (dengan kode spesifik: 0=net unreachable, 1=host unreachable, dst) |
| **11** | Time Exceeded | TTL habis (Code 0) → dipakai **traceroute** |

**Ping:** Kirim ICMP Type 8 (Echo Request) → terima Type 0 (Echo Reply) → ukur RTT.

**Traceroute:** Kirim paket dengan TTL=1, 2, 3, … secara berturut-turut. Setiap router yang membuang paket (karena TTL=0) mengirim ICMP Type 11 Time Exceeded → traceroute mencatat IP router tersebut → peta jalur terbentuk.

---

### NAT (Network Address Translation)

**TL;DR:** *NAT memungkinkan banyak host dengan IP privat berbagi satu IP publik dengan cara memetakan pasangan (IP privat, port) ke (IP publik, port baru) di router.*

**Motivasi:** IPv4 hanya punya ~4,3 miliar alamat — tidak cukup untuk semua perangkat. Solusi sementara: gunakan **IP privat** (RFC 1918: `10.0.0.0/8`, `172.16.0.0/12`, `192.168.0.0/16`) di jaringan lokal, dan share satu IP publik.

**Cara kerja:**
1. Host `10.0.0.1:3345` kirim paket ke internet.
2. Router NAT **mengganti** source address menjadi `138.76.29.7:5001` (IP publik + port baru).
3. Pemetaan `(10.0.0.1, 3345) ↔ (138.76.29.7, 5001)` disimpan di **NAT translation table**.
4. Server di internet membalas ke `138.76.29.7:5001`.
5. Router NAT melihat tabel → ganti destination ke `10.0.0.1:3345` → teruskan ke host lokal.

**Keterbatasan NAT:**
- Melanggar prinsip IP: setiap node seharusnya punya alamat unik global.
- Bermasalah dengan protokol yang menyematkan IP di dalam payload (misal: FTP) — router NAT harus turut mengubah isi payload.
- Koneksi *inbound* (dari internet ke host lokal) tidak bisa langsung tanpa konfigurasi manual (*port forwarding*).

---

## Komponen Kunci

| Istilah | Definisi Singkat |
|---|---|
| **Internetwork** | Kumpulan jaringan heterogen yang saling terhubung via router |
| **Datagram** | Model jaringan connectionless; setiap paket diteruskan independen |
| **Virtual Circuit** | Model jaringan connection-oriented; jalur logis dipesan sebelum data dikirim |
| **IPv4** | Protokol pengalamatan 32-bit di Network Layer |
| **Classful Addressing** | Pembagian kaku kelas A/B/C berdasarkan oktet pertama |
| **CIDR** | Pengalamatan fleksibel berbasis prefix length, menggantikan classful |
| **Subnet Mask** | Deretan bit `1` untuk memisahkan network part dan host part dari IP |
| **Network Address** | Alamat terendah subnet; hasil IP AND mask — tidak bisa dipakai host |
| **Broadcast Address** | Alamat tertinggi subnet (semua bit host = 1) — tidak bisa dipakai host |
| **MTU** | Maximum Transmission Unit — batas ukuran paket per medium fisik |
| **Fragmentasi** | Pemecahan paket besar oleh router agar muat di MTU link |
| **TTL** | Time to Live — counter di header IP yang mencegah paket loop selamanya |
| **Forwarding** | Aksi lokal router memindahkan paket dari port masuk ke port keluar |
| **Routing** | Algoritma terdistribusi antar-router untuk membangun forwarding table |
| **Longest Prefix Match** | Aturan memilih entri tabel paling spesifik yang cocok dengan alamat tujuan |
| **Distance Vector** | Algoritma routing berbasis Bellman-Ford; berbagi tabel ke tetangga saja |
| **Count-to-Infinity** | Bug DV — dua router saling menganggap rute mati masih valid secara bertahap |
| **Split Horizon** | Solusi count-to-infinity: jangan kirim rute kembali ke sumbernya |
| **Poison Reverse** | Solusi kuat: kirim rute ke sumber dengan metrik ∞ |
| **Link State** | Algoritma routing berbasis Dijkstra; sebarkan info lokal ke seluruh jaringan |
| **LSA/LSP** | Link State Advertisement/Packet — pesan yang disebarkan tiap router di LS |
| **Reliable Flooding** | Mekanisme penyebaran LSA ke semua node dalam jaringan |
| **OSPF** | Implementasi Link State Protocol yang populer |
| **RIP** | Implementasi Distance Vector; metrik hop count, maks 15 |
| **AS** | Autonomous System — domain administratif tunggal di Internet |
| **BGP** | Border Gateway Protocol — routing antar-AS berbasis kebijakan |
| **eBGP / iBGP** | BGP antar AS (external) / BGP dalam satu AS (internal) |
| **ARP** | Address Resolution Protocol — terjemahkan IP ke MAC address |
| **ARP Cache** | Tabel lokal pemetaan IP→MAC dengan TTL (~15 menit) |
| **ICMP** | Protokol error reporting dan diagnostik pendamping IP |
| **NAT** | Network Address Translation — bagi IP publik untuk banyak host privat |
| **NAT Translation Table** | Tabel pemetaan (private IP, port) ↔ (public IP, port) di router NAT |
| **Private Address** | Blok IP (10/8, 172.16/12, 192.168/16) yang tidak bisa dirutekan di Internet |

---

## Rumus Kunci

```
# Subnetting
Network Address   = IP  AND  Subnet Mask    (bitwise)
Broadcast Address = Network OR inverse(Mask) (semua bit host = 1)
Host Range        = Network+1  hingga  Broadcast-1
Jumlah Subnet     = 2^n        (n = bit dipinjam dari host)
Jumlah Host/Subnet= 2^h - 2    (h = sisa bit host)

# Distance Vector (Bellman-Ford)
D(x, y) = min_v { cost(x, v) + D(v, y) }

# Contoh Subnetting
IP: 128.96.34.15 /25  (mask: 255.255.255.128)
Network:   128.96.34.0
Broadcast: 128.96.34.127
Host range: .1 – .126   → 126 host
```

---

## Checklist Pemahaman

### Sub-materi yang Dibahas
1. Fungsi Network Layer & konsep internetworking
2. Datagram vs Virtual Circuit
3. IP Addressing: classful (A/B/C/D/E) dan CIDR
4. Subnetting: kalkulasi lengkap
5. IP Packet Header: semua field + fragmentasi
6. Forwarding vs Routing, routing table, longest prefix match
7. Distance Vector: Bellman-Ford, count-to-infinity, split horizon, poison reverse, RIP
8. Link State: Dijkstra, LSA flooding, OSPF
9. Perbandingan DV vs LS
10. BGP: AS, inter-AS vs intra-AS, eBGP vs iBGP
11. ARP: request broadcast, reply unicast, ARP cache
12. ICMP: echo (ping), destination unreachable, time exceeded (traceroute)
13. NAT: translation table, cara kerja, keterbatasan

### Prioritas Belajar

🔴 **Wajib dikuasai:**
- Subnetting: hitung Network, Broadcast, Range, jumlah subnet (2^n), jumlah host (2^h−2) — **hampir pasti keluar**
- IP header field dan fungsinya, terutama TTL, Protocol, Fragmentation fields
- Longest Prefix Matching: cara memilih entri tabel
- Perbedaan fundamental DV vs LS (info yang dibagi, konvergensi, robustness)
- Count-to-infinity: penyebab + solusi split horizon dan poison reverse
- ARP: cara kerja request/reply, mengapa diperlukan
- ICMP: Type 8/0 (ping) dan Type 11 (traceroute)
- NAT: cara kerja translation table, motivasi

🟡 **Cukup paham konsep:**
- Datagram vs Virtual Circuit: bisa beda keduanya, contoh protokol
- Classful addressing: range tiap kelas (A/B/C/D/E)
- CIDR: memahami notasi /x dan makna prefix length
- Dijkstra: tahu cara kerjanya step-by-step, tidak perlu hafal notasi formal
- Bellman-Ford: tahu formula `D(x,y) = min { c(x,v) + D(v,y) }`
- BGP: tahu fungsi (inter-AS), tahu eBGP vs iBGP, tidak perlu detail implementasi
- OSPF: tahu fitur hierarki area
- Fragmentasi IP: tahu Identification/Flags/Offset dipakai untuk apa
- Keterbatasan NAT

✅ **Sudah dikuasai:**
- Physical Layer (seluruh materi)
- Data Link Layer (seluruh materi)

