Baik, saya sudah memahami semua dokumen yang diberikan. Saya akan langsung memberikan isi WBS untuk proyek MoneyLaundry (kelompokmu) yang bisa langsung di-copy paste ke Google Docs.

---

## DOKUMEN WORK BREAKDOWN STRUCTURE (WBS)

**Judul Proyek:** MoneyLaundry – Platform Digital Laundry Koin
**Kelas/Kelompok:** K22 / [No. Kelompok]
**Anggota Kelompok:**
- 13524032 / Juan Oloando Simanungkalit
- 13524036 / Edward David Rumahorbo
- 13524044 / Narendra Dharma Wistara M
- 13524100 / Arghawisesa Dwinanda Arham
- 13524108 / Daffa Mutaqin Tetaputra

---

## 1. Model Proses Software Engineering

### a. Model yang Dipilih

Model proses software engineering yang digunakan dalam proyek MoneyLaundry adalah model **Waterfall**. Model Waterfall adalah model pengembangan perangkat lunak yang bersifat linear dan sekuensial, di mana setiap fase harus diselesaikan sepenuhnya sebelum fase berikutnya dimulai. Proses dalam model ini bersifat maju (forward-only), sehingga tidak diperkenankan untuk kembali ke fase sebelumnya setelah fase tersebut selesai.

Berikut merupakan tahapan proses Waterfall yang digunakan:

**Requirements**
Pada proses ini, seluruh kebutuhan proyek dikumpulkan (requirement gathering) dan ditetapkan secara rinci. Business Case yang telah dibuat diterjemahkan menjadi spesifikasi teknis, seperti penentuan fitur MVP, kebutuhan integrasi IoT, sistem pembayaran digital (QRIS/e-wallet), dan antarmuka pengguna.

**Design**
Proses design berfokus pada perancangan hasil dari requirements. Perancangan yang dimaksud meliputi desain UI/UX aplikasi mobile dan web, skema basis data untuk manajemen mesin cuci dan transaksi, serta arsitektur sistem dan infrastruktur cloud beserta jalur komunikasi IoT ke cloud.

**Implementation/Development**
Pada proses ini, kode aplikasi mulai dieksekusi berdasarkan rancangan yang telah dibuat. Tim developer menulis kode program untuk modul frontend (aplikasi pengguna), backend (API, logika bisnis, integrasi payment gateway), dan tim IoT merakit serta memprogram modul hardware (ESP32 + relay + sensor arus).

**Testing**
Setelah pengembangan selesai, proses testing dilakukan untuk memastikan seluruh fitur MVP—termasuk booking mesin, notifikasi real-time, pembayaran digital, dan sistem IoT—berjalan dengan optimal sesuai requirement dan desain yang telah ditetapkan.

**Deployment**
Pada proses ini, aplikasi MoneyLaundry dirilis secara resmi ke server produksi dan modul IoT dipasang ke mesin cuci mitra. Aplikasi yang lolos tahap testing dipindahkan dari lingkungan staging ke lingkungan produksi sehingga siap diakses oleh pengguna.

**Maintenance**
Setelah aplikasi dirilis, pemeliharaan dilakukan secara berkala. Jika ditemukan bug, error, atau penurunan performa setelah perilisan, perbaikan dan optimalisasi akan dilakukan pada tahap ini.

### b. Alasan Pemilihan

Model Waterfall dipilih karena kebutuhan dan spesifikasi proyek MoneyLaundry telah ditetapkan dengan jelas sejak awal melalui Business Case, sehingga tidak diperlukan iterasi berulang. Beberapa alasan tambahan:

- **Ruang lingkup terdefinisi dengan baik:** Fitur utama (booking mesin, notifikasi real-time, pembayaran QRIS/e-wallet, otomasi IoT) sudah ditentukan secara eksplisit sejak tahap inisiasi.
- **Tidak ada iterasi:** Setiap tahapan dikerjakan berurutan, meminimalkan tumpang tindih pekerjaan antar fase dan memudahkan koordinasi tim.
- **Setiap fase menghasilkan deliverable yang jelas:** Setiap fase menghasilkan dokumen atau produk yang menjadi acuan fase berikutnya, mendukung traceability proyek.
- **Manajemen risiko lebih stabil:** Karena scope sudah jelas, risiko perubahan mendadak di tengah proyek dapat diminimalkan.
- **Memudahkan pengawasan proyek:** Setiap fase memiliki milestone terukur sehingga kemajuan dapat dipantau oleh Project Manager dan stakeholder mitra laundry.

---

## 2. Work Breakdown Structure

### a. Deliverables Structure Chart (DSC)

*(Lampirkan diagram pohon/bagan hierarki DSC di sini — lihat deskripsi dekomposisi di bawah untuk strukturnya)*

### b. Dekomposisi Utama WBS

Pendekatan dekomposisi utama WBS proyek MoneyLaundry adalah kombinasi dari **Project Management Process Group** (level 1) dan **Project Phase/SDLC** (level 2 dalam fase Executing).

**Dekomposisi Tingkat Pertama: Project Management Process Group**
Level tertinggi WBS dipecah berdasarkan lima kelompok proses manajemen proyek:
1. Initiating
2. Planning
3. Executing
4. Monitoring and Controlling
5. Closing

**Dekomposisi Tingkat Kedua (dalam fase Executing): SDLC Waterfall**
Tahapan SDLC di dalam fase Executing meliputi:
- Requirements
- Design
- Implementation/Development
- Testing
- Deployment
- Maintenance

### c. Work Breakdown Structure (WBS)

---

**1. Initiating**

1.1 Membangun tim proyek
1.2 Menyusun business case
1.3 Menyusun project charter

---

**2. Planning**

2.1 Menyusun lingkup proyek (project scope statement)
2.2 Menyusun Work Breakdown Structure (WBS)
2.3 Menetapkan alokasi sumber daya manusia
2.4 Menyusun budget plan
2.5 Menyusun risk management plan
2.6 Menyusun quality management plan
&nbsp;&nbsp;&nbsp;&nbsp;2.6.1 Menentukan standar pengujian perangkat lunak
&nbsp;&nbsp;&nbsp;&nbsp;2.6.2 Menetapkan indikator keberhasilan kualitas produk

---

**3. Executing**

3.1 Requirements
&nbsp;&nbsp;&nbsp;&nbsp;3.1.1 Melakukan requirement gathering (analisis kebutuhan fungsional dan non-fungsional)
&nbsp;&nbsp;&nbsp;&nbsp;3.1.2 Menyusun Spesifikasi Kebutuhan Perangkat Lunak (SKPL)
&nbsp;&nbsp;&nbsp;&nbsp;3.1.3 Menetapkan fitur MVP aplikasi dan IoT

3.2 Design
&nbsp;&nbsp;&nbsp;&nbsp;3.2.1 Merancang UI/UX aplikasi mobile dan web
&nbsp;&nbsp;&nbsp;&nbsp;3.2.2 Mendesain skema basis data (status mesin, transaksi, pengguna)
&nbsp;&nbsp;&nbsp;&nbsp;3.2.3 Mendesain arsitektur sistem, API, dan infrastruktur cloud
&nbsp;&nbsp;&nbsp;&nbsp;3.2.4 Mendesain jalur komunikasi IoT ke cloud
&nbsp;&nbsp;&nbsp;&nbsp;3.2.5 Mendefinisikan bahan implementasi perangkat lunak (DPPL)

3.3 Implementation/Development
&nbsp;&nbsp;&nbsp;&nbsp;3.3.1 Implementasi frontend dan backend sistem autentikasi pengguna (registrasi, login, logout)
&nbsp;&nbsp;&nbsp;&nbsp;3.3.2 Implementasi frontend dan backend sistem monitoring ketersediaan mesin cuci secara real-time
&nbsp;&nbsp;&nbsp;&nbsp;3.3.3 Implementasi frontend dan backend sistem booking/reservasi mesin cuci
&nbsp;&nbsp;&nbsp;&nbsp;3.3.4 Implementasi frontend dan backend sistem notifikasi estimasi waktu selesai
&nbsp;&nbsp;&nbsp;&nbsp;3.3.5 Implementasi frontend dan backend sistem pembayaran digital (QRIS dan e-wallet)
&nbsp;&nbsp;&nbsp;&nbsp;3.3.6 Implementasi frontend dan backend sistem pencatatan keuangan dan laporan transaksi otomatis
&nbsp;&nbsp;&nbsp;&nbsp;3.3.7 Implementasi frontend dan backend sistem manajemen operasional untuk pemilik laundry
&nbsp;&nbsp;&nbsp;&nbsp;3.3.8 Perakitan dan pemrograman modul IoT (ESP32 + relay + sensor arus SCT-013)
&nbsp;&nbsp;&nbsp;&nbsp;3.3.9 Implementasi basis data
&nbsp;&nbsp;&nbsp;&nbsp;3.3.10 Integrasi frontend, backend, database, dan IoT
&nbsp;&nbsp;&nbsp;&nbsp;3.3.11 Melakukan staging deployment

3.4 Testing
&nbsp;&nbsp;&nbsp;&nbsp;3.4.1 Melakukan unit testing pada tiap modul
&nbsp;&nbsp;&nbsp;&nbsp;3.4.2 Melakukan integration testing antar modul
&nbsp;&nbsp;&nbsp;&nbsp;3.4.3 Melakukan system testing terhadap seluruh fitur MVP
&nbsp;&nbsp;&nbsp;&nbsp;3.4.4 Melakukan user acceptance testing
&nbsp;&nbsp;&nbsp;&nbsp;3.4.5 Menyusun dokumentasi implementasi dan hasil testing

3.5 Deployment
&nbsp;&nbsp;&nbsp;&nbsp;3.5.1 Melakukan production deployment aplikasi ke server
&nbsp;&nbsp;&nbsp;&nbsp;3.5.2 Instalasi modul IoT ke mesin cuci mitra
&nbsp;&nbsp;&nbsp;&nbsp;3.5.3 Validasi pasca deployment
&nbsp;&nbsp;&nbsp;&nbsp;3.5.4 Melakukan handover aplikasi ke end user dan mitra

3.6 Maintenance
&nbsp;&nbsp;&nbsp;&nbsp;3.6.1 Penanganan bug dan error pasca deployment
&nbsp;&nbsp;&nbsp;&nbsp;3.6.2 Optimalisasi performa dan pembaruan minor

---

**4. Monitoring and Controlling**

4.1 Melakukan evaluasi kualitas hasil pengujian
4.2 Melakukan pengendalian risiko dan perubahan scope jika dibutuhkan
4.3 Melakukan pemantauan kemajuan proyek berdasarkan jadwal dan anggaran
4.4 Menyusun laporan kinerja proyek

---

**5. Closing**

5.1 Dokumentasi hasil akhir proyek
5.2 Penutupan administrasi dan kontrak kepada mitra
5.3 Penyusunan laporan akhir proyek

---

### d. Kamus WBS

---

| No. Task | 1.1 |
|---|---|
| **Nama Task** | Membangun tim proyek |
| **Deskripsi** | Menyusun struktur organisasi dan membagi peran anggota tim proyek MoneyLaundry |
| **Deliverables** | Tim proyek dan struktur organisasi |
| **Sumber Daya** | 1 orang |
| **Durasi** | 4 hari |
| **Task Pendahulu** | - |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 1.2 |
|---|---|
| **Nama Task** | Menyusun business case |
| **Deskripsi** | Menyusun analisis manfaat, biaya, peluang bisnis, dan justifikasi proyek MoneyLaundry |
| **Deliverables** | Dokumen Business Case MoneyLaundry |
| **Sumber Daya** | 5 orang |
| **Durasi** | 19 hari |
| **Task Pendahulu** | 1.1 |
| **Penanggung Jawab** | Project Manager, Semua Anggota |

---

| No. Task | 1.3 |
|---|---|
| **Nama Task** | Menyusun project charter |
| **Deskripsi** | Menetapkan tujuan proyek, deskripsi singkat, dan tanggung jawab masing-masing anggota tim |
| **Deliverables** | Dokumen Project Charter MoneyLaundry |
| **Sumber Daya** | 5 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 1.2 |
| **Penanggung Jawab** | Project Manager, Semua Anggota |

---

| No. Task | 2.1 |
|---|---|
| **Nama Task** | Menyusun lingkup proyek (project scope statement) |
| **Deskripsi** | Mendefinisikan MOV, deskripsi lingkup domain dan SDLC, deliverables, kendala, dan milestone proyek |
| **Deliverables** | Dokumen Project Scope Statement MoneyLaundry |
| **Sumber Daya** | 5 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 1.2, 1.3 |
| **Penanggung Jawab** | Project Manager, Semua Anggota |

---

| No. Task | 2.2 |
|---|---|
| **Nama Task** | Menyusun Work Breakdown Structure (WBS) |
| **Deskripsi** | Menyusun struktur dekomposisi pekerjaan proyek beserta kamus WBS |
| **Deliverables** | Dokumen Work Breakdown Structure MoneyLaundry |
| **Sumber Daya** | 5 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 2.1 |
| **Penanggung Jawab** | Project Manager, Semua Anggota |

---

| No. Task | 2.3 |
|---|---|
| **Nama Task** | Menetapkan alokasi sumber daya manusia |
| **Deskripsi** | Menentukan distribusi peran dan tanggung jawab untuk setiap anggota tim di tiap fase proyek |
| **Deliverables** | Matriks alokasi sumber daya manusia |
| **Sumber Daya** | 1 orang |
| **Durasi** | 3 hari |
| **Task Pendahulu** | 1.3, 2.1 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 2.4 |
|---|---|
| **Nama Task** | Menyusun budget plan |
| **Deskripsi** | Membuat estimasi biaya CAPEX (pengembangan software dan hardware IoT) dan OPEX proyek |
| **Deliverables** | Rencana anggaran proyek |
| **Sumber Daya** | 1 orang |
| **Durasi** | 3 hari |
| **Task Pendahulu** | 1.2, 1.3 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 2.5 |
|---|---|
| **Nama Task** | Menyusun risk management plan |
| **Deskripsi** | Mengidentifikasi risiko proyek (adopsi pengguna, ketergantungan internet, margin mitra) dan merancang rencana penanggulangannya |
| **Deliverables** | Dokumen Risk Management Plan |
| **Sumber Daya** | 1 orang |
| **Durasi** | 3 hari |
| **Task Pendahulu** | 1.2, 2.1 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 2.6 |
|---|---|
| **Nama Task** | Menyusun quality management plan |
| **Deskripsi** | Menentukan standar kualitas, metode pengujian, dan indikator keberhasilan produk MoneyLaundry |
| **Deliverables** | Dokumen Quality Management Plan |
| **Sumber Daya** | 1 orang |
| **Durasi** | 3 hari |
| **Task Pendahulu** | 1.2, 1.3 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 3.1.1 |
|---|---|
| **Nama Task** | Melakukan requirement gathering |
| **Deskripsi** | Mengumpulkan dan menganalisis kebutuhan fungsional dan non-fungsional dari perspektif pelanggan (mahasiswa) dan pemilik laundry, termasuk kebutuhan fitur booking, notifikasi, pembayaran, dan IoT |
| **Deliverables** | Dokumen kebutuhan sistem |
| **Sumber Daya** | 2 orang |
| **Durasi** | 9 hari |
| **Task Pendahulu** | 2.1, 2.2 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 3.1.2 |
|---|---|
| **Nama Task** | Menyusun Spesifikasi Kebutuhan Perangkat Lunak (SKPL) |
| **Deskripsi** | Menerjemahkan hasil requirement gathering menjadi dokumen spesifikasi teknis fungsional dan non-fungsional aplikasi dan IoT |
| **Deliverables** | Dokumen SKPL MoneyLaundry |
| **Sumber Daya** | 2 orang |
| **Durasi** | 7 hari |
| **Task Pendahulu** | 3.1.1 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 3.1.3 |
|---|---|
| **Nama Task** | Menetapkan fitur MVP aplikasi dan IoT |
| **Deskripsi** | Menentukan fitur minimum viable product yang wajib ada pada rilis pertama, mencakup monitoring mesin real-time, booking, notifikasi, dan pembayaran digital |
| **Deliverables** | Dokumen MVP Features MoneyLaundry |
| **Sumber Daya** | 2 orang |
| **Durasi** | 3 hari |
| **Task Pendahulu** | 3.1.1, 3.1.2 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 3.2.1 |
|---|---|
| **Nama Task** | Merancang UI/UX aplikasi mobile dan web |
| **Deskripsi** | Membuat wireframe, mockup, dan high-fidelity prototype interaktif untuk antarmuka pelanggan dan antarmuka pemilik laundry |
| **Deliverables** | Desain UI/UX aplikasi MoneyLaundry |
| **Sumber Daya** | 2 orang |
| **Durasi** | 14 hari |
| **Task Pendahulu** | 3.1.2, 3.1.3 |
| **Penanggung Jawab** | UI/UX Designer, Frontend Developer |

---

| No. Task | 3.2.2 |
|---|---|
| **Nama Task** | Mendesain skema basis data |
| **Deskripsi** | Mendesain ERD dan skema tabel untuk manajemen data mesin cuci, transaksi pembayaran, data pengguna, dan riwayat booking |
| **Deliverables** | Skema basis data dan ERD MoneyLaundry |
| **Sumber Daya** | 1 orang |
| **Durasi** | 14 hari |
| **Task Pendahulu** | 3.1.2, 3.1.3 |
| **Penanggung Jawab** | Backend Developer |

---

| No. Task | 3.2.3 |
|---|---|
| **Nama Task** | Mendesain arsitektur sistem, API, dan infrastruktur cloud |
| **Deskripsi** | Menentukan arsitektur sistem backend, desain REST API, konfigurasi Firebase Blaze sebagai cloud, dan jaringan server yang aman |
| **Deliverables** | Dokumen arsitektur sistem dan infrastruktur server |
| **Sumber Daya** | 1 orang |
| **Durasi** | 14 hari |
| **Task Pendahulu** | 3.1.2, 3.1.3 |
| **Penanggung Jawab** | Backend Developer |

---

| No. Task | 3.2.4 |
|---|---|
| **Nama Task** | Mendesain jalur komunikasi IoT ke cloud |
| **Deskripsi** | Merancang alur komunikasi dari modul IoT (ESP32) di mesin cuci ke server cloud untuk sinkronisasi status mesin secara real-time |
| **Deliverables** | Dokumen desain jalur IoT-cloud |
| **Sumber Daya** | 1 orang |
| **Durasi** | 14 hari |
| **Task Pendahulu** | 3.1.2, 3.1.3 |
| **Penanggung Jawab** | IoT Engineer |

---

| No. Task | 3.2.5 |
|---|---|
| **Nama Task** | Mendefinisikan bahan implementasi perangkat lunak (DPPL) |
| **Deskripsi** | Menyusun dokumen yang menjabarkan detail implementasi seluruh modul perangkat lunak sebagai acuan tim pengembangan |
| **Deliverables** | Dokumen Deskripsi Perancangan Perangkat Lunak (DPPL) |
| **Sumber Daya** | 2 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 3.2.1, 3.2.2, 3.2.3, 3.2.4 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 3.3.1 |
|---|---|
| **Nama Task** | Implementasi sistem autentikasi pengguna |
| **Deskripsi** | Mengembangkan fitur registrasi akun, login, dan logout untuk pelanggan maupun pemilik laundry pada sisi frontend dan backend |
| **Deliverables** | Source code dan modul sistem autentikasi pengguna |
| **Sumber Daya** | 2 orang |
| **Durasi** | 6 hari |
| **Task Pendahulu** | 3.2.5 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer |

---

| No. Task | 3.3.2 |
|---|---|
| **Nama Task** | Implementasi sistem monitoring ketersediaan mesin cuci secara real-time |
| **Deskripsi** | Mengembangkan fitur tampilan status setiap mesin cuci (tersedia/sedang digunakan) secara real-time pada sisi frontend dan backend, terintegrasi dengan data dari IoT |
| **Deliverables** | Source code dan modul sistem monitoring mesin real-time |
| **Sumber Daya** | 2 orang |
| **Durasi** | 7 hari |
| **Task Pendahulu** | 3.3.1 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer |

---

| No. Task | 3.3.3 |
|---|---|
| **Nama Task** | Implementasi sistem booking/reservasi mesin cuci |
| **Deskripsi** | Mengembangkan fitur yang memungkinkan pelanggan melakukan reservasi mesin cuci sebelum tiba di lokasi pada sisi frontend dan backend |
| **Deliverables** | Source code dan modul sistem booking mesin cuci |
| **Sumber Daya** | 2 orang |
| **Durasi** | 7 hari |
| **Task Pendahulu** | 3.3.2 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer |

---

| No. Task | 3.3.4 |
|---|---|
| **Nama Task** | Implementasi sistem notifikasi estimasi waktu selesai |
| **Deskripsi** | Mengembangkan fitur notifikasi otomatis kepada pelanggan mengenai estimasi waktu cucian selesai pada sisi frontend dan backend |
| **Deliverables** | Source code dan modul sistem notifikasi |
| **Sumber Daya** | 2 orang |
| **Durasi** | 7 hari |
| **Task Pendahulu** | 3.3.3 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer |

---

| No. Task | 3.3.5 |
|---|---|
| **Nama Task** | Implementasi sistem pembayaran digital (QRIS dan e-wallet) |
| **Deskripsi** | Mengembangkan fitur pembayaran menggunakan QRIS dan berbagai layanan e-wallet pada sisi frontend dan backend, termasuk integrasi dengan payment gateway |
| **Deliverables** | Source code dan modul sistem pembayaran digital |
| **Sumber Daya** | 2 orang |
| **Durasi** | 7 hari |
| **Task Pendahulu** | 3.3.4 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer |

---

| No. Task | 3.3.6 |
|---|---|
| **Nama Task** | Implementasi sistem pencatatan keuangan dan laporan transaksi otomatis |
| **Deskripsi** | Mengembangkan fitur pencatatan otomatis seluruh transaksi digital dan pembuatan laporan keuangan bagi pemilik laundry pada sisi frontend dan backend |
| **Deliverables** | Source code dan modul sistem pencatatan dan laporan keuangan |
| **Sumber Daya** | 2 orang |
| **Durasi** | 7 hari |
| **Task Pendahulu** | 3.3.5 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer |

---

| No. Task | 3.3.7 |
|---|---|
| **Nama Task** | Implementasi sistem manajemen operasional untuk pemilik laundry |
| **Deskripsi** | Mengembangkan dashboard manajemen yang memungkinkan pemilik memantau operasional mesin, status transaksi, dan statistik penggunaan tanpa harus hadir secara fisik |
| **Deliverables** | Source code dan modul dashboard pemilik laundry |
| **Sumber Daya** | 2 orang |
| **Durasi** | 7 hari |
| **Task Pendahulu** | 3.3.6 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer |

---

| No. Task | 3.3.8 |
|---|---|
| **Nama Task** | Perakitan dan pemrograman modul IoT |
| **Deskripsi** | Merakit modul ESP32 dengan relay 5V dan sensor arus SCT-013, lalu memprogram modul tersebut agar dapat berkomunikasi dengan server cloud untuk mendeteksi ketersediaan dan mengontrol mesin cuci |
| **Deliverables** | Modul IoT yang terpasang dan terprogram (10 unit untuk pilot partner) |
| **Sumber Daya** | 1 orang |
| **Durasi** | 27 hari |
| **Task Pendahulu** | 3.2.4, 3.2.5 |
| **Penanggung Jawab** | IoT Engineer |

---

| No. Task | 3.3.9 |
|---|---|
| **Nama Task** | Implementasi basis data |
| **Deskripsi** | Membangun dan mengkonfigurasi basis data sesuai desain ERD, serta menghubungkannya ke backend |
| **Deliverables** | Database aplikasi MoneyLaundry |
| **Sumber Daya** | 2 orang |
| **Durasi** | 4 hari |
| **Task Pendahulu** | 3.3.7 |
| **Penanggung Jawab** | Backend Developer |

---

| No. Task | 3.3.10 |
|---|---|
| **Nama Task** | Integrasi frontend, backend, database, dan IoT |
| **Deskripsi** | Mengintegrasikan seluruh modul aplikasi (frontend, backend, database) dan sistem IoT agar dapat berfungsi bersama dengan data aktual secara end-to-end |
| **Deliverables** | Aplikasi MoneyLaundry terintegrasi penuh |
| **Sumber Daya** | 4 orang |
| **Durasi** | 3 hari |
| **Task Pendahulu** | 3.3.8, 3.3.9 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer, IoT Engineer |

---

| No. Task | 3.3.11 |
|---|---|
| **Nama Task** | Melakukan staging deployment |
| **Deskripsi** | Melakukan deployment internal ke lingkungan staging untuk uji coba tim sebelum production release |
| **Deliverables** | Versi staging MoneyLaundry |
| **Sumber Daya** | 3 orang |
| **Durasi** | 3 hari |
| **Task Pendahulu** | 3.3.10 |
| **Penanggung Jawab** | Backend Developer, IoT Engineer |

---

| No. Task | 3.4.1 |
|---|---|
| **Nama Task** | Melakukan unit testing pada tiap modul |
| **Deskripsi** | Melakukan pengujian unit terhadap masing-masing modul frontend, backend, dan IoT untuk memastikan logika dan fungsionalitas berjalan sesuai desain |
| **Deliverables** | Laporan hasil unit testing |
| **Sumber Daya** | 1 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 3.3.1 – 3.3.11 |
| **Penanggung Jawab** | QA Engineer |

---

| No. Task | 3.4.2 |
|---|---|
| **Nama Task** | Melakukan integration testing antar modul |
| **Deskripsi** | Menguji integrasi antar modul untuk memastikan tidak ada error dalam komunikasi data antar komponen sistem |
| **Deliverables** | Laporan hasil integration testing |
| **Sumber Daya** | 1 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 3.4.1 |
| **Penanggung Jawab** | QA Engineer |

---

| No. Task | 3.4.3 |
|---|---|
| **Nama Task** | Melakukan system testing terhadap seluruh fitur MVP |
| **Deskripsi** | Melakukan pengujian sistem secara menyeluruh untuk memastikan seluruh fitur MVP (booking, notifikasi, pembayaran, IoT) berjalan sesuai requirement |
| **Deliverables** | Laporan hasil system testing |
| **Sumber Daya** | 1 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 3.4.2 |
| **Penanggung Jawab** | QA Engineer |

---

| No. Task | 3.4.4 |
|---|---|
| **Nama Task** | Melakukan user acceptance testing |
| **Deskripsi** | Mengadakan sesi uji coba dengan pengguna (mahasiswa) dan mitra pemilik laundry untuk memastikan aplikasi sesuai harapan pengguna akhir |
| **Deliverables** | Laporan hasil user acceptance testing |
| **Sumber Daya** | 2 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 3.4.3 |
| **Penanggung Jawab** | QA Engineer, Project Manager |

---

| No. Task | 3.4.5 |
|---|---|
| **Nama Task** | Menyusun dokumentasi implementasi dan hasil testing |
| **Deskripsi** | Menyusun dokumentasi lengkap hasil implementasi seluruh modul, proses testing, dan temuan pengujian sebagai bagian dari pelaporan proyek |
| **Deliverables** | Dokumen implementasi dan testing MoneyLaundry |
| **Sumber Daya** | 2 orang |
| **Durasi** | 5 hari |
| **Task Pendahulu** | 3.4.4 |
| **Penanggung Jawab** | Project Manager, QA Engineer |

---

| No. Task | 3.5.1 |
|---|---|
| **Nama Task** | Melakukan production deployment aplikasi ke server |
| **Deskripsi** | Meluncurkan aplikasi MoneyLaundry secara resmi ke server produksi (Firebase Blaze) agar dapat diakses oleh target pengguna |
| **Deliverables** | Aplikasi MoneyLaundry berjalan di server produksi |
| **Sumber Daya** | 1 orang |
| **Durasi** | 2 hari |
| **Task Pendahulu** | 3.4.1 – 3.4.4 |
| **Penanggung Jawab** | Backend Developer |

---

| No. Task | 3.5.2 |
|---|---|
| **Nama Task** | Instalasi modul IoT ke mesin cuci mitra |
| **Deskripsi** | Memasang modul IoT (ESP32 + relay + sensor SCT-013) pada 10 mesin cuci milik pilot partner dan memastikan koneksi ke server produksi berjalan |
| **Deliverables** | Modul IoT terpasang pada mesin cuci mitra |
| **Sumber Daya** | 1 orang |
| **Durasi** | 2 hari |
| **Task Pendahulu** | 3.5.1 |
| **Penanggung Jawab** | IoT Engineer |

---

| No. Task | 3.5.3 |
|---|---|
| **Nama Task** | Validasi pasca deployment |
| **Deskripsi** | Mengevaluasi performa aplikasi dan sistem IoT di lingkungan produksi, memastikan kestabilan sistem secara end-to-end |
| **Deliverables** | Laporan validasi performa pasca deployment |
| **Sumber Daya** | 2 orang |
| **Durasi** | 2 hari |
| **Task Pendahulu** | 3.5.2 |
| **Penanggung Jawab** | QA Engineer, IoT Engineer |

---

| No. Task | 3.5.4 |
|---|---|
| **Nama Task** | Melakukan handover aplikasi ke end user dan mitra |
| **Deskripsi** | Menyerahkan aplikasi final dan dokumentasi proyek kepada pengguna akhir (mahasiswa dan pemilik laundry mitra) |
| **Deliverables** | Dokumen serah terima sistem MoneyLaundry |
| **Sumber Daya** | 1 orang |
| **Durasi** | 1 hari |
| **Task Pendahulu** | 3.5.3 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 3.6.1 |
|---|---|
| **Nama Task** | Penanganan bug dan error pasca deployment |
| **Deskripsi** | Mengidentifikasi dan memperbaiki bug atau error yang ditemukan oleh pengguna atau tim QA setelah rilis ke produksi |
| **Deliverables** | Patch/perbaikan bug |
| **Sumber Daya** | 3 orang |
| **Durasi** | 3 hari (paralel dengan 3.6.2) |
| **Task Pendahulu** | 3.5.1 – 3.5.4 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer, IoT Engineer |

---

| No. Task | 3.6.2 |
|---|---|
| **Nama Task** | Optimalisasi performa dan pembaruan minor |
| **Deskripsi** | Melakukan optimasi performa sistem (caching, efisiensi query, sinkronisasi IoT) dan pembaruan kecil seperti perbaikan UI/UX minor |
| **Deliverables** | Laporan optimisasi sistem |
| **Sumber Daya** | 3 orang |
| **Durasi** | 3 hari (paralel dengan 3.6.1) |
| **Task Pendahulu** | 3.6.1 |
| **Penanggung Jawab** | Frontend Developer, Backend Developer, IoT Engineer |

---

| No. Task | 4.1 |
|---|---|
| **Nama Task** | Melakukan evaluasi kualitas hasil pengujian |
| **Deskripsi** | Mengevaluasi seluruh hasil pengujian (unit, integrasi, sistem, dan user acceptance testing) untuk memastikan standar kualitas tercapai |
| **Deliverables** | Laporan evaluasi hasil pengujian |
| **Sumber Daya** | 1 orang |
| **Durasi** | Berlangsung sepanjang proyek (laporan per 7 hari) |
| **Task Pendahulu** | 3.4.1 – 3.4.5 |
| **Penanggung Jawab** | QA Engineer |

---

| No. Task | 4.2 |
|---|---|
| **Nama Task** | Melakukan pengendalian risiko dan perubahan scope jika dibutuhkan |
| **Deskripsi** | Memantau dan mengendalikan risiko yang teridentifikasi serta memproses setiap perubahan scope melalui prosedur formal |
| **Deliverables** | Dokumen evaluasi risiko dan perubahan scope |
| **Sumber Daya** | 1 orang |
| **Durasi** | Berlangsung sepanjang proyek (laporan per 7 hari) |
| **Task Pendahulu** | 4.1 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 4.3 |
|---|---|
| **Nama Task** | Melakukan pemantauan kemajuan proyek berdasarkan jadwal dan anggaran |
| **Deskripsi** | Memastikan proyek berjalan sesuai rencana waktu dan biaya dengan memonitor kemajuan tiap tim secara berkala |
| **Deliverables** | Laporan progress proyek |
| **Sumber Daya** | 1 orang |
| **Durasi** | Berlangsung sepanjang proyek (laporan per 7 hari) |
| **Task Pendahulu** | 4.2 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 4.4 |
|---|---|
| **Nama Task** | Menyusun laporan kinerja proyek |
| **Deskripsi** | Mengkompilasi data performa tim, capaian milestone, dan evaluasi waktu serta biaya menjadi laporan kinerja formal |
| **Deliverables** | Laporan kinerja proyek |
| **Sumber Daya** | 1 orang |
| **Durasi** | Berlangsung sepanjang proyek (laporan per 7 hari) |
| **Task Pendahulu** | 4.3 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 5.1 |
|---|---|
| **Nama Task** | Dokumentasi hasil akhir proyek |
| **Deskripsi** | Mengkompilasi seluruh hasil pekerjaan, laporan testing, desain, kode, dan dokumentasi implementasi sebagai arsip proyek |
| **Deliverables** | Dokumen hasil akhir proyek MoneyLaundry |
| **Sumber Daya** | 5 orang |
| **Durasi** | 4 hari |
| **Task Pendahulu** | 4.1 – 4.4 |
| **Penanggung Jawab** | Project Manager, Semua Anggota |

---

| No. Task | 5.2 |
|---|---|
| **Nama Task** | Penutupan administrasi dan kontrak kepada mitra |
| **Deskripsi** | Menyelesaikan seluruh administrasi proyek termasuk kontrak dengan mitra laundry, laporan keuangan akhir, dan penutupan sumber daya proyek |
| **Deliverables** | Dokumen penutupan proyek dan kontrak |
| **Sumber Daya** | 1 orang |
| **Durasi** | 2 hari |
| **Task Pendahulu** | 5.1 |
| **Penanggung Jawab** | Project Manager |

---

| No. Task | 5.3 |
|---|---|
| **Nama Task** | Penyusunan laporan akhir proyek |
| **Deskripsi** | Menyusun laporan akhir proyek MoneyLaundry yang berisi capaian, kendala yang dihadapi, rekomendasi, dan pembelajaran selama proyek berlangsung |
| **Deliverables** | Laporan akhir proyek MoneyLaundry |
| **Sumber Daya** | 5 orang |
| **Durasi** | 4 hari |
| **Task Pendahulu** | 5.2 |
| **Penanggung Jawab** | Project Manager, Semua Anggota |

---

Beberapa catatan penting untuk pengerjaan selanjutnya:

**DSC (Deliverables Structure Chart):** Kamu perlu membuat diagram pohon berdasarkan struktur WBS di atas. Gunakan tools seperti draw.io, Lucidchart, atau Figma untuk membuatnya, lalu embed ke dokumen Google Docs.

**Nomor kelompok:** Lengkapi nomor kelompok di bagian header dokumen.

**Konsistensi dengan Business Case:** Durasi dan PIC sudah disesuaikan dengan Gantt Chart yang ada di Business Case kalian (proyek berjalan ~3 bulan, Maret–Juni 2026), tapi kamu bisa menyesuaikan lebih lanjut jika ada perubahan.
