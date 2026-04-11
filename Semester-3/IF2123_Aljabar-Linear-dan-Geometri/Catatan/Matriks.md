# Matriks
Matriks $A$ dengan $m$ baris dan $n$ kolom, disebut juga matriks $m \times n$ dinotasikan sebagai berikut

$$
A = [a_{ij}] = 
\begin{bmatrix} 
a_{11} && a_{12} && \dots && a_{1n} \\
a_{21} && a_{22} && \dots && a_{2n} \\
\vdots && \vdots && \vdots && \vdots \\
a_{m1} && a_{m2} && \dots && a_{mn} 
\end{bmatrix}
$$

Jika matriks berukuran $m = n$, maka matriks tersebut dinamakan matriks persegi orde $n$.

Diagonal utama matriks persegi berukuran $n \times n$ adalah elemen $a_{ij}$ dengan $i = j$. Matriks $m \times n$ tidak memiliki diagonal utama.

Kegunaan matriks di bidang informatika adalah untuk representasi data, misalkan representasi graf, representasi citra digital, matriks kernel di dalam metode deep learning, serta representasi sistem persamaan linier.

## Operasi pada matriks
### Penjumlahan Matriks
Penjumlahan dua buah matriks dihitung sebagai berikut

$$
C_{m \times n} = A_{m \times n} + B_{m \times n}
$$

Misal, jika $A = [a_{ij}]$ dan $B = [b_{ij}]$, maka 

$$
C = A + B = [c_{ij}],\  c_{ij} = a_{ij} + b_{ij}
$$
dengan $i = 1, 2, \dots, m$ dan $j = 1,2, \dots, n$

Begitu juga dengan pengurangan matriks. 

### Perkalian Matriks

Perkalian dua buah matriks dihitung sebagai berikut
$$
C_{m \times n} = A_{m \times a} \times B_{a \times n}
$$

Misal, jika $A = [a_{ij}]$ dan $B = [b_{ij}]$, maka 
$$
C = A + B = [c_{ij}],\  c_{ij} = a_{i1} \cdot b_{1j} + a_{i2} \cdot b_{2j} + \dots + a_{in} \cdot b{nj}
$$ 
dengan $i = 1, 2, \dots, m$ dan $j = 1,2, \dots, n$. 
Syarat dari sebuah perkalian matriks adalah jumlah kolom $A$ dengan jumlah baris $B$ bernilai sama.

### Perkalian Matriks dengan Skalar

Misal, jika $A = [a_{ij}]$ dan $c$ adalah skalar, maka 
$$
c A = [c \cdot a_{ij}]
$$ 

dengan $i = 1, 2, \dots, m$ dan $j = 1,2, \dots, n$. 

### Kombinasi Linier

Perkalian matriks dapat dipandang sebagai kombinasi linier. Misalkan:

$$
A = 
\begin{bmatrix} 
a_{11} && a_{12} && \dots && a_{1n} \\
a_{21} && a_{22} && \dots && a_{2n} \\
\vdots && \vdots && \vdots && \vdots \\
a_{m1} && a_{m2} && \dots && a_{mn} 
\end{bmatrix} 
\textsf{ dan } X = 
\begin{bmatrix}
x_{1} \\
x_{2} \\
\vdots \\
x_{n} \\
\end{bmatrix}
$$

Maka, 

$$
A \cdot X = 
\begin{bmatrix} 
a_{11} \cdot x_1 + a_{12} \cdot x_2 + \dots + a_{1n} \cdot x_n \\
a_{21} \cdot x_1 + a_{22} \cdot x_2 + \dots + a_{2n} \cdot x_n \\
\vdots \qquad \qquad \vdots \qquad \qquad \qquad \vdots \\
a_{m1} \cdot x_1 + a_{m2} \cdot x_2 + \dots + a_{mn} \cdot x_n \\
\end{bmatrix} 
$$

Perhatikan bahwa tiap kolomnya sama-sama dikalikan oleh $x$ pada baris yang sama. Oleh karena itu, kita dapat merubah bentuknya menjadi perkalian skalar, seperti:

$$
A \cdot X = 
x_1 \begin{bmatrix}
a_{11} \\
a_{21} \\
\vdots \\
a_{m1} \\
\end{bmatrix}

+
x_1 \begin{bmatrix}
a_{12} \\
a_{22} \\
\vdots \\
a_{m2} \\
\end{bmatrix}

+ \cdots +
x_n \begin{bmatrix}
a_{1n} \\
a_{2n} \\
\vdots \\
a_{mn} \\
\end{bmatrix}
$$

Contoh: 
$$
AB = 
\begin{bmatrix} 1 & 2 & 4 \\ 2 & 6 & 0 \end{bmatrix} 
\begin{bmatrix} 4 & 1 & 4 & 3 \\ 0 & -1 & 3 & 1 \\ 2 & 7 & 5 & 2 \end{bmatrix}
= \begin{bmatrix} 12 & 27 & 30 & 13 \\ 8 & -4 & 26 & 12 \end{bmatrix}
$$

$$
\begin{align*} 
\begin{bmatrix} 12 \\ 8 \end{bmatrix} &= 
4\begin{bmatrix} 1 \\ 2 \end{bmatrix} + 0\begin{bmatrix} 2 \\ 6 \end{bmatrix} + 2\begin{bmatrix} 4 \\ 0 \end{bmatrix} \\ \\
\begin{bmatrix} 27 \\ -4 \end{bmatrix} &=
1\begin{bmatrix} 1 \\ 2 \end{bmatrix} - 1\begin{bmatrix} 2 \\ 6 \end{bmatrix} + 7\begin{bmatrix} 4 \\ 0 \end{bmatrix} \\ \\ 
\begin{bmatrix} 30 \\ 26 \end{bmatrix} &= 
4\begin{bmatrix} 1 \\ 2 \end{bmatrix} + 3\begin{bmatrix} 2 \\ 6 \end{bmatrix} + 5\begin{bmatrix} 4 \\ 0 \end{bmatrix} \\ \\ 
\begin{bmatrix} 13 \\ 12 \end{bmatrix} &= 3\begin{bmatrix} 1 \\ 2 \end{bmatrix} + 1\begin{bmatrix} 2 \\ 6 \end{bmatrix} + 2\begin{bmatrix} 4 \\ 0 \end{bmatrix} \end{align*}
$$

### Transpose Matriks

Transpose sebuah matriks dihitung sebagai berikut
$$
B = A^{T}
$$

Misal, jika $A = [a_{ij}]$ dan $B = [b_{ij}]$, maka

$$
b_{ji} = a_{ij}
$$

dengan $i = 1, 2, \dots, m$ dan $j = 1,2, \dots, n$. 

Misalkan: 
$$
A = 

\begin{bmatrix} 
a_{11} && a_{12} && a_{13} && a_{14} \\
a_{21} && a_{22} && a_{23} && a_{24} \\
a_{31} && a_{32} && a_{33} && a_{34} \\
\end{bmatrix}

\textsf{, maka }

A^T = 
\begin{bmatrix} 
a_{11} && a_{21} && a_{31} \\
a_{12} && a_{22} && a_{32} \\
a_{13} && a_{23} && a_{33} \\
a_{14} && a_{24} && a_{34}
\end{bmatrix}
$$

Transpose Matriks memilik sifat-sifat sebagai berikut:

$$
\begin{align}
	1) & \ (A^T)^T &&= A \\
	2) & \ (A + B)^T &&= A^T + B^T \\
	3) & \ (A - B)^T &&= A^T - B^T \\
	4) & \ (kA)^T &&= k \cdot A^T \\
	5) & \ (AB)^T &&= B^T \cdot A^T \\
\end{align}
$$

### Trace sebuah Matriks

Jika $A$ adalah matriks persegi, maka trace matriks $A$ (dinotasikan dengan $tr(A)$) adalah jumlah semua elemen pada diagonal utama.
$$
A = 

\begin{bmatrix} 
a_{11} && a_{12} && a_{13} \\
a_{21} && a_{22} && a_{23} \\
a_{31} && a_{32} && a_{33} \\
\end{bmatrix}
$$
Maka, $tr(A) = a_{11} + a_{22} + a_{33}$. Jika $A$ bukan matriks persegi, maka $tr(A)$ tidak terdefinisi,

### Sifat-Sifat Operasi Aritmatika Matriks

$$
\begin{align*}
(a) \quad & A+B=B+A && \text{(Commutative law for addition)} \\
(b) \quad & A+(B+C)=(A+B)+C && \text{(Associative law for addition)} \\
(c) \quad & A(BC)=(AB)C && \text{(Associative law for multiplication)} \\
(d) \quad & A(B+C)=AB+AC && \text{(Left distributive law)} \\
(e) \quad & (B+C)A=BA+CA && \text{(Right distributive law)} \\
(f) \quad & A(B-C)=AB-AC \\
(g) \quad & (B-C)A=BA-CA \\
(h) \quad & a(B+C)=aB+aC \\
(i) \quad & a(B-C)=aB-aC \\
(j) \quad & (a+b)C=aC+bC \\
(k) \quad & (a-b)C=aC-bC \\
(l) \quad & a(bC)=(ab)C \\
(m) \quad & a(BC)=(aB)C=B(aC)
\end{align*}
$$
### Matriks Nol

Matriks nol adalah matriks yang seluruh elemennya bernilai 0. Matriks nol dilambangkan dengan 0. 
$$
\begin{bmatrix}
0 && 0 \\
0 && 0 \\
\end{bmatrix},

\begin{bmatrix}
0 && 0 && 0 \\
0 && 0 && 0 \\
0 && 0 && 0 \\
\end{bmatrix},

\begin{bmatrix}
0 && 0 && 0 \\
0 && 0 && 0 \\
\end{bmatrix},

\begin{bmatrix}
0
\end{bmatrix}
$$
Sifat-sifat matriks nol adalah: 
$$
\begin{align*}
(a) \quad & A + 0 = 0 + A = A \\
(b) \quad & A - 0 = A \\
(c) \quad & A - A = A + (-A) = 0  \\
(d) \quad & 0A = 0 \\
(e) \quad & cA = 0 \implies c = 0 \text{ or } A = 0
\end{align*}
$$

### Matriks Identitas

Matriks Identitas adalah matriks persegi yang semua elemen bernilai 1 pada diagonal utamanya dan bernilai 0 pada posisi lainnya

$$
\begin{bmatrix}
1 && 0 \\
0 && 1 \\
\end{bmatrix},
\begin{bmatrix}
1 && 0 && 0 \\
0 && 1 && 0 \\
0 && 0 && 1 \\
\end{bmatrix},
\begin{bmatrix}
1 && 0 && 0 && 0 \\
0 && 1 && 0 && 0 \\
0 && 0 && 1 && 0 \\
0 && 0 && 0 && 1 \\
\end{bmatrix},
\begin{bmatrix}
1
\end{bmatrix}
$$

Matriks Identitas disimbolkan dengan I.

Matriks identitas memiliki sifat, yaitu $AI = IA = A$

### Matriks Balikan

Matriks Balikan (invers) dari sebuah matriks A adalah matriks B sedemikian sehingga
$$
AB = BA = I
$$

Matriks balikan memiliki sifat, yaitu $A \cdot A^{-1} = A^{-1} \cdot A = I$. Untuk matriks $A$ berukuran $2 \times 2$, maka $A^{-1}$ dihitung sebagai berikut:
$$
A = 
\begin{bmatrix}
a && b \\
c && d \\
\end{bmatrix} \implies 

A^{-1} = \frac{1}{ad-bc} \cdot 
\begin{bmatrix}
d && -b \\
-c && a \\
\end{bmatrix}
$$

dengan syarat $D \ne 0$ .  $D=ad-bc$. Jika $D=0$, maka matriks tidak memiliki balikan dan dinamakan matriks singular.

# Matriks Eselon Baris

Matriks eselon baris (*row echelon form*) adalah matriks yang memilik 1 utama (*leading one*) pada setiap baris, kecuali pada baris yang seluruhnya nol.

Matriks eselon baris berbentuk:

$$
\begin{bmatrix}
1 && * && * \\
0 && 1 && * \\
0 && 0 && 1 \\
\end{bmatrix},

\begin{bmatrix}
1 && * && * && * \\
0 && 0 && 1 && * \\
0 && 0 && 0 && 1 \\
0 && 0 && 0 && 0 \\
\end{bmatrix},

\begin{bmatrix}
0 && 1 && * && * && * \\
0 && 0 && 0 && 1 && * \\
0 && 0 && 0 && 0 && 0 \\
0 && 0 && 0 && 0 && 0 \\
\end{bmatrix}
$$
Keterangan: * adalah sembarang nilai

Sifat-sifat matriks eselon baris:
1. Jika sebuah baris tidak terdiri dari seluruhnya nol, maka bilangan tidak nol pertama di dalam baris tersebut adalah 1 (disebut **1 utama**)
2. Jika ada baris yang seluruhnya nol, maka semua baris itu dikumpulkan pada bagian bawah matriks
3. Di dalam dua baris berturutan yang tidak seluruhnya nol, maka 1 utama pada baris yang lebih rendah terdapat lebih jauh ke kanan daripada 1 utama pada baris yang lebih tinggi

Ciri-ciri matriks eselon baris: memiliki semua nilai nol pada kolom di bawah 1 utama.

## Matriks Eselon Baris Tereduksi

Matriks eselon baris tereduksi (*reduce row echelon*) berbentuk:
$$
\begin{bmatrix}
1 && * && 0 && 0 \\
0 && 0 && 1 && 0 \\
0 && 0 && 0 && 1 \\
0 && 0 && 0 && 0 \\
\end{bmatrix},

\begin{bmatrix}
0 && 1 && 0 && 0 && * \\
0 && 0 && 1 && 0 && * \\
0 && 0 && 0 && 1 && * \\
0 && 0 && 0 && 0 && 0 \\
\end{bmatrix}, \textsf{ dst}
$$
Ciri-ciri matriks eselon baris tereduksi: memiliki semua nilai nol pada kolo di bawah dan di atas 1 utama.

Sifat-sifat matriks eselon baris tereduksi sama seperti matris eselon baris, tetapi dengan tambahan:
4. Setiap kolom yang memiliki 1 utama memiliki nol di tempat lain