---
Note Type: Notes
Done: true
Date: 2025-04-01
Last edited time: 2025-09-01T18:00
tags: Fisika
---
- Quick Access
    - [[#Referensi]]
    - [[#📝 Notes]]
    - [[#Gelombang]]
        - [[#Grafik Fungsi Posisi]]
        - [[#Grafik Fungsi Waktu]]
        - [[#Kecepatan Gelombang]]
    - [[#Gelombang Tali]]
    - [[#Energi dan Daya pada Gelombang Tali]]
        - [[#Laju Transmisi Energi]]
    - [[#Interferensi Gelombang]]
        - [[#Superposisi Gelombang]]
        - [[#Interferensi Gelombang]]
        - [[#Metode Fasor]]
    - [[#Gelombang Berdiri]]
        - [[#Gelombang Berdiri Pada Tali]]
    - [[#Gelombang Bunyi]]
        - [[#Gelombang Longitudinal]]
        - [[#Kecepatan Rambat Gelombang Bunyi]]
        - [[#Intensitas Bunyi]]
        - [[#Skala Desibel]]
    - [[#Interferensi Gelombang Bunyi]]
    - [[#Efek Doppler]]

## Referensi

---

- Buku Halliday
- PPT Gelombang I Pak Arief
- PPT Gelombang II Pak Arief

## 📝 Notes

---

## Gelombang

Gelombang mekanik terjadi karena perambatan energi akibat gangguan periodik pada medium gelombang. Jika gangguan yang diberikan pada suatu medium tidak periodik, ini tidak disebut sebagai gelombang, tapi disebut sebagai detak (pulse).

Terdapat dua jenis gelombang berdasarkan jenis simpangannya, yaitu

1. Gelombang transversal (**Gambar 1**) adalah gelombang yang arah simpangannya tegak lurus dengan arah rambatan gelombang.
2. Gelombang longitudinal (**Gambar 2**) adalah gelombang yang arah simpangannya sejajar dengan arah rambatan gelombang.

![[image 15.png|image 15.png]]

Gambar 1

![[image 1 8.png|image 1 8.png]]

Gambar 2

Anggap sebuah gelombang bergerak ke arah positif dalam sumbu-$x$. Sebuah elemen gelombang berosilasi paralel terhadap sumbu-$y$. Pada waktu $t$, posisi $y$ dari elemen gelombang yang berlokasi di posisi $x$ dinyatakan dalam:

$$y(x,t)= y_m\sin(kx-\omega t + \phi)$$

dengan $y(x,t)$ sebagai perpindahan gelombang, $y_m$ sebagai amplitudo gelombang, $k$ sebagai bilangan gelombang, $\omega$ sebagai frekuensi gelombang, dan $\phi$ sebagai fasa awal gelombang.

### Grafik Fungsi Posisi

![[image 2 7.png|image 2 7.png]]

Gambar 3

**Gambar 3** merupakan gambar grafik di mana waktu $t = 0$, yaitu

$$y(x,0) = y_m\sin(kx)$$

Berdasarkan definisi, posisi suatu elemen gelombang $y$ pada suatu $x =x_1$ sama seperti posisi pada $x = x_1+\lambda$ dengan $\lambda$ sebagai panjang gelombang (meter). Sehingga, jika kita subtitusikan pada fungsi posisi pada $t =0$, kita akan mendapatkan

$$y_m\sin(kx)= y_m\sin(kx+k\lambda)$$

Perlu diingat bahwa fungsi sinus berulang ketika argumennya merupakan ditambah dengan kelipatan $2\pi$, maka dapat disimpulkan bahwa $k\lambda = 2 \pi$, maka untuk mendapatkan bilangan gelombang kita dapat menghitungnya dengan:

$$k=\frac{2\pi}{\lambda}$$

Bilangan gelombang $k$ memiliki satuan radian per meter atau $m^{-1}$.

### Grafik Fungsi Waktu

![[image 3 7.png|image 3 7.png]]

Gambar 4

**Gambar 4** merupakan gambar grafik di mana elemen gelombang berada pada posisi $x =0$, yaitu

$$y(0,t) = y_m \sin(-\omega t)= -y_m\sin(\omega t)$$

Sama seperti apa yang kita lakukan pada grafik fungsi posisi, suatu elemen gelombang pada posisi $y$ pada suatu waktu $t$ akan sama dengan suatu elemen gelombang pada posisi elemen gelombang pada waktu $t+T$.

$$-y_m\sin(\omega t)= -y_m\sin(\omega t+\omega T)\\  
\omega T = 2\pi \\  
\omega = \frac{2\pi}{T}$$

Tidak lupa juga bahwa $f = \dfrac{1}{T}=\dfrac{\omega}{2\pi}$

### Kecepatan Gelombang

![[image 4 7.png|image 4 7.png]]

Gambar 5

Seperti pada **Gambar 5**, dua fungsi gelombang yang hampir sama apabila berada pada $x$ yang berbeda sehingga mendapatkan $\Delta x$ berada pada ketinggian yang sama. Begitu pula dengan $t$. Sehingga, dapat kita simpulkan bahwa argumen dari fungsi sinusnya konstan atau $kx-\omega t$ adalah suatu konstan. Namun, $x$ dan $t$ tentu saja tidak konstan, karena seiring bertambahnya waktu $t$, maka agar formula ini konstan, $x$ juga harus bertambah

Dengan menurunkan formula tadi, maka kita dapat mendapatkan:

$$\begin{align*}  
kx-\omega t &= C \\  
k\frac{dx}{dt} - \omega &= 0 \\  
kv - \omega &= 0 \\  
v &= \frac{\omega}{k}  
\end{align*}$$

Sehingga, dapat disimpulkan pula bahwa kecepatan gelombang $v$ adalah:

$$v = \frac{\omega}{k} = \frac{\lambda}{T}=\lambda f$$

Hal ini juga berlaku pada $kx + \omega t$, namun jika kita melakukan hal yang sama, maka kita akan mendapat bahwa:

$$\frac{dx}{dt}=-\frac{\omega}{k}$$

Sehingga, dibuktikan bahwa $kx -\omega t$ bergerak ke arah sumbu $x$ positif dan $kx + \omega t$ bergerak ke arah sumbu $x$ negatif.

## Gelombang Tali

Pada gelombang tali, kita anggap bahwa gelombang ini bukan sebagai gelombang sinusoidal, namun sebagai suatu _pulse_ simetris seperti pada **Gambar 6** yang bergerak dari kiri ke kanan dengan kecepatan $v$. Tali ini memiliki dimensi massa $m$ dan dimensi panjang $l$. Massa $m$ terbagi atas panjang $l$. Rasio antara massa dan panjang ini disebut rapat massa linear $\mu = m/l$.

![[image 5 7.png|image 5 7.png]]

Gambar 6

Pada **Gambar 6** kita dapat menghitung bahwa secara vertikal, gaya tali $\vec T$. Maka, $F = 2(T\sin \theta) \approx T(2\theta) = T(\frac{\Delta l}{R})$. $\Delta l$ juga bergerak dalam lintasan lingkaran, sehingga memiliki percepatan sentripetal $a = \frac{v^2}{R}$. Lalu, dengan menggabungkannya dalam Hukum Kedua Newton, maka kita akan mendapatkan:

$$F = ma \\  
T(\frac{\Delta l}{R}) = \mu \Delta l\frac{v^2}{R}$$

Maka, kita dapat menentukan kecepatan dengan persamaan:

$$v= \sqrt{\frac{T}{\mu}}$$

## Energi dan Daya pada Gelombang Tali

![[image 6 7.png|image 6 7.png]]

Gambar 7

Elemen gelombang tali di puncak amplitudonya memiliki kecepatan transversal $\vec u= 0$, sehingga energi kinetik $K= 0$. Sedangkan, pada ketinggian $y =0$, kecepatan transversalnya $\vec u$ maksimal, sehingga energi kinetik $K$ maksimal.

Sebaliknya, elemen gelombang tali di puncak amplitudo memiliki panjang yang tidak berubah, sehingga energi potensial elastik $U = 0$. Sedangkan, pada ketinggian $y = 0$, tali meregang maksimal, sehingga panjangnya juga maksimal, dan energi potensial elastik $U$ maksimal.

Untuk membuat sebuah tali berosilasi, kita memberikan energi secara kontinu pada tiap elemen gelombangnya. Hal ini dilakukan secara alami oleh tali dengan mentransfer energi dari satu elemen gelombang ke elemen gelombang selanjutnya secara kontinu. Hal inilah yang disebutkan **Transmisi Energi**.

### Laju Transmisi Energi

Elemen energi kinetik $dK$ diasosiakan dengan elemen massa $dm$ dan kecepatan transversal $u$. Sehingga, persamaannya menjadi

$$dK=\frac{1}{2}dm\ u^2$$

Untuk mencari kecepatan transversal, tentunya kita dapat melakukannya dengan menurunkan persamaan posisi terhadap waktu.

$$u = \frac{\delta y}{\delta t} = -\omega y_m\cos(kx-\omega t)$$

Lalu, dengan mensubtitusikan persamaan ini ke persamaan elemen energi kinetik dan $dm = \mu \ dx$. Serta, membagi persamaan dengan $dt$. Maka, persamaannya akan menjadi

$$dK = \frac{1}{2}(\mu \ dx)(-\omega ^2 y^2)\cos^2(kx-\omega t) \\  
\frac{dK}{dt}=\frac{1}{2}\mu v\omega^2y_m^2 \cos^2{(kx-\omega t)}$$

Lalu, energi potensial elastik $U$ juga mendapatkan persamaan yang sama (_pembuktiannya gaada di buku)_, lalu untuk mencari laju energi rata-rata, kita akan menggunakan juga rata-rata fungsi cosinus kuadrat adalah $\frac{1}{2}$. Maka, kita akan mendapat laju energi rata-ratanya adalah:

$$\left(\frac{dK}{dt} \right)_{avg} = \frac{1}{4}\mu v\omega^2y_m^2 \\  
\left(\frac{dU}{dt} \right)_{avg} = \frac{1}{4}\mu v\omega^2y_m^2$$

Maka, daya rata-ratanya adalah $P_{avg} = \left[\frac{dK}{dt}\right] + \left[\frac{dU}{dt}\right]$

$$P_{avg}= \frac{1}{2}\mu v \omega^2 y_m^2$$

## Interferensi Gelombang

### Superposisi Gelombang

Prinsip superposisi gelombang adalah penjumlahan antara dua gelombang yang saling tumpuk atau _overlapping_.

![[image 7 5.png|image 7 5.png]]

Gambar 8

Pada **Gambar 8**, ditunjukkan bahwa ketika dua gelombang yang berbeda $y_1(x,t)$ dan $y_2(x,t)$ akan menghasilkan gelombang yang _overlap_ dengan hasil aljabar dari kedua gelombang tersebut.

$$y'(x,t) = y_1(x,t) + y_2(x,t)$$

Hal ini menunjukkan bahwa gelombang yang _overlap_ akan menghasilkan resultan gelombangnya. Gelombang yang _overlap_ tidak mempengaruhi pergerakan kedua gelombang.

### Interferensi Gelombang

Interferensi gelombang berlaku ketika terjadi superposisi dua buah gelombang yang memiliki amplitudo dan panjang gelombang yang sama, namun berbeda fasanya yang bergerak ke arah yang sama.

$$\begin{align*}  
y_1(x, t) &= y_m \sin(kx - \omega t) \\  
y_2(x, t) &= y_m \sin(kx - \omega t + \phi)  
\end{align*}$$

Maka, superposisi gelombangnya adalah

$$\begin{align*}  
y'(x, t) &= y_1(x, t) + y_2(x, t) \\  
&= y_m \sin(kx - \omega t) + y_m \sin(kx - \omega t + \phi)  
\end{align*}$$

dan menuliskannya ulang dengan $\sin \alpha + \sin \beta = 2\sin(\frac{1}{2}(\alpha + \beta)\cos \frac{1}{2}(\alpha - \beta)$. Maka, persamaannya menjadi:

$$y'(x, t) = \underbrace{2y_m \cos(\frac{1}{2}\phi)}_{\textsf{amplitudo}}\underbrace{\sin(kx-\omega t + \frac{1}{2}\phi)}_{\textsf{variabel osilasi}} \\  
y'_m = 2y_m\cos(\frac{1}{2}\phi)$$

Dengan memberikan fasa yang berbeda, berikut adalah hasil dari interferensi gelombangnya:

![[image 8 4.png|image 8 4.png]]

Gambar 9

![[image 9 2.png|image 9 2.png]]

Gambar 10

Sebagai penjelasan untuk **Gambar 10**, interferensi konstruktif terjadi ketika fase awal $\phi = 0$ yang menghasilkan superposisi gelombang memiliki amplitudo maksimal. Sedangkan, interferensi destruktif terjadi ketika fase awal $\phi = \pi$ yang menghasilkan superposisi gelombang datar

### Metode Fasor

Fasor adalah vektor yang berputar pada titik sumbunya. Besaran vektornya sama dengan amplitudo $y_m$ dari gelombang dan kecepatan sudut $\omega$ sama dengan frekuensi sudut $\omega$ dari gelombang. Kita dapat menggunakan metode fasor bahkan jika amplitudo dari kedua gelombang berbeda.

![[image 10 2.png|image 10 2.png]]

Gambar 11

*_Sebenarnya metode fasor gak seplek-ketiplek ini, dia bisa dibuat untuk menggambar gelombangnya juga, tapi karena gak diajarin Pak Arief (Dosen gw) jadi gak gw masukin, tapi ada di buku kok kalau mau liat_

Jika gelombang 1 $y_1(x, t)$ dan gelombang 2 $y_2(x, t)$ adalah sebagai berikut:

$$y_1(x,t) = y_{m1}\sin(kx-\omega t) \\  
y_2(x,t) = y_{m2}\sin(kx-\omega t + \phi)$$

Maka, superposisi gelombangnya adalah:

$$y'(x, t) = y'_m\sin(kx - \omega t + \beta)$$

Kita dapat mencari $y'_m$ dan $\beta$ dengan penjumlahan vektor dan perhitungan dasar.

## Gelombang Berdiri

Gelombang berdiri berlaku ketika terjadi superposisi dua buah gelombang yang memiliki amplitudo, panjang gelombang, dan fasa yang sama yang bergerak ke arah yang berlawanan.

![[image 11 2.png|image 11 2.png]]

Gambar 12

  

Gelombang 1 $y_1(x, t)$ dan gelombang 2 $y_2(x,t)$ adalah sebagai berikut:

$$y_1(x,t) = y_{m}\sin(kx-\omega t) \\  
y_2(x,t) = y_{m}\sin(kx + \omega t )$$

Maka, superposisi gelombangnya adalah:

$$y'(x,t) = [2y_m\sin(kx)]\cos(\omega t)$$

Nilai dari $2y_m\sin(kx)$ dapat kita anggap sebagai amplitudo. Pada gelombang berdiri, amplitudonya bervariasi sesuai dengan posisi $x$. Misal, amplitudo dari gelombang berdiri bernilai nol, jika nilai $kx$ akan membuat $\sin(kx) = 0$. Nilai tersebut ialah:

$$kx = n\pi \ \text{ untuk } n = 0, 1, 2, \dots$$

dengan mensubtitusikan $k = 2\pi/\lambda$, sehingga $\displaystyle x = n\frac{\lambda}{2}$. Nilai ini selanjutnya disebut _node_.

dan amplitudo dari gelombang berdiri bernilai maksimal, jika nilai $kx$ membuat $|\sin(kx)| = 1$. Nilai tersebut ialah:

$$kx = \frac{1}{2}\pi, \frac{3}{2}\pi, \frac{5}{2}\pi, \dots \\  
kx = (n+\frac{1}{2})\pi\ \text{ untuk } n = 0, 1, 2, \dots$$

dengan mensubtitusikan $k = 2\pi/\lambda$, sehingga $\displaystyle x = (n+\frac{1}{2})\frac{\lambda}{2}$. Nilai ini selanjutnya disebut _antinode_.

### Gelombang Berdiri Pada Tali

Saat kita memberikan suatu tali yang kedua ujungnya terikat dan kita memberikan gelombang sinusoidal secara kontinu dengan suatu frekuensi, misalkan ke kanan. Ketika gelombang mencapai ujung kanan, gelombang akan berputar kembali dan bergerak ke ujung kiri dan seterusnya. Maka, dengan cepat kita akan mendapatkan gelombang yang bergerak dengan _overlap_ yang akan terinterferensi dengan satu sama lain.

Untuk suatu frekuensi, interferensi akan menghasilkan suatu pola gelombang berdiri dengan _node_ dan _antinode_. Gelombang berdiri ini akan menghasilkan resonansi dan tali akan beresonansi dalam suatu frekuensi yang disebut frekuensi resonansi. Resonansi ini terjadi karena frekuensi _driving_ dan frekuensi natural tali bernilai sama.

Pola yang ditunjukkan oleh **gelombang berdiri dengan kedua ujung terika**t ini akan berbentuk sebagai berikut.

![[image 12 2.png|image 12 2.png]]

Gambar 13

Di mana tiap seri harmonik akan menambahkan panjang gelombang sebagai $\lambda = \frac{2L}{n}$ untuk $n = 1, 2, 3, \dots$ dan $n$ sebagai bilangan harmonik dari seri ke-$n$ harmoni. Lalu, frekuensinya dapat ditentukan dengan

$$f = \frac{v}{\lambda} = n \frac{v}{2L}$$

Cara menghafal gelombang berdiri dengan kedua ujung terikat ini adalah $n-a-n$, yaitu _nodes_–_antinodes_–_nodes_.

  

**Gelombang berdiri dengan kedua ujung bebas:**

![[image 13 2.png|image 13 2.png]]

![[image 14 2.png|image 14 2.png]]

Gambar 14

Tiap seri harmonik akan menambahkan panjang gelombang sebagai $\lambda = \frac{2L}{n}$ untuk $n = 1, 2, 3, \dots$. dan $n$ sebagai bilangan harmonik dari seri ke-$n$ harmoni. Lalu frekuensinya dapat ditentukan dengan $f = \frac{v}{\lambda} = n \frac{v}{2L}$.

Cara menghafal gelombang berdiri dengan kedua ujung terikat ini adalah $a-n-a$, yaitu _antinodes_–_nodes_–_antinodes_.

  

**Gelombang berdiri dengan salah satu ujung terikat:**

![[image 15 2.png|image 15 2.png]]

Gambar 15

iap seri harmonik akan menambahkan panjang gelombang sebagai $\lambda = \frac{4L}{n}$ untuk $n = 1, 3, 5, \dots$. dan $n$ sebagai bilangan harmonik dari seri ke-$n$ harmoni. Catat bahwa $n$ harus berupa bilangan ganjil. Lalu frekuensinya dapat ditentukan dengan $f = \frac{v}{\lambda} = n \frac{v}{4L}$.

Cara menghafal gelombang berdiri dengan kedua ujung terikat ini adalah $n-a$, yaitu _nodes_–antinodes.

  

## Gelombang Bunyi

### Gelombang Longitudinal

Gelombang bunyi dikategorikan sebagai gelombang longitudinal, _yak gitu doang, gw gak tau lagi mau nulis apa_

![[image 16.png]]

Gambar 16

Fungsi dari gelombang ini tetap sama dengan fungsi gelombang pada umumnya, namun ia memiliki dua fungsi yang berbeda, yaitu fungsi gelombang tekanan udara $\Delta p (x, t)$ dan fungsi gelombang simpangan elemen udara $s(x, t)$.

$$\Delta p (x, t) = \Delta p_m \sin(kx - \omega t + \phi_0) \\  
s(x, t) = s_m \sin(kx - \omega t + \phi_0)$$

### Kecepatan Rambat Gelombang Bunyi

$$v = \sqrt{\frac{B}{\rho}}$$

dengan $B$ sebagai Modulus Bulk dan $\rho$ sebagai rapat massa udara. Modulus Bulk didefinisikan sebagai $\displaystyle B = \frac{\Delta p}{\Delta V/V_0}$

### Intensitas Bunyi

Intensitas gelombang bunyi $I$ didefinisikan sebagai rata-rata energi bunyi yang dipancarkan per luas daerah. Sehingga, kita dapat menuliskan bahwa:

$$I = \frac{P}{A}$$

di mana $P$ adalah kekuatan rata-rata energi bunyi dan $A$ adalah luas daerah yang menerima bunyi. Intensitas bunyi juga berhubungan dengan simpangan amplitudo $s_m$ sehingga

$$I = \frac{1}{2}\rho v \omega^2 s_m^2$$

Sedangkan, untuk sumber bunyi yang mengemisikan suara secara isotropikal (simetri bola), yaitu intensitas yang sama ke semua arah, seperti pada **Gambar 17**, maka persamaannya akan menjadi:

$$I = \frac{P}{4\pi r^2}$$

![[image 17.png]]

Gambar 17

### Skala Desibel

Skala desibel adalah skala yang digunakan untuk mempermudah penyebutan skala suara berdasarkan intensitas referensi pendengaran manusia, dibandingkan harus menggunakan intensitas bunyi asli. Skala desibel dihitung menggunakan persamaan berikut:

$$\beta = (10 \text{ dB}) \log_{10}\frac{I}{I_0}$$

dengan $\beta$ sebagai tingkat intensitas (dB), $I$ sebagai intensitas bunyi (W/m$^2$) dan $I_0$ sebagai intensitas referensi ($10^{-12}$ W/m$^2$)

## Interferensi Gelombang Bunyi

Sama, seperti interferensi gelombang sebelumnya, Interferensi gelombang bunyi berlaku ketika terjadi superposisi dua buah gelombang yang memiliki amplitudo dan panjang gelombang yang sama, namun berbeda fasanya yang bergerak ke arah yang sama.

$$s_1(x, t) = s_m \cos(kx - \omega t) \\  
s_2 (x, t) = s_m \cos(kx - \omega t + \phi)$$

Jika dua gelombang ini _overlap_ dan berinterferensi, maka resultannya akan menjadi:

$$s' = \underbrace{[2s_m\cos(\frac{1}{2}\phi)]}_{\textsf{amplitudo}}\underbrace{\cos(kx - \omega t + \frac{1}{2}\phi)}_{\textsf{variabel osilasi}} \\  
s'_m = 2s_m\cos(\frac{1}{2}\phi)$$

![[image 18.png]]

Gambar 18

Fase pada superposisi gelombang ini, bergantung ke pada perbedaan panjang lintasan $\Delta L = |L_2-L_1|$. Perbedaan lintasan ini dapat kita relasikan dengan perbedaan fase dengan:

$$\frac{\Delta L}{\lambda} = \frac{\Delta \phi}{2\pi}$$

Interferensi konstruktif terjadi ketika $\cos(\frac{1}{2}\phi) = 1$, hal ini terjadi jika fasa $\phi = m 2\pi$ untuk $m = 0, 1, 2, \dots$. Sehingga, $\Delta L = m \lambda$.

Sedangkan, interferensi destruktif terjadi ketika $\cos(\frac{1}{2}\phi) = 0$, hal ini terjadi jika fasa $\phi = (2m+1)\pi$ untuk $m = 0, 1, 2, \dots$. Sehingga, $\Delta L = (m + \frac{1}{2})\lambda$.

## Efek Doppler

Efek Doppler adalah perubahan dari frekuensi yang diamati dari sebuah gelombang ketik sumber bunyi atau detektor bunyi bergerak relatif terhadap medium rambat. Persamaan umum dari efek ini ialah:

$$f' = f\frac{v \pm v_d}{v \pm v_s}$$

dengan $f'$ adalah frekuensi yang diamati, $f$ adalah frekuensi yang dipancarkan, $v$ adalah kecepatan suara dalam udara, $v_d$ adalah kecepatan detektor, dan $v_s$ adalah kecepatan sumber bunyi.

Ketika detektor atau sumber bunyi bergerak menuju satu sama lain, maka tanda pada kecepatan harus memberikan kenaikan pada frekuensi. Ketika detektor atau sumber bunyi bergerak menjauhi satu sama lain, maka tanda pada kecepatan harus memberikan penurunan pada frekuensi.

Atau dalam matematis dapat ditulis sebagai:

1. $v+v_d$ detektor mendekati sumber
2. $v-v_d$ detektor menjauhi sumber
3. $v-v_s$ sumber mendekati detektor
4. $v+ v_s$ sumber menjauhi detektor

![[image 19.png]]

Gambar 19