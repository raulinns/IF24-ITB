# Dekomposisi Matriks
Mendekomposisi matriks artinya memfaktorkan sebuah matriks. Misalnya $A$ dapat disusun dari perkalian matriks, sedemikian sehingga:
$$
A = P_1 \times P_2 \times \dots \times P_k
$$

Terdapat beberapa metode untuk mendekomposisi matriks:
1. Metode [[Dekomposisi LU]]
2. Metode  [[Dekomposisi QR]]
3. Metode Dekomposisi Nilai Singular (SVD)

# Singular Value Decomposition
> SVD adalah faktorisasi yang dapat diterapkan pada **semua matriks** $m \times n$ (bisa non-bujursangkar). 

SVD memfaktorkan matriks $\mathbf{A}$ ke dalam bentuk:

$$
\mathbf{A} = \mathbf{U}\mathbf{\Sigma}\mathbf{V}^T
$$

> Notes: beberapa konsep dan istilah yang ada materi ini belum dijelaskan sebelumnya, jadi wajar untuk merasa bingung. Oleh karena itu, sebelum masuk lebih jauh ke dalam SVD, kita akan membahas dasar teorinya terlebih dahulu

Di mana:
* $A$ adalah matriks $m \times n$ yang ingin kita dekomposisi (dengan rank $r$).
* $U$ adalah matriks ortogonal $m \times m$. Kolom-kolomnya ($\mathbf{u}_j$) disebut **vektor singular kiri**.
* $V$ adalah matriks ortogonal $n \times n$. Kolom-kolomnya ($\mathbf{v}_j$) disebut **vektor singular kanan**.
* $\Sigma$ (Sigma) adalah matriks "diagonal" $m \times n$ yang elemen diagonal utamanya adalah nilai-nilai singular dari matriks $A$

## Matriks Ortogonal dan Matriks Ortonormal
Matriks ortogonal (atau matriks ortonormal) adalah matriks persegi yang baris-baris/kolom-kolomnya adalah vektor ortonormal (vektor yang saling ortogonal satu sama lain (hasil kali titik sama dengan 0) dan memiliki panjang/*magnitude* sebesar 1.

>Notes: Sepertinya ada kesalahan terminologi pada slide [[21-Singular-value-decomposition-Bagian1-2025.pdf]]. Beberapa sumber lain, termasuk buku, mengatakan bahwa matriks ortogonal dan matriks ortonormal adalah hal yang sama.


Jika $Q$ adalah matriks ortogonal berukuran $n \times n$, maka
$$
Q^T Q = Q Q^T = I_{n \times n}
$$

## Matriks Simetris dan Diagonalisasi Ortogonal
Sebuah matriks $M$ dikatakan simetris jika ia sama dengan transposnya ($M = M^T$). Jika $A$ adalah matriks $n \times n$, maka pernyataan tersebut adalah ekuivalen (jika salah satu pernyataan benar, maka lainnya juga benar):
1. $A$ dapat didiagonalisasi secara ortogonal
2. $A$ memiliki himpunan ortonormal dari $n$ vektor eigen
3. $A$ merupakan matriks simetris

Maka, dapat dikatakan bahwa:
> Jika $A$ adalah matriks simetris, maka setiap vektor eigen dari ruang eigen yang berbeda bersifat ortogonal.

Mendiagonalisasi matriks secara ortogonal adalah kasus khusus dari diagonalisasi, di mana matriks $P$ yang digunakan adalah sebuah matriks ortogonal.

Maka, untuk mendiagonalisasi matriks secara ortogonal, kita hanya perlu mencari basis dari vektor eigen matriks $A$, karena himpunan vektor eigen yang dihasilkan dari matriks $A$ sudah merupakan himpunan vektor ortogonal.

## Diagonal Utama Matriks $m \times n$
Diagonal utama sebuah matriks biasanya didefinisikan pada matriks persegi berukuran $n \times n$. Untuk matriks $m \times n$, diagonal utama matriks didefinisikan pada garisd yang dimulai pada sudut kiri ats terus ke bawah matriks sejauh mungkin.

Definisi akhirnya, diagonal utama matriks $A$ dengan ukuran $m \times n$ adalah seluruh elemen $a_{ii}$ pada matriks $A$.

>[!img-caption] ![[Pasted image 20251113051546.png]]

## Nilai Singular Matriks
Misalkan $A$ adalah matriks $m \times n$. Jika $\lambda_1, \lambda_2, \dots, \lambda_n$ adalah nilai-nilai eigen dari $A^TA$, maka
$$
\sigma_1 = \sqrt{\lambda_1}, \sigma_2 = \sqrt{ \lambda_2 }, \dots, \sigma_n = \sqrt{ \lambda_n }
$$

> Teorema:
> Jika $A$ adalah matriks $m \times n$, maka:
> - $A^TA$ dapat didiagonalisasi secara ortogonal
> - Nilai-nilai eigen untuk $A^TA$ tidak pernah negatif.

Untuk memudahkan perhitungan, asumsikan $\lambda_1 \ge \lambda_2 \ge \dots \ge \lambda_n \ge 0$, sehingga $\sigma_1 \ge \sigma_2 \ge \dots \ge \sigma_n \ge 0$.

# SVD
JIka $A$ adalah matriks $m \times n$ dengan *rank* $k$, maka $A$ dapat difaktorkan menjadi

$$
A = U \Sigma V^T = 
\begin{bmatrix}
u_1 & u_2 & \dots & u_k | u_{k+1} & \dots &  u_n
\end{bmatrix}
\begin{bmatrix}
\sigma_1 & 0 & \dots & 0  & \dots \\
0 & \sigma_2 & \dots & 0  & \dots\\
\vdots & \vdots & \ddots & \vdots & \dots \\
0 & 0 & \dots & \sigma_k  & \dots \\
\vdots  & \vdots &  \vdots & \vdots & \ddots \\
\end{bmatrix}
\begin{bmatrix}
v_1^T \\
v_2^T \\
\vdots \\
v_k^T \\
\hline
v_{k+1}^T \\
\vdots \\
v_n^T
\end{bmatrix}
$$

>[!img-caption] ![[Pasted image 20251113051634.png]]

Setelah kita mengenal istilah/konsep di atas, kita dapat mengartikan bahwa:
- $m$ adalah jumlah baris $A$, $n$ adalah jumlah kolom $A$, dan $A = rank(A)$, yakni nilai eigen $A^T A$ yang tak nol (sudah pasti tidak negatif berdasarkan teorema).
- $V$ adalah matriks yang mendiagonalisasi $A^TA$ secara ortogonal. Vektor ini disebut vektor singular kanan.  (1). $V^T$ adalah transpos dari matriks $V$. (2)
- $\Sigma$ adalah matriks yang komponen diagonal utamanya adalah nilai-nilai singular dari matriks $A$ dengan susunan dari besar ke kecil. Nilai singular dari $\Sigma$ adalah akar pangkat dua dari nilai-nilai eigen tak nol dari $A^T A$.
- $U$ adalah matriks yang berisi basis ortonormal untuk `col(A)` dan disebut matriks singular kiri. (2)

Untuk (1) dan (2) boleh diabaikan, jika tidak ingin melihat rumus turunan/asal teoremanya
#### (1)
Ingat bahwa untuk mendiagonalisasi sebuah vektor $A$, kita memerlukan vektor $P$ yang berisi himpunan vektor basis dari ruang eigen  $A$, serta vektor $D$ yang diagonal utamanya berisi nilai eigen dari vektor $A$. Sehingga, cara mencari matriks $V$ adalah dengan mencari himpunan vektor eigen dari matriks $A^TA$ (karena sudah dijamin kesimetrisannya) dan menormalisasikannya (membaginya dengan panjang vektor). 

#### (2a)
Penurunan $\mathbf{A}^T\mathbf{A}$ (Untuk Menemukan $V$). Jika kita hitung $\mathbf{A}^T\mathbf{A}$ menggunakan dekomposisi SVD:
$$
\mathbf{A}^T\mathbf{A} = (\mathbf{U}\mathbf{\Sigma}\mathbf{V}^T)^T (\mathbf{U}\mathbf{\Sigma}\mathbf{V}^T) = (\mathbf{V}\mathbf{\Sigma}^T\mathbf{U}^T) (\mathbf{U}\mathbf{\Sigma}\mathbf{V}^T)
$$
Karena $\mathbf{U}$ ortogonal, $\mathbf{U}^T\mathbf{U} = \mathbf{I}$.
$$
\mathbf{A}^T\mathbf{A} = \mathbf{V}(\mathbf{\Sigma}^T\mathbf{\Sigma})\mathbf{V}^T
$$

Ingat bahwa $\Sigma$ dan $\Sigma^T$ sama-sama berisi nilai singular pada diagonal utamanya, maka ketika dikalikan, akan menghasilkan matriks dengan nilai eigen pada diagonal utamanya (tak lain dan tak bukan adalah matriks $D$ pada materi diagonalisasi), Sehingga bentuk ini dapat dinyatakan sebagai diagonalisasi ortogonal dari $\mathbf{A}^T\mathbf{A}$. 

Ini memberitahu kita:
* Kolom-kolom **V** adalah **vektor-vektor eigen ortonormal** dari $\mathbf{A}^T\mathbf{A}$.
* Nilai-nilai eigen dari $\mathbf{A}^T\mathbf{A}$ adalah $\lambda_j = \sigma_j^2$ (kuadrat dari nilai singular).

#### (2b)
Penurunan $\mathbf{A}\mathbf{A}^T$ (Untuk Menemukan U). Jika kita hitung $\mathbf{A}\mathbf{A}^T$:
$$
\mathbf{A}\mathbf{A}^T = (\mathbf{U}\mathbf{\Sigma}\mathbf{V}^T) (\mathbf{U}\mathbf{\Sigma}\mathbf{V}^T)^T = (\mathbf{U}\mathbf{\Sigma}\mathbf{V}^T) (\mathbf{V}\mathbf{\Sigma}^T\mathbf{U}^T)
$$

Karena $\mathbf{V}$ ortogonal, $\mathbf{V}^T\mathbf{V} = \mathbf{I}$.
$$
\mathbf{A}\mathbf{A}^T = \mathbf{U}(\mathbf{\Sigma}\mathbf{\Sigma}^T)\mathbf{U}^T
$$

Bentuk ini sama dengan bentuk di atas, sehingga kesimpulannya pun sama.

#### (2c)
Penurunan Rumus Turunan . Kita juga dapat menurunkan hubungan antara **U** dan **V** secara langsung. Mulai dari $\mathbf{A} = \mathbf{U}\mathbf{\Sigma}\mathbf{V}^T$, kalikan dengan $\mathbf{V}$:
$$
\mathbf{A}\mathbf{V} = (\mathbf{U}\mathbf{\Sigma}\mathbf{V}^T)\mathbf{V} \implies \mathbf{A}\mathbf{V} = \mathbf{U}\mathbf{\Sigma}
$$
Jika kita melihat kolom ke-$j$ (untuk $j \le r$, di mana $r$ adalah rank):
$$
\mathbf{A}\mathbf{v}_j = \sigma_j\mathbf{u}_j \implies \mathbf{u}_j = \frac{1}{\sigma_j} \mathbf{A}\mathbf{v}_j
$$
(Ini adalah rumus untuk menghitung $U$  jika $V$ diketahui).

Jika kita mulai dari $\mathbf{A}^T = \mathbf{V}\mathbf{\Sigma}^T\mathbf{U}^T$ dan kalikan dengan **U**:
$$
\mathbf{A}^T\mathbf{U} = \mathbf{V}\mathbf{\Sigma}^T \implies \mathbf{A}^T\mathbf{u}_j = \sigma_j\mathbf{v}_j \implies \mathbf{v}_j = \frac{1}{\sigma_j} \mathbf{A}^T\mathbf{u}_j
$$
(Ini adalah rumus untuk menghitung **V** jika **U** diketahui).

# Menentukan SVD
## Cara 1
1. Buatlah matriks $A^T A$, lalu cari nilai dan vektor eigennya. Urutkan vektor eigen secara menurun berdasarkan nilai eigennya, lalu gabungkan dalam sebuah matriks $V$. Lalu, normalisasi vektor eigen agar matriks $V$ menjadi matriks ortogonal. Transpose matriks $V$ agar menjadi $V^T$.
2. Akarkan nilai eigen untuk mendapatkan nilai singular yang sudah ditemukan pada langkah sebelumnya, lalu urutkan secara menurun. Masukkan nilai singular yang sudah diurutkan secara diagonal pada sebuah matriks $\Sigma$.
3. Tentukan matriks singular kiri dengan persamaan $\mathbf{u}_j = \frac{1}{\sigma_j} \mathbf{A}\mathbf{v}_j$.
4. Apabila $k$ atau `rank(A) = rank(A * A^T)` atau banyaknya nilai eigen $< n$, Perluas $U$ dengan membentuk basis ortonormal untuk $R^m$ .  Perluasan dilakukan dengan melakukan SPL dari vektor $u_j$ yang sudah ada, lalu disamadengankan dengan 0.
5. Normalisasi vektor $u_j$ dan gabungkan hasil normalisasinya pada matriks $U$.
6. Terbentuklah, $A = U \Sigma V^T$.

## Cara 2
Cara yang sama, tetapi alih-alih mencari matriks $V$ terlebih dahulu, kita mencari matriks $U$ dengan menggunakan matriks $A A^T$ sebagai matriks yang dicari nilai dan vektor eigennya. Lalu, untuk langkah nomor 3, kita menghitung $v_j$ bukan $u_j$ (karena $U$-nya sudah diketahui terlebih dahulu, sisa mencari $V$).

## Cara 3
Cara ini ada di file [[22-Singular-value-decomposition-Bagian2-2025.pdf]], tetapi saat dicari ke sumber-sumber lain, tidak ditemukan cara yang serupa. 
1. Ulang langkah 1 dan 2 pada Cara 1.
2. Buatlah matriks $A A^T$, lalu cari nilai dan vektor eigennya. Urutkan vektor eigen secara menurun berdasarkan nilai eigennya, lalu gabungkan dalam sebuah matriks $U$, Lalu, normalisasi vektor eigen agar matriks $U$ menjadi matriks ortogonal.
3. Terbentuklah, $A = U \Sigma V^T$.

Cara ini dapat menghasilkan inkonsistensi, karena untuk nilai eigen yang sama, vektor eigen yang dihasilkan bisa berbeda arah dan keduanya valid ($v_j$ dan $-v_j$). Jika menghitung $U$ dan $V$ secara terpisah, harus dipastikan bahwa pasangan yang dipilih memenuhim $Av_j= \sigma_j u_j$. Jika ada yang tidak sesuai, coba balik tanda dari $v_j$. Hal ini bisa ditanggulangi dengan mengecek ulang hasil dekomposisi setelah menghitun SVD. (Apakah $U \cdot \Sigma \cdot V^T =A$?). 

