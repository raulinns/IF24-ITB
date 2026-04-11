# Definisi Nilai Eigen dan Vektor Eigen
Jika  $A$ adalah matriks $n \times n$ , maka vektor **tidak-nol** $\mathbf{x}$ di $R^n$ disebut **vektor eigen** dari $A$ jika $A\mathbf{x}$ sama dengan perkalian suatu skalar $\lambda$ dengan . Persamaan fundamentalnya adalah:
$$
A\mathbf{x}=\lambda \mathbf{x}
$$

Skalar $\lambda$ disebut **nilai eigen** dari $A$, dan $\mathbf{x}$ dinamakan vektor eigen yang berkoresponden dengan $\lambda$.

Secara geometris, operasi $A\mathbf{x} = \lambda \mathbf{x}$ menyebabkan vektor $\mathbf{x}$ menyusut atau memanjang dengan faktor $\lambda$.
* Arah vektor $\mathbf{x}$ tetap **sama** jika $\lambda$ positif.
* Arah vektor $\mathbf{x}$ menjadi **berkebalikan** jika $\lambda$ negatif.

# Cara Menghitung Nilai dan Vektor Eigen
Untuk menemukan nilai eigen dan vektor eigen dari sebuah matriks **A**, kita memanipulasi persamaan dasarnya:
$$
\begin{align*}
A\mathbf{x} &= \lambda\mathbf{x} \\
\lambda \mathbf{x} - A\mathbf{x} &= 0 \\
\lambda I \mathbf{x} - I\mathbf{Ax} &= 0 \\
\lambda I\mathbf{x}- A\mathbf{x} &= 0 \\
(\lambda I - A)\mathbf{x} &= 0
\end{align*}
$$

Ini adalah sebuah sistem persamaan linear homogen. Agar sistem ini memiliki solusi $\mathbf{x}$ yang tidak-nol (sesuai definisi vektor eigen), matriks koefisien $(\lambda\mathbf{I} - \mathbf{A})$ haruslah singular, yang berarti determinannya harus nol. Persamaan ini disebut persamaan karakteristik.

$$
\det(\lambda\mathbf{I} - \mathbf{A}) = 0
$$

>  Perhatian: Tidak semua matriks memiliki nilai eigen. 0Matriks $A$ tidak memiliki nilai eigen jika persamaan karakteristiknya menghasilkan akar-akar imajiner (misalnya $\lambda^2 + 1 = 0$).

Setelah menemukan nilai-nilai eigen ($\lambda$), kita dapat menemukan vektor-vektor eigen yang bersesuaian dengan mensubstitusi nilai eigen dalam persamaan  $\lambda I - A = 0$ dan menyelesaikan persamaannya (dicari solusinya, misal menggunakan metode Gauss).

Himpunan semua solusi dari sistem homogen ini (termasuk vektor nol) adalah sebuah subruang dari $R^n$, yang disebut **ruang eigen** (eigenspace) dari **A** yang bersesuaian dengan $\lambda$.

## Aplikasi Nilai Eigen dan Vektor Eigen
Konsep ini memiliki berbagai aplikasi di berbagai bidang:
* **Grafika komputer** dan *computer vision*.
* **Fisika** (getaran mekanis, aliran panas, mekanika kuantum).
* **Biologi** (dinamika populasi).
* **Sistem pendukung keputusan** dan **Ekonomi**.gg