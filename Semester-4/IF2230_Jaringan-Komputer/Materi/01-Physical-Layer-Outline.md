## 1. Physical Layer

### Hubungan dengan CPMK
> **CPMK1**: Menyebutkan struktur tipikal layer arsitektur network.
> *Physical Layer* merupakan lapisan terbawah (Layer 1) dalam arsitektur jaringan yang mendasari seluruh komunikasi data. Lapisan ini menjadi pondasi bagi layer-layer di atasnya dengan berfokus pada pengiriman bit mentah melintasi media fisik, mengubah data digital perangkat menjadi sinyal energi (analog atau digital) yang relevan untuk ditransmisikan.

---

### Outline Konsep Fundamental
- Sistem Transmisi dan Konsep Sinyal (Analog vs Digital)
- Keterbatasan Fisik Saluran Jaringan (Bandwidth, Noise)
- Pengkodean Data (Encoding)
- Media Transmisi (Guided vs Unguided)
- Metrik Kinerja Jaringan (Performance)

---

### Penjelasan Materi

#### Sistem Transmisi dan Sinyal
**TL;DR:** *Data yang tersimpan di perangkat harus diubah menjadi energi fisik (sinyal) agar dapat merambat melalui media transmisi dari pengirim ke penerima.*

Sebuah sistem transmisi secara fundamental dibangun dari tiga komponen utama: *Transmitter* (pengirim), *Transmission Medium* (media), dan *Receiver* (penerima). Baik data yang akan dikirim maupun bentuk rambatan energinya dapat diklasifikasikan ke dalam dua sifat dasar: analog dan digital. Sinyal analog berupa gelombang kontinu dengan rentang nilai yang tak terhingga (misalnya gelombang sinus murni), sementara sinyal digital merepresentasikan data dalam bentuk pulsa diskret dengan tingkatan nilai terbatas. Sinyal komposit dibentuk dari gabungan banyak gelombang sinus fundamental untuk membawa informasi yang jauh lebih kompleks melintasi jaringan. 

- **Karakteristik Gelombang Sinyal:**
  - **Amplitude**: Kekuatan atau ketinggian puncak gelombang elektromagnetik.
  - **Frequency**: Laju kecepatan perubahan siklus gelombang terhadap waktu (diukur dalam Hz).
  - **Phase**: Derajat pergeseran waktu awal dari posisi gelombang tersebut.
- **Faktor Pembatas Transmisi (*Data Rate Limits*):**
  - Lebar pita frekuensi saluran (*bandwidth*)
  - Tingkat level (kekuatan) sinyal yang digunakan
  - Tingkat gangguan/kualitas kebersihan saluran dari *noise*

#### Encoding (Pengkodean Data)
**TL;DR:** *Rangkaian hierarkis pemetaan data menjadi sinyal agar sesuai, efisien, dan andal ketika ditransmisikan melintasi medium kabel atau udara.*

Proses pengkodean (*encoding*) dan modulasi merupakan tahapan penerjemahan aliran bit (0 dan 1) menjadi pulsa energi yang dapat disalurkan secara fisik. Karena kabel atau udara hanya mengerti besaran tegangan dan cahaya, diperlukan mekanisme penerjemahan agar struktur data biner tidak rusak selama perjalanan akibat redaman. Terdapat tiga tingkatan utama pengkodean dalam komunikasi, di mana masing-masing menyasar efisiensi ruang, ketahanan dari *noise*, hingga sinkronisasi pewaktuan transmisi (*bit timing*) agar pengirim dan penerima memiliki detak metronom komputasi yang seragam.

- **Tahapan Fungsional Pengkodean:**
  - **Source Coding:** Berfungsi mengompresi pesan mentah dengan membuang redundansi untuk menghemat penggunaan kapasitas *bandwidth*.
  - **Channel Coding:** Berfungsi sebaliknya; dengan sengaja menyisipkan bit tambahan agar *receiver* dapat mendeteksi atau bahkan mengoreksi kesalahan (*error-correction*) yang diakibatkan oleh *noise* di jalan.
  - **Line Coding:** Berfungsi secara langsung memetakan blok bit menjadi bentuk sinyal tegangan (*voltage*) yang disesuaikan dengan kelistrikan kabel fisik.
- **Jenis/Klasifikasi *Line Coding* Dasar:**
  - **Unipolar NRZ:** Bit 1 dipetakan sebagai tegangan positif, bit 0 nol voltase. Sederhana namun boros daya.
  - **Polar NRZ:** Bit 1 dipetakan menjadi tegangan +A/2, dan bit 0 menjadi -A/2.
  - **Bipolar:** Memanfaatkan 3 tingkatan voltase (positif, negatif, nol). Bit 1 selalu mengubah kutub sebelumnya secara bolak-balik, efektif mencegah arus tumpukan (DC) berlebih pada sirkuit kabel.
  - **Manchester:** Nilai bit ditandai dengan transisi tegangan persis di tengah waktu (*1 = turun, 0 = naik*). Sangat andal menjaga sinkronisasi, banyak digunakan secara fundamental pada jaringan Ethernet LAN.

#### Transmission Media (Media Transmisi)
**TL;DR:** *Jalur fisik aktual yang menghubungkan transmitter dan receiver untuk merambatkan sinyal kelistrikan, cahaya, maupun gelombang radio.*

Media transmisi bertindak sebagai jalan raya fisik tempat komunikasi mengalir. Karakteristik dari media ini—berupa struktur material fisik dan kemampuannya menahan hambatan elektromagnetik—secara langsung mendikte seberapa jauh jarak rentang koneksi serta batas kecepatan puncaknya. Pemilihan media ini dalam arsitektur LAN/WAN sangat bergantung pada kebutuhan kapasitas rasio anggaran, skalabilitas area, serta kondisi *noise* di lokasi instalasi.

- **Klasifikasi Media Transmisi Utama:**
  - **Guided Media (Media Terpandu/Berkabel):** Sinyal terkurung di dalam sebuah selubung kabel fisik secara solid menuju penerima.
    - *Twisted Pair:* Menggunakan dua kawat tembaga yang saling dipilin rapat guna membatalkan interferensi elektromagnetik silang. Relatif murah dan mendominasi arsitektur dasar LAN (misal: kabel UTP).
    - *Coaxial Cable:* Kabel dengan konduktor padat di inti (tertutup lapisan isolator pelindung kuat). Kebal *noise*, ideal untuk transmisi *broadband* hingga jarak jauh.
    - *Optical Fiber:* Kaca silika murni yang menyalurkan sinyal berwujud kedipan cahaya laser/LED. Memiliki *bandwidth* ekstrem dan redaman kerugian yang sangat minim.
      - **Multimode Fiber:** Jalur kaca tebal di mana gelombang memantul berulang, difokuskan untuk LAN lokal dan jarak pendek.
      - **Single-mode Fiber:** Jalur kaca sangat tipis dan lurus secara laser untuk *backbone* jarak yang sangat jauh antar kota/negara.
  - **Unguided Media (Nirkabel/Wireless):** Gelombang transmisi dipancarkan melintasi udara bebas atau ruang hampa tanpa memerlukan kabel.
    - Meliputi *Radiowaves* (radio pemancar luasan), *Microwaves* (parabola *line-of-sight*), dan frekuensi *Infrared* (jarak dekat hampa rintangan).

#### Kinerja Jaringan (Network Performance)
**TL;DR:** *Matriks pengukuran kuantitatif untuk mengevaluasi seberapa banyak dan seberapa cepat aliran paket data bergerak melintasi tautan fisik aktual.*

Evaluasi di Layer 1 bukan sekadar soal kabel tersambung atau terputus, melainkan membutuhkan pengukuran analitis dari performa kapasitas. Arsitek jaringan menggunakan beberapa metrik absolut untuk mengevaluasi batasan maksimal vs pengiriman nyata, diiringi penghitungan total rintangan hambatan waktu (keterlambatan) yang akan dirasakan suatu pesan sejak bit pertama diinjeksi ke pengirim hingga bit terakhir utuh tertampung di penerima.

- **Matriks Metrik Kinerja:**
  - **Bandwidth (Digital):** Kapasitas ambang batas maksimal sebuah media/kanal diukur dalam satuan bit per detik (bps).
  - **Throughput:** Jumlah ukuran laju bit nyata/aktual yang berhasil lewat dengan mulus dalam kondisi praktis sehari-hari (nilainya lazim di bawah nilai *Bandwidth*).
  - **Latency (Delay Jaringan):** Jeda total keterlambatan dari suatu siklus paket komunikasi, dihitung dari jumlah gabungan elemen berikut:
    - *Propagation time:* Waktu rambat fisik impuls sinyal melintasi material kabel.
    - *Transmission time:* Waktu *hardware* memasukkan (*push*) ukuran jumlah bit secara keseluruhan masuk ke saluran.
    - *Processing & Queueing time:* Waktu rute proses *switch* di setiap persimpangan dan antrean trafik sibuk.

---

### Komponen Kunci
- **Bit Rate**: Laju intensitas volume bit yang sukses berjalan dalam setiap detiknya (bps).
- **Bit Duration**: Waktu dalam detak detik yang dihabiskan *transmitter* untuk menekan masuk tepat 1 bit.
- **Bit Length**: Panjang fisik riil di dalam kabel (dalam hitungan meter/centimeter) yang memakan tempat untuk sebuah gelombang bit.
- **Nyquist Rate**: Formulasi teori fisika klasik yang menunjukkan kapasitas transmisi paling optimal sebuah saluran saat tidak terdapat cacat/gangguan *noise* sama sekali.
- **Bandwidth (Analog)**: Karakteristik selisih lebar dari kurva frekuensi yang bisa dilewatkan saluran tersebut tanpa distorsi (Hz).

---

### Checklist Pemahaman

1. **List sub-materi:**
   - Sistem Transmisi dan Sinyal
   - Encoding (Pengkodean Data)
   - Transmission Media (Media Transmisi)
   - Kinerja Jaringan (Network Performance)

2. **Prioritas belajar:**
   - 🔴 *Wajib dikuasai* 
     - Perbedaan esensial dari arti konsep Bandwidth, Throughput, dan perhitungan Latency (Delay).
     - Karakteristik dan keunggulan praktikal tiap Guided Media (Kabel UTP vs Kabel Fiber Optik).
     - Pemahaman fungsional dari prinsip dasar *Line Coding* (khususnya mengapa Manchester Encoding digunakan).
   - 🟡 *Cukup paham konsep* 
     - Perbedaan antara laju Bit (*Bit Rate*) dan frekuensi (Baud/Hz).
     - Pembagian fungsional dari *Source Coding* vs *Channel Coding* untuk menghadapi persoalan ruang dan *noise*.
     - Terminologi batas Nyquist dalam kapasitas fisika.
