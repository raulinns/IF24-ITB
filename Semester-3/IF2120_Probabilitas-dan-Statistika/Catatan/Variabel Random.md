> **Definisi**: Variabel random adalah sebuah fungsi $X:S \to R$ yang memetakan setiap titik sampel $s \in S$dalam ruang sampel $S$ ke sebuah bilangan real $X(s)$.

Ruang sampel diskrit adalah ruang sampel yang berisi sejumlah hingga kemungkinan hasil atau barisan tak hingga sebanyak elemen-elemen bilangan bulat. Contoh: Himpunan bilangan bulat.

Ruang Sampel Kontinu adalah ruang sampel berisi sejumlah tak hingga kemungkinan hasil , sama dengan sejumlah titik pada sebuah segmen garis. Contoh: Himpunan bilangan real.  

# Distribusi Peluang Diskrit
### Fungsi Massa Peluang (*Probability Mass Function*)
Kumpulan pasangan terurut $(x, f(x))$ disebut fungsi peluang/fungsi massa peluang dari variabel random diskrit $X$ jika untuk setiap nilai $x$ dipenuhi:
1.  $f(x) \ge 0$ 

2.  $\sum_{x} f(x) = 1$ 

3.  $P(X=x) = f(x)$ 

###  Fungsi Distribusi Kumulatif (*Cumulative Distribution Function*)
Distribusi kumulatif $F(x)$ dari variabel random diskrit $X$ didefinisikan sebagai peluang bahwa X akan mengambil nilai yang lebih kecil atau sama dengan $x$.
$$ F(x) = P(X \le x) = \sum_{t \le x} f(t), \quad \text{untuk } -\infty < x < \infty $$

Grafik dari fungsi distribusi kumulatif untuk variabel diskrit akan berbentuk seperti tangga.

# Distribusi Peluang Kontinu
Distribusi Peluang kontinu adalah peluang yang bernilai nol pada suatu titik. Oleh karena itu, distribusi peluang tidak dapat dituliskan dalam bentuk tabel. 

Jika $X$ kontinu, maka:
$$
P(a < X \le b) = P(a < X <b) + P(X = b) = P(a < X < b)
$$
dan dapat dihitung sebagai berikut:
$$
	P(a < X < b) = \int_a^b f(x) \ dx
$$
  
### Fungsi Kepadatan Peluang (*Probability Density Function* )
Fungsi $f(x)$ adalah fungsi densitas peluang untuk variabel kontinu X jika memenuhi syarat:

1.  $f(x) \ge 0$ untuk semua $x$ 

2.  $\int_{-\infty}^{\infty} f(x) dx = 1$ 

3.  $P(a < X < b) = \int_{a}^{b} f(x) dx$ 

![[Pasted image 20250929045019.png]]

### Fungsi Distribusi Kumulatif (*Cumulative Distribution Function*)
Distribusi kumulatif $F(x)$ dari variabel random kumulatif $X$ dengan distribusi peluang adalah:
 $$
P(a < X < b) = F(b) - F(a)
$$
dan

$$
f(x) = \frac{d}{dx} F(X)
$$

# Distribusi Peluang Gabungan (Joint)
Jika $X$ dan $Y$ adalah dua variabel random diskrit, maka distribusi peluang untuk kejadian simultan dapat direpresentasikan dengan fungsi $f(x, y)$ untuk setiap pasangan $(x, y)$.

Fungsi ini disebut dengan distribusi peluang gabungan dari variabel random $X$ dan $Y$. 

### Kasus Diskrit
 Fungsi $f(x, y)$ adalah distribusi peluang gabungan atau fungsi masa peluang dari variabel random diskrit $X$ dan $Y$$ jika:
1. $f(x,y) \ge 0$ 

2. $\sum_{x}\sum_{y} f(x,y) = 1$

3. $P (X = x, Y = y) = f(x,y)$ 

4. **Tambahan**: Untuk daerah sembarang A dalam bidang $xy$, $P[(x,y) \in A] = \sum_A \sum f(x, y)$

### Kasus Kontinu
Fungsi $f(x, y)$ adalah fungsi densitas gabungan dari variabel random kontinu $X$ dan $Y$ jika:

1.  $f(x,y) \ge 0$  untuk semua $(x,y)$

2.  $\int_{-\infty}^{\infty}\int_{-\infty}^{\infty} f(x,y) \ dx \ dy = 1$

3. $P[(X < Y) \in A] = \int \int_A f(x,y) \ dx \ dy$ untuk sembarang $A$ dalam bidang $xy$

# Distribusi Marginal
Distribusi marginal adalah distribusi peluang dari satu variabel saja, yang didapat dari distribusi gabungan.
-   **Diskrit**: $g(x) = \sum_{y} f(x,y)$ dan $h(y) = \sum_{x} f(x,y)$.

-   **Kontinu**: $g(x) = \int_{-\infty}^{\infty} f(x,y) \ dy$ dan $h(y) = \int_{-\infty}^{\infty} f(x,y) \ dx$.

# Distribusi Bersyarat
Misalkan $X$ dan $Y$ adalah dua variabel random diskrit atau kontinu. Distribusi bersyarat dari variabel random $Y$, diberikan $X = x$ adalah 
$$
f(y|x) = \frac{f(x,y)}{g(x)}, \text{ dengan } g(x)>0
$$

Serta, distribusi bersyarat dari variabel random $X$, diberikan $Y = y$ adalah
$$
f(x|y) = \frac{f(x,y)}{h(y)}, \text{ dengan } h(y)>0
$$

# Bebas Statistik (Statistically Independent)
Misal $X$ dan $Y$  merupakan dua variable random (diskrit atau kontinu), dengan $f(x,y)$ merupakan distribusi peluang gabungan, $g(x)$ dan $h(y)$ merupakan distribusi marginal. Variabel random X, Y disebut bebas statistik jika
$$
f(x,y) = g(x) \cdot h(y)
$$

Misal $X_1, X_2, \dots , X_n$ adalah $n$ variabel acak, diskrit or kontinu, dengan distribusi peluang gabungan $f(x_1, x_2, \dots , x_n)$ dan distribusi marginal $f_1(x_1), f_2(x_2), \dots , f_n(x_n)$. Variabel acak $X_1, X_2, \dots , X_n$ bersifat statistically independent jika: 
$$
f(x_1, x_2, \dots , x_n) = f_1(x_1)f_2(x_2) \dots f_n(x_n)
$$
untuk semua $(x_1, x_2, \dots, x_n)$ dalam batasan nilainya.3