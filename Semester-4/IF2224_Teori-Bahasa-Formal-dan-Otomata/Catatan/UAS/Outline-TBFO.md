# Outline TBFO Berdasarkan NotebookLM Terbaru

Dokumen ini berisi outline terbaru yang diminta ulang dari NotebookLM satu per satu per materi, lalu akan dibandingkan dengan outline yang sudah ada pada proyek LaTeX.

Sumber NotebookLM: `if2224-teori-bahasa-formal-dan-otomata-uas`

## 1. PDA, Termasuk Konversi CFG

1. Konsep Fundamental dan Arsitektur PDA
   1. Definisi informal: epsilon-NFA yang diperluas dengan stack LIFO.
   2. Definisi formal 7-tuple: `P = (Q, Sigma, Gamma, delta, q0, Z0, F)`.
   3. Komponen: state kontrol, alfabet input, alfabet stack, fungsi transisi, state awal, simbol dasar stack, accepting states.
   4. Fungsi transisi: `delta: Q x (Sigma union {epsilon}) x Gamma -> 2^(Q x Gamma*)`.
   5. Operasi stack: pop, no-op, replace/push.
   6. Larangan mixing and matching pada cabang nondeterministik.

2. Representasi Komputasi
   1. Instantaneous Description `(q, w, gamma)`.
   2. Relasi turnstile satu langkah `|-`.
   3. Relasi banyak langkah `|-*`.
   4. Sifat validitas ID: ekspansi input, ekspansi dasar stack, dan pemotongan sisa input yang tidak pernah dibaca.

3. Metode Penerimaan
   1. Acceptance by final state `L(P)`.
   2. Acceptance by empty stack `N(P)`.
   3. Konversi empty stack ke final state dengan state awal baru, state final baru, dan bottom marker baru.
   4. Konversi final state ke empty stack dengan state awal baru, marker dasar, dan state pembersih stack.

4. Ekuivalensi PDA dan CFG
   1. Konversi CFG ke PDA.
      1. PDA mensimulasikan leftmost derivation secara top-down.
      2. Transisi expand variable `delta(q, epsilon, A)`.
      3. Transisi match terminal `delta(q, a, a) = {(q, epsilon)}`.
      4. Relevansi UAS 2425: modifikasi grammar menjadi transisi epsilon.
   2. Konversi PDA ke CFG.
      1. Variabel komposit `[pXq]`.
      2. Aturan start `S -> [q0 Z0 p]` untuk setiap state `p`.
      3. Aturan umum untuk transisi `delta(q, a, X) = (r, Y1...Yk)`.
      4. Kasus pop murni `k = 0`: `[qXr] -> a`.
      5. Relevansi UAS 2425: pemetaan transisi PDA ke produksi CFG.
   3. Isu ukuran grammar.
      1. Push panjang dapat menyebabkan exponential blow-up.
      2. Banyak aturan dapat tumbuh hingga `O(n^n)`.
      3. Mitigasi: tambahkan `k-2` state bantu agar push per transisi dibatasi.
      4. Ukuran produksi dapat ditekan ke orde polinomial, misalnya `O(n^3)` untuk bentuk normal.

5. Deterministic PDA
   1. Definisi DPDA: transisi pada konfigurasi yang sama maksimal satu pilihan.
   2. Eksklusivitas transisi input nyata dan transisi epsilon.
   3. DPDA mengenali subkelas sejati CFL.
   4. DPDA dapat meniru DFA dengan mengabaikan stack.
   5. Prefix property untuk DPDA yang menerima dengan empty stack.
   6. Bahasa yang diterima DPDA dengan final state memiliki CFG unambiguous.

6. Closure Properties Terkait CFL dan PDA
   1. Intersection CFL dengan regular language.
      1. Simulasi paralel PDA dan DFA melalui product construction.
      2. Acceptance mensyaratkan komponen PDA dan DFA sama-sama menerima.
   2. Inverse homomorphism pada PDA.
      1. PDA baru memakai buffer internal untuk mensimulasikan hasil homomorphism.
      2. Input asli diubah secara konseptual menjadi string yang dapat dibaca PDA lama.

## 2. CYK dan Chomsky Normal Form

1. Chomsky Normal Form
   1. Definisi formal CNF.
      1. Produksi hanya berbentuk `A -> BC`.
      2. Produksi terminal hanya berbentuk `A -> a`.
      3. CNF membuat parse tree menjadi pohon biner dan menjadi prasyarat CYK.
   2. Terminologi kunci.
      1. Generating symbols: simbol yang dapat menurunkan string terminal.
      2. Reachable symbols: simbol yang dapat dicapai dari start symbol.
      3. Nullable symbols: variabel yang dapat menurunkan epsilon.
      4. Unit pairs: pasangan `(A, B)` dengan `A =>* B` melalui unit productions.
   3. Prosedur pembersihan grammar.
      1. Eliminasi epsilon-productions.
      2. Eliminasi unit productions.
      3. Eliminasi useless symbols.
      4. Urutan penting: epsilon, unit, lalu useless agar residu aturan tidak muncul kembali.
   4. Konversi CFG bersih ke CNF.
      1. Pemisahan terminal pada body panjang dengan variabel baru.
      2. Pemecahan produksi panjang menjadi rangkaian produksi biner.
      3. Untuk `A -> B1 B2 ... Bk`, gunakan variabel perantara `C1, ..., C(k-2)`.
   5. Kompleksitas konversi.
      1. Generating/reachable/useless cleanup dapat berjalan linear terhadap ukuran grammar.
      2. Unit-pair computation dapat berjalan `O(n^2)`.
      3. Ukuran grammar hasil CNF umumnya `O(n^2)`.
      4. Blow-up dapat muncul jika nullable symbols dieliminasi tanpa strategi pemecahan body.

2. Algoritma CYK
   1. Motivasi.
      1. Menyelesaikan membership problem `w in L(G)`.
      2. Menghindari enumerasi parse tree secara brute-force.
      3. Memakai dynamic programming/table-filling.
   2. Prasyarat.
      1. Grammar harus dalam CNF.
      2. Input `w = a1 a2 ... an`.
   3. Struktur tabel.
      1. Tabel segitiga 2D.
      2. Sel `X_ij` menyimpan himpunan variabel yang dapat menurunkan substring `a_i ... a_j`.
   4. Langkah basis.
      1. Untuk setiap `i`, isi `X_ii = {A | A -> a_i}`.
   5. Langkah induksi.
      1. Untuk substring `a_i ... a_j`, coba semua split `k` dengan `i <= k < j`.
      2. Tambahkan `A` ke `X_ij` jika ada produksi `A -> BC`, `B in X_ik`, dan `C in X_(k+1,j)`.
   6. Kondisi penerimaan.
      1. String diterima jika start symbol `S in X_1n`.
   7. Kompleksitas.
      1. Waktu `O(n^3)` untuk grammar tetap.
      2. Ruang `O(n^2)`.
   8. Implikasi teoretis.
      1. Membership problem untuk CFL decidable.
      2. CYK menjadi bukti konstruktif bahwa CFL dapat diuji keanggotaannya secara algoritmik.

## 3. Mesin Turing

1. Konsep Dasar Mesin Turing
   1. Motivasi: model matematika abstrak untuk batas komputabilitas.
   2. Church-Turing Thesis: semua proses komputasi efektif dapat disimulasikan Mesin Turing.
   3. Definisi formal 7-tuple: `M = (Q, Sigma, Gamma, delta, q0, B, F)`.
   4. Komponen: state, alfabet input, alfabet pita, fungsi transisi, state awal, blank, final states.
   5. Struktur: tape tak terbatas, finite control, dan head baca/tulis.

2. Representasi Komputasi
   1. Instantaneous Description `alpha q beta`.
   2. State ditulis tepat sebelum simbol yang sedang dibaca.
   3. Fungsi transisi `delta(q, X) = (p, Y, D)`.
   4. Aturan gerak kiri dan kanan.
   5. Relasi turnstile `|-` dan `|-*`.
   6. Diagram transisi berlabel `X/YD`.
   7. Trace eksekusi, termasuk contoh UAS seperti pengenal `{0^n 1^n}`.

3. Fungsionalitas Mesin Turing
   1. Language recognizer.
      1. Acceptance by final state.
      2. Acceptance by halting.
      3. Reject melalui halt non-accepting atau loop.
   2. Transducer untuk fungsi integer.
      1. Input integer direpresentasikan unary.
      2. Output ditulis pada pita.
      3. Relevansi UAS: desain TM untuk fungsi seperti `f(n) = 2n`.
   3. Enumerator.
      1. TM membangkitkan string bahasa.
      2. Output dipisahkan dengan marker seperti `#`.
      3. Canonical order.

4. Kelas Bahasa
   1. Recursively enumerable language.
      1. Ada TM yang menerima semua string anggota.
      2. Untuk non-anggota, TM dapat reject atau loop.
   2. Recursive language.
      1. Ada TM yang selalu halt untuk semua input.
      2. Accept untuk anggota dan reject untuk non-anggota.
   3. Relasi komplemen.
      1. Jika `L` RE dan komplemennya juga RE, maka `L` recursive.

5. Teknik Pemrograman Mesin Turing
   1. Storage in state.
   2. Multiple tracks.
   3. Marker/shifting-over.
   4. Subroutines dengan state pemanggil dan return.

6. Variasi Mesin Turing
   1. Multitape TM.
      1. Memiliki banyak pita dan head independen.
      2. Dapat disimulasikan single-tape TM dengan overhead waktu, misalnya `O(n^2)`.
   2. Nondeterministic TM.
      1. Memiliki banyak cabang transisi.
      2. Ekuivalen dengan deterministic TM.
      3. Simulasi deterministik dapat memakai BFS atas konfigurasi.
   3. Two-way infinite tape.
      1. Pita tak terbatas ke kiri dan kanan.
   4. Multi-dimensional dan multi-head TM.
   5. Off-line TM.
      1. Pita input read-only dengan marker batas.
      2. Working tape terpisah.
   6. Restricted TM.
      1. Semi-infinite tape.
      2. Counter machines.
      3. Multistack machines.

7. Undecidability dan Reduksi
   1. Encoding Turing Machine.
      1. Spesifikasi TM dikodekan menjadi string biner.
      2. Program dapat menjadi input program lain.
   2. Diagonalization language `Ld`.
      1. Bahasa self-rejection.
      2. `Ld` bukan recursively enumerable.
   3. Universal language `Lu`.
      1. Universal TM menerima encoding `(M, w)`.
      2. `Lu` RE tetapi undecidable.
   4. Reduction.
      1. Problem baru dibuktikan undecidable dengan mereduksi problem undecidable lama.
      2. Arah reduksi harus dari problem sulit lama ke problem target.
   5. Rice's Theorem.
      1. Semua properti nontrivial tentang bahasa RE undecidable.
      2. Contoh: mengecek apakah bahasa TM finite atau CFL.
   6. Post's Correspondence Problem.
      1. Masalah penyusunan indeks dua daftar string agar konkatenasinya sama.
      2. Dipakai untuk membuktikan undecidability di luar representasi TM langsung.

## 4. Compiler

1. Konsep Dasar dan Sistem Pemrosesan Bahasa
   1. Compiler: translasi bahasa tingkat tinggi ke bahasa target secara utuh.
   2. Interpreter: eksekusi langsung tanpa object code eksternal.
   3. Perbandingan compiler dan interpreter: performa, diagnostik, ukuran kode, dan cara eksekusi.
   4. Model hibrida: compile ke bytecode lalu eksekusi dengan VM/JIT.
   5. Tujuan desain bahasa: simplicity, orthogonality, compilability, dan machine independence.

2. Bootstrapping dan Translator Tools
   1. Bootstrapping: membangun compiler bertahap dari versi awal atau bahasa lain.
   2. Cross-compiling: compiler dibangun pada host untuk target berbeda.
   3. Lex dan Yacc sebagai scanner/parser generator klasik.
   4. ANTLR, GENTLE, dan ELI sebagai tool generasi modern.
   5. TASSKAF sebagai contoh platform pembelajaran subset Java ke JVM.

3. Compiler Pipeline
   1. Front end: lexical analysis, syntax analysis, semantic analysis.
   2. Back end: optimization dan code generation.
   3. Passes: pengelompokan beberapa fase ke dalam satu siklus I/O.
   4. Struktur data global: symbol table dan error handler.

4. Lexical Analysis
   1. Mengubah character stream menjadi token stream.
   2. Terminologi: lexeme, pattern, token.
   3. Input buffering dengan sentinel dan pointer.
   4. Implementasi berbasis regular expression dan DFA.
   5. Aturan longest prefix dan prioritas aturan.

5. Syntax Analysis
   1. Memvalidasi token terhadap CFG/BNF.
   2. Membangun parse tree atau AST.
   3. Top-down parsing: root ke leaves, leftmost derivation.
   4. Bottom-up parsing: leaves ke root, shift-reduce, LR/Yacc.
   5. Brute-force parsing.
   6. Recursive descent parser.
   7. Predictive parsing LL(1) berbasis FIRST dan FOLLOW.

6. Semantic Analysis
   1. Type checking.
   2. Array bounds dan aturan semantik lain.
   3. Coercion.
   4. Overloading resolution.
   5. Syntax-directed translation.
   6. Inherited dan synthesized attributes.
   7. On-the-fly code generation.

7. Symbol Table
   1. Menyimpan identifier dan atributnya.
   2. Atribut: nama, tipe, object-time address, depth of block, dimensi, reference pointer.
   3. Tabel identifier, array, block, real, string.
   4. Display table untuk scope aktif berbasis stack.

8. Error Handling dan Recovery
   1. Reaksi yang tidak boleh terjadi: compiler crash, infinite loop, atau target code rusak.
   2. Error reporting dengan lokasi dan pesan.
   3. Ad-hoc recovery.
   4. Syntax-directed recovery.
      1. Panic mode sampai delimiter.
      2. Unit deletion.
   5. Context-sensitive repair.
      1. Spelling repair.
      2. Dummy identifier.

9. Intermediate Code dalam Pipeline Compiler
   1. IR untuk retargeting dan modularitas.
   2. Syntax tree dan DAG.
   3. Postfix notation.
   4. Three-address code.
   5. Quadruples, triples, dan indirect triples.

10. Runtime Environment
   1. Code area.
   2. Static data.
   3. Stack area untuk activation record.
   4. Heap area untuk objek dinamis.
   5. Garbage collection dari root set.

11. Code Optimization
   1. Machine-independent optimization.
   2. Machine-dependent optimization.
   3. Local optimization.
      1. Constant folding.
      2. Redundant-subexpression elimination.
      3. Loop unrolling.
      4. Strength reduction.
   4. Global optimization.
      1. Dead code elimination.
      2. Unreachable code elimination.
      3. Data-flow analysis.
      4. Liveness dan reaching definitions.

12. Code Generation
   1. Instruction selection.
   2. Evaluation order.
   3. Register allocation.
   4. Graph coloring.
   5. Single accumulator assembly pada konteks UAS 2425.
   6. Peephole optimization.

## 5. Recursive Descent Parser

1. Konsep Dasar Parsing dan Top-Down Parsing
   1. Top-down parsing menelusuri parse tree dari root ke leaf.
   2. Ekuivalen dengan leftmost derivation.
   3. Input dipindai left-to-right.
   4. Konstruksi parse tree mengikuti preorder/depth-first.

2. Brute-Force Parsing vs Recursive Descent
   1. Brute-force parsing.
      1. Mencoba semua kemungkinan produksi dari kiri.
      2. Bergantung pada backtracking penuh.
      3. Lambat dan boros memori karena harus menyimpan status stack dan input.
   2. Recursive descent parser.
      1. Parser tanpa tabel statis.
      2. Mengganti automata eksplisit dengan call stack program.
      3. Translasi langsung dari CFG atau syntax diagram ke fungsi.

3. Arsitektur Recursive Descent Parser
   1. Satu fungsi untuk setiap nonterminal.
   2. Fungsi start symbol dipanggil pertama.
   3. Fungsi mengembalikan nilai boolean sukses/gagal.
   4. Token input seperti `INT`, `PLUS`, `TIMES`, `OPEN`, `CLOSE`.
   5. Lookahead/pointer input seperti `next`.
   6. Terminal matching dengan fungsi seperti `term(tok)`.
   7. Jika token cocok, pointer input dimajukan.
   8. Jika gagal, fungsi mengembalikan false.

4. Backtracking
   1. Terjadi ketika suatu alternatif produksi gagal di tengah proses.
   2. Parser membatalkan konsumsi input dan mencoba alternatif lain.
   3. Mekanisme save pointer: `TOKEN *save = next`.
   4. Mekanisme reset pointer: `next = save`.
   5. Alternatif produksi dapat dirangkai dengan operator OR.

5. Transformasi dan Syarat Grammar
   1. Left recursion.
      1. Bentuk `A -> A alpha | beta`.
      2. Menyebabkan infinite loop pada top-down parser.
      3. Fungsi memanggil dirinya sendiri tanpa mengonsumsi input.
   2. Eliminasi left recursion.
      1. Ubah rekursi kiri menjadi rekursi kanan.
      2. Pola: `A -> beta A'`, `A' -> alpha A' | epsilon`.
      3. General left recursion juga perlu ditangani jika rekursi melewati nonterminal lain.
   3. Left factoring.
      1. Masalah terjadi ketika alternatif berbagi prefix.
      2. Bentuk `A -> alpha beta1 | alpha beta2`.
      3. Transformasi: `A -> alpha A'`, `A' -> beta1 | beta2`.

6. Hubungan dengan Predictive Parsing
   1. Predictive parsing adalah recursive descent deterministik.
   2. Tidak memerlukan backtracking.
   3. Produksi dipilih berdasarkan lookahead.
   4. Pemilihan memakai FIRST dan FOLLOW.
   5. Implementasi dapat memakai `if-else` atau `switch`.

7. Integrasi Syntax-Directed Translation
   1. Cocok untuk L-attributed SDD.
   2. Inherited attributes menjadi parameter fungsi.
   3. Synthesized attributes menjadi return value.
   4. Semantic actions disisipkan di antara pemanggilan fungsi.
   5. On-the-fly code generation dapat dilakukan tanpa membangun AST penuh.

## 6. LL(1) Parser

1. Konsep Dasar LL(1)
   1. `L` pertama: left-to-right scan.
   2. `L` kedua: leftmost derivation.
   3. `1`: satu token lookahead.
   4. Parser deterministik: memilih tepat satu produksi pada setiap langkah.
   5. Tidak memerlukan backtracking.

2. Hubungan dengan Top-Down Parsing dan Recursive Descent
   1. Membangun parse tree dari root ke leaves.
   2. Evaluasi node secara preorder/depth-first.
   3. Recursive descent biasa dapat mencoba banyak alternatif dan backtrack.
   4. LL(1) adalah predictive recursive descent tanpa backtracking.
   5. Implementasi dapat rekursif atau nonrekursif berbasis stack.

3. FIRST, FOLLOW, Nullable, dan Endmarker
   1. FIRST(alpha): terminal yang dapat muncul pertama dari derivasi alpha.
   2. Jika alpha nullable, maka epsilon masuk FIRST(alpha).
   3. FOLLOW(A): terminal yang dapat muncul setelah nonterminal A.
   4. Endmarker `$` masuk FOLLOW start symbol.
   5. FIRST dihitung dari simbol paling kiri RHS produksi.
   6. FOLLOW diwariskan dari konteks kanan atau FOLLOW parent jika simbol kanan nullable.

4. Transformasi dan Syarat Grammar LL(1)
   1. Eliminasi left recursion.
      1. Grammar LL(1) tidak boleh memiliki `A -> A alpha`.
      2. Left recursion menyebabkan infinite loop pada top-down parser.
      3. Transformasi menjadi right recursion dengan nonterminal baru.
   2. Left factoring.
      1. Diperlukan jika alternatif berbagi prefix.
      2. Prefix umum ditarik keluar, keputusan ditunda ke nonterminal baru.
   3. Syarat formal untuk produksi berbeda `A -> alpha | beta`.
      1. FIRST(alpha) dan FIRST(beta) harus disjoint.
      2. Maksimal satu alternatif dapat menghasilkan epsilon.
      3. Jika salah satu nullable, FIRST alternatif lain harus disjoint dari FOLLOW(A).

5. Parsing Table `M[A,a]`
   1. Baris adalah nonterminal.
   2. Kolom adalah terminal dan endmarker `$`.
   3. Untuk setiap `t in FIRST(alpha)`, letakkan `A -> alpha` di `M[A,t]`.
   4. Jika `epsilon in FIRST(alpha)`, letakkan `A -> alpha` di `M[A,t]` untuk setiap `t in FOLLOW(A)`.
   5. Jika `$ in FOLLOW(A)`, produksi nullable juga dapat diletakkan di kolom `$`.
   6. Multiply defined entries berarti grammar bukan LL(1).
   7. Blank entries berarti syntax error.

6. Nonrecursive Predictive Parser
   1. Komponen: input buffer, stack, parsing table.
   2. Stack diinisialisasi dengan `$` di dasar dan start symbol di puncak.
   3. Input diakhiri `$`.
   4. Expand: nonterminal puncak diganti RHS produksi dari tabel.
   5. Match: terminal puncak cocok dengan input, lalu pop dan advance.
   6. Accept: stack dan input sama-sama mencapai `$`.
   7. Error: sel tabel kosong atau terminal mismatch.

7. Error Handling dan Recovery
   1. Error dideteksi saat sel tabel kosong atau terminal mismatch.
   2. Panic-mode recovery.
      1. Buang token sampai menemukan synchronizing token.
      2. Synchronizing token sering dipilih dari FOLLOW.
      3. Tabel dapat berisi entri `synch`.
   3. Unit deletion: buang satu unit sintaksis yang rusak.
   4. Phrase-level recovery.
      1. Sel kosong tabel dapat diisi pointer ke error routine.
      2. Error routine dapat menyisipkan/menghapus token.
   5. Context-sensitive repair.
      1. Spelling repair.
      2. Dummy identifier.

## 7. Intermediate Code / Intermediate Representation

1. Pengantar IR
   1. Posisi IR dalam pipeline compiler.
      1. Dihasilkan di akhir front end.
      2. Setelah syntax dan semantic analysis.
      3. Menjadi input optimizer atau code generator.
   2. Motivasi.
      1. Retargeting compiler.
      2. Modularitas: `m+n` komponen dibanding `m*n` compiler penuh.
      3. Machine-independent representation.
      4. Optimasi lebih mudah dilakukan pada IR.

2. Bentuk IR Tingkat Tinggi
   1. Abstract Syntax Tree.
      1. Node internal sebagai operator.
      2. Leaf sebagai operand.
   2. DAG.
      1. Node dapat memiliki lebih dari satu parent.
      2. Berguna untuk common subexpression.
      3. Dapat dibangun dengan value-number/hash node.

3. Bentuk IR Linear
   1. Postfix notation.
      1. Format operand-operand-operator.
      2. Dapat dipakai untuk evaluasi stack.
      3. Control flow memakai BZ dan BR.
   2. Three-address code.
      1. Instruksi pseudo-assembly.
      2. Satu instruksi maksimal satu operator.
      3. Ekspresi panjang dipecah ke temporary variables.

4. Struktur Implementasi 3AC
   1. Quadruples.
      1. Field: operator, operand1, operand2, result.
      2. Result eksplisit.
      3. Mudah dipindah saat optimasi.
   2. Triples.
      1. Field: operator, operand1, operand2.
      2. Hasil dirujuk dengan indeks instruksi seperti `(1)`.
      3. Sulit dipindahkan karena referensi indeks berubah.
   3. Indirect triples.
      1. Memisahkan instruction list dan execution list.
      2. Reordering cukup mengubah pointer eksekusi.

5. Address dan Operasi 3AC
   1. Address berupa nama variabel.
   2. Address berupa konstanta.
   3. Address berupa temporary variables `t1`, `t2`, dan seterusnya.
   4. Instruksi assignment biner dan unari.
   5. Copy instruction.
   6. Conditional dan unconditional jumps.
   7. Procedure/function call: `param`, `call`, `return`.

6. Syntax-Directed Translation ke IR
   1. Translasi ekspresi aritmetika dan assignment.
      1. Menggunakan lvalue dan rvalue.
      2. Menghasilkan instruksi ke temporary variable.
   2. Translasi array.
      1. Offset runtime: `base + (i - low) * w`.
      2. Load: `x = y[i]`.
      3. Store: `x[i] = y`.
   3. Translasi pointer.
      1. Address-of: `x = &y`.
      2. Dereference: `x = *y`.
      3. Indirect assignment: `*x = y`.

7. Boolean dan Control Flow
   1. Jumping code.
   2. Short-circuit evaluation.
   3. `B.true` dan `B.false`.
   4. `S.next`.
   5. Translasi `if`, `while`, dan struktur branch.

8. Backpatching
   1. Dibutuhkan ketika target jump belum diketahui pada one-pass translation.
   2. Goto rumpang disimpan dalam list.
   3. `truelist`, `falselist`, dan `nextlist`.
   4. `makelist(i)`.
   5. `merge(p1, p2)`.
   6. `backpatch(p, i)`.

9. Optimasi IR
   1. Machine-independent optimization.
   2. Local optimization.
      1. Constant folding.
      2. Redundant-subexpression elimination.
      3. Loop unrolling.
      4. Frequency reduction/code motion.
      5. Strength reduction.
   3. Global optimization.
      1. Unreachable code elimination.
      2. Dead code elimination.
      3. Unused parameter/variable cleanup.
      4. Uninitialized variable detection.

10. Relasi ke Code Generation dan UAS
    1. Temporary variable dipetakan ke register atau accumulator.
    2. Quadruple dapat ditranslasi ke single accumulator assembly.
    3. Instruksi target: `LDA`, `STO`, `ADD`, `SUB`, `MUL`.
    4. Optimasi dapat mengurangi store/load temporary yang tidak perlu.

## 8. Interpreter dan Virtual Machine

1. Sistem Pemrosesan Bahasa
   1. Compiler.
      1. Menerjemahkan source code secara utuh menjadi kode mesin/object code.
      2. Melaporkan error dalam fase kompilasi.
      3. Membutuhkan linking dengan library.
   2. Interpreter.
      1. Mengeksekusi program langsung baris demi baris atau melalui struktur internal.
      2. Dapat memakai teks, AST, atau instruksi linear.
      3. Tidak menghasilkan object code target sebagai output utama.
      4. Melaporkan error saat runtime.
   3. Perbandingan compiler dan interpreter.
      1. Compiler lebih cepat saat eksekusi.
      2. Interpreter lebih cepat untuk uji coba kecil dan diagnostik interaktif.
      3. Compiler dapat melakukan optimasi hardware lebih kuat.

2. Model Hibrida dan VM
   1. Source code dikompilasi menjadi bytecode.
   2. Bytecode dieksekusi oleh VM.
   3. Portabilitas: bytecode berjalan pada platform apa pun dengan VM kompatibel.
   4. Compiler lebih sederhana karena cukup menargetkan VM.
   5. VM mengabstraksi hardware, memory management, thread, dan I/O.
   6. JIT compiler.
      1. Mengidentifikasi hot spots.
      2. Menerjemahkan bytecode menjadi native code saat runtime.

3. Arsitektur Virtual Machine
   1. Stack-based VM.
      1. Operand dan hasil antara disimpan di stack.
      2. JVM sebagai contoh utama.
      3. Mengurangi beban compiler dalam alokasi register.
   2. Register-based VM.
      1. Memakai register virtual seperti CPU.
      2. Instruksi memiliki operand eksplisit.
   3. Instruction set dan bytecode.
      1. Bytecode memakai opcode.
      2. Opcode sering berukuran satu byte.
      3. JVM memakai typed instructions.
      4. Contoh: `iadd`, `invokevirtual`.

4. Runtime Memory Model
   1. Code area.
      1. Menyimpan executable bytecode.
   2. Run-time stack.
      1. Menyimpan frame pemanggilan fungsi.
      2. Push saat fungsi/method dipanggil.
      3. Pop saat fungsi/method selesai.
   3. Activation record / stack frame.
      1. Parameter.
      2. Local variables.
      3. Control/access links.
      4. Return value.
      5. Operand stack internal.
   4. Heap.
      1. Menyimpan objek dinamis.
      2. Objek dapat outlive frame pembuatnya.
   5. Garbage collection.
      1. Membebaskan objek unreachable.
      2. Root set.
      3. Marking phase.
      4. Sweeping phase.

5. Siklus Eksekusi Interpreter VM
   1. Fetch: ambil instruksi bytecode berikutnya.
   2. Decode: identifikasi opcode, sering melalui `switch/case`.
   3. Execute: jalankan operasi dan ubah state mesin.
   4. Overhead: dispatch dan indirect branch dapat mengganggu pipeline CPU.

6. Optimasi VM
   1. Threaded code.
      1. Mengurangi loncatan kembali ke main loop.
      2. Handler instruksi melompat langsung ke handler berikutnya.
   2. Top-of-stack caching.
      1. Menyimpan puncak stack VM di register fisik CPU.
      2. Mengurangi akses memori.
   3. Super-instructions.
      1. Static super-instructions seperti penggabungan `mul` dan `add` menjadi `madd`.
      2. Dynamic super-instructions untuk basic block tertentu.
   4. JIT HotSpot.
      1. Client compiler: cepat, optimasi ringan.
      2. Server compiler: lebih lambat, optimasi lebih dalam.

7. Relasi dengan Intermediate Code dan Code Generation
   1. Bytecode adalah IR linear level rendah.
   2. Stack-machine code membebaskan compiler dari register allocation awal.
   3. Stack-based VM sejalan dengan evaluasi postfix.
   4. JIT merupakan code generation runtime dari bytecode ke native code.
   5. Kaitan UAS: postfix, quadruple/triple, dan single accumulator assembly.

---

# Perbandingan dengan Outline Proyek LaTeX Saat Ini

Bagian ini membandingkan outline terbaru dari NotebookLM dengan outline yang sudah ada pada proyek LaTeX `Catatan-Ujian-IF2224-Teori-Bahasa-Formal-dan-Otomata`. Yang dimaksud outline proyek adalah gabungan dari:

1. `Outline Keseluruhan Materi` pada `main.tex`;
2. `Outline Fundamental Konsep Materi` pada setiap file `section/*.tex`;
3. tambahan isi yang sudah pernah dimasukkan setelah sumber NotebookLM baru ditambahkan.

## Ringkasan Umum

Secara umum, catatan LaTeX sudah mencakup seluruh delapan materi utama:

1. PDA termasuk konversi CFG;
2. CYK;
3. Mesin Turing;
4. Compiler;
5. Recursive Descent Parser;
6. LL(1) Parser;
7. Intermediate Code;
8. Interpreter dan Virtual Machine.

Namun outline NotebookLM terbaru lebih luas pada beberapa area karena sumber baru menambahkan buku teks dan slide tambahan. Perbedaan paling penting muncul pada:

1. closure properties CFL via PDA;
2. detail kompleksitas konversi CNF;
3. Mesin Turing sebagai transducer dan enumerator;
4. PCP;
5. symbol table management yang lebih rinci;
6. bottom-up parsing dan LR/Yacc;
7. optimasi compiler yang lebih luas;
8. JIT HotSpot client/server compiler.

## Tabel Perbandingan per Materi

| Materi | Status terhadap catatan LaTeX saat ini | Sudah tercakup kuat | Tambahan dari outline NotebookLM terbaru yang belum/kurang eksplisit |
|---|---|---|---|
| PDA | Hampir lengkap | Definisi formal, ID, acceptance by final state/empty stack, CFG ke PDA, PDA ke CFG, DPDA, prefix property, blow-up konversi | Closure properties CFL via PDA: intersection CFL dengan regular language, inverse homomorphism |
| CYK | Hampir lengkap | CNF, membership problem, tabel `X_ij`, basis, induksi, acceptance condition, kompleksitas `O(n^3)`/`O(n^2)` | Detail clean-up CNF lebih eksplisit: generating, reachable, nullable, unit pairs, urutan eliminasi, kompleksitas konversi CNF |
| Mesin Turing | Kuat, tetapi outline NotebookLM lebih luas | 7-tuple, transisi, ID, acceptance/halting, RE vs recursive, variasi TM, encoding, diagonalization, universal language, reduction, Rice | TM sebagai transducer fungsi integer, TM sebagai enumerator, canonical order, PCP sebagai materi undecidability tambahan |
| Compiler | Kuat untuk pipeline utama | Language processing system, front end/back end, lexical, syntax, semantic, symbol table, runtime, code generation, optimization, tools | Detail tujuan desain bahasa, bottom-up parsing/LR/Yacc, struktur symbol table rinci: tabel array, tabel blok, tabel display, real/string table |
| Recursive Descent Parser | Sangat selaras | Top-down, leftmost derivation, brute-force vs RD, satu fungsi per nonterminal, token/lookahead, backtracking, left recursion, left factoring, SDT | General left recursion bersarang dari Dragon Book masih belum eksplisit dalam outline LaTeX |
| LL(1) Parser | Sangat selaras | Arti LL(1), FIRST/FOLLOW, nullable, parsing table, konflik, nonrecursive parser, error recovery, left factoring/left recursion | Phrase-level recovery dan `synch` table entries bisa dibuat lebih eksplisit |
| Intermediate Code | Sangat selaras | Motivasi IR, AST, DAG, postfix/3AC, quadruples/triples/indirect triples, temporary, array/pointer, boolean/control flow, backpatching, optimasi, UAS | Value-number/hash node untuk DAG, uninitialized variable detection, loop invariant code motion/frequency reduction bisa ditambahkan eksplisit |
| Interpreter dan VM | Sangat selaras | Compiler/interpreter/VM, bytecode, JIT, stack/register VM, instruction set, memory model, GC, fetch-decode-execute, threaded code, top-of-stack caching, super-instructions | JIT HotSpot client/server compiler lebih rinci di NotebookLM terbaru |

## Catatan Detail Per Materi

### 1. PDA

Outline proyek LaTeX sudah menangkap inti utama PDA dan sudah diperbarui dengan sumber baru:

- definisi PDA sebagai epsilon-NFA dengan stack;
- definisi 7-tuple;
- ID dan relasi `|-`;
- final state vs empty stack;
- CFG ke PDA;
- PDA ke CFG;
- DPDA;
- prefix property;
- exponential blow-up pada konversi PDA ke CFG.

Perbedaan utama dari outline NotebookLM terbaru adalah adanya bagian closure properties:

- CFL tertutup terhadap intersection dengan regular language;
- konstruksi product antara PDA dan DFA;
- inverse homomorphism untuk CFL/PDA.

Bagian ini belum menjadi fokus eksplisit catatan LaTeX karena materi ujian awal menekankan PDA dan konversi CFG. Jika ingin catatan PDA lebih lengkap secara teori CFL, bagian closure properties dapat ditambahkan sebagai subtopik pendukung.

### 2. CYK

Outline proyek LaTeX sudah mencakup struktur utama CYK:

- membership problem;
- kebutuhan CNF;
- tabel `X_ij`;
- basis;
- induksi dengan split;
- acceptance condition `S in X_1n`;
- kompleksitas waktu dan ruang.

NotebookLM terbaru memberi detail lebih sistematis tentang proses konversi CNF:

- generating symbols;
- reachable symbols;
- nullable symbols;
- unit pairs;
- urutan eliminasi epsilon, unit, useless;
- kompleksitas konversi grammar.

Catatan LaTeX menjelaskan CNF sebagai prasyarat, tetapi belum menjadikan algoritma konversi CNF sebagai outline besar yang rinci. Ini dapat ditambahkan jika UAS menuntut transformasi grammar ke CNF secara manual.

### 3. Mesin Turing

Outline proyek LaTeX sudah kuat untuk computability:

- definisi formal;
- ID;
- acceptance by final state dan halting;
- RE vs recursive;
- teknik pemrograman TM;
- variasi TM;
- komputer riil;
- encoding;
- diagonalization;
- universal language;
- reduction;
- Rice's Theorem.

Outline NotebookLM terbaru menambahkan dua peran Mesin Turing yang belum terlalu eksplisit di outline LaTeX:

- TM sebagai transducer fungsi integer;
- TM sebagai enumerator bahasa.

NotebookLM terbaru juga memasukkan PCP sebagai topik undecidability penting. Catatan LaTeX belum membahas PCP. Jika ingin mengikuti outline terbaru secara penuh, PCP adalah tambahan paling jelas untuk section Mesin Turing.

### 4. Compiler

Outline proyek LaTeX sudah memuat pipeline compiler secara luas:

- compiler/interpreter/VM;
- language-processing system;
- front end/back end;
- lexical analysis;
- syntax dan semantic analysis;
- symbol table;
- runtime environment;
- code generation;
- machine-independent optimization;
- translator tools.

NotebookLM terbaru menambahkan detail yang lebih administratif dan implementasional:

- simplicity, orthogonality, compilability, machine independence;
- bottom-up parsing, shift-reduce, LR Parser, Yacc;
- fragmentasi symbol table: identifier table, array table, block table, real/string table, display table;
- peephole optimization.

Catatan LaTeX sudah mencakup konsep inti compiler, tetapi belum menguraikan LR/Yacc dan struktur symbol table se-rinci outline terbaru. Karena Recursive Descent dan LL(1) menjadi materi parsing utama, LR/Yacc dapat dicatat sebagai konteks, bukan prioritas utama.

### 5. Recursive Descent Parser

Outline proyek LaTeX dan outline NotebookLM terbaru sangat selaras:

- top-down parsing;
- leftmost derivation;
- brute-force parsing;
- satu fungsi per nonterminal;
- terminal matching;
- lookahead/pointer input;
- save/reset pointer;
- backtracking;
- left recursion;
- eliminasi left recursion;
- left factoring;
- hubungan ke predictive parsing;
- SDT.

Tambahan yang bisa dibuat lebih eksplisit adalah general left recursion, yaitu rekursi kiri tidak langsung/bersarang yang melewati nonterminal lain. Catatan LaTeX sudah menyebut rekursi kiri tidak langsung dalam catatan, tetapi outline fundamentalnya belum menonjolkan algoritma general elimination.

### 6. LL(1) Parser

Outline proyek LaTeX sudah mencakup hampir semua yang muncul di NotebookLM terbaru:

- makna LL(1);
- hubungan dengan top-down/RD;
- FIRST;
- FOLLOW;
- nullable/epsilon;
- endmarker;
- tabel parsing;
- konflik;
- syarat grammar LL(1);
- stack parser;
- error handling/recovery.

NotebookLM terbaru memberi penekanan tambahan pada:

- syarat formal disjoint FIRST/FOLLOW dari Dragon Book;
- `synch` entries untuk panic-mode recovery;
- phrase-level recovery melalui error routines.

Catatan LaTeX sudah membahas error recovery, tetapi dapat diperkaya dengan istilah `synch` dan phrase-level recovery jika ingin lebih dekat ke Dragon Book.

### 7. Intermediate Code

Outline proyek LaTeX sudah sangat selaras dengan NotebookLM terbaru:

- motivasi IR;
- posisi dalam pipeline;
- AST;
- DAG;
- 3AC;
- quadruples;
- triples;
- indirect triples;
- temporary variables;
- array;
- pointer;
- boolean/control flow;
- backpatching;
- kaitan UAS.

Tambahan NotebookLM terbaru yang belum sangat eksplisit:

- value-number/hash node untuk konstruksi DAG;
- uninitialized variable detection;
- frequency reduction/code motion sebagai loop invariant optimization;
- loop unrolling dan strength reduction sebagai daftar optimasi lokal yang lebih luas.

Bagian optimasi di catatan Intermediate Code bisa diperluas bila ingin catatan menjawab soal optimasi IR lebih banyak.

### 8. Interpreter dan Virtual Machine

Outline proyek LaTeX sudah mencakup:

- compiler vs interpreter vs VM;
- bytecode;
- JIT;
- model hibrida;
- stack-based VM;
- register-based VM;
- instruction set;
- runtime memory model;
- stack frame;
- operand stack;
- local variables;
- heap;
- garbage collection;
- fetch-decode-execute loop;
- threaded code;
- top-of-stack caching;
- super-instructions;
- relasi dengan IR/code generation.

Tambahan NotebookLM terbaru yang lebih rinci:

- HotSpot client compiler vs server compiler;
- optimasi JIT berdasarkan hot spots;
- relasi lebih eksplisit dengan testing/diagnostik interpreter.

Catatan LaTeX sudah cukup untuk inti materi VM. Penambahan HotSpot client/server bersifat pengayaan, bukan fondasi.

## Kesimpulan Perbandingan

Outline proyek LaTeX saat ini sudah mencakup seluruh materi utama dan sebagian besar tambahan dari sumber baru. Jika ingin menyelaraskan sepenuhnya dengan outline NotebookLM terbaru, prioritas revisi yang paling masuk akal adalah:

1. Tambahkan closure properties CFL pada PDA sebagai subtopik pendukung.
2. Tambahkan detail algoritma konversi CNF pada CYK.
3. Tambahkan TM sebagai enumerator/transducer dan PCP pada Mesin Turing.
4. Tambahkan struktur symbol table yang lebih rinci pada Compiler.
5. Tambahkan `synch` dan phrase-level recovery pada LL(1).
6. Tambahkan value-number DAG dan optimasi IR tambahan pada Intermediate Code.
7. Tambahkan HotSpot client/server JIT sebagai catatan pengayaan pada Interpreter dan VM.

Secara prioritas ujian, gap paling penting adalah:

1. PCP jika dosen menekankan undecidability lanjutan.
2. Konversi CNF rinci jika soal meminta transformasi grammar sebelum CYK.
3. Detail symbol table dan error recovery jika soal compiler lebih implementasional.
4. Closure properties CFL jika soal PDA/CFL keluar lebih teoretis daripada konstruktif.
