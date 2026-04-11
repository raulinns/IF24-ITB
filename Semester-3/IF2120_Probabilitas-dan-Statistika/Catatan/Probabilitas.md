# Ruang Sampel
Ruang sampel, dinotasikan sebagai $S$, adalah kumpulan dari semua hasil yang mungkin terjadi dari suatu eksperimen statistik. Sebuah kejadian adalah himpunan bagian (subset) dari ruang sampel. Ini merepresentasikan suatu hasil dengan kondisi tertentu yang kita amati.

# Peluang Suatu Kejadian
Peluang dari suatu kejadian A adalah jumlah dari bobot semua titik sampel dalam A, sehingga   $0 \le P(A) \le 1.$ Peluang dari himpunan kosong (kejadian mustahil) adalah 0: $P(\emptyset) = 0$. Peluang dari seluruh ruang sampel (kejadian pasti) adalah 1: $P(S) = 1$.

# Aturan Penjumlahan Peluang
Aturan ini digunakan untuk menghitung peluang dari gabungan beberapa kejadian.

### a. Kejadian Sembarang
**Dua Kejadian**: Untuk dua kejadian sembarang A dan B
$$
P(A \cup B) = P(A) + P(B) - P(A \cap B)
$$
**Tiga Kejadian**: Untuk tiga kejadian sembarang A, B, dan C
$$
P(A \cup B \cup C) = P(A)+P(B)+P(C) - P(A \cap B) - P(A \cap C) - P(B \cap C) + P(A \cap B \cap C)
$$

### b. Kejadian Saling Lepas (Mutually Exclusive)
Dua kejadian disebut saling lepas jika keduanya tidak dapat terjadi secara bersamaan.

Jika A dan B saling lepas, maka $P(A \cap B) = 0$, sehingga:
$$
P(A \cup B) = P(A) + P(B)
$$

### c. Kejadian Saling Komplemen
Jika A dan A' adalah dua kejadian yang saling komplemen (satu kejadian pasti terjadi jika yang lain tidak), maka:
$$
P(A) + P(A') = 1
$$

#  Peluang Bersyarat

Peluang bersyarat $P(B|A)$ adalah peluang terjadinya kejadian B, dengan syarat kejadian A telah terjadi. Rumus peluang bersyarat adalah:
$$
P(B|A) = \frac{P(A \cap B)}{P(A)}
$$

### Kejadian Saling Bebas
Dua kejadian A dan B disebut saling bebas jika terjadinya kejadian A tidak mempengaruhi peluang terjadinya kejadian B.
Syarat kejadian saling bebas:
- $P(B|A) = P(B)$
- $P(A|B) = P(A)$

# Aturan Perkalian Peluang
Aturan ini adalah turunan dari rumus peluang bersyarat dan digunakan untuk mencari peluang irisan dua kejadian.

Untuk dua kejadian A dan B:
$$
P(A \cap B) = P(A) \cdot P(B|A)
$$
Jika A dan B saling bebas
$$
P(A \cap B) = P(A) \cdot P(B)
$$

# Aturan Bayes
> **Rumus Umum Bayes**
> $$
> P(A|B) = \frac{P(B|A) \cdot P(A)}{P(B)}
> $$

> **Teorema**: Jika kejadian-kejadian $B_1, B_2, ..., B_k$ merupakan partisi dari ruang sampel S, maka untuk sembarang kejadian A:
>$$
> P(B_r|A) = \frac{P(B_r \cap A)}{\sum_{i=1}^{k} P(B_i \cap A)} = \frac{P(B_r)P(A|B_r)}{\sum_{i=1}^{k} P(B_i)P(A|B_i)}
> $$

> **Teorema Aturan Eliminasi (Peluang Total)**: Peluang kejadian A dapat dihitung dengan menjumlahkan peluang A yang terjadi bersama setiap partisi. 
>  $$
P(A) = \sum_{i=1}^{k} P(B_i)P(A|B_i) 
$$