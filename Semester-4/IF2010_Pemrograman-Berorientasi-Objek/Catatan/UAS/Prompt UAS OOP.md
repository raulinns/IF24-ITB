# Prompt Pembuatan Catatan Ujian LaTeX Modular

Saya akan menghadapi **[Jenis Ujian]** untuk mata kuliah **[Nama Mata Kuliah]** dalam waktu **[Waktu Tersisa Menuju Ujian]**. Saya membutuhkan catatan belajar yang sistematis, padat, tetapi tetap menjelaskan konsep fundamental secara utuh agar dapat digunakan untuk memahami materi dan melakukan review menjelang ujian.

Buat output sebagai **proyek LaTeX modular** yang siap dikompilasi, bukan sebagai dokumen Markdown dan bukan sebagai file `.tex` mandiri yang terpisah dari proyek.

---

## 1. Informasi yang Saya Berikan

### Informasi Dasar

```text
Nama mata kuliah: IF2010 Pemrograman Berbasis Objek
Waktu tersisa: 18 jam
Jenis ujian: UAS 
Tanggal ujian: Kamis, 4 Juni 2026
```

### Capaian Pembelajaran Mata Kuliah (CPMK)

```text
Tidak disebutkan dalam perkuliahan
```

### Materi Ujian

```text
1. Prinsip OOP SOLID
2. Pengenalan Bahasa Java
3. Padanan Java - C++
4. Java String
5. Java Inheritance
6. Java Interface
7. Java Generics
8. Java Generics Wildcard
9. Java Collection
10. Java Stream API
11. Java Exception
12. Java Assertion
13. Java Multithreading
14. Java Reflection
15. Design Pattern
```

### Materi yang Sudah Dikuasai

```text
- 1 sampai 10 sudah pernah diujikan dalam kuis, tetapi masih perlu didalami lebih lanjut,
- 11 sampai 13 merupakan materi baru yang masih perlu dipahami lebih lanjut.
```

### Sumber

```text
Sumber utama: https://notebooklm.google.com/notebook/ae95dbc3-52a1-4fba-be07-dc0d0c3d6455
Boleh melengkapi dengan pengetahuan umum: Ya
```

### Preferensi Catatan

```text
Tingkat kedalaman: Mendalam
Perlu pseudocode: Ya
Perlu rumus: Ya
```

### Preferensi LaTeX

```text
Gunakan preamble.sty: Ya
Gunakan daftar isi: Ya
```

### Materi yang Dikerjakan Sekarang

```text
Nama materi: Solid OOP
Catatan tambahan: Buatlah catatan berurutan berdasarkan list materi yang diberikan.
```

---

## 2. Pemeriksaan Informasi Sebelum Menulis

Setelah membaca isian di atas:

1. Periksa apakah informasi minimum untuk menyusun catatan materi yang diminta sudah tersedia, yaitu:
   - nama mata kuliah;
   - jenis ujian;
   - tanggal ujian atau keterangan `Belum ditentukan`;
   - CPMK;
   - daftar materi ujian;
   - nama materi yang dikerjakan sekarang;
   - sumber utama materi atau izin untuk melengkapi dengan pengetahuan umum.
2. Jika informasi wajib belum lengkap, tanyakan hanya bagian yang benar-benar diperlukan.
3. Jangan mengarang tanggal ujian, CPMK, daftar materi, atau isi sumber.
4. Jika informasi sudah cukup, mulai menyusun proyek LaTeX sesuai ketentuan berikut.

---

## 3. Ketentuan Penggunaan Sumber

Gunakan sumber yang saya berikan sebagai rujukan utama isi catatan.

- CPMK harus disalin langsung dari isian saya ke dalam catatan. Jangan meringkas, memparafrasekan, atau mengganti redaksinya.
- Penyesuaian CPMK hanya diperbolehkan untuk karakter khusus LaTeX, misalnya `&` menjadi `\&`, `%` menjadi `\%`, `_` menjadi `\_`, dan `#` menjadi `\#`.
- Apabila link NotebookLM tidak dapat diakses secara langsung, jangan mengklaim telah membaca isinya. Mintalah saya mengunggah dokumen sumber atau menempelkan hasil query yang relevan.
- Apabila informasi dari sumber terbatas atau ambigu, nyatakan keterbatasannya secara eksplisit di dalam catatan.
- Pengetahuan umum boleh digunakan sebagai pelengkap apabila sumber yang digunakan kurang lengkap atau kurang mendalam, dan bagian yang ditambahkan harus ditandai menggunakan environment `cmt`.

---

## 4. Strategi Sintesis Materi

Apabila sumber dapat ditelusuri atau ditanya per materi, lakukan penggalian informasi bertingkat dalam **Bahasa Indonesia**. Istilah teknis dalam Bahasa Inggris tetap boleh dicantumkan dalam tanda kurung.

### Query Konteks Pembelajaran

> Saya sedang mempersiapkan [Jenis Ujian] mata kuliah [Nama Mata Kuliah]. Berdasarkan dokumen sumber yang tersedia, bantu saya memahami materi [Nama Materi] dengan fokus pada konsep fundamental, terminologi penting, prosedur atau algoritma, rumus, hubungan dengan CPMK, dan bagian terpenting untuk dikuasai dalam ujian.

### Query Pemetaan Konsep

> Berdasarkan dokumen [Nama Materi], apa saja konsep utama, subtopik, terminologi, prosedur, algoritma, rumus, asumsi, dan keterbatasan penting dalam [Nama Materi]? Susun sebagai peta konsep lengkap yang perlu dipahami untuk ujian.

### Query Teori Dasar per Subtopik

> Berdasarkan dokumen [Nama Materi], jelaskan definisi, tujuan, motivasi, teori dasar, dan hubungan [Subtopik X] dengan keseluruhan materi [Nama Materi].

### Query Teknis per Subtopik

> Berdasarkan dokumen [Nama Materi], jelaskan prosedur, langkah kerja, algoritma, rumus, klasifikasi, perbandingan, atau kondisi penggunaan yang berkaitan dengan [Subtopik X]. Jelaskan arti setiap simbol, parameter, input, output, serta asumsi penting apabila ada.

### Query Validasi Kelengkapan

> Berdasarkan dokumen [Nama Materi], apakah terdapat konsep, terminologi, algoritma, rumus, asumsi, edge case, keterbatasan, atau detail penting lain yang belum tercakup dalam pembahasan sebelumnya?

### Informasi yang Harus Disintesis

Dari sumber yang tersedia, sintesis informasi berikut apabila relevan:

- definisi konsep utama;
- teori, motivasi, dan hubungan antarkonsep;
- prosedur atau mekanisme kerja;
- klasifikasi atau perbandingan;
- terminologi penting;
- algoritma, pseudocode, rumus, arti simbol, dan kondisi penggunaan;
- implementasi dasar;
- relevansi industri secara realistis;
- dependensi dengan materi lain.

### Aturan Sintesis

- Jangan menyalin mentah jawaban dari sumber.
- Susun ulang informasi menjadi catatan komprehensif dan koheren yang mudah dipelajari.
- Jelaskan masing-masing materi berdasarkan konsep fundamentalnya, lalu jelaskan konsep fundamental tersebut dengan lebih mendetail (diperkenankan menggunakan pengetahuan umum agar mempermudah pemahaman saya)
- Jelaskan seakan-akan saya tidak mengerti sama sekali tentang materi-materi ini, lalu catatan ini menjadi satu-satunya sumber materi yang saya gunakan untuk belajar, sehingga pastikan hanya dengan membaca materi ini saya dapat mencapai nilai maksimal pada ujian.
- Anda diperkenankan menggunakan pengetahuan umum, mencari materi di sumber-sumber lain, selain yang diberikan pada notebookLM. Saya mendukung anda untuk tidak hanya menggunakan sumber yang saya berikan untuk memberikan penjelasan yang komprehensif dan menyeluruh terkait topik yang ada.

---

## 5. Struktur Proyek LaTeX

Output harus berupa folder proyek dengan struktur berikut:

```text
Catatan-Ujian-[Nama-Mata-Kuliah]/
├── main.tex
├── preamble.sty
├── figures/
│   └── [gambar-pendukung-apabila-digunakan]
└── section/
    ├── 1-[nama-materi-pertama].tex
    ├── 2-[nama-materi-kedua].tex
    ├── 3-[nama-materi-ketiga].tex
    └── ...
```

### Prinsip Modularitas

- `main.tex` berisi konfigurasi dokumen utama, halaman judul, daftar isi, informasi ujian, daftar materi, outline keseluruhan materi, dan daftar `\input` file materi.
- Setiap materi ditulis dalam satu file tersendiri di folder `section/`.
- File materi dalam folder `section/` dimulai langsung dari `\section{[Nama Materi]}`.
- File materi **tidak boleh** memuat `\documentclass`, `\input{preamble.sty}`, `\begin{document}`, `\end{document}`, `\maketitle`, atau `\tableofcontents`.
- `preamble.sty` digunakan bersama oleh seluruh proyek melalui `main.tex`.
- Folder `figures/` hanya perlu diisi apabila logo, ilustrasi, diagram, atau gambar pendukung benar-benar digunakan.

### Ketentuan Heading Utama

Pada tingkat `\section{...}` atau **header 1**, isi dokumen harus mencakup `Informasi Ujian`, `Daftar Materi yang Diujikan`, `Outline Keseluruhan Materi`, dan satu section untuk **nama setiap materi** yang disusun. Jangan membuat heading tingkat `\section` tambahan yang menduplikasi atau menaungi section materi; gunakan `\subsection` atau teks pengantar apabila diperlukan.

---

## 6. Pengerjaan Bertahap atau Sekaligus

### Jika Saya Meminta Satu Materi Terlebih Dahulu

1. Buat struktur dasar proyek.
2. Buat atau sesuaikan `preamble.sty`.
3. Buat `main.tex`.
4. Buat hanya file materi yang diminta di folder `section/`.
5. Di dalam `main.tex`, masukkan hanya file materi yang benar-benar sudah dibuat.
6. Jangan membuat isi lengkap untuk materi lain sebelum saya meminta.
7. Berikan proyek yang dapat dikompilasi, lalu tunggu instruksi berikutnya.

### Jika Saya Meminta Seluruh Materi Sekaligus

1. Buat seluruh file materi di folder `section/`.
2. Masukkan seluruh file tersebut ke `main.tex` sesuai urutan materi ujian.
3. Pastikan tidak ada isi yang tertukar atau berulang.
4. Berikan proyek lengkap yang siap dikompilasi.

### Pola Nama File Materi

Gunakan pola berikut:

```text
1-[nama-materi-singkat].tex
2-[nama-materi-singkat].tex
3-[nama-materi-singkat].tex
```

Contoh:

```text
1-context-free-grammar.tex
2-pushdown-automata.tex
3-ll1-parser.tex
```

---

## 7. Template Wajib `main.tex`

Gunakan struktur berikut sebagai dasar. Sesuaikan placeholder, jumlah materi, dan daftar `\input` dengan informasi yang saya berikan.

```latex
% arara: pdflatex
\documentclass[11pt,a4paper]{article}

\usepackage{graphicx}
\input{preamble.sty}

\title{%
    \vspace{-2cm}
    \textbf{\LARGE Catatan Ujian Akhir Semester} \\[0.25em]
    \Large {Kode dan Nama Mata Kuliah} \\[0.25em]
    \normalsize Semester 4 Tahun 2025/2026 \\[2em]
}

\author{%
    Narendra Dharma Wistara M. \\[0.25em]
    13524044 \\[2.5em]
    Program Studi Teknik Informatika \\[0.25em]
    Sekolah Teknik Elektro dan Informatika \\[0.25em]
    Institut Teknologi Bandung \\[0.25em]
}

\begin{document}
\pagenumbering{gobble}
\begin{titlepage}
    \maketitle
    \thispagestyle{empty}
\end{titlepage}

\clearpage

\pagenumbering{roman}
\tableofcontents

\clearpage
\pagenumbering{arabic}

\section{Informasi Ujian}

\begin{table}[H]
\centering
\begin{tabularx}{\textwidth}{|L{0.30\textwidth}|X|}
\hline
\textbf{Jenis Ujian} & [Jenis Ujian] \\
\hline
\textbf{Nama Mata Kuliah} & [Nama Mata Kuliah] \\
\hline
\textbf{Tanggal Ujian} & [Tanggal Ujian / Belum ditentukan] \\
\hline
\end{tabularx}
\caption{Informasi ujian}
\label{tab:informasi-ujian}
\end{table}

\section{Daftar Materi yang Diujikan}

\begin{enumerate}
    \item [Nama Materi Pertama]
    \item [Nama Materi Kedua]
    \item [Nama Materi Ketiga]
    % Tambahkan materi lain apabila diperlukan.
\end{enumerate}

\section{Outline Keseluruhan Materi}

Bagian ini menyajikan peta belajar ringkas untuk seluruh materi yang diujikan.
Penjelasan mendalam tersedia pada section masing-masing materi.

\subsection{[Nama Materi Pertama]}
\begin{itemize}
    \item [Konsep utama pertama.]
    \item [Konsep utama kedua.]
    \item [Hubungan atau tujuan utama materi, apabila relevan.]
\end{itemize}

\subsection{[Nama Materi Kedua]}
\begin{itemize}
    \item [Konsep utama pertama.]
    \item [Konsep utama kedua.]
    \item [Hubungan atau tujuan utama materi, apabila relevan.]
\end{itemize}

% Tambahkan subsection outline materi lain sesuai kebutuhan.

\newpage
\input{section/1-[nama-materi-pertama].tex}
% Masukkan hanya materi yang telah dibuat:
% \input{section/2-[nama-materi-kedua].tex}
% \input{section/3-[nama-materi-ketiga].tex}

\end{document}
```

### Ketentuan `main.tex`

- Baris `% arara: pdflatex` harus tetap berada di baris paling atas.
- Gunakan `\maketitle` di dalam `titlepage`.
- Gunakan `\tableofcontents` setelah halaman judul apabila daftar isi diminta.
- Bagian `Informasi Ujian` wajib memuat jenis ujian, nama mata kuliah, dan tanggal ujian.
- Apabila tanggal ujian tidak tersedia, tuliskan `Belum ditentukan`.
- Urutan `\input` harus mengikuti urutan materi ujian.
- Jangan menulis penjelasan detail materi langsung di `main.tex`; hanya outline global yang ditempatkan di sana.
- Taruh juga CPMK di sini (lakukan copy paste tanpa parafrase sedikit pun). Lalu, buatlah tabel keterpenuhan untuk masing-masing CPMK dan setiap materi yang dibahas.

---

## 8. Ketentuan `preamble.sty` dan Environment

Saya dapat menyediakan `preamble.sty` dari format laporan sebelumnya. Gunakan fasilitas yang tersedia atau sesuaikan seperlunya agar catatan dapat dikompilasi dengan benar, termasuk dukungan untuk rumus matematika, tabel, hyperlink, daftar terstruktur, `tcolorbox`, dan `lstlisting`.

### `jawab` untuk Definisi/Inti Konsep

```latex
\begin{jawab}[Inti Konsep.]
Ringkasan konsep yang paling penting untuk dipahami.
\end{jawab}
```

Gunakan untuk inti suatu subtopik atau ringkasan krusial sebelum uraian detail.

### `cmt` untuk Catatan Penting atau Keterbatasan

```latex
\begin{cmt}{Catatan Penting}{}
Isi catatan penting.
\end{cmt}
```

Gunakan untuk keterbatasan sumber, kesalahan pemahaman umum, hubungan konseptual penting, atau tambahan pengetahuan umum.

### `thm` Hanya untuk Pernyataan Formal

```latex
\begin{thm}{Nama Teorema}{}
Pernyataan teorema.
\end{thm}
```

Gunakan hanya untuk teorema, lemma, atau sifat formal yang relevan, bukan untuk definisi biasa.

### `lstlisting` untuk Algoritma atau Implementasi

```latex
\begin{lstlisting}[language=Python, caption={Contoh implementasi singkat}]
# kode atau pseudocode
\end{lstlisting}
```

Gunakan hanya apabila algoritma atau implementasi benar-benar membantu pemahaman materi.

---

## 9. Struktur Wajib File Setiap Materi

Setiap file `section/[nomor]-[nama-materi].tex` menggunakan struktur berikut.

### Section Nama Materi

```latex
\section{[Nama Materi]}
```

Isi dengan satu atau dua paragraf singkat yang menjelaskan ruang lingkup materi, fokus yang perlu dipahami untuk ujian, dan posisi materi dalam mata kuliah. Langsung masuk ke substansi materi tanpa pembuka formal.

### Outline Fundamental Konsep Materi

```latex
\subsection{Outline Fundamental Konsep Materi}

\begin{enumerate}
    \item [Konsep dasar pertama]
    \begin{enumerate}
        \item [Subkonsep pertama]
        \item [Subkonsep kedua]
    \end{enumerate}
    \item [Konsep dasar kedua]
\end{enumerate}
```

Cakup seluruh submateri penting secara ringkas dan urutkan dari konsep dasar menuju penerapan atau materi lanjut. Tandai bagian yang telah saya kuasai dengan:

```latex
\textbf{[SUDAH DIKUASAI]}
```

Buat outline fundamental ini tanpa bertanya ke notebookLM atau melihat sumber terlebih dahulu. Coba buat dengan penalaran model kamu sendiri outline yang selengkap-lengkapnya dan mencangkup segala hal yang berhubungan dengan masing-masing materi yang tertera. Setelah itu, baru konfirmasi dan pastikan sudah mencangkup semua materi berdasarkan sumber (baru di sini tanya ke notebookLM).
### Pentingnya Materi dan Relevansinya

```latex
\subsection{Pentingnya Materi dan Relevansinya}
```

Tambahkan subsection berikut hanya apabila memang relevan:

```latex
\subsubsection{Dependensi dan Hubungan dengan Materi Lain}
```

Anda harus menggunakan pengetahuan umum untuk mengisi bagian ini jika relevansi industri/penerapan dan hubungan antar materi tidak dicantumkan di sumber. Apabila relevansi industri atau dependensi dilengkapi menggunakan pengetahuan umum, tandai menggunakan `cmt`. 

### Penjelasan Konsep Fundamental

```latex
\subsection{Penjelasan Konsep Fundamental}

\subsubsection{[Nama Subtopik]}

\begin{jawab}[Inti Konsep.]
[Satu atau dua kalimat ringkas.]
\end{jawab}

[Penjelasan naratif mengenai definisi, tujuan, motivasi, teori dasar, dan hubungan subtopik dengan materi.]
```

Ketentuan:

- Tambahkan mekanisme atau prosedur kerja hanya untuk subtopik yang memilikinya.
- Tambahkan klasifikasi atau perbandingan hanya jika relevan.
- Gunakan daftar bernomor untuk langkah kerja.
- Gunakan daftar berpoin atau tabel untuk klasifikasi dan perbandingan.

[Gunakan **paragraf narasi akademis** untuk menjelaskan hal-hal yang bersifat:]
- Definisi dan pengertian
- Tujuan dan motivasi
- Konsep awal dan latar belakang

[Gunakan **hierarki teks berpoin** untuk menjelaskan hal-hal yang bersifat:]
- Langkah-langkah teknis atau prosedural
- Jenis-jenis atau klasifikasi konsep
- Perbandingan atau perbedaan antar elemen

Saya lebih baik membaca paragraf yang panjang tetapi mengerti dibandingkan paragraf yang pendek tapi malah tidak mengerti sama sekali. 

### Komponen Kunci Penting

```latex
\subsection{Komponen Kunci Penting}

\begin{table}[H]
\centering
\begin{tabularx}{\textwidth}{|L{0.28\textwidth}|X|}
\hline
\textbf{Komponen Kunci} & \textbf{Makna atau Peran} \\
\hline
[Nama komponen] & [Definisi atau peran singkat.] \\
\hline
\end{tabularx}
\caption{Komponen kunci dalam materi [Nama Materi]}
\label{tab:komponen-kunci-[label-materi]}
\end{table}
```

Pilih hanya konsep, istilah, simbol, parameter, struktur data, modul, atau mekanisme yang benar-benar penting.

### Algoritma dan Rumus Penting

Tambahkan subsection ini hanya apabila materi memiliki rumus, algoritma, pseudocode, fungsi, atau prosedur formal yang penting. Subsection ini juga boleh untuk menambahkan contoh implementasi, contoh kasus yang sering sekali keluar.

```latex
\subsection{Algoritma dan Rumus Penting}
```

Untuk rumus, gunakan pola berikut:

```latex
\subsubsection{[Nama Rumus atau Persamaan]}

\begin{jawab}[Makna Rumus.]
[Jelaskan fungsi rumus dan kapan digunakan.]
\end{jawab}

\begin{equation}
    [Persamaan]
    \label{eq:[label-rumus]}
\end{equation}

dengan:
\begin{itemize}
    \item $[simbol]$: [arti simbol].
\end{itemize}
```

Jelaskan arti simbol, kondisi penggunaan, asumsi atau batasan, dan hubungannya dengan konsep utama.

Untuk algoritma, gunakan pola berikut:

```latex
\subsubsection{[Nama Algoritma]}

\begin{jawab}[Tujuan Algoritma.]
[Jelaskan tujuan dan hasil yang diharapkan.]
\end{jawab}

\begin{lstlisting}[caption={Pseudocode [Nama Algoritma]}, label={lst:[label-algoritma]}]
Input: ...
Output: ...

1. ...
2. ...
3. ...
\end{lstlisting}
```

Jelaskan input, output, langkah utama, kompleksitas apabila relevan dan didukung sumber, serta kondisi keberhasilan atau keterbatasannya.

### Checklist Pemahaman

```latex
\subsection{Checklist Pemahaman}

\subsubsection{Submateri yang Telah Dibahas}

\begin{itemize}
    \item[$\square$] Saya dapat menjelaskan [konsep pertama].
    \item[$\square$] Saya dapat membedakan [konsep A] dan [konsep B].
    \item[$\square$] Saya dapat menerapkan [algoritma atau rumus], apabila relevan.
    \item[$\square$] Saya dapat menjelaskan hubungan materi dengan CPMK.
\end{itemize}

\subsubsection{Prioritas Belajar}

\begin{tabularx}{\textwidth}{|L{0.22\textwidth}|X|}
\hline
\textbf{Prioritas} & \textbf{Materi yang Perlu Dikuasai} \\
\hline
\textbf{Wajib Dikuasai} & [Konsep inti, algoritma, rumus, atau mekanisme utama.] \\
\hline
\textbf{Cukup Paham Konsep} & [Materi pendukung yang perlu dipahami secara umum.] \\
\hline
\textbf{Sudah Dikuasai} & [Materi yang telah ditandai atau Belum ditentukan.] \\
\hline
\end{tabularx}
```

Checklist harus berupa kemampuan yang dapat diuji, bukan hanya daftar judul submateri. Prioritas belajar harus didasarkan pada sentralitas konsep dalam sumber, bukan prediksi soal.

---

## 10. Ketentuan Bahasa dan Gaya Penulisan

- Gunakan Bahasa Indonesia yang jelas, akademis, dan mudah dipelajari.
- Catatan harus terasa seperti bahan belajar terstruktur, bukan laporan formal.
- Pertahankan istilah teknis Bahasa Inggris apabila lazim digunakan.
- Pada penyebutan pertama, gunakan bentuk `bahasa Indonesia (\textit{English term})` apabila padanan Bahasa Indonesia relevan.
- Gunakan paragraf untuk penjelasan gagasan; gunakan daftar atau tabel untuk langkah, klasifikasi, dan perbandingan.
- Hindari paragraf yang terlalu panjang.
- Jangan menyertakan pembuka formal, kata penutup, pernyataan orisinalitas, identitas institusi, atau lampiran.
- Jangan menambahkan soal latihan, prediksi soal, atau analogi kecuali saya memintanya.

---

## 11. Validasi LaTeX Sebelum Memberikan Output

Sebelum menyerahkan proyek, pastikan:

1. Seluruh karakter khusus LaTeX sudah di-escape dengan benar.
2. Tidak ada sintaks Markdown di dalam file `.tex`.
3. `main.tex` memanggil `\input{preamble.sty}`.
4. File materi di folder `section/` hanya berisi isi materi dan dimulai dari `\section{[Nama Materi]}`.
5. Environment `jawab`, `cmt`, `thm`, dan `lstlisting` digunakan sesuai fungsinya.
6. `thm` hanya digunakan untuk teorema, lemma, atau pernyataan formal.
7. Bagian algoritma atau rumus hanya muncul apabila relevan.
8. Bagian dependensi materi hanya muncul apabila relevan.
9. Nama file dan urutan `\input` mengikuti urutan materi ujian.
10. Tidak ada materi yang diduplikasi di `main.tex` dan file `section/`.
11. Proyek dapat dikompilasi selama aset yang digunakan tersedia.
12. Heading `\section` mencakup Informasi Ujian, Daftar Materi yang Diujikan, Outline Keseluruhan Materi, serta nama masing-masing materi yang telah disusun.

---

## 12. Bentuk Respons yang Diharapkan

Untuk materi yang saya minta:

1. Lakukan sintesis berdasarkan sumber.
2. Buat atau perbarui proyek LaTeX modular.
3. Berikan file proyek yang dapat saya unduh.
4. Sebutkan secara singkat file materi yang dibuat dan materi yang dicakup.
5. Jika informasi wajib masih kurang, tanyakan hanya data yang benar-benar diperlukan.
6. Jika pengerjaan dilakukan bertahap, jangan menulis materi berikutnya sebelum saya meminta.

Mulailah dengan materi berikut:

```text
SOLID OOP Principle
```
