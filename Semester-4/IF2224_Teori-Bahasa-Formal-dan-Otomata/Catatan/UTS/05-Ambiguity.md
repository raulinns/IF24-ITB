# Ambiguity in Grammar

---

### Hubungan dengan CPMK

> **CPMK 1** — Ambiguitas adalah konsep penting dalam desain grammar untuk kompiler. Grammar yang ambigu menghasilkan parse tree berbeda untuk satu string yang sama, sehingga makna program menjadi tidak deterministik.

---

### Outline Konsep Fundamental

- **Definisi Ambiguitas**
  - Grammar ambigu: ∃ string dengan ≥2 parse tree
  - Ekuivalensi: ≥2 leftmost derivation = ≥2 rightmost derivation = ≥2 parse tree
- **Mendeteksi Ambiguitas**
  - Cari string yang bisa diturunkan dengan dua cara berbeda
- **Menghilangkan Ambiguitas**
  - Teknik precedence (tingkatan operator)
  - Teknik grouping (asosiativitas kiri/kanan)
  - Contoh: ekspresi aritmatika
- **Inherent Ambiguity**
  - Definisi: bahasa yang semua grammar-nya pasti ambigu
  - Contoh bahasa inherently ambiguous

---

### Penjelasan Materi

---

#### Definisi Ambiguitas

**TL;DR:** *Grammar ambigu jika ada satu string yang bisa dihasilkan dengan dua struktur parse tree yang berbeda.*

Sebuah CFG G dikatakan **ambigu** jika terdapat setidaknya satu string terminal w ∈ L(G) yang memiliki:
- **Lebih dari satu parse tree**, atau ekuivalen:
- **Lebih dari satu leftmost derivation**, atau
- **Lebih dari satu rightmost derivation**

Jika setiap string dalam L(G) hanya memiliki tepat satu parse tree, grammar G disebut **tidak ambigu (unambiguous)**.

**Mengapa ambiguitas berbahaya?**

Parse tree menentukan *struktur sintaksis* dan *makna* dari string. Dalam konteks kompiler:
- Ekspresi `3 + 4 * 2` harus memiliki *satu* makna: 3 + (4*2) = 11, bukan (3+4)*2 = 14
- Jika grammar ambigu, kompiler tidak tahu struktur mana yang "benar" → perilaku program tidak terdefinisi

---

#### Mendeteksi Ambiguitas

**TL;DR:** *Cari string yang bisa diturunkan dengan dua leftmost derivation berbeda — jika ada, grammar ambigu.*

**Cara praktis:** Untuk grammar yang dicurigai ambigu, coba cari string yang "bisa diinterpretasikan dua cara":
1. Buat dua leftmost derivation berbeda untuk string yang sama
2. Jika berhasil → grammar ambigu (sudah terbukti)
3. Jika tidak bisa menemukan → tidak berarti tidak ambigu (tidak ada algoritma umum yang bisa membuktikan grammar *pasti* tidak ambigu)

*Catatan: Tidak ada algoritma decidable untuk menguji apakah CFG sembarang bersifat ambigu atau tidak.*

**Contoh grammar ambigu — ekspresi sederhana:**

```
E → E + E | E * E | (E) | id
```

String `id + id * id` memiliki dua parse tree:
- Pohon 1: `(id + id) * id` *(penjumlahan dikerjakan dulu)*
- Pohon 2: `id + (id * id)` *(perkalian dikerjakan dulu)*

---

#### Menghilangkan Ambiguitas

**TL;DR:** *Tambahkan variabel baru untuk memaksa satu urutan evaluasi — precedence dan grouping harus dienkode dalam struktur grammar.*

Tidak ada algoritma otomatis untuk menghilangkan ambiguitas. Solusinya adalah **merancang ulang grammar secara manual** dengan dua teknik:

**Teknik 1 — Precedence (tingkatan operator):**

Buat hierarki variabel — semakin "dalam" di pohon, semakin tinggi prioritasnya:

| Level | Variabel | Operator | Prioritas |
|-------|----------|----------|-----------|
| Terluar | E (Expression) | `+` | Rendah |
| Tengah | T (Term) | `*` | Tinggi |
| Terdalam | F (Factor) | — | Atom |

**Teknik 2 — Grouping / Asosiativitas:**

Gunakan rekursif kiri untuk asosiativitas kiri (paling umum):
- `E → E + T` *(kiri-rekursif: a+b+c = (a+b)+c)*
- bukan `E → E + E` *(ambigu)*

**Grammar tidak ambigu untuk ekspresi aritmatika:**

```
E → E + T | T
T → T * F | F
F → (E) | id
```

**Cara membacanya:**
- `F` (Factor): atom — identifier atau ekspresi dalam kurung
- `T` (Term): rangkaian perkalian faktor-faktor (F → T hanya lewat perkalian)
- `E` (Expression): rangkaian penjumlahan term-term (T → E hanya lewat penjumlahan)

**Akibatnya pada parse tree:**
- Perkalian selalu menjadi cabang *lebih dalam* → dikerjakan lebih dulu (prioritas lebih tinggi)
- Penjumlahan di cabang *lebih luar* → dikerjakan belakangan

---

#### Inherent Ambiguity

**TL;DR:** *Beberapa bahasa tidak bisa punya grammar tidak ambigu — ambiguitas adalah sifat dari bahasa itu sendiri, bukan grammarnya.*

Sebuah CFL L disebut **inherently ambiguous** (ambigu secara bawaan) jika:
> Untuk **semua** CFG G dengan L(G) = L, G bersifat ambigu

Artinya, tidak mungkin merancang grammar tidak ambigu untuk bahasa tersebut — apapun yang kita coba.

**Contoh bahasa inherently ambiguous:**

```
L = { aⁿbⁿcᵐdᵐ : n≥1, m≥1 } ∪ { aⁿbᵐcᵐdⁿ : n≥1, m≥1 }
```

String `aabbccdd` (n=2, m=2) memenuhi kedua bagian union:
- Dari L₁: a²b²c²d² (dengan n=2, m=2)
- Dari L₂: a²b²c²d² (dengan n=2, m=2)

Karena string ini bisa diturunkan dari dua "cerita" berbeda, **setiap** grammar untuk L ini pasti akan memiliki dua leftmost derivation untuk string tersebut → selalu ambigu.

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **Grammar ambigu** | Ada ≥1 string dengan ≥2 parse tree dalam grammar tersebut |
| **Unambiguous grammar** | Setiap string memiliki tepat satu parse tree |
| **Precedence** | Tingkatan operator — dikodekan dengan hierarki variabel dalam grammar |
| **Grouping/Asosiativitas** | Urutan evaluasi operator setara — rekursif kiri = asosiativitas kiri |
| **Factor (F)** | Variabel terdalam: atom atau ekspresi dalam kurung |
| **Term (T)** | Variabel tengah: terikat dengan operator `*` |
| **Expression (E)** | Variabel terluar: terikat dengan operator `+` |
| **Inherently ambiguous** | CFL yang semua grammar-nya pasti ambigu |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Definisi ambiguitas (≥2 parse tree = ≥2 leftmost derivation)
- [x] Mengapa ambiguitas berbahaya dalam kompiler
- [x] Cara mendeteksi ambiguitas (cari dua leftmost derivation)
- [x] Teknik menghilangkan: precedence (hierarki E, T, F)
- [x] Teknik menghilangkan: grouping (rekursif kiri)
- [x] Grammar tidak ambigu untuk ekspresi aritmatika
- [x] Inherent ambiguity: definisi dan contoh

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Definisi ambiguitas + cara mendeteksi |
| 🔴 *Wajib dikuasai* | Grammar E/T/F untuk ekspresi aritmatika (mampu menulis ulang) |
| 🟡 *Cukup paham konsep* | Teknik precedence dan grouping secara umum |
| 🟡 *Cukup paham konsep* | Inherent ambiguity: definisi dan contoh |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
