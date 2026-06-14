# Physical Layer

## Hubungan dengan CPMK

> **CPMK1** — Physical Layer adalah Layer 1 dalam arsitektur OSI/TCP-IP, sehingga memahaminya secara langsung membangun pemahaman struktur tipikal layer jaringan secara keseluruhan.
>
> **CPMK2** *(sedikit terkait)* — Konsep shared medium dan unguided transmission di Physical Layer menjadi prasyarat untuk memahami medium access di layer atas (MAC/Data Link Layer).

---

## Outline Konsep Fundamental

- **Physical Layer**
  - Definisi & Fungsi
    - Peran dalam OSI (Layer 1) dan TCP/IP
    - Konversi bit ↔ sinyal fisik
  - Medium Transmisi
    - Guided (berkabel)
      - Twisted Pair (UTP/STP)
      - Coaxial Cable
      - Fiber Optic (Multimode / Single-mode)
    - Unguided (nirkabel)
      - Radio Transmission (berdasarkan pita frekuensi)
  - Representasi Sinyal
    - Encoding / Line Coding (NRZ, Manchester, Bipolar)
    - Bandwidth (Analog: Hz / Digital: bps)
    - Throughput vs Bandwidth
  - Performa Transmisi
    - Latency & komponennya (Propagation Delay, Transmission Delay)
    - Bandwidth-Delay Product
  - Perangkat Physical Layer
    - Repeater & Hub
  - Modulasi & Multiplexing
    - Modulasi (carrier frequency)
    - Multiplexing pada medium bersama

---

## Penjelasan Materi

### Definisi dan Fungsi Physical Layer

**TL;DR:** *Physical Layer adalah lapisan paling bawah yang bertanggung jawab mengubah bit digital menjadi sinyal fisik untuk ditransmisikan melalui medium.*

Physical Layer (Layer 1 dalam OSI, bagian dari Network Interface dalam TCP/IP) mendefinisikan seluruh spesifikasi **elektrikal, mekanikal, prosedural, dan fungsional** yang diperlukan untuk mengaktivasi, mengelola, dan menonaktifkan sambungan fisik antar sistem. Layer ini tidak mengenal konsep alamat, paket, atau koneksi logis — ia hanya berurusan dengan raw bits dan bagaimana bit tersebut direpresentasikan sebagai sinyal yang dapat merambat melalui medium.

- **Fungsi utama:** konversi Data → Sinyal (analog atau digital)
- **Yang diatur oleh Physical Layer:**
  - Level tegangan dan timing sinyal
  - Data rate fisik (seberapa cepat bit dikirim)
  - Jarak transmisi maksimum
  - Jenis konektor dan antarmuka fisik

---

### Medium Transmisi Guided (Berkabel)

**TL;DR:** *Medium guided menggunakan konduktor fisik untuk memandu sinyal dari pengirim ke penerima, dengan trade-off antara biaya, bandwidth, dan jarak.*

Medium guided adalah jalur transmisi di mana sinyal dikurung dan diarahkan melalui konduktor fisik. Pemilihan jenis medium bergantung pada kebutuhan bandwidth, jarak, ketahanan terhadap interferensi, dan anggaran.

- **Twisted Pair**
  - Dua kawat tembaga berisolasi yang dipilin spiral untuk meminimalkan interferensi elektromagnetik
  - Jenis: **UTP** (Unshielded, Cat3/Cat5) dan **STP** (Shielded)
  - Keunggulan: murah, umum digunakan (LAN Ethernet, telepon)
  - Kelemahan: atenuasi meningkat pada frekuensi tinggi, jarak terbatas

- **Coaxial Cable**
  - Konduktor dalam + lapisan isolasi + konduktor luar (anyaman) + jaket luar
  - Bandwidth lebih besar dari twisted pair (hingga ratusan MHz)
  - Keunggulan: sangat imun terhadap interferensi
  - Penggunaan: kabel TV, Ethernet generasi awal

- **Fiber Optic**
  - Mengirimkan pulsa cahaya melalui inti kaca tipis (prinsip: *total internal reflection*)
  - Jenis:
    - **Multimode** — inti lebih tebal, jarak pendek, ada dispersi modal
    - **Single-mode** — inti sangat tipis, hanya satu jalur cahaya, mendukung >40 Gbps dan >1000 km
  - Keunggulan: kecepatan sangat tinggi, jarak sangat jauh, imun noise, sulit disadap
  - Kelemahan: mahal, rapuh jika ditekuk, sulit disambung

---

### Medium Transmisi Unguided (Nirkabel)

**TL;DR:** *Medium unguided menggunakan gelombang elektromagnetik yang merambat bebas di udara, dengan karakteristik propagasi yang bergantung pada pita frekuensi.*

Tidak seperti guided media, unguided media tidak memiliki konduktor fisik — sinyal merambat melalui ruang hampa atau udara. Karakteristik propagasi sangat bervariasi tergantung frekuensi:

- **Berdasarkan pita frekuensi:**
  - **VLF, LF, MF** — merambat sebagai *ground wave*, mengikuti kelengkungan bumi
  - **HF** — memantul pada lapisan ionosfer (*sky wave*)
  - **VHF ke atas** — propagasi garis lurus (*line-of-sight*)
- **Keunggulan:** mobilitas, tidak perlu infrastruktur kabel
- **Kelemahan:** rentan interferensi, jangkauan terbatas, keamanan lebih rendah

---

### Encoding Sinyal dan Bandwidth

**TL;DR:** *Line coding mengubah bit biner menjadi bentuk sinyal yang dapat ditransmisikan, sementara bandwidth menentukan kapasitas maksimum saluran.*

Encoding sinyal (*line coding*) adalah proses pemetaan bit "1" dan "0" menjadi level sinyal fisik yang dapat direpresentasikan pada medium. Pemilihan teknik encoding memengaruhi sinkronisasi clock, efisiensi bandwidth, dan kemampuan deteksi error.

- **Teknik line coding:**
  - **Unipolar NRZ** — "1" = tegangan positif, "0" = nol volt
  - **Polar NRZ** — dua level tegangan (+V dan −V)
  - **Bipolar** — "1" bergantian antara +V dan −V, menjaga rata-rata daya = 0
  - **Manchester** — setiap bit dikodekan sebagai transisi di tengah interval; memudahkan pemulihan clock, namun membutuhkan **2× bandwidth**

- **Bandwidth:**
  - **Analog (Hz)** — lebar rentang frekuensi yang dapat dilewatkan medium
  - **Digital (bps)** — kecepatan transmisi bit maksimum teoritis pada sebuah link
  - **Throughput** — laju bit nyata yang terukur, selalu ≤ bandwidth teoritis

---

### Latency dan Delay

**TL;DR:** *Latency adalah total waktu tempuh data dari pengirim ke penerima, yang terdiri dari beberapa komponen delay yang berbeda penyebabnya.*

Latency merupakan metrik fundamental dalam mengevaluasi performa jaringan. Memahami komponen-komponennya penting untuk mendiagnosis bottleneck di level fisik.

- **Komponen latency:**
  - **Propagation Delay** — waktu sinyal merambat secara fisik melalui medium dari satu titik ke titik lain (tergantung jarak dan kecepatan rambat medium)
  - **Transmission Delay** — waktu yang dibutuhkan untuk "memompa" seluruh bit ke dalam medium = *Ukuran data / Bandwidth*
  - *(Queue delay dan processing delay terjadi di layer atas)*

- **Bandwidth-Delay Product (BDP)**
  - Rumus: *BDP = Bandwidth × Propagation Delay*
  - Makna: volume kapasitas "pipa" transmisi — seberapa banyak bit yang sedang *in transit* dalam medium pada satu waktu
  - Penting untuk memahami efisiensi penggunaan link

---

### Perangkat Physical Layer

**TL;DR:** *Repeater dan Hub adalah perangkat Physical Layer yang meregenerasi sinyal fisik tanpa memahami alamat atau protokol.*

- **Repeater** — meregenerasi sinyal digital yang melemah agar dapat ditransmisikan lebih jauh tanpa kehilangan integritas
- **Hub** — repeater multi-port; sinyal yang diterima pada satu port diteruskan ke semua port lainnya (broadcast pada level fisik)
- **Karakteristik:** tidak memahami alamat MAC maupun IP; hanya berurusan dengan sinyal fisik mentah
- **Perangkat lain di Layer 1:** kabel, konektor, NIC (bagian transmit/receive)

---

### Modulasi dan Multiplexing

**TL;DR:** *Modulasi menggeser sinyal ke frekuensi carrier agar dapat ditransmisikan pada medium bersama, sementara multiplexing memungkinkan berbagi kapasitas medium oleh banyak pengirim.*

Modulasi adalah proses mengubah sinyal baseband (dari encoding) menjadi sinyal yang digeser ke **frekuensi carrier** tertentu, agar dapat memanfaatkan alokasi spektrum frekuensi yang telah ditetapkan. Demodulasi dilakukan di sisi penerima untuk memulihkan sinyal asli.

- **Multiplexing pada Physical Layer:**
  - Memungkinkan satu medium fisik digunakan oleh beberapa saluran secara bersamaan
  - Contoh pada fiber optik: **WDM (Wavelength Division Multiplexing)** — beberapa panjang gelombang cahaya berbeda ditransmisikan secara simultan pada satu serat

---

## Komponen Kunci

| Istilah | Definisi Singkat |
|---|---|
| **Physical Layer** | Layer 1 OSI; mengubah bit menjadi sinyal fisik |
| **Guided Media** | Medium berkabel yang mengarahkan sinyal (twisted pair, coaxial, fiber) |
| **Unguided Media** | Medium nirkabel; sinyal merambat bebas di udara |
| **UTP / STP** | Unshielded / Shielded Twisted Pair |
| **Total Internal Reflection** | Prinsip fisika yang menjaga cahaya tetap di dalam inti fiber optik |
| **Line Coding** | Pemetaan bit biner ke bentuk sinyal fisik |
| **Manchester Encoding** | Encoding dengan transisi di tengah bit-interval; clock recovery mudah |
| **Bandwidth (digital)** | Kapasitas maksimum link dalam bps |
| **Throughput** | Laju bit nyata yang terukur (≤ bandwidth) |
| **Propagation Delay** | Waktu rambat sinyal fisik melalui medium |
| **Transmission Delay** | Waktu memompa seluruh bit ke medium = size / bandwidth |
| **Bandwidth-Delay Product** | Volume "pipa" transmisi = bandwidth × propagation delay |
| **Repeater / Hub** | Perangkat Physical Layer; meregenerasi sinyal tanpa memahami alamat |
| **Modulasi** | Penggeseran sinyal ke frekuensi carrier untuk transmisi |
| **WDM** | Wavelength Division Multiplexing; berbagi fiber optik dengan panjang gelombang berbeda |

---

## Encoding di Physical Layer

### Pipeline Lengkap: Dari Data ke Sinyal

Sebelum detail masing-masing, pahami dulu **posisi setiap konsep dalam alur transmisi**:

```
[Data Asli]
     ↓
 Source Coding       ← Kompresi (buang redundansi)
     ↓
 Channel Coding      ← Tambah bit pelindung (error detection/correction)
     ↓
 Line Coding         ← Ubah bit → sinyal digital (untuk kabel)
     ↓  atau
 Modulation          ← Ubah bit → gelombang analog (untuk wireless/jarak jauh)
     ↓
[Sinyal Fisik di Medium]
     ↓
 Demodulation / Line Decoding
     ↓
 Channel Decoding
     ↓
 Source Decoding
     ↓
[Data Asli Diterima]
```

---

### Source Coding (Kompresi)

**TL;DR:** *Buang redundansi dari data agar lebih ringkas sebelum dikirim.*

Source coding adalah kompresi — mengubah data mentah menjadi representasi yang lebih pendek dengan menghilangkan informasi berulang atau tidak perlu.

- **Tujuan:** efisiensi — hemat bandwidth dan kapasitas saluran
- **Contoh:**
  - **Huffman coding** — simbol yang sering muncul diberi kode lebih pendek
  - **Run-Length Encoding (RLE)** — `AAABBC` → `3A2B1C`
  - **JPEG** — kompresi gambar (lossy)
  - **MPEG** — kompresi video

> Source coding *membuang* redundansi. Channel coding *menambahkan* redundansi. Keduanya berlawanan arah tapi sama-sama penting.

---

### Channel Coding (Error Detection & Correction)

**TL;DR:** *Tambahkan bit ekstra ke data agar penerima bisa mendeteksi atau memperbaiki error akibat noise.*

Medium fisik selalu mengandung noise. Channel coding menambahkan **bit redundan** secara terstruktur sehingga penerima bisa mengetahui apakah data tiba utuh atau rusak.

**Dua pendekatan:**

- **Error Detection** — mendeteksi kerusakan, lalu minta kirim ulang (*ARQ — Automatic Repeat Request*)
  - Contoh: **Parity bit**, **Checksum**, **CRC (Cyclic Redundancy Check)**
  - Langkah teknis (Parity bit genap):
    1. Hitung jumlah bit `1` dalam data
    2. Tambahkan 1 bit di akhir: `0` jika sudah genap, `1` jika ganjil
    3. Penerima hitung ulang — jika jumlah `1` ganjil → error terdeteksi

- **Error Correction (FEC — Forward Error Correction)** — deteksi *sekaligus* koreksi, tanpa kirim ulang
  - Contoh: **Hamming Code**, **Reed-Solomon**
  - Lebih mahal (bit overhead lebih banyak), tapi cocok untuk link dengan delay tinggi (misal: satelit)

---

### Modulation & Demodulation

**TL;DR:** *Bit dikodekan sebagai perubahan pada gelombang sinus carrier — dipakai untuk wireless dan transmisi jarak jauh.*

Modulasi mengambil sinyal baseband (hasil encoding) dan **menumpangkannya ke gelombang carrier** pada frekuensi tertentu, agar bisa merambat di udara atau kabel jarak jauh.

**Tiga properti gelombang sinus yang bisa dimodifikasi:**

```
V(t) = A · sin(2πf·t + φ)
        ↑         ↑      ↑
   Amplitude  Frequency  Phase
```

| Tipe Modulasi | Yang Diubah | Versi Digital |
|---|---|---|
| **AM** (Amplitude Modulation) | Amplitudo (A) | **ASK** (Amplitude Shift Keying) |
| **FM** (Frequency Modulation) | Frekuensi (f) | **FSK** (Frequency Shift Keying) |
| **PM** (Phase Modulation) | Fase (φ) | **PSK** (Phase Shift Keying) |
| **QAM** | Amplitudo + Fase sekaligus | **QAM** (Quadrature Amplitude Modulation) |

**Cara kerja tiap tipe:**

- **ASK** — `1` = amplitude tinggi, `0` = amplitude rendah (atau nol)
  ```
  1    0    1    1    0
  ~~~  _  ~~~  ~~~  _
  ```

- **FSK** — `1` = frekuensi tinggi, `0` = frekuensi rendah
  ```
  1        0      1
  ~~  ~~~  ~  ~~  ~~
  ```

- **PSK** — `1` = fase 0°, `0` = fase 180° (sinyal terbalik)
  ```
  1       0        1
  ~~~  ~~~(inv)  ~~~
  ```

- **QAM** — gabungan ASK + PSK; setiap *simbol* bisa membawa banyak bit
  - 16-QAM: 4 amplitudo × 4 fase = 16 kombinasi = **4 bit per simbol**
  - 64-QAM: **6 bit per simbol**
  - Digunakan di WiFi, LTE, kabel modern

**Demodulasi** adalah proses kebalikannya di penerima: mengekstrak kembali urutan bit dari sinyal termodulasi yang masuk.

---

### Line Coding

**TL;DR:** *Bit dikodekan langsung sebagai level tegangan diskret pada kabel — tanpa carrier frequency.*

Line coding adalah teknik untuk medium **baseband** (kabel lokal, LAN). Tidak ada carrier wave — bit langsung direpresentasikan sebagai pulsa tegangan.

**Tujuan desain line coding:**
- Sinkronisasi clock (*clock recovery*) — penerima harus tahu kapan satu bit berakhir dan bit berikutnya mulai
- Minimasi daya rata-rata (DC component = 0 ideal)
- Efisiensi bandwidth
- Deteksi error sederhana

#### Tipe-Tipe Line Coding

##### NRZ-L (Non-Return to Zero — Level)

```
Bit:   1    1    0    0    1
       ┌────┐         ┌────
───────┘    └─────────┘
```
- `1` → level tinggi (+V), `0` → level rendah (−V) atau 0
- **Masalah:** deretan `1` atau `0` panjang → tidak ada transisi → penerima kehilangan sinkronisasi clock

##### NRZ-I (Non-Return to Zero — Inverted)

```
Bit:   1    0    0    1    1    0
  ┌────┐              ┌────
──┘    └──────────────┘    └──────
```
- `1` → **transisi** di awal interval (flip level)
- `0` → **tidak ada transisi** (pertahankan level saat ini)
- **Perbaikan:** deretan `1` panjang tetap ada transisi
- **Masalah:** deretan `0` panjang masih bermasalah

##### RZ (Return to Zero)

```
Bit:   1         0         1
      ┌──┐            ┌──┐
──────┘  └────────────┘  └────
```
- `1` → naik ke +V lalu kembali ke 0 di tengah interval
- `0` → tetap 0
- **Keunggulan:** selalu ada transisi untuk bit `1` → clock recovery lebih mudah
- **Kelemahan:** butuh bandwidth 2× karena ada dua transisi per bit

##### Manchester

```
Bit:   0         1         0         1
  ┌────          ┌────      ┌────     ┌────
──┘    └─────────┘    └─────┘    └───┘    └──
       ↑mid       ↑mid      ↑mid      ↑mid
```
- Selalu ada transisi **di tengah** interval bit
- `0` → transisi **naik** (low→high) di tengah
- `1` → transisi **turun** (high→low) di tengah
- **Keunggulan:** clock recovery sempurna, DC-free
- **Kelemahan:** efisiensi 50% — butuh bandwidth **2× NRZ**
- **Digunakan:** Ethernet 10BASE-T

##### Differential Manchester

```
Bit:   1         0         0         1
```
- Selalu ada transisi di **tengah** interval (sama seperti Manchester)
- Perbedaan pada **awal** interval:
  - `0` → **ada transisi** di awal interval
  - `1` → **tidak ada transisi** di awal interval
- **Keunggulan:** tahan terhadap inversi polaritas kabel (kabel terbalik pasang tidak masalah)
- **Digunakan:** Token Ring

##### AMI / Bipolar (Alternate Mark Inversion)

```
Bit:   0    1    0    1    0    0    1
           +V         +V
───────────────────────────────────────
                  -V              -V
       0         0         0    0
```
- Tiga level: `+V`, `0`, `−V`
- `0` → level nol (tidak ada sinyal)
- `1` → bergantian antara **+V dan −V** setiap kali muncul
- **Keunggulan:** rata-rata daya = 0 (DC-free), error detection built-in (dua `+V` berturutan = error)
- **Kelemahan:** deretan `0` panjang tetap bermasalah untuk sinkronisasi

##### 4B/5B

- Setiap **4 bit data** dipetakan ke **5 bit kode** menggunakan tabel pemetaan tetap
- Kode 5-bit dipilih agar tidak ada lebih dari **1 nol di depan** atau **2 nol berturutan di belakang**
- **Efisiensi:** 4/5 = **80%**
- Hasil 5-bit kemudian diproses dengan NRZ-I

**Contoh pemetaan:**
```
Data 4-bit → Kode 5-bit
0000       → 11110
0001       → 01001
0010       → 10100
...
1111       → 11101
```
- **Digunakan:** Fast Ethernet (100BASE-TX), FDDI

##### 8B/10B dan 64B/66B

- Evolusi dari keluarga mB/nB
- **8B/10B:** 8 bit → 10 bit (efisiensi 80%), digunakan di Gigabit Ethernet, USB 3.0, HDMI
- **64B/66B:** 64 bit → 66 bit (efisiensi **97%**), digunakan di 10G/40G/100G Ethernet

---

### Perbedaan Line Coding vs Modulation

| Aspek | Line Coding | Modulation |
|---|---|---|
| **Output sinyal** | Digital (pulsa tegangan kotak) | Analog (gelombang sinus termodulasi) |
| **Carrier wave** | Tidak ada — baseband langsung | Ada — sinyal ditumpang pada carrier |
| **Jarak** | Pendek (butuh repeater) | Jauh (wireless, kabel telepon) |
| **Medium** | Kabel tembaga (LAN) | Udara (WiFi), kabel telepon, fiber |
| **Contoh** | Manchester, NRZ, 4B/5B | QAM, FSK, PSK |

---

### Ringkasan Hierarki Encoding

```
SOURCE CODING      → efisiensi (kompres data)
CHANNEL CODING     → reliabilitas (tambah bit proteksi)
LINE CODING        → kompatibilitas fisik kabel (bit → pulsa)
MODULATION         → jangkauan (bit → gelombang carrier)
```

---

## Rumus dan Konsep Matematis

### 1. Latency dan Turunannya

**Rumus utama:**
```
Latency = Propagation Delay + Transmission Delay + Queue Delay + Processing Delay
```

#### Propagation Delay
Waktu sinyal merambat secara fisik dari pengirim ke penerima melalui medium.
```
Propagation Delay = Distance / Speed
```

| Variabel | Keterangan |
|---|---|
| `Distance` | Panjang medium fisik (meter) |
| `Speed` | Kecepatan rambat sinyal di medium |

Kecepatan rambat referensi:
- Kabel tembaga: ≈ 2.3 × 10⁸ m/s
- Fiber optik: ≈ 2.0 × 10⁸ m/s
- Ruang hampa (wireless): ≈ 3.0 × 10⁸ m/s

#### Transmission Delay
Waktu yang dibutuhkan untuk memasukkan seluruh bit data ke dalam medium.
```
Transmission Delay = Size / Bandwidth
```

| Variabel | Keterangan |
|---|---|
| `Size` | Ukuran data dalam **bits** (ingat: 1 Byte = 8 bits) |
| `Bandwidth` | Kapasitas link (bps) |

#### Bandwidth-Delay Product (BDP)
Volume "pipa" jaringan — jumlah bit yang bisa berada *in-transit* secara bersamaan.
```
BDP = Bandwidth × Propagation Delay    (satuan: bits)
```

**Interpretasi:**
- BDP besar → banyak bit bisa mengalir sebelum ACK kembali → butuh buffer besar
- BDP kecil → link pendek/lambat, mudah diisi penuh

**Contoh lengkap:**
Mengirim file 1 MB lewat link 10 Mbps, jarak 1000 km (kabel tembaga):
```
Propagation Delay  = 1.000.000 m / 2.3×10⁸ m/s  ≈ 4,35 ms
Transmission Delay = (1×10⁶ × 8 bits) / 10×10⁶  = 0,8 s
Latency (total)    ≈ 0,8 s + 4,35 ms             ≈ 804,35 ms

BDP = 10×10⁶ bps × 0,00435 s = 43.500 bits ≈ 43,5 Kb
```

---

### 2. Throughput

Laju data nyata yang berhasil diterima — selalu ≤ bandwidth teoritis.

```
Throughput = TransferSize / TransferTime
```

```
TransferTime = RTT + (TransferSize / Bandwidth)
```

| Variabel | Keterangan |
|---|---|
| `TransferSize` | Ukuran total data yang ditransfer (bits) |
| `TransferTime` | Total waktu transfer dari awal hingga selesai |
| `RTT` | *Round-Trip Time* — waktu sinyal pergi + kembali (2 × Propagation Delay) |
| `Bandwidth` | Kapasitas link (bps) |

**Mengapa Throughput < Bandwidth?**
- Ada RTT (waktu tunggu ACK)
- Overhead header protokol
- Antrian (*queue*) di router/switch
- Retransmisi akibat error

**Contoh:**
Transfer file 1 GB lewat link 1 Gbps dengan RTT = 20 ms:
```
TransferTime = 0,02 s + (8×10⁹ bits / 10⁹ bps) = 0,02 + 8 = 8,02 s
Throughput   = 8×10⁹ bits / 8,02 s              ≈ 997,5 Mbps
```

---

### 3. Bandwidth dan Efisiensi / Utilization

#### Bandwidth Digital
Kapasitas maksimum teoritis sebuah link.
```
Bandwidth (bps) = jumlah bit yang dapat dikirim per detik
```

#### Bandwidth Analog
Lebar rentang frekuensi yang dapat dilewatkan medium.
```
B = f_high − f_low    (satuan: Hz)
```

#### Efisiensi / Utilization Bandwidth
Seberapa besar persentase kapasitas bandwidth yang benar-benar terpakai untuk membawa data berguna.

```
Utilization = Throughput / Bandwidth × 100%
```

atau dalam konteks protokol dengan window/frame:

```
Utilization = (Data yang terkirim per siklus) / (Kapasitas link per siklus) × 100%
```

**Faktor yang menurunkan utilization:**
- Propagation delay tinggi (link panjang) → banyak waktu "nganggur" menunggu ACK
- Frame/paket kecil → overhead header relatif besar
- Error rate tinggi → banyak retransmisi

**Contoh:**
Link 100 Mbps dengan throughput aktual 75 Mbps:
```
Utilization = 75 / 100 × 100% = 75%
```

---

### Ringkasan Rumus

| Rumus | Formula | Satuan |
|---|---|---|
| **Propagation Delay** | `Distance / Speed` | detik |
| **Transmission Delay** | `Size (bits) / Bandwidth (bps)` | detik |
| **Latency** | `Prop. + Trans. + Queue + Proc.` | detik |
| **RTT** | `2 × Propagation Delay` | detik |
| **Throughput** | `TransferSize / TransferTime` | bps |
| **TransferTime** | `RTT + (TransferSize / Bandwidth)` | detik |
| **BDP** | `Bandwidth × Propagation Delay` | bits |
| **Bandwidth analog** | `f_high − f_low` | Hz |
| **Utilization** | `Throughput / Bandwidth × 100%` | % |

---

## Checklist Pemahaman

### Sub-materi yang dibahas

1. Definisi dan Fungsi Physical Layer
2. Medium Transmisi Guided (Twisted Pair, Coaxial, Fiber Optic)
3. Medium Transmisi Unguided (Radio/Wireless)
4. Encoding Sinyal dan Bandwidth
5. Latency dan Delay (Propagation, Transmission, BDP)
6. Perangkat Physical Layer (Repeater, Hub)
7. Modulasi dan Multiplexing

### Prioritas Belajar

- 🔴 *Wajib dikuasai*
  - Fungsi Physical Layer dalam arsitektur OSI/TCP-IP
  - Perbedaan jenis medium transmisi dan karakteristiknya (terutama fiber vs twisted pair)
  - Konsep Propagation Delay vs Transmission Delay
  - Bandwidth-Delay Product dan maknanya
  - Teknik line coding (terutama Manchester)

- 🟡 *Cukup paham konsep*
  - Detail spesifikasi teknis tiap jenis kabel (kategori UTP, jarak maks, dll.)
  - Perbedaan propagasi radio berdasarkan pita frekuensi
  - Perbedaan Multimode vs Single-mode fiber
  - Mekanisme WDM dan multiplexing
