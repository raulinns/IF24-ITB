# Master Outline — IF2224 Teori Bahasa Formal dan Otomata

> **UAS dalam < 36 jam** · Gunakan dokumen ini sebagai peta navigasi belajar.
> File detail per materi tersimpan di folder yang sama (`01-`, `02-`, dst.)

---

## Status Penguasaan

| Materi                              | File                                | Status           |
| ----------------------------------- | ----------------------------------- | ---------------- |
| Regular Language (FA + RE)          | `01-Regular-Language.md`            | ✅ Dasar dikuasai |
| Properties of Regular Language      | `02-Properties-Regular-Language.md` | ⏳ Belum          |
| Context Free Grammar & Language     | `03-CFG-and-CFL.md`                 | ⏳ Belum          |
| Parse Tree & Conversion             | `04-Parse-Tree-and-Conversion.md`   | ⏳ Belum          |
| Ambiguity in Grammar                | `05-Ambiguity.md`                   | ⏳ Belum          |
| Properties of Context Free Language | `06-Properties-CFL.md`              | ⏳ Belum          |
| Compiler & Recursive Descent Parser | `07-Compiler-and-RD-Parser.md`      | ⏳ Belum          |
| CNF & CYK Parser                    | `08-CNF-and-CYK.md`                 | ⏳ Belum          |
| LL(1) Parser                        | `09-LL1-Parser.md`                  | ⏳ Belum          |

---

## Hierarki Konsep Keseluruhan

```
Teori Bahasa Formal dan Otomata
│
├── BAHASA REGULER (Regular Languages)
│   ├── 1. Regular Language
│   │   ├── Finite Automata: DFA, NFA, ε-NFA
│   │   ├── Regular Expression (RE)
│   │   ├── Ekuivalensi DFA = NFA = ε-NFA = RE
│   │   └── Aplikasi: Lexical Analyzer, Text Search
│   │
│   └── 2. Properties of Regular Language
│       ├── Pumping Lemma (bukti bukan RL)
│       ├── Closure Properties (Union, Intersection, Complement, ...)
│       ├── Decision Properties (emptiness, membership, equivalence)
│       └── DFA Minimization
│
└── BAHASA BEBAS KONTEKS (Context Free Languages)
    ├── 3. Context Free Grammar & Language
    │   ├── Komponen CFG: Variables, Terminals, Productions, Start Symbol
    │   ├── Derivasi: Leftmost & Rightmost
    │   └── Context Free Language (CFL)
    │
    ├── 4. Parse Tree & Conversion
    │   ├── Struktur Parse Tree
    │   ├── Yield dari Parse Tree
    │   └── Konversi Parse Tree ↔ Derivasi
    │
    ├── 5. Ambiguity in Grammar
    │   ├── Definisi Ambiguitas (≥2 parse tree untuk 1 string)
    │   ├── Menghilangkan Ambiguitas (precedence, grouping)
    │   └── Inherent Ambiguity
    │
    ├── 6. Properties of CFL
    │   ├── Simplifikasi CFG (useless symbols, ε-production, unit production)
    │   ├── Closure Properties (Union, Concat, Kleene, Homomorphism, ...)
    │   └── Decision Properties (membership, emptiness)
    │
    ├── 7. Compiler & Recursive Descent Parser
    │   ├── Tahapan Kompilator: Lexical → Parsing → Semantic
    │   ├── Top-Down Parsing
    │   └── Recursive Descent Parser + Backtracking
    │
    ├── 8. CNF & CYK Parser
    │   ├── Chomsky Normal Form (A→BC | A→a)
    │   ├── Konversi CFG → CNF
    │   └── CYK Algorithm (Dynamic Programming, O(n³))
    │
    └── 9. LL(1) Parser
        ├── Konsep Predictive Parsing (non-rekursif, no backtracking)
        ├── FIRST dan FOLLOW Sets
        └── Parsing Table & Error Recovery
```

---

## Urutan Belajar yang Disarankan

Materi saling bergantung satu sama lain. Ikuti urutan berikut agar konsep terhubung dengan baik:

```
Regular Language (review cepat)
    ↓
Properties of Regular Language        ← Pumping Lemma penting!
    ↓
CFG & CFL                             ← Fondasi semua materi selanjutnya
    ↓
Parse Tree                            ← Langsung hubungan visual dengan CFG
    ↓
Ambiguity                             ← Extension dari Parse Tree
    ↓
Properties of CFL + CNF               ← Gabungan, termasuk konversi ke CNF
    ↓
CYK Parser                            ← Bergantung pada CNF
    ↓
Compiler & RD Parser                  ← Aplikasi CFG
    ↓
LL(1) Parser                          ← Penyempurnaan RD Parser
```

---

## Prioritas Materi untuk UAS

| Prioritas | Materi | Alasan |
|-----------|--------|--------|
| 🔴 Wajib | CFG & CFL | Fondasi semua materi CFL |
| 🔴 Wajib | Parse Tree | Paling sering muncul di soal |
| 🔴 Wajib | CNF & CYK | Algoritma spesifik, soal teknis |
| 🔴 Wajib | LL(1) Parser | FIRST/FOLLOW + Parsing Table |
| 🔴 Wajib | Pumping Lemma | Soal pembuktian klasik |
| 🟡 Penting | Ambiguity | Konsep penting, teknis sedang |
| 🟡 Penting | Properties of CFL | Closure properties |
| 🟡 Penting | RD Parser | Konsep compiler |
| ✅ Review | Regular Language | Sudah dikuasai, review cepat |
| ✅ Review | Properties of RL | Closure properties RL |

---

*Dibuat: 2026-05-04 · Sumber: NotebookLM IF2224*
