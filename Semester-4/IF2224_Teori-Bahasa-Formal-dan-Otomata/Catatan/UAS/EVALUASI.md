# EVALUASI.MD — Panduan Pembaruan Catatan UAS IF2224 TBFO

> **Dokumen ini ditujukan untuk AI yang bertugas memperbarui catatan UAS IF2224 TBFO
> milik Narendra Dharma Wistara M. (13524044).** Semua instruksi bersifat direktif.
> Baca seluruh dokumen sebelum mulai mengeksekusi perubahan apapun.

---

## KONTEKS DAN SUMBER DATA

**Catatan yang diperbarui:** Catatan UAS IF2224 TBFO (sumber LaTeX), mencakup 8 bagian:
§1 PDA · §2 CYK/CNF · §3 Mesin Turing · §4 Compiler · §5 RDP · §6 LL(1) · §7 Intermediate Code · §8 VM/Interpreter

**Dua sumber evaluasi yang digunakan:**

1. `evaluasi-catatan-tbfo.html` — Pemetaan 104 poin outline ke catatan. Hasil:
   72 Lengkap · 12 Sebagian · 8 Belum Ada · 1 Terlalu Dangkal · 11 poin bermasalah

2. Bundel soal UAS IF2224 TBFO 2003/04–2021/22 (16 sesi dianalisis) — Analisis
   frekuensi topik untuk menentukan relevansi gap terhadap pola soal UAS.

---

## ⚠️ PENEMUAN KRITIS — BACA SEBELUM MELANJUTKAN

**Topik Compiler / RDP / LL(1) / Intermediate Code / VM tidak pernah muncul di 16
sesi UAS historis yang tersedia (2003/04–2021/22).** Implikasinya:

- Meskipun `evaluasi-catatan-tbfo.html` mendeteksi banyak gap di area ini (code
  generation, postfix IR, error handling, dll.), **gap tersebut BUKAN prioritas
  tertinggi** untuk tujuan mempersiapkan UAS.
- **Jangan mengalokasikan lebih dari 20% kapasitas pengeditan** untuk topik-topik
  tersebut kecuali ada instruksi eksplisit di Bagian C.
- Topik yang paling kritis untuk segera diperbaiki adalah **Mesin Turing** (§3),
  karena ada di UAS historis (P3) tetapi catatan punya gap serius di sana.

---

## BAGIAN A — DIRECTIVES PRIORITAS WAJIB

> Kerjakan semua item di Bagian A sebelum melanjutkan ke Bagian B atau C.
> Urutan pengerjaan: A.1 → A.2 → A.3 → A.4 → A.5

---

### A.1 — TAMBAHKAN: Trace Eksekusi Mesin Turing pada Input Konkret

**Lokasi target:** Sisipkan setelah §7.2.6 (aturan gerak kanan/kiri formal),
sebelum §7.2.7 (acceptance by final state). Buat subseksi baru bernama
`§7.2.7 Trace Eksekusi — Contoh Langkah demi Langkah`.

**Mengapa wajib:**
- Outline §3.2.7 secara eksplisit menyebut trace eksekusi sebagai poin mandiri.
- Soal UAS TM (03/04, 14/15) biasanya berupa: "rancang TM untuk bahasa X,
  tunjukkan trace pada input Y" atau "given TM berikut, trace pada input 0011."
- Catatan saat ini: definisi ID dan aturan gerak ada (§7.2.5–7.2.6), tetapi tidak
  ada satu pun trace konkret step-by-step. Tanpa ini, soal tipe tersebut tidak
  bisa dikerjakan dari catatan.

**Yang harus ditambahkan:**

1. **Tabel trace untuk TM pengenal `{0^n 1^n}` pada input `0011`.**
   Format kolom tabel LaTeX: `Langkah | State | Isi Tape | Posisi Head | Aksi`.
   Tunjukkan 6–10 langkah penuh dari konfigurasi awal hingga accept.
   Gunakan teknik mark-scan (tandai 0 dengan X, scan ke kanan untuk tandai 1 dengan Y).

2. **Catatan pola desain umum TM untuk `{0^n 1^n}`:**
   "Strategi: (1) scan kiri, tandai 0 pertama dengan X; (2) scan kanan ke 1
   pertama, tandai dengan Y; (3) kembali ke kiri; (4) ulangi; (5) accept jika
   semua 0 dan 1 tertandai."

3. **Satu paragraf: representasi unary untuk TM transducer.**
   "Integer n pada soal TM transducer biasanya direpresentasikan unary: n buah
   simbol 0 (atau 1). Contoh: n=3 ditulis sebagai `000`. TM transducer membaca
   encoding ini dan menulis output di tape yang sama atau tape terpisah."

4. **Contoh pola TM transducer untuk f(n) = 2n dengan encoding unary.**
   Deskripsikan strategi (bukan trace penuh): "untuk setiap 0 pada input, tulis
   dua 0 pada output area tape."

---

### A.2 — TAMBAHKAN: Contoh Walkthrough Soal UAS untuk CFG→PDA dan PDA→CFG

**Lokasi target A.2.1:** Setelah §5.2.12 (CFG→PDA, kesetaraan N(P_G)=L(G)).
Buat komentar/callout bernama `Komentar 5.6 — Contoh Soal UAS: CFG → PDA`.

**Lokasi target A.2.2:** Setelah §5.2.14 (PDA→CFG, analisis ukuran grammar).
Buat komentar/callout bernama `Komentar 5.7 — Contoh Soal UAS: PDA → CFG`.

**Mengapa wajib:**
- Outline secara eksplisit menandai "relevansi UAS 2425" untuk kedua konversi.
- CFG→PDA muncul di 11/16 sesi UAS (69%). PDA→CFG di 7/16 sesi (44%).
- Grammar `S → aAA, A → aS | bS | a` muncul **empat kali** di UAS berbeda
  (03/04, 04/05, 07/08, 10/11). Belum ada contoh pengerjaan di catatan.

**Yang harus ditambahkan di Komentar 5.6 (CFG→PDA):**
Walkthrough manual langkah demi langkah konversi grammar berikut ke PDA empty stack:
```
S → aAA
A → aS | bS | a
```
Tunjukkan: (a) transisi expand-variable untuk setiap produksi; (b) transisi
match-terminal untuk setiap simbol terminal; (c) hasil akhir berupa daftar fungsi
transisi δ lengkap; (d) verifikasi satu derivasi bahwa string `aba` atau `aaa`
diterima.

**Yang harus ditambahkan di Komentar 5.7 (PDA→CFG):**
Walkthrough manual konversi PDA berikut ke CFG (ambil dari UAS 2009/10 Q3 atau
UAS 2006/07 Q5 dengan PDA null stack 1–2 state):
Tunjukkan: (a) variabel komposit [pXq] yang dibangkitkan; (b) aturan start
`S → [q0 Z0 q]` untuk setiap state q; (c) aturan produksi untuk setiap transisi;
(d) simplifikasi produksi yang tidak reachable (jika ada).

---

### A.3 — TAMBAHKAN: Walkthrough Derivasi + Parse Tree Manual

**Lokasi target:** Tambahkan sebagai subseksi baru di bagian CFG (bisa di akhir
bagian pendahuluan §5 sebelum masuk PDA, atau sebagai lampiran/komentar).
Judul subseksi: `Derivasi Leftmost/Rightmost dan Parse Tree — Panduan Pengerjaan`.

**Mengapa wajib:**
- Soal derivasi + parse tree muncul di 5/16 sesi (31%) — P2, konsisten sporadis.
- Catatan punya konsep derivasi, tetapi tidak ada walkthrough naratif yang bisa
  diikuti saat mengerjakan soal. Ambigu grammar juga termasuk dalam pola ini.

**Yang harus ditambahkan:**

1. **Definisi operasional (1 paragraf singkat):**
   "Leftmost derivation: pada setiap langkah, expand nonterminal paling KIRI.
   Rightmost derivation: pada setiap langkah, expand nonterminal paling KANAN.
   Parse tree unik untuk setiap derivasi jika grammar tidak ambiguous."

2. **Contoh walkthrough untuk grammar:**
   ```
   S → AB
   A → 0A | 0
   B → 1B | 1
   ```
   Tunjukkan leftmost derivation, rightmost derivation, dan parse tree untuk string
   `001` atau `0011`. Gambar parse tree dalam format ASCII/LaTeX tree.

3. **Cara menunjukkan grammar AMBIGUOUS:**
   "Grammar G ambiguous jika ada string w ∈ L(G) yang mempunyai DUA parse tree
   berbeda. Untuk membuktikan ambiguity: (1) pilih satu string w; (2) tunjukkan
   dua leftmost derivation berbeda yang menghasilkan w yang sama."
   Sertakan contoh untuk grammar klasik `S → SS | (S) | ε` atau if-then-else.

---

### A.4 — TAMBAHKAN: Teorema Komplemen RE

**Lokasi target:** Di §7.2.11, setelah pembahasan perbedaan RE dan Recursive
(setelah Tabel 10), sebelum §7.2.12 (teknik pemrograman TM).

**Mengapa penting:**
- Outline §3.4.3 mencantumkan teorema ini secara eksplisit.
- Teorema ini adalah dasar argumen undecidability standar HMU §9.3.
- Catatan §7.2.11 sudah punya perbedaan RE/Recursive yang baik, tetapi teorema
  komplemen tidak disebutkan sama sekali.

**Yang harus ditambahkan (satu paragraf + satu baris rumus):**

```
Teorema (Komplemen RE):
Jika L ∈ RE dan L̄ ∈ RE, maka L ∈ Recursive.
Kontrapositif: Jika L ∈ RE tetapi L ∉ Recursive, maka L̄ ∉ RE.
```

Tambahkan implikasi langsung: "Penerapan untuk L_d dan L_u: L_d bukan RE
(dibuktikan lewat diagonalisasi, §7.2.18). Karena L_u = L̄_d, dan L_u ∈ RE
(UTM menerima semua (M,w) yang valid), maka ini konsisten — L_u RE tetapi
undecidable, L_d bukan RE."

---

### A.5 — TAMBAHKAN: Kompleksitas Konversi CNF per Tahap

**Lokasi target:** Di §6.2.5 atau dalam Komentar 6.2 (yang menyebut "grammar
dapat membesar"). Tambahkan tabel atau daftar poin dengan angka spesifik.

**Mengapa penting:**
- Outline §2.1.5 menyebutkan tiga angka kompleksitas secara eksplisit.
- Catatan saat ini hanya menyebut "grammar dapat membesar" tanpa angka.
- Soal analitik tentang biaya preprocessing sebelum CYK tidak dapat dijawab.

**Yang harus ditambahkan (tabel tiga baris atau bullet list):**

| Tahap Konversi | Kompleksitas |
|----------------|-------------|
| Generating & reachable symbol cleanup | O(|G|) — linear terhadap ukuran grammar |
| Unit-pair computation | O(n²) — kuadratik terhadap jumlah variabel |
| Ukuran grammar hasil CNF | O(n²) dalam kasus umum |

Tambahkan catatan: "Blow-up O(n²) terutama dari eliminasi nullable symbols yang
melipat-gandakan jumlah produksi bila tidak dikendalikan dengan pemecahan body."

---

## BAGIAN B — DIRECTIVES PRIORITAS SEDANG

> Kerjakan Bagian B hanya setelah Bagian A selesai, dan jika masih ada kapasitas
> pengeditan. Urutan B.1 → B.2 → B.3.

---

### B.1 — TAMBAHKAN: Tiga Syarat Formal LL(1) dari Dragon Book

**Lokasi target:** §10.2.6 (setelah pembahasan konflik Tabel 24).

**Yang harus ditambahkan:**
Rumus tiga kondisi formal Dragon Book §4.4.3:
1. `FIRST(α) ∩ FIRST(β) = ∅` untuk setiap dua alternatif `A → α | β`.
2. Paling banyak satu alternatif `A → α` yang dapat menurunkan `ε`.
3. Jika ada `α` nullable, maka `FIRST(α_lain) ∩ FOLLOW(A) = ∅`.

Tambahkan catatan: "Soal UAS sering meminta 'buktikan grammar ini LL(1)':
cukup hitung FIRST dan FOLLOW, lalu verifikasi ketiga kondisi di atas."

---

### B.2 — TAMBAHKAN: Constant Folding dan CSE di Tabel Optimasi IR

**Lokasi target:** §11.2.11 atau Tabel 32 (tabel teknik optimasi IR).

**Yang harus ditambahkan (dua baris baru di tabel):**

| Teknik | Deskripsi | Contoh |
|--------|-----------|--------|
| Constant Folding | Evaluasi ekspresi konstanta saat compile-time | `2+3 → 5`, `x*1 → x` |
| Common Subexpression Elimination (CSE) | Jika `a+b` dihitung >1× tanpa perubahan a atau b, simpan ke temporary | `t = a+b; ... t; ... t` alih-alih hitung ulang |

---

### B.3 — TAMBAHKAN: Teknik Marker/Shifting-Over untuk TM

**Lokasi target:** §7.2.12 (Teknik Pemrograman TM), setelah storage in state.

**Yang harus ditambahkan (satu paragraf):**
"Marker/Shifting-Over: Tandai posisi di tape dengan simbol khusus (misalnya X, Y,
atau ★) untuk merekam progress pembacaan tanpa menghapus input asli. Teknik
shifting-over berguna untuk menyisipkan simbol di tengah tape: geser semua simbol
ke kanan satu posisi, lalu tulis simbol baru di posisi yang kosong. Banyak konstruksi
TM untuk bahasa seperti `{ww^R}` atau fungsi aritmatika mengandalkan teknik ini."

---

## BAGIAN C — DIRECTIVES KONDISIONAL (Compiler/RDP/LL1/IR/VM)

> **Kerjakan Bagian C HANYA JIKA ada konfirmasi eksplisit dari dosen atau syllabus
> resmi bahwa topik Compiler/RDP/LL(1)/IR/VM masuk dalam lingkup soal UAS.**
>
> Jika tidak ada konfirmasi, SKIP seluruh Bagian C.

Jika dikonfirmasi, kerjakan dalam urutan prioritas berikut:

**C.1 — TAMBAHKAN: Subseksi Postfix Notation di §11 (IR)**
Lokasi: Sebelum §11.2.5 (3AC). Konten: definisi postfix; konversi ekspresi
aritmetika `a+b*c` ke postfix; semantik BZ (branch if zero/false) dan BR
(unconditional branch) untuk if/while; trace evaluasi stack 5 langkah
untuk ekspresi sederhana `3 4 + 2 *`.

**C.2 — TAMBAHKAN: Subbagian Error Handling di §8 (Compiler)**
Lokasi: Sebelum §8.2.8 (Lexical Analysis). Konten: tiga "reaksi yang dilarang"
(crash, infinite loop, corrupt output); tabel 5 strategi recovery (panic mode,
unit deletion, terminal repair, context-sensitive, spelling repair); konsep
dummy identifier — "jika identifier `x` tidak dideklarasikan, masukkan ke symbol
table dengan tipe dummy agar semantic analysis tidak cascade error."

**C.3 — TAMBAHKAN: Code Generation Techniques di §8.2 (Code Gen)**
Lokasi: Perluas §8.2.19–8.2.20. Konten: (a) instruction selection — pemetaan
pola IR ke instruksi target; (b) interference graph untuk register allocation —
"buat graf konflik, warnai dengan k warna (jumlah register tersedia), spill
variabel tanpa warna ke memory"; (c) peephole optimization — "lihat jendela
3–5 instruksi, hapus pola redundan seperti `mov r0, r0` atau pasangan
`store r0, M` diikuti `load r0, M`."

**C.4 — TAMBAHKAN: Algoritma Formal General Left Recursion di §9 (RDP)**
Lokasi: Perluas Komentar 9.3. Konten: algoritma dua-loop eliminasi rekursi kiri
tidak langsung dari Aho et al.; contoh konkret dengan dua nonterminal
`A₁ → A₂ α` dan `A₂ → A₁ β`.

---

## BAGIAN D — YANG HARUS DIPERTAHANKAN — JANGAN DIUBAH

Bagian-bagian berikut sudah sangat kuat berdasarkan evaluasi. **Jangan modifikasi
kecuali ada instruksi eksplisit lain:**

- **§10 LL(1) Parser (keseluruhan):** Section terkuat dalam catatan. FIRST, FOLLOW,
  tabel parsing, trace parsing, error recovery, synch entries — semua ada dan kuat.
  Hanya tambahkan syarat formal (B.1) tanpa mengubah struktur yang ada.

- **§6 CYK + CNF (keseluruhan):** Sangat kuat. Tidak ada perubahan struktural,
  hanya tambahkan kompleksitas konversi (A.5).

- **§5 PDA — Konstruksi, ID, Acceptance Modes, Closure Properties:** Semua kuat.
  Hanya tambahkan komentar walkthrough soal UAS (A.2).

- **§7 TM Undecidability — PCP, Rice, L_d, L_u:** Lengkap dan tepat. Pertahankan.

- **§12 VM/Interpreter (keseluruhan):** Cukup lengkap untuk topik yang ada.

---

## MATRIKS PRIORITAS GABUNGAN

| Topik UAS | Frekuensi Historis | Status Catatan | Tindakan yang Diperlukan | Prioritas |
|-----------|-------------------|----------------|--------------------------|-----------|
| CFG Design | 81% (13/16) | Lengkap | — (opsional: tambah latihan soal) | Latihan |
| CFG → PDA | 69% (11/16) | Lengkap | Tambah walkthrough soal UAS | **A.2 WAJIB** |
| PDA Design | 63% (10/16) | Lengkap | — (opsional: tambah latihan soal) | Latihan |
| CYK Algorithm | 50% (8/16) | Sangat Lengkap | — | Tidak perlu |
| CNF Conversion | 50% (8/16) | Lengkap | Tambah kompleksitas per tahap | **A.5 WAJIB** |
| PDA → CFG | 44% (7/16) | Lengkap | Tambah walkthrough soal UAS | **A.2 WAJIB** |
| Derivasi/Parse Tree | 31% (5/16) | Sebagian | Tambah walkthrough + ambiguity | **A.3 WAJIB** |
| FS ↔ ES Konversi | 19% (3/16) | Lengkap | — | Tidak perlu |
| TM Design/Trace | 19% (3/16) | **GAP KRITIS** | Tambah trace + unary encoding | **A.1 WAJIB** |
| Ambiguous Grammar | 19% (3/16) | Sebagian | Dicakup di A.3 | **A.3 WAJIB** |
| Teorema Komplemen RE | n/a | Belum Ada | Tambah teorema + rumus | **A.4 WAJIB** |
| Kompleksitas CNF | n/a | Belum Ada | Tambah tabel kompleksitas | **A.5 WAJIB** |
| Syarat formal LL(1) | n/a | Sebagian | Tambah 3 kondisi Dragon Book | B.1 Sedang |
| Constant Folding/CSE | n/a | Belum Ada | Tambah di Tabel 32 | B.2 Sedang |
| Marker/Shifting TM | n/a | Belum Ada | Tambah paragraf di §7.2.12 | B.3 Sedang |
| Postfix IR | 0% historis | Dangkal | HANYA jika dikonfirmasi UAS | C.1 Kondisional |
| Error Handling Compiler | 0% historis | Belum Ada | HANYA jika dikonfirmasi UAS | C.2 Kondisional |
| Code Generation Lanjut | 0% historis | Belum Ada | HANYA jika dikonfirmasi UAS | C.3 Kondisional |
| General Left Recursion | 0% historis | Sebagian | HANYA jika dikonfirmasi UAS | C.4 Kondisional |

---

## CATATAN TEKNIS UNTUK AI YANG MENGUPDATE

1. **Jangan hapus konten yang sudah ada** kecuali ada instruksi eksplisit.
   Semua direktif di atas bersifat TAMBAHAN atau MODIFIKASI minor pada yang ada.

2. **Pertahankan gaya penulisan catatan asli:**
   - Formal, tiga-bagian per section (outline fundamental → penjelasan konsep → algoritma/rumus)
   - Penggunaan `Komentar X.Y` untuk catatan "titik rawan pemahaman"
   - Numbering Tabel, Rumus, Pseudocode yang konsisten dan berlanjut

3. **Format untuk trace TM (A.1):** Gunakan tabel LaTeX `tabular` dengan kolom
   tetap. Jangan embed trace dalam paragraf prosa — trace dalam tabel jauh lebih
   mudah diikuti saat belajar.

4. **Format untuk komentar walkthrough soal UAS (A.2):** Gunakan format visual
   yang sama dengan §11.2.10 (box/callout terpisah dari alur konsep utama).
   Awali dengan label "⬛ CONTOH SOAL UAS" agar mudah diidentifikasi.

5. **Setelah semua update Bagian A selesai:** Perbarui daftar isi (jika ada)
   dan pastikan numbering subsection konsisten. Tidak perlu mengubah numbering
   section yang sudah ada — cukup sisipkan subseksi baru di posisi yang ditentukan.

6. **Verifikasi akhir:** Setelah semua perubahan, pastikan tidak ada referensi
   silang yang rusak (misalnya, §X.Y yang disebutkan di tempat lain tetapi
   nomornya berubah karena penyisipan).
