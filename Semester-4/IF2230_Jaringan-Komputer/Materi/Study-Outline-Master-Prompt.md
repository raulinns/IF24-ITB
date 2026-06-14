# Master Prompt: Outline Pembelajaran Teknis & Akademis

Dokumen ini berisi template prompt yang dapat digunakan untuk menghasilkan outline pembelajaran berkualitas tinggi dengan struktur yang mendalam, akademis, dan teknis.

---

## Cara Penggunaan
1. Copy seluruh teks di dalam blok **Template Prompt** di bawah ini.
2. Ganti bagian di dalam kurung siku `[...]` dengan informasi yang sesuai.
3. Masukkan ke dalam chat AI (ChatGPT, Gemini, atau NotebookLM).

---

## Template Prompt

```markdown
# Role & Context
Bertindaklah sebagai Senior Subject Matter Expert (SME) dan Pendidik Akademis di bidang [MATA_KULIAH]. Bantu saya menyusun outline pembelajaran yang sangat mendalam untuk persiapan ujian materi [MATERI_SEKARANG].

# Tujuan Pembelajaran (CPMK)
Gunakan daftar Capaian Pembelajaran Mata Kuliah (CPMK) berikut sebagai panduan relevansi materi:
[DAFTAR_CPMK_ATAU_TUJUAN_KULIAH]

# Status Penguasaan
Materi yang sudah saya kuasai adalah: [MATERI_YANG_SUDAH_DIKUASAI].
(Jika sub-topik ini muncul dalam outline, sajikan secara sangat ringkas dan tandai dengan ceklis ✅).

# Instruksi Struktur Output
Susunlah penjelasan berdasarkan sumber [SUMBER_MATERI_ATAU_DOKUMEN] dengan format berikut secara ketat:

## 1. [Nama Materi]

### Hubungan dengan CPMK
> Jelaskan secara singkat dan poin-per-poin bagaimana materi ini berkontribusi langsung pada pencapaian CPMK yang relevan.

---

### Outline Konsep Fundamental
Tampilkan peta konsep dalam bentuk hierarki bullet point (nested list) untuk memberikan gambaran besar (big picture) sebelum masuk ke detail.

---

### Penjelasan Materi Detail
Untuk setiap sub-topik dalam materi ini, gunakan struktur:
#### [Nama Sub-topik]
**TL;DR:** *[Satu kalimat miring yang merangkum inti teknis/logika dari sub-topik ini]*

[Paragraf Narasi Akademis: Jelaskan definisi, filosofi/latar belakang, dan urgensi konsep ini dalam sistem yang lebih besar.]

[Hierarki Teks Berpoin: Jelaskan aspek teknis, langkah-langkah prosedural, klasifikasi, atau aturan kerja secara mendetail. Gunakan TABEL jika ada perbandingan antar elemen.]

---

### Komponen Kunci (Glossary)
Sajikan dalam tabel Markdown:
| Istilah | Definisi Teknis & Fungsi |
|---|---|

---

### Rumus, Logika, atau Algoritma (Jika Ada)
Sajikan rumus matematis, pseudocode, atau urutan algoritma dalam blok kode (code block) agar terlihat profesional dan mudah dipelajari.

---

### Checklist Pemahaman & Strategi
1. **Daftar Sub-materi**: List apa saja yang baru dibahas.
2. **Prioritas Belajar**:
   - 🔴 **Wajib dikuasai**: Konsep inti yang kompleks atau sering keluar di ujian.
   - 🟡 **Cukup paham konsep**: Materi pendukung atau klasifikasi.
   - ✅ **Sudah dikuasai**: Materi yang ditandai di awal instruksi.

# Catatan Tambahan
- Gunakan terminologi standar industri/akademis (bahasa Inggris) jika tidak ada padanan kata yang tepat dalam bahasa Indonesia.
- Jangan melakukan penyederhanaan yang berlebihan; saya membutuhkan detail teknis yang cukup untuk level mahasiswa.

Silakan mulai dengan materi: [MATERI_SEKARANG]

| `[MATA_KULIAH]`     |
| ------------------- |
| `[MATERI_SEKARANG]` = Data Link Layer |
| `[DAFTAR_CPMK]` = CPMK1: Menyebutkan struktur tipikal layer arsitektur network
CPMK2: Menjelaskan prinsip dasar medium access layer
CPMK3: Menjelaskan prinsip switched networks dan reliable message delivery
CPMK4: Menjelaskan prinsip routing dan packet forwarding pada jaringan IP
CPMK5: Mengkonfigurasi LAN dan jaringan IP
CPMK6: Mengimplementasikan aplikasi jaringan / aplikasi client-server sederhana|
| `[MATERI_DIKUASAI]` = Introduction to Computer Networks, Layer and Protocols, Physical Layer |
| `[SUMBER_MATERI]` = [https://notebooklm.google.com/notebook/9822036f-c269-4d48-9c18-a2a64e1efcda  |](https://notebooklm.google.com/notebook/7182a91c-3bcd-465c-b3f6-ab64af18877d)
```

---

## Penjelasan Variabel

| Variabel            | Deskripsi                                        | Contoh                                          |
| ------------------- | ------------------------------------------------ | ----------------------------------------------- |
| `[MATA_KULIAH]`     | Nama mata kuliah yang sedang dipelajari.         | Jaringan Komputer, Sistem Operasi, Kalkulus.    |
| `[MATERI_SEKARANG]` | Nama bab atau topik spesifik yang ingin diulas.  | Internetworking Bridging and Switching.         |
| `[DAFTAR_CPMK]`     | Poin-poin capaian pembelajaran dari silabus.     | CPMK1: Menjelaskan arsitektur jaringan...       |
| `[MATERI_DIKUASAI]` | Daftar topik yang sudah Anda pahami dengan baik. | Physical Layer, Data Link Layer dasar.          |
| `[SUMBER_MATERI]`   | Asal informasi yang digunakan AI.                | Dokumen PDF yang saya unggah, Pengetahuan umum. |
