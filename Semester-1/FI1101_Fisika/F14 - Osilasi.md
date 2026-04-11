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
    - [[#Osilasi Harmonik Sederhana]]
        - [[#Kecepatan dan Percepatan pada SHM]]
    - [[#Gaya pada SHM]]
    - [[#Energi pada SHM]]
    - [[#Sistem Osilasi Harmonik Sederhana]]
        - [[#Bandul Matematis]]
        - [[#Bandul Fisis]]
    - [[#Osilasi Harmonik Teredam]]
    - [[#Osilasi Harmonik Terpaksa]]

## Referensi

---

- Buku Halliday
- PPT Osilasi Pak Arief

## 📝 Notes

---

## Osilasi Harmonik Sederhana

Osilasi harmonik sederhana (_simple harmonic motion_/SHM) adalah gerakan berulang (periodik terhadap waktu) terhadap titik kesetimbangan dengan fungsi posisi berupa fungsi sinusoidal (sinus/cosinus). Osilasi harmonik sederhana memiliki fungsi posisi, yaitu

$$x(t) =x_m\cos(\omega t + \phi)$$

dengan $x(t)$ sebagai posisi pada waktu $t$, $x_m$ sebagai jarak maksimum (amplitudo). $\omega$ sebagai frekuensi sudut/angular, dan $\phi$ adalah konstanta fase awal

![[image 8.png|image 8.png]]

Gambar 1

Sebuah gerakan osilasi memiliki **frekuensi**, yaitu jumlah gerakan osilasi per detik. Frekuensi memiliki satuan hertz (Hz) atau setara dengan per sekon ($s^{-1}$).

Sedangkan, waktu yang diperlukan untuk melakukan satu gerakan osilasi penuh disebut periode $T$ dengan satuan sekon $s$.

$$T=\frac{1}{f}$$

Kita lihat bahwa, jika kita memasukkan $t = 0$ pada posisi waktu, maka kita dapat mengetahui bahwa ketika fase awalnya $\phi = \pi$, kita akan mendapatkan nilai fungsi posisi berada pada $-x_m$. Beberapa nilai $\phi$ juga dapat kita masukkan dan kita akan mendapatkan nilai sebagai berikut.

![[image 1 4.png|image 1 4.png]]

Gambar 2

Sebuah periode pada waktu tertentu $t$, akan berada pada posisi yang sama pada waktu tersebut ditambah dengan periodenya $t +T$.

$$\begin{align*}  
x(t) &= x(t+T) \\  
x_m \cos (\omega t + \phi) &= x_m \cos (\omega (t+T) + \phi) \\  
\end{align*}$$

Lalu, dengan menganggap waktu $t= 0$ dan fase awalnya $\phi = 0$. Tak lupa juga bahwa fungsi cosinus berada pada fase awalnya kembali pada $2\pi$ rad. Maka, kita dapat menuliskan persamaannya menjadi

$$\begin{align*}  
\omega t + 2\pi &= \omega(t+T) \\  
2\pi &= \omega T \\  
\omega &= \frac{2\pi}{T}  
\end{align*}$$

Atau, dengan substitusi $T = \frac{1}{f}$, kita akan mendapat

$$\omega = \frac{2\pi}{T}= 2\pi f$$

Satuan dari frekuensi angular $\omega$ adalah radian per sekon.

Fungsi cosinus ini dapat kita kaji lagi lebih dalam secara kuantitasnya dengan bermain dengan frekuensi atau periode, amplitudo, dan fase awalnya.

![[image 2 3.png|image 2 3.png]]

Gambar 3

![[image 3 3.png|image 3 3.png]]

Gambar 4

![[image 4 3.png|image 4 3.png]]

Gambar 5

  

### Kecepatan dan Percepatan pada SHM

Untuk menentukan kecepatan, kita turunkan fungsi posisi terhadap waktu:

$$v(t) = \frac{dx(t)}{dt}=\frac{d}{dt}[x_m\cos(\omega t + \phi)] \\  
v(t) = -\omega x_m \sin(\omega t + \phi)$$

Sedangkan, untuk percepatan, kita turunkan fungsi kecepatan terhadap waktu:

$$a(t) = \frac{dv(t)}{dt}=\frac{d}{dt}[-\omega x_m \sin(\omega t + \phi)]\\  
a(t) = -\omega^2 x_m \cos(\omega t +\phi) \\  
a(t) = -\omega^2x(t)$$

## Gaya pada SHM

Berlaku Hukum Kedua Newton pada osilasi harmonik sederhana, sehingga

$$F = ma = m(-\omega^2x) = -m\omega^2x$$

![[image 5 3.png|image 5 3.png]]

Gambar 6

Dalam **Gambar 6**, berlaku juga Hukum Hooke $F=-kx$, maka kita dapat menyimpulkan bahwa

$$\begin{align*}  
-kx &=-m\omega^2x \\  
k &= m\omega^2 \\  
\omega &= \sqrt{\frac{k}{m}}  
\end{align*}$$

Lalu, dengan substitusi $\omega$ ke persamaan periode $T$, kita akan mendapatkan

$$T = \frac{2\pi}{\omega} \\  
T=2\pi\sqrt{\frac{m}{k}}$$

## Energi pada SHM

Seperti pada **Gambar 6**, berlaku juga persamaan energi potensial ($U =\frac{1}{2}kx^2$) yang berasosiasi sepenuhnya terhadap pegas. Nilai energi potensial ini bergantung kepada seberapa banyak pegas diregangkan atau dikompresi ($x(t)$). Dengan mengimplementasikan fungsi posisi osilasi harmonik sederhana, persamaannya akan menjadi:

$$U(t)=\frac{1}{2}kx(t)^2 = \frac{1}{2}kx_m^2\cos^2(\omega t + \phi)$$

Pada **Gambar 6**, juga berlaku persamaan energi kinetik ($K = \frac{1}{2}mv^2$) yang berasosiasi sepenuhnya terhadap balok. Nilai energi kinetik ini bergantung kepada seberapa cepat balok bergerak ($v(t)$). Dengan mengimplementasikan fungsi kecepatan osilasi harmonik sederhana, persamaannya dan mensubtitusikan $\omega^2 = \frac{k}{m}$ akan menjadi:

$$K(t)=\frac{1}{2}mv(t)^2=\frac{1}{2}m\omega^2 x_m^2 \sin^2(\omega t + \phi) = K(t)=\frac{1}{2}mv(t)^2= \frac{1}{2}k x_m^2 \sin^2(\omega t + \phi)$$

Sehingga, energi mekaniknya $EM$ akan menjadi

$$\begin{align*}  
EM(t)=U(t) + K(t) &= \frac{1}{2}kx_m^2\cos^2(\omega t + \phi) + \frac{1}{2}k x_m^2 \sin^2(\omega t + \phi) \\  
&= \frac{1}{2}kx_m^2[\cos^2(\omega t + \phi) + \sin^2(\omega t + \phi)] \\  
&= \frac{1}{2}kx_m^2  
\end{align*}$$

## Sistem Osilasi Harmonik Sederhana

### Bandul Matematis

Bandul matematis terbentuk dari benda bermassa $m$ yang terhubung tali tidak bermassa dan tidak dapat teregang dengan panjang $L$. Tali ini terikat pada suatu titik poros. Benda ini dapat berayun kiri ke kanan dari garis vertikal yang dengan titik porosnya.

![[image 6 3.png|image 6 3.png]]

Gambar 7

![[image 7 2.png|image 7 2.png]]

Gambar 8

  

Gaya yang bekerja pada benda adalah gaya tegangan tali $\vec T$ dan gaya gravitasi $\vec F_g$ yang tegak lurus dengan permukaan bumi. Setelah memecah $\vec F_g$ menjadi $F_g\sin\theta$ dan $F_g \cos \theta$. Gaya yang tegak lurus dengan tali $L$ adalah $F_g \sin \theta$. Gaya yang tegak lurus ini yang menghasilkan torsi yang mengembalikan benda kepada titik ekuilibriumnya ($\theta = 0$). Sehingga:

$$\tau = rF_\bot = -L(F_g\sin\theta)$$

Tanda negatif menunjukkan bahwa torsi bekerja untuk mengurangi $\theta$. Lalu, dengan mensubtitusikan persamaan di atas ke $\tau = I\alpha$, kita akan mendapatkan:

$$-L(mg\sin\theta) =I\alpha \\  
\alpha = -\frac{mgL\sin\theta}{I}$$

Untuk sudut yang sangat kecil ($\theta \le 15\degree$), maka $\sin \theta \approx \theta$.

$$\alpha = \frac{-mgL}{I}\theta$$

Lalu, dengan mensubtitusikan persamaan di atas dengan persamaan percepatan osilasi harmonik sederhana $a(t) = -\omega^2x(t)$, kita dapat menganggap fungsi posisi $x(t)$ sebagai fungsi sudut $\theta(x)$. Sehingga, kita akan mendapatkan:

$$-\frac{mgL}{I}\theta = -\omega^2\theta \\  
\omega = \sqrt{\frac{mgL}{I}}$$

Lalu, subtitusikan $\omega$ dengan persamaan $\omega = \frac{2 \pi}{T}$, maka kita akan mendapatkan bahwa periode adalah:

$$T = 2\pi\sqrt{\frac{I}{mgL}}$$

Kita dapat mensimplifikasi persamaan ini dengan mensubtitusikan momen inersia pada benda titik $I=mr^2$, maka persamaannya akan menjadi:

$$T = 2\pi \sqrt{\frac{L}{g}}$$

### Bandul Fisis

Perbedaan dari bandul matematis dan bandul fisis ialah benda yang digantung pada bandul memiliki distribusi massa yang lebih kompleks. Namun, untuk menghitung percepatan, kecepatan angular, dan periode dari bandul fisis ini, kita tetap menggunakan metode yang sama seperti bandul matematis.

![[image 8 2.png|image 8 2.png]]

Gambar 9

Torsi di pusat massa $\tau = -mgh\sin\theta= I \alpha$, maka

$$\alpha = -\frac{mgh}{I}\theta$$

dan frekuensi angularnya adalah

$$\omega = \sqrt{\frac{mgh}{I}}$$

,serta periode osilasinya adalah

$$T=2\pi \sqrt{\frac{I}{mgh}}$$

Namun, berbeda dengan bandul matematis, untuk mengubah periodenya kita harus memperhatikan momen inersia massanya (dimensi, titik pusat massa, massa, dan lain-lain)

## Osilasi Harmonik Teredam

Ketika gerakan osilasi harmonik berkurang karena adanya gaya eksternal, maka osilator dan gerakannya disebut **teredam**.

![[image 9.png]]

Gambar 10

Pada **Gambar 10**, balok dengan massa $m$ berosilasi secara vertikal pada pegas dengan konstanta pegas $k$. Balok tersebut kemudian diperpanjang menggunakan sebuah batang dan baling-baling yang tenggelam dalam air. Ketika balok berosilasi naik-turun, baling-baling ini juga berosilasi dan memberikan gaya redaman pada sistem. Sehingga energi mekanik pada sistem balok-pegas menurun. Gaya redaman $\vec F_d$ ini dapat dihitung dengan

$$F_d = -bv$$

dengan $b$ sebagai konstanta redam (kg/s) dan tanda negatif pada persamaan menandakan $\vec F_d$ berbeda arah dengan gerakan.

Diasumsikan bahwa gaya gravitasi dapat diabaikan relatif terhadap gaya redaman $F_d$ dan gaya pegas $F_s$. Lalu, dengan memasukkan $F_d$ dan $F_s$ pada Hukum Kedua Newton, maka didapat:

$$\begin{align*}  
F_d + F_s &= ma \\  
-bv -kx &= ma  
\end{align*}$$

Lalu, dengan mensubtitusikan $v = \frac{dx}{dt}$, $a =\frac{d^2x}{dt^2}$, dan menyusunnya kembali, kita akan mendapatkan persamaan diferensial:

$$m\frac{d^x}{dt^2}+b\frac{dx}{dt}+kx=0$$

yang mana solusinya adalah:

$$x(t)=x_me^{-bt/2m}\cos(\omega'f +\phi)$$

di mana $x_m$ adalah amplitudonya dan $\omega'$ adalah frekuensi angular osilasinya. $\omega'$ dapat dicari menggunakan:

$$\omega' = \sqrt{\frac{k}{m}-\frac{b^2}{4m^2}}$$

![[image 10.png]]

Gambar 11

**Gambar 11** menunjukkan grafik fungsi posisi dari osilasi harmonik yang teredam, di mana amplitudonya $x_me^{-bt/2m}$berkurang secara eksponensial beriringan dengan bertambahnya waktu $t$.

Sedangkan, energi osilasi teredamnya, untuk redaman yang kecil, kita dapat mencari $E(t)$ dengan:

$$E(t)=\frac{1}{2}kx^2_.e^{-bt/2m}$$

Persamaan ini berarti energi dari osilasi harmonik yang teredam berkurang beriringan dengan bertambahnya waktu.

## Osilasi Harmonik Terpaksa

Ketika gerakan osilasi harmonik bertambah karena adanya gaya eksternal, maka osilator dan gerakannya disebut **terpaksa**.

![[image 11.png]]

Gambar 12

Pada **Gambar 12**, balok dengan massa $m$ berosilasi secara vertikal pada pegas dengan konstanta pegas $k$. Balok tersebut kemudian digerakkan oleh gaya eksternal atau yang disebut gaya penggerak/_driving force_ $F_D$. Pada osilasi harmonik terpaksa ini, titik tumpu (_rigid support_) yang biasanya diam, dibuat naik-turun dalam variabel frekuensi angular $\omega_d$. Sehingga jika kita menggunakan Hukum Kedua Newton, maka akan didapat:

$$\begin{align*}  
F_s+F_d+F_D &= ma \\  
-kx -bv + F_0\cos(\omega_Dt) &= ma \\  
m\frac{d^x}{dt^2}+b\frac{dx}{dt}+kx &= F_0\cos(\omega_Dt)  
\end{align*}$$

yang mana solusi dari persamaan diferensial di atas adalah

$$x(t)= x_m\cos(\omega_D t + \phi)$$

Seperti yang kita ketahui sebelumnya, bahwa frekuensi alami sistem dinyatakan dalam $\omega_0 = \sqrt{\frac{k}{m}}$, amplitudo maksimal (diaproksimasikan) dan kecepatan amplitudonya maksimal ketika kecepatan angular terpaksanya sama dengan kecepatan angular sistem ($\omega_D = \omega_0$). Ketika hal ini terjadi, kondisi ini disebut resonansi.