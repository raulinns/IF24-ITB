# Prompt Pembuatan Catatan Ujian LaTeX Modular

Saya akan menghadapi **[Jenis Ujian]** untuk mata kuliah **[Nama Mata Kuliah]** dalam waktu **[Waktu Tersisa Menuju Ujian]**. Saya membutuhkan catatan belajar yang sistematis, padat, tetapi tetap menjelaskan konsep fundamental secara utuh agar dapat digunakan untuk memahami materi dan melakukan review menjelang ujian.

Buat output sebagai **proyek LaTeX modular** yang siap dikompilasi, bukan sebagai dokumen Markdown dan bukan sebagai file `.tex` mandiri yang terpisah dari proyek.

---

## 1. Informasi yang Saya Berikan

### Informasi Dasar

```text
Nama mata kuliah: IF2224 Teori Bahasa Formal dan Otomata
Jenis ujian: UAS
Tanggal ujian: Kamis, 11 Juni 2026
```

### Capaian Pembelajaran Mata Kuliah (CPMK)

```text
- **CPMK 1** Menjelaskan konsep, notasi dan penerapan konsep teori automaton dan bahasa formal seperti deterministik, non-deterministik, dan penerapannya dalam compiler, hierarki automaton, dan teori bahasa formal terkait dengan batasan kompleksitas dari permasalahan praktik.
    
- **CPMK 2** Merancang automaton (finite automaton, push down automaton, turing machine) untuk permasalahan tertentu
```

### Materi Ujian

```text
- PDA (termasuk konversi CFG)   
- CYK 
- Mesin turing 
- Compiler 
- Recursive Decent Parser 
- LL(1) parser
- Intermediate Code 
- Interpreter dan Virtual Machine
```

### Materi yang Sudah Dikuasai

```text
-
```

### Sumber

```text
Sumber utama: https://notebooklm.google.com/notebook/69a24559-4494-45a1-847a-cfe0af4212dc
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
Nama materi: PDA
Catatan tambahan:
```

---

## 2. Pemeriksaan Informasi Minimum

Sebelum memulai workflow apapun, periksa apakah seluruh informasi berikut tersedia:

- nama mata kuliah;
- jenis ujian;
- tanggal ujian atau keterangan `Belum ditentukan`;
- CPMK;
- daftar materi ujian;
- nama materi yang dikerjakan sekarang;
- sumber utama materi atau izin untuk melengkapi dengan pengetahuan umum.

Jika ada yang belum lengkap, tanyakan **hanya** bagian yang kurang sebelum melanjutkan. Jangan mengarang tanggal ujian, CPMK, daftar materi, atau isi sumber.

Setelah informasi minimum terpenuhi, jalankan **Workflow Pra-Penulisan** pada Bagian 3 secara berurutan dan menyeluruh. Jangan melewati satu langkah pun.

---

## 3. Workflow Pra-Penulisan (Wajib Dilaksanakan Sebelum Menulis LaTeX)

Workflow ini terdiri dari enam langkah berurutan. Langkah 1–4 dijalankan untuk **seluruh materi ujian**. Langkah 5–6 dijalankan hanya untuk **materi yang diminta sekarang**.

---

### Langkah 1 — Inventarisasi Sumber NotebookLM

Jalankan perintah berikut untuk mendaftar seluruh notebook yang tersedia:

```
$notebooklm notebook_manager.py list
```

Tampilkan hasil listing dalam format tabel ringkas berisi: ID notebook, nama, dan deskripsi. Jika tidak ada notebook yang terdaftar, informasikan kepada saya dan minta saya menambahkan sumber terlebih dahulu sebelum melanjutkan.

Setelah listing selesai, tentukan notebook mana yang paling relevan untuk setiap materi ujian. Gunakan perintah berikut apabila perlu membantu pemetaan:

```
$notebooklm notebook_manager.py search --query "[nama materi atau kata kunci topik]"
```

Catat mapping `[nama materi] → [notebook-id]` sebelum melanjutkan ke Langkah 2. Jika satu materi relevan dengan lebih dari satu notebook, catat semua notebook-id-nya.

---

### Langkah 2 — Pembuatan Outline Awal dari NotebookLM

Untuk **setiap materi** dalam daftar materi ujian (bukan hanya materi yang dikerjakan sekarang), query NotebookLM menggunakan template berikut. Ganti `[NAMA MATERI]` dan `[NOTEBOOK-ID]` dengan nilai aktual.

```
$notebooklm ask_question.py --question "Buatkan outline komprehensif untuk materi [NAMA MATERI]. Outline harus mencakup: (1) seluruh konsep utama dan sub-topik yang dibahas di sumber, (2) hierarki dari konsep dasar menuju konsep lanjut atau penerapan, (3) relasi dan dependensi antar konsep, (4) terminologi kunci, (5) rumus, algoritma, atau prosedur utama apabila ada. Gunakan format daftar bernomor bertingkat. Jangan meringkas; sertakan semua topik yang dibahas di sumber." --notebook-id [NOTEBOOK-ID]
```

Jika suatu materi dipetakan ke lebih dari satu notebook, jalankan query ke setiap notebook yang relevan lalu gabungkan hasilnya menjadi satu outline per materi, hilangkan duplikasi.

Simpan semua outline ini sebagai **Outline Awal**. Jangan tampilkan ke saya dulu; lanjut ke Langkah 3.

---

### Langkah 3 — Kritisi dan Pengayaan Outline

Untuk setiap Outline Awal dari Langkah 2, lakukan evaluasi kelengkapan secara sistematis menggunakan pengetahuan internal dan pencarian web.

**a. Identifikasi topik yang hilang**

Bandingkan Outline Awal dengan pengetahuan standar tentang materi tersebut. Lakukan web search untuk memeriksa:

- silabus atau kurikulum standar di universitas teknis untuk topik ini;
- daftar isi textbook referensi yang lazim digunakan;
- konsep prerequisite yang biasanya diperlukan untuk memahami materi ini.

**b. Tambahkan langsung topik yang belum ada**

Masukkan setiap topik yang kurang ke dalam outline. Tandai setiap item yang ditambahkan dari pengetahuan umum atau web dengan simbol `†` di akhir item.

**c. Tandai konflik antar sumber**

Jika ada sub-topik atau klaim yang berbeda antara NotebookLM dan pengetahuan umum atau web, tandai item tersebut dengan `⚠` dan tambahkan catatan singkat perbedaannya dalam kurung siku setelah item.

**Legenda penanda pada outline:**

- Tanpa penanda → berasal dari NotebookLM
- `†` → ditambahkan dari pengetahuan umum atau web (tidak ada di NotebookLM)
- `⚠` → ada di NotebookLM, tetapi terdapat perbedaan atau konflik dengan sumber lain

---

### Langkah 4 — Tampilkan Outline Final dan Tunggu Persetujuan

Setelah seluruh outline selesai dikritisi, tampilkan **Outline Final** untuk semua materi ujian dalam format yang mudah dibaca. Sertakan:

1. Legenda penanda (`†`, `⚠`) di bagian paling atas.
2. Outline per materi dengan hierarki yang jelas dan penanda yang konsisten.
3. Ringkasan perubahan di bagian bawah: berapa item berasal dari NotebookLM, berapa item ditambahkan (`†`), berapa item berkonflik (`⚠`).

**Setelah menampilkan Outline Final, berhenti dan tunggu respons saya.**

Saya akan merespons dengan salah satu dari berikut:

- **"Lanjutkan"** atau persetujuan serupa → jalankan Langkah 5.
- **Permintaan revisi** → terapkan perubahan, tampilkan kembali Outline Final, tunggu persetujuan lagi.
- **Penambahan atau penghapusan item tertentu** → modifikasi outline, tampilkan kembali, tunggu persetujuan lagi.

**Jangan lanjut ke Langkah 5 tanpa persetujuan eksplisit dari saya.**

---

### Langkah 5 — Penggalian Materi Mendalam (Hanya untuk Materi yang Dikerjakan Sekarang)

Setelah mendapat persetujuan, jalankan langkah ini **hanya untuk materi yang saya minta sekarang**. Untuk setiap item dalam outline materi tersebut — sub-topik, konsep, rumus, algoritma, prosedur — lakukan query mendalam ke NotebookLM menggunakan template berikut:

```
$notebooklm ask_question.py --question "Jelaskan secara mendalam dan fundamental konsep [NAMA SUB-TOPIK] dari materi [NAMA MATERI]. Penjelasan harus mencakup: (1) definisi formal dan pengertian lengkap, (2) motivasi dan latar belakang mengapa konsep ini penting, (3) teori dasar yang mendasari, (4) mekanisme atau prosedur kerja langkah demi langkah, (5) rumus atau persamaan matematika beserta arti setiap simbol dan kondisi penggunaannya, (6) algoritma atau pseudocode apabila relevan, (7) klasifikasi atau jenis-jenis apabila ada, (8) hubungan dengan konsep lain dalam materi ini, (9) contoh konkret apabila tersedia di sumber. Sertakan semua informasi yang ada di sumber tanpa pengecualian." --notebook-id [NOTEBOOK-ID]
```

**Perlakuan khusus per jenis item:**

- Item **tanpa penanda** → query ke NotebookLM menggunakan template di atas.
- Item **`†`** (hanya dari pengetahuan umum) → tidak perlu query; gunakan pengetahuan umum dan web search langsung.
- Item **`⚠`** (konflik) → query ke NotebookLM untuk mendapatkan versi sumbernya, lalu catat perbedaan dengan sumber lain agar dapat ditandai dengan environment `cmt` di dokumen LaTeX.

Simpan seluruh hasil query sebelum melanjutkan ke Langkah 6.

---

### Langkah 6 — Sintesis ke Dokumen LaTeX

Gunakan seluruh hasil dari Langkah 5 sebagai bahan dasar untuk menyusun dokumen LaTeX. Ikuti ketentuan sintesis pada Bagian 5 dan ketentuan format pada Bagian 6 hingga 10.

---

## 4. Penanganan Konflik dan Keterbatasan Sumber

### Konflik antara NotebookLM dan Pengetahuan Umum atau Web

Kedua sumber diperlakukan setara. Ketika ada perbedaan atau konflik, sajikan versi NotebookLM sebagai penjelasan utama dalam teks, lalu sajikan versi yang berbeda dalam environment `cmt`:

```latex
\begin{cmt}{Catatan: Perbedaan dengan Sumber Lain}{}
Berdasarkan [sumber atau referensi lain], [penjelasan alternatif atau tambahan].
Perbedaan ini kemungkinan disebabkan oleh [penjelasan singkat, apabila dapat diidentifikasi].
\end{cmt}
```

### Informasi Hanya dari Pengetahuan Umum atau Web (Item `†`)

Untuk sub-topik yang tidak ada di NotebookLM sama sekali, bungkus seluruh penjelasan dalam environment `cmt`:

```latex
\begin{cmt}{Catatan: Sumber Pengetahuan Umum}{}
Informasi berikut tidak ditemukan di sumber utama dan didasarkan pada pengetahuan umum atau referensi eksternal. [Isi penjelasan.]
\end{cmt}
```

### Keterbatasan Sumber

Apabila NotebookLM memberikan jawaban yang terlalu singkat, ambigu, atau tidak dapat menjawab pertanyaan untuk sub-topik tertentu, nyatakan keterbatasannya secara eksplisit:

```latex
\begin{cmt}{Keterbatasan Sumber}{}
Informasi mengenai [sub-topik ini] tidak tersedia secara lengkap di sumber yang diberikan.
Penjelasan berikut didasarkan pada pengetahuan umum dan mungkin berbeda dari apa yang diajarkan di kelas.
\end{cmt}
```

---

## 5. Ketentuan Penggunaan Sumber

- CPMK harus disalin langsung dari isian saya ke dalam catatan tanpa diringkas, diparafrasekan, atau diganti redaksinya.
- Penyesuaian CPMK hanya diperbolehkan untuk karakter khusus LaTeX: `&` → `\&`, `%` → `\%`, `_` → `\_`, `#` → `\#`.
- Jika query NotebookLM gagal atau hasilnya kosong, informasikan kepada saya dan jangan mengarang isi sumber.
- Apabila informasi dari sumber terbatas atau ambigu, nyatakan keterbatasannya secara eksplisit menggunakan environment `cmt`.
- Jangan menyalin mentah jawaban dari NotebookLM. Susun ulang informasi menjadi catatan yang komprehensif dan koheren.

---

## 6. Strategi Sintesis Materi

Setelah seluruh hasil query dari Langkah 5 terkumpul, sintesis informasi berikut apabila relevan untuk setiap sub-topik:

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

- Susun ulang informasi menjadi catatan komprehensif dan koheren yang mudah dipelajari.
- Jelaskan masing-masing materi berdasarkan konsep fundamentalnya terlebih dahulu, lalu jelaskan lebih mendetail.
- Jelaskan seakan-akan pembaca tidak mengerti sama sekali tentang materi ini; catatan ini adalah satu-satunya sumber belajar.
- Pastikan hanya dengan membaca catatan ini, pembaca dapat mencapai nilai maksimal pada ujian.
- Informasi dari pengetahuan umum atau web yang tidak ada di NotebookLM harus dibungkus dalam environment `cmt`.

---

## 7. Struktur Proyek LaTeX

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

Pada tingkat `\section{...}`, isi dokumen harus mencakup `Informasi Ujian`, `Daftar Materi yang Diujikan`, `Outline Keseluruhan Materi`, dan satu section untuk nama setiap materi yang disusun. Jangan membuat heading `\section` tambahan yang menduplikasi atau menaungi section materi; gunakan `\subsection` atau teks pengantar apabila diperlukan.

---

## 8. Pengerjaan Bertahap atau Sekaligus

### Jika Saya Meminta Satu Materi Terlebih Dahulu

1. Jalankan **Langkah 1–4** untuk **seluruh materi ujian**: inventarisasi sumber, buat outline semua materi, kritisi, tampilkan Outline Final, dan tunggu persetujuan.
2. Setelah persetujuan, jalankan **Langkah 5–6** hanya untuk materi yang saya minta sekarang.
3. Buat struktur dasar proyek, `preamble.sty`, `main.tex`, dan hanya file materi yang diminta di folder `section/`.
4. Di dalam `main.tex`, masukkan hanya file materi yang benar-benar sudah dibuat.
5. Jangan membuat isi lengkap untuk materi lain sebelum saya memintanya.
6. Berikan proyek yang dapat dikompilasi, lalu tunggu instruksi berikutnya.

Untuk sesi berikutnya (materi kedua, ketiga, dst.), **Langkah 1–4 tidak perlu diulang** karena outline sudah disetujui. Langsung jalankan Langkah 5–6 untuk materi yang baru diminta, lalu tambahkan file-nya ke proyek dan perbarui `main.tex`.

### Jika Saya Meminta Seluruh Materi Sekaligus

1. Jalankan Langkah 1–4 untuk seluruh materi.
2. Setelah persetujuan, jalankan Langkah 5–6 untuk semua materi sekaligus.
3. Buat seluruh file materi di folder `section/`.
4. Masukkan seluruh file ke `main.tex` sesuai urutan materi ujian.
5. Pastikan tidak ada isi yang tertukar atau berulang.
6. Berikan proyek lengkap yang siap dikompilasi.

### Pola Nama File Materi

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

## 9. Template Wajib `main.tex`

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

\section{Capaian Pembelajaran Mata Kuliah (CPMK)}

% Salin CPMK PERSIS sebagaimana diberikan. Tidak boleh diparafrasekan.
\begin{enumerate}
    \item [CPMK 1 --- salin verbatim]
    \item [CPMK 2 --- salin verbatim]
    \item [CPMK 3 --- salin verbatim]
\end{enumerate}

\subsection{Tabel Keterpenuhan CPMK}

\begin{table}[H]
\centering
\begin{tabularx}{\textwidth}{|L{0.22\textwidth}|*{N}{>{\centering\arraybackslash}X|}}
\hline
\textbf{CPMK} & \textbf{Materi 1} & \textbf{Materi 2} & \textbf{Materi 3} \\
\hline
CPMK 1 & \checkmark & & \\
\hline
CPMK 2 & & \checkmark & \checkmark \\
\hline
CPMK 3 & & & \checkmark \\
\hline
\end{tabularx}
\caption{Keterpenuhan CPMK per materi yang dibahas}
\label{tab:keterpenuhan-cpmk}
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

- Baris `% arara: pdflatex` harus berada di baris paling atas.
- Gunakan `\maketitle` di dalam `titlepage`.
- Gunakan `\tableofcontents` setelah halaman judul apabila daftar isi diminta.
- Bagian `Informasi Ujian` wajib memuat jenis ujian, nama mata kuliah, dan tanggal ujian. Apabila tanggal tidak tersedia, tuliskan `Belum ditentukan`.
- CPMK harus dicantumkan persis sesuai isian saya, disertai tabel keterpenuhan CPMK per materi.
- Urutan `\input` harus mengikuti urutan materi ujian.
- Jangan menulis penjelasan detail materi langsung di `main.tex`; hanya outline global yang ditempatkan di sana.

---

## 10. Ketentuan `preamble.sty` dan Environment

Saya dapat menyediakan `preamble.sty` dari format laporan sebelumnya. Gunakan fasilitas yang tersedia atau sesuaikan seperlunya agar catatan dapat dikompilasi dengan benar, termasuk dukungan untuk rumus matematika, tabel, hyperlink, daftar terstruktur, `tcolorbox`, dan `lstlisting`.

### `jawab` untuk Definisi atau Inti Konsep

```latex
\begin{jawab}[Inti Konsep.]
Ringkasan konsep yang paling penting untuk dipahami.
\end{jawab}
```

Gunakan untuk inti suatu subtopik atau ringkasan krusial sebelum uraian detail.

### `cmt` untuk Catatan Penting, Konflik, atau Keterbatasan

```latex
\begin{cmt}{Judul Catatan}{}
Isi catatan penting.
\end{cmt}
```

Gunakan untuk: keterbatasan sumber, perbedaan atau konflik antara NotebookLM dan sumber lain, informasi yang berasal dari pengetahuan umum atau web (item `†`), kesalahan pemahaman umum, dan hubungan konseptual penting.

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

### Perintah Prioritas Belajar untuk Outline

Tambahkan tiga perintah berikut ke dalam `preamble.sty`. Perintah ini digunakan pada outline di setiap file materi untuk menampilkan kode warna prioritas belajar secara visual.

```latex
% Prioritas belajar — digunakan pada \subsection{Outline Fundamental Konsep Materi}
\newcommand{\pwajib}{\colorbox{red!18}{\textcolor{red!75!black}{\textbf{\scriptsize WAJIB}}}\;}
\newcommand{\ppaham}{\colorbox{yellow!55}{\textcolor{yellow!65!black}{\textbf{\scriptsize PAHAM}}}\;}
\newcommand{\pkuasai}{\colorbox{green!22}{\textcolor{green!60!black}{\textbf{\scriptsize KUASAI}}}\;}
```

Makna masing-masing perintah:

- `\pwajib` — label **merah**: konsep ini adalah inti materi; tanpa memahaminya tidak mungkin menjawab soal ujian dengan benar.
- `\ppaham` — label **kuning**: konsep ini perlu dipahami secara umum; soal ujian jarang menguji detailnya secara langsung.
- `\pkuasai` — label **hijau**: konsep ini sudah dikuasai berdasarkan isian saya pada field "Materi yang Sudah Dikuasai".

---

## 11. Struktur Wajib File Setiap Materi

Setiap file `section/[nomor]-[nama-materi].tex` menggunakan struktur berikut.

### Section Nama Materi

```latex
\section{[Nama Materi]}
```

Isi dengan satu atau dua paragraf singkat yang menjelaskan ruang lingkup materi, fokus yang perlu dipahami untuk ujian, dan posisi materi dalam mata kuliah. Langsung masuk ke substansi tanpa pembuka formal.

### Outline Fundamental Konsep Materi

```latex
\subsection{Outline Fundamental Konsep Materi}

\begin{enumerate}
    \item \pwajib Konsep Dasar Pertama
    \begin{enumerate}
        \item \pwajib Subkonsep A
        \item \ppaham Subkonsep B
    \end{enumerate}
    \item \ppaham Konsep Dasar Kedua
    \item \pkuasai Konsep Dasar Ketiga
\end{enumerate}
```

Outline ini diturunkan langsung dari Outline Final yang telah disetujui pada Langkah 4. Cakup seluruh submateri penting secara ringkas dan urutkan dari konsep dasar menuju penerapan atau materi lanjut.

Setiap item pada outline **wajib** diberi label prioritas menggunakan salah satu dari tiga perintah berikut. Penetapan prioritas harus didasarkan pada sentralitas konsep dalam sumber dan kaitannya dengan CPMK, bukan pada prediksi soal ujian.

- `\pwajib` (merah) — konsep ini adalah fondasi; tanpa memahaminya tidak mungkin menjawab soal dengan benar. Gunakan untuk: definisi fundamental, mekanisme utama, algoritma kunci, rumus pokok, dan konsep yang menjadi prasyarat subtopik lain.
- `\ppaham` (kuning) — konsep ini mendukung pemahaman keseluruhan materi tetapi tidak selalu diuji secara langsung. Gunakan untuk: latar belakang, konsep pendukung, varian minor, konteks historis, dan contoh tambahan.
- `\pkuasai` (hijau) — konsep ini sudah dikuasai berdasarkan isian saya pada field "Materi yang Sudah Dikuasai". Gunakan tepat sasaran; jangan melabeli sesuatu sebagai hijau jika saya tidak menyatakannya secara eksplisit.

### Penjelasan Konsep

```latex
\subsection{Penjelasan Konsep}

\subsubsection{[Nama Subtopik]}

\begin{jawab}[Inti Konsep.]
[Dua atau tiga kalimat yang menjawab: apa konsep ini, untuk apa digunakan, dan mengapa penting dalam konteks materi ini.]
\end{jawab}

[Penjelasan naratif mendalam: motivasi → definisi → mekanisme → komponen dan terminologi → hubungan dengan konsep lain.]
```

Setiap `\subsubsection` adalah **unit belajar yang mandiri dan lengkap**. Standar yang berlaku: setelah membaca satu subsubsection saja, pembaca harus mampu menjawab soal ujian yang berkaitan dengan subtopik itu tanpa membuka sumber lain. Berikut adalah ketentuan rinci tentang apa yang harus ada, bagaimana cara menulisnya, dan kapan tambahan tertentu diperlukan.

#### (a) Cakupan: satu item outline, satu subsubsection

Setiap item dalam Outline Final yang disetujui mendapat tepat satu `\subsubsection` tersendiri. Jangan menggabungkan dua item berbeda, dan jangan memecah satu item menjadi beberapa subsubsection kecuali materinya benar-benar sangat kompleks dan pemecahan itu membantu pemahaman.

#### (b) Blok `jawab`: pintu masuk wajib

Blok `\begin{jawab}` **wajib ada** di awal setiap subsubsection. Isinya 2–3 kalimat yang menjawab tiga pertanyaan sekaligus: _apa_ konsep ini, _untuk apa_ digunakan, dan _mengapa_ penting dalam konteks materi. Bayangkan mahasiswa memiliki 30 detik sebelum ujian; blok `jawab` adalah yang pertama mereka baca. Buat sepadat dan seinformatif mungkin.

#### (c) Urutan narasi: motivasi dulu, definisi kemudian

Urutan penjelasan yang efektif adalah **motivasi → definisi → mekanisme → komponen → hubungan**. Jangan membalik urutan ini.

- **Motivasi**: Jelaskan _mengapa_ konsep ini ada atau diperlukan. Apa masalah yang diselesaikannya? Apa yang tidak bisa dilakukan tanpa konsep ini? Motivasi membangun konteks yang membuat definisi lebih bermakna dan jauh lebih mudah diingat.
- **Definisi**: Setelah konteks terbangun, sajikan definisi formal atau pengertian yang tepat. Definisi tanpa motivasi sulit diingat; motivasi tanpa definisi tidak presisi — keduanya wajib hadir berdampingan.
- **Mekanisme**: Apabila konsep memiliki cara kerja, prosedur, atau alur eksekusi yang bisa diuraikan, jelaskan langkah demi langkah menggunakan daftar bernomor. Jangan menjelaskan mekanisme dalam paragraf prosa karena urutan langkah akan kabur.
- **Komponen dan terminologi kunci**: Setiap istilah teknis atau komponen penting yang muncul untuk pertama kali harus dicetak **tebal** dan langsung didefinisikan pada kalimat yang sama atau kalimat berikutnya. Jangan biarkan istilah teknis melintas tanpa penjelasan, seberapa pun "umum" istilah itu terasa.
- **Hubungan dengan konsep lain**: Akhiri setiap subsubsection dengan satu atau dua kalimat yang menjelaskan bagaimana konsep ini berkaitan dengan subtopik lain dalam outline atau dengan CPMK. Ini membantu pembaca membangun peta konsep yang kohesif, bukan kumpulan fakta yang terpencar.

Jangan berasumsi pembaca sudah tahu apapun tentang subtopik ini. Setiap penjelasan harus dapat dipahami oleh seseorang yang baru pertama kali membacanya.

#### (d) Tabel komponen inline: wajib untuk tiga komponen atau lebih

Apabila suatu subtopik memiliki tiga komponen atau lebih yang perlu disajikan bersama — misalnya parameter, modul, simbol, tipe-tipe data, atau jenis varian — gunakan tabel kecil inline langsung di dalam subsubsection tersebut. Ini menggantikan penyajian komponen di subsection terpisah; semua komponen dan terminologi kunci hidup di dalam subsubsection yang relevan.

```latex
\begin{table}[H]
\centering
\begin{tabularx}{\textwidth}{|L{0.28\textwidth}|X|}
\hline
\textbf{Komponen / Istilah} & \textbf{Definisi atau Peran} \\
\hline
[Nama komponen] & [Penjelasan singkat dan tepat.] \\
\hline
\end{tabularx}
\caption{Komponen dalam [Nama Subtopik]}
\label{tab:[label-subtopik]}
\end{table}
```

Untuk satu atau dua komponen saja, cukup definisikan secara inline dalam paragraf tanpa tabel.

#### (e) Klasifikasi dan perbandingan

Apabila suatu subtopik memiliki jenis-jenis, varian, atau hal-hal yang perlu dibandingkan, gunakan tabel atau daftar berpoin — jangan membahasnya dalam prosa panjang karena perbedaan akan sulit dilacak saat review.

#### (f) Catatan sumber menggunakan `cmt`

Setiap bagian penjelasan yang berasal dari pengetahuan umum atau web (item `†`) harus dibungkus dalam environment `cmt`. Setiap konflik dengan sumber NotebookLM (item `⚠`) harus ditangani sesuai ketentuan Bagian 4. Jangan menggabungkan konten sumber utama dan konten pengetahuan umum dalam satu paragraf tanpa penanda.

#### (g) Standar kecukupan

Sebuah subsubsection dianggap cukup apabila setelah membacanya seorang mahasiswa mampu melakukan **keempat hal** berikut tanpa membuka sumber lain:

1. Mendefinisikan konsep dengan kalimatnya sendiri secara tepat.
2. Menjelaskan kapan dan mengapa konsep ini digunakan.
3. Menjelaskan cara kerjanya atau menerapkan prosedurnya apabila konsep bersifat prosedural.
4. Mengidentifikasi dan mendefinisikan semua komponen atau istilah kunci yang terlibat.

Apabila salah satu dari keempat hal di atas tidak dapat dipenuhi setelah membaca penjelasan, tambahkan pendalaman hingga keempatnya terpenuhi.

### Algoritma dan Rumus Penting

Tambahkan subsection ini hanya apabila materi memiliki rumus, algoritma, pseudocode, fungsi, atau prosedur formal yang penting. Subsection ini juga dapat memuat contoh implementasi atau contoh kasus yang sering keluar.

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

---

## 12. Ketentuan Bahasa dan Gaya Penulisan

- Gunakan Bahasa Indonesia yang jelas, akademis, dan mudah dipelajari.
- Catatan harus terasa seperti bahan belajar terstruktur, bukan laporan formal.
- Pertahankan istilah teknis Bahasa Inggris apabila lazim digunakan.
- Pada penyebutan pertama, gunakan bentuk `bahasa Indonesia (\textit{English term})` apabila padanan Bahasa Indonesia relevan.
- Gunakan paragraf untuk penjelasan gagasan; gunakan daftar atau tabel untuk langkah, klasifikasi, dan perbandingan.
- Hindari paragraf yang terlalu pendek hingga tidak menjelaskan apapun.
- Jangan menyertakan pembuka formal, kata penutup, pernyataan orisinalitas, identitas institusi, atau lampiran.
- Jangan menambahkan soal latihan, prediksi soal, atau analogi kecuali saya memintanya.

---

## 13. Validasi LaTeX Sebelum Memberikan Output

Sebelum menyerahkan proyek, pastikan seluruh poin berikut terpenuhi:

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
12. Heading `\section` mencakup: Informasi Ujian, CPMK dan Tabel Keterpenuhan, Daftar Materi yang Diujikan, Outline Keseluruhan Materi, serta nama masing-masing materi yang telah disusun.
13. Semua item `†` dari outline (pengetahuan umum) sudah dibungkus dalam environment `cmt` di LaTeX.
14. Semua item `⚠` dari outline (konflik) sudah ditangani dengan format konflik sesuai Bagian 4.
15. Setiap item pada subsection `Outline Fundamental Konsep Materi` sudah diberi label prioritas (`\pwajib`, `\ppaham`, atau `\pkuasai`) tanpa ada item yang tidak berlabel.
16. Setiap `\subsubsection` di dalam `Penjelasan Konsep` memiliki blok `\begin{jawab}` di baris pertamanya.
17. Setiap komponen atau terminologi kunci sudah didefinisikan inline atau dalam tabel di dalam subsubsection yang relevan; tidak ada subsection "Komponen Kunci" yang berdiri sendiri.

---

## 14. Bentuk Respons yang Diharapkan

Urutan respons yang diharapkan untuk setiap sesi baru adalah sebagai berikut:

1. **Pemeriksaan informasi minimum** → tanyakan hanya bagian yang kurang.
2. **Langkah 1** → tampilkan daftar notebook yang ditemukan beserta mapping ke materi ujian.
3. **Langkah 2** → jalankan query outline untuk semua materi (tidak ditampilkan ke saya dulu).
4. **Langkah 3** → kritisi dan perkaya outline secara internal (tidak ditampilkan ke saya dulu).
5. **Langkah 4** → tampilkan Outline Final lengkap untuk semua materi beserta ringkasan perubahan. **Berhenti dan tunggu persetujuan.**
6. **Langkah 5** (setelah persetujuan) → jalankan query mendalam untuk materi yang diminta (tidak ditampilkan mentah ke saya).
7. **Langkah 6** → hasilkan proyek LaTeX modular.
8. Berikan file proyek yang dapat diunduh.
9. Sebutkan secara singkat file materi yang dibuat dan cakupan materinya.

Untuk sesi lanjutan (materi berikutnya dalam proyek yang sama), lewati Langkah 1–4 dan langsung ke Langkah 5–6 untuk materi yang baru diminta.