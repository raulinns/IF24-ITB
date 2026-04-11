# SVD Tereduksi
Baris dan kolom bernilai nol pada matriks $\Sigma$ dapat dihilangkan sehingga menjadi:
$$
A = 
\begin{bmatrix}
u_1 & u_2 & \dots & u_k
\end{bmatrix}
\begin{bmatrix}
\sigma_1 & 0 & \dots & 0 \\
0 & \sigma_2 & \dots & 0  \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \dots & \sigma_k
\end{bmatrix}
\begin{bmatrix}
v_{1}^T \\
v_2^T \\
\vdots \\
v_k^T
\end{bmatrix} = U_1 \Sigma_1 V_1
$$


SVD dengan bentuk seperti itu, disebut dengan SVD tereduksi. Perhatikan bahwa notasinya juga berbeda (terdapat *subscript* 1 di masing-masing variabel matriks).

$U_1$ berukuran $m \times k$, $\Sigma_1$ berukuran $k \times k$, dan $V^T$ berukuran $k \times n$. Matriks $\Sigma_1$ memiliki balikan karena semua elemen diagonal utamanya positif.

Bentuk SVD tereduksi dapat ditulis sebagai jumlahan dari $r$ buah matriks `rank-1`:
$$
\mathbf{A} = \sigma_1 \mathbf{u}_1 \mathbf{v}_1^T + \sigma_2 \mathbf{u}_2 \mathbf{v}_2^T + \dots + \sigma_r \mathbf{u}_r \mathbf{v}_r^T
$$

Bentuk ini dinamakan bentuk ekspansi SVD.

Setiap suku $\sigma_i \mathbf{u}_i \mathbf{v}_i^T$ adalah matriks $m \times n$ dengan rank 1. Suku pertama ($\sigma_1 \mathbf{u}_1 \mathbf{v}_1^T$) adalah aproksimasi rank-1 terbaik untuk matriks $A$, karena semakin kiri suku, nilai eigen yang disimpan juga lebih besar.

# SVD dan Empat Ruang Submatriks Fundamental

SVD menyediakan basis ortonormal untuk keempat ruang submatriks fundamental dari **A** (dengan rank $r$):

| Ruang Submatriks | Basis Ortonormal (dari SVD) |
| :--- | :--- |
| **Ruang Baris** ($\text{Row}(\mathbf{A})$) | $\{\mathbf{v}_1, \dots, \mathbf{v}_r\}$ (Kolom $r$ pertama dari **V**) |
| **Ruang Nol** ($N(\mathbf{A})$) | $\{\mathbf{v}_{r+1}, \dots, \mathbf{v}_n\}$ (Kolom $n-r$ terakhir dari **V**) |
| **Ruang Kolom** ($\text{Col}(\mathbf{A})$) | $\{\mathbf{u}_1, \dots, \mathbf{u}_r\}$ (Kolom $r$ pertama dari **U**) |
| **Ruang Nol Kiri** ($N(\mathbf{A}^T)$) | $\{\mathbf{u}_{r+1}, \dots, \mathbf{u}_m\}$ (Kolom $m-r$ terakhir dari **U**) |

# Aplikasi SVD
### Pseudo-Inverse (Invers Semu)
Jika matriks **A** tidak persegi atau tidak invertible, kita tidak bisa mencari $\mathbf{A}^{-1}$. Namun, kita bisa mendefinisikan **pseudo-inverse** $\mathbf{A}^+$:

Jika SVD dari **A** adalah $\mathbf{A} = \mathbf{U}\mathbf{\Sigma}\mathbf{V}^T$, maka:
$$
\mathbf{A}^+ = \mathbf{V}\mathbf{\Sigma}^+\mathbf{U}^T
$$
di mana $\mathbf{\Sigma}^+$ adalah matriks $n \times m$ yang diperoleh dengan mengambil kebalikan ($1/\sigma_i$) dari setiap nilai singular tidak-nol di $\mathbf{\Sigma}$, dan kemudian mentranspos matriks $\mathbf{\Sigma}$ yang dihasilkan.

### Solusi Least-Squares
SVD menyediakan cara elegan untuk menyelesaikan masalah *least-squares* (mencari solusi "terbaik" untuk sistem $\mathbf{Ax}=\mathbf{b}$ yang inkonsisten). Solusi *least-squares* diberikan oleh:

$$
\mathbf{x} = \mathbf{A}^+ \mathbf{b}
$$


### Kompresi Citra (Image Compression)
Ekspansi SVD ($\mathbf{A} = \sum \sigma_i \mathbf{u}_i \mathbf{v}_i^T$) sangat ideal untuk kompresi. Nilai-nilai singular $\sigma_i$ seringkali menurun drastis.
* Dengan hanya menyimpan $k$ suku pertama (dengan $k < r$), kita mendapatkan aproksimasi rank-k dari matriks **A** yang sangat baik.
* Ini menghemat ruang penyimpanan secara signifikan dengan mengorbankan sedikit kualitas gambar.
