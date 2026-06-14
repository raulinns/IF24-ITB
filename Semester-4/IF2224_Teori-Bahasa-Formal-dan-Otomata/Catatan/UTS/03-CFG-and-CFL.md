# Context Free Grammar (CFG) dan Context Free Language (CFL)

---

### Hubungan dengan CPMK

> **CPMK 1 & 2** — CFG adalah fondasi seluruh materi CFL. CPMK 1: memahami notasi dan konsep formal grammar. CPMK 2: merancang CFG untuk bahasa tertentu dan memahami hubungannya dengan Pushdown Automata.

---

### Outline Konsep Fundamental

- **Definisi Formal CFG**
  - 4-tuple: Variables, Terminals, Productions, Start Symbol
  - Notasi produksi (head → body)
- **Derivasi**
  - Derivasi satu langkah (⇒) dan banyak langkah (⇒*)
  - Leftmost Derivation vs Rightmost Derivation
  - Sentential form vs Sentence
- **Context Free Language (CFL)**
  - Definisi L(G)
  - Inferensi rekursif (bottom-up)
- **Contoh CFG**
  - Bahasa {aⁿbⁿ}
  - Palindrom
- **Hubungan CFG ↔ PDA**

---

### Penjelasan Materi

---

#### Definisi Formal CFG

**TL;DR:** *CFG adalah sistem aturan penggantian simbol yang secara rekursif mendefinisikan suatu bahasa.*

Context-Free Grammar didefinisikan sebagai **4-tuple G = (V, T, P, S)** dengan komponen:

- **V** — himpunan berhingga *Variables* (non-terminal): merepresentasikan kategori sintaksis atau kelas string
- **T** — himpunan berhingga *Terminals*: simbol-simbol dasar yang membentuk string aktual (V ∩ T = ∅)
- **P** — himpunan berhingga *Productions* (aturan produksi): setiap produksi berbentuk **A → α** di mana:
  - *head* A ∈ V (tepat satu variabel)
  - *body* α ∈ (V ∪ T)* (string dari variabel dan/atau terminal, boleh ε)
- **S ∈ V** — *Start Symbol*: titik awal terbentuknya semua string dalam bahasa

**Notasi shorthand:** Beberapa produksi dengan head yang sama dapat digabung menggunakan `|`:
```
A → α₁ | α₂ | α₃
```
artinya A → α₁, A → α₂, A → α₃

---

#### Derivasi

**TL;DR:** *Derivasi adalah proses menghasilkan string dengan mengganti variabel menggunakan aturan produksi, satu langkah demi satu langkah.*

**Derivasi satu langkah (⇒):**
Jika A → β adalah produksi dalam P, dan αAγ adalah string, maka:
> αAγ ⇒ αβγ

Satu variabel A diganti dengan body β-nya.

**Derivasi banyak langkah (⇒*):**
Penutupan refleksif-transitif dari ⇒ — artinya nol, satu, atau lebih langkah derivasi berturut-turut.
- α ⇒* α *(nol langkah — setiap string bisa menurunkan dirinya sendiri)*
- Jika α ⇒ β dan β ⇒* γ, maka α ⇒* γ

**Leftmost vs Rightmost Derivation:**

| | Leftmost (⇒lm) | Rightmost (⇒rm) |
|---|---|---|
| **Aturan** | Selalu ganti variabel paling **kiri** | Selalu ganti variabel paling **kanan** |
| **Notasi** | ⇒lm | ⇒rm |
| **Relevansi** | Digunakan oleh top-down parser (LL) | Digunakan oleh bottom-up parser (LR) |

Penting: Satu string yang sama bisa memiliki banyak derivasi biasa, tetapi hanya **satu** leftmost dan **satu** rightmost derivation untuk setiap parse tree.

**Sentential Form vs Sentence:**

- **Sentential form:** string apapun (campuran variabel + terminal) yang dapat diturunkan dari S:
  S ⇒* α, di mana α ∈ (V ∪ T)*
- **Sentence:** sentential form yang sudah *tidak mengandung variabel*, hanya terminal:
  S ⇒* w, di mana w ∈ T*

---

#### Context Free Language (CFL)

**TL;DR:** *CFL adalah himpunan semua sentence yang bisa dihasilkan oleh suatu CFG.*

Bahasa yang dihasilkan CFG G = (V, T, P, S) didefinisikan:

> **L(G) = { w ∈ T* : S ⇒*_G w }**

Semua string terminal yang dapat diturunkan dari start symbol S melalui satu atau lebih langkah derivasi.

Sebuah bahasa L disebut *context-free* jika ada CFG G sedemikian sehingga L = L(G).

**Inferensi rekursif (bottom-up):**

Alternatif cara membuktikan string w ∈ L(G) — bekerja dari bawah ke atas:
1. Kenali terminal-terminal sebagai hasil derivasi variabel dari produksi terpendek
2. Gabungkan secara bertahap menggunakan aturan produksi (body → head)
3. Jika akhirnya seluruh w dapat "diklaim" oleh S → w ∈ L(G)

Secara matematis, inferensi rekursif ekuivalen dengan derivasi dan parse tree.

---

#### Contoh-contoh CFG

**CFG untuk bahasa { aⁿbⁿ | n ≥ 1 }:**

```
A → aAb | ab
```

- Basis: A → ab (menghasilkan "ab", n=1)
- Rekursif: A → aAb (membungkus hasil rekursif dengan satu 'a' dan satu 'b')
- Contoh derivasi: A ⇒ aAb ⇒ aaAbb ⇒ aaabbb (menghasilkan a³b³)

*Catatan: bahasa ini bukan Regular Language — tidak bisa dibuat DFA karena perlu "mengingat" jumlah a yang sudah dibaca.*

**CFG untuk Palindrom di atas {0, 1}:**

```
P → ε | 0 | 1 | 0P0 | 1P1
```

- Basis: ε (string kosong), 0 (palindrom panjang 1), 1 (palindrom panjang 1)
- Rekursif: 0P0 (bungkus palindrom dengan 0 di kedua sisi), 1P1 (dengan 1)
- Contoh: P ⇒ 0P0 ⇒ 01P10 ⇒ 010 (palindrom)

---

#### Hubungan CFG ↔ PDA

**TL;DR:** *CFG dan PDA mendefinisikan kelas bahasa yang persis sama: Context-Free Languages.*

**Ekuivalensi:** L adalah CFL ⟺ L dikenali oleh PDA

- **CFG → PDA:** Untuk setiap CFG, bangun PDA yang mensimulasikan *leftmost derivation* CFG menggunakan stack. PDA menerima dengan *empty stack*.
- **PDA → CFG:** Untuk setiap PDA, ekstrak CFG dengan variabel berbentuk `[pXq]` yang merepresentasikan "PDA mulai di state p dengan X di atas stack, berakhir di state q dengan X ter-pop".

**PDA secara singkat:**
- Seperti DFA tetapi ditambah stack (memori tak terbatas tapi hanya bisa akses top)
- Dapat "mengingat" dan "menghitung" — kemampuan yang tidak dimiliki FA
- Oleh karena itu CFL lebih kuat dari Regular Language

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **CFG** | 4-tuple (V, T, P, S) — sistem aturan penggantian simbol |
| **Variable (non-terminal)** | Simbol dalam V; merepresentasikan kategori sintaksis |
| **Terminal** | Simbol dalam T; simbol dasar yang membentuk string aktual |
| **Production (A → α)** | Aturan: ganti variabel A dengan string α |
| **Start Symbol (S)** | Variabel awal tempat semua derivasi dimulai |
| **Derivasi (⇒)** | Proses mengganti satu variabel dengan body produksinya |
| **⇒*** | Penutupan refleksif-transitif: nol atau lebih langkah derivasi |
| **Leftmost derivation** | Selalu ganti variabel paling kiri |
| **Rightmost derivation** | Selalu ganti variabel paling kanan |
| **Sentential form** | String (V ∪ T)* yang dapat diturunkan dari S |
| **Sentence** | Sentential form yang hanya mengandung terminal |
| **L(G)** | Bahasa yang dihasilkan CFG G: semua sentence yang bisa diturunkan dari S |
| **CFL** | Bahasa yang dihasilkan oleh suatu CFG |
| **PDA** | Pushdown Automaton; FA + stack; ekuivalen dengan CFG |
| **Inferensi rekursif** | Pendekatan bottom-up untuk membuktikan string ∈ L(G) |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Definisi formal CFG sebagai 4-tuple (V, T, P, S)
- [x] Notasi produksi (A → α, shorthand dengan |)
- [x] Derivasi satu langkah (⇒) dan banyak langkah (⇒*)
- [x] Leftmost vs Rightmost Derivation
- [x] Sentential form vs Sentence
- [x] Definisi CFL: L(G) = { w ∈ T* : S ⇒* w }
- [x] Inferensi rekursif (bottom-up)
- [x] Contoh CFG: {aⁿbⁿ} dan Palindrom
- [x] Hubungan CFG ↔ PDA (ekuivalensi)

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Definisi formal CFG 4-tuple, notasi produksi |
| 🔴 *Wajib dikuasai* | Derivasi, leftmost vs rightmost |
| 🔴 *Wajib dikuasai* | Merancang CFG untuk bahasa sederhana (aⁿbⁿ, palindrom) |
| 🟡 *Cukup paham konsep* | Sentential form vs sentence |
| 🟡 *Cukup paham konsep* | Inferensi rekursif |
| 🟡 *Cukup paham konsep* | Hubungan CFG ↔ PDA |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
