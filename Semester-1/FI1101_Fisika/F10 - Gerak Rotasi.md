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
    - [[#Besaran Gerak Rotasi]]
        - [[#Posisi Sudut]]
        - [[#Perpindahan Sudut]]
        - [[#Kecepatan Sudut]]
        - [[#Percepatan Sudut]]
    - [[#Gerak Rotasi Dengan Percepatan Konstan]]
    - [[#Hubungan Besar Gerak Rotasi dan Translasi]]
        - [[#Posisi Sudut]]
        - [[#Kecepatan Sudut]]
        - [[#Percepatan Sudut]]
    - [[#Energi Kinetik Rotasi]]
    - [[#Torsi]]
        - [[#Arah Torsi]]
        - [[#Hukum Newton II]]
    - [[#Usaha]]
    - [[#Hubungan Besar Gerak Rotasi dan Translasi (2)]]

## Referensi

---

- Buku Halliday
- PPT Gerak Rotasi Pak Arief

## 📝 Notes

---

## Besaran Gerak Rotasi

Gerak rotasi yang kita amati hanya pada benda tegar–yaitu benda yang tidak berubah bentuknya selama perputaran–yang sumbu putarnya tetap (tidak berubah).

### Posisi Sudut

$$\theta = \frac{s}{r}$$

dengan $\theta$ adalah posisi sudut, $s$ adalah panjang busur lingkaran, dan $r$ adalah jari-jari lingkaran.

Perlu dicatat bahwa 1 radian (rad) adalah $57,3\degree$dan 1 putaran adalah $2\pi$ radian atau $360\degree$.

### Perpindahan Sudut

$$\begin{align*}  
\Delta \theta &= \theta_f-\theta_i \\  
\Delta \theta &= \frac{\Delta s}{r}  
\end{align*}$$

Perpindahan sudut yang positif adalah perpindahan sudut yang mengikuti arah berlawanan jarum jam (_counterclockwise_/CCW). Sebaliknya, perpindahan sudut yang negatif adalah perpindahan sudut yang mengikuti arah jarum jam (_clockwise_/CW).

### Kecepatan Sudut

$$\begin{align*}  
\omega_{avg} &= \frac{\Delta \theta}{\Delta t} \\  
\omega &= \lim_{\Delta t \to 0} \frac{\Delta \theta}{\Delta t} = \frac{\mathrm{d}\theta}{\mathrm{d}t}  
\end{align*}$$

dengan $\omega$ (rad/s) melambangkan kecepatan sudut.

### Percepatan Sudut

$$\begin{align*}  
\alpha_{avg} &= \frac{\Delta \omega}{\Delta t} \\  
\alpha &= \lim_{\Delta t \to 0} \frac{\Delta \omega}{\Delta t} = \frac{\mathrm{d}\omega}{\mathrm{d}t}  
\end{align*}$$

dengan $\alpha$ (rad/s$^2$) melambangkan percepatan sudut.

Untuk melambangkan kecepatan sudut dan percepatan sudut sebagai vektor, kita dapat menggunakan kaidah tangan kanan untuk menentukan hal ini.

![[image.png]]

Gambar 1

## Gerak Rotasi Dengan Percepatan Konstan

|   |   |   |
|---|---|---|
|Variabel|Gerak Rotasi|Gerak Translasi|
|Posisi|$\theta = \theta_0 + \omega_0t + \frac{1}{2} \alpha t^2$|$x = x_0 + v_0t + \frac{1}{2}at^2$|
|Kecepatan|$\omega = \omega_0 + \alpha t$|$v = v_0 + at$|
|Percepatan|$\alpha$|$a$|
|Kecepatan-Posisi|$\omega^2 = \omega_0^2 + 2\alpha(\theta-\theta_0)$|$v^2 = v_0^2 + 2a(x-x_0)$|

## Hubungan Besar Gerak Rotasi dan Translasi

### Posisi Sudut

$$\begin{align*}  
\theta &= \frac{s}{r} \\  
s &= \theta r  
\end{align*}$$

### Kecepatan Sudut

Perhatikan bahwa dengan menurunkan persamaan posisi sudut di atas dengan waktu $t$, kita akan mendapat:

$$\begin{align*}  
\frac{ds}{dt} &= \frac{d\theta}{dt}r \\  
v_t &= \omega r  
\end{align*}$$

dengan $v_t$ adalah kecepatan tangensial, yaitu kecepatan yang bersinggungan dengan lingkaran di sekitar sumbu putar.

Dengan menganggap bahwa percepatan sudutnya konstan–sehingga kecepatan sudutnya juga konstan–maka kita dapat menentukan periode dari suatu putaran dengan:

$$\begin{align*}  
T &= \frac{2\pi r}{v} \\  
T &= \frac{2\pi}{\omega}  
\end{align*}$$

### Percepatan Sudut

Menurunkan persamaan posisi sudut dengan waktu $t$, maka kita akan mendapat:

$$\begin{align*}  
\frac{dv}{dt} &= \frac{d\omega}{dt}r \\  
a_t &= \alpha r  
\end{align*}$$

dengan $a_t$ adalah percepatan tangensial, yaitu percepatan yang bersinggungan dengan lingkaran di sekitar sumbu putar.

Setiap rotasi juga memiliki gaya sentripetal yang mengarah ke pusat rotasi yang membuat sebuah benda dapat berputar, sehingga didapat juga percepatan sentripetal.

$$a_r = \frac{v_2}{r} = \omega^2 r$$

![[image 1.png]]

Gambar 2

## Energi Kinetik Rotasi

Energi kinetik dari benda yang berotasi tidak dapat dihitung dari kecepatan linear pusat massanya menggunakan $K=\frac{1}{2}mv_{pm}^2$, karena kecepatan sudut pusat massanya adalah $0$. Oleh karena itu, kita harus meninjau setiap titik pada benda dan dihitung energi kinetik rotasinya.

$$\begin{align*}  
K = \frac{1}{2}m_1 v_1^2 + \frac{1}{2}m_2 v_2^2 + \dots + \frac{1}{2}m_n v_n^2 = \frac{1}{2} \left(\sum_{i=1}^nm_ir_i^2 \right)\omega^2  
\end{align*}$$

$\displaystyle \sum_{i=1}^n m_ir_i^2$ ini menyatakan bagaimana massa dalam benda yang berotasi terdistribusi di sumbu putarnya. Kita dapat menyebut besaran ini sebagai rotasi inersia atau momen inersia $I$ ($kg \cdot m^2$) dari suatu benda terhadap sumbu putarnya.

$$I = \sum_{i=1}^n m_ir_i^2$$

sehingga didapat,

$$K=\frac{1}{2}I\omega^2$$

Momen inersia ini menentukan ukuran sulit atau mudahnya memutar benda pada sumbu rotasi tertentu. Tentu saja, dalam suatu benda tegar, partikel penyusunnya sangat banyak bahkan mendekati tak hingga $\infty$. Maka, kita dapat menyusun persamaan momen inersia di atas menjadi

$$I = \int r^2 dm$$

dengan $dm$ menyatakan elemen massa pada benda. Dengan perhitungan dasar (_gak dasar-dasar banget sih, lihat Buku Halliday Hal. 300 aja pokoknya_), mendapatkan momen inersia di sembarang titik adalah

$$I = I_{pm} +Mh^2$$

dengan $I_{pm}$ sebagai momen inersia di pusat massa, $M$ adalah massa benda, dan $h$ adalah jarak titik sembarang dengan pusat massa.

![[image 2.png]]

Gambar 3

## Torsi

Torsi $\tau$ ($N \cdot m$) adalah putaran pada benda terhadap sumbu rotasi yang disebabkan oleh gaya. Untuk menghitung torsi terhadap titik $P$–posisinya relatif terhadap $O$ (dinotasikan dengan vektor $\vec r$)–yang dikenakan gaya $\vec F$ adalah

$$\vec \tau = \vec r \times \vec F$$

Untuk menghitung $\tau$, kita harus menggunakan cross product, sehingga $\vec r$ dan $\vec F$ harus tegak lurus. Sehingga, untuk menghitungnya dapat digunakan dua cara, yaitu

![[image 3.png]]

Gambar 4

Pada **Gambar 5** kita memecah $\vec F$ menjadi $\vec F_t$ yang melambangkan gaya tangensial dan $\vec F_r$ yang menggambarkan gaya sentripetal.

Persamaannya menjadi $\tau = r \cdot (F\sin\phi)$

![[image 4.png]]

Gambar 5

Pada **Gambar 6**, kita memperpanjang garis gaya $\vec F$ menjadi garis kerja gaya dan garis $\vec r$ menjadi _moment arm of $\vec F$_ yang dinamakan $r_\bot$

Persamaannya menjadi $\tau = (r \sin \phi) \cdot F$

Selanjutnya, jika diberikan gaya lebih dari satu terhadap suatu benda, maka kita harus menghitung resultan torsinya $\tau_{total}$ untuk menentukan arah torsinya.

### Arah Torsi

Arah torsi bisa ditentukan dengan menggunakan kaidah tangan kanan dengan jari jempol sebagai $\vec r$, jari telunjuk sebagai $\vec F$, dan jari tengah sebagai $\vec\tau$

### Hukum Newton II

Kita dapat mengaplikasikan Hukum Kedua Newton pada torsi.

$$\tau_{net}=I\alpha$$

## Usaha

Seperti pada Bab Usaha dan Energi, kita dapati bahwa $\Delta K = W$ di mana $\displaystyle W = \int_{x_i}^{x_f}F \ dx$. Untuk menghitung usaha pada gerak rotasi, kita dapat menghitungnya dengan.

$$\Delta K = K_f-K_i = \frac{1}{2}I\omega_f^2 - \frac{1}{2} \omega_i^2=W \\  
W = \int_{\theta_i}^{\theta_f} \tau \ d\theta$$

Jika, $\tau$ konstan, maka $W = \tau(\theta_f-\theta_i)$ dan dayanya dapat dihitung sebagai berikut

$$P= \frac{dW}{dt}=\tau\omega$$

## Hubungan Besar Gerak Rotasi dan Translasi (2)

![[image 5.png]]

Gambar 6