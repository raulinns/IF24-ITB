#Fisika 
# Referensi
- Buku Halliday
- PPT Pusat Massa dan Momentum Linear Pak Arief

# Pusat Massa

Pusat massa dari sistem partikel adalah representasi benda dari sebuah sistem partikel atau benda tegar. Titik pusat massa ini bergerak seolah-olah semua massa sistem terkonsentrasi di sana dan semua gaya eksternal bekerja di sana.

>[!img-caption] ![[image 14.png|image 14.png]]
> Gambar 1

Posisi pusat massa dari sistem $n$-partikel dapat ditentukan dari


$$  
x_{pm} = \frac{m_1x_1+m_2x_2+\dots+m_nx_n}{M }=\frac{1}{M}\sum^n_{i=1}m_ix_i
$$

dengan $M$ adalah total massa ($m_1x_1 + m_2x_2+\dots +m_nx_n$).

Dari rumus tersebut, dapat ditentukan posisi pusat massa pada benda tiga dimensi.

$$
\begin{align*}
x_{pm} &= \frac{1}{M}\sum_{i=1}^nm_ix_i \\
y_{pm} &= \frac{1}{M}\sum_{i=1}^nm_iy_i \\
z_{pm}&=\frac{1}{M}\sum_{i=1}^nm_iz_i \\
\end{align*}
$$

Posisi partikel juga dinotasikan sebagai $\vec r_i = x_i \hat{i} + y_i \hat{j}+z_i \hat{k}$. Dari notasi tersebut, posisi pusat massa dinotasikan sebagai.

$$
\vec r_{pm} = x_{pm} \hat{i} + y_{pm} \hat{j}+z_{pm} \hat{k}
$$

Sehingga diperoleh,

$$
\vec{r}_{pm} = \frac{1}{M} \sum_{i=1}^n m_i \vec{r}_i \tag*{satuan: (dalam notasi vektor)}
$$

Namun, dalam dunia nyata, tentunya akan ada sangat banyak (mendekati tak hingga) partikel (atom) pada suatu benda. Hal ini dapat kita perlakukan sebagai sebuah distribusi materi yang kontinu. Partikel yang ada pada sebuah benda pun bisa dianggap sangat kecil sehingga tiap partikelnya memiliki elemen massa $\Delta m$. Sehingga, karena distribusi materinya kontinu (syarat integral) dan partikel yang ada mendekati tak hingga. Maka, rumus di atas dapat dituliskan sebagai.

$$
x_{pm} = \frac{1}{M}\lim_{n\to\infty}\sum_{i=1}^nx \ \Delta m \iff x_{pm} = \frac{1}{M} \int x \ dm
$$

Maka, dengan cara yang sama dapat ditentukan

$$
\begin{align*}
x_{pm}&=\frac{1}{M}\int x \ dm \\
y_{pm}&=\frac{1}{M}\int y \ dm \\
z_{pm}&=\frac{1}{M}\int z \ dm \\
\end{align*}
$$

Tentunya, rumus integral ini akan jauh lebih mudah jika benda yang dihitung adalah benda dengan densitas ($\rho = \frac{m}{V}$) yang seragam.

$$\rho = \frac{m}{V} \implies \rho = \frac{\Delta m}{\Delta V}=\frac{M}V \implies \Delta m = \frac{M}{V} \cdot \Delta V \\ \\ x_{pm} = \frac{1}{M}\int x \ dm \implies x_{pm} = \frac{1}{M}\int x \ \frac{M}{V} \ dv \implies x_{pm} = \frac{1}{V} \int x \ dV$$

Maka, dengan cara yang sama dapat ditentukan

$$
\begin{align*}
x_{pm}&=\frac{1}{V}\int x \ dV \\
y_{pm}&=\frac{1}{V}\int y \ dV \\
z_{pm}&=\frac{1}{V}\int z \ dV \\
\end{align*}
$$

Hal ini juga berlaku untuk massa per satuan luas ($\sigma = \frac{M}{A}$) dan massa per satuan panjang ($\lambda = \frac{M}{L}$)

Lalu, dengan melakukan manipulasi aljabar dan menurunkannya terhadap waktu, maka dapat diperoleh.

$$\boxed{r_{pm}=\frac{m_1 \vec r_1 +m_2 \vec r_2 +\dots+m_n \vec r_n}{M}}$$

$$\boxed{v_{pm}=\frac{m_1 \vec v_1 +m_2 \vec v_2 +\dots+m_n \vec v_n}{M}}$$

$$\boxed{a_{pm}=\frac{m_1 \vec a_1 +m_2 \vec a_2 +\dots+m_n \vec a_n}{M}}$$

Dari rumus $a_{pm}$ pula dapat diperoleh,

$$a_{pm}=\frac{F_1+F_2+\dots+F_n}{M} \implies \Sigma \vec F = M\vec a_{pm}$$

dan berlaku $\Sigma F_x = Ma_{pm, x}$, $\Sigma F_y = Ma_{pm, y}$, dan $\Sigma F_z = Ma_{pm, z}$.

Catatan: Gaya internal, seperti ledakan tidak akan mengubah lintasan dari pusat massa.

# Momentum Linear

Momentum didefinisikan sebagai sebuah karakteristik dari benda yang menentukan seberapa sulit untuk menghentikan sebuah objek yang bergerak. Momentum linear disebut untuk membedakannya dengan momentum sudut atau momentum angular.

$$
\vec p = m\vec v \tag{satuan: kg ⋅ m/s atau N ⋅ s}
$$

Momentum dari sebuah benda dapat ditentukan dari momentum sistem partikelnya.

$$
\begin{align*}
v_{pm} =\frac{m_1 \vec v_1 +m_2 \vec v_2 +\dots+m_n \vec v_n}{M} &\implies Mv_{pm} = m_1 \vec v_1 +m_2 \vec v_2 +\dots+m_n
\vec v_n \\ \implies \vec P = \vec p_1 + \vec p_2 + \dots+\vec p_n &\implies \vec P = Mv_{pm}
\end{align*}
$$

dengan $M$ adalah massa total benda.

$$\Sigma F = ma = m\frac{dv}{dt}=\frac{d}{dt}(mv) = \implies \Sigma F=\frac{d\vec p}{dt}$$
  
Sehingga, dapat dikatakan bahwa momentum suatu benda dapat berubah dengan memberikan gaya eksternal.

# Impuls

Berdasarkan rumus di atas dan menganggap $\Sigma F$ sebagai fungsi gaya terhadap waktu $F(t)$, dapat diperoleh,

$$
\begin{aligned}  
\Sigma F &= \frac{d\vec p}{dt} \\ \\d\vec p &= F(t) \ dt  
\end{aligned}
$$

Dari sini, kita dapat mengintegralkan persamaan tersebut dari waktu sebelum gaya diberikan (tumbukan) $t_i$ sampai waktu setelah gaya diberikan $t_f$.

$$
\begin{aligned}  
\int_{t_i}^{t_f} d\vec p &= \int_{t_i}^{t_f} F(t) dt  
\\ \\  
p_f-p_i &= \int_{t_i}^{t_f} F(t) dt  
\\ \\  
\Delta p &= \int_{t_i}^{t_f} F(t) dt  
\end{aligned}
$$

Perubahan dari momentum $\Delta p$ inilah yang akan dinamakan impuls, yaitu perubahan momentum akibat gaya yang bekerja selama interval waktu tertentu

$$
\vec J = \Delta p =\int_{t_i}^{t_f}F(t) dt \tag{satuan: N ⋅ s}
$$

Rumus ini dapat diartikan luas di bawah kurva $F(t)$-$t$ dari $t_i$ sampai $t_f$, seperti **Gambar 2.**

>[!img-caption] ![[image 1 7.png|image 1 7.png]]

>Gambar 2

>[!img-caption] ![[image 2 6.png|image 2 6.png]]
>Gambar 3

Namun, berdasarkan Teori Nilai Rata-Rata, dapat diperoleh **Gambar 3**. Sehingga, dapat diperoleh rumus berikut.

$$
\vec J =F_{avg}\Delta t
$$

## Kekekalan Momentum Linear

Jika tidak ada gaya eksternal ($\Sigma F=0 \implies \vec J = 0$) yang diberikan pada kedua sistem partikel (terisolasi) dan kedua sistem tidak berkurang atau bertambah partikel/massanya (tertutup), maka berlaku kekekalan momentum linear.

$$
\begin{aligned}  
\vec P_i &= \vec P_f  
\\ \vec p_{1i} + \vec p_{2i} &= \vec p_{1f} + \vec p_{2f}  
\\ m\vec v_{1i} + m\vec v_{2i} &= m\vec v_{1f} + m\vec v_{2f}  
\end{aligned}
$$

# Tumbukan

Dalam sebuah kejadian tumbukan, jika energi kinetik total sebelum tumbukan dan setelah tumbukan sama, maka berlaku konservasi energi dan tumbukan disebut **Tumbukan Lenting Sempurna** (_Elastic Colission_). Namun, dalam kejadian dunia nyata seringkali tumbukan lenting sempurna ini tidak terjadi, karena saat kedua benda bertumbuk, energi berubah menjadi energi lainnya, seperti energi panas atau energi suara. Pada kondisi ini, tumbukan disebut _Inelastic Colissions_. Tumbukan ini dapat berupa inelastic colission (**Tumbukan Lenting Sebagian**) atau completely inelastic collision (**Tumbukan Tidak Lenting**).

## Tumbukan Lenting Sebagian

Dalam kondisi ini, kedua benda bergerak pada arah yang sama, tetapi benda pertama memiliki kecepatan yang lebih tinggi sehingga menumbuk benda 2.

>[!img-caption] ![[image 3 6.png|image 3 6.png]]
>Gambar 4

Dalam hal ini, karena kedua sistem tertutup dan terisolasi, maka berlaku hukum kekekalan momentum linear, sehingga

$$
\begin{aligned}  
\vec P_i &= \vec P_f  
\\  
\vec p_{1i} + \vec p_{2i} &= \vec p_{2i} + \vec p_{2f}  
\\ m_1\vec v_{1i} + m_2\vec v_{2i} &= m_1\vec v_{1f} + m_2\vec v_{2f}  
\end{aligned}
$$

## Tumbukan Tidak Lenting

Dalam kondisi ini, benda 1 bergerak menuju dan menumbuk benda 2 selagi benda 2 diam ($v_{2i} = 0$). Setelah tumbukan, benda 1 dan benda 2 bergerak bersama.

>[!img-caption] ![[image 4 6.png|image 4 6.png]]
> Gambar 5

Berlaku hukum kekekalan momentum linear, sehingga

$$
\begin{aligned}  
m\vec v_{1i} + m\vec v_{2i} &= m\vec v_{1f} + m\vec v_{2f}  
\\  
m_1\vec v_{1i} + 0&= (m_1 + m_2)V  
\end{aligned}
$$

Perhatikan bahwa $V = \frac{m_1}{m_1+m_2}\vec v_{1i}$, sehingga $V$ tidak mungkin lebih besar dari $\vec v_{1i}$ karena rasionya.

## Tumbukan Lenting Sempurna

### Kasus Benda 2 Diam

Dalam kondisi ini, benda 1 bergerak menuju dan menumbuk benda 2 selagi benda 2 diam ($v_{2i} = 0$). Setelah tumbukan, benda 1 dan benda 2 bergerak ke arah yang sama.    
>[!img-caption] ![[image 5 6.png|image 5 6.png]]
> Gambar 6

Berlaku hukum kekekalan momentum linear dan kekekalan energi sehingga

$$
\begin{aligned}  
m_1\vec v_{1i} + 0 &= m_1 \vec v_{1f} + m_2 \vec v_{2f}  
\\  
\frac{1}{2}m_1v_{1i}^2 + 0 &= \frac{1}{2}m_1v_{1f}^2 + \frac{1}{2}m_1v_{2f}^2  
\end{aligned}
$$

Untuk mendapatkan rumus $v_{1f}$ dan $v_{2f}$ dapat dilakukan dengan manipulasi aljabar dan membagi persamaan 1 dan persamaan 2. Setelah itu, dapat pula dikaji bagaimana jika $m_1 =m_2$, $m_2 \gg m_1$, dan $m_1 \gg m_2$.

### Kasus Kedua Benda Bergerak Ke Arah Satu Sama Lain

>[!img-caption]  ![[image 6 6.png|image 6 6.png]]
> Gambar 7

Berlaku hukum kekekalan momentum linear dan kekekalan energi sehingga

$$
\begin{aligned}  
m_1\vec v_{1i} + m_2\vec v_{2i} &= m_1 \vec v_{1f} + m_2 \vec v_{2f}\\  
\frac{1}{2}m_1v_{1i}^2 + \frac{1}{2}m_2v_{2i}^2 &= \frac{1}{2}m_1v_{1f}^2 + \frac{1}{2}m_1v_{2f}^2  
\end{aligned}
$$

### Tumbukan Dua Dimensi

>[!img-caption]  ![[image 7 4.png|image 7 4.png]]
> Gambar 8

Dal~am tumbukan, berlaku kekekalan momentum linear sehingga,

$$
\vec P_{1i}+ \vec P_{2i} = \vec P_{1f}+ \vec P_{2f}
$$

dan untuk tumbungan lenting sempurna berlaku kekekalan energi kinetik sehingga,

$$
K_{1i}+ K_{2i} = K_{1f}+ K_{2f}
$$