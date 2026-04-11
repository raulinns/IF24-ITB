#  Nilai Eigen dan Invertibilitas Matriks
Terdapat hubungan fundamental antara nilai eigen suatu matriks dengan kemampuannya untuk di-invers (invertibilitas).

> **Teorema:** Sebuah matriks persegi $\mathbf{A}$ berukuran $n \times n$ **memiliki balikan (invertible)** jika dan hanya jika **$\lambda = 0$ bukan** merupakan salah satu nilai eigen dari **A**.

Hal ini sejalan dengan sifat-sifat matriks yang telah dipelajari sebelumnya:
* Jika $\mathbf{A}$ memiliki balikan, maka $\det(\mathbf{A}) \neq 0$.
* Persamaan karakteristik adalah $\det(\lambda\mathbf{I} - \mathbf{A}) = 0$.
* Jika kita substitusi $\lambda = 0$ ke persamaan karakteristik, kita mendapatkan $\det(-\mathbf{A}) = 0$, yang setara dengan $\det(\mathbf{A}) = 0$.
* Jadi, $\lambda = 0$ adalah nilai eigen jika dan hanya jika $\det(\mathbf{A}) = 0$, yang berarti **A** tidak memiliki balikan.

# Diagonalisasi
Matriks diagonal adalah matriks yang  semua entri di luar diagonal utamanya adalah nol.

Contoh: $D = \begin{bmatrix} 2 & 0 & 0 \\ 0 & 4 & 0 \\ 0 & 0 & 1 \end{bmatrix}$

Sebuah matriks persegi $A$ dikatakan dapat didiagonalisasi jika ia "mirip" dengan matriks diagonal, yaitu terdapat matriks $P$ yang invertibel (memiliki balikan) sedemikian sehingga:
$$
P^{-1} A P
$$

> **Teorema**: Matriks $\mathbf{A}$ dapat didiagonalisasi jika dan hanya jika $\mathbf{A}$ memiliki $n$ buah vektor eigen yang bebas linier.

$P$ adalah matriks $n \times n$ yang kolom-kolomnya terdiri dari $n$ vektor basis dari ruang eigen (vektor eigen) dari $A$.
$$
P = \begin{bmatrix} | & | & & | \\ \mathbf{p}_1 & \mathbf{p}_2 & \dots & \mathbf{p}_n \\ | & | & & | \end{bmatrix}
$$

Matriks diagonal $\mathbf{D} = \mathbf{P}^{-1}\mathbf{AP}$ akan memiliki nilai-nilai eigen $\lambda_1, \lambda_2, \dots, \lambda_n$ yang bersesuaian dengan vektor eigen $\mathbf{p}_1, \mathbf{p}_2, \dots, \mathbf{p}_n$ sebagai entri-entri diagonalnya.

Misalkan $D$ adalah matriks diagonal, maka
$$
A = PDP^{-1} \implies D = P^{-1} A P
$$

Sebelumnya disebutkan bahwa matriks $A$ dan maktris diagonalnya ($D$) memiliki kemiripan, beberapa di antaranya adalah determinan, *rank*, *nulity*, *trace*, persamaan karakteristik, nilai-nilai eigen, dan dimensi ruang eigen.

# Prosedur untuk Mendiagonalisasi Matriks
Berikut adalah langkah-langkah untuk mendiagonalisasi matriks $\mathbf{A}$:
1.  Selesaikan persamaan karakteristik $\det(\lambda\mathbf{I} - \mathbf{A}) = 0$ untuk mendapatkan nilai-nilai eigen $\lambda_1, \dots, \lambda_n$.
2.  Untuk setiap nilai eigen $\lambda_i$, cari basis untuk ruang eigen $E(\lambda_i)$ dengan menyelesaikan sistem homogen $(\lambda_i\mathbf{I} - \mathbf{A})\mathbf{x} = \mathbf{0}$.
3.  Hitung jumlah total vektor basis yang ditemukan dari semua ruang eigen.
    * Jika jumlah total vektor basis sama dengan $n$ (ukuran matriks $A$), maka $A$ dapat didiagonalisasi.
    * Jika jumlah total vektor basis **kurang dari $n$**, maka **A tidak dapat didiagonalisasi**.
4.  Susun $n$ vektor basis yang ditemukan sebagai kolom-kolom matriks $P$.
5.  Susun nilai-nilai eigen yang bersesuaian dengan urutan kolom $P$ sebagai entri diagonal matriks $D$.


# Kegunaan Diagonalisasi
Diagonalisasi sangat berguna untuk menghitung pangkat dari sebuah matriks $\mathbf{A}^k$ dengan efisien.

Jika $\mathbf{A}$ dapat didiagonalisasi, maka $\mathbf{A} = \mathbf{P}\mathbf{D}\mathbf{P}^{-1}$. Untuk menghitung $\mathbf{A}^k$ (misalnya $k=3$):

$$
\mathbf{A}^3 = (\mathbf{P}\mathbf{D}\mathbf{P}^{-1})(\mathbf{P}\mathbf{D}\mathbf{P}^{-1})(\mathbf{P}\mathbf{D}\mathbf{P}^{-1})
$$
$$
\mathbf{A}^3 = \mathbf{P}\mathbf{D}(\mathbf{P}^{-1}\mathbf{P})\mathbf{D}(\mathbf{P}^{-1}\mathbf{P})\mathbf{D}\mathbf{P}^{-1}
$$
$$
\mathbf{A}^3 = \mathbf{P}\mathbf{D}\mathbf{I}\mathbf{D}\mathbf{I}\mathbf{D}\mathbf{P}^{-1} = \mathbf{P}\mathbf{D}\mathbf{D}\mathbf{D}\mathbf{P}^{-1}
$$
$$
\mathbf{A}^k = \mathbf{P}\mathbf{D}^k\mathbf{P}^{-1}
$$

Dengan ini mencari pangkat akan jauh lebih mudah, karena menghitung $D^k$ cukup pangkatkan setiap entri diagonalnya. Jika $D = \begin{bmatrix} \lambda_1 & 0 \\ 0 & \lambda_2 \end{bmatrix}$, maka $D^k = \begin{bmatrix} \lambda_1^k & 0 \\ 0 & \lambda_2^k \end{bmatrix}$.

# Aplikasi Nilai Eigen
Nilai eigen dan vektor eigen digunakan secara luas dalam berbagai bidang:
* **Analytic Hierarchy Process (AHP):** Metode pengambilan keputusan yang menggunakan perbandingan berpasangan (pairwise comparison) untuk menentukan prioritas. Vektor eigen dari matriks perbandingan tersebut akan menghasilkan "vektor prioritas" yang menunjukkan bobot atau peringkat dari setiap pilihan.
* **Eigenface (Pengenalan Wajah):** Dalam *computer vision*, metode ini menggunakan vektor eigen (disebut *eigenfaces*) dari matriks kovarian citra wajah. Setiap wajah dalam database dapat direpresentasikan sebagai kombinasi linear (pembobotan) dari *eigenfaces* ini, yang memungkinkan pengenalan dan klasifikasi wajah.

Untuk penjelasan lebih lanjut terkait dengan aplikasi nilai eigen, terutama terkait **AHP** silakan tinjau slide [[20-Nilai-Eigen-dan-Vektor-Eigen.pdf]] pada halaman ke-27.