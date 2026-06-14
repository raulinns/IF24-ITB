# Parse Tree dan Conversion

---

### Hubungan dengan CPMK

> **CPMK 1 & 2** — Parse tree adalah representasi visual dari struktur sintaksis yang dihasilkan CFG. Memahami parse tree dan korelasinya dengan derivasi adalah kunci untuk materi ambiguitas, CNF, dan parser.

---

### Outline Konsep Fundamental

- **Definisi Parse Tree**
  - Struktur node: akar, interior node, daun
  - Aturan pelabelan
- **Yield dari Parse Tree**
  - Cara membaca string dari parse tree
  - Parse tree yang "penting" (important parse tree)
- **Hubungan Parse Tree ↔ Derivasi**
  - Satu parse tree ↔ tepat satu leftmost derivation
  - Satu parse tree ↔ tepat satu rightmost derivation
- **Konversi**
  - Derivasi → Parse Tree
  - Parse Tree → Derivasi (leftmost/rightmost)
- **Teorema Ekuivalensi**

---

### Penjelasan Materi

---

#### Definisi Parse Tree

**TL;DR:** *Parse tree adalah pohon yang merepresentasikan struktur sintaksis sebuah string — setiap node menunjukkan bagaimana produksi CFG diterapkan.*

Parse tree adalah struktur pohon yang memiliki aturan pelabelan berikut:

- **Akar (root):** dilabeli oleh *Start Symbol* S
- **Interior node (simpul dalam):** dilabeli oleh *Variable* (non-terminal) ∈ V
- **Daun (leaf):** dilabeli oleh simbol dari T ∪ V ∪ {ε}
  - Jika sebuah daun dilabeli ε, maka daun itu adalah **satu-satunya** anak dari parent-nya

**Aturan ekspansi:** Jika interior node A memiliki anak-anak X₁, X₂, ..., Xₖ (dari kiri ke kanan), maka A → X₁X₂...Xₖ harus merupakan produksi dalam P.

**Visualisasi:**
```
          S
        / | \
       a  A  b
         / \
        a    b
```
*(Contoh parse tree untuk grammar S → aAb, A → ab, menghasilkan "aabb")*

---

#### Yield dari Parse Tree

**TL;DR:** *Yield adalah string yang terbentuk dengan membaca semua daun parse tree dari kiri ke kanan.*

Yield dari sebuah parse tree = string yang didapat dari membaca semua **daun** secara berurutan **dari kiri ke kanan**.

**Parse tree yang "penting" (important parse tree):**
Sebuah parse tree dianggap penting jika:
1. Yield-nya hanya terdiri dari **terminal** (tidak ada variabel)
2. Akarnya dilabeli oleh **Start Symbol** S

Himpunan semua yield dari parse tree yang penting inilah yang membentuk **L(G)**.

---

#### Hubungan Parse Tree ↔ Derivasi

**TL;DR:** *Satu parse tree mewakili banyak urutan derivasi yang berbeda, tapi hanya satu leftmost dan satu rightmost derivation.*

Sebuah string dapat memiliki banyak cara derivasi (urutannya berbeda), namun satu parse tree **mengelompokkan** semua urutan tersebut menjadi satu struktur tunggal.

**Korespondensi kritis:**

> **Satu parse tree** ↔ **tepat satu leftmost derivation**
> **Satu parse tree** ↔ **tepat satu rightmost derivation**

Sebaliknya:
> **Lebih dari satu parse tree** untuk string w yang sama → **Grammar ambigu**

Ini adalah jembatan konseptual ke materi Ambiguitas berikutnya.

---

#### Konversi Parse Tree ↔ Derivasi

**TL;DR:** *Konversi dua arah: dari pohon ke urutan langkah derivasi, dan sebaliknya.*

**Dari Derivasi → Parse Tree:**

Gunakan induksi pada panjang derivasi:
1. Mulai dari node S (akar)
2. Setiap kali digunakan produksi A → X₁X₂...Xₖ, buat node A dengan anak-anak X₁, X₂, ..., Xₖ (kiri ke kanan)
3. Untuk setiap Xᵢ yang berupa variabel, lanjutkan rekursif
4. Untuk Xᵢ yang terminal → jadikan daun

**Dari Parse Tree → Leftmost Derivation:**

Telusuri pohon secara pre-order (kiri ke kanan, atas ke bawah):
1. Di setiap langkah, ekspansi **variabel paling kiri** dalam sentential form saat ini
2. Ekspansi = ubah variabel tersebut menjadi anak-anaknya dalam pohon
3. Lanjutkan sampai tidak ada variabel tersisa

**Properti penting:** Proses ini memanfaatkan sifat *context-free*: cara menurunkan suatu variabel tidak dipengaruhi oleh string di kiri maupun kanannya.

---

#### Teorema Ekuivalensi

**TL;DR:** *Empat cara mendefinisikan keanggotaan string dalam L(G) semuanya ekuivalen.*

Untuk CFG G = (V, T, P, S) dan string w ∈ T*, pernyataan-pernyataan berikut **ekuivalen satu sama lain**:

1. w dapat dibuktikan keanggotaannya via **inferensi rekursif** (bottom-up)
2. w dapat diturunkan dari S: **S ⇒* w** (derivasi)
3. w memiliki **leftmost derivation**: S ⇒*_lm w
4. w memiliki **rightmost derivation**: S ⇒*_rm w
5. Ada **parse tree** dengan akar S dan yield w

Artinya: untuk membuktikan w ∈ L(G), cukup gunakan salah satu dari lima metode di atas — hasilnya pasti sama.

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **Parse tree** | Pohon representasi sintaksis string; akar = S, interior = variabel, daun = terminal/ε |
| **Yield** | String yang dibentuk dari membaca daun parse tree dari kiri ke kanan |
| **Interior node** | Node bukan daun; dilabeli variabel ∈ V |
| **Important parse tree** | Parse tree dengan akar S dan yield murni terminal |
| **Korespondensi** | 1 parse tree ↔ 1 leftmost derivation ↔ 1 rightmost derivation |
| **Ambiguitas (petunjuk awal)** | Jika ada ≥2 parse tree untuk string w yang sama → grammar ambigu |
| **Teorema ekuivalensi** | Inferensi rekursif = derivasi = leftmost der. = rightmost der. = parse tree |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Definisi parse tree: struktur akar, interior node, daun
- [x] Aturan pelabelan (dan aturan khusus untuk daun ε)
- [x] Yield dari parse tree
- [x] Important parse tree dan hubungannya dengan L(G)
- [x] Korespondensi satu parse tree ↔ satu leftmost derivation
- [x] Konversi derivasi → parse tree
- [x] Konversi parse tree → leftmost derivation
- [x] Teorema ekuivalensi (5 cara yang ekuivalen)

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Definisi parse tree + aturan pelabelan |
| 🔴 *Wajib dikuasai* | Yield + korespondensi parse tree ↔ derivasi |
| 🔴 *Wajib dikuasai* | Bisa membangun parse tree dari derivasi (dan sebaliknya) |
| 🟡 *Cukup paham konsep* | Teorema ekuivalensi (5 cara ekuivalen) |
| 🟡 *Cukup paham konsep* | Properti context-free pada konversi |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
