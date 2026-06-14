# Compiler dan Recursive Descent Parser

---

### Hubungan dengan CPMK

> **CPMK 1 & 2** — Materi ini menunjukkan aplikasi nyata dari CFG: kompiler menggunakan teori bahasa formal untuk menganalisis program. Recursive Descent Parser adalah implementasi langsung dari top-down parsing berbasis CFG.

---

### Outline Konsep Fundamental

- **Tahapan Kompilator**
  - Lexical Analysis → tokens
  - Parsing (Syntax Analysis) → parse tree
  - Semantic Analysis → type checking
- **Top-Down Parsing**
  - Dari akar ke daun
  - Setara dengan leftmost derivation
- **Recursive Descent Parser (RD Parser)**
  - Satu fungsi per non-terminal
  - Cara menggunakan produksi sebagai kode
  - Backtracking
  - Keterbatasan: left recursion
- **Contoh implementasi RD Parser**

---

### Penjelasan Materi

---

#### Tahapan Kompilator

**TL;DR:** *Kompilator mengubah kode sumber menjadi kode mesin melalui tiga tahap analisis: lexical, syntactic, semantic.*

Kompiler memproses program sumber melalui beberapa fase berurutan:

**1. Lexical Analysis (Analisis Leksikal)**

- Input: aliran karakter dari source code
- Proses: kelompokkan karakter menjadi unit bermakna (*lexemes*)
- Output: urutan **tokens** untuk diteruskan ke parser
- Contoh: `int x = 3 + 4;` → `[INT, ID(x), ASSIGN, NUM(3), PLUS, NUM(4), SEMICOLON]`
- Implementasi: Regular Expression → DFA

**2. Parsing (Syntax Analysis)**

- Input: urutan tokens dari lexer
- Proses: bangun **parse tree** yang merepresentasikan struktur gramatikal program
- Output: parse tree yang memverifikasi program sesuai aturan grammar bahasa
- Implementasi: CFG → Parser (RD Parser, LL, LR, dst.)

**3. Semantic Analysis**

- Input: parse tree + symbol table
- Proses: periksa konsistensi *makna* program
- Contoh tugas utama: **type checking** — pastikan operator diterapkan pada operand dengan tipe yang kompatibel
- Output: annotated AST (Abstract Syntax Tree) atau pesan error semantik

---

#### Top-Down Parsing

**TL;DR:** *Parser membangun parse tree dari atas (root) ke bawah (daun), memproses token dari kiri ke kanan — setara dengan mencari leftmost derivation.*

- Mulai dari root (start symbol S)
- Pada setiap langkah: pilih produksi untuk variabel paling kiri, ekspansi ke bawah
- Baca token input dari kiri ke kanan untuk mengkonfirmasi pilihan produksi
- Ekuivalen dengan **leftmost derivation**

```
Input: id + id * id

    E
   / \
  T   + E
  |     |
  id    T
       / \
      id  * T
            |
            id
```

---

#### Recursive Descent Parser

**TL;DR:** *Implementasi top-down parsing di mana setiap non-terminal menjadi satu fungsi rekursif — langsung diterjemahkan dari grammar.*

**Prinsip dasar:**

Untuk setiap non-terminal A dalam grammar, buat satu fungsi `A()` yang:
- Mencoba setiap produksi A → α₁ | α₂ | ... secara berurutan
- Jika body produksi mengandung **terminal**: cocokkan dengan token input saat ini
- Jika body produksi mengandung **non-terminal**: panggil fungsi yang bersangkutan secara rekursif

**Backtracking:**

Saat parser tidak tahu produksi mana yang benar:
1. Simpan posisi input saat ini (`save = next`)
2. Coba produksi pertama
3. Jika gagal: kembalikan posisi ke `save`, coba produksi berikutnya
4. Jika semua produksi gagal → parse error

**Contoh grammar:**
```
E → T | T + E
T → int | int * T | (E)
```

**Implementasi pseudocode:**
```c
bool term(TOKEN tok) { return *next++ == tok; }

// Produksi E → T
bool E1() { return T(); }

// Produksi E → T + E
bool E2() { return T() && term(PLUS) && E(); }

// Non-terminal E: coba semua produksi dengan backtracking
bool E() {
    TOKEN *save = next;
    return (next = save, E1())  // coba E1, reset jika gagal
        || (next = save, E2()); // coba E2, reset jika gagal
}

// Produksi T → int
bool T1() { return term(INT); }

// Produksi T → int * T
bool T2() { return term(INT) && term(TIMES) && T(); }

// Produksi T → (E)
bool T3() { return term(OPEN) && E() && term(CLOSE); }

bool T() {
    TOKEN *save = next;
    return (next = save, T1())
        || (next = save, T2())
        || (next = save, T3());
}
```

---

#### Keterbatasan: Left Recursion

**TL;DR:** *Grammar dengan rekursif kiri akan menyebabkan infinite loop pada RD Parser — harus dieliminasi terlebih dahulu.*

**Left recursion:** Produksi berbentuk A → Aα (A muncul di awal body)

**Masalah:** Fungsi `A()` akan memanggil `A()` lagi tanpa mengonsumsi token apapun → **infinite loop**.

**Solusi — Eliminasi left recursion:**

Ubah `A → Aα | β` menjadi:
```
A  → β A'
A' → α A' | ε
```

Contoh:
```
E → E + T | T
```
menjadi:
```
E  → T E'
E' → + T E' | ε
```

Grammar baru ini memiliki semantik yang sama tapi tanpa rekursif kiri — aman untuk RD Parser.

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **Lexical analysis** | Fase kompiler: karakter → tokens |
| **Token** | Unit leksikal bermakna (keyword, identifier, operator, dll.) |
| **Lexeme** | Urutan karakter yang cocok dengan pola token |
| **Parsing** | Fase kompiler: tokens → parse tree |
| **Semantic analysis** | Fase kompiler: periksa tipe dan konsistensi makna |
| **Top-down parsing** | Bangun parse tree dari root ke daun, kiri ke kanan |
| **Recursive Descent Parser** | Top-down parser: satu fungsi per non-terminal |
| **Backtracking** | Kembalikan posisi input dan coba produksi lain saat gagal |
| **Left recursion** | A → Aα — menyebabkan infinite loop pada RD Parser |
| **Left recursion elimination** | Ubah A → Aα\|β menjadi A → βA', A' → αA'\|ε |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Tiga tahapan kompiler: Lexical, Parsing, Semantic Analysis
- [x] Top-down parsing: dari root ke daun, setara leftmost derivation
- [x] RD Parser: prinsip satu fungsi per non-terminal
- [x] RD Parser: cara menggunakan produksi sebagai kode
- [x] Backtracking: save → try → reset → retry
- [x] Keterbatasan: left recursion → infinite loop
- [x] Eliminasi left recursion

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Tahapan kompiler (Lexical → Parsing → Semantic) |
| 🔴 *Wajib dikuasai* | Prinsip RD Parser: satu fungsi per non-terminal |
| 🟡 *Cukup paham konsep* | Backtracking dalam RD Parser |
| 🟡 *Cukup paham konsep* | Left recursion dan cara eliminasinya |
| 🟡 *Cukup paham konsep* | Contoh pseudocode RD Parser |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
