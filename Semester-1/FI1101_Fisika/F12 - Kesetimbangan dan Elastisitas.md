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
    - [[#Kesetimbangan]]
    - [[#Elastisitas]]

## Referensi

---

- Buku Halliday
- PPT Kesetimbangan dan Elastisitas Pak Arief

## 📝 Notes

---

## Kesetimbangan

Suatu sistem benda dikatakan dalam keadaan setimbang apabila:

1. Momentum linear titik pusat massa konstan $\vec P= \textsf{konstan}$
2. Momentum sudut titik pusat massa konstan $\vec L = \textsf{konstan}$

Untuk memenuhi kedua syarat kesetimbangan, kita dapat meninjaunya berdasarkan gaya dan torsi.

$$\begin{align*}  
\vec P \textsf{ konstan} &\to \frac{d\vec P}{dt} = 0 = \vec F_{\textsf{total}} \\  
\vec L \textsf{ konstan} &\to \frac{d\vec L}{dt} = 0 = \vec \tau_{\textsf{total}}  
\end{align*}$$

Sehingga, dapat dikatakan bahwa kesetimbangan benda tegar dipengaruhi oleh gaya dan torsinya, sehingga untuk suatu benda setimbang, maka harus berlaku kesetimbangan gaya dan kesetimbangan torsi.

Ketika gaya dan torsi pada benda adalah nol, tentu saja ini berlaku untuk tiga sumbu koordinatnya $\sum \vec F_x$, $\sum \vec F_y$, $\sum \vec F_z$, $\sum \vec \tau_x$, $\sum \vec \tau_y$, dan $\sum \vec \tau_z$. Namun, untuk simplifikasi, maka kita hanya perlu memikirkan tentang gaya pada sumbu $x$ dan $y$ yang akan membuat torsi bekerja ke arah sumbu $z$.

## Elastisitas

Sebuah benda padat terdiri dari susunan atom-atom yang saling terhubung melalui gaya antar atom yang seperti pegas. Benda padat dapat diubah bentuk/dimensinya (deformasi) ketika diberikan gaya pada benda. Terdapat dua karakteristik dalam sebuah deformasi, yakni **tegangan (**_**stress**_**)** yang menghasilkan ukuran deformasi **regangan (**_**strain)**_. Ada tiga jenis deformasi berdasarkan arah tegangan:

1. Tension stress di mana gaya yang diberikan tegak lurus terhadap permukaan
2. Shear stress di mana gaya yang diberikan sejajar terhadap permukaan
3. Hydraulic stress di mana gaya yang diberikan berada ke semua arah permukaan

![[image 20.png|image 20.png]]

Gambar 1

Proporsi dari tegangan dan regangan akan mendapatkan nilai modulus elastisitas.

$$\textsf{stress} = \textsf{modulus} \times \textsf{strain} \\  
\textsf{stress} = \frac{F}{A} \\  
\textsf{strain} = \frac{\Delta L}{L_0}$$

dengan $F$ adalah gaya yang diberikan, $A$ adalah luas daerah, $\Delta L$ adalah perubahan panjang dan $L_0$ adalah panjang awal

Untuk interval tegangan yang diberikan tertentu, hubungan tegangan-regangan linear dan benda kembali ke dimensi semulanya setelah tegangannya hilang. Namun, jika tegangan yang diberikan berada di atas _yield strength_ $S_y$, maka deformasi yang terjadi akan permanan dan apabila tegangannya terus bertambah hingga mencapai _ultimate strength_ $S_u$, maka benda akan hancur.

![[image 1 9.png|image 1 9.png]]

Gambar 2

Untuk _tension stress_, modulus yang kita gunakan disebut **Modulus Young** $E$. Modulus ini mengukur respons dari benda terhadap gaya tekan/tarik. Sehingga, persamaan di atas akan menjadi

$$\frac{F}{A}=E\frac{\Delta L}{L}$$

Sedangkan, untuk _shearing stress_, modulus yang kita gunakan adalah **Modulus Shear** $G$. Modulus ini mengukur respons dari benda terhadap gaya geser. Sehingga, persamaan di atas menjadi

$$\frac{F}{A}=G\frac{\Delta x}{L}$$

_Hydraulis stress_ tidak masuk ujian.

YAAYY KELAARRR