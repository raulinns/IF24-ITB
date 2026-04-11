---
Note Type: Notes
Done: true
Date: 2025-04-01
Last edited time: 2025-09-01T18:01
tags: Fisika
---
- Quick Access
    - [[#Referensi]]
    - [[#📝 Notes]]
    - [[#Pendahuluan]]
    - [[#Gaya dan Energi pada Gerak Menggelinding]]
        - [[#Gaya]]
        - [[#Energi]]
    - [[#Momentum Sudut]]
        - [[#Kekekalan Momentum Sudut]]

## Referensi

---

- Buku Halliday
- PPT Gerak Menggelinding Pak Arief

## 📝 Notes

---

## Pendahuluan

Gerak menggelinding (sempurna) adalah gabungan dari gerak translasi dan gerak rotasi tanpa mengalami slip. Agar benda tidak slip, maka kecepatan di titik kontak permukaan benda dengan tanah adalah nol. Sehingga besar kecepatan rotasi harus sama dengan besar kecepatan translasi.

![[image 7.png|image 7.png]]

Gambar 1

Gerak rotasi yang dialami oleh benda bergerak dengan kecepatan sudut yang sama. Titik pada pinggir benda juga bergerak dengan kecepatan pusat massanya. Gerak translasi yang dialami oleh benda bergerak dengan kecepatan translasi yang sama, yaitu kecepatan pusat massanya.  

![[image 1 3.png|image 1 3.png]]

Gambar 2

Pada gerak menggelinding sempurna, terdapat hubungan antara variabel translasi dan variabel rotasi

$$\begin{align*}  
s &= \theta R \\  
v_{pm} &= \omega R \\  
a_pm &= \alpha R  
\end{align*}$$

dengan R adalah jari-jari dari benda tegar.

## Gaya dan Energi pada Gerak Menggelinding

### Gaya

Saat gaya eksternal $F$ membuat benda menggelinding sempurna, titik paling bawah selalu bekerja gaya kinetik statis $f_s$ dengan arah berlawanana dengan percepatan pusat massa. Jika, benda menggelinding dengan slip (tidak sempurna), maka gaya yang bekerja adalah gaya kinetik kinetis.

Resultan gaya $F$ dan $f_s$ akan menghasilkan percepatan pusat massa dan torsi dari gaya gesek $f_s$ menghasilkan percepatan sudut.

Pada lintasan miring, benda akan bergerak menggelinding dengan percepatan pusat massa dan percepatan sudut. Sedangkan, pada lintasan lurus, benda akan bergerak menggelinding dengan kecepatan pusat massa dan kecepatan sudut konstan

### Energi

Jika tidak ada gaya eksternal dan gaya nonkonservatif yang bekerja pada sistem, maka berlaku kekekalan energi mekanik.

$$EM = K_{\textsf{translasi}} +K_{\textsf{rotasi}}+U$$

dengan $K$ adalah energi kinetik dan $U$ adalah energi potensial.

## Momentum Sudut

Momentum sudut $\vec l$ adalah ukuran gerak rotasi benda terhadap sumbu rotasinya.

$$\vec l = \vec r \times \vec p = m(\vec r \times \vec v)$$

Untuk menghitung momentum sudut $\vec l$ kita menggunakan cross product, sehingga $\vec r$ dan $\vec p$ harus tegak lurus. Untuk menghitungnya kita dapat menggunakan cara yang sudah dibahas di **F10 - Gerak Rotasi Subbab Torsi**. Untuk menentukan arahnya, kita gunakan kaidah tangan kanan dengan $\vec r$ sebagai jari telunjuk, $\vec p$ sebagai jari tengah, dan $\vec l$ sebagai jari jempol.

Untuk sistem partikel, kita dapat menghitung momentum sudut dari benda dengan

$$\begin{align*}  
\vec L &= \vec l_1 + \vec l_2 + \dots +\vec l_n \\  
&= \sum_{i=1}^n l_i \\  
&= \sum_{i=1}^nm_i v_i r_{\bot i} \\  
&= \sum_{i=1}^nm_i (\omega r_{\bot i}) r_{\bot i} \\  
&= \omega \sum_{i=1}^n m_i r_{\bot i}^2 \\  
\vec L &= I \omega  
\end{align*}$$

Sama seperti total gaya yang diberikan seimbang dengan perubahan momentum linear terhadap waktu. total torsi yang diberikan juga seimbang dengan perubahan momentum sudut terhadap waktu

$$\vec \tau_{total} = \frac{d\vec L}{dt}$$

### Kekekalan Momentum Sudut

Jika tidak ada torsi eksternal $\tau$ yang diberikan pada sistem, maka momentum sudut dari sistem tersebut, maka berlaku kekekalan momentum sudut $\vec L$

$$\begin{align*}  
\vec L_i &= \vec L_f \\  
I_i \vec\omega_i &= I_f \vec\omega_f  
\end{align*}$$