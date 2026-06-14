# Regular Language

> ✅ *Materi ini sudah dikuasai secara dasar. File ini berfungsi sebagai review cepat dan referensi terminologi untuk materi selanjutnya.*

---

### Hubungan dengan CPMK

> **CPMK 1 & 2** — Materi ini membangun fondasi formal: memahami notasi otomaton (DFA/NFA/ε-NFA) dan Regular Expression sebagai bahasa formal paling sederhana dalam hierarki Chomsky. Kemampuan merancang dan mengonversi automaton langsung diuji di CPMK 2.

---

### Outline Konsep Fundamental

- **Finite Automata**
  - DFA — deterministic, satu state tujuan per transisi
  - NFA — non-deterministic, himpunan state tujuan per transisi
  - ε-NFA — NFA dengan transisi spontan (ε)
- **Regular Expression (RE)**
  - Basis: ε, ∅, simbol terminal `a`
  - Operator: Union, Concatenation, Kleene Star
- **Konversi Antar Representasi**
  - NFA → DFA: Subset Construction
  - ε-NFA → DFA: Subset Construction + ECLOSE
  - RE → ε-NFA: Structural Induction (Thompson Construction)
  - DFA → RE: State Elimination
- **Ekuivalensi:** DFA = NFA = ε-NFA = RE = Regular Language
- **Aplikasi:** Lexical Analyzer, Text Search

---

### Penjelasan Materi

---

#### DFA (Deterministic Finite Automaton)

**TL;DR:** *Mesin abstrak dengan state terbatas yang membaca string simbol demi simbol secara deterministik.*

DFA didefinisikan secara formal sebagai **5-tuple** A = (Q, Σ, δ, q₀, F) di mana:

- **Q** — himpunan state berhingga
- **Σ** — himpunan simbol input (alphabet) berhingga
- **δ** — fungsi transisi: δ: Q × Σ → Q
- **q₀ ∈ Q** — start state
- **F ⊆ Q** — himpunan accepting states (final states)

**Fungsi transisi δ** menerima *satu state* dan *satu simbol input*, lalu mengembalikan tepat *satu state* tujuan. Sifat ini yang membuatnya *deterministik*.

**Fungsi δ̂ (extended transition function)** memperluas δ untuk memproses seluruh string sekaligus:
- **Basis:** δ̂(q, ε) = q *(string kosong tidak mengubah state)*
- **Induktif:** untuk w = xa (x adalah string, a adalah simbol terakhir):
  δ̂(q, w) = δ(δ̂(q, x), a)

**Cara kerja DFA:**
1. Mulai dari start state q₀
2. Baca string input simbol demi simbol
3. Ikuti transisi δ untuk setiap simbol
4. Setelah semua simbol dibaca: jika state akhir ∈ F → string **diterima**; jika tidak → **ditolak**

---

#### NFA (Nondeterministic Finite Automaton)

**TL;DR:** *Seperti DFA tetapi fungsi transisinya bisa mengembalikan banyak state sekaligus — string diterima jika ada minimal satu jalur yang berhasil.*

NFA juga didefinisikan sebagai **5-tuple** A = (Q, Σ, δ, q₀, F) — strukturnya identik dengan DFA.

**Perbedaan utama dengan DFA terletak pada fungsi transisi δ:**

| | DFA | NFA |
|---|---|---|
| δ: | Q × Σ → Q | Q × Σ → 2^Q |
| Satu input → | tepat satu state | himpunan state (bisa kosong ∅) |
| Tidak ada transisi → | tidak mungkin (harus ada) | mengembalikan ∅ |
| String diterima jika | state akhir ∈ F | *setidaknya satu* jalur berakhir di F |

NFA secara konseptual "memilih" jalur terbaik secara non-deterministik. Dalam implementasi, ini dimodelkan dengan menjelajahi *semua* jalur secara paralel.

---

#### ε-NFA

**TL;DR:** *NFA yang boleh bertransisi ke state lain tanpa membaca simbol input apapun — menggunakan transisi ε (epsilon).*

ε-NFA adalah NFA dengan kemampuan **transisi spontan**: dari satu state bisa berpindah ke state lain tanpa mengonsumsi simbol input. Secara formal, fungsi transisinya mengambil argumen dari Σ ∪ {ε}.

**ECLOSE (ε-closure):**

ECLOSE(q) = himpunan semua state yang dapat dicapai dari q *hanya* melalui transisi ε (tanpa membaca simbol apapun).

**Cara menghitung ECLOSE(q):**
- **Basis:** q ∈ ECLOSE(q) *(state itu sendiri selalu masuk)*
- **Induksi:** Jika p ∈ ECLOSE(q) dan δ(p, ε) mengandung state r, maka r ∈ ECLOSE(q)
- Ulangi sampai tidak ada state baru yang bisa ditambahkan (*fixed point*)

**Contoh:**
Jika state 1 →ε→ 2 →ε→ 3, maka ECLOSE(1) = {1, 2, 3}

---

#### Subset Construction (NFA → DFA dan ε-NFA → DFA)

**TL;DR:** *Algoritma untuk mengonversi NFA/ε-NFA ke DFA dengan menjadikan setiap himpunan state NFA sebagai satu state DFA.*

**Konversi NFA → DFA:**

- **Start state DFA:** {q₀} *(himpunan berisi start state NFA)*
- **Accepting state DFA:** semua subset yang mengandung ≥1 accepting state NFA
- **Fungsi transisi DFA:** δ_D(S, a) = ∪_{q∈S} δ_N(q, a)
  *(gabungan semua state NFA yang dicapai dari setiap elemen S dengan input a)*
- Setiap subset yang ditemukan menjadi state DFA baru — lanjutkan hingga tidak ada subset baru

**Konversi ε-NFA → DFA:**

Sama seperti di atas, tetapi dengan dua modifikasi:
- **Start state DFA:** ECLOSE(q₀)
- **Fungsi transisi DFA:** δ_D(S, a) = ECLOSE(∪_{q∈S} δ(q, a))
  *(hitung transisi biasa, lalu kenakan ECLOSE pada hasilnya)*

---

#### Regular Expression (RE)

**TL;DR:** *Notasi aljabar kompak untuk mendeskripsi pola string menggunakan tiga operator dasar.*

**Definisi rekursif RE:**

*Basis case:*
- ε adalah RE (merepresentasikan bahasa {ε})
- ∅ adalah RE (merepresentasikan bahasa kosong)
- Setiap simbol terminal `a ∈ Σ` adalah RE (merepresentasikan bahasa {a})

*Recursive case* — jika E dan F adalah RE, maka:
- **E | F** (Union) — string yang cocok dengan E *atau* F
- **EF** (Concatenation) — string E diikuti string F
- **E\*** (Kleene Star) — string E diulang nol atau lebih kali

**Konversi RE → ε-NFA (Thompson Construction / Structural Induction):**

Setiap sub-ekspresi RE diubah menjadi ε-NFA dengan *tepat satu start state* dan *satu accepting state*, lalu digabungkan sesuai operatornya:

- **Basis:** Buat NFA trivial dengan 2 state: start →a→ accept
- **Union (R|S):**
  - Buat start state baru dengan transisi ε ke start_R dan start_S
  - Buat accepting state baru dengan transisi ε dari accept_R dan accept_S
- **Concatenation (RS):**
  - Gabungkan accept_R dengan start_S (atau tambahkan transisi ε di antara keduanya)
- **Kleene Star (R\*):**
  - Buat start dan accepting state baru
  - Transisi ε: start_baru → start_R (mulai iterasi)
  - Transisi ε: start_baru → accept_baru (0 kali pengulangan)
  - Transisi ε: accept_R → start_R (loop untuk pengulangan)
  - Transisi ε: accept_R → accept_baru (selesai)

---

#### Konversi DFA → RE (State Elimination)

**TL;DR:** *Hapus state DFA satu per satu dan kompensasi penghapusan dengan menulis ulang label transisi sebagai RE.*

**Prosedur State Elimination:**

1. Tambahkan start state baru (q_s) dengan ε ke start state asli
2. Tambahkan accepting state baru (q_f) dengan ε dari semua accepting state asli
3. **Eliminasi state** satu per satu (kecuali q_s dan q_f):
   - Untuk setiap predecessor q dan successor p dari state s yang dieliminasi:
   - Jika label q→s = Q, loop s→s = S, label s→p = P, dan busur langsung q→p = R:
   - Label busur baru q→p = **R | QS\*P**
4. Ulangi sampai hanya tersisa q_s dan q_f
5. Label pada busur q_s → q_f adalah RE yang mewakili bahasa DFA

---

#### Aplikasi Regular Language

**TL;DR:** *Regular Language bukan hanya teori — ia digunakan langsung di kompiler (lexer) dan pencarian teks.*

**Lexical Analyzer (Lexer):**
- Bagian pertama dari kompiler yang men-*scan* source code
- Tugasnya: mengenali **tokens** (identifier, angka, keyword, operator)
- Setiap kategori token didefinisikan oleh RE, lalu dikonversi ke DFA
- DFA tersebut kemudian dijalankan untuk menentukan token dari setiap potongan teks

**Text Search:**
- Mesin regex (seperti `grep`, regex di Python/Java) bekerja berdasarkan prinsip yang sama
- Pola pencarian ditulis sebagai RE → dikompilasi ke NFA/DFA → dijalankan pada teks
- Efisiensi pencarian bergantung pada bagaimana implementasi mengelola NFA vs DFA

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **DFA** | 5-tuple (Q,Σ,δ,q₀,F); δ: Q×Σ→Q (satu state tujuan) |
| **NFA** | 5-tuple sama; δ: Q×Σ→2^Q (himpunan state tujuan) |
| **ε-NFA** | NFA dengan transisi spontan ε tanpa membaca simbol |
| **δ̂ (delta-hat)** | Extended transition function untuk memproses string penuh |
| **ECLOSE(q)** | Semua state yang dicapai dari q hanya via transisi ε |
| **Subset Construction** | Algoritma konversi NFA/ε-NFA → DFA |
| **RE** | Ekspresi reguler: ε, ∅, terminal, dan operator |, concat, * |
| **Thompson Construction** | Konversi RE → ε-NFA via structural induction |
| **State Elimination** | Konversi DFA → RE dengan menghapus state satu per satu |
| **Accepting state** | State di mana string dianggap diterima (∈ F) |
| **Lexer / Lexical Analyzer** | Komponen kompiler yang mengenali token menggunakan RE/DFA |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Definisi formal DFA (5-tuple, δ, δ̂)
- [x] Definisi formal NFA dan perbedaannya dengan DFA
- [x] ε-NFA dan konsep ECLOSE
- [x] Subset Construction (NFA→DFA dan ε-NFA→DFA)
- [x] Regular Expression: definisi rekursif dan operator
- [x] Thompson Construction (RE→ε-NFA)
- [x] State Elimination (DFA→RE)
- [x] Aplikasi: Lexical Analyzer dan Text Search

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Definisi formal DFA & NFA, δ̂, Subset Construction, ECLOSE |
| 🔴 *Wajib dikuasai* | State Elimination (DFA→RE), Thompson Construction (RE→ε-NFA) |
| 🟡 *Cukup paham konsep* | Aplikasi Lexical Analyzer & Text Search |
| ✅ *Sudah dikuasai* | Konsep dasar DFA/NFA/ε-NFA, ekuivalensi model |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
