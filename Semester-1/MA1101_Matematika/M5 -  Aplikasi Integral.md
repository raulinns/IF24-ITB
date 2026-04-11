# Referensi
- Buku Purcell
- LKM Bab 5 Aplikasi Integral Pak Eric
- [https://youtube.com/playlist?list=PLjs4VVzVn2XtmNmzEsQuJEZ6S_l-Zvcko&si=deOXWN3ANrxn0SS9](https://youtube.com/playlist?list=PLjs4VVzVn2XtmNmzEsQuJEZ6S_l-Zvcko&si=deOXWN3ANrxn0SS9)

# Luas Daerah di Antara Dua Kurva

> [!img-caption] ![[image 23.png|image 23.png]]
> Gambar 4.2

Langkah-langkah untuk mencari luas daerah di antara dua kurva:

1. Partisi interval $[a, \ b]$ menjadi $n$ buah subinterval yang sama panjang yaitu $\Delta x = \frac{b-a}{n}$

$$
\begin {align*}
x_o &= a
x_1 &= a + \Delta x      
x_i &= a + i\ \Delta x        
x_n &= b
\end{align*}
$$      

2. Tentukan elemen luas ke-$i$: _(persegi panjang berwarna merah)_
$$
\Delta L_i=[f(\bar x_i) -g(\bar x_i)]\ \Delta x \text{,}
$$
dengan $\bar x_i$ adalah titik sampel di mana $\bar x_i \isin[x_{i-1},\ x_i]$. 

Pastikan penggunaan elemen luas mewakilkan semua potongan/partisi yang ada. Misal, pastikan pada seluruh wakil elemen yang dibuat, $f(x)$ selalu berada di atas $g(x)$. Jika tidak, maka perhitungan harus dipisah berdasarkan batas tersebut.

3. Aproksimasi nilai luasnya
$$
L \approx \sum_{i=1}^n [f(x) -g(x))]\ \Delta x
$$

4. Luas sesungguhnya adalah limit jumlah Riemann aproksimasi nilai luasnya
$$
L = \lim\limits_{n\to \infty} \sum_{i=1}^n [f(\bar x_i] - g(\bar x_i)] \Delta x = \int_a^b [f(x) -g(x)]\ dx\text{,}
$$

dengan $y = f(x)$ fungsi di atas $y = g(x)$

**Catatan**: untuk mencari luas di bawah grafik fungsi (antara fungsi dan sumbu x), maka dicari luas antara $y = f(x)$ dan $y = 0$, sehingga menghasilkan $\int_a^b f(x) - 0\ dx$

# Volume Benda
   
Ingat bahwa volume dapat ditentukan dari $V = A \cdot h$ dengan $A$ adalah luas alas dan $h$ adalah tinggi alas untuk tiap benda dengan alas dan tutup yang berbentuk sama. Maka secara matematis–sama seperti menghitung luas–untuk menghitung volume kita dapat mencari aproksimasi elemen volume ke-$i$ menggunakan $\Delta V_i \approx A(\bar x_i)\ \Delta x$ dan menghitung limit jumlah Riemann-nya.

> [!img-caption] ![[image 1 12.png|image 1 12.png]]
> Gambar 4.3

> [!img-caption] ![[image 2 10.png|image 2 10.png]]
> Gambar 4.4

Maka, langkah-langkah untuk menghitung volume suatu benda adalah:

1. Partisi interval $[a, \ b]$ menjadi $n$ buah subinterval yang sama panjang yaitu $\Delta x = \frac{b-a}{n} = x_i -x_{i-1}$, sehingga potongan benda memiliki bentuk alas dan tutup yang hampiran volumenya sama.

2. Aproksimasi elemen volume ke-$i$: _(prisma berwarna abu-abu)_

$$
\Delta V_i = L(\bar x_i) \ \Delta x \text{ atau } \Delta V \approx L(x) \ \Delta x \text{,}
$$

dengan $\bar x_i$ adalah titik sampel di mana $\bar x_i \isin [x_{i-1},\ x_i]$ dan $L(\bar x_i)$ adalah luas alas.

3. Aproksimasi nilai volumenya

$$
V \approx \sum_{i=1}^n \Delta V_i = \sum_{i=1}^n L(\bar x_i) \ \Delta x
$$

4. Volume sesungguhnya adalah limit jumlah Riemann aproksimasi nilai volumenya

$$
V = \lim_{n \to \infty} \sum_{i=1}^n L(\bar x_i) \ \Delta x = \int_a^b L(\bar x_i) \ dx
$$

Dalam hal ini $V$ dapat berupa silinder, silinder berongga, prisma segitiga sama kaki, prisma setengah lingkaran, prisma persegi, dan lainnya. Selanjutnya, $L(\bar x_i)$ ini dapat dihitung sesuai dengan luas alasnya.

# Volume Benda Putar
Ketika suatu wilayah bidang (_plane region_) yang berada pada suatu bidang kartesian dua dimensi diputar terhadap suatu sumbu (_axis_), pemutaran ini akan membentuk sebuah benda yang dinamakan **Benda Putar**.

Dalam menghitung volume benda putar, kita memiliki berbagai metode. Metode-metode ini memiliki perbedaan dalam bentuk apa kita akan meninjau **elemen volumenya**. Jadi metode-metode ini bukan tentang bentuk dari benda tegarnya, namun bentuk dari **tinjauan elemen volumenya**.

## Metode Cakram (_disks_)

> [!img-caption] ![[image 3 10.png|image 3 10.png]]
> Gambar 4.5

Dalam metode ini, luas dari penampangnya adalah luas lingkaran. Maka, 
$$\text{Luas} = \pi r^2 \implies L(x)=\pi f(x)^2 \implies \Delta V \approx \pi f(x)^2 \ \Delta x \implies V = \pi \int_a^b f(x)^2 \ dx
$$

## Metode Cincin (_washers_)

> [!img-caption] ![[image 4 10.png|image 4 10.png]]
> Gambar 4.6

Dalam metode ini, luas dari penampangnya adalah luas lingkaran luar dikurang luas lingkaran dalam. Maka, 
$$
\begin{align*}
\text{Luas} &= \pi R^2- \pi r^2 = \pi (R^2-r^2) \implies \pi [f(x)^2-g(x)^2] 
\\ &\implies \Delta V \approx \pi [f(x)^2-g(x)^2] \ \Delta x \implies V = \pi[f(x)^2-g(x)^2] \ \rm{d} x
\end{align*}
$$



### Metode Kulit Tabung (_shells)_

>[!img-caption] ![[image 5 10.png|image 5 10.png]]
> Gambar 4.7

>[!img-caption] ![[image 6 10.png|image 6 10.png]]
>Gambar 4.8

Dalam metode ini, kita akan memotong kulit tabung ini, sehingga menjadi sebuah balok, seperti pada **Gambar 4.8**.

Sehingga, dalam metode ini, luas penampang dari kulit tabung ini adalah persegi panjang. Maka, 
$$
\begin{align*}
\text{Luas} &= p \cdot l =2\pi \cdot r \cdot h \implies L(x) = 2\pi \cdot x \cdot f(x)  \\
&\implies \Delta V \approx 2\pi \cdot x \cdot f(x) \cdot \Delta x \implies V = 2\pi \int_a^bx \cdot f(x) \ dx
\end{align*}
$$



Catatan: Jika ingin memutar sebuah wilayah bidang terhadap sumbu $x = r$ atau $y = h$, kita bisa mengurangi atau menambahkan fungsi sesuai dengan sumbu yang diberikan untuk mendapatkan jari-jarinya.

### Pemilihan Metode?

1. Jika fungsi menyentuh sumbu putarnya, maka gunakan **Metode Cakram**
2. Jika fungsi tidak menyentuh sumbu putarnya dan ingin elemen luasnya tegak lurus dengan sumbu putarnya, maka gunakan **Metode Cincin**
3. Jika fungsi tidak menyentuh sumbu putarnya dan ingin elemen luasnya sejajar dengan sumbu putarnya, maka gunakan **Metode Kulit Tabung**

Tentu saja dalam penghitungan volume, kita bisa menggunakan lebih dari satu metode yang ada. Namun, untuk simplifikasi gunakan yang sudah diketahui dalam soal (misal jika sudah diketahui $y = f(x)$ tidak perlu mengubah menjadi $x = f(y)$ untuk menggunakan metode lain (Lihat **Latihan 17** pada **LKM Bab 5 Aplikasi Integral Pak Eric)**


### Volume Benda Nonputar
Pada benda putar, kita memutar suatu wilayah bidang terhadap suatu sumbu. Namun, pada benda nonputar, potongan melintangnya (_cross section_) berupa segitiga atau persegi.

Biasanya pada soal, potongan melintangnya diketahui dan alas dari benda nonputar ini adalah fungsi yang diberikan oleh soal.

>[!img-caption] ![[image 7 8.png|image 7 8.png]]
> Gambar 4.9

Potongan melintang berarti, ketika benda tersebut dipotong-potong, setiap potongan tersebut akan memiliki bentuk yang sama. Di sini, benda tegar ini baik alas, maupun sisi depannya adalah fungsi yang diberikan oleh soal. Misalnya, pada **Gambar 4.7**, maka setiap benda tegar ini dipotong, maka potongan tersebut akan berbentuk

Dalam metode ini, penampangnya adalah fungsi yang diketahui. Namun, kita menghitung volumenya dengan luas dari _cross section_-nya dan tebal dengan $\Delta x$.

- Jika _cross section_-nya adalah persegi, maka $\text{Luas} = s^2 \implies L(x) = f(x)^2 \implies \Delta V \approx f(x)^2 \ \Delta x \implies V = \int^b_a f(x)^2 \ dx$
- Jika _cross section_-nya adalah segitiga sama sisi, karena masing-masing sudutnya adalah $60^o$, maka jika masing-masing sisinya adalah $u$, maka ketinggiannya adalah $\sin 60^o = \frac{\sqrt{3}}{2}u$.

Sehingga,
$$
\begin{align*}
\text{Luas} &= \frac12 \cdot a \cdot t = \frac12 u \cdot \frac{\sqrt{3}}{2}u = \frac{\sqrt{3}}{4}u^2 \\
\implies L(x) &= \frac{\sqrt{3}}{4}f(x)^2 \implies \Delta V \approx \frac{\sqrt{3}}{4}f(x)^2 \ \Delta x \implies V = \frac{\sqrt{3}}{4}\int_a^bf(x)^2 \ dx
\end{align*}
$$
(Lihat **Gambar 4.9**)

Menggunakan metode yang sama, kita dapat menentukan volume dari benda tegar, seperti bola, prisma, dan limas dengan menggunakan luas penampangnya.

## Usaha

- Usaha

### Usaha Secara Umum

Usaha (_$W$_) adalah usaha/kerja yang dibutuhkan untuk memindahkan sebuah benda sejauh $d$ dengan gaya konstan $F$. Dalam Fisika, usaha didefinisikan dengan,

$$W = F \cdot d$$

Namun, pada banyak kondisi, gaya yang diberikan tidaklah konstan. Sehingga, perlu ada strategi secara matematis untuk menghitung hal tersebut. Konsep yang digunakan tidaklah jauh berbeda dengan penghitungan luas yang telah dilakukan sebelumnya, yaitu partisi menjadi subinterval, aproksimasi, dan integralkan untuk mengetahui nilai aslinya.

1. Partisi interval $[a, \ b]$ menjadi $n$ buah subinterval yang sama panjang yaitu $\Delta x$. Sehingga, gaya untuk memindahkan benda dari $x$ menuju $x + \Delta x$, untuk subinterval yang cukup kecil, memiliki gaya yang konstan, yaitu $F(x)$.
2. Aproksimasi elemen kerjanya
	
	$$\Delta W_i = F(\bar x_i)\ \Delta x \implies \Delta W \approx F(x) \ \Delta x$$
	
1. Aproksimasi nilai kerjanya
	
	$$W \approx \sum_{i=1}^n F(\bar x_i)\ \Delta x$$
	
2. Luas sesungguhnya adalah limit jumlah Riemann aproksimasi luas daerahnya
	
	$$W = \lim_{n\to\infty} \sum_{i=1}^nF(\bar x_i)\ \Delta x = \int_a^bF(x)\ dx$$
	

### Aplikasi Pada Pegas

>[!img-caption] ![[image 8 7.png|image 8 7.png]]
> Gambar 4.10

Menurut Hukum Hooke dalam Fisika, gaya $F(x)$ yang dibutuhkan untuk menahan sebuah pegas agar terkompresi atau teregang sebesar $x$ panjang dinyatakan dalam

$$
F(x) = k x
$$

dengan $k$ adalah konstanta dari pegas. Semakin kaku pegasnya, semakin besar nilai $k$-nya.

Aplikasi pada soal biasanya menanyakan tentang usaha yang dibutuhkan. Kita harus mencari gaya dari informasi pada soal, lalu diintegralkan sehingga mendapatkan hasil yang diinginkan.

## Aplikasi Pada Memompa Cairan

>[!img-caption] ![[image 9 5.png|image 9 5.png]]
> Gambar 4.11

Untuk menghitung usaha yang dibutuhkan untuk memompa suatu cairan. Kita perlu menghitung terlebih dahulu gaya $F(x)$ yang dibutuhkannya. Dalam hal ini, $F(x) = \delta \cdot V$, dengan $\delta$adalah berat jenis dari cairan dan $V$ adalah volume dari cairan. Sehingga usahanya adalah integral dari $F(x)$