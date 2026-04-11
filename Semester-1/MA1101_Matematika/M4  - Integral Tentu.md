# Referensi
1. Buku Calculus Early Transcendentals, Dale Varberg Edwin J. Purcell, Steve E. Rigdon
2. LKM Bab 4 Integral Tentu Pak Eric
3. [https://youtube.com/playlist?list=PLjs4VVzVn2XtmNmzEsQuJEZ6S_l-Zvcko&si=deOXWN3ANrxn0SS9](https://youtube.com/playlist?list=PLjs4VVzVn2XtmNmzEsQuJEZ6S_l-Zvcko&si=deOXWN3ANrxn0SS9)

# Pendahuluan

> [!img-caption] ![[image 12.png]]
> Gambar 1

Kunci dari materi integral tentu ini adalah **aproksimasi**. Pada **Gambar 1**, kita dapat melihat bahwa untuk menghampiri luas dari lingkaran, dapat digunakan polinom beraturan $T_n$. DIlihat juga bahwa semakin banyak segi dari polinom tersebut, maka semakin akurat pula luas lingkaran yang dihitung. Sehingga, secara intuisi kita bisa mengatakan bahwa:

$$
\text{A} = \lim_{n \to \infty}\text{A}(T_n)
$$

Konsep menghampiri inilah yang akan kita gunakan untuk menghitung luasan daerah yang nantinya akan membawakan kita ke konsep integral tentu

# Notasi Sigma

Untuk penulisan penjumlahan yang sangat panjang, kita dapat menuliskannya dalam notasi sigma, contoh

$$
\begin{aligned}  
1 + 2 + 3 + \dots+100 &= \sum_{i=1}^{100} i  
\\  
\frac11 +\frac 12+\frac13+\dots+\frac1n &=\sum_{i=1}^n \frac1i  
\\  
\underbrace{2+2+2+\dots+2}_{n \textsf{ kali}} = \sum_{i=1}^n 2  
\end{aligned}
$$

## Sifat-Sifat Notasi Sigma
1. $\displaystyle \sum_{i=1}^nc=cn$
2. $\displaystyle \sum_{i=1}^nca_i = c \sum_{i=1}^na_i$
3. $\displaystyle \sum_{i=1}^n (a_i \pm b_i) = \sum_{i=1}^n a_i \pm \sum_{i=1}^n b_i$
4. $\displaystyle \sum_{i=1}^n i = \frac{n(n+1)}{2}$
5. $\displaystyle \sum_{i=1}^n i^2 = \frac{n(n+1)(2n+1}{6}$
6. $\displaystyle \sum_{i=1}^n i^3 = \left(\frac{n(n+1)}{2}\right)^2$
7. $\displaystyle \sum_{i=1}^n i^4 = \frac{n(n+1)(2n+1)(3n^2+3n-1)}{30}$

# Pengenalan Luas Daerah
Berdasarkan konsep di bab subbab **Pendahuluan**. Maka, secara rinci untuk menghitung luas daerah di bawah kurva:

1. Partisi selang $[a, b]$ menjadi $n$ buah subinterval sama panjang
2. Cari luas satu persegi panjang sembarang.
3. Menjumlahkan luas semua persegi panjang.
4. Mencari limitnya untuk $n \to \infty$.

  

Misal untuk menghitung luas daerah di bawah kurva $y = x^2$ pada $(0,2)$

> [!img-caption] ![[image 1 5.png|image 1 5.png]]
> Gambar 2

1. Partisi selang $[0,2]$ menjadi $n$ subinterval sama panjang, $\Delta x = \frac{2-0}{n}=\frac{2}{n}$.
> [!img-caption] ![[image 2 4.png|image 2 4.png]]
> Gambar 3

$$
\begin{aligned}  
x_0 &= 0  
\\  
x_1 = \Delta x &= \frac2n  
\\  
x_2 = 2\cdot\Delta x &= \frac4n  
\\  
x_{i-1} = (i-1)\cdot \Delta x &= \frac{2(i-1)}{n}  
\\  
x_i = i\cdot\Delta x &= \frac{2i}{n}  
\\  
x_n = n \cdot \Delta x &= 2  
\end{aligned}
$$

2. Cari luas daerah persegi panjang sembarang.
> [!img-caption] ![[image 3 4.png|image 3 4.png]]
> Gambar 4

$$
L_i=f(x_{i-1})\Delta x = x_{i-1}^2 \cdot \frac{2}n = \left(\frac{2(i-1)}{n}\right)^2\cdot\frac{2}{n} = \frac{8}{n^3}(i^2-2i+1)
$$

3. Jumlahkan luas semua persegi panjang.

$$
\sum_{i=1}^n L_i = \frac{8}{n^3}\sum_{i=1}^n (i^2-2i+1) = \frac{8}{n^3}\left( \frac{n(n+1)(2n+1)}{6} - 2 \frac{n(n+1)}{2}+n\right)
$$

4. Mencari limitnya untuk $n \to \infty$.

$$
\lim_{n \to \infty} \frac{8}{n^3}\left( \frac{n(n+1)(2n+1)}{6} - 2 \frac{n(n+1)}{2}+n\right) = \frac{8}{3}
$$

Sehingga, didapat luas dari $y = x^2$ di interval $(0,2)$ adalah $\frac83$ satuan luas.

Dapat dilihat bahwa kita mencari luas menggunakan persegi panjang dalam, kita juga dapat menggunakan metode serupa dengan menggunakan persegi panjang luas, seperti **Gambar 5**.

> [!img-caption] ![[image 4 4.png|image 4 4.png]]
>  Gambar 5

5. Partisi selang $[0,2]$ menjadi $n$ subinterval sama panjang, $\Delta x = \frac{2-0}{n}=\frac{2}{n}$.

$$
\begin{aligned}  
x_0 &= 0  
\\  
x_1 = \Delta x &= \frac2n  
\\  
x_i = i\cdot\Delta x &= \frac{2i}{n}  
\\  
x_n = n \cdot \Delta x &= 2  
\end{aligned}
$$

6. Cari luas daerah persegi panjang sembarang.    
$$
L_i=f(x_{i})\Delta x = x_{i}^2 \cdot \frac{2}n = \left( \frac{2i}{n}\right)^2 \cdot \frac{2}{n} = \frac{8}{n^3}i^2
$$

7. Jumlahkan luas semua persegi panjang.

$$
\sum_{i=1}^n L_i = \frac{8}{n^3}\sum_{i=1}^n i^2 = \frac{8}{n^3}\left( \frac{n(n+1)(2n+1)}{6} \right)
$$

8. Mencari limitnya untuk $n \to \infty$.

$$
\lim_{n \to \infty} \frac{8}{n^3}\left( \frac{n(n+1)(2n+1)}{6} \right) = \frac{8}{3}
$$

Sehingga, sama seperti menggunakan persegi panjang dalam, didapat luas dari $y = x^2$ di interval $(0,2)$ adalah $\frac83$ satuan luas.

Dapat disimpulkan bahwa dari kedua metode ini, akan menghasilkan hasil yang sama

# Jumlah Riemann

Partisi $P$ dalam interval $[a,b]$ menjadi $n$ buah subinterval (tidak harus sama panjang) dengan,

$$
a = x_0 <x_1<\dots<x_n=n,
$$

seperti pada **Gambar 6**.

> [!img-caption] ![[image 5 4.png|image 5 4.png]]
> Gambar 6

Seperti pada **Gambar 6**, $\Delta x_i = (x_i-x_{i-1})$. Untuk setiap subinterval $[x_{i-1},x_i]$, pilih satu wakil $\bar x_i \in [x_{i-1}, x_i]$ sebagai panjang dari persegi panjangnya. Titik $\bar x_i$ ini akan disebut titik sampel dari subinterval ke-$i$. Lalu, jumlahan dari hampiran luas daerah yang kita cari ini disebut dengan **Jumlah Riemann**, yaitu

$$
\sum_{i=1}^n f(\bar x_i)\Delta x_i
$$

Selanjutnya, untuk subinterval ini, dipilih $|P|$, yaitu **norma partisi** dari $P$ yang menyatakan subinterval paling panjang dalam partisi $P$. Lalu, ketika $\|P\| \to 0$ maka jumlah hampiran luas daerah ini akan menjadi akurat (seperti pada subbab sebelumnya). Hal inilah yang akan menjadi definisi dari **Integral Tentu**.

> [!definition] Integral Tentu 
> Misalkan $f$ terdefinisi pada interval tutup $[a,b]$. Jika,
> 
> $$\lim_{\|P\| \to 0}\sum_{i=1}^n f(\bar x_i) \Delta x$$
> 
> ada, maka $f$ terintegralkan di $[a,b]$. Serta, $\displaystyle \int_a^b f(x) \ \mathrm{d} x$ dikatakan sebagai integral tentu (integral Riemann) dari fungsi $f$ dari $a$ hingga $b$ diberikan oleh
> 
> $$\lim_{\|P\|\to 0} \sum_{i=1}^n f(\bar x_i) \Delta x_i = \int_a^b f(x) \ \mathrm d x$$

Tentunya, ketika kita melimitkan $\|P\| \to 0$, jumlah dari subintervalnya juga akan menuju 0 ($n \to \infty$). Dengan $a$ disebut sebagai batas bawah dan $b$ disebut sebagai batas bawah. Pada definisinya secara implisit dinyatakan bahwa $a <b$. Namun, kita dapat menghilangkan restriksi tersebut dengan:

$$  
\begin{align*}  
\int_a^a f(x) \ \mathrm d x &= 0  
\\  
\int_a^b f(x) \ \mathrm d x &= -\int_b^a f(x) \ \mathrm d x, \quad a>b  
\end{align*}
$$

# Teorema Keintegralan

 Jika $f$ kontinu pada interval $[a,b]$, maka $f$ terintegralkan pada $[a,b]$. Selain itu, fungsi terbatas yang terdefinisi pada interval tutup $[a,b]$ yang tidak kontinu di hingga buah titik, maka fungsi tersebut juga terintegralkan pada $[a,b]$.

### Sifat Penambahan Integral

> [!img-caption] ![[image 6 4.png|image 6 4.png]]
> Gambar 7

$$
A(R) = A(R_1 \cup R_2) = A(R_1) + A(R_2)
$$

sehingga,

$$
\int_a^c f(x) \mathrm d x = \int_a^b f(x) \mathrm d x + \int_b^c f(x) \mathrm d x
$$

### Teorema Dasar Kalkulus I

Misalkan $f$ kontinu pada interval tutup $[a,b]$ dan $x_0 \in (a,b)$. Akibatnya,

$$\frac{\mathrm d}{\mathrm d x }\int_a^x f(t) = f(x)$$

### Kelinearan Integral

1. $\displaystyle \int_a^b kf(x) \ dx = k \int_a^b f(x) \ dx$
2. $\displaystyle \int_a^b [f(x)-g(x)] \ dx = \int_a^b f(x) \ dx - \int_a^b g(x) \ dx$