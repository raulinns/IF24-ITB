# Properties of Context Free Language (CFL)

---

### Hubungan dengan CPMK

> **CPMK 1** — Materi ini menjelaskan batas dan kemampuan CFL: operasi apa yang aman dilakukan, dan keterbatasan CFL dibanding Regular Language. Simplifikasi CFG adalah prasyarat teknis untuk konversi ke CNF.

---

### Outline Konsep Fundamental

- **Simplifikasi CFG**
  - Eliminasi ε-productions (nullable variables)
  - Eliminasi unit productions (unit pairs)
  - Eliminasi useless symbols (non-generating, unreachable)
  - Urutan eksekusi yang benar
- **Closure Properties CFL**
  - Tertutup: Union, Concat, Kleene, Homomorphism, Reversal, Intersection dengan RL
  - Tidak tertutup: Intersection sesama CFL, Complement, Difference sesama CFL
- **Decision Properties**
  - Emptiness Test
  - Membership Test (→ CYK)

---

### Penjelasan Materi

---

#### Simplifikasi CFG

**TL;DR:** *Bersihkan grammar dari tiga jenis "sampah" sebelum menggunakannya lebih lanjut — urutan eliminasi sangat penting.*

Simplifikasi dilakukan untuk mempersiapkan CFG ke bentuk yang lebih bersih, terutama sebelum konversi ke CNF.

---

##### Eliminasi ε-productions

**ε-production:** Produksi berbentuk A → ε.

**Langkah-langkah:**

1. Temukan semua **nullable variables** — variabel yang bisa menurunkan ε:
   - Basis: Jika A → ε ada dalam P, maka A adalah nullable
   - Induksi: Jika A → B₁B₂...Bₖ dan semua Bᵢ nullable, maka A juga nullable
2. Untuk setiap produksi yang mengandung nullable variable, buat **semua kombinasi** baru dengan nullable variable tersebut ada atau tidak ada:
   - Contoh: Jika B nullable, A → αBγ → tambahkan A → αγ
3. Hapus semua produksi ε (kecuali S → ε jika ε ∈ L(G))

**Contoh:**
```
Sebelum: A → aBb, B → ε | c
B adalah nullable
Setelah: A → aBb | ab, B → c
```

---

##### Eliminasi Unit Productions

**Unit production:** Produksi berbentuk A → B (satu variabel ke satu variabel).

**Langkah-langkah:**

1. Temukan semua **unit pairs** (A, B) — pasangan di mana A dapat menurunkan B hanya menggunakan unit productions:
   - Basis: (A, A) selalu merupakan unit pair
   - Induksi: Jika (A, B) unit pair dan B → C ada, maka (A, C) juga unit pair
2. Untuk setiap unit pair (A, B) dan setiap produksi **non-unit** B → α:
   - Tambahkan produksi A → α
3. Hapus semua unit productions

---

##### Eliminasi Useless Symbols

**Useless symbol:** Simbol yang tidak pernah muncul dalam derivasi yang menghasilkan string terminal dari S.

Ada dua jenis, dieliminasi secara berurutan:

**Non-generating symbols** (evaluasi pertama):
- Simbol X *generating* jika X ⇒* w untuk suatu w ∈ T*
- Identifikasi dengan bottom-up: terminal selalu generating; variabel A generating jika ada produksi A → α di mana semua simbol dalam α generating
- Hapus semua simbol non-generating dan produksi yang memuatnya

**Unreachable symbols** (evaluasi kedua, setelah non-generating):
- Simbol X *reachable* jika S ⇒* αXβ untuk suatu α, β
- Identifikasi dengan BFS/DFS dari S
- Hapus semua simbol unreachable dan produksinya

---

##### Urutan Eksekusi yang Benar

**Urutan ini WAJIB diikuti:**

```
1. Eliminasi ε-productions
       ↓
2. Eliminasi unit productions
       ↓
3. Eliminasi useless symbols
   (a. non-generating dulu)
   (b. lalu unreachable)
```

Mengapa urutan ini penting? Mengeliminasi ε-production bisa menciptakan unit productions baru. Mengeliminasi unit productions bisa menciptakan useless symbols baru. Urutannya harus tepat agar hasil akhir benar-benar bersih.

---

#### Closure Properties CFL

**TL;DR:** *CFL tertutup terhadap operasi "konstruktif" (union, concat, dll.) tapi tidak tertutup terhadap intersection sesama CFL dan complement.*

**Tertutup (hasil operasi tetap CFL):**

| Operasi | Cara Membuktikan |
|---------|-----------------|
| **Union (L₁ ∪ L₂)** | Buat start symbol baru S → S₁ \| S₂ |
| **Concatenation (L₁·L₂)** | Buat S → S₁S₂ |
| **Kleene Star (L*)** | Buat S → SS₁ \| ε |
| **Homomorphism h(L)** | Terapkan h pada terminal di grammar |
| **Inverse Homomorphism h⁻¹(L)** | Konstruksi PDA |
| **Reversal (Lᴿ)** | Balik semua produksi (body dibaca terbalik) |
| **Intersection dengan RL (L ∩ R)** | Product construction PDA × DFA |
| **Difference dengan RL (L − R)** | L ∩ R̄ (R̄ adalah RL, karena complement RL adalah RL) |

**Tidak tertutup (hasil bisa bukan CFL):**

| Operasi | Contoh Kontraposisi |
|---------|---------------------|
| **Intersection sesama CFL (L₁ ∩ L₂)** | {aⁿbⁿcⁿ} = {aⁿbⁿcᵐ} ∩ {aᵐbⁿcⁿ}, keduanya CFL tapi hasilnya bukan CFL |
| **Complement (L̄)** | Jika CFL tertutup complement, maka juga tertutup intersection (DeMorgan) — kontradiksi |
| **Difference sesama CFL (L₁ − L₂)** | L₁ − L₂ = L₁ ∩ L̄₂ — tidak tertutup |

**Catatan penting:** CFL **tidak** tertutup terhadap intersection sesama CFL, tapi **tertutup** terhadap intersection dengan Regular Language. Ini sering menjadi soal jebakan.

---

#### Decision Properties

**TL;DR:** *Beberapa pertanyaan tentang CFL bisa dijawab algoritmik, termasuk apakah bahasa kosong dan apakah suatu string anggota bahasa.*

**Emptiness Test — Apakah L(G) = ∅?**

- Cek apakah S termasuk *generating symbols*
- Jika S generating → L(G) ≠ ∅ (ada string yang bisa dihasilkan)
- Jika S tidak generating → L(G) = ∅
- Kompleksitas: O(n²) naif, O(n) dengan struktur data khusus (array + counter)

**Membership Test — Apakah w ∈ L(G)?**

- Cara naif (coba semua parse tree): eksponensial — tidak praktis
- Cara efisien: **Algoritma CYK** (Cocke-Younger-Kasami)
  - Membutuhkan CFG dalam bentuk **CNF** terlebih dahulu
  - Menggunakan dynamic programming dengan tabel segitiga
  - Kompleksitas: **O(n³)** untuk string panjang n
  - Detail lengkap di materi CNF & CYK

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **Simplifikasi CFG** | Proses membersihkan grammar: hapus ε-prod, unit prod, useless symbols |
| **Nullable variable** | Variabel A yang dapat menurunkan ε (A ⇒* ε) |
| **Unit pair (A,B)** | A dapat menurunkan B hanya via unit productions |
| **Generating symbol** | Dapat menurunkan string terminal (X ⇒* w) |
| **Reachable symbol** | Dapat dicapai dari S (S ⇒* αXβ) |
| **Useless symbol** | Tidak generating atau tidak reachable |
| **Closure property** | Sifat bahwa operasi tertentu menjaga bahasa tetap dalam kelas yang sama |
| **Intersection RL** | CFL ∩ Regular Language = CFL (tertutup) |
| **Intersection CFL** | CFL ∩ CFL ≠ pasti CFL (tidak tertutup) |
| **Emptiness test** | Cek apakah S adalah generating symbol |
| **Membership test** | CYK algorithm (O(n³), butuh CNF) |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Eliminasi ε-productions: nullable variables, cara membuat kombinasi
- [x] Eliminasi unit productions: unit pairs, cara menambah produksi langsung
- [x] Eliminasi useless symbols: non-generating vs unreachable
- [x] Urutan yang benar: ε → unit → useless
- [x] Closure Properties: daftar tertutup dan tidak tertutup
- [x] Closure intersection RL (tertutup) vs intersection CFL (tidak tertutup)
- [x] Emptiness test: cek generating symbol
- [x] Membership test: CYK (O(n³))

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Simplifikasi CFG: 3 eliminasi + urutan yang benar |
| 🔴 *Wajib dikuasai* | Closure: daftar tertutup vs tidak tertutup (terutama intersection!) |
| 🟡 *Cukup paham konsep* | Decision Properties: emptiness dan membership test |
| 🟡 *Cukup paham konsep* | Detail algoritma untuk nullable variables dan unit pairs |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
