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
    - [[#Fluida]]
    - [[#Fluida Statis]]
    - [[#Pengukuran Tekanan]]
        - [[#Barometer]]
        - [[#Barometer Merkuri]]
        - [[#Manometer Tabung Terbuka]]
    - [[#Prinsip Pascal]]
    - [[#Prinsip Archimedes]]
        - [[#Berat Semu]]
    - [[#Fluida Dinamis]]
    - [[#Prinsip Kontinuitas]]
    - [[#Prinsip Bernoulli]]

## Referensi

---

- Buku Halliday
- PPT Fluida Pak Arief

## 📝 Notes

---

## Fluida

Fluida adalah materi yang dapat terus bergerak dan mengalami deformasi (mengalir). Fluida mengikuti batasan pada tempat fluida disimpan. Secara Fisika, dikatakan bahwa fluida memiliki **Modulus Shear** $G =0$.

Pada benda padat, kita dapat mengatakan bahwa mekanika benda padat memiliki massa $m$ (kg) dan dapat dikenakan gaya $F$ (N). Sedangkan, pada fluida, mekanika benda ini memiliki rapat massa $\rho = \frac{m}{V}$ (kg/m$^3$) dan dapat dikenakan tekanan $P = \frac{F}{A}$ (N/m$^2$)

Tekanan dapat dinyatakan dalam satuan SI-nya, yaitu $N/m^2$ yang dinamakan sebagai pascal (Pa). Namun, tekanan juga dapat dinyatakan dalam satuan non-SI sebagai berikut.

$$1 \text{ atm} = 1.01 \times 10^5 \text{ Pa} = 760 \text{ torr}$$

![[image 24.png|image 24.png]]

Gambar 1

## Fluida Statis

Pada suatu sampel balok air dalam suatu kontainer, kita dapat melihat bahwa terdapat tiga gaya yang bekerja pada suatu sampel tersebut.

![[image 1 13.png|image 1 13.png]]

Gambar 2

Lalu, karena fluida ini statis (tidak bergerak), maka berlaku persamaan $\sum F=0$. Sehingga,

$$F_2 = F_1 +mg$$

di mana $F = pA$ dan $m = \rho V$ yang mana $V = A (y_1-y_2)$ di mana $A$ adalah luas daerah alasnya dan $y$ melambangkan ketinggian dari permukaan air. Substitusikan variabel-variabel di atas, maka kita mendapatkan:

$$p_1 A = p_2 A + \rho [A(y_1-y_2)]g$$

Jika kita pilih $y_1$ sebagai ketinggian pada permukaan air ($y = 0$) dan $y_2$ kita notasikan sebagai kedalaman dari permukaan air $h$, maka tekanan $p_1$ juga bergantung pada ketinggiannya, yaitu $p_0 =0$ dan tekanan $p_2$ kita notasikan sebagai tekanan yang akan dihitung $p$, maka kita dapat tulis ulang persamaan sebagai

$$p = p_0 + \rho_{\text{air}}gh$$

Dari persamaan ini, dapat disimpulkan bahwa semakin bertambah kedalaman, maka tekanan hidrostatis juga akan semakin besar. Sebaliknya, jika kita menghitung tekanan di atas permukaan air (udara), maka semakin bertambah ketinggian, tekanan hidrostatisnya akan semakin kecil.

$$p = p_0 - \rho_{\text{udara}}gh$$

## Pengukuran Tekanan

### **Barometer**

![[image 2 11.png|image 2 11.png]]

Gambar 3

Pada barometer ini kita dapat menghitung tekanan atmosfer $p_0$. Tekanan pada ruang vakum mendekati 0 $p \approx 0$, maka dengan menghitung tekanan di titik tersebut, kita mendapatkan persamaan

$$\begin{align*}  
0 &= p_0 - \rho gh \\  
p_0 &= \rho_f gh  
\end{align*}$$

$p_0$ sebagai tekanan atmosferw

### Barometer Merkuri

Merkuri atau air raksa (Hg) dapat digunakan untuk menghitung tekanan pula. Dari percobaan Torricelli, didapatkan apabila tabung digerakkan, air raksa pada tabung tetap akan berada 760 mm dari permukaan air raksa pada wadah.

![[image 3 11.png|image 3 11.png]]

Gambar 4

Oleh karena itu, satuan ini dinamakan mmHg, atau milimeter pada air raksa

### Manometer Tabung Terbuka

![[image 4 11.png|image 4 11.png]]

Gambar 5

Untuk menghitung tekanan gauge $p_g$ dari gas pada kontainer, kita dapat menghitungnya dengan menganggap $y_1 = 0$, $y_2 =-h$, dan tekanan pada titik 2 adalah $p$. Maka, kita akan mendapatkan:

$$p_g= p-p_0 = \rho gh$$

## Prinsip Pascal

Perubahan tekanan yang diberikan pada fluida _incompressible_ dalam kontainer tertutup akan diteruskan pada setiap bagian fluida dan seluruh dinding kontainer.

![[image 5 11.png|image 5 11.png]]

Gambar 6

$$\Delta P = \frac{F_i}{A_i}=\frac{F_o}{A_o}$$

Kontainer tertutup pada Percobaan Prinsip Pascal ini menjamin bahwa volume dari fluida tetap. Maka,

$$V = A_id_i=A_od_o$$

Kerja yang dilakukan akan berpengaruh terhadap piston output $W = F_od_o$. Namun, dengan menuliskannya ulang, kita akan mendapat bahwa kerja yang diberikan terhadap piston output sama terhadap kerja yaang diberikan kepada piston input

$$W=F_od_o=\left(A_o\frac{F_i}{A_i}\right)\left(d_i\frac{A_i}{A_o}\right)=F_id_i$$

## Prinsip Archimedes

Saat sebuah benda tenggelam seluruh atau sebagian, terdapat gaya angkat $\vec F_b$ dengan arah ke atas besarnya sebanding dengan massa fluida yang dipindahkan. Besaran gaya angkat ini setara dengan berat dari fluida $W_f$.

$$F_b= W_f = m_fg$$

dengan $m_f$ adalah massa dari fluida.

![[image 6 11.png|image 6 11.png]]

Gambar 7

Benda akan melayang, jika $F_a = F_g$.

![[image 7 9.png|image 7 9.png]]

Gambar 8

Benda akan tenggelam, jika $F_a <F_g$.

![[image 8 8.png|image 8 8.png]]

Gambar 9

Benda akan terapung, jika $F_a>F_g$

### Berat Semu

![[image 9 6.png|image 9 6.png]]

Gambar 10

$$\textsf{Berat semu}= \textsf{Berat sebenarnya} - \textsf{Gaya angkat} \\  
W_{\text{semu}} = W-F_a$$

## Fluida Dinamis

Untuk mempermudah perhitungan, kita akan menganggap bahwa fluida dinamis yang ditinjau berupa aliran fluida ideal. Asumsi pada aliran fluida ideal adalah:

1. _Steady flow_: Kecepatan setiap titik di fluida sama setiap waktunya
2. _Incompressible flow_: Rapat massa fluida bernilai tetap atau konstan
3. Nonviscous flow: Tidak mengalami gaya hambatan akibat viskositas (kekentalan) fluida
4. _Irrotational flow_: Tidak berotasi pada sebuah sumbu putar

## Prinsip Kontinuitas

Pada **Gambar 11**, arus volume per detik yang masuk pada sisi kiri selang, akan sama dengan arus volume per detik pada ujung kanan selang.

![[image 10 5.png|image 10 5.png]]

Gambar 11

  

![[image 11 5.png|image 11 5.png]]

Gambar 12

Pada **Gambar 12**, elemen volume $\Delta V$ yang mengalir pada waktu $t$ dari garis putus-putus pada selang waktu $\Delta t$ adalah

$$\Delta V = A\Delta x = Av\Delta t$$

dengan $v$ sebagai kecepatan elemen fluida. Dengan mengaplikasikan persamaan ini pada **Gambar 11** di ujung kiri dan ujung kanan pipa, maka didapat

$$\Delta V = A_1 v_1 \Delta t = A_2 v_2 \Delta t$$

atau $A_1 v_1 = A_2 v_2$. Persamaan ini yang disebut persamaan kontinuitas. \

Persamaan ini juga dapat dinyatakan dalam volume per detik atau biasa disebut _Volumetric flowrate_ (debit) fluida $Q$ atau $R_v$ dapat dinyatakan dalam $\displaystyle R_v = \frac{\Delta V}{\Delta t} = Av$. Debit ini menyatakan volume yang mengalir per detik (m$^3$/s).

_Ada pula, mass flowrate_ fluida dapat dinyatakan dalam $\displaystyle R_m =\frac{\Delta m}{\Delta t} = \rho Av$. _Mass flowrate_ ini menyatakan massa yang mengalir per detik (kg/s).

## Prinsip Bernoulli

Ambil **Prinsip Kontinuitas** pada subbab sebelumnya dan terapkan perbedaan ketinggian pada kedua selang.

![[71caabb2-1288-44f3-b6d7-563463009f71.png]]

Gambar 13a

![[image 12 4.png|image 12 4.png]]

Gambar 13b

Pada **Gambar 13**, dengan interval waktu $\Delta t$, elemen volume $\Delta V$ memasuki pipa pada sisi kiri (berwarna biru) dan berakhir dengan volume yang identik di sisi kanan (berwarna hijau). Di sini kita akan terapkan kekekalan energi untuk fluida.

$$W_F = EM_1 - EM_2 \\  
W_F = \Delta F s = \Delta p A s = (p_2-p_1)V$$

Dengan menggabungkan kedua persamaan di atas, maka kita mendapatkan kekekalan energi dalam aliran fluida.

$$(p_2 - p_1)V = EM_1 - EM_2\\  
(p_2-p_1)V = \left(\frac{1}{2} m v_1^2 + mgy_1\right) - \left(\frac{1}{2} m v_2^2 + mgy_2\right)$$

Bagi kedua ruas dengan volume $V$, maka didapat:

$$p_2-p_1 = \left(\frac{1}{2} \rho v_1^2 + \rho gy_1\right) - \left(\frac{1}{2} \rho v_2^2 + \rho gy_2\right)$$

Dengan menyusun ulang persamaan ini, maka didapat **Persamaan Bernoulli**

$$p_1 + \frac{1}{2} \rho v_1^2 + \rho g y_1 = p_2 + \frac{1}{2} \rho v_2^2 + \rho g y_2$$

Apabila ketinggian dari fluida sama $y_1 = y_2$, maka persamaannya dapat kita ubah menjadi:

$$p_1 + \frac{1}{2} \rho v_1^2 = p_2 + \frac{1}{2} \rho v_2^2$$

Lalu, dengan menerapkan **Persamaan Kontinuitas** $A_1 v_1 = A_2 v_2$

$$p_1 + \frac{1}{2} \rho v_1^2 = p_2 + \frac{1}{2} \rho \left(\frac{A_1}{A_2} \right)^2 v_1^2 \\  
\frac{1}{2}\rho \left( \frac{A_1^2}{A_2^2}-1\right)v_1^2 = p_1 - p_2 \\  
v_1 = \sqrt{\frac{2(p_1 - p_2)A_2^2}{\rho (A_1^2-A_2^2)}}$$