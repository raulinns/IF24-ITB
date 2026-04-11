1Konsep "vektor" diperluas dari sekadar panah di $R^2$ atau $R^3$ menjadi lebih abstrak, karena tidak mungkin digambar lagi melebihi tiga dimensi. Konsep vektor di ruang $R^n$ dapat diperluas sehingga berbagai objek matematika dapat diperlakukan sebagai vektor asalkan memenuhi serangkaian aturan yang disebut **aksioma ruang vektor**.

Ruang vektor adalah himpunan-himpunan objek yang dilengkapi dengan dua operasi di dalam himpunan tersebut, yaitu
1.  Penjumlahan antar objek (vektor).
2.  Perkalian objek (vektor) dengan skalar.

# Aksioma Vektor
Sebuah himpunan objek-objek $V$ yang dilengkapi dengan operasi penjumlahan dan operasi perkalian dengan skalar dapat disebut dengan ruang vektor dan semua objek di dalam $V$ disebut vektor, apabila memenuhi enam aksioma berikut:
1. Tertutup (*closure*), operasi penjumlahan dan perkalian skalar selalu menghasilkan vektor di dalam $V$. Jadi, untuk semua $\mathbf{u}, \mathbf{v} \in V$ dan skalar $k$, maka $\mathbf{u} + \mathbf{v} \in V$ dan $k \mathbf{u} \in V$
2. Komutatif, $\mathbf{u} + \mathbf{v} = \mathbf{v} + \mathbf{u}$.
3. Asosiatif, $\mathbf{u} + (\mathbf{v} + \mathbf{w}) = (\mathbf{u} + \mathbf{v}) + \mathbf{w}$. 
4. Identitas, terdapat sebuah vektor nol **0** dan skalar 1 di $V$ sehingga $\mathbf{u} + \mathbf{0} = \mathbf{u}$ dan $1\mathbf{u} = \mathbf{u}$
5. Elemen Invers (Balikan), untuk setiap $\mathbf{u}$ di $V$, terdapat -$\mathbf{u}$ di $V$ sehingga $\mathbf{u} + (-\mathbf{u}) = \mathbf{-u} + \mathbf{u}= \mathbf{0}$
6. Distributif,  
$$
\begin{align*}
k(\mathbf{u} + \mathbf{v}) &= k\mathbf{u} + k\mathbf{v} \\
(k + m)\mathbf{u} &= k\mathbf{u} + m\mathbf{u} \\ 
k(m \mathbf{u}) &= (km) \mathbf{u}
\end{align*}
$$

## Cara Menunjukkan Ruang vektor
1. Identifikasi himpunan $V$ dengan objek-objek di dalamnya yang akan menjadi vektor
2. Identifikasi operasi penjumlahan dan perkalian skalar di dalam $V$
3. Periksa aksioma 1 (tertutup)
4. Periksa apakah lima aksioma lainnya dipenuhi

## Contoh-contoh Ruang Vektor

-   **$R^n$**: Himpunan semua n-tupel $(u_1, u_2, ..., u_n)$.
-   **Matriks $M_{mn}$**: Himpunan semua matriks berukuran $m \times n$. Vektor nolnya adalah matriks nol.
-   **Fungsi Bernilai Riil**: Himpunan fungsi-fungsi $f(x)$ di mana $(f+g)(x) = f(x) + g(x)$ dan $(kf)(x) = kf(x)$. Vektor nolnya adalah fungsi konstan $f(x) = 0$.
-   **Polinom $P_n$**: Himpunan semua polinom dengan derajat kurang dari atau sama dengan n.

# Subruang (Subspace)
Subruang adalah sub-himpunan dari sebuah ruang vektor yang juga merupakan ruang vektor dengan operasi yang sama.

> **Teorema Subruang**: 
> Sebuah sub-himpunan tak kosong W dari V adalah subruang jika dan hanya jika memenuhi dua syarat **ketertutupan (closure)**:
> 1. Jika **u** dan **v** ada di W, maka **u** + **v** juga harus di W.
> 2. Jika **u** ada di W dan *k* adalah skalar, maka *k***u** juga harus di W.

# Kombinasi Linier dan Span Set
 Sebuah vektor **w** adalah kombinasi linier dari himpunan vektor $\{v_1, v_2, ..., v_r\}$ jika dapat dinyatakan sebagai:
$$
\mathbf{w} = k_1\mathbf{v_1} + k_2\mathbf{v_2} + ... + k_r\mathbf{v_r} 
$$

> Teorema: Jika $S = \{w_1, w_2, \dots, w_i\}$ adalah himpunan vektor-vektor di ruang vektor $V$ maka
> 1. Himpunan $W$ yang berisi semua kombinasi linier vektor-vektor dalam $S$ adalah subruang dari V
> 2. Himpunan $W$ tersebut adalah subruang "terkecil" dari $V$ yang mengancung vektor-vektor di dalam $S$ dengan pengertian bahwa sembarang subruang lain yang mengandung vektor-vektor tersebut juga mengandung $W$.
 
Himpunan vektor $S = \{w_1, w_2, ..., w_r\}$ dikatakan **membangun (span)** sebuah subruang W jika setiap vektor di W dapat ditulis sebagai kombinasi linier dari vektor-vektor di S. Ini dinotasikan sebagai $W = \text{span}(S)$.

**Interpretasi Geometris**:
`span{v}` adalah garis yang melalui titik asal.
`span{v₁, v₂}` adalah bidang yang melalui titik asal.

Untuk menguji apakah sebuah himpunan vektor membangun sebuah ruang (misal, $R^3$), kita harus memeriksa apakah Sistem Persamaan Linier (SPL) yang terbentuk memiliki solusi untuk sembarang vektor. Ini bisa dicek dengan determinan matriks koefisiennya: jika **determinan $\neq 0$**, maka himpunan tersebut membangun ruang tersebut.

# Kebebasan Linier
Sebuah himpunan vektor $S = \{v_1, v_2, ..., v_r\}$ dikatakan **bebas linier (linearly independent)** jika satu-satunya solusi untuk persamaan
$$
k_1\mathbf{v_1} + k_2\mathbf{v_2} + ... + k_r\mathbf{v_r} = \mathbf{0} 
$$
adalah solusi trivial, yaitu $k_1 = k_2 = ... = k_r = 0$.

Jika ada solusi lain (solusi non-trivial), maka himpunan tersebut dikatakan **bergantung linier (linearly dependent)**.

Sebuah himpunan bergantung linier jika setidaknya satu vektor di dalamnya dapat ditulis sebagai kombinasi linier dari vektor-vektor lainnya.

Sama seperti *span*, kita membentuk SPL homogen dan memeriksa solusinya.
-   Jika hanya ada solusi trivial (unik), himpunan tersebut bebas linier.
-   Jika ada solusi non-trivial (banyak solusi), himpunan tersebut bergantung linier.
-   Ini juga bisa dicek dengan determinan matriks koefisien: jika **determinan $\neq 0$**, himpunan tersebut bebas linier.

# Basis
**Basis** adalah "kerangka" fundamental dari sebuah ruang vektor. Himpunan vektor $S = \{\mathbf{v_1}, \mathbf{v_2}, \dots, \mathbf{v_n}\}$ disebut sebagai basis untuk ruang vektor V jika memenuhi dua syarat:

1.  **Bebas Linier (Linearly Independent)**: Tidak ada vektor di S yang dapat ditulis sebagai kombinasi linier dari vektor lainnya.
2.  **Membangun V (Spans V)**: Setiap vektor di V dapat ditulis sebagai kombinasi linier dari vektor-vektor di S.

Keberadaan basis menjamin bahwa setiap vektor di dalam ruang tersebut dapat direpresentasikan secara **unik** sebagai kombinasi linier dari vektor-vektor basis.

**Cara Menguji Basis di $R^n$**: Untuk menguji apakah *n* buah vektor di $R^n$ membentuk sebuah basis, bentuklah sebuah matriks A yang kolomnya adalah vektor-vektor tersebut. Jika **determinan A $\neq 0$**, maka himpunan tersebut adalah sebuah basis.

-   **Contoh Basis Standar**:
    -   Untuk $R^3$: $\{\mathbf{i}, \mathbf{j}, \mathbf{k}\} = \{(1,0,0), (0,1,0), (0,0,1)\}$.
    -   Untuk $P_n$ (polinom derajat $\leq n$): $\{1, x, x^2, \dots, x^n\}$.
    -   Untuk $M_{22}$ (matriks 2x2): $\{ \begin{pmatrix} 1 & 0 \\ 0 & 0 \end{pmatrix}, \begin{pmatrix} 0 & 1 \\ 0 & 0 \end{pmatrix}, \begin{pmatrix} 0 & 0 \\ 1 & 0 \end{pmatrix}, \begin{pmatrix} 0 & 0 \\ 0 & 1 \end{pmatrix} \}$.

# Dimensi
**Dimensi** dari sebuah ruang vektor $V$, dinotasikan `dim(V)`, adalah **banyaknya vektor di dalam basisnya**.
-   `dim($R^n$)` = $n$.
-   `dim($P_n$)` = $n+1$.
-   `dim($M_{mn}$)` = $m \times n$.

 **Dimensi Ruang Solusi**: Untuk menemukan basis dan dimensi dari ruang solusi sebuah SPL Homogen, selesaikan SPL tersebut. Solusi parametriknya dapat dipecah menjadi vektor-vektor basis, dan jumlah parameter bebasnya adalah dimensi dari ruang solusi tersebut. Pada subbab selanjutnya ini akan disebut sebagai *nullity*

# Vektor Koordinat
Jika $S = \{\mathbf{v_1}, \mathbf{v_2}, \dots, \mathbf{v_n}\}$ adalah basis untuk V, dan sebuah vektor **v** dapat ditulis sebagai $\mathbf{v} = c_1\mathbf{v_1} + c_2\mathbf{v_2} + \dots + c_n\mathbf{v_n}$, maka skalar-skalar $c_1, c_2, \dots, c_n$ adalah **koordinat** dari **v** relatif terhadap basis S.

  **Vektor Koordinat**: $(v)_S = (c_1, c_2, \dots, c_n)$
  
   **Matriks Koordinat**: $[v]_S = \begin{pmatrix} c_1 \\ c_2 \\ \vdots \\ c_n \end{pmatrix}$

Untuk mencari vektor koordinat, kita harus menyelesaikan sebuah Sistem Persamaan Linier (SPL).

# Mengubah Basis
Mengubah basis berarti mengubah representasi koordinat sebuah vektor dari satu basis ke basis lain.

**Matriks Transisi**: Jika B adalah basis lama dan B' adalah basis baru, **matriks transisi dari B ke B'** dinotasikan sebagai $P_{B \to B'}$. Matriks ini digunakan untuk mengubah koordinat.
$$
[v]_{B'} = P_{B \to B'} [v]_B
$$

**Algoritma Mencari Matriks Transisi $P_{B \to B'}$**:
1.  Bentuk matriks gabungan: $[B' | B]$
2.  Lakukan Operasi Baris Elementer (OBE) pada matriks tersebut hingga bagian kiri menjadi matriks identitas (I).
3.  Hasilnya akan berbentuk $[I | P]$. Matriks **P** di bagian kanan adalah matriks transisi yang dicari.

**Sifat Invers**: Matriks transisi dari B' ke B adalah invers dari matriks transisi B ke B'.
$$
P_{B' \to B} = (P_{B \to B'})^{-1}
$$

# Ruang Baris, Ruang Kolom, dan Ruang Null
Misalkan $A$ adalah matriks $m \times n$ sebagai berikut:
$$
\begin{bmatrix}
a_{11} & a_{12} & \dots & a_1n \\
a_{21} & a_{22} & \dots & a_2n \\
\vdots & \vdots  &   & \vdots \\
a_{m1} & a_{m2} & \dots & a_mn \\
\end{bmatrix}
$$
- **Ruang Baris (Row Space)**: Subruang dari $R^n$ yang dibangun (*span*) oleh vektor-vektor baris dari matriks $A$. 
- **Ruang Kolom (Column Space)**: Subruang dari $R^m$ yang dibangun (*span*) oleh vektor-vektor kolom dari matriks $A$. 
- **Ruang Null (Null Space)**: Ruang solusi dari sistem persamaan linier (SPL) homogen . Ini adalah subruang dari $R^n$.

Sebuah SPL $A\mathbf{x} = \mathbf{b}$ akan **konsisten** (memiliki solusi) jika dan hanya jika **b** berada di dalam ruang kolom matriks A.

Vektor baris:
$$
\begin{align*}
\mathbf{r}_1 &= 
\begin{bmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \end{bmatrix} \\

\mathbf{r}_2 &= 
\begin{bmatrix} a_{21} & a_{22} & \cdots & a_{2n}  \\
\end{bmatrix} \\ &\vdots \\ 
\mathbf{r}_m &= \begin{bmatrix} a_{m1} & a_{m2} & \cdots & a_{mn}  \\
\end{bmatrix}
\end{align*}
$$

Vektor kolom:
$$
\mathbf{c}_1 = 
\begin{bmatrix}
a_{11} \\ a_{21} \\ \vdots \\ a_{m1}  \\
\end{bmatrix}, \quad \mathbf{c}_2 = \begin{bmatrix} a_{12} \\ a_{22} \\ \vdots \\ a_{m2} \end{bmatrix}, \quad \dots, \quad \mathbf{c}_n = 
\begin{bmatrix}
 a_{1n} \\ a_{2n} \\ \vdots \\ a_{mn} \\
\end{bmatrix}
$$

## Menemukan Basis
Untuk menemukan basis dari ketiga ruang tersebut, langkah-langkahnya adalah gunakan OBE hingga menghasilkan matriks eselon baris, lalu:
-  **Basis Ruang Baris**:   Basis untuk ruang baris adalah **semua baris tak-nol** (baris yang mengandung 1 utama) dari matriks eselon baris **R**.
- **Basis Ruang Kolom**:   Identifikasi kolom-kolom pada matriks eselon baris **R** yang mengandung 1 utama.  Basis untuk ruang kolom adalah **kolom-kolom yang bersesuaian** dari matriks **A (matriks asli)**.
-  **Basis Ruang Null**: Selesaikan SPL homogen $A\mathbf{x} = \mathbf{0}$ (menggunakan matriks R untuk mempermudah). Tulis solusi dalam bentuk parametrik.  Vektor-vektor yang menjadi pengali dari setiap parameter membentuk basis untuk ruang null.

# Rank dan Nulitas
 **Rank**: `rank(A)` adalah dimensi dari ruang baris atau ruang kolom. Nilai rank sama dengan jumlah 1 utama (atau jumlah baris tak-nol) pada matriks eselon baris.
$$
\text{rank}(A) = \text{dim(ruang baris)} = \text{dim(ruang kolom)}
$$

 **Nulitas (Nullity)**: `nullity(A)` adalah dimensi dari ruang null. Nilai nulitas sama dengan jumlah parameter (variabel bebas) dalam solusi SPL homogen $A\mathbf{x} = \mathbf{0}$.

### Teorema Rank-Nulitas
Untuk matriks A dengan **n** kolom, berlaku hubungan:
$$\text{rank}(A) + \text{nullity}(A) = n$$
(Jumlah variabel utama) + (Jumlah parameter bebas) = (Jumlah total variabel)

## Teorema Pernyataan Ekuivalen
Untuk sebuah matriks persegi **A** berukuran *n x n*, semua pernyataan berikut adalah ekuivalen (jika salah satu benar, maka semuanya benar):
-   A dapat dibalik (*invertible*).
-   $A\mathbf{x} = \mathbf{0}$ hanya memiliki solusi trivial.
-   Bentuk eselon baris tereduksi dari A adalah matriks identitas ($I_n$).
- $A$ dapat dinyatakan sebagai bentuk perkalian dari matriks Elementer
- $Ax = b$ konsisten untuk setiap $n \times 1$ matriks $b$
- $Ax = b$ memiliki tepat satu solusi untuk tiap $n \times 1$ matriks $b$
-   $\det(A) \neq 0$.
-   Vektor-vektor baris/kolom dari A adalah **bebas linier**.
-   Vektor-vektor baris/kolom dari A **membangun** $R^n$.
-   Vektor-vektor baris/kolom dari A membentuk **basis** untuk $R^n$.
-   `rank(A) = n`.
-   `nullity(A) = 0`

# Transformasi Linier
Transformasi (atau fungsi/pemetaan)  $T: V \to W$ adalah sebuah aturan yang memetakan setiap vektor di ruang vektor $V$ (domain) ke sebuah vektor di ruang vektor $W$ (kodomain). Jika $V = W$, $T$ disebut **operator**.

**Syarat Transformasi Linier**: Sebuah transformasi $T$ disebut **linier** jika memenuhi dua syarat untuk semua vektor **u**, **v** di V dan skalar *k*:
1.  **Aditivitas**: $T(\mathbf{u} + \mathbf{v}) = T(\mathbf{u}) + T(\mathbf{v})$
2.  **Homogenitas**: $T(k\mathbf{u}) = kT(\mathbf{u})$

 **Sifat-sifat Transformasi Linier**:
-   $T(\mathbf{0}) = \mathbf{0}$ (selalu memetakan vektor nol ke vektor nol).
-   $T(-\mathbf{v}) = -T(\mathbf{v})$.
-   $T(\mathbf{u} - \mathbf{v}) = T(\mathbf{u}) - T(\mathbf{v})$.
-   $T(k_1\mathbf{v_1} + \dots + k_n\mathbf{v_n}) = k_1T(\mathbf{v_1}) + \dots + k_nT(\mathbf{v_n})$.

# Transformasi Matriks
Setiap transformasi linier $T: R^n \to R^m$ dapat direpresentasikan sebagai perkalian matriks:
$$\mathbf{w} = A\mathbf{x}$$
-   **x**: Vektor di $R^n$ (input).
-   **w**: Vektor di $R^m$ (output/bayangan).
-   **A**: Matriks berukuran *m x n* yang disebut **matriks standar** untuk transformasi T.

### Cara Menemukan Matriks Standar
1.  Tentukan hasil transformasi dari setiap **vektor basis standar** di domain ($e_1, e_2, \dots, e_n$).
2.  Bentuk sebuah matriks di mana **kolom-kolomnya** adalah hasil transformasi tersebut ($T(e_1), T(e_2), \dots, T(e_n)$). Matriks inilah yang menjadi matriks standar A.

# Komposisi Transformasi
Komposisi adalah penerapan dua atau lebih transformasi secara berurutan. Jika transformasi pertama adalah $T_A$ (matriks A) dan diikuti oleh $T_B$ (matriks B), maka komposisinya adalah:
$$
(T_B \circ T_A)(\mathbf{x}) = T_B(T_A(\mathbf{x})) = B(A\mathbf{x}) = (BA)\mathbf{x}
$$
Matriks standar untuk komposisi adalah hasil perkalian matriks-matriksnya, dengan urutan **dari kanan ke kiri** sesuai urutan transformasi.
$$A_{\text{komposisi}} = A_{\text{terakhir}} \dots A_{\text{kedua}} A_{\text{pertama}}$$

# Aplikasi di Grafika Komputer
-   Dalam grafika komputer, transformasi seperti rotasi, penskalaan, dan translasi (pergeseran) sangat umum.
-   **Translasi** bukan transformasi linier murni karena $T(\mathbf{0}) \neq \mathbf{0}$.
-   Untuk menyatukan semua operasi (termasuk translasi) menjadi satu perkalian matriks, digunakan **koordinat homogen**.
-   **Koordinat Homogen**: Sebuah titik 2D $(x, y)$ direpresentasikan sebagai vektor 3D $(x, y, 1)$, dan titik 3D $(x, y, z)$ sebagai vektor 4D $(x, y, z, 1)$.
-   Dengan ini, semua transformasi (rotasi, scaling, translasi, dll.) dapat dinyatakan sebagai perkalian dengan matriks 3x3 (untuk 2D) atau 4x4 (untuk 3D), sehingga komposisi transformasi menjadi sangat efisien.
