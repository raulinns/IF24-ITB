# Properties of Regular Language

---

### Hubungan dengan CPMK

> **CPMK 1** — Materi ini menjelaskan *batas kemampuan* Regular Language: apa yang bisa dan tidak bisa direpresentasikan. Pumping Lemma adalah alat formal untuk membuktikan keterbatasan tersebut. Closure dan Decision Properties menunjukkan operasi apa yang "aman" dilakukan pada Regular Language.

---

### Outline Konsep Fundamental

- **Pumping Lemma**
  - Pernyataan formal (tiga kondisi)
  - Proof by contradiction (adversarial game)
  - Contoh pembuktian: L = {0ⁿ1ⁿ}
- **Closure Properties**
  - Union, Concatenation, Kleene Star *(via RE)*
  - Complement *(via DFA state flip)*
  - Intersection, Difference *(via DeMorgan / product construction)*
  - Reversal *(via FA reversal)*
  - Homomorphism, Inverse Homomorphism
- **Decision Properties**
  - Emptiness Test (L = ∅?)
  - Membership Test (w ∈ L?)
  - Equivalence Test (L = M?)
- **DFA Minimization**
  - Algoritma Table-Filling
  - Equivalence classes → state minimal

---

### Penjelasan Materi

---

#### Pumping Lemma

**TL;DR:** *Jika suatu bahasa reguler, maka string yang cukup panjang di dalamnya PASTI bisa "dipompa" — jika tidak bisa, bahasa itu bukan reguler.*

Pumping Lemma adalah teorema yang digunakan sebagai **alat bukti kontradiksi** untuk menunjukkan bahwa suatu bahasa *bukan* Regular Language.

**Pernyataan formal:**

> Jika L adalah bahasa reguler, maka ∃ konstanta n (bergantung pada L) sedemikian sehingga untuk setiap string w ∈ L dengan |w| ≥ n, w dapat dipecah menjadi **w = xyz** yang memenuhi:
> 1. **y ≠ ε** *(bagian yang dipompa tidak boleh kosong)*
> 2. **|xy| ≤ n** *(pemompaan terjadi di n karakter pertama)*
> 3. **∀k ≥ 0, xyᵏz ∈ L** *(y boleh diulang berapa kali saja, hasilnya tetap di L)*

**Cara menggunakan — Adversarial Game (Proof by Contradiction):**

Proses pembuktian dimodelkan seperti permainan dua pemain:

1. **Asumsikan** L adalah bahasa reguler
2. **"Lawan"** (Pumping Lemma) memberikan konstanta n
3. **Kita pilih** string spesifik w ∈ L dengan |w| ≥ n *(pilih dengan cermat!)*
4. **"Lawan" memecah** w = xyz, mematuhi y ≠ ε dan |xy| ≤ n *(kita tidak tahu persisnya bagaimana)*
5. **Kita pilih k** (biasanya k=0 atau k=2) sehingga xyᵏz ∉ L → **kontradiksi!**
6. Karena kontradiksi, asumsi awal salah → **L bukan Regular Language** ∎

**Kunci pilihan string w:** Pilih w yang *strukturnya jelas tergantung pada keseimbangan*, sehingga memompa bagian manapun dari n karakter pertama akan merusaknya.

**Contoh pembuktian — Leq = {w | jumlah 0 dan 1 dalam w sama}:**

1. Asumsikan Leq reguler, dapatkan konstanta n
2. Pilih w = 0ⁿ1ⁿ ∈ Leq (panjang 2n ≥ n) ✓
3. Berdasarkan lemma: w = xyz, |xy| ≤ n dan y ≠ ε
   - Karena |xy| ≤ n, maka xy berada di bagian awal string → **x dan y hanya terdiri dari 0**
4. Pilih k = 0: tinjau xz = x·z (hapus y)
   - String xz kehilangan |y| buah angka 0, tapi jumlah 1 tetap n
   - Karena y ≠ ε, jumlah 0 < n = jumlah 1 → xz ∉ Leq
5. **Kontradiksi!** → Leq bukan Regular Language ∎

---

#### Closure Properties

**TL;DR:** *Regular Language "tertutup" terhadap banyak operasi — hasil operasi tersebut dijamin masih regular.*

Untuk membuktikan closure, ada tiga teknik utama: menggunakan **RE**, memanipulasi **DFA/FA**, atau menggunakan **DeMorgan + operasi lain yang sudah terbukti**.

| Operasi                         | Cara Membuktikan                                                                                       |
| ------------------------------- | ------------------------------------------------------------------------------------------------------ |
| **Union (L ∪ M)**               | Jika L=L(E), M=L(F), maka L∪M = L(E\|F) — langsung via RE                                              |
| **Concatenation (L·M)**         | L(E·F) — operator bawaan RE                                                                            |
| **Kleene Star (L\*)**           | L(E\*) — operator bawaan RE                                                                            |
| **Complement (L̄)**             | Balik semua accepting/non-accepting state di DFA                                                       |
| **Intersection (L ∩ M)**        | DeMorgan: L∩M = **L̄ ∪ M̄** (komplemen union komplemen) *atau* Product Construction                    |
| **Difference (L − M)**          | L ∩ M̄ (iris L dengan komplemen M)                                                                     |
| **Reversal (Lᴿ)**               | Balik arah semua transisi FA; start lama → accepting; buat start baru dengan ε ke semua accepting lama |
| **Homomorphism h(L)**           | Ganti setiap simbol dalam RE dengan h(a)                                                               |
| **Inverse Homomorphism h⁻¹(L)** | Bangun DFA baru: transisi input a pada DFA baru = mensimulasikan h(a) pada DFA L                       |

**Detail beberapa operasi penting:**

**Complement:**
- Ambil DFA untuk L
- Ubah semua accepting state → non-accepting, dan sebaliknya
- *Catatan: DFA harus lengkap (complete) — harus ada dead state untuk input yang tidak terdefinisi*

**Product Construction (untuk Intersection):**
- Buat pasangan state (p, q) dari DFA_L × DFA_M
- Transisi: δ((p,q), a) = (δ_L(p,a), δ_M(q,a))
- Accepting state: (p,q) diterima jika p ∈ F_L **dan** q ∈ F_M
- Untuk Union: p ∈ F_L **atau** q ∈ F_M

---

#### Decision Properties

**TL;DR:** *Ada algoritma efisien untuk menjawab pertanyaan dasar tentang Regular Language: apakah kosong, apakah suatu string diterima, apakah dua otomata ekuivalen.*

**Emptiness Test — Apakah L = ∅?**

- Jalankan algoritma *reachability* (BFS/DFS) pada FA
- L ≠ ∅ jika dan hanya jika ada jalur dari start state ke ≥1 accepting state
- Kompleksitas: **O(n²)** untuk FA dengan n state

**Membership Test — Apakah w ∈ L?**

- **DFA:** Simulasikan DFA pada w, cek apakah state akhir ∈ F → **O(|w|)**
- **NFA/ε-NFA:** Tracking himpunan state yang aktif secara paralel → **O(|w|·s²)** atau O(|w|·s³) untuk s state

**Equivalence Test — Apakah L(A) = L(B)?**

1. Konversi kedua otomata ke DFA
2. Jalankan algoritma Table-Filling pada gabungan keduanya
3. Jika start state A dan start state B tidak bisa dibedakan (*indistinguishable*) → **L(A) = L(B)**
4. Jika bisa dibedakan → L(A) ≠ L(B)

---

#### DFA Minimization (Table-Filling Algorithm)

**TL;DR:** *Temukan state-state yang "identik secara perilaku" dan gabungkan, menghasilkan DFA dengan jumlah state paling sedikit.*

**Konsep dasar:** Dua state p dan q dikatakan **ekuivalen** (p ≡ q) jika:
> Untuk semua string w: δ̂(p, w) ∈ F ⟺ δ̂(q, w) ∈ F

Artinya, dari p maupun dari q, keputusan accept/reject untuk semua string **selalu sama**.

**Algoritma Table-Filling:**

Langkah 1 — Buat tabel segitiga semua pasangan state {p, q}

Langkah 2 — **Basis:** Tandai (×) semua pasangan {p, q} di mana tepat satu dari keduanya adalah accepting state

Langkah 3 — **Induksi:** Untuk setiap pasangan {p, q} yang belum ditandai dan setiap simbol a:
- Hitung r = δ(p, a) dan s = δ(q, a)
- Jika {r, s} sudah ditandai (×) → tandai {p, q} juga (×)
- Ulangi sampai tidak ada perubahan (*fixed point*)

Langkah 4 — **Minimisasi:**
- Semua pasangan yang **tidak** ditandai → state-state tersebut ekuivalen → gabungkan jadi satu state
- Hapus state yang tidak terjangkau dari start state
- Setiap *equivalence class* menjadi satu state di DFA minimal

**Hasil:** DFA minimal ini **unik** (hingga penamaan state) — tidak ada DFA ekuivalen dengan jumlah state lebih sedikit.

---

### Komponen Kunci

| Istilah | Definisi Singkat |
|---------|-----------------|
| **Pumping Lemma** | Jika L reguler, string panjang ≥n dapat dipecah w=xyz dengan 3 kondisi yang harus dipenuhi |
| **Pumping constant n** | Nilai minimum panjang string yang berlaku Pumping Lemma (≈ jumlah state DFA) |
| **Proof by contradiction** | Asumsikan reguler → dapatkan n → pilih w → pompa → tunjukkan hasil ∉ L → kontradiksi |
| **Closure property** | Jika L,M regular, maka hasil operasi (union, complement, dst.) juga regular |
| **Product construction** | Teknik membuat DFA baru dari DFA_L × DFA_M untuk intersection/union |
| **Emptiness test** | Cek apakah ada jalur dari start ke accepting state (reachability) |
| **Membership test** | Simulasikan DFA/NFA pada string input |
| **Equivalence test** | Table-Filling pada gabungan dua DFA |
| **Table-Filling** | Algoritma tandai pasangan state distinguishable secara iteratif |
| **Distinguishable states** | p dan q distinguishable jika ∃w: δ̂(p,w) ∈ F XOR δ̂(q,w) ∈ F |
| **Equivalent states** | p ≡ q jika tidak distinguishable — perilaku mereka identik untuk semua input |
| **DFA minimal** | DFA dengan jumlah state paling sedikit yang ekuivalen — unik untuk setiap bahasa |

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- [x] Pumping Lemma: pernyataan formal (3 kondisi)
- [x] Pumping Lemma: cara menggunakan (adversarial game)
- [x] Pumping Lemma: contoh pembuktian Leq
- [x] Closure Properties: Union, Concat, Kleene Star (via RE)
- [x] Closure Properties: Complement (via DFA flip)
- [x] Closure Properties: Intersection, Difference (via DeMorgan / product)
- [x] Closure Properties: Reversal, Homomorphism, Inverse Homomorphism
- [x] Decision Properties: Emptiness, Membership, Equivalence
- [x] DFA Minimization: Table-Filling Algorithm

**Prioritas belajar:**

| Prioritas | Sub-materi |
|-----------|-----------|
| 🔴 *Wajib dikuasai* | Pumping Lemma — pernyataan + cara pakai + contoh pembuktian |
| 🔴 *Wajib dikuasai* | Table-Filling (DFA Minimization) — langkah basis & induksi |
| 🟡 *Cukup paham konsep* | Closure Properties — hafal daftar operasi + teknik pembuktiannya |
| 🟡 *Cukup paham konsep* | Decision Properties — emptiness, membership, equivalence |
| 🟡 *Cukup paham konsep* | Product Construction untuk intersection |

---

*Sumber: NotebookLM IF2224 · 2026-05-04*
