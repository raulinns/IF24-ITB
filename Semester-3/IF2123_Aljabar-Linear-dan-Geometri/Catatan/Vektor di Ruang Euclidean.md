Kuantitas fisik dapat direpresentasikan dalam dua jenis, yaitu skalar dan vektor. Skalar adalah nilai numerik yang menyatakan besaran kuantitas fisik tersebut. Misalnya: temperatur $15 \degree C$, laju kendaraan 75 km/jam,  atau panjang 2,5 meter. Sedangkan, 

> Vektor adalah kuantitas fisik yang memiliki besar dan arah. Misalkan, kecepatan ($v$) mobil 80 km/jam ke arah timur laut. 

Vektor dapat dinotasikan huruf-huruf kecil (dicetak tebal) atau memakai tanda panah. Contoh: **u**, **v**, **w** atau $\vec{u}, \vec{v}, \vec{w}$. Secara geometri, vektor di ruang 2 dimensi dinyatakan sebagai garis berarah.

> [!img-caption]  ![[Pasted image 20251013225654.png]]

# Vektor
Ruang vektor (*vector space*) adalah ruang tempat vektor didefinisikan atau disebut juga ruang Euclidean. $R^2, R^3, R^n$
> [!img-caption] ![[Pasted image 20251013230020.png]]

> Vektor di $R^n$ didefinisikan sebagai:

$$
v = (v_{1}, v_{2}, \dots, v_{n})$ \textsf{ atau }
v = 
\begin{bmatrix}
v_{1}  \\
v_{2} \\
v_{3} \\
\vdots  \\
v_{n}
\end{bmatrix}
$$

Semua vektor yang ditulis sebagai $v=(v_{1}, v_{2}) , v = (v_{1},v_{2}, v_{3})$  berawal dari **titik asal** $O$.

Vektor nol adalah vektor yang semua komponennya 0, vektor nol dilambangkan dengan $0$. Negatif dari vektor $v$ dilambangkan dengan $-v$, berarti besarannya sama tetapi arahnya berbeda.

# Operasi pada Vektor
## Penjumlahan dan Pengurangan pada Dua Vektor

Jika $v = (v_1, v_2, ..., v_n)$ dan $w = (w_1, w_2, ..., w_n)$ adalah vektor di $R^n$. 

$v + w = (v_1+w_1, v_2+w_2, ..., v_n+w_n)$. 

Sedangkan, untuk pengurangan dua vektor dapat dilakukan dengan: $v - w = w + (-v)$

Secara geometris, penjumlagan ini menggunakan kaidah segitiga atau jajargenjang (parallelogram).

## Perkalian Vektor dengan Skalar

 $kv = (kv_1, kv_2, ..., kv_n)$. Jika $k > 0$, arah $kv$ sama dengan $v$. Jika $k < 0$, arahnya berlawanan. $kv$ berarti vektor yang panjangnya $|k|$ kali dari panjang $v$.

## Vektor yang Tidak Berasal dari Titik Asal
 
 Vektor Antara Dua Titik Vektor yang berawal dari titik $P_1(x_1, y_1, z_1)$ dan berakhir di $P_2(x_2, y_2, z_2)$ adalah: $\vec{P_1P_2} = \vec{OP_{1}} - \vec{OP_{2}}=(x_2-x_1, y_2-y_1, z_2-z_1)$.

# Norma Vektor
Panjang (atau *magnitude*) sebuah vektor **v** dinamakan norma **v**. Norma vektor **v** dilambangkan dengan ||v||. Norma sebuah vektor dinamakan juga **norma Euclidean**.

Norma vektor **v** = $(v_{1}, v_{2}, \dots, v_{n})$ di $R_{n}$ adalah $||v|| = \sqrt{v_{1}^2 + v_{2}^2 + \dots + v_{n}^2}$. 

Jika **u** = $(u_{1}, u_{2}, \dots, u_{n})$ dan $v = (v_{1}, v_{2}, \dots, v_{n})$ adalah dua titik di $R_{n}$, maka jarak ($d$) kedua titik tersebut adalah
$$
d(u,v) = ||u-v|| = \sqrt{(u_1 - v_1)^2 + (u_2 - v_2)^2 + \dots + (u_n - v_n)^2}
$$
Jarak iini sering dinamakan jarak Euclidean. Jarak Euclidean berguna untuk menentukan seberapa dekat (atau seberapa mirip) sebuah objek dengna objek lain (*obejct recognition*, *face recognition*, dsb.)

# Arah Sebuah Vektor
Misalkan $\vec{v} = (v_1, v_2, v_3)$ adalah sbeuah vektor di $R_3$ maka arah vektor $\vec{v}$ adalah
> [!img-caption] ![[Pasted image 20251014004911.png]]

$$
\begin{align*}
\cos \alpha &= \frac{v_1}{||v||} \\
\cos \beta &= \frac{v_2}{||v||} \\
\cos \gamma &= \frac{v_3}{||v||} \\
\end{align*}


$$

## Sifat-Sifat Aljabar Vektor
Jika **u**, **v**, dan **w** adalah vektor pada $R_n$ dan $k$ dan $m$ adalah skalar, maka
$$
\begin{align}
\vec{u} + \vec{v} &= \vec{v} + \vec{u} \\
(\vec{u}+ \vec{v}) + \vec{w}&= \vec{u}+ (\vec{v}+ \vec{w}) \\
\vec{u} + 0  & = 0 + \vec{u} = u \\
\vec{u} + -\vec{u}  & = 0 \\
k(\vec{u} + \vec{v}) &= \vec{k}u + k \vec{v} \\
(k + m)\vec{u} &= k\vec{u}+ m\vec{u} \\
k(m\vec{u}) &= (km)\vec{u} \\
1 \vec{u} &= \vec{u}
\end{align}
$$



# Kombinasi Linier

Sebuah vektor **w** disebut sebagai kombinasi linier dari vektor-vektor $v_1, v_2, ..., v_r$ jika dapat dinyatakan dalam bentuk:
  $$ w = k_1v_1 + k_2v_2 + ... + k_rv_r $$
  di mana $k_1, k_2, ..., k_r$ adalah skalar.

# Vektor Satuan
Vektor Satuan (*Unit Vector*) adalah vektor yang memiliki norma (panjang) sama dengan 1. Vektor satuan dinotasikan dengan $\vec{u}$. Jika $\vec{v}$ adalah vektor di $R^n$ dan $\vec{v} \ne 0$, maka
$$
\vec{u} = \frac{\vec{v}}{||v||}
$$
Vektor $\vec{u}$ memiliki arah yang sama dengan $\vec{v}$. Proses "membagi" sebuah vektor $\vec{v}$ dengan panjangnya dinamakan menormalisasi vektor.

## Vektor Satuan Standar
Vektor satuan standar di $R^n$ adalah $e_1, e_2, \dots, e_n$, di mana
$$
e_1 = (1, 0, 0, \dots, 0), e_2 = (0, 1, 0, \dots, 0), \dots, e_n = (0, 0, 0, \dots ,1)
$$
Setiap vektor $v = (v_1, v_2, \dots, v_n$ di $R^n$ dapat dinyatakan sebagai kobinasi linier 
$$
v = v_1e_1 + v_2e_2 + \dots + v_ne_n
$$
Untuk vektor satuan standar di $R^3$ adalah $i, j, k$ 

# Perkalian Titik
Jika $\vec{u}$ dan $\vec{v}$ adakah vektor tidak nol di $R^2$ atau $R^3$, maka perkalian titik (*dot product*) atau disebut juga *Euclidean inner product*, $\vec{u}$ dan $\vec{v}$ adalah
$$
u \cdot v = ||u|| \cdot ||v|| \cdot \cos \theta
$$
yang dalam hal ini $\theta$ adalah sudut yang dibentuk oleh $\vec{u}$ dan $\vec{v}$. Jika $\vec{u} = 0$ dan $\vec{v} = 0$, maka $u  \cdot v = 0$. 

Secara umum, jika $\vec{u} = (u_1, u_2, \dots, u_n$ dan $\vec{v} = (v_1, v_2, \dots, v_n)$ adalah dua buah vektor di $R^n$ maka
$$
\vec{u} \cdot \vec{v} = u_1v_1 + u_2v_2 + \dots + u_nv_n
$$

Dari rumus perkalian titik ini, dapat ditulis sebagai
$$
\cos \theta = \frac{{u \cdot v}}{||u|| \cdot ||v||}
$$
dan karena $\vec{u} \cdot \vec{v} = u_1v_1 + u_2v_2 + \cdot + u_nv_n$, maka
$$
\cos \theta = \frac{u_1v_1 + u_2v_2 + \cdot + u_nv_n}{||u|| \cdot ||v||}
$$
## Sifat-Sifat Perkalian Titik
Jika $\vec{u}$, $\vec{v}$, dan $\vec{w}$ adalah vektor pada $R^n$ dan $k$ adalah skalar, maka
$$
\begin{align*}
\mathbf{u} \cdot \mathbf{v} &= \mathbf{v} \cdot \mathbf{u} \\
\mathbf{u} \cdot (\mathbf{v} + \mathbf{w}) &= \mathbf{u} \cdot \mathbf{v} + \mathbf{u} \cdot \mathbf{w} \\
k(\mathbf{u} \cdot \mathbf{v}) &= (k\mathbf{u}) \cdot \mathbf{v} \\
\mathbf{v} \cdot \mathbf{v} \geq 0 \cap \mathbf{v} \cdot \mathbf{v} &= 0 \iff \mathbf{v} = \mathbf{0} \\
\mathbf{0} \cdot \mathbf{v} &= \mathbf{v} \cdot \mathbf{0} = 0 \\
(\mathbf{u} + \mathbf{v}) \cdot \mathbf{w} &= \mathbf{u} \cdot \mathbf{w} + \mathbf{v} \cdot \mathbf{w}  \\
\mathbf{u} \cdot (\mathbf{v} - \mathbf{w}) &= \mathbf{u} \cdot \mathbf{v} - \mathbf{u} \cdot \mathbf{w} \\
(\mathbf{u} - \mathbf{v}) \cdot \mathbf{w} &= \mathbf{u} \cdot \mathbf{w} - \mathbf{v} \cdot \mathbf{w} \\
 k(\mathbf{u} \cdot \mathbf{v}) &= \mathbf{u} \cdot (k\mathbf{v})
\end{align*} 
$$



## Ketidaksamaan Cauchy-Schwarz
Jika $\textbf{u} = (u_1, u_2, \dots, u_n)$ dan $\textbf{v} = (v_1, v_2, \dots, v_n)$ adalah vektor di $R^n$, maka
$$
|u \cdot v| \le ||u|| \cdot ||v||
$$
atau
$$
|u_1v_1 + u_2v_2 + \cdot + u_nv_n| \le \sqrt{u_{1}^2 + u_{2}^2 + \dots + u_{n}^2} \cdot \sqrt{v_{1}^2 + v_{2}^2 + \dots + v_{n}^2}
$$

# Ortogonal dan Ortonormal
Dua vektor tak-nol **u** dan **v** dikatakan ortogonal (saling tegak lurus) jika perkalian titiknya sama dengan nol. $$ \mathbf{u} \cdot \mathbf{v} = 0 $$
Vektor nol selalu ortogonal dengan setiap vektor di $R^n$

Sebuah himpunan vektor disebut **himpunan ortogonal** di mana setiap pasang vektor di dalamnya saling ortogonal.  Sebuah himpunan ortogonal yang semua vektornya adalah vektor satuan (memiliki panjang/norma sama dengan 1) disebut **himpunan ortonormal**. 

Himpunan vektor satuan standar {**i**, **j**, **k**} di $R^3$ adalah himpunan ortogonal sekaligus himpunan ortonormal. 

## Proyeksi Ortogonal 
Setiap vektor **u** dapat diuraikan menjadi dua komponen vektor: 
1. $w_1$: Proyeksi ortogonal **u** pada vektor **v**. Ini adalah "bayangan" **u** pada **v**. $w_1$ dapat dikatakan sebagai perkalian skalar $k$ dengan ($\mathbf{v}$  $= k \mathbf{v}$)
2. $w_2$: Komponen vektor dari **u** yang ortogonal terhadap **v**. 

Berlaku hubungan: 
$$
\begin{align}
\mathbf{u} = \mathbf{w_1} + \mathbf{w_2} &= k \mathbf{v} + \mathbf{w_2} \\
u \cdot v &= (k \mathbf{v} + w_2) \cdot v \\
&= k ||v||^2 + w_2 \cdot v \\
&= k||v||^2 \\
k &= \frac{{u \cdot v}}{||v||^2} \\
\end{align}
$$

Sehingga:
 $$
\mathbf{w_1} = k \mathbf{v} = \frac{\mathbf{u} \cdot \mathbf{v}}{||\mathbf{v}||^2} \mathbf{v}
$$
dan
$$
\mathbf{w_2} = \mathbf{u} - \mathbf{w_1} 
$$

#  Vektor Normal
Vektor normal (normal/*n*) adalah sebuah vektor yang tegak lurus terhadap sebuah garis (di $R^2$) atau sebuah bidang (di $R^3$). 

Jika terdapat sebuah titik $P(x, y)$ dan $P_0(x_0, y_0)$ dan vektor $\vec{P_{0}P} = (x - x_0, y - y_0)$ memiliki vektor normal $\mathbf{n} = (a, b)$, sehingga $\mathbf{n}$ dan $\vec{P_0P}$ adalah orthogonal, maka memiliki persamaan:  $$ a(x - x_0) + b(y - y_0) = 0 $$ 
Sedangkan, untuk bidang yang melalui titik $P_0(x_0, y_0, z_0)$ dan memiliki vektor normal $\mathbf{n} = (a, b, c)$ memiliki persamaan: 
$$
a(x - x_0) + b(y - y_0) + c(z - z_0) = 0
$$

Persamaan garis $ax + by + c = 0$ memiliki normal $\mathbf{n} = (a, b)$. 
Persamaan bidang $ax + by + cz + d = 0$ memiliki normal $\mathbf{n} = (a, b, c)$.

# Jarak Titik dan Bidang

## Jarak antara Titik ke Garis
 Jarak dari titik $P_0(x_0, y_0)$ ke garis $ax + by + c = 0$ adalah (bidang $R^2$): 
 $$
 d = \frac{|ax_0 + by_0 + c|}{\sqrt{a^2 + b^2}}
 $$ 
## Jarak antara Titik ke Bidang
 Jarak dari titik $P_0(x_0, y_0, z_0)$ ke bidang $ax + by + cz + d = 0$ adalah (bidang $R^3$): 
 $$
 d = \frac{|ax_0 + by_0 + cz_0 + d|}{\sqrt{a^2 + b^2 + c^2}}
 $$
## Jarak antara Bidang Paralel
 Dihitung dengan cara memilih satu titik sembarang di salah satu bidang, lalu menghitung jarak dari titik tersebut ke bidang yang satunya. 
 >[!img-caption] ![[Pasted image 20251014181706.png]]

## Perpotongan Garis dengan Bidang
Kedudukan sebuah garis dengan bidang dapat memiliki tiga kemungkinan:
1. Garis memotong bidang di sebuah titik
2. Garis sejajar dengan bidang
3. Garis terletak pada bidang

Garis dengan Bidang Untuk menemukan titik potong antara garis (dalam bentuk parametrik) dan bidang: 
1. Substitusikan persamaan parametrik garis ($x(t), y(t), z(t)$) ke dalam persamaan bidang. 
2. Selesaikan persamaan tersebut untuk mendapatkan nilai parameter $t$. Dari jawaban yang didapatkan, kita dapat menentukan kedudukan garis dengan sebuah bidang.
	- Satu nilai $t$, berarti garis memotong bidang di satu titik. 
	- Tidak ada solusi $t$ (kontradiksi, misal $6=4$), berarti Garis sejajar dengan bidang.
	- Solusi tak hingga (identitas, misal $4=4$): Garis terletak pada bidang.


# Vektor dan Persamaan Parametrik
Misalkan $L$ adalah garis di $R^2$ dan $R^3$ yang mengandung titik $x_0$ dan paralel dengan vektor $\mathbf{v}$. Persamaan garis yang melalui $x_0$ dan paralel dengan $\mathbf{v}$ adalah
$$
x = x_0 + t\mathbf{v}
$$


Misalkan $W$ adalah bidang di  yang mengandung titik $x_0$ dan paralel dengan vektor $\mathbf{v_1}$ dan $\mathbf{v_2}$. Persamaan bidang yang melalui $x_0$ dan paralel dengan $\mathbf{v_1}$ dan $\mathbf{v_2}$ adalah
$$
x = x_0 + t_1\mathbf{v_1} + t_2 \mathbf{v_2}
$$

# Perkalian Silang
Jika $\mathbf{u} = (u_1, u_2, u_3)$ dan $\mathbf{v} = (v_1, v_2, v_3)$ adalah dua vektor di $R^3$, maka perkalian silang (*cross product*) antara $\mathbf{u}$ dan $\mathbf{v}$ adalah
$$
\begin{align*}
\mathbf{u} \times \mathbf{v} &= (u_2v_3 - u_3v_2, u_3v_1 - u_1v_3, u_1v_2 - u_2v_1) \\
\mathbf{u} \times \mathbf{v} &= (
\begin{vmatrix}
u_2 & u_3 \\
v_2 & v_3
\end{vmatrix}, - 
\begin{vmatrix}
u_1 & u_3 \\
v_1 & v_3
\end{vmatrix},
\begin{vmatrix}
u_1 & u_2 \\
v_1 & v_2
\end{vmatrix}
)
\end{align*}
$$

Perkalian silang menghasilkan vektor, sedangkan perkalian titik menghasilkan titik.

*Cross product* antara $\vec{u}$ dan $\vec{v}$  adalah vektor yang tegak lurus dengan $\vec{u}$ dan $\vec{v}$.

## Sifat-Sifat Perkalian Silang
Jika $\mathbf{u}$, $\mathbf{v}$, dan $\mathbf{w}$ adalah vektor di $R^3$ dan $k$ adalah skalar, maka:
$$
\begin{align}
\mathbf{u} \times \mathbf{v} &= -(\mathbf{v} \times \mathbf{u}) \\
\mathbf{u} \times (\mathbf{v} + \mathbf{w}) &= (\mathbf{u} \times \mathbf{v}) + (\mathbf{u} \times \mathbf{w}) \\
(\mathbf{u} + \mathbf{v}) \times \mathbf{w} &= (\mathbf{u} \times \mathbf{w}) + (\mathbf{v} \times \mathbf{w}) \\
k(\mathbf{u} \times \mathbf{v}) &= (k\mathbf{u}) \times \mathbf{v} = \mathbf{u} \times (k\mathbf{v}) \\
\mathbf{u} \times \mathbf{0} &= \mathbf{0} \times \mathbf{u} = \mathbf{0} \\
\mathbf{u} \times \mathbf{u} &= \mathbf{0} \\
\end{align}
$$

### Hubungan antara Perkalian Silang dan Perkalian Titik
Jika $\mathbf{u}$, $\mathbf{v}$, dan $\mathbf{w}$ adalah vektor di ruang $R^3$, maka:
$$
\begin{align}
\mathbf{u} \cdot (\mathbf{u} \times \mathbf{v}) &= 0 \\
\mathbf{v} \cdot (\mathbf{u} \times \mathbf{v}) &= 0 \\
\|\mathbf{u} \times \mathbf{v}\|^2 &= \|\mathbf{u}\|^2\|\mathbf{v}\|^2 - (\mathbf{u} \cdot \mathbf{v})^2\\ 
\mathbf{u} \times (\mathbf{v} \times \mathbf{w}) &= (\mathbf{u} \cdot \mathbf{w})\mathbf{v} - (\mathbf{u} \cdot \mathbf{v})\mathbf{w} \\
(\mathbf{u} \times \mathbf{v}) \times \mathbf{w} &= (\mathbf{u} \cdot \mathbf{w})\mathbf{v} - (\mathbf{v} \cdot \mathbf{w})\mathbf{u} \\
\end{align}
$$

Menurut kesamaan Lagrance:
$$
\begin{align*}
||u \times  v||^2 &= ||u||^2 \cdot ||v||^2 - (u \cdot v)^2 \\
&= |u||^2 \cdot ||v||^2 - (||u|| \cdot ||v|| \cdot \cos \theta)^2 \\
&= |u||^2 \cdot ||v||^2 - (||u||^@ \cdot ||v||^2 \cdot \cos^2 \theta) \\
&= |u||^2 \cdot ||v||^2 \cdot (1 - \cos^2 \theta) \\
&= |u||^2 \cdot ||v||^2 \cdot \sin^2 \theta
\end{align*}
$$
> $$
>||u \times v|| = ||u|| \cdot ||v|| \sin \theta
>$$

## Perkalian Silang Vektor Satuan Standard
Jika antara satuan standard di $R^3$ dilakukan operasi perkalian silang, maka akan didapat sebagai berikut:
$$
\begin{align*}
\mathbf{i} \times \mathbf{j} &= \mathbf{k} \\
\mathbf{j} \times \mathbf{i} &= -\mathbf{k} \\
\mathbf{j} \times \mathbf{k} &= \mathbf{i} \\
\mathbf{k} \times \mathbf{j} &= \mathbf{-i} \\
\mathbf{k} \times \mathbf{i} &= \mathbf{j} \\
\mathbf{i} \times \mathbf{k} &= \mathbf{-j} \\
\end{align*}
$$

Misalkan $\mathbf{u} = (u_1, u_2, u_3) = u_1i + u_2j + u_3k$ dan $\mathbf{v} = (v_1, v_2, v_3) = v_1i + v_2j + v_3k$. Untuk mengingat cara mencari *cross product* dari ini dapat digunakan matriks berikut
$$
\mathbf{u} \times \mathbf{v} = 
\begin{vmatrix}
\mathbf{i} & \mathbf{j} & \mathbf{k} \\
u_1 & u_2 & u_3 \\
v_1 & v_2 & v_3
\end{vmatrix}
=
\begin{vmatrix}
u_2 & u_3 \\
v_2 & v_3
\end{vmatrix}
\mathbf{i} - 
\begin{vmatrix}
u_1 & u_3 \\
v_1 & v_3
\end{vmatrix}
\mathbf{j} + 
\begin{vmatrix}
u_1 & u_2 \\
v_1 & v_2
\end{vmatrix}
\mathbf{k}
$$

# Aplikasi Geometri Perkalian Silang

Luas Jajar Genjang (Parallelogram). Magnitudo (panjang) dari vektor hasil perkalian silang, $||\mathbf{u} \times \mathbf{v}||$, secara geometris setara dengan **luas jajar genjang** yang dibentuk oleh vektor **u** dan **v**. 
$$
\text{Luas} = ||\mathbf{u} \times \mathbf{v}||
$$

Luas Segitiga Luas segitiga yang dibentuk oleh tiga titik $P_1, P_2, P_3$ adalah setengah dari luas jajar genjang yang dibentuk oleh vektor $\vec{P_1P_2}$ dan $\vec{P_1P_3}$. 
$$
\text{Luas Segitiga} = \frac{1}{2} ||\vec{P_1P_2} \times \vec{P_1P_3}||
$$

Volume Balok Miring (Parallelepiped) Volume dari balok miring yang dibentuk oleh tiga vektor **u**, **v**, dan **w** dapat dihitung menggunakan *scalar triple product*, yang setara dengan nilai absolut dari determinan matriks 3x3 yang dibentuk oleh ketiga vektor tersebut. 
$$
\text{Volume} = |\mathbf{u} \cdot (\mathbf{v} \times \mathbf{w})| = \left| \det \begin{pmatrix} u_1 & u_2 & u_3 \\ v_1 & v_2 & v_3 \\ w_1 & w_2 & w_3 \end{pmatrix} \right|
$$