:## Determinan
Misalkan $A$ adalah matriks berukuran $n \times n$.
$$
A = \begin{bmatrix} 
a_{11} && a_{12} && \dots && a_{1n} \\
a_{21} && a_{22} && \dots && a_{2n} \\
\vdots && \vdots && \vdots && \vdots \\
a_{n1} && a_{n2} && \dots && a_{nn} 
\end{bmatrix}
$$
Determinan matriks A dilambangkan dengan
$$
det(A) = A = [a_{ij}] = 

\begin{vmatrix} 
a_{11} && a_{12} && \dots && a_{1n} \\
a_{21} && a_{22} && \dots && a_{2n} \\
\vdots && \vdots && \vdots && \vdots \\
a_{n1} && a_{n2} && \dots && a_{nn} 
\end{vmatrix}
$$
Untuk matriks $A$ berukuran $2 \times 2$ sebagai berikut
$$
A = 
\begin{bmatrix}
a_{11} && a_{12} \\
a_{21} && a_{22} \\
\end{bmatrix}
$$
maka $det(A) = a_{11} \cdot a_{22} - a_{12} \cdot a_{21}$ 

Untuk matriks $A$ berukuran $3 \times 3$ sebagai berikut
$$
A =
\begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33}
\end{bmatrix}
$$

maka 
$$
\begin{align*}
\det(A) = (a_{11} \cdot a_{22} \cdot a_{33} + a_{12} \cdot a_{21} \cdot a_{31} + a_{13}\cdot a_{21} \cdot a_{32}) \\

- (a_{13} \cdot a_{22} \cdot a_{31} + a_{11} \cdot a_{23} \cdot a_{32} + a_{12} \cdot a_{21} \cdot a_{33})
\end{align*}
$$


Sedangkan untuk matriks segitiga, determinannya adalah
$$
\det(A) = a_{11} \times a_{22} \times \dots \times a_{nn}
$$
Matriks segitiga adalah matriks yang semua elemen di bawah/atas diagonal utama adalah nol.

## Aturan Determinan
Misalkan $A$ adalah matriks $n \times n$. Matriks $B$ adalah matriks yang diperoleh dengan memanipulasi matriks $A$. Maka, determinan $B$ memiliki hubungan dengan determinan $A$ sebagai berikut.
1. Jika sebuah baris dikalikan dengan skala $k$, maka $\det(B) = k \cdot \det(A)$
2. Jika dua baris dipertukarkan, maka $\det(B) = - \det(A)$
3. Jika sebuah baris ditambahkan dengan $k$ kali baris yang lain, maka $\det(B) = \det(A)$

## Menghitung Determinan dengan Reduksi Baris
Determinan matriks $A$ dapat diperoleh dengan menggunakan OBE pada matriks $A$ sampai diperoleh matriks segitiga (segitiga bawah atau atas)

$$
\begin{align*}
\begin{bmatrix}
A
\end{bmatrix}
&\overset{OBE}\sim \begin{bmatrix}
\textsf{matriks segitiga bawah}
\end{bmatrix} \\ \\
\begin{vmatrix} 
a_{11} && a_{12} && \dots && a_{1n} \\
a_{21} && a_{22} && \dots && a_{2n} \\
\vdots && \vdots && \vdots && \vdots \\
a_{n1} && a_{n2} && \dots && a_{nn} 
\end{vmatrix}
&\overset{OBE}\sim
\begin{vmatrix} 
a'_{11} && a'_{12} && \dots && a'_{1n} \\
0 && a'_{22} && \dots && a'_{2n} \\
\vdots && \vdots && \vdots && \vdots \\
0 && 0 && 0 && a'_{nn} 
\end{vmatrix}
\end{align*}
$$

maka $\det(A) = (-1)^p a'_{11} \cdot a'_{22} \cdot \dots \cdot a'_{nn}$  dengan $p$ menyatakan banyaknya operasi pertukaran baris di dalam OBE.

Jika selama reduksi baris ada OBE berupa perkalian baris-baris matriks dengan $k_1, k_2, \dots, k_m$, maka
$$
\det(A) = \frac{(-1)^p a'_{11} \cdot a'_{22} \cdot \dots \cdot a'_{nn}}{k_1 \cdot k_2 \cdot \dots \cdot k_m}
$$

## Teorema tentang Determinan
1. Jika $A$ mengandung baris nol atau kolom nol, maka $\det(A) = 0$
2. Jika $A^T$ adalah matriks transpose dari A, maka $\det(A^T) = \det(A)$
3. Jika $A = BC$, maka $\det(A) = \det(B) \cdot \det(C)$
4.  Sebuah matriks hanya mempunyai balikan jika dan hanya jika $\text{det}(A) \neq 0$
5.  $\text{det}(A^{-1}) = 1/\text{det}(A)$
$$
\begin{align*}
AA^{-1} &= I \\
\text{det}(AA^{-1}) &= \text{det}(I) \\
\text{det}(A)\text{det}(A^{-1}) &= 1 \\
\text{det}(A^{-1}) &= 1/\text{det}(A)
\end{align*}
$$

Jika $A$ adalah sebuah matriks $n \times n$, maka pernyataan-pernyataan berikut ekuivalen.
1. $A$ dapat dibalik (*is invertible*).
2. $A\mathbf{x} = \mathbf{0}$ hanya memiliki solusi trivial.
3. Bentuk eselon baris tereduksi dari $A$ adalah $I_n$.
4. $A$ dapat diekspresikan sebagai produk dari matriks-matriks elementer.
5. $A\mathbf{x} = \mathbf{b}$ konsisten untuk setiap matriks $\mathbf{b}$ berukuran $n \times 1$.
6. $A\mathbf{x} = \mathbf{b}$ memiliki tepat satu solusi untuk setiap matriks $\mathbf{b}$ berukuran $n \times 1$.
7. $\text{det}(A) \neq 0$.

## Menghitung Determinan dengan Ekspansi Kofaktor
Misalkan A adalah matriks berukuran $n \times n$
$$
A = \begin{bmatrix} 
a_{11} && a_{12} && \dots && a_{1n} \\
a_{21} && a_{22} && \dots && a_{2n} \\
\vdots && \vdots && \vdots && \vdots \\
a_{n1} && a_{n2} && \dots && a_{nn} 
\end{bmatrix}
$$

Didefinisikan bahwa, 
1. $M_{ij}$ atau minor entri $a_{ij}$, yaitu determinan dari upa-matriks (*submatrix*) yang elemen-elemennya tidak berada pada baris $i$ dan kolom $j$.
2. C atau kofaktor entri $a_{ij}$, yaitu $(-1)^{i + j} M_{ij}$

Dalam praktiknya, kofaktor $C_{ij}$ berkoresponden dengan minor entri $M_{ij}$ hanya berbeda tanda saja tergantung nilai $i$ dan $j$. Pola tandanya adalah:
$$
\begin{bmatrix}
+ & - & + & - & \dots \\
- & + & - & + & \dots \\
+ & - & + & - & \dots \\
- & + & - & + & \dots \\
\vdots & \vdots & \vdots & \vdots & \dots \\
\end{bmatrix}
$$

Dengan menggunakan kofaktor, maka determinan matriks $A$ dapat dihitung dengan salah satu persamaan berikut
1. **Secara Baris**:
    * Sepanjang baris ke-1: $\text{det}(A) = a_{11}C_{11} + a_{12}C_{12} + \dots + a_{1n}C_{1n}$
    
    * Sepanjang baris ke-2: $\text{det}(A) = a_{21}C_{21} + a_{22}C_{22} + \dots + a_{2n}C_{2n}$
    
    * dan seterusnya...

* **Secara Kolom**:
    * Sepanjang kolom ke-1: $\text{det}(A) = a_{11}C_{11} + a_{21}C_{21} + \dots + a_{n1}C_{n1}$
    
    * Sepanjang kolom ke-2: $\text{det}(A) = a_{12}C_{12} + a_{22}C_{22} + \dots + a_{n2}C_{n2}$
    
    * dan seterusnya...

### Tips Menghitung Determinan

1. Gunakan baris atau kolom yang memiliki elemen nol paling banyak untuk menghemat perhitungan. (Tidak perlu menghitung semua determinan dari $C_{ij}$ karena ada yang akan dikalikan nol)
2. Terapkan Operasi Baris Elementer (OBE) untuk menciptakan baris/kolom yang mengandung banyak elemen nol.

## Matriks Kofaktor
Jika A adalah matriks $n \times n$ dan $C_{ij}$ adalah kofaktor dari entri $a_{ij}$, maka matriks kofaktor dari A adalah:
    $$
    \begin{bmatrix}
    C_{11} & C_{12} & \dots & C_{1n} \\
    C_{21} & C_{22} & \dots & C_{2n} \\
    \vdots & \vdots & & \vdots \\
    C_{n1} & C_{n2} & \dots & C_{nn}
    \end{bmatrix} \text{}
    $$
    
Adjoin dari A, ditulis `adj(A)`, adalah transpose dari matriks kofaktornya.

### Mencari Matriks Balikan Menggunakan Adjoin

Balikan dari matriks A dapat dihitung menggunakan rumus:
$$
A^{-1} = \frac{1}{\text{det}(A)} \text{adj}(A) \text{}
$$

## Kaidah Cramer
Jika $A\mathbf{x} = \mathbf{b}$ adalah SPL yang terdiri dari n persamaan dan n peubah dengan $\text{det}(A) \neq 0$, maka SPL tersebut memiliki solusi unik yang diberikan oleh:
$$
x_1 = \frac{\text{det}(A_1)}{\text{det}(A)}, \quad x_2 = \frac{\text{det}(A_2)}{\text{det}(A)}, \quad \dots, \quad x_n = \frac{\text{det}(A_n)}{\text{det}(A)} \text{}
$$
Di mana $A_j$ adalah matriks yang diperoleh dengan mengganti kolom ke-j dari A dengan matriks kolom $\mathbf{b}$.