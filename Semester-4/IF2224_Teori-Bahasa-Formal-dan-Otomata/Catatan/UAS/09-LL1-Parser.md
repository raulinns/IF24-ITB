# LL(1) Parser

---

### Hubungan dengan CPMK

> **CPMK 1 & 2** — LL(1) adalah teknik parsing deterministik yang dibangun di atas teori FIRST/FOLLOW dari CFG. Ini adalah penyempurnaan dari RD Parser — parsing tanpa backtracking menggunakan tabel prediksi.

---

### Outline Konsep Fundamental

- **Konsep LL(1)**
  - L: Left-to-right scan
  - L: Leftmost derivation
  - 1: 1 simbol lookahead
  - vs RD Parser: tidak ada backtracking
- **FIRST Sets**
  - Definisi FIRST(α)
  - Aturan: terminal, variabel, string
- **FOLLOW Sets**
  - Definisi FOLLOW(A)
  - Aturan: $, kanan, ujung produksi
- **Parsing Table**
  - Cara mengisi M[A, a]
  - Entri error
- **Grammar LL(1)**
  - Konflik → bukan grammar LL(1)
  - Syarat: tidak ambigu, tidak left-recursive, left-factored
- **Menjalankan Parser**
  - Stack + input + tabel
  - Aksi: expand, match, accept, error

---

### Penjelasan Materi

---

#### Konsep LL(1)

**TL;DR:** *LL(1) adalah top-down parser yang memilih produksi secara deterministik hanya dengan melihat satu token ke depan — tidak perlu backtracking.*

**Nama LL(1) berasal dari:**
- **L** pertama: *Left-to-right scan* — baca input dari kiri ke kanan
- **L** kedua: *Leftmost derivation* — selalu ekspansi variabel paling kiri
- **1**: gunakan *1 simbol lookahead* untuk memilih produksi

**Perbedaan dengan Recursive Descent Parser:**

| | RD Parser | LL(1) Parser |
|---|---|---|
| **Implementasi** | Fungsi rekursif | Stack eksplisit + tabel |
| **Pilih produksi** | Trial-and-error + backtracking | Lookup tabel M[A, lookahead] |
| **Backtracking** | Ya (ada) | Tidak (deterministik) |
| **Kecepatan** | Bisa lambat | Efisien (linear) |

---

#### FIRST Sets

**TL;DR:** *FIRST(α) = himpunan terminal yang bisa menjadi karakter pertama dari string yang diturunkan dari α.*

**Definisi:**
> FIRST(α) = { a ∈ T | α ⇒* aw } ∪ (ε jika α ⇒* ε)

**Aturan menghitung FIRST:**

**Untuk terminal `a`:**
> FIRST(a) = {a}

**Untuk variabel A:**
- Untuk setiap produksi A → Y₁Y₂...Yₖ:
  - Tambahkan FIRST(Y₁) − {ε} ke FIRST(A)
  - Jika ε ∈ FIRST(Y₁): tambahkan FIRST(Y₂) − {ε} ke FIRST(A)
  - Jika ε ∈ FIRST(Y₁) dan ε ∈ FIRST(Y₂): tambahkan FIRST(Y₃) − {ε}, dst.
  - Jika ε ∈ FIRST(Yᵢ) untuk semua i: tambahkan ε ke FIRST(A)
- Jika ada produksi A → ε: tambahkan ε ke FIRST(A)

**Untuk string α = X₁X₂...Xₙ:**
Aturan sama seperti variabel di atas, terapkan untuk X₁, X₂, ..., Xₙ berurutan.

**Contoh:**

```
Grammar:
E  → T E'
E' → + T E' | ε
T  → F T'
T' → * F T' | ε
F  → (E) | id
```

- FIRST(F) = {(, id}
- FIRST(T') = {*, ε}
- FIRST(T) = FIRST(F) = {(, id}
- FIRST(E') = {+, ε}
- FIRST(E) = FIRST(T) = {(, id}

---

#### FOLLOW Sets

**TL;DR:** *FOLLOW(A) = himpunan terminal yang bisa muncul tepat setelah A dalam sentential form manapun.*

**Definisi:**
> FOLLOW(A) = { a ∈ T | S ⇒* αAaβ }

Simbol `$` (endmarker) juga bisa masuk FOLLOW.

**Aturan menghitung FOLLOW:**

**Aturan 1 — Start Symbol:**
> $ ∈ FOLLOW(S)  *(selalu)*

**Aturan 2 — Kanan: produksi A → αBβ:**
> FIRST(β) − {ε} ⊆ FOLLOW(B)

*(semua yang bisa mulai β, kecuali ε, masuk ke FOLLOW(B))*

**Aturan 3 — Ujung: produksi A → αB atau A → αBβ di mana ε ∈ FIRST(β):**
> FOLLOW(A) ⊆ FOLLOW(B)

*(jika B di ujung atau β bisa hilang, maka apa yang mengikuti A juga bisa mengikuti B)*

**Ulangi aturan 2 dan 3 sampai tidak ada perubahan (fixed point).**

**Contoh (lanjutan grammar di atas):**

- FOLLOW(E) = {), $}  *(dari aturan 1 dan produksi F → (E))*
- FOLLOW(E') = FOLLOW(E) = {), $}
- FOLLOW(T) = FIRST(E') − {ε} ∪ FOLLOW(E') = {+, ), $}
- FOLLOW(T') = FOLLOW(T) = {+, ), $}
- FOLLOW(F) = FIRST(T') − {ε} ∪ FOLLOW(T') = {*, +, ), $}

---

#### Parsing Table LL(1)

**TL;DR:** *Tabel M[A, a] memetakan non-terminal A dan lookahead a ke produksi yang harus digunakan.*

**Cara mengisi tabel M[A, a]:**

Untuk setiap produksi **A → α**:

1. Untuk setiap terminal `a` ∈ FIRST(α) − {ε}:
   → masukkan `A → α` ke M[A, a]

2. Jika ε ∈ FIRST(α):
   - Untuk setiap terminal `b` ∈ FOLLOW(A):
     → masukkan `A → α` ke M[A, b]
   - Jika `$` ∈ FOLLOW(A):
     → masukkan `A → α` ke M[A, $]

3. Semua sel yang tidak terisi = **error**

**Contoh tabel (grammar ekspresi):**

|  | id | + | * | ( | ) | $ |
|--|----|----|---|---|---|---|
| **E** | E→TE' | | | E→TE' | | |
| **E'** | | E'→+TE' | | | E'→ε | E'→ε |
| **T** | T→FT' | | | T→FT' | | |
| **T'** | | T'→ε | T'→\*FT' | | T'→ε | T'→ε |
| **F** | F→id | | | F→(E) | | |

---

#### Grammar LL(1)

**TL;DR:** *Grammar adalah LL(1) jika setiap sel tabel paling berisi satu produksi — tidak ada konflik.*

**Grammar G adalah LL(1) jika dan hanya jika:**
- Tabel LL(1) tidak memiliki sel dengan lebih dari satu entri (*no multiply defined entries*)

**Penyebab konflik:**

| Penyebab | Masalah |
|----------|---------|
| **Grammar ambigu** | Satu string punya banyak derivasi → banyak produksi bersaing |
| **Left recursion** (A → Aα) | FIRST(Aα) mengandung FIRST(A) → konflik dengan produksi lain |
| **Tidak left-factored** | A → αβ₁ \| αβ₂ → FIRST(αβ₁) ∩ FIRST(αβ₂) ≠ ∅ |

**Left-factoring** (solusi untuk konflik tipe ketiga):
```
A → αβ₁ | αβ₂    →    A → α A'
                        A' → β₁ | β₂
```

---

#### Menjalankan LL(1) Parser

**TL;DR:** *Parser menggunakan stack dan tabel: ekspansi non-terminal via tabel, cocokkan terminal dengan input.*

**Setup:**
- Stack: `[S, $]` *(start symbol di atas, $ di dasar)*
- Input: `w$` *(string input diakhiri $)*
- Tabel: M[A, a]

**Algoritma:**

```
while stack ≠ [$]:
    X = top of stack
    a = current input token

    if X == a:           // X adalah terminal yang cocok
        pop X
        advance input
    elif X is terminal:  // X ≠ a → error
        ERROR
    else:                // X adalah non-terminal
        if M[X, a] == X → Y₁Y₂...Yₖ:
            pop X
            push Yₖ, ..., Y₂, Y₁  // push terbalik agar Y₁ di atas
        else:            // M[X, a] kosong → error
            ERROR

if input == $ dan stack == [$]:
    ACCEPT
```

**Contoh trace untuk `id + id * id$`:**

| Stack | Input | Aksi |
|-------|-------|------|
| E $ | id+id*id$ | M[E,id]: E→TE' |
| T E' $ | id+id*id$ | M[T,id]: T→FT' |
| F T' E' $ | id+id*id$ | M[F,id]: F→id |
| id T' E' $ | id+id*id$ | Match id, advance |
| T' E' $ | +id*id$ | M[T',+]: T'→ε, pop |
| E' $ | +id*id$ | M[E',+]: E'→+TE' |
| + T E' $ | +id*id$ | Match +, advance |
| T E' $ | id*id$ | ... (lanjut) |
| ... | ... | ... |
| $ | $ | ACCEPT ✓ |

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **LL(1)** | Top-down parser: L-to-R scan, Leftmost derivation, 1 lookahead |
| **Predictive parsing** | Pilih produksi tanpa backtracking menggunakan lookahead |
| **FIRST(α)** | Himpunan terminal yang bisa mengawali string dari α (+ ε jika nullable) |
| **FOLLOW(A)** | Himpunan terminal yang bisa muncul tepat setelah A di sentential form |
| **Nullable** | Variabel/string yang bisa menurunkan ε |
| **M[A, a]** | Sel parsing table: produksi yang digunakan saat top stack = A, lookahead = a |
| **Konflik LL(1)** | Sel M[A,a] punya lebih dari satu produksi → grammar bukan LL(1) |
| **Left-factoring** | Transformasi A→αβ₁\|αβ₂ menjadi A→αA', A'→β₁\|β₂ untuk menghilangkan konflik |
| **Left recursion** | A → Aα — menyebabkan infinite loop / konflik LL(1) |
| **Endmarker $** | Simbol khusus yang menandai akhir input dan dasar stack |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Konsep LL(1): arti L, L, 1
- [x] Perbedaan LL(1) vs RD Parser (backtracking)
- [x] FIRST: definisi dan aturan menghitung (terminal, variabel, string)
- [x] FOLLOW: definisi dan 3 aturan menghitung ($, kanan, ujung)
- [x] Cara mengisi parsing table M[A, a] dari FIRST dan FOLLOW
- [x] Konflik tabel: penyebab dan arti
- [x] Syarat grammar LL(1)
- [x] Left-factoring sebagai solusi konflik
- [x] Algoritma menjalankan parser (stack, tabel, trace)

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Menghitung FIRST dan FOLLOW dengan benar |
| 🔴 *Wajib dikuasai* | Membangun parsing table M[A, a] dari FIRST/FOLLOW |
| 🔴 *Wajib dikuasai* | Menjalankan parser (trace stack + tabel) |
| 🟡 *Cukup paham konsep* | Konsep LL(1) vs RD Parser |
| 🟡 *Cukup paham konsep* | Konflik tabel dan penyebabnya |
| 🟡 *Cukup paham konsep* | Left-factoring |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
