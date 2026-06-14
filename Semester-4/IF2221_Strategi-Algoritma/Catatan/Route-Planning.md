# Route Planning — IF2211 Strategi Algoritma

---

## Outline Keseluruhan Materi (High-Level Overview)

Materi ini terbagi menjadi dua kelompok besar berdasarkan apakah algoritma memiliki informasi tambahan tentang jarak ke tujuan.

```
Route / Path Planning
├── 1. Uninformed Search (Pencarian Buta)
│   ├── Breadth-First Search (BFS)
│   ├── Depth-First Search (DFS)
│   ├── Depth-Limited Search (DLS)
│   ├── Iterative Deepening Search (IDS)
│   └── Uniform Cost Search (UCS)
│
└── 2. Informed Search (Pencarian Heuristik)
    ├── Greedy Best-First Search
    ├── A* (A Star)
    ├── Admissible & Consistent Heuristics
    └── Branch-and-Bound vs A*
```

**Studi Kasus yang Digunakan:**
- Peta Romania (Arad → Bucharest)
- Penyelesaian 8-Puzzle
- Pencarian Rute Entitas Video Game (A → F)

---
---

## Pencarian Rute Dasar — Uninformed Search

### Hubungan dengan CPMK

> Materi ini berkaitan dengan CPMK kemampuan **menerapkan strategi algoritma pencarian** untuk menemukan solusi optimal maupun sub-optimal pada ruang keadaan (*state space*). Mahasiswa diharapkan mampu memilih algoritma yang tepat berdasarkan sifat masalah (apakah bobot seragam atau tidak, apakah memori terbatas, dsb.) serta menganalisis kompleksitas waktu dan ruang dari masing-masing algoritma.

---

### Outline Konsep Fundamental

- **Uninformed Search (Pencarian Buta)**
  - Definisi: pencarian tanpa informasi tambahan tentang jarak ke tujuan
  - Representasi: pohon pencarian / graf dengan simpul dan sisi
  - Struktur data agenda: Queue (FIFO) vs Stack (LIFO)
  - **BFS** — eksplorasi level-by-level dengan Queue
  - **DFS** — eksplorasi sedalam mungkin dengan Stack
    - **DLS** — DFS dengan batas kedalaman (*cutoff*)
    - **IDS** — DLS berulang dengan kedalaman bertambah
  - **UCS** — eksplorasi berdasarkan biaya akumulatif minimum
- **Perbandingan Properti Algoritma**
  - Complete, Optimal, Time Complexity, Space Complexity
- **Studi Kasus**
  - Peta Romania (Arad → Bucharest)
  - Video Game Entitas (A → F)

---

### Penjelasan Materi

---

#### Konsep Dasar Uninformed Search

**TL;DR:** *Uninformed Search mengeksplorasi ruang keadaan tanpa mengetahui seberapa dekat suatu simpul dengan tujuan.*

Uninformed Search, atau sering disebut *blind search*, adalah kelompok algoritma pencarian yang beroperasi tanpa memiliki informasi tambahan mengenai estimasi jarak suatu simpul menuju tujuan. Algoritma ini hanya mengetahui definisi masalah — yaitu *state* awal, *state* tujuan, dan aksi-aksi yang mungkin dilakukan — tanpa memiliki petunjuk arah mana yang "lebih menjanjikan."

Representasi masalah dalam uninformed search menggunakan **pohon pencarian** (*search tree*) atau **graf**, di mana:
- **Simpul (*node*)** merepresentasikan suatu keadaan (*state*)
- **Sisi (*edge*)** merepresentasikan aksi atau transisi antar keadaan, dengan bobot yang mungkin sama atau berbeda
- **Agenda** adalah struktur data yang menyimpan simpul-simpul yang menunggu untuk diekspansi

Perbedaan utama antar algoritma dalam kelompok ini terletak pada **urutan ekspansi simpul**, yang ditentukan oleh struktur data agenda yang digunakan.

---

#### Breadth-First Search (BFS)

**TL;DR:** *BFS mengeksplorasi semua simpul di level yang sama sebelum turun ke level berikutnya, menjamin jalur dengan langkah paling sedikit.*

BFS adalah algoritma pencarian yang memanfaatkan **Queue (antrian) dengan prinsip FIFO** (*First-In First-Out*) sebagai agenda. Akibatnya, semua simpul di kedalaman `d` akan diekspansi sebelum simpul manapun di kedalaman `d+1` diekspansi.

**Cara Kerja Step-by-Step:**
1. Masukkan simpul awal ke dalam Queue
2. Ambil simpul paling depan dari Queue (FIFO)
3. Cek: apakah simpul ini adalah tujuan? Jika ya, selesai
4. Ekspansi: masukkan semua successor simpul ini ke belakang Queue
5. Ulangi dari langkah 2

**Contoh (Peta Romania, Arad → Bucharest):**
- Iterasi 1: Ekspansi Arad → Queue: [Zerind(A), Sibiu(A), Timisoara(A)]
- Iterasi 2: Ekspansi Zerind → Queue: [Sibiu(A), Timisoara(A), Oradea(AZ), Arad(AZ)]
- ... berlanjut hingga Bucharest ditemukan
- **Hasil:** Arad → Sibiu → Fagaras → Bucharest, total biaya = **450**

**Properti:**

| Properti | Nilai | Keterangan |
|---|---|---|
| **Complete?** | ✅ Ya | Selalu menemukan solusi jika ada |
| **Optimal?** | ⚠️ Hanya jika semua bobot sama | Jika bobot berbeda, tidak menjamin solusi termurah |
| **Time Complexity** | O(b^d) | b = branching factor, d = kedalaman solusi |
| **Space Complexity** | O(b^d) | Menyimpan semua simpul di level terkini — sangat boros memori |

- **Kelebihan:** Dijamin menemukan solusi jika ada; menemukan jalur dengan langkah paling sedikit
- **Kekurangan:** Konsumsi memori sangat besar — untuk `b=10, d=12`, memori yang dibutuhkan bisa mencapai terabyte

---

#### Depth-First Search (DFS)

**TL;DR:** *DFS mengeksplorasi cabang sedalam mungkin sebelum mundur, sangat hemat memori tapi tidak menjamin solusi optimal.*

DFS memanfaatkan **Stack (tumpukan) dengan prinsip LIFO** (*Last-In First-Out*) sebagai agenda. Algoritma ini terus masuk ke cabang terdalam sebelum melakukan *backtracking* ke simpul yang belum diekspansi.

**Cara Kerja Step-by-Step:**
1. Masukkan simpul awal ke Stack
2. Ambil simpul paling atas dari Stack (LIFO)
3. Cek: apakah simpul ini adalah tujuan? Jika ya, selesai
4. Ekspansi: masukkan semua successor simpul ini ke atas Stack
5. Ulangi dari langkah 2

**Contoh (Peta Romania, Arad → Bucharest):**
- Iterasi 1: A → Stack: [ZA, SA, TA]
- Iterasi 2: Ekspansi ZA → Stack: [OAZ, AAZ, SA, TA]
- Iterasi 3: Ekspansi OAZ → Stack: [SAZO, AAZ, SA, TA]
- ... berlanjut masuk ke cabang terdalam
- **Hasil:** A → Z → O → S → F → B, total biaya = **607** *(jauh dari optimal)*

**Properti:**

| Properti | Nilai | Keterangan |
|---|---|---|
| **Complete?** | ❌ Tidak | Dapat terjebak di jalur tak terbatas / siklus |
| **Optimal?** | ❌ Tidak | Tidak menjamin jalur terpendek |
| **Time Complexity** | O(b^m) | m = kedalaman maksimum pohon |
| **Space Complexity** | O(bm) | Hanya menyimpan satu jalur aktif — sangat hemat memori |

- **Kelebihan:** Efisiensi memori jauh lebih baik dibanding BFS
- **Kekurangan:** Bisa terjebak *infinite loop*; hasil tidak optimal

---

#### Depth-Limited Search (DLS)

**TL;DR:** *DLS adalah DFS yang dibatasi kedalaman maksimumnya untuk mencegah infinite loop.*

DLS adalah modifikasi dari DFS yang menambahkan parameter **batas kedalaman (limit/cutoff)**. Ketika pencarian mencapai kedalaman sebesar limit, ekspansi dihentikan di cabang tersebut dan dilakukan *backtracking*. Ini menyelesaikan masalah utama DFS yaitu kemungkinan terjebak di jalur tak hingga.

**Cara Kerja:**
- Sama persis dengan DFS, namun sebelum mengekspansi simpul, dilakukan pengecekan:
  - Jika `depth(simpul) == limit` → kembalikan *cutoff* (tidak ekspansi)
  - Jika `depth(simpul) < limit` → ekspansi normal

**Properti:**

| Properti | Nilai | Keterangan |
|---|---|---|
| **Complete?** | ✅ Ya, jika `d ≤ limit` | Gagal jika solusi lebih dalam dari limit |
| **Optimal?** | ❌ Tidak | |
| **Time Complexity** | O(b^l) | l = nilai limit |
| **Space Complexity** | O(bl) | |

- **Kelebihan:** Mencegah infinite loop dari DFS biasa
- **Kekurangan:** Jika limit terlalu dangkal, solusi tidak akan ditemukan; memilih limit yang tepat butuh pengetahuan domain

---

#### Iterative Deepening Search (IDS)

**TL;DR:** *IDS menjalankan DLS berulang kali dengan limit yang terus bertambah, menggabungkan efisiensi memori DFS dengan completeness dan optimality BFS.*

IDS secara sistematis meningkatkan batas kedalaman dari 0, 1, 2, 3, ... hingga solusi ditemukan. Di setiap iterasi, IDS menjalankan DLS dari awal dengan limit baru. Seperti BFS, IDS akan menemukan rute dengan **jumlah langkah paling sedikit**.

**Cara Kerja Step-by-Step (Contoh Peta Romania):**
- **Depth = 0:** Evaluasi A saja → *cutoff*
- **Depth = 1:** Ekspansi A → [ZA, SA, TA], masing-masing → *cutoff*
- **Depth = 2:** Ekspansi satu level lebih dalam → *cutoff*
- **Depth = 3:** Terus berlanjut hingga Bucharest ditemukan

**Properti:**

| Properti | Nilai | Keterangan |
|---|---|---|
| **Complete?** | ✅ Ya | Pasti menemukan solusi |
| **Optimal?** | ✅ Ya (untuk jumlah langkah) | |
| **Time Complexity** | O(b^d) | Sama dengan BFS meski mengulang ekspansi |
| **Space Complexity** | O(bd) | Hemat memori seperti DFS |

- **Kelebihan:** Memori efisien (DFS) sekaligus komplit dan optimal (BFS) — kombinasi terbaik dari keduanya
- **Kekurangan:** Mengulang ekspansi simpul-simpul dangkal di setiap iterasi (namun overhead-nya kecil secara asimtotik pada pohon eksponensial)

> **Catatan penting:** IDS mengulang ekspansi simpul di level atas, tapi ini tidak masalah karena jumlah simpul di level-level dangkal jauh lebih sedikit dibanding level terdalam.

---

#### Uniform Cost Search (UCS)

**TL;DR:** *UCS selalu mengekspansi simpul dengan akumulasi biaya terkecil dari akar, menjamin jalur berbiaya minimum pada graf berbobot.*

UCS adalah algoritma pencarian *shortest path* yang menggunakan **fungsi evaluasi f(n) = g(n)**, di mana `g(n)` adalah **akumulasi biaya** dari simpul akar menuju simpul `n`. Berbeda dengan BFS yang meminimalkan jumlah langkah, UCS meminimalkan total biaya perjalanan — sehingga lebih cocok untuk graf dengan bobot sisi yang bervariasi.

**Cara Kerja Step-by-Step:**
1. Masukkan simpul awal dengan `f = 0` ke *priority queue* (terurut berdasarkan f terkecil)
2. Ambil simpul dengan nilai `f(n)` terkecil
3. Cek: apakah simpul ini adalah tujuan? Jika ya, selesai
4. Hitung `g(successor) = g(n) + cost(n → successor)` untuk setiap penerus
5. Masukkan penerus ke *priority queue*
6. Ulangi dari langkah 2

**Contoh (Peta Romania, Arad → Bucharest):**
- Iterasi 1: Ekspansi Arad (f=0) → Zerind(f=75), Sibiu(f=140), Timisoara(f=118)
- Iterasi 2: Ekspansi Zerind(f=75) karena terkecil → Oradea(f=146)
- Iterasi 3: Ekspansi Timisoara(f=118) → ...
- ... terus mengekspansi yang paling murah
- **Hasil:** A → S → R → P → B *(optimal)*

**Contoh (Video Game, A → F):**
- Iterasi 1: Ekspansi A → B(f=2), C(f=4), E(f=5)
- Iterasi 2: Ekspansi B(f=2) karena terkecil → E via B (f=3)
- Iterasi 3: Ekspansi E via B (f=3) → F(f=5), D(f=6)
- ... berlanjut 6 iterasi total
- **Hasil:** A → B → E → F, total jarak = **5**, jumlah iterasi = **6**

**Properti:**

| Properti | Nilai | Keterangan |
|---|---|---|
| **Complete?** | ✅ Ya (jika semua bobot > 0) | |
| **Optimal?** | ✅ Ya | Selalu menjamin jalur berbiaya minimum |
| **Time Complexity** | O(b^(1+⌊C*/ε⌋)) | C* = biaya solusi optimal, ε = bobot minimum |
| **Space Complexity** | O(b^(1+⌊C*/ε⌋)) | Bisa sangat besar |

- **Kelebihan:** Optimal untuk graf berbobot tak seragam
- **Kekurangan:** Mengekspansi ke segala arah tanpa "tahu" di mana tujuan — bisa sangat lambat

---

### Komponen Kunci

| Istilah | Definisi |
|---|---|
| **Uninformed Search** | Algoritma pencarian tanpa informasi estimasi jarak ke tujuan |
| **State Space** | Ruang semua kemungkinan keadaan yang dapat dicapai dari keadaan awal |
| **Search Tree** | Representasi pohon dari ruang pencarian |
| **Agenda / Frontier** | Struktur data yang menyimpan simpul yang menunggu diekspansi |
| **FIFO (Queue)** | First-In First-Out — digunakan BFS |
| **LIFO (Stack)** | Last-In First-Out — digunakan DFS |
| **Priority Queue** | Antrian berdasarkan prioritas — digunakan UCS |
| **g(n)** | Biaya aktual dari simpul akar ke simpul n |
| **f(n) = g(n)** | Fungsi evaluasi UCS |
| **Branching factor (b)** | Jumlah rata-rata successor dari setiap simpul |
| **Depth (d)** | Kedalaman solusi di pohon pencarian |
| **Complete** | Algoritma pasti menemukan solusi jika solusi ada |
| **Optimal** | Algoritma pasti menemukan solusi terbaik (biaya minimum) |
| **Cutoff** | Penghentian pencarian di cabang tertentu karena batas kedalaman |
| **Backtracking** | Kembali ke simpul sebelumnya ketika cabang tidak berhasil |

---

### Checklist Pemahaman

**Sub-materi yang telah dibahas:**
1. Konsep Dasar Uninformed Search
2. Breadth-First Search (BFS)
3. Depth-First Search (DFS)
4. Depth-Limited Search (DLS)
5. Iterative Deepening Search (IDS)
6. Uniform Cost Search (UCS)

**Prioritas Belajar:**

- 🔴 *Wajib dikuasai*
  - Cara kerja BFS dan DFS (termasuk struktur data yang digunakan)
  - UCS — fungsi evaluasi `f(n) = g(n)` dan cara kerjanya
  - Tabel perbandingan Complete vs Optimal setiap algoritma
  - Simulasi langkah-langkah ekspansi (terutama contoh video game)

- 🟡 *Cukup paham konsep*
  - DLS dan IDS — cukup paham hubungannya satu sama lain dan dengan BFS/DFS
  - Kompleksitas waktu dan ruang (O-notation) setiap algoritma
  - Kapan memilih algoritma mana berdasarkan sifat masalah

---
---

## Pencarian Rute Kompleks — Informed Search (Heuristic Search)

### Hubungan dengan CPMK

> Materi ini berkaitan dengan CPMK kemampuan **menerapkan fungsi heuristik** untuk meningkatkan efisiensi pencarian rute. Mahasiswa diharapkan mampu memahami cara mendefinisikan dan mengevaluasi kualitas heuristik (admissible, consistent), serta menganalisis trade-off antara efisiensi dan optimalitas pada berbagai algoritma informed search.

---

### Outline Konsep Fundamental

- **Informed Search (Pencarian Heuristik)**
  - Definisi: pencarian dengan fungsi evaluasi yang memestimasi jarak ke tujuan
  - Fungsi evaluasi `f(n)`: mengukur "nilai" suatu simpul
  - Heuristik `h(n)`: estimasi biaya dari simpul n ke tujuan
  - **Greedy Best-First Search** — hanya menggunakan `h(n)`
    - Kelemahan: tidak komplit, local minima, irrevocable
  - **A* (A Star)** — menggabungkan `g(n) + h(n)`
    - Cara kerja dan perbandingan dengan UCS dan Greedy
  - **Kualitas Heuristik**
    - Admissible Heuristics: `h(n) ≤ h*(n)`
    - Consistent / Monotone Heuristics
    - Contoh: Manhattan Distance untuk 8-Puzzle
  - **Branch-and-Bound vs A***
- **Studi Kasus Perbandingan**
  - Peta Romania: Greedy vs A*
  - Video Game: UCS vs Greedy vs A*

---

### Penjelasan Materi

---

#### Konsep Dasar Informed Search

**TL;DR:** *Informed Search menggunakan fungsi heuristik h(n) untuk "menebak" arah yang lebih menjanjikan, sehingga pencarian lebih efisien.*

Berbeda dengan uninformed search, Informed Search atau *Heuristic Search* menggunakan **fungsi evaluasi** yang memanfaatkan pengetahuan tambahan tentang ruang pencarian. Pengetahuan ini dikodekan dalam **fungsi heuristik h(n)**, yaitu estimasi biaya dari simpul `n` menuju tujuan.

Dengan h(n), algoritma dapat "memprioritaskan" simpul yang lebih dekat dengan tujuan, mengurangi jumlah simpul yang perlu diekspansi secara signifikan dibanding uninformed search.

**Kerangka umum fungsi evaluasi:**

| Fungsi | Algoritma |
|---|---|
| `f(n) = g(n)` | Uniform Cost Search (UCS) |
| `f(n) = h(n)` | Greedy Best-First Search |
| `f(n) = g(n) + h(n)` | A* |

---

#### Greedy Best-First Search

**TL;DR:** *Greedy hanya mempertimbangkan estimasi jarak ke tujuan dan mengabaikan biaya yang sudah ditempuh, membuatnya cepat tapi tidak menjamin hasil optimal.*

Greedy Best-First Search menggunakan fungsi evaluasi **f(n) = h(n)**, di mana `h(n)` adalah estimasi biaya dari simpul `n` ke tujuan. Pada setiap iterasi, algoritma selalu mengekspansi simpul yang *kelihatan* paling dekat dengan tujuan berdasarkan nilai `h(n)` terkecil.

**Cara Kerja:**
1. Hitung `h(n)` untuk semua penerus dari simpul yang diekspansi
2. Pilih simpul dengan `h(n)` terkecil untuk diekspansi selanjutnya
3. Ulangi hingga tujuan ditemukan

**Contoh (Peta Romania, Arad → Bucharest) — h = straight-line distance ke Bucharest:**
- Iterasi 1: Ekspansi Arad → Sibiu(h=253), Timisoara(h=329), Zerind(h=374) → pilih **Sibiu**
- Iterasi 2: Ekspansi Sibiu → Fagaras(h=176), Rimnicu Vilcea(h=193), Oradea(h=380) → pilih **Fagaras**
- Iterasi 3: Ekspansi Fagaras → Bucharest(h=0) → **Selesai**
- **Hasil:** A → Sibiu → Fagaras → Bucharest, biaya total = **450** *(tidak optimal, hanya kebetulan sama)*

**Kelemahan Greedy Best-First Search:**
- **Tidak Komplit (*Not Complete*):** Dapat gagal menemukan solusi; contoh: pencarian dari Lasi ke Fagaras dapat terjebak dalam siklus tak terhingga
- **Terjebak di Local Minima / Plateau:** Ketika semua simpul tetangga memiliki nilai `h` lebih buruk atau sama, pencarian terhenti di jalan buntu
- **Irrevocable:** Langkah yang sudah diambil tidak dapat dibatalkan — jika memilih arah yang salah, algoritma tidak dapat kembali dan mencoba jalur lain yang lebih baik

---

#### A* (A Star)

**TL;DR:** *A* menggabungkan biaya aktual g(n) dan estimasi heuristik h(n) sehingga menjamin solusi optimal selama heuristiknya admissible.*

A* menggunakan fungsi evaluasi **f(n) = g(n) + h(n)**, menggabungkan dua komponen:
- **g(n):** biaya aktual dari akar ke simpul n (sudah pasti/diketahui)
- **h(n):** estimasi biaya dari simpul n ke tujuan (perkiraan)
- **f(n):** estimasi total biaya jalur dari akar, melalui n, hingga ke tujuan

Dengan memperhitungkan biaya yang sudah ditempuh (`g`), A* menghindari kesalahan Greedy yang bisa mengambil jalur "tampak dekat" tapi sebenarnya mahal.

**Cara Kerja Step-by-Step (Peta Romania, Arad → Bucharest):**

| Iterasi | Ekspansi                          | Simpul yang Dievaluasi          | f(n) = g + h          |
| ------- | --------------------------------- | ------------------------------- | --------------------- |
| 1       | **Arad** (f=366)                  | Sibiu, Timisoara, Zerind        | 393, 447, 449         |
| 2       | **Sibiu** (f=393)                 | Rimnicu Vilcea, Fagaras, Oradea | 413, 415, 671         |
| 3       | **Rimnicu Vilcea** (f=413)        | Pitesti, Craiova                | 417, 526              |
| 4       | **Fagaras** (f=415)               | Bucharest                       | 450                   |
| 5       | **Pitesti** (f=417)               | Bucharest via Pitesti           | 418                   |
| 6       | **Bucharest via Pitesti** (f=418) | —                               | **Solusi ditemukan!** |

- **Hasil:** A → Sibiu → Rimnicu Vilcea → Pitesti → Bucharest, biaya = **418** *(optimal)*

> Perhatikan iterasi 4-5: A* memilih Pitesti (f=417) sebelum Bucharest via Fagaras (f=450) karena 417 < 450, sehingga akhirnya menemukan jalur lebih murah melalui Pitesti.

**Properti A*:**

| Properti | Nilai | Syarat |
|---|---|---|
| **Complete?** | ✅ Ya | Selalu menemukan solusi jika ada |
| **Optimal?** | ✅ Ya | *Asalkan* heuristik bersifat **admissible** |
| **Time Complexity** | O(b^d) dalam kasus terburuk | Bisa jauh lebih baik dengan heuristik baik |
| **Space Complexity** | O(b^d) | Menyimpan semua simpul di frontier |

**Contoh (Video Game, A → F):**
- Iterasi 1: Ekspansi A → B(f=4), C(f=6), E(f=6)
- Iterasi 2: Ekspansi B(f=4) → E via B(f=4), C(f=6), E dari A(f=6)
- Iterasi 3: Ekspansi E via B (f=4) → F(f=5), C(f=6), D(f=7), E dari A(f=6)
- Iterasi 4: Ekspansi F(f=5) → **Solusi ditemukan!**
- **Hasil:** A → B → E → F, total jarak = **5**, jumlah iterasi = **4**

---

#### Admissible Heuristics

**TL;DR:** *Heuristik admissible tidak pernah melebih-lebihkan biaya sebenarnya ke tujuan — ini syarat wajib agar A* menjamin solusi optimal.*

Sebuah fungsi heuristik `h(n)` dikatakan **admissible** jika untuk setiap simpul `n`, nilai estimasinya tidak pernah melebihi biaya optimal sebenarnya:

> **h(n) ≤ h\*(n)**
>
> di mana **h\*(n)** adalah biaya optimal sesungguhnya dari simpul n ke tujuan.

Heuristik yang admissible bersifat **selalu optimis** — ia tidak pernah melebih-lebihkan kesulitan untuk mencapai tujuan. Agar A* **dijamin komplit dan optimal**, heuristik yang digunakan wajib bersifat admissible.

**Contoh heuristik admissible:**
- **Straight-Line Distance (h_SLD):** jarak garis lurus ke tujuan — tidak pernah lebih besar dari jarak jalan sebenarnya
- **Manhattan Distance:** untuk 8-puzzle, jumlah langkah ubin secara horizontal+vertikal ke posisi tujuan

**Consistent (Monotone) Heuristics:**
Heuristik `h` dikatakan *consistent* jika untuk setiap simpul `n` dan penerusnya `n'`:

> **h(n) ≤ cost(n → n') + h(n')**

Artinya, estimasi dari `n` tidak lebih besar dari biaya satu langkah ke `n'` ditambah estimasi dari `n'`. Setiap heuristik yang *consistent* pasti juga *admissible*, tapi tidak sebaliknya.

---

#### Contoh Heuristik: Manhattan Distance (8-Puzzle)

**TL;DR:** *Manhattan Distance menghitung total perpindahan horizontal dan vertikal setiap ubin ke posisi tujuannya, merupakan heuristik admissible untuk 8-Puzzle.*

Pada persoalan 8-Puzzle, **biaya (path cost)** adalah banyaknya langkah ubin kosong yang telah dilakukan. Heuristik **Manhattan Distance** dihitung sebagai:

> Untuk setiap ubin (kecuali ubin kosong), hitung berapa banyak langkah horizontal + vertikal yang diperlukan untuk memindahkan ubin tersebut ke posisi tujuannya, lalu jumlahkan semua nilai tersebut.

**Contoh:**
```
State saat ini:        State Tujuan:
[ 7 | 2 | 4 ]         [ 1 | 2 | 3 ]
[ 5 |   | 6 ]         [ 4 | 5 | 6 ]
[ 8 | 3 | 1 ]         [ 7 | 8 |   ]
```

Manhattan Distance untuk state ini menghitung perpindahan setiap ubin dari posisi sekarang ke posisi target, lalu dijumlahkan. Hasilnya adalah heuristik yang admissible karena ubin tidak bisa berpindah secara diagonal.

---

#### Branch-and-Bound vs A*

**TL;DR:** *Branch-and-Bound identik dengan A* ketika pencarian dilakukan secara best-first dengan fungsi (biaya + bound heuristik).*

**Branch-and-Bound (B&B)** adalah metode optimasi yang bekerja dengan cara:
- Menghitung **bound** (batas bawah) yang dijamin lebih rendah dari biaya sebenarnya
- Memotong (*prune/cutoff*) cabang pencarian jika `biaya saat ini + bound > solusi terbaik yang sudah ditemukan`

**Hubungan dengan A*:**
- Jika fungsi evaluasi B&B adalah **biaya + bound** (yaitu `g(n) + h(n)`)
- Dan pencariannya dilakukan dengan pendekatan **best-first** (selalu ekspansi node dengan nilai terkecil)
- Maka **B&B secara fundamental identik dengan A***

---

### Komponen Kunci

| Istilah | Definisi |
|---|---|
| **Informed Search** | Algoritma pencarian yang menggunakan pengetahuan tambahan (heuristik) tentang domain |
| **Heuristik h(n)** | Fungsi estimasi biaya dari simpul n ke tujuan |
| **g(n)** | Biaya aktual dari akar ke simpul n |
| **f(n) = g(n) + h(n)** | Fungsi evaluasi A* |
| **Greedy Best-First** | Pencarian yang hanya menggunakan f(n) = h(n) |
| **A* (A Star)** | Pencarian yang menggunakan f(n) = g(n) + h(n) |
| **Admissible** | Heuristik yang tidak pernah melebih-lebihkan biaya: h(n) ≤ h*(n) |
| **h*(n)** | Biaya optimal sebenarnya dari n ke tujuan |
| **Consistent / Monotone** | Heuristik yang memenuhi h(n) ≤ cost(n→n') + h(n') |
| **Local Minima** | Keadaan di mana semua simpul tetangga lebih buruk, sehingga pencarian terhenti |
| **Irrevocable** | Langkah yang tidak dapat dibatalkan setelah diambil |
| **Manhattan Distance** | Heuristik 8-puzzle: jumlah perpindahan horizontal+vertikal setiap ubin ke posisi target |
| **h_SLD** | Straight-Line Distance — jarak garis lurus sebagai heuristik |
| **Branch-and-Bound** | Metode optimasi yang identik dengan A* jika menggunakan best-first search |

---

### Komponen Kunci: Tabel Perbandingan Lengkap

| Algoritma | f(n) | Complete | Optimal | Time | Space | Catatan |
|---|---|---|---|---|---|---|
| **BFS** | — (level order) | ✅ Ya | ⚠️ Hanya jika bobot sama | O(b^d) | O(b^d) | Sangat boros memori |
| **DFS** | — (LIFO) | ❌ Tidak | ❌ Tidak | O(b^m) | O(bm) | Hemat memori |
| **DLS** | — (DFS + limit) | ✅ Jika d ≤ limit | ❌ Tidak | O(b^l) | O(bl) | — |
| **IDS** | — (iterative DLS) | ✅ Ya | ✅ Ya (langkah) | O(b^d) | O(bd) | Terbaik di uninformed |
| **UCS** | g(n) | ✅ Ya | ✅ Ya | O(b^C*/ε) | O(b^C*/ε) | Optimal untuk bobot berbeda |
| **Greedy** | h(n) | ❌ Tidak | ❌ Tidak | O(b^m) | O(b^m) | Cepat tapi tidak andal |
| **A*** | g(n)+h(n) | ✅ Ya | ✅ Ya (jika admissible) | O(b^d) | O(b^d) | Terbaik di informed |

---

### Checklist Pemahaman

**Sub-materi yang telah dibahas:**
1. Konsep Dasar Informed Search dan Fungsi Evaluasi
2. Greedy Best-First Search dan kelemahannya
3. A* (A Star) — cara kerja dan fungsi evaluasi
4. Admissible Heuristics
5. Consistent / Monotone Heuristics
6. Manhattan Distance untuk 8-Puzzle
7. Branch-and-Bound vs A*
8. Perbandingan Greedy vs A* (Peta Romania)
9. Perbandingan UCS vs Greedy vs A* (Video Game)

**Prioritas Belajar:**

- 🔴 *Wajib dikuasai*
  - Fungsi evaluasi: `f(n) = g(n)` (UCS), `f(n) = h(n)` (Greedy), `f(n) = g(n) + h(n)` (A*)
  - Definisi admissible heuristic: `h(n) ≤ h*(n)`
  - Simulasi A* step-by-step (terutama contoh video game dan Romania)
  - Mengapa A* optimal sedangkan Greedy tidak
  - Perbandingan jumlah iterasi: UCS(6) vs Greedy(3) vs A*(4) pada video game

- 🟡 *Cukup paham konsep*
  - Consistent/monotone heuristics dan perbedaannya dengan admissible
  - Manhattan Distance sebagai contoh heuristik konkret
  - Hubungan Branch-and-Bound dengan A*
  - Kelemahan spesifik Greedy (not complete, local minima, irrevocable)
