# CNF dan CYK Parser

---

### Hubungan dengan CPMK

> **CPMK 1 & 2** — CNF adalah "bentuk baku" CFG yang memudahkan analisis matematis dan komputasional. CYK adalah algoritma membership test paling efisien untuk CFL, langsung dibangun di atas struktur CNF.

---

### Outline Konsep Fundamental

- **Chomsky Normal Form (CNF)**
  - Definisi: hanya A→BC atau A→a
  - Manfaat: binary parse tree, prasyarat CYK
- **Konversi CFG → CNF**
  - Prasyarat: simplifikasi dulu
  - Langkah 1: isolasi terminal dari body panjang
  - Langkah 2: pecah produksi panjang menjadi biner
- **Algoritma CYK**
  - Tabel segitiga Xᵢⱼ
  - Pengisian basis (panjang 1)
  - Pengisian induktif (panjang ≥ 2)
  - Membaca hasil
  - Kompleksitas O(n³)

---

### Penjelasan Materi

---

#### Chomsky Normal Form (CNF)

**TL;DR:** *CNF adalah bentuk normal CFG di mana setiap produksi hanya berisi tepat 2 variabel atau 1 terminal — menghasilkan parse tree biner.*

CFG G = (V, T, P, S) berada dalam **Chomsky Normal Form** jika setiap produksi dalam P berbentuk **salah satu** dari:
- **A → BC** — tepat dua variabel (B, C ∈ V)
- **A → a** — tepat satu terminal (a ∈ T)

Tidak boleh ada:
- Produksi ε (kecuali S → ε jika ε ∈ L(G), dan S tidak muncul di ruas kanan manapun)
- Simbol useless
- Unit production

**Manfaat CNF:**

1. **Prasyarat CYK** — Algoritma CYK hanya bekerja pada CNF
2. **Parse tree biner** — Setiap internal node memiliki tepat 2 anak → struktur lebih sederhana dan dapat diprediksi
3. **Analisis matematis** — Parse tree dengan kedalaman m menghasilkan string maksimal panjang 2^(m-1), membantu pembuktian Pumping Lemma untuk CFL

---

#### Konversi CFG → CNF

**TL;DR:** *Lakukan simplifikasi dulu, lalu dua langkah konversi: isolasi terminal, kemudian pecah produksi panjang.*

**Prasyarat:** Grammar sudah disederhanakan (no ε-productions, no unit productions, no useless symbols).

**Langkah 1 — Isolasi terminal dari body panjang:**

Untuk setiap body dengan panjang ≥ 2 yang mengandung terminal `a`:
- Buat variabel baru: Tₐ
- Tambahkan produksi: Tₐ → a
- Ganti semua kemunculan `a` di body tersebut dengan Tₐ

Contoh:
```
A → aBC         →    A → TₐBC,   Tₐ → a
B → bC          →    B → TᵦC,    Tᵦ → b
```
*(Body panjang 1 A → a dibiarkan, tidak perlu diubah)*

**Langkah 2 — Pecah produksi panjang (≥ 3 simbol) menjadi biner:**

Untuk produksi A → B₁B₂B₃...Bₖ (k ≥ 3):
- Kenalkan variabel baru C₁, C₂, ..., C_{k-2}
- Buat kaskade:
  ```
  A  → B₁ C₁
  C₁ → B₂ C₂
  C₂ → B₃ C₃
  ...
  C_{k-2} → B_{k-1} Bₖ
  ```

Contoh:
```
A → BCDE
```
menjadi:
```
A  → B C₁
C₁ → C C₂
C₂ → D E
```

---

#### Algoritma CYK (Cocke-Younger-Kasami)

**TL;DR:** *CYK mengisi tabel segitiga bottom-up: setiap sel Xᵢⱼ berisi variabel yang bisa menurunkan substring dari posisi i ke j.*

**Prasyarat:** CFG harus dalam bentuk CNF.

**Setup:**

Untuk string input w = a₁a₂...aₙ:
- Bangun tabel dengan sel **Xᵢⱼ** = himpunan variabel A sedemikian A ⇒* aᵢaᵢ₊₁...aⱼ
- Tabel berbentuk segitiga: i dari 1..n, j dari i..n

**Visualisasi struktur tabel (n=4, "abcd"):**

```
        j=1   j=2   j=3   j=4
i=1  [ X₁₁ | X₁₂ | X₁₃ | X₁₄ ]  ← Baris atas (seluruh string)
i=2  [      | X₂₂ | X₂₃ | X₂₄ ]
i=3  [      |      | X₃₃ | X₃₄ ]
i=4  [      |      |      | X₄₄ ]  ← Baris bawah (satu karakter)
```

**Pengisian tabel — Basis (baris bawah, substring panjang 1):**

Untuk setiap posisi i dari 1 sampai n:
> X_{i,i} = { A | A → aᵢ ∈ P }
*(semua variabel yang memiliki produksi langsung ke terminal aᵢ)*

**Pengisian tabel — Induktif (substring panjang ≥ 2):**

Untuk substring dari posisi i ke j (panjang = j-i+1 ≥ 2):
Coba semua titik potong k di mana i ≤ k < j:

> X_{i,j} = { A | ∃ produksi A → BC, B ∈ X_{i,k}, C ∈ X_{k+1,j} }

Artinya: A bisa masuk ke Xᵢⱼ jika ada produksi A→BC di mana B bisa menurunkan bagian kiri (aᵢ...aₖ) dan C bisa menurunkan bagian kanan (aₖ₊₁...aⱼ).

**Urutan pengisian:**

Isi dari bawah ke atas, kiri ke kanan — sel hanya boleh diisi setelah semua sel yang dibutuhkan sudah terisi.

```
Isi: X₁₁, X₂₂, ..., Xₙₙ   (panjang 1)
lalu: X₁₂, X₂₃, ..., X_{n-1,n}  (panjang 2)
lalu: X₁₃, X₂₄, ...         (panjang 3)
...
akhir: X₁ₙ                  (seluruh string)
```

**Membaca hasil:**

> String w diterima oleh G ⟺ **S ∈ X₁ₙ**

*(Start symbol S muncul di sel paling atas yang mencakup seluruh string)*

**Kompleksitas:**
- Jumlah sel: O(n²)
- Setiap sel dievaluasi dengan mencoba O(n) titik potong
- Total: **O(n³)**

---

#### Contoh CYK

Grammar (CNF):
```
S → AB | BC
A → BA | a
B → CC | b
C → AB | a
```

Input: `baaba` (n=5)

| | b | a | a | b | a |
|---|---|---|---|---|---|
| **b** | {B} | | | | |
| **a** | {A,C} | {A,C} | | | |
| **a** | {A,C} | {A,C} | | | |
| **b** | ... | ... | ... | {B} | |
| **a** | ... | ... | ... | ... | {A,C} |

*(Isi sel baris atas dari kombinasi sel di bawahnya — jika S ∈ X₁₅, string diterima)*

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **CNF** | Bentuk normal CFG: semua produksi A→BC atau A→a |
| **Binary parse tree** | Parse tree di CNF: setiap interior node punya tepat 2 anak |
| **Konversi ke CNF** | Simplifikasi → isolasi terminal → pecah produksi panjang |
| **CYK Algorithm** | DP membership test untuk CNF; tabel segitiga bottom-up |
| **Xᵢⱼ** | Sel CYK: himpunan variabel yang bisa menurunkan substring aᵢ...aⱼ |
| **Titik potong k** | Pemisahan substring dalam CYK: Xᵢⱼ ← Xᵢₖ × Xₖ₊₁,ⱼ |
| **Basis CYK** | X_{i,i} = variabel yang punya produksi langsung ke aᵢ |
| **Induksi CYK** | X_{i,j} diisi dari pasangan (X_{i,k}, X_{k+1,j}) dan produksi A→BC |
| **Hasil CYK** | S ∈ X₁ₙ → string diterima |
| **Kompleksitas CYK** | O(n³) untuk string panjang n |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Definisi CNF: hanya A→BC atau A→a
- [x] Manfaat CNF: binary tree, prasyarat CYK
- [x] Konversi ke CNF: langkah isolasi terminal
- [x] Konversi ke CNF: langkah pecah produksi panjang
- [x] Algoritma CYK: struktur tabel Xᵢⱼ
- [x] CYK basis: isi dari terminal
- [x] CYK induksi: isi dari titik potong k
- [x] CYK membaca hasil: S ∈ X₁ₙ
- [x] Kompleksitas O(n³)

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Konversi CFG → CNF (2 langkah) |
| 🔴 *Wajib dikuasai* | Algoritma CYK: cara mengisi tabel + membaca hasil |
| 🔴 *Wajib dikuasai* | Latihan CYK dengan contoh string (sangat sering disoalkan) |
| 🟡 *Cukup paham konsep* | Definisi CNF dan manfaatnya |
| 🟡 *Cukup paham konsep* | Kompleksitas O(n³) dan alasannya |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
