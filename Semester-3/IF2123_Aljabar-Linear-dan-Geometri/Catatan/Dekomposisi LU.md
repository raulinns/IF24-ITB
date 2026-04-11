Matriks $A$ persegi non-singular dapat didekomposisi menjadi matriks segitiga bawah $L$ (*lower*) dan matriks segitiga atas $U$ (*upper*).

$$
\begin{align}
A &= LU \\
\begin{bmatrix}
a_{11} & a_{12} & a_{13} & \dots & a_1n \\
a_{21} & a_{22} & a_{23} & \dots & a_2n \\
a_{31} & a_{32} & a_{33} & \dots & a_3n \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & a_{n3} & \dots & a_{nn} \\
\end{bmatrix} &= 
\begin{bmatrix}
1 & 0 & 0 & \dots & 0 \\
l_{21} & 1 & 0 & \dots & 0 \\
l_{31} & l_{32} & 1 & \dots & 0 \\
\vdots & \vdots & \vdots & \ddots & 0 \\
l_{n1} & l_{n2} & l_{n3} & \dots &  1
\end{bmatrix}
\begin{bmatrix}
u_{11} & u_{12} & u_{13} & \dots & u_{1n} \\
0 & u_{22} & u_{23} & \dots & u_{2n} \\
0 & 0 & u_{33} & \dots & u_{3n} \\
\vdots & \vdots & \vdots & \ddots  & \vdots \\
0 & 0 & 0 & \dots & u_{nn}
\end{bmatrix}
\end{align}
$$

> Catatan: Di dalam kelas dan di literatur lain, elemen diagonal utama matriks $L$ semuanya 1. Tetapi, di dalam buku [[Howard-Anton-Chris-Rorres-Elementary-Linear-Algebra-10th-Version.pdf]] elemen di dalam diagonal utama matriks $U$ yang semuanya 1. Perbedaan keduanya tidak masalah, karena hasil kali keduanya tetap sama dengan $A$. 

Memfaktorkan matriks $A$ menjad matriks $L$ dan $U$ dinamakan dekomposisi LU. Terdapat dua metode untuk melakukan dekomposisi LU:
1. Metode LU-Gauss, menggunakan metode eliminasi Gauss
2. Metode reduksi Crout, menggunakan kesamaan dua buah matriks.

# Metode LU-Gauss
$$
\begin{bmatrix}
a_{11} & a_{12} & a_{13} & \dots & a_1n \\
a_{21} & a_{22} & a_{23} & \dots & a_2n \\
a_{31} & a_{32} & a_{33} & \dots & a_3n \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & a_{n3} & \dots & a_{nn} \\
\end{bmatrix} = 
\begin{bmatrix}
1 & 0 & 0 & \dots & 0 \\
m_{21} & 1 & 0 & \dots & 0 \\
m_{31} & m_{32} & 1 & \dots & 0 \\
\vdots & \vdots & \vdots & \ddots & 0 \\
m_{n1} & m_{n2} & m_{n3} & \dots &  1
\end{bmatrix}
\begin{bmatrix}
u_{11} & u_{12} & u_{13} & \dots & u_{1n} \\
0 & u_{22} & u_{23} & \dots & u_{2n} \\
0 & 0 & u_{33} & \dots & u_{3n} \\
\vdots & \vdots & \vdots & \ddots  & \vdots \\
0 & 0 & 0 & \dots & u_{nn}
\end{bmatrix}
$$

Di sini, kita menggunakan simbol $m_{ij}$ daripada $l_{ij}$, karena nilai $l_ij$ akan berasal dari faktor pengali ($m_{ij}$) pada OBE ($R_j - m_{ij}R_i$).

Langkah-langkah menggunakan metode LU-Gauss adalah sebagai berikut:
1. Nyatakan $A$ sebagai $A = IA$.
$$
\begin{bmatrix}
a_{11} & a_{12} & a_{13} & \dots & a_1n \\
a_{21} & a_{22} & a_{23} & \dots & a_2n \\
a_{31} & a_{32} & a_{33} & \dots & a_3n \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & a_{n3} & \dots & a_{nn} \\
\end{bmatrix} = 
\begin{bmatrix}
1 & 0 & 0 & \dots & 0 \\
0 & 1 & 0 & \dots & 0 \\
0 & 0 & 1 & \dots & 0 \\
\vdots & \vdots & \vdots & \ddots & 0 \\
0 & 0 & 0 & \dots &  1
\end{bmatrix}
\begin{bmatrix}
a_{11} & a_{12} & a_{13} & \dots & a_1n \\
a_{21} & a_{22} & a_{23} & \dots & a_2n \\
a_{31} & a_{32} & a_{33} & \dots & a_3n \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & a_{n3} & \dots & a_{nn} \\
\end{bmatrix}
$$
2. Lakukan eliminasi Gauss pada matriks $A$ menjadi matriks $U$. tempatkan faktor pengali $m_{ij}$ pada posisi $l_{ij}$ di dalam matriks $I$.
3. Setelah seluruh proses eliminasi Gauss selesai, matriks $I$ menjadi matriks $L$ dan matriks $A$ di ruas kanan menjadi matriks $U$.

Apabila ada pertukaran baris dalam pencarian matriks $U$, maka pertukarkan juga baris untuk pengali yang ada pada matriks $L$ (diagonalnya tidak termasuk) dan matriks $b$ (jika menghitung SPL menggunakan Dekomposisi LU).



# Metode Reduksi Crout
Meskipun, LU Gauss dapat digunakan uyntuk melakukan dekomposisi LU, terdapat metode dekomposisi lain yang digunakan secara luas, yaitu metode reduksi Crout. Dapat juga disebut sebagai metode reduksi Cholesky atau metode Dolittle.

Metode reduksi Crout memiliki bentuk sebagai berikut:
$$
A = \begin{bmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23}  \\
a_{31} & a_{32} & a_{33}
\end{bmatrix} \space L =
\begin{bmatrix}
1 & 0 & 0 \\
l_{21} & 1 & 0 \\
l_{31} & l_{32} & 1
\end{bmatrix} \space U =
\begin{bmatrix}
u_{11}  & u_{12} & u_{13} \\
0 & u_{22} & u_{23} \\
0 & 0 & u_{33}
\end{bmatrix}
$$
Sehingga,
$$
A = LU =
\begin{bmatrix}
u_{11} & u_{12} & u_{13} \\
l_{21}u_{11} & l_{21}u_{12} + u_{22} & l_{21}u_{13}+u_{23} \\
l_{31}u_{13} & l_{31}u_{12}+l_{32}u_{22} & l_{31}u_{13} + l_{32}u_{23} + u_{33}
\end{bmatrix} =
\begin{bmatrix}
a_{11} & a_{12} & a_{13} \\
a_{21} & a_{22} & a_{23} \\
a_{31} & a_{32} & a_{33}
\end{bmatrix}
$$

Dari kesamaan ini dapat diperoleh langkah-langkah sebagai berikut:
1. Mencari baris pertama $U$. Kalikan baris-baris $L$ dengan kolom-kolom $U$. Baris pertama $U$ identik dengan baris pertama $A$
$$
\begin{align}
1 \cdot u_{11} &= a_{11} \\
1 \cdot u_{12} &= a_{12} \\
1 \cdot u_{13} &= a_{13}
\end{align}
$$

2. Mencari kolom pertama $L$. Kalikan baris-baris $L$ (selain baris 1) dengan kolom pertama $U$. Kolom pertama $L$ adalah kolom pertama $A$ dibagi dengan pivot pertama ($u_{11}$)
$$
\begin{align}
l_{21} \cdot u_{11} = a_{21} &\implies l_{21} = \frac{a_{21}}{u_{11}} \\
l_{31} \cdot u_{11} = a_{31} &\implies l_{31} = \frac{a_{31}}{u_{11}}​ \\
l_{i1} &= \frac{a_{i1}}{u_{11}} \quad \text{untuk } i = 2, \dots, n
\end{align}
$$

3. Untuk baris selanjutnya, nilai $u$ adalah nilai asli $a$ dikurangi hasil kali elemen $l$ dan $u$ yang bersesuaian yang sudah dihitung sebelumnya.

$$
u_{kj} = a_{kj} - \sum_{r=1}^{k-1} l_{kr} u_{rj} \quad \text{untuk } j = k, \dots, n
$$

4. Untuk kolom selanjutnya, rumusnya mirip dengan $U$, namun dibagi dengan elemen diagonal $U$ ($u_{kk}$).

$$
l_{ik} = \frac{a_{ik} - \sum_{r=1}^{k-1} l_{ir} u_{rk}}{u_{kk}} \quad \text{untuk } i = k+1, \dots, n
$$

# Aplikasi Dekomposisi LU
## Penyelesaian SPL
Dekomposisi LU dapat digunakan untuk menyelesaikan sistem persamaan linier $A\mathbf{x} = b$. Setelah $A$ difaktorkan menjadi $A = LU$, maka:
$$
A\mathbf{x} = b \implies LU \mathbf{x} = b
$$
Misalkan, $U\mathbf{x} = y$, maka:
$$
LU\mathbf{x} = b \implies Ly = b
$$

Untuk memperoleh $y_1, y_2, \dots, y_n$, kita menggun

### Tahap 1: Substitusi Maju (Forward Substitution)
Selesaikan $\mathbf{Ly} = \mathbf{b}$ untuk mendapatkan vektor $\mathbf{y}$.
$$
\begin{bmatrix} 
1 & 0 & 0 \\ 
l_{21} & 1 & 0 \\ 
l_{31} & l_{32} & 1 
\end{bmatrix}
\begin{bmatrix} y_1 \\ y_2 \\ y_3 \end{bmatrix} 
= 
\begin{bmatrix} b_1 \\ b_2 \\ b_3 \end{bmatrix}
$$

### Tahap 2: Substitusi Balik (Backward Substitution)
Selesaikan $\mathbf{Ux} = \mathbf{y}$ untuk mendapatkan solusi akhir $\mathbf{x}$.
$$
\begin{bmatrix} 
u_{11} & u_{12} & u_{13} \\ 
0 & u_{22} & u_{23} \\ 
0 & 0 & u_{33} 
\end{bmatrix}
\begin{bmatrix} x_1 \\ x_2 \\ x_3 \end{bmatrix} 
= 
\begin{bmatrix} y_1 \\ y_2 \\ y_3 \end{bmatrix}
$$


## Menghitung Determinan
Determinan matriks $A$ dapat dihitung dari perkalian determinan matriks $L$ dan determinan matriks $U$.

### Kasus 1: Tidak ada pertukaran baris
$$
\begin{align}
\det(A) &= \det(LU) \\
 &= \det(L) \times \det(U) \\
 & = 1 \times \det(U) \\
 & = \det(U) \\
 & = u_{11} \times u_{22} \times u_{33} \times \dots \times u_nn
\end{align}
$$

### Kasus 2: Terdapat pertukaran baris
Jika terdapat operasi pertukaran baris, maka dekomposisi $LU$ dengan operasi pertukaran baris setara dengan mengerjakan dua proses terpisah berikut:
1. Pertukaran baris dapat dipandang sebagai transformasi matriks $A$ menjadi matriks $A'$ dengan cara permutasi baris-baris matriks (sama dengan mengalikan $A$ dengan matriks permutasi $P$)
$$
A = PA \implies A = P^{-1} A'
$$
2. Dekomposisi $A'$ menjadi LU tanpa operasi pertukaran baris
$$
A' = LU \implies A = P^{-1}A' = P^{-1} LU
$$
3. Maka, determinan $A$ dapat ditulis sebagai:
$$
\begin{align}
\det(A) &= \det(P^{-1}) \times \det(L) \times \det(U) \\
&= \det(P^{-1}) \times 1 \times \det(U) \\
&= \det(P^{-1}) \times \det(U) \\
&= \alpha \det(U)
\end{align}
$$
Dalam hal ini $\alpha = \det(P^{-1}) = 1 \lor -1$ bergantung apakah pertukaran baris dilakukan sejumlah bilangan ganjil atau genap. Atau dapat ditulis juga $\alpha = (-1)^p$

$$
\det(A) = (-1)^p \det(U) = (-1)^p \frac{u_{11} u_{22} \dots u_{nn}}{k_1 k_2 \dots k_m}
$$
