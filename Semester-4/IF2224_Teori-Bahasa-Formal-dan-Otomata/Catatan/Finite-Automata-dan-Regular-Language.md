# Finite Automata & Regular Language
### IF2224 — Teori Bahasa Formal dan Otomata

---

## BAGIAN 1 — Review: Finite Automata & Regular Language

---

### SLIDE 1 — Fondasi: Alphabet, String, dan Bahasa

**Alphabet (Σ)**
- Himpunan berhingga simbol
- Contoh: `Σ = {0, 1}`, `Σ = {a, b, c}`

**String**
- Sekuens berhingga simbol dari Σ
- **ε** = string kosong (panjang nol)
- Contoh: `"0110"`, `"abc"`, `ε`
- Panjang string `w` ditulis `|w|`; contoh: `|"abc"| = 3`, `|ε| = 0`

**Bahasa (Language)**
- Himpunan string yang diambil dari suatu alphabet
- Contoh: `L = { w ∈ {0,1}* | w mengandung "01" }`
- Bahasa bisa berhingga atau tak berhingga

**Operasi pada String**
- **Konkatenasi**: `xy` = string x diikuti string y; `xε = εx = x`
- **Kleene Star** `Σ*`: himpunan semua string (termasuk ε) dari Σ
- **Kleene Plus** `Σ+`: semua string non-kosong dari Σ; `Σ+ = Σ* \ {ε}`

---

### SLIDE 2 — Deterministic Finite Automata (DFA)

**Intuisi**
Mesin yang deterministik — pada setiap state dan simbol input, selalu ada **tepat satu** state tujuan.

**Formal — 5-tuple:** `A = (Q, Σ, δ, q₀, F)`

| Komponen | Tipe | Keterangan |
|----------|------|-----------|
| `Q` | Himpunan berhingga | States |
| `Σ` | Himpunan berhingga | Alphabet input |
| `δ` | `Q × Σ → Q` | Fungsi transisi |
| `q₀ ∈ Q` | State | Start state |
| `F ⊆ Q` | Himpunan | Final/accepting states |

**Representasi**
- **Diagram transisi**: graf berarah, state = simpul, transisi = busur berlabel simbol
- **Tabel transisi**: baris = state, kolom = simbol input, sel = state tujuan

**Extended Transition Function `δ̂`**
- `δ̂(q, ε) = q`
- `δ̂(q, wa) = δ(δ̂(q, w), a)`
- Memproses seluruh string mulai dari state `q`

**Penerimaan String**
- String `w` **diterima** ⟺ `δ̂(q₀, w) ∈ F`
- String `w` **ditolak** ⟺ `δ̂(q₀, w) ∉ F`
- **Bahasa yang diterima DFA**: `L(A) = { w ∈ Σ* | δ̂(q₀, w) ∈ F }`
- Bahasa yang diterima DFA = **Regular Language**

**Contoh**
DFA yang menerima semua string biner yang berakhiran `1`:
- `Q = {q₀, q₁}`, `Σ = {0,1}`, `q₀` = start, `F = {q₁}`
- `δ(q₀, 0) = q₀`, `δ(q₀, 1) = q₁`, `δ(q₁, 0) = q₀`, `δ(q₁, 1) = q₁`

---

### SLIDE 3 — Nondeterministic Finite Automata (NFA)

**Intuisi**
Mesin yang bisa "menebak" jalur terbaik — satu input bisa menuju **banyak state sekaligus**. Bisa juga tidak ada transisi untuk kombinasi state+input tertentu.

**Formal — 5-tuple:** `N = (Q, Σ, δ, q₀, F)`

Perbedaan utama dari DFA ada pada fungsi transisi:
- `δ: Q × Σ → 2^Q` (menuju *himpunan* state, bukan satu state tunggal)
- Boleh menuju `∅` (tidak ada transisi)

**Cara Kerja — Komputasi Paralel**
Ketika membaca input, NFA "bercabang" — semua kemungkinan state dijalankan paralel.

**Penerimaan String**
- String `w` **diterima** ⟺ **setidaknya satu jalur** komputasi berakhir di final state
- String `w` **ditolak** ⟺ **semua jalur** berakhir di non-final state atau mati

**Perbandingan NFA vs DFA**

| Aspek | DFA | NFA |
|-------|-----|-----|
| Fungsi transisi | `Q × Σ → Q` | `Q × Σ → 2^Q` |
| Transisi per input | Tepat 1 | 0, 1, atau banyak |
| Komputasi | Satu jalur | Banyak jalur paralel |
| Kemudahan desain | Lebih sulit | Lebih mudah/intuitif |
| Ekspresivitas | **Ekuivalen** | **Ekuivalen** |

> **Teorema:** Untuk setiap NFA, ada DFA yang menerima bahasa yang sama.

---

### SLIDE 4 — ε-NFA (Epsilon-NFA)

**Intuisi**
NFA dengan kemampuan ekstra — bisa berpindah state **tanpa membaca simbol input** (transisi ε / transisi kosong).

**Formal**
- `δ: Q × (Σ ∪ {ε}) → 2^Q`
- Fungsi transisi menerima simbol dari Σ **atau** ε

**Konsep Kunci — ε-Closure (ECLOSE)**

Himpunan semua state yang dapat dicapai dari state `q` **hanya melalui transisi ε** (tanpa membaca input):

> **Basis:** `q ∈ ECLOSE(q)` *(state itu sendiri selalu masuk)*
>
> **Induksi:** Jika `p ∈ ECLOSE(q)` dan `r ∈ δ(p, ε)`, maka `r ∈ ECLOSE(q)`

**Cara Hitung ECLOSE**
Gunakan BFS atau DFS dari state `q`, ikuti **hanya busur berlabel ε**.

**Contoh**
Jika `δ(q₀, ε) = {q₁}` dan `δ(q₁, ε) = {q₂}`, maka:
- `ECLOSE(q₀) = {q₀, q₁, q₂}`
- `ECLOSE(q₁) = {q₁, q₂}`
- `ECLOSE(q₂) = {q₂}`

**Penerimaan String**
- String `w` diterima ⟺ setelah memproses `w` (dengan memperhitungkan semua transisi ε), setidaknya satu state yang dapat dicapai adalah final state

---

### SLIDE 5 — Regular Expression (RE)

**Intuisi**
Notasi deklaratif yang ringkas untuk mendeskripsikan bahasa reguler. Lebih mudah ditulis daripada menggambar automaton lengkap.

**Basis (Komponen Dasar)**
| Ekspresi | Bahasa yang Dideskripsikan |
|----------|--------------------------|
| `ε` | `{ε}` — hanya string kosong |
| `∅` | `{}` — bahasa kosong (tidak ada string) |
| `a` (simbol) | `{a}` — hanya string satu karakter `a` |

**Tiga Operasi Utama**
| Operasi | Notasi | Arti |
|---------|--------|------|
| Union | `R + S` | String yang ada di L(R) **atau** L(S) |
| Concatenation | `RS` | String dari L(R) diikuti string dari L(S) |
| Kleene Closure | `R*` | L(R) diulang 0 atau lebih kali (termasuk ε) |

**Prioritas Operator** (dari tertinggi ke terendah):
1. Kleene Star `*`
2. Concatenation (penulisan bersebelahan)
3. Union `+`

**Contoh RE**
- `(0+1)*1` — semua string biner yang berakhiran `1`
- `0*10*` — string biner dengan tepat satu `1`
- `(aa)*` — string atas `{a}` dengan panjang genap

**Ekuivalensi Fundamental**
```
DFA  ⟺  NFA  ⟺  ε-NFA  ⟺  Regular Expression
```
Semua model ini mendefinisikan **kelas yang sama**: **Regular Language**

---

## BAGIAN 2 — Konversi Antar Komponen

---

### SLIDE 6 — Peta Konversi (Overview)

```
         Subset Construction
  NFA ──────────────────────────► DFA
   ▲                               ▲
   │                               │
   │ Structural Induction          │ State Elimination
   │                               │
  RE ◄────────────────────────── DFA/NFA
         State Elimination

  ε-NFA ──────────────────────► DFA
        ECLOSE + Subset Construction

  RE ──────────────────────────► ε-NFA
        Structural Induction
```

**Ringkasan Tabel**

| Dari | Ke | Metode | Catatan |
|------|----|--------|---------|
| NFA | DFA | Subset Construction | State DFA bisa eksponensial |
| ε-NFA | DFA | ECLOSE + Subset Construction | Sama + operasi ECLOSE |
| DFA/NFA | RE | State Elimination | Satu RE per final state |
| RE | ε-NFA | Structural Induction | Bottom-up, rekursif |

**Mengapa Semua Ekuivalen?**
Setiap model mampu menerima tepat kelas bahasa yang sama: **Regular Language**. Ini membuktikan bahwa nondeterminisme tidak menambah kekuatan komputasi pada finite automata.

---

### SLIDE 7 — Konversi NFA → DFA: Subset Construction

**Prinsip Utama**
Setiap state DFA mewakili satu **subset** dari himpunan state NFA. Dengan demikian, DFA "melacak" semua state NFA yang mungkin aktif secara bersamaan.

**Definisi Formal**
- **Diberikan:** NFA `N = (Q_N, Σ, δ_N, q₀, F_N)`
- **Dibangun:** DFA `D = (Q_D, Σ, δ_D, {q₀}, F_D)`

**Langkah Algoritma**

1. **Tentukan Start State DFA**
   - Start state = `{q₀}` (himpunan yang berisi satu state awal NFA)

2. **Hitung Transisi (Lazy Evaluation)**
   - Untuk setiap subset `S ∈ Q_D` dan setiap simbol `a ∈ Σ`:
   ```
   δ_D(S, a) = ⋃_{p∈S} δ_N(p, a)
   ```
   - Gabungkan semua state tujuan dari tiap state di `S` ketika membaca `a`

3. **Temukan Semua State yang Dapat Dicapai**
   - Ulangi langkah 2 untuk setiap subset baru yang muncul
   - Hentikan ketika tidak ada subset baru
   - **Tidak perlu** menghitung semua `2^|Q_N|` subset — hanya yang accessible

4. **Tentukan Final States DFA**
   ```
   F_D = { S ⊆ Q_N : S ∩ F_N ≠ ∅ }
   ```
   - Setiap subset yang mengandung **setidaknya satu** final state NFA

**Kompleksitas**
- Paling buruk: DFA memiliki `2^|Q_N|` state
- Dalam praktik: biasanya jauh lebih sedikit (lazy evaluation)

**Contoh Singkat**
NFA dengan state `{q₀, q₁, q₂}` → DFA dengan subset sebagai state:
`∅`, `{q₀}`, `{q₁}`, `{q₀,q₁}`, `{q₀,q₂}`, dst.

---

### SLIDE 8 — Konversi ε-NFA → DFA: ECLOSE + Subset Construction

**Prinsip Utama**
Sama dengan NFA→DFA, tetapi setiap himpunan state harus **di-ECLOSE** setelah setiap transisi untuk memperhitungkan perpindahan ε spontan.

**Definisi Formal**
- **Diberikan:** ε-NFA `E = (Q_E, Σ, δ_E, q₀, F_E)`
- **Dibangun:** DFA `D = (Q_D, Σ, δ_D, q_D, F_D)`

**Langkah Algoritma**

1. **Tentukan Start State DFA**
   ```
   q_D = ECLOSE(q₀)
   ```
   Tutup start state dengan semua state yang dapat dicapai via ε.

2. **Hitung Transisi**
   - Untuk setiap subset `S ∈ Q_D` dan setiap simbol `a ∈ Σ` (bukan ε!):
   ```
   δ_D(S, a) = ECLOSE( ⋃_{p∈S} δ_E(p, a) )
   ```
   - Langkah: baca simbol `a` dari tiap state di `S` → gabungkan hasilnya → tutup dengan ECLOSE

3. **Temukan Semua State yang Dapat Dicapai**
   - Ulangi langkah 2 untuk setiap subset baru, hingga tidak ada yang baru

4. **Tentukan Final States DFA**
   - Subset `S` adalah final state ⟺ `S ∩ F_E ≠ ∅`

**Perbedaan vs NFA→DFA**
Hanya satu perbedaan: penambahan `ECLOSE(...)` di setiap transisi dan di start state.

**Tips Praktis**
Buat tabel ECLOSE untuk semua state ε-NFA terlebih dahulu sebelum memulai subset construction.

---

### SLIDE 9 — Konversi DFA/NFA → RE: State Elimination

**Prinsip Utama**
Hapus state satu per satu dari automaton. Setiap state yang dihapus, jalur yang melewatinya digantikan dengan ekspresi reguler. Proses berakhir ketika hanya tersisa start state dan satu final state.

**Persiapan**
- Ubah semua label transisi menjadi RE (simbol tunggal sudah merupakan RE)
- Proses dilakukan **terpisah untuk setiap final state**

**Rumus Eliminasi State `s`**

Untuk jalur `qᵢ → s → pⱼ`:

```
Label baru (qᵢ → pⱼ) = Rᵢⱼ + Qᵢ · S* · Pⱼ
```

| Simbol | Arti |
|--------|------|
| `Qᵢ` | Label busur `qᵢ → s` |
| `S` | Label loop pada `s` sendiri |
| `Pⱼ` | Label busur `s → pⱼ` |
| `Rᵢⱼ` | Label busur langsung `qᵢ → pⱼ` sebelumnya (`∅` jika tidak ada) |

**Kondisi Berhenti (per final state `q`)**

| Kasus | Kondisi | Rumus RE |
|-------|---------|----------|
| Tersisa 2 state | `q₀ ≠ q` | `E_q = (R + S·U*·T)* · S·U*` |
| Tersisa 1 state | `q₀ = q` | `E_q = R*` |

*Untuk kasus 2 state: R = loop di q₀, S = q₀→q, U = loop di q, T = q→q₀*

**Hasil Akhir**
```
RE_total = E_q1 + E_q2 + ... + E_qn
```
Union dari semua ekspresi untuk tiap final state.

**Urutan Eliminasi**
Pilih state yang memiliki paling sedikit busur masuk/keluar terlebih dahulu untuk meminimalkan kerumitan ekspresi.

---

### SLIDE 10 — Konversi RE → ε-NFA: Structural Induction

**Prinsip Utama**
Bangun ε-NFA dari komponen RE terkecil secara rekursif. Setiap sub-ekspresi menghasilkan automaton kecil dengan **tepat satu start state dan satu final state**, lalu digabungkan sesuai operatornya.

**Aturan Penting**
- Final state dari sub-automaton **tidak boleh** menjadi start state komponen lain secara langsung
- Penggabungan selalu melalui transisi ε

---

**BASIS CASE — Komponen Dasar**

```
ε:    →○ ──ε──► ◎      (start → final via ε)

∅:    →○         ◎     (start dan final tanpa busur)

a:    →○ ──a──► ◎      (start → final via simbol a)
```

---

**RECURSIVE CASE — Union `R + S`**
```
              ┌──ε──► [Mesin R] ──ε──┐
→○_new ───────┤                      ├───► ◎_new
              └──ε──► [Mesin S] ──ε──┘
```
- Buat start state baru dan final state baru
- Tarik ε dari start baru ke start mesin R dan S
- Tarik ε dari final mesin R dan S ke final baru

---

**RECURSIVE CASE — Concatenation `RS`**
```
→○ [Mesin R] ◎ ──ε──► ○ [Mesin S] ◎
```
- Hubungkan final state mesin R ke start state mesin S via ε
- Start gabungan = start mesin R; Final gabungan = final mesin S

---

**RECURSIVE CASE — Kleene Star `R*`**
```
         ┌────────── ε (loop) ──────────┐
         │                              ▼
→○_new ──┴──ε──► ○ [Mesin R] ◎ ──ε──► ◎_new
    └──────────────── ε (bypass) ──────────┘
```
- Buat start state baru dan final state baru
- 4 transisi ε:
  1. Start baru → start mesin R
  2. Final mesin R → start mesin R *(loop/perulangan)*
  3. Final mesin R → final baru *(keluar dari loop)*
  4. Start baru → final baru *(bypass untuk menerima ε)*

---

## RINGKASAN UMUM

### Hierarki Ekuivalensi
```
Regular Language = L(DFA) = L(NFA) = L(ε-NFA) = L(RE)
```

### Tabel Konversi Lengkap

| Dari | Ke | Metode | Kompleksitas |
|------|----|--------|-------------|
| NFA | DFA | Subset Construction | O(2^n) state worst case |
| ε-NFA | DFA | ECLOSE + Subset Construction | O(2^n) state worst case |
| ε-NFA | NFA | Hapus transisi ε, pakai ECLOSE | O(n²) |
| DFA | NFA | Langsung (DFA ⊆ NFA) | O(1) |
| DFA/NFA | RE | State Elimination | Per final state |
| RE | ε-NFA | Structural Induction | Linier terhadap panjang RE |

### Poin Kunci untuk Ujian
1. **Subset Construction**: State DFA = himpunan state NFA; final state DFA mengandung ≥1 final state NFA
2. **ECLOSE**: Selalu hitung ECLOSE di start state dan setelah setiap transisi non-ε
3. **State Elimination**: Rumus `Rᵢⱼ + Qᵢ·S*·Pⱼ`; proses terpisah per final state
4. **RE → ε-NFA**: Selalu 2 state per basis; 4 transisi ε untuk Kleene Star
5. **Semua model ekuivalen**: Mereka mendefinisikan kelas yang sama — Regular Language
