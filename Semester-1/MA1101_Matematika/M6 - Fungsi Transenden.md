# Referensi
- Buku Calculus Early Transcendentals, Dale Varberg Edwin J. Purcell, Steve E. Rigdon
- LKM Bab 6 Fungsi Transenden Pak Eric
- Diktat Kalkulus 1 Warsoma Djohan, Wono Setya Budhi.
- [https://youtube.com/playlist?list=PLjs4VVzVn2XtmNmzEsQuJEZ6S_l-Zvcko&si=deOXWN3ANrxn0SS9](https://youtube.com/playlist?list=PLjs4VVzVn2XtmNmzEsQuJEZ6S_l-Zvcko&si=deOXWN3ANrxn0SS9)

# Fungsi Transenden
Fungsi polinomial atau fungsi aljabar adalah fungsi yang didapatkan dari manipulasi aljabar seperti penjumlahan dan perkalian. Sedangkan, fungsi transenden adalah fungsi yang tidak dapat didapatkan dari manipulasi aljabar sederhana. Contohnya, fungsi logaritma asli yang merupakan fungsi akumulasi dari $\frac1 t$ dari 1 sampai $x$. (akan dipelajari selanjutnya).

# Fungsi Logaritma Alami ($\ln x$)

Dari bab sebelumnya, perhatikan bahwa

$$\int x^n \ \mathrm{d}x = \frac{1}{n+1} x^{n+1} + C \implies \int \frac{1}{x^n} \ \mathrm{d}x = \int x^{-n} = \frac{1}{-n+1}x^{-n+1} + C$$

dengan $n \ne 1$, hal ini merupakan fungsi aljabar yang sudah kita ketahui sebelumnya. Namun, jika $n = 1$, maka akan didapat hasil $\frac{1}0$. Sehingga, perlu didefinisikan fungsi baru, yaitu

$$
\ln x = \int_1^x \frac{1}{t}\ \mathrm{d}t
$$

> [!img-caption] ![[diagram-20231205_(7).svg]]
> Gambar 1

## Turunan Fungsi Logaritma Alami

Berdasarkan TDK 1, maka

$$\frac{\mathrm{d}}{dx} (\ln x) = \frac{\mathrm{d}}{dx} \left( \int_1^x \frac{1}{t}\ \mathrm{d}t\right) = \frac1x$$

Namun, dengan berbagai pembuktian dapat melihat Video Pak Barra, LKM Pak Eric, dan metode lainnya, anti turunan dari $\displaystyle \frac{1}{x}$, tidak terbatas hanya pada $\ln x$. Namun, juga pada $\ln (-x)$ untuk $x < 0$. Sehingga, secara umum, anti turunan dari $\frac{1}{x}$ adalah

$$
\int \frac{1}{x} \ \mathrm{d}x = \ln |x| + C, \quad x \ne 0
$$

Bukti
$$
\begin{aligned}  
\ln |x| &= \begin{cases} \ln x , \quad &x > 0 \\ \ln(-x), \quad &x <0  
\end{cases}  
\\ \\  
Dx \ln |x| &= \begin{cases} \frac{1}{x}, &x >0 \\ \frac{1}{-x} \cdot (-1), &x < 0  
\end{cases}  
\end{aligned}
$$

## Grafik Logaritma Alami

![[diagram-20231205_(8).svg]]

Gambar 2

Grafik ini dapat ditentukan dari:

1. $D_f = \set{x:x>0}$ (terima dulu aja, nanti pembuktiannya)
2. $R_f=\set{x \in R}$
3. $\ln 1 = \int_1^1 \frac{1}{t} \ dt = 0$
4. $D_x (\ln x) = \frac{1}{x}$ yang mana karena $x>0$ sehingga $D_x (\ln x) > 0$ sehingga grafik monoton naik
5. $D_x^2(\ln x) = -\frac{1}{x^2}$ yang mana karena $x>0$ sehingga $D_x^2(\ln x) <0$ sehingga grafik cekung ke bawah
6. Asimtot tegak dari $\ln x$ adalah 0
7. Asimtot datar dari $\ln x$ adalah $e$ (dibuktikan nanti)

### Sifat-Sifat Logaritma Alami
1. $\ln 1 = 0$
$$
\ln 1 = \int_1^1 \frac{1}{t} \ \mathrm{d}t = 0
$$

$\displaystyle \int_1^1 \frac{1}{t} \ \mathrm{d}t$ berarti luas area di bawah kurva $\dfrac1t$ dari $x = 1$ sampai $x =1$ sehingga luas areanya adalah 0.

2. $\ln(ab) = \ln a+\ln b$
$$
\underbrace{\ln (ax) = \int_1^{ax} \frac{1}{t}\ \mathrm{d}t \implies \frac{\mathrm{d}}{\mathrm{d}x}\ln (ax) = \frac{1}{ax}\cdot a = \frac{1}{x} = \frac{\mathrm{d}}{\mathrm{d}x}\ln}_{\textsf{turunan dari} \ln x \textsf{ dan} \ln(ax) \textsf{ sama sehingga hanya berbeda konstanta } C}
$$
$$
\ln(ax) =\ln x + C
$$

Ketika x = 1, $\displaystyle{\ln(a) = 0 + C \implies \ln a = C}$ sehingga,

$$
\ln (ax) = \ln x + \ln a \implies \boxed{\ln(ab) = \ln a + \ln b}
$$

3.  $\displaystyle \ln \frac{a}{b} = \ln a - \ln b$

Misal, $a = \frac{1}{b}$, sehingga

$$
\begin{aligned}  
\ln (ab) &= \ln (\frac{1}{b} \cdot b)  
\\  
\ln a + \ln b &= \ln1  
\\  
\ln \frac{1}{b} + \ln b &= 0  
\\  
\ln \frac{1}{b} &= -\ln b  
\end{aligned}
$$


$$
\begin{align*}
\ln \frac{a}{b} &= \ln a + \ln \frac{1}{b} \\
\ln \frac{a}{b} &= \ln a - \ln b \\
\end{align*}
$$

5. $\ln x^r = r \ln x$
$$
\begin{align*}
\frac{\mathrm{d}}{\mathrm{d}x}\ln x^r =\frac{1}{x^r}rx^{r-1} &= \frac{1}{\cancel{x^r}}r(\cancel{x^r}\cdot x^{-1}) = \frac{r}{x} \\
\frac{\mathrm{d}}{\mathrm{d}x}(r \ln x) &= r \cdot \frac{1}{x} = \frac{r}{x}
\end{align*}
$$

Turunan dari $\ln x^r$ dan $r \ln x$ sama sehingga yang berbeda hanya konstanta $C$.

$$
\ln x^r = r \ln x + C
$$

Ketika $x =1$, maka $\ln 1^r = r \ln 1 + C$, sehingga
$$
C = 0 \implies \ln x^r = r \ln x
$$

# Pendiferensialan Logaritma
Dengan menggunakan
1. sifat-sifat logaritma alami,
2. melakukan operasi logaritma alami kepada kedua ruas, dan
3. menggunakan turunan implisit dengan menganggap $y$ adalah fungsi dari $x$

kita dapat mencari turunan dari fungsi yang rumit seperti $y = \dfrac{\sqrt{x^2 + 1}}{(x - 1)^2}$.
Langkah pengerjaan

$$
\begin{aligned}  
\ln y &= \ln \frac{\sqrt{x^2+1}}{(x-1)^2}  
\\  
\ln y &= \ln (x^2+1)^{\frac{1}{2}} - \ln (x-1)^2  
\\  
\ln y &= \frac12\ln(x^2+1) - 2\ln(x-1)  
\\  
D_x (\ln y) &= D_x\left( \frac12\ln(x^2+1) - 2\ln(x-1) \right)  
\\  
\frac{1}{y} \cdot \frac{\mathrm{d}y}{\mathrm{d}x} &= \frac{1}{2} \cdot \frac{1}{x^2+1}\cdot 2x - 2\cdot\frac{1}{x-1}\cdot 1  
\\  
\frac{\mathrm{d}{y}}{\mathrm{d}{x}} &= \left(\frac{x}{x^2+1} -\frac{2}{x-1} \right)y  
\\  
\frac{\mathrm{d}{y}}{\mathrm{d}{x}} &= \left(\frac{x}{x^2+1} -\frac{2}{x-1} \right) \dfrac{\sqrt{x^2 + 1}}{(x - 1)^2}  
\end{aligned}
$$

# Fungsi Satu-Satu
Fungsi disebut fungsi satu-satu (bijektif), jika tiap nilai $x$ pada daerah asal dipasangkan dengan tepat satu nilai $y$ yang unik pada daerah hasilnya. Dalam fungsi satu-satu tidak ada dua nilai $x$ yang berbeda yang menghasilkan nilai $y$ yang sama.

> [!img-caption] ![[diagram-20231205_(4).svg]]
> Gambar 3

> [!definition] Definition 
> Fungsi $f : X \to Y$ disebut satu-satu di $X$, dalam hal untuk setiap $x \in X$ berlaku jika $f(x_1) = f(x_2)$, maka $x_1 = y_2$ atau bisa juga ditulis jika $x_1 \ne x_2$, maka $f(x_1) \ne f(x_2)$`

Sehingga, dari definisi tersebut dapat diperoleh

> [!definition] Theorem 
> ]ika $f$ monoton di interval $I$, maka $f$ termasuk fungsi satu-satu di interval $I$.`

Hal ini disebabkan jika fungsi monoton naik, maka $x_1 < x_2 \iff f(x_1) < f(x_2)$ dan jika fungsi monoton turun, maka $x_1 < x_2 \iff f(x_1) > f(x_2)$. Dari hal ini, maka fungsi monoton memenuhi kontraposisi tersebut, yakni untuk tiap $x$ yang berbeda, pasti hasil fungsinya pun juga berbeda.

# Fungsi Invers
Pada fungsi $f:X\to Y$, relasi balikannya adalah pemetaan kembali fungsi dari $Y$ ke $X$. Namun, tiap relasi balikan belum tentu merupakan fungsi. Misal, pada $f(x) = x^2$, setiap $D_f$ memiliki tepat satu daerah hasilnya masing-masing. Namun, jika dibalik ada $R_f$ yang memiliki lebih dari satu daerah asal, misal $f(x) =4$ didapat melalui $x =2$ dan $x=-2$.

Syarat agar fungsi memiliki invers adalah fungsi harus bersifat satu-satu. Kita juga dapat membatasi domain dari fungsi agar fungsi memiliki invers.

Maka, dari syarat tersebut berlaku
Jika $f$ monoton di interval $I$, maka $f$ memiliki invers di interval $I$.

Fungsi invers dinotasikan sebagai $f^{-1}$ dengan aturan $f^{-1}(b)=a \iff f(a) =b$ dengan $a \in D_f$ dan $b \in R_f$. Secara umum, $D_{f^{-1}} = R_f$ dan $R_{f^{-1}} = D_f$. Sehingga, definisi fungsi invers adalah

$$
f^{-1}(f(x)) =x
$$

Secara grafis, untuk menggambar fungsi invers, kita dapat menukar input dan outputnya atau dicerminkan terhadap sumbu $y =x$. Sedangkan, untuk mencari fungsi invers secara aljabar dapat mengikuti langkah seperti soal berikut, misalkan $f(x) = 6x + 1$:

$$
\begin{aligned}  
f(x) = y &= 6x + 1  
\\  
y - 1 &= 6x  
\\  
\frac{y-1}{6} &= x \qquad [x = f^{-1}(y)]  
\\  
f^{-1}(y) &= \frac{y-1}{6}  
\\  
f^{-1}(x) &= \frac{x-1}{6}  
\end{aligned}
$$

# Turunan Fungsi Invers

> [!img-caption] ![[image 21.png|image 21.png]]
> Gambar 4

Misal diketahui grafik seperti gambar 4. Dengan $l_1$ adalah $f(x)$ dan $l_2$ adalah $f^{-1}(x)$. Dari titik-titik di atas, maka diperoleh

$$
\begin{aligned}  
m_1 &= \frac{d-b}{c-a}\\  
m_2 &= \frac{c-a}{d-b}  
\end{aligned}
$$

sehingga $m_1 \cdot m_2 = \dfrac{d-b}{c-a} \cdot \dfrac{c-a}{d-b} = 1 \implies m_2 = \dfrac{1}{m_1}$. Dengan demikian jika ada suatu titik $(a,b)$ atau $f(a) = b \iff f^{-1}(b) = a$. Maka, berlaku

$$
(f^{-1})'(b) =\dfrac{1}{f'(a)} \iff (f^{-1})'(b) =\dfrac{1}{f'(f^{-1}(b))}
$$

# Fungsi Eksponen Alami
Fungsi logaritma alami terbukti monoton naik pada domainnya, sehingga fungsi logaritma alami memiliki invers. Invers dari fungsi logaritma alami ini, kita sebut sebagai fungsi eksponen alami.
$$
y=\exp(x) \iff x = \ln(y)
$$

Perhatikan bahwa $\exp(x)$ adalah invers dari $\ln(x)$. Maka, mengingat $(f \circ f^{-1})(x) = x$, didapatkan bahwa $\exp(\ln(x)) = x$ dan $\ln(\exp(x)) = x$.

Berdasarkan sifat logaritma alami, diketahui bahwa $\ln(e) = 1$. Sehingga didapat bahwa $e = \ln^{-1}(1) \iff e = \exp(1)$. PPerhatikan juga bahwa, $\ln e^x =x \underbrace{\ln e}_{1} = x$.

$$
\ln e^x = x \iff e^x = \ln^{-1}(x) = \exp(x)
$$

Secara definisi, bilangan $e$ (disebut bilangan euler) didefinisikan sebagai
$$
\begin{aligned}  
e &= \lim_{h \to 0} (1+h)^\frac{1}{h}  
\\  
&= \lim_{n \to \infty} \left(1+\frac1 n \right)^n  
\\  
&= \lim_{n \to \infty}\left(1+\frac{1}{1!}+\frac{1}{2!}+\frac{1}{3!}+\dots\right)  
\\  
&\approx 2.71828\dots  
\end{aligned}
$$

Bukti (sort of):

Untuk $f(x) = \ln{x}$ didapat $f'(x) = \frac{1}{x}$ dan $f'(1)=1$
$$
\begin{aligned}  
f'(1) &= \lim_{h \to 0} \frac{\ln{(1+h)}-\overbrace{\ln{1}}^{0}}{h}=\lim_{h \to 0}\frac{1}{h}\ln(1+h)  
\\  
1 &=  
\lim_{h \to 0}\ln(1+h)^{\frac{1}{h}}  
\end{aligned}
$$

Perhatikan bahwa $e^x=\exp(x)$, maka $e^1 = \exp(1)$:
$$
\begin{aligned}  
e &= \exp{(\lim_{h \to 0}\ (\ln(1+h)^{\frac{1}{h}})} \\  
e &= \lim_{h \to 0\ }(\exp(\ln(1+h)^{\frac{1}{h}} \\  
e &= \lim_{h \to 0}\ (1+h)^{\frac{1}{h}}  
\end{aligned}
$$

## Sifat-Sifat Eksponen Alami
1. $e^{\ln x} = x \iff \ln(e^x) = x$
2. $e^0 = 1$

$$
\ln(1) = 0 \iff 1 = \ln^{-1}(0) = \exp(0) =e^0
$$

3. $e^{a+b} = e^a + e^b$
$$
\begin{aligned}  
a + b &= \ln(\exp(a)) + \ln(\exp(b))  
\\ &= \ln(\exp(a) \cdot \exp(b))  
\\ &= \ln(e^a \cdot e^b)  
\\ e^{a+b} &= e^{\ln(e^a \cdot e^b)}  
\\ &= e^a \cdot e^b  
\end{aligned}
$$

4. $e^{a-b} = \frac{e^a}{e^b}$
$$
\begin{aligned}  
a - b &= \ln(\exp(a)) - \ln(\exp(b))  
\\ &= \ln(\frac{\exp(a)}{\exp(b)})  
\\ &= \ln(\frac{e^a}{e^b})  
\\ e^{a+b} &= e^{\ln\frac{e^a}{e^b}}  
\\ &= \frac{e^a}{e^b}  
\end{aligned}
$$    
5. $(e^a)^{r} = e^{ar}$
$$
\begin{aligned}  
(e^a)^r &= e^{\ln(e^a)^r} \\  
&= e^{r \ln(e^a)}\\  
&= e^{a\cdot r \ln e} \\  
(e^a)^r &= e^{ar}  
\end{aligned}
$$

Perhatikan bahwa $a^x = e^{\ln a^x} = e^{x \ln a}$, dengan $a$ adalah bilangan rasional sembarang, maka sifat-sifat di atas juga berlaku untuk bilangan eksponen.

## Turunan Fungsi $e^x$
$$
f(x)= e^x \iff f'(x) =e^x
$$

Hal ini dapat dibuktikan dengan Teorema Turunan Fungsi Invers. Misal, $f(x) = \ln(x)$, $f^{-1}(x)=e^x$, $f'(x) = \dfrac{1}{x}$, sehingga
$$
(f^{-1})'(x) =\dfrac{1}{f'(f^{-1}(x))} \implies \frac{\rm{d}}{\rm d x} e^x = \frac{1}{\frac{1}{e^x}} \implies \frac{\rm{d}}{\rm d x} e^x = e^x
$$

atau dapat juga dibuktikan sebagai, misal $y = e^x \iff x = \ln y$
$$
\begin{aligned}  
\ln y &= x \\  
\frac{1}{y} \cdot \frac{\rm{dy}}{\rm{dx}}&= 1 \\  
\frac{\rm{d}}{\rm{dx}} e^x&= e^x  
\end{aligned}
$$

Dikarenakan turunan dari $e^x$ adalah $e^x$, maka
$$
\int e^x = e^x + C
$$

# Fungsi Eksponen Umum
Fungsi eksponen memiliki bentuk umum $f(x) = a^x$ dengan $a>0$ dan $a \ne 1$. Fungsi ini dapat kita definisikan menggunakan fungsi eksponen alami, yaitu

$$
a^x = e^{\ln(a^x)}=e^{x\ln a}
$$

Turunan dari fungsi ini adalah

$$
\begin{aligned}  
\frac{\rm{d}}{\rm{dx}} a^x &= \frac{\rm{d}}{\rm{dx}} e^{x\ln a}  
\\ &= e^{x \ln a} \cdot \ln a  
\\ &= a^x \ln a  
\end{aligned}
$$

Sedangkan, dengan $u = x \ln a$ dan $\rm{du} = \ln a \ \rm{dx}$, anti turunannya adalah

$$
\begin{aligned}  
\int a^x &= \int e^{x\ln a}\ \rm{dx}  
\\ &= \int e^u \frac{\rm{du}}{\ln a}  
\\ &= \frac{e^{x\ln a}}{\ln a} + C \\  
&= \frac{a^x}{\ln a} + C  
\end{aligned}
$$

# Fungsi Logaritma Umum

Fungsi eksponen umum juga memiliki fungsi inversnya. Invers dari fungsi logaritma umum ini disebut fungsi logaritma umum.

$$
x = a^y \iff y = \log_a x
$$

Sehingga,
$$
x = \log_a y \implies y = a^x \implies \ln y = x \ln a \implies x =\frac{\ln y}{\ln a} \\  
\log_a y = \frac{\ln y}{\ln a}
$$

Dari definisi ini, kita dapat menemukan bahwa logaritma umum adalah logaritma dengan basis $e$.
$$
\log_e y = \frac{\ln y}{\ln e} = \ln y
$$

Berdasarkan definisi logaritma umum, maka turunannya adalah
$$
\log_a x = \frac{\ln x}{\ln a} \implies \frac{\rm{d}}{\rm{dx}} \log_a x = \frac{\frac{1}{x}\cdot \ln a - 0}{(\ln a)^2} = \frac{1}{x\ln a}
$$

Sifat yang berlaku pada $\ln x$ juga berlaku untuk $\log_a x$.

# Aplikasi Fungsi Eksponen dan Logaritma

## Pertumbuhan Populasi
Diasumsikan bahwa laju pertumbuhan berbanding lurus dengan banyaknya populasi.

$$
\frac{\mathrm{d}y}{\mathrm{d}t}\sim y
$$

Sehingga, untuk suatu konstanta $k$, $\dfrac{\mathrm{d}y}{\mathrm{d}t} = ky$. Di mana solusi dari persamaan diferensial tersebut adalah
$$
\begin{aligned}  
\frac{\mathrm{d}y}{\mathrm{d}t} &= ky \\  
\frac{1}{y} \cdot \mathrm{d}y &= k \cdot \mathrm{d}t \\  
\int\frac{1}{y} \cdot \mathrm{d}y &= \int k \cdot \mathrm{d}t \\  
\ln{|y|} &= kt + C \\  
e^{\ln{|y|}} &= e^{kt+C} \\  
|y| &= e^C \cdot e^{kt} \\  
\end{aligned}
$$

Perhatikan bahwa $e^C$ akan bergantung pada waktu $t$. Sehingga pada saat $t =0$, $y =e^C$ yang mana $e^C$dapat didefinisikan sebagai konstanta $A$ atau $y_0$ yang berarti populasi awal (populasi saat $t=0$). Sehingga persamaan di atas dapat ditulis sebagai:

$$
y(t) = Ae^{kt}
$$

## Peluruhan

Persamaan di atas, juga dapat diaplikasikan untuk menghitung jumlah zat dalam suatu peluruhan.

## Bunga Majemuk
Persamaan di atas, juga dapat diaplikasikan untuk menghitung bunga majemuk dalam bank. _Loh, kok bisa._ Jadi gini:

Untuk menghitung bunga majemuk, dengan modal dengan bunga $A$, modal awal $A_0$, bunga per tahun dalam desimal $r$, tahun tabungan $t$, dan periode pembayaran $n$ (jumlah dibayar, misal jika pembayaran per bulan, maka $\frac{\textsf{bunga/12 bulan}}{\textsf{bulan}}=\frac{\textsf{bunga}}{\textsf{12}}$, akan digunakan persamaan berikut

$$
\begin{aligned}  
A = A_0\left(1+\frac{r}{n}\right)^{nt}  
\end{aligned}
$$

Hal ini berlaku untuk periode $n$ yang hingga. Namun, penghitungan bunga majemuk pada dunia nyata, tentunya dihitung secara kontinu dan tiap waktu. Maka, persamaan untuk bunga majemuk yang “benar” adalah

$$
\begin{aligned}  
A &= \lim_{n \to \infty}A_0\left(1 + \frac{r}{n} \right)^{nt} \qquad \to h = \frac{r}{n}\\  
&= \lim_{h \to \infty}A_0 \left( 1 + h \right)^{\frac{1}{h}^{rt}} \\  
&= A_0 \left( \lim_{h \to \infty}\left( 1 + h \right)^{\frac{1}{h}}\right)^{rt}\\  
&= A_0e^{rt}  
\end{aligned}
$$

## Hukum Pendinginan Newton
Menurut Hukum Pendinginan Newton, laju perubahan temperatur suatu benda $\frac{\mathrm{d}T}{\mathrm{d}t}$sebanding dengan perbedaan temperatur awal dari benda ($T$) dengan temperatur sekitarnya ($T_1$).

$$
\frac{\mathrm{d}T}{\mathrm{d}{t}}=-k(T-T_1)
$$

$$
\begin{aligned}  
\frac{\mathrm{d}T}{\mathrm{d}t} &= -k(T-T_1) \\  
\frac{1}{T-T_1} \cdot \mathrm{d}T &= -k \cdot \mathrm{d}t \\  
\int\frac{1}{T-T_1} \cdot \mathrm{d}T &= \int-k \cdot \mathrm{d}t \\  
\ln{|T-T_1|} &= -kt + C \\  
e^{\ln{|T-T_1|}} &= e^{-kt+C} \\  
|T-T_1| &= e^C \cdot e^{-kt} \\  
\end{aligned}
$$

Perhatikan bahwa $e^C$ akan bergantung pada waktu $t$. Sehingga pada saat $t =0$, $T-T_1 =e^C$. Sehingga persamaan di atas dapat ditulis sebagai:

$$T(t)=(T-T_1)e^{-kT} + T_1$$

# Persamaan Diferensial Linear Orde Satu

Orde persamaan diferensial mengacu pada turunan paling tinggi dalam persamaan diferensial. Linear pada persamaan diferensial linear orde satu berarti bahwa persamaan ini linear terhadap variabel terikatnya. Persamaan diferensial linear orde satu adalah persamaan dalam bentuk:

$$
\frac{dy}{dx} + P(x)y = Q(x)
$$

*_simpelnya disebut linear karena $y$-nya linear gak ada $y \cdot y$, atau $y \cdot y'$._

_Untuk persamaan diferensial linear orde satu ini, kita gak banyak dijelasin tentang asal muasalnya tapi yang penting kita ngerti cara dapet solusi dari persamaan diferensial ini._

## Faktor Pengintegralan

1. Tentukan faktor pengintegralan sebagai $\mu(x) = e^{\int P(x) dx}$
2. Kalikan kedua ruas dengan faktor pengintegralnya
3. Kenali ruas kiri dapat ditulis ulang sebagai $\frac{d}{dx}(u(x)y(x))$
4. Integralkan kedua ruas dan selesaikan untuk $y$

# Fungsi Invers Trigonometri

Fungsi trigonometri dapat memiliki invers, apabila kita membatasi domainnya, sehingga fungsi trigonometri monoton dan tidak memiliki nilai $f(x)$ yang sama pada satu domain.

Fungsi $\sin(x)$

>[!img-caption] ![[image 1 10.png|image 1 10.png]]
> Gambar 5

Agar fungsi $\sin(x)$ monoton dan memiliki invers, maka dibatasi domainnya pada $[-\frac{\pi}{2}, \frac{\pi}{2}]$. Fungsi ini disebut fungsi $\arcsin (x)$ atau $\sin^{-1}(x)$.

Fungsi $\cos(x)$

>[!img-caption] ![[image 2 8.png|image 2 8.png]]
> Gambar 6

Agar fungsi $\cos (x)$ monoton dan memiliki invers, maka dibatasi domainnya pada $[0, \pi]$. Fungsi ini disebut fungsi $\arccos (x)$ atau $\cos^{-1}(x)$.

Fungsi $\tan(x)$

>[!img-caption] ![[image 3 8.png|image 3 8.png]]
> Gambar 7

Agar fungsi $\tan(x)$ monoton dan memiliki invers, maka dibatas domainnya pada $(-\frac{\pi}{2}, \frac{\pi}{2})$. Fungsi ini disebut fungsi $\arctan (x)$ atau $\tan^{-1}(x)$.

Grafik fungsi $\sin^{-1}(x)$

>[!img-caption] ![[image 4 8.png|image 4 8.png]]
> Gambar 8

Gambar fungsi $\cos^{-1}(x)$

>[!img-caption] ![[image 5 8.png|image 5 8.png]]
> Gambar 9

Grafik fungsi $\tan^{-1}(x)$

>[!img-caption] ![[image 6 8.png|image 6 8.png]]
> Gambar 10

### Turunan Fungsi Invers Trigonometri

Turunan fungsi invers trigonometri dapat kita lakukan dengan turunan implisit dan beberapa identitas trigonometri dasar, seperti $\sin^2(x) + \cos^2(x) = 1 \implies \cos(x) = \sqrt{1 - \sin^2(x)}$

$$
\begin{align*}  
y &= \sin^{-1}(x) \\  
\sin(y) &= x \\  
\frac{d}{dx}[\sin(y)] &= \frac{d}{dx}[x] \\  
\cos(y) \cdot \frac{dy}{dx} &= 1 \\  
\frac{dy}{dx} &= \frac{1}{\cos(y)} \\  
&= \frac{1}{\sqrt{1-\sin^2(y)}} \\  
&= \frac{1}{\sqrt{1-x^2}}  
\end{align*}
$$

Pembuktian lain dapat dilakukan sendiri, namun secara singkat untuk rumus turunan fungsi invers trigonometri adalah sebagai berikut.

|Fungsi Invers Trigonometri|Rumus Turunan|
|---|---|
|$\sin^{-1}(x)$|$\frac{1}{\sqrt{1-x^2}}$|
|$\cos^{-1}(x)$|$-\frac{1}{\sqrt{1-x^2}}$|
|$\tan^{-1}(x)$|$\frac{1}{1+x^2}$|
|$\cot^{-1}(x)$|$-\frac{1}{1+x^2}$|
|$\sec^{-1}(x)$|$\frac{1}{x\sqrt{x^2-1}}$|
|$\cosec^{-1}(x)$|$\frac{1}{x\sqrt{x^2-1}}$|

# Fungsi Hiperbolik
Fungsi hiperbolik didefinisikan menggunakan eksponensial, yang mengarah pada sifat-sifat yang mirip dengan fungsi trigonometri, tetapi dengan "sudut" dalam konteks hiperbolik (bukan melingkar). Fungsi hiperbolik ini menggunakan notasi dari trigonometri karena kemiripannya dengan beberapa identitas trigonometri.

$$
\begin{align*}  
\sinh(x) &= \frac{e^x - e^{-x}}{2} \\  
\cosh(x) &= \frac{e^x + e^{-x}}{2}  
\end{align*}
$$

Beberapa kemiripan dengan identitas trigonometri adalah sebagai berikut.
1. $\tanh(x) = \frac{\sinh(x)}{\cosh(x)}$
2. $\cosh^2(x) - \sinh^2(x) = 1$

## Grafik Fungsi Hiperbolik

Grafik fungsi $\sinh(x)$
>[!img-caption] ![[image 7 6.png|image 7 6.png]]
>Gambar 11

Grafik fungsi $\cosh(x)$
>[!img-caption] ![[image 8 5.png|image 8 5.png]]
> Gambar 12

Grafik fungsi $\tanh(x)$
>[!img-caption] ![[image 9 3.png|image 9 3.png]]
> Gambar 13

## Invers Fungsi Hiperbolik

>[!img-caption] ![[image 10 3.png|image 10 3.png]]
> Gambar 13

### Turunan Fungsi Hiperbolik
>[!img-caption] ![[image 11 3.png|image 11 3.png]]
> Gambar 14