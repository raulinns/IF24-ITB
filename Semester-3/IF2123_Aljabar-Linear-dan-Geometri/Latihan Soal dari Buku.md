## Exercise Set 1.1

(a) Sistem linear yang semua persamaannya homogen pasti konsisten.
**Answer:** True
**Penjelasan:** Sistem homogen selalu memiliki solusi trivial `x=0`.

(b) Mengalikan persamaan linear dengan nol adalah operasi baris elementer yang dapat diterima.
**Answer:** False
**Penjelasan:** Operasi baris elementer mensyaratkan pengali tak-nol.

(c) Sistem linear `x-y=3`, `2x-2y=k` tidak mungkin memiliki solusi unik, terlepas dari nilai k.
**Answer:** True
**Penjelasan:** Persamaan kedua adalah kelipatan dari yang pertama; garisnya sejajar atau berimpit.

(d) Satu persamaan linear dengan dua atau lebih variabel yang tidak diketahui harus selalu memiliki tak hingga banyaknya solusi.
**Answer:** True
**Penjelasan:** Selalu ada variabel bebas.

(e) Jika jumlah persamaan dalam sistem linear melebihi jumlah variabel yang tidak diketahui, maka sistem tersebut pasti tidak konsisten.
**Answer:** False
**Penjelasan:** Bisa saja konsisten, contohnya sistem dengan persamaan redundant (berlebihan).

(f) Jika setiap persamaan dalam sistem linear yang konsisten dikalikan dengan konstanta c, maka semua solusi sistem baru dapat diperoleh dengan mengalikan solusi dari sistem asli dengan c.
**Answer:** False
**Penjelasan:** Ini hanya berlaku jika `c ≠ 0` dan sistemnya homogen.

(g) Operasi baris elementer mengizinkan satu persamaan dalam sistem linear dikurangkan dari persamaan lain.
**Answer:** True
**Penjelasan:** Ini sama dengan menambahkan kelipatan -1 dari satu persamaan ke persamaan lain.

(h) Sistem linear dengan matriks augmented yang bersesuaian `[2 -1 4; 0 0 -1]` adalah konsisten.
**Answer:** False
**Penjelasan:** Baris terakhir menyatakan `0x + 0y = -1`, yang tidak mungkin.

---

## Exercise Set 1.2

(a) Jika sebuah matriks dalam bentuk eselon baris tereduksi, maka matriks tersebut juga dalam bentuk eselon baris.
**Answer:** True
**Penjelasan:** Bentuk eselon baris tereduksi memenuhi semua kriteria bentuk eselon baris.

(b) Jika operasi baris elementer diterapkan pada matriks yang dalam bentuk eselon baris, matriks yang dihasilkan akan tetap dalam bentuk eselon baris.
**Answer:** False
**Penjelasan:** Contoh: menambahkan kelipatan baris bawah ke baris atas dapat merusak properti nol di bawah *leading 1*.

(c) Setiap matriks memiliki bentuk eselon baris yang unik.
**Answer:** False
**Penjelasan:** Bentuk eselon baris *tereduksi* yang unik, bukan bentuk eselon baris biasa.

(d) Sistem linear homogen dalam n variabel yang matriks augmentednya memiliki bentuk eselon baris tereduksi dengan r buah *leading 1* memiliki `n-r` variabel bebas.
**Answer:** True
**Penjelasan:** Jumlah variabel dikurangi jumlah *leading variable* adalah jumlah *free variable*.

(e) Semua *leading 1* dalam matriks bentuk eselon baris harus terletak di kolom yang berbeda.
**Answer:** True
**Penjelasan:** Ini adalah bagian dari definisi bentuk eselon baris.

(f) Jika setiap kolom dari matriks bentuk eselon baris memiliki *leading 1*, maka semua entri yang bukan *leading 1* adalah nol.
**Answer:** False
**Penjelasan:** Ini hanya berlaku untuk bentuk eselon baris *tereduksi*.

(g) Jika sistem linear homogen dari n persamaan dalam n variabel memiliki matriks augmented yang bersesuaian dengan bentuk eselon baris tereduksi yang mengandung n *leading 1*, maka sistem linear tersebut hanya memiliki solusi trivial.
**Answer:** True
**Penjelasan:** Bentuk eselon baris tereduksinya adalah `I_n`, sehingga `x=0` adalah satu-satunya solusi.

(h) Jika bentuk eselon baris tereduksi dari matriks augmented untuk sistem linear memiliki satu baris nol, maka sistem tersebut harus memiliki tak hingga banyaknya solusi.
**Answer:** False
**Penjelasan:** Sistem bisa jadi tidak konsisten jika ada baris `[0 0 ... | 1]`.

(i) Jika sistem linear memiliki lebih banyak variabel daripada persamaan, maka sistem tersebut harus memiliki tak hingga banyaknya solusi.
**Answer:** False
**Penjelasan:** Sistem tersebut bisa jadi tidak konsisten.

---

## Exercise Set 1.3

(a) Matriks `[1 2 3; 4 5 6]` tidak memiliki diagonal utama.
**Answer:** True
**Penjelasan:** Diagonal utama hanya didefinisikan untuk matriks persegi.

(b) Matriks `m x n` memiliki m vektor kolom dan n vektor baris.
**Answer:** False
**Penjelasan:** Memiliki n vektor kolom dan m vektor baris.

(c) Jika A dan B adalah matriks `2 x 2`, maka `AB=BA`.
**Answer:** False
**Penjelasan:** Perkalian matriks pada umumnya tidak komutatif.

(d) Vektor baris ke-i dari perkalian matriks AB dapat dihitung dengan mengalikan A dengan vektor baris ke-i dari B.
**Answer:** False
**Penjelasan:** Vektor baris ke-i dari AB adalah vektor baris ke-i dari A dikalikan B.

(e) Untuk setiap matriks A, berlaku `(A^T)^T=A`.
**Answer:** True
**Penjelasan:** Mentranspos dua kali mengembalikan ke matriks asli.

(f) Jika A dan B adalah matriks persegi dengan ordo yang sama, maka `tr(AB)=tr(A)tr(B)`.
**Answer:** False
**Penjelasan:** Tidak ada properti seperti ini untuk trace. Properti yang benar adalah `tr(AB) = tr(BA)`.

(g) Jika A dan B adalah matriks persegi dengan ordo yang sama, maka `(AB)^T=A^T B^T`.
**Answer:** False
**Penjelasan:** Properti yang benar adalah `(AB)^T=B^T A^T`.

(h) Untuk setiap matriks persegi A, berlaku `tr(A^T)=tr(A)`.
**Answer:** True
**Penjelasan:** Diagonal utama tidak berubah saat ditranspos.

(i) Jika A adalah matriks `6 x 4` dan B adalah matriks `m x n` sedemikian sehingga `B^T A^T` adalah matriks `2 x 6`, maka `m=4` dan `n=2`.
**Answer:** True
**Penjelasan:** Dimensi harus cocok: `B^T` adalah `n x m`, `A^T` adalah `4 x 6`. Agar `B^T A^T` terdefinisi, `m=4`. Hasilnya berukuran `n x 6`. Karena hasilnya `2 x 6`, maka `n=2`.

(j) Jika A adalah matriks `n x n` dan c adalah skalar, maka `tr(cA)=c * tr(A)`.
**Answer:** True
**Penjelasan:** Trace adalah jumlah elemen diagonal, dan setiap elemen diagonal dikalikan c.

(k) Jika A, B, dan C adalah matriks dengan ukuran yang sama sedemikian sehingga `A-C=B-C`, maka `A=B`.
**Answer:** True
**Penjelasan:** Tambahkan C ke kedua sisi.

(l) Jika A, B, dan C adalah matriks persegi dengan ordo yang sama sedemikian sehingga `AC=BC`, maka `A=B`.
**Answer:** False
**Penjelasan:** Ini hanya berlaku jika C invertibel.

(m) Jika `AB+BA` terdefinisi, maka A dan B adalah matriks persegi dengan ukuran yang sama.
**Answer:** True
**Penjelasan:** Agar AB dan BA terdefinisi dan dapat dijumlahkan, A dan B harus persegi dan berukuran sama.

(n) Jika B memiliki satu kolom nol, maka AB juga demikian jika perkalian ini terdefinisi.
**Answer:** True
**Penjelasan:** Kolom ke-j dari AB adalah A dikalikan kolom ke-j dari B. Jika kolom ke-j dari B adalah nol, hasilnya adalah vektor nol.

(o) Jika B memiliki satu kolom nol, maka BA juga demikian jika perkalian ini terdefinisi.
**Answer:** False
**Penjelasan:** Perkalian dari kiri oleh B tidak menjamin kolom nol.

---

## Exercise Set 1.4

(a) Dua matriks `n x n`, A dan B, adalah invers satu sama lain jika dan hanya jika `AB=BA=0`.
**Answer:** False
**Penjelasan:** Definisi invers adalah `AB=BA=I`.

(b) Untuk semua matriks persegi A dan B dengan ukuran yang sama, berlaku `(A+B)^2=A^2+2AB+B^2`.
**Answer:** False
**Penjelasan:** Ini hanya berlaku jika `AB=BA`, karena `(A+B)^2 = A^2+AB+BA+B^2`.

(c) Untuk semua matriks persegi A dan B dengan ukuran yang sama, berlaku `A^2-B^2=(A-B)(A+B)`.
**Answer:** False
**Penjelasan:** Ini hanya berlaku jika `AB=BA`, karena `(A-B)(A+B) = A^2+AB-BA-B^2`.

(d) Jika A dan B adalah matriks invertibel dengan ukuran yang sama, maka AB invertibel dan `(AB)^(-1)=A^(-1)B^(-1)`.
**Answer:** False
**Penjelasan:** Properti yang benar adalah `(AB)^(-1)=B^(-1)A^(-1)`.

(e) Jika A dan B adalah matriks sedemikian sehingga AB terdefinisi, maka berlaku `(AB)^T=A^T B^T`.
**Answer:** False
**Penjelasan:** Properti yang benar adalah `(AB)^T=B^T A^T`.

(f) Matriks `A=[a b; c d]` invertibel jika dan hanya jika `ad-bc != 0`.
**Answer:** True
**Penjelasan:** Ini adalah kondisi determinan tak-nol untuk matriks 2x2.

(g) Jika A dan B adalah matriks dengan ukuran yang sama dan k adalah konstanta, maka `(kA+B)^T=kA^T+B^T`.
**Answer:** True
**Penjelasan:** Properti transpos penjumlahan dan perkalian skalar.

(h) Jika A adalah matriks invertibel, maka `A^T` juga demikian.
**Answer:** True
**Penjelasan:** Invers dari `A^T` adalah `(A^(-1))^T`.

(i) Jika `p(x)=a_0+a_1x+a_2x^2+...+a_mx^m` dan I adalah matriks identitas, maka `p(I)=a_0+a_1+a_2+...+a_m`.
**Answer:** False
**Penjelasan:** `p(I)=a_0I+a_1I+a_2I^2+...+a_mI^m = (a_0+a_1+...+a_m)I`.

(j) Matriks persegi yang mengandung baris atau kolom nol tidak mungkin invertibel.
**Answer:** True
**Penjelasan:** Determinannya akan nol.

(k) Jumlah dua matriks invertibel dengan ukuran yang sama haruslah invertibel.
**Answer:** False
**Penjelasan:** Contoh: `I + (-I) = 0`, yang tidak invertibel.

---

## Exercise Set 1.5

(a) Hasil kali dua matriks elementer dengan ukuran yang sama haruslah matriks elementer.
**Answer:** False
**Penjelasan:** Hasil kalinya bisa jadi bukan representasi dari *satu* operasi baris elementer.

(b) Setiap matriks elementer invertibel.
**Answer:** True
**Penjelasan:** Setiap operasi baris elementer dapat dibatalkan oleh operasi baris elementer lain.

(c) Jika A dan B ekuivalen baris, dan jika B dan C ekuivalen baris, maka A dan C ekuivalen baris.
**Answer:** True
**Penjelasan:** Relasi ekuivalen baris bersifat transitif.

(d) Jika A adalah matriks `n x n` yang tidak invertibel, maka sistem linear `Ax=0` memiliki tak hingga banyaknya solusi.
**Answer:** True
**Penjelasan:** Sistem homogen `Ax=0` selalu konsisten. Jika A tidak invertibel, pasti ada variabel bebas, sehingga solusinya tak hingga banyak.

(e) Jika A adalah matriks `n x n` yang tidak invertibel, maka matriks yang diperoleh dengan menukar dua baris A tidak mungkin invertibel.
**Answer:** True
**Penjelasan:** Menukar baris mengalikan determinan dengan -1. Jika `det(A)=0`, maka determinan matriks baru juga 0.

(f) Jika A invertibel dan kelipatan baris pertama A ditambahkan ke baris kedua, maka matriks yang dihasilkan invertibel.
**Answer:** True
**Penjelasan:** Operasi baris elementer tidak mengubah invertibilitas.

(g) Ekspresi matriks invertibel A sebagai hasil kali matriks elementer adalah unik.
**Answer:** False
**Penjelasan:** Urutan operasi baris elementer bisa berbeda.

---

## Exercise Set 1.6

(a) Tidak mungkin sistem persamaan linear memiliki tepat dua solusi.
**Answer:** True
**Penjelasan:** Setiap sistem linear memiliki nol, satu, atau tak hingga solusi.

(b) Jika sistem linear `Ax=0` memiliki solusi unik, maka sistem linear `Ax=b` juga harus memiliki solusi unik.
**Answer:** True
**Penjelasan:** Jika `Ax=0` hanya punya solusi trivial, A invertibel. Jika A invertibel, `Ax=b` punya solusi unik `x=A^(-1)b`.

(c) Jika A dan B adalah matriks `n x n` sedemikian sehingga `AB=I_n`, maka `BA=I_n`.
**Answer:** True
**Penjelasan:** Ini adalah salah satu properti matriks invertibel.

(d) Jika A dan B adalah matriks ekuivalen baris, maka sistem linear `Ax=0` dan `Bx=0` memiliki himpunan solusi yang sama.
**Answer:** True
**Penjelasan:** Operasi baris elementer tidak mengubah himpunan solusi sistem homogen.

(e) Jika A adalah matriks `n x n` dan S adalah matriks `n x n` yang invertibel, maka jika x adalah solusi sistem linear `(S^(-1)AS)x=b`, maka Sx adalah solusi sistem linear `Ay=Sb`.
**Answer:** True
**Penjelasan:** Substitusi `y=Sx` (atau `x=S^(-1)y`), maka `(S^(-1)AS)(S^(-1)y)=b`. Kalikan `S` dari kiri: `A(SS^(-1))y = Sb`, sehingga `Ay=Sb`.

(f) Misalkan A adalah matriks `n x n`. Sistem linear `Ax=4x` memiliki solusi unik jika dan hanya jika `A-4I` adalah matriks invertibel.
**Answer:** True
**Penjelasan:** `Ax=4x` ekuivalen dengan `(A-4I)x=0`. Sistem ini punya solusi unik (yaitu `x=0`) jika dan hanya jika `A-4I` invertibel.

(g) Misalkan A dan B adalah matriks `n x n`. Jika A atau B (atau keduanya) tidak invertibel, maka AB juga tidak invertibel.
**Answer:** True
**Penjelasan:** Jika AB invertibel, maka `det(AB) != 0`. Tapi `det(AB) = det(A)det(B)`. Jika `det(A)=0` atau `det(B)=0`, maka `det(AB)=0`, yang merupakan kontradiksi.

---

## Exercise Set 1.7

(a) Transpos dari matriks diagonal adalah matriks diagonal.
**Answer:** True
**Penjelasan:** Entri non-diagonal tetap nol setelah transpos.

(b) Transpos dari matriks segitiga atas adalah matriks segitiga atas.
**Answer:** False
**Penjelasan:** Transposnya adalah matriks segitiga bawah.

(c) Jumlah matriks segitiga atas dan matriks segitiga bawah adalah matriks diagonal.
**Answer:** False
**Penjelasan:** Jumlahnya bisa jadi matriks penuh (tidak harus diagonal).

(d) Semua entri matriks simetris ditentukan oleh entri yang terletak pada dan di atas diagonal utama.
**Answer:** True
**Penjelasan:** Karena `a_ij = a_ji`, entri di bawah diagonal utama sama dengan entri di atasnya.

(e) Semua entri matriks segitiga atas ditentukan oleh entri yang terletak pada dan di atas diagonal utama.
**Answer:** True
**Penjelasan:** Entri di bawah diagonal utama adalah nol berdasarkan definisi.

(f) Invers dari matriks segitiga bawah yang invertibel adalah matriks segitiga atas.
**Answer:** False
**Penjelasan:** Inversnya adalah matriks segitiga bawah juga.

(g) Matriks diagonal invertibel jika dan hanya jika semua entri diagonalnya positif.
**Answer:** False
**Penjelasan:** Invertibel jika dan hanya jika semua entri diagonalnya *tak-nol*.

(h) Jumlah matriks diagonal dan matriks segitiga bawah adalah matriks segitiga bawah.
**Answer:** True
**Penjelasan:** Entri di atas diagonal utama tetap nol karena keduanya nol di posisi tersebut.

(i) Matriks yang sekaligus simetris dan segitiga atas haruslah matriks diagonal.
**Answer:** True
**Penjelasan:** Simetris berarti `a_ij = a_ji`. Segitiga atas berarti `a_ij = 0` untuk `i > j`. Maka `a_ji = 0` untuk `j > i`. Jadi, semua entri non-diagonal adalah nol.

(j) Jika A dan B adalah matriks `n x n` sedemikian sehingga `A+B` simetris, maka A dan B simetris.
**Answer:** False
**Penjelasan:** Contoh: `A=[1 2; 3 4]`, `B=[1 3; 2 4]`. `A+B=[2 5; 5 8]` simetris, tapi A dan B tidak simetris.

(k) Jika A dan B adalah matriks `n x n` sedemikian sehingga `A+B` segitiga atas, maka A dan B segitiga atas.
**Answer:** False
**Penjelasan:** Contoh: `A=[1 2; 1 4]`, `B=[1 3; -1 4]`. `A+B=[2 5; 0 8]` segitiga atas, tapi A dan B tidak segitiga atas.

(l) Jika `A^2` adalah matriks simetris, maka A adalah matriks simetris.
**Answer:** False
**Penjelasan:** Contoh: `A=[0 1; 0 0]`. `A^2=[0 0; 0 0]` simetris, tapi A tidak simetris.

(m) Jika `kA` adalah matriks simetris untuk suatu `k != 0`, maka A adalah matriks simetris.
**Answer:** True
**Penjelasan:** Jika `kA` simetris, `(kA)^T = kA`. Maka `k A^T = kA`. Karena `k != 0`, kita bisa membagi dengan k untuk mendapatkan `A^T = A`.

---

## Exercise Set 1.8

(a) Dalam jaringan apapun, jumlah aliran keluar dari sebuah node harus sama dengan jumlah aliran masuk ke node tersebut.
**Answer:** True
**Penjelasan:** Ini adalah prinsip dasar konservasi aliran pada node.

(b) Ketika arus melewati resistor, terjadi peningkatan potensial listrik dalam rangkaian.
**Answer:** False
**Penjelasan:** Terjadi penurunan potensial (voltage drop) melintasi resistor.

(c) Hukum Arus Kirchhoff menyatakan bahwa jumlah arus yang mengalir masuk ke sebuah node sama dengan jumlah arus yang mengalir keluar dari node tersebut.
**Answer:** True
**Penjelasan:** Ini adalah definisi Hukum Arus Kirchhoff (Kirchhoff's Current Law).

(d) Persamaan kimia disebut setara jika jumlah total atom di setiap sisi persamaan sama.
**Answer:** False
**Penjelasan:** Persamaan setara jika jumlah total atom *untuk setiap elemen* sama di kedua sisi.

(e) Diberikan n titik di bidang xy, ada polinomial unik berderajat `n-1` atau kurang yang grafiknya melewati titik-titik tersebut.
**Answer:** False
**Penjelasan:** Ini benar hanya jika semua koordinat-x dari titik-titik tersebut berbeda.

---

## Exercise Set 1.9

(a) Sektor ekonomi yang menghasilkan output disebut sektor terbuka.
**Answer:** False
**Penjelasan:** Sektor terbuka adalah sektor yang mengkonsumsi output tanpa memproduksi (misalnya konsumen akhir). Sektor yang memproduksi disebut sektor produktif.

(b) Ekonomi tertutup adalah ekonomi yang tidak memiliki sektor terbuka.
**Answer:** True
**Penjelasan:** Dalam model tertutup, semua output dari sektor produktif dikonsumsi oleh sektor produktif itu sendiri.

(c) Baris-baris matriks konsumsi merepresentasikan output dalam suatu sektor ekonomi.
**Answer:** False
**Penjelasan:** Baris ke-i merepresentasikan berapa banyak output dari sektor i yang dibutuhkan *sebagai input* oleh sektor lain (dan mungkin dirinya sendiri) untuk menghasilkan satu unit output.

(d) Jika jumlah kolom dari matriks konsumsi semuanya kurang dari 1, maka matriks Leontief `I-C` invertibel.
**Answer:** True
**Penjelasan:** Ini adalah salah satu kondisi yang menjamin bahwa ekonomi tersebut produktif dan matriks Leontief invertibel (dengan invers yang non-negatif).

(e) Persamaan Leontief `x=Cx+d` menghubungkan vektor produksi suatu ekonomi dengan vektor permintaan luar.
**Answer:** True
**Penjelasan:** Persamaan ini (`(I-C)x = d`) adalah persamaan inti dari model Leontief terbuka, yang menyatakan bahwa produksi (`x`) harus mencukupi konsumsi internal (`Cx`) dan permintaan eksternal (`d`).

---

## Exercise Set 2.1

(a) Determinan matriks `2 x 2` `[a b; c d]` adalah `ad+bc`.
**Answer:** False
**Penjelasan:** Determinannya adalah `ad-bc`.

(b) Dua matriks persegi A dan B dapat memiliki determinan yang sama hanya jika ukurannya sama.
**Answer:** False
**Penjelasan:** Determinan adalah sebuah skalar. Matriks dengan ukuran berbeda bisa saja memiliki nilai determinan yang sama, contohnya `det([2])=2` dan `det([1 0; 0 2])=2`.

(c) Minor `M_ij` sama dengan kofaktor `C_ij` jika dan hanya jika `i+j` genap.
**Answer:** True
**Penjelasan:** Definisi kofaktor adalah `C_ij = (-1)^(i+j) M_ij`. Jika `i+j` genap, `(-1)^(i+j) = 1`.

(d) Jika A adalah matriks simetris `3 x 3`, maka `C_ij = C_ji` untuk semua i dan j.
**Answer:** True
**Penjelasan:** Submatriks untuk `M_ij` adalah transpos dari submatriks untuk `M_ji`. Karena A simetris, determinan submatriks tersebut sama. Tanda `(-1)^(i+j)` juga sama dengan `(-1)^(j+i)`.

(e) Nilai ekspansi kofaktor matriks A tidak bergantung pada baris atau kolom yang dipilih untuk ekspansi.
**Answer:** True
**Penjelasan:** Ini adalah teorema dasar tentang determinan.

(f) Determinan matriks segitiga bawah adalah jumlah entri sepanjang diagonal utamanya.
**Answer:** False
**Penjelasan:** Determinannya adalah *hasil kali* entri diagonal utama.

(g) Untuk setiap matriks persegi A dan setiap skalar c, berlaku `det(cA)=c * det(A)`.
**Answer:** False
**Penjelasan:** Jika A berukuran `n x n`, maka `det(cA)=c^n * det(A)`.

(h) Untuk semua matriks persegi A dan B, berlaku `det(A+B)=det(A)+det(B)`.
**Answer:** False
**Penjelasan:** Determinan pada umumnya tidak bersifat aditif (distributif terhadap penjumlahan).

(i) Untuk setiap matriks `2 x 2` A, berlaku `det(A^2)=(det(A))^2`.
**Answer:** True
**Penjelasan:** Menggunakan sifat `det(AB)=det(A)det(B)`, maka `det(A^2)=det(AA)=det(A)det(A)=(det(A))^2`.

---

## Exercise Set 2.2

(a) Jika A adalah matriks `3 x 3` dan B diperoleh dari A dengan menukar dua baris pertama dan kemudian menukar dua baris terakhir, maka `det(B)=det(A)`.
**Answer:** True
**Penjelasan:** Setiap penukaran baris mengalikan determinan dengan -1. Dua penukaran mengalikan dengan `(-1)^2 = 1`.

(b) Jika A adalah matriks `3 x 3` dan B diperoleh dari A dengan mengalikan kolom pertama dengan 4 dan mengalikan kolom ketiga dengan `3/4`, maka `det(B)=3 * det(A)`.
**Answer:** True
**Penjelasan:** Mengalikan satu kolom dengan skalar k akan mengalikan determinan dengan k. Jadi `det(B) = (4)*(3/4)*det(A) = 3*det(A)`.

(c) Jika A adalah matriks `3 x 3` dan B diperoleh dari A dengan menambahkan 5 kali baris pertama ke masing-masing baris kedua dan ketiga, maka `det(B)=(25) * det(A)`.
**Answer:** False
**Penjelasan:** Menambahkan kelipatan satu baris ke baris lain *tidak mengubah* determinan. Jadi `det(B)=det(A)`.

(d) Jika A adalah matriks `n x n` dan B diperoleh dari A dengan mengalikan setiap baris A dengan nomor barisnya, maka `det(B) = (n(n+1)/2) * det(A)`.
**Answer:** False
**Penjelasan:** Mengalikan baris ke-i dengan i mengalikan determinan dengan i. Melakukan ini untuk semua baris `i=1...n` akan mengalikan determinan dengan `1 * 2 * ... * n = n!`. Jadi `det(B) = n! * det(A)`.

(e) Jika A adalah matriks persegi dengan dua kolom identik, maka `det(A)=0`.
**Answer:** True
**Penjelasan:** Jika satu kolom dikurangkan dari kolom identik lainnya, hasilnya adalah kolom nol. Determinan matriks dengan kolom nol adalah 0.

(f) Jika jumlah vektor baris kedua dan keempat dari matriks `6 x 6` A sama dengan vektor baris terakhir, maka `det(A)=0`.
**Answer:** True
**Penjelasan:** Lakukan operasi baris: kurangkan baris kedua dan baris keempat dari baris terakhir (`R_6 = R_6 - R_2 - R_4`). Baris terakhir akan menjadi baris nol, sehingga determinannya 0.

---

## Exercise Set 2.3

(a) Jika A adalah matriks `2 x 2`, maka `det(A)=(a_11+a_22)(a_11-a_22)-(a_12+a_21)(a_12-a_21)`.
**Answer:** False
**Penjelasan:** Rumus yang benar adalah `det(A) = a_11 a_22 - a_12 a_21`. Ekspresi yang diberikan menghasilkan `a_11^2 - a_22^2 - (a_12^2 - a_21^2)`.

(b) Jika A dan B adalah matriks persegi dengan ukuran yang sama sedemikian sehingga `det(A)=det(B)`, maka `det(A+B)=2 * det(A)`.
**Answer:** False
**Penjelasan:** Determinan tidak bersifat aditif.

(c) Jika A dan B adalah matriks persegi dengan ukuran yang sama dan A invertibel, maka `det(A^(-1)BA)=det(B)`.
**Answer:** True
**Penjelasan:** `det(A^(-1)BA) = det(A^(-1))det(B)det(A) = (1/det(A))det(B)det(A) = det(B)`.

(d) Matriks persegi A invertibel jika dan hanya jika `det(A)=0`.
**Answer:** False
**Penjelasan:** Invertibel jika dan hanya jika `det(A) != 0`.

(e) Matriks kofaktor dari A persis sama dengan `(adj(A))^T`.
**Answer:** True
**Penjelasan:** Adjoint dari A, `adj(A)`, didefinisikan sebagai transpos dari matriks kofaktor. Jadi, matriks kofaktor adalah `(adj(A))^T`.

(f) Untuk setiap matriks `n x n` A, berlaku `A * adj(A)=(det(A))I_n`.
**Answer:** True
**Penjelasan:** Ini adalah teorema fundamental tentang hubungan matriks dengan adjointnya.

(g) Jika A adalah matriks persegi dan sistem linear `Ax=b` memiliki banyak solusi untuk x, maka `det(A)=0`.
**Answer:** True
**Penjelasan:** Jika sistem memiliki banyak solusi, A tidak invertibel, yang berarti `det(A)=0`.

(h) Jika A adalah matriks `n x n` dan terdapat matriks `n x 1` b sedemikian sehingga sistem linear `Ax=b` tidak memiliki solusi, maka bentuk eselon baris tereduksi A tidak mungkin `I_n`.
**Answer:** True
**Penjelasan:** Jika sistem tidak memiliki solusi, A tidak invertibel. Bentuk eselon baris tereduksi dari matriks non-invertibel tidak mungkin `I_n`.

(i) Jika E adalah matriks elementer, maka `Ex=0` hanya memiliki solusi trivial.
**Answer:** True
**Penjelasan:** Matriks elementer selalu invertibel, sehingga sistem homogen `Ex=0` hanya memiliki solusi trivial `x=0`.

(j) Jika A adalah matriks invertibel, maka sistem linear `Ax=0` hanya memiliki solusi trivial jika dan hanya jika sistem linear `A^(-1)x=0` hanya memiliki solusi trivial.
**Answer:** True
**Penjelasan:** Jika A invertibel, `A^(-1)` juga invertibel. Sistem homogen `Mx=0` hanya punya solusi trivial jika dan hanya jika M invertibel.

(k) Jika A invertibel, maka `adj(A)` juga harus invertibel.
**Answer:** True
**Penjelasan:** Karena `A^(-1) = (1/det(A))adj(A)`, maka `adj(A)=det(A)A^(-1)`. Karena `det(A) != 0` dan `A^(-1)` invertibel, maka `adj(A)` adalah perkalian skalar tak-nol dari matriks invertibel, sehingga `adj(A)` juga invertibel.

(l) Jika A memiliki baris nol, maka `adj(A)` juga demikian.
**Answer:** False
**Penjelasan:** Adjoint adalah transpos dari matriks kofaktor. Kofaktor dihitung dari submatriks. Jika A memiliki baris nol, kofaktornya tidak harus nol semua. Contoh: `A=[1 2 3; 0 0 0; 4 5 6]`. Kofaktor `C_21 = -(12-15) = 3`. `adj(A)` akan memiliki 3 di posisi (1,2).

---

## Exercise Set 3.1

(a) Dua vektor ekuivalen harus memiliki titik awal yang sama.
**Answer:** False
**Penjelasan:** Vektor ekuivalen memiliki panjang dan arah yang sama, tapi titik awalnya bisa berbeda.

(b) Vektor `(a, b)` dan `(a, b, 0)` ekuivalen.
**Answer:** False
**Penjelasan:** Vektor berada di ruang dimensi yang berbeda (`R^2` vs `R^3`).

(c) Jika k adalah skalar dan v adalah vektor, maka v dan kv paralel jika dan hanya jika `k >= 0`.
**Answer:** False
**Penjelasan:** Mereka paralel jika `k != 0`. Jika `k < 0`, arahnya berlawanan tapi tetap paralel.

(d) Vektor `v+(-v)` dan `0` sama.
**Answer:** True
**Penjelasan:** Ini adalah definisi dari vektor negatif (additive inverse).

(e) Jika `a+b=a+c`, maka `b=c`.
**Answer:** True
**Penjelasan:** Ini adalah hukum pembatalan (cancellation law) untuk penjumlahan vektor.

(f) Jika `a` dan `b` adalah skalar sedemikian sehingga `av+bv=0`, maka `u` dan `v` adalah vektor paralel.
**Answer:** False
**Penjelasan:** Pernyataan ini tidak melibatkan `u`. Jika maksudnya `(a+b)v=0`, dan `v != 0`, maka `a+b=0`. Ini tidak mengatakan apa-apa tentang paralelisme antar vektor yang berbeda.

(g) Vektor kolinear dengan panjang yang sama adalah sama.
**Answer:** False
**Penjelasan:** Mereka bisa memiliki arah yang berlawanan (misal `v` dan `-v`).

(h) Jika `v+w=v`, maka `w` harus vektor nol.
**Answer:** True
**Penjelasan:** Ini adalah sifat identitas penjumlahan (vektor nol).

(i) Jika k dan m adalah skalar dan u dan v adalah vektor, maka `(k+m)(u+v)=ku+kv+mu+mv`.
**Answer:** False
**Penjelasan:** Sifat distributif yang benar adalah `(k+m)u = ku+mu` dan `k(u+v)=ku+kv`. Ekspansi yang diberikan tidak benar secara umum.

(j) Jika vektor v dan w diberikan, maka persamaan vektor `x-v=w` dapat diselesaikan untuk x.
**Answer:** True
**Penjelasan:** Solusinya adalah `x=w+v`.

(k) Kombinasi linear `a_1v_1+a_2v_2` dan `b_1v_1+b_2v_2` hanya bisa sama jika `a_1=b_1` dan `a_2=b_2`.
**Answer:** False
**Penjelasan:** Ini hanya berlaku jika `v_1` dan `v_2` linear independen. Jika dependen (misal `v_2 = 2v_1`), maka `3v_1 + 0v_2` sama dengan `1v_1 + 1v_2`.

---

## Exercise Set 3.2

(a) Jika setiap komponen vektor di `R^n` digandakan, norma vektor tersebut digandakan.
**Answer:** True
**Penjelasan:** Menggunakan sifat `||kv|| = |k| ||v||`. Jika `k=2`, maka `||2v|| = |2| ||v|| = 2||v||`.

(b) Di `R^2`, vektor-vektor dengan norma 5 yang titik awalnya di titik asal memiliki titik akhir yang terletak pada lingkaran berjari-jari 5 yang berpusat di titik asal.
**Answer:** True
**Penjelasan:** Definisi norma Euclidean `sqrt(x^2+y^2)` sama dengan jarak dari titik asal. `sqrt(x^2+y^2) = 5` adalah persamaan lingkaran.

(c) Setiap vektor di `R^n` memiliki norma positif.
**Answer:** False
**Penjelasan:** Vektor nol `0` memiliki norma `||0|| = 0`, yang tidak positif.

(d) Jika v adalah vektor tak-nol di `R^n`, terdapat tepat dua vektor satuan yang paralel dengan v.
**Answer:** True
**Penjelasan:** Vektor-vektor tersebut adalah `v/||v||` (arah sama) dan `-v/||v||` (arah berlawanan).

(e) Jika `||u||=1`, `||v||=2`, dan `u . v = -1`, maka sudut antara u dan v adalah `2pi/3` radian.
**Answer:** True
**Penjelasan:** Menggunakan rumus `cos(theta) = (u . v) / (||u|| ||v||)`. Maka `cos(theta) = -1 / (1 * 2) = -1/2`. Sudut `theta` dalam `[0, pi]` yang memenuhi ini adalah `2pi/3`.

(f) Ekspresi `||u . v||` dan `||u|| * ||v||` keduanya bermakna dan sama satu sama lain.
**Answer:** False
**Penjelasan:** `u . v` adalah skalar, sehingga `||u . v||` adalah nilai mutlaknya, `|u . v|`. Ketidaksamaan Cauchy-Schwarz menyatakan `|u . v| <= ||u|| ||v||`. Kesamaan hanya berlaku jika u dan v kolinear.

(g) Jika `u . v = 0`, maka `||u+v||^2 = ||u||^2 + ||v||^2`.
**Answer:** True
**Penjelasan:** `||u+v||^2 = (u+v).(u+v) = u.u + 2(u.v) + v.v = ||u||^2 + 2(0) + ||v||^2 = ||u||^2 + ||v||^2`. Ini adalah Teorema Pythagoras untuk vektor.

(h) Jika `u . v = u . w`, maka `v=w`.
**Answer:** False
**Penjelasan:** Jika `u=0`, pernyataan tidak berlaku. Jika `u != 0`, persamaan bisa ditulis `u . (v-w) = 0`, yang berarti `v-w` ortogonal terhadap `u`, tidak harus `v-w=0`.

(i) Di `R^2`, jika u terletak di kuadran pertama dan v terletak di kuadran ketiga, maka `u . v` tidak mungkin positif.
**Answer:** True
**Penjelasan:** `u=(u_1, u_2)` dengan `u_1>0, u_2>0`. `v=(v_1, v_2)` dengan `v_1<0, v_2<0`. Maka `u . v = u_1 v_1 + u_2 v_2 = (positif)(negatif) + (positif)(negatif) = negatif + negatif`, yang hasilnya pasti negatif.

(j) Untuk semua vektor u, v, dan w di `R^n`, berlaku `|(u+v) . w|=|u . w + v . w|`.
**Answer:** True
**Penjelasan:** Ini adalah sifat distributif dot product: `(u+v) . w = u . w + v . w`. Mengambil nilai mutlak kedua sisi tidak mengubah kesamaan.

---

## Exercise Set 3.3

(a) Vektor `(3, -1, 2)` dan `(0, 0, 0)` ortogonal.
**Answer:** True
**Penjelasan:** Dot product mereka adalah `3(0) + (-1)(0) + 2(0) = 0`. Vektor nol ortogonal terhadap semua vektor.

(b) Jika u dan v adalah vektor ortogonal, maka untuk semua skalar tak-nol k dan m, `ku` dan `mv` adalah vektor ortogonal.
**Answer:** True
**Penjelasan:** `(ku) . (mv) = (km)(u . v) = (km)(0) = 0`.

(c) Proyeksi ortogonal u terhadap a tegak lurus terhadap komponen vektor u yang ortogonal terhadap a.
**Answer:** True
**Penjelasan:** Vektor u didekomposisi menjadi `u = proj_a(u) + w`, di mana `w = u - proj_a(u)` adalah komponen yang ortogonal terhadap `a`. Berdasarkan definisi, `proj_a(u)` (yang paralel dengan `a`) dan `w` (yang ortogonal terhadap `a`) saling tegak lurus.

(d) Jika a dan b adalah vektor ortogonal, maka untuk setiap vektor tak-nol u, berlaku `proj_a(proj_b(u)) = 0`.
**Answer:** True
**Penjelasan:** `proj_b(u)` adalah kelipatan skalar dari `b`. Karena `a` ortogonal terhadap `b`, maka `a` juga ortogonal terhadap kelipatan skalar dari `b`. Proyeksi vektor terhadap vektor yang ortogonal padanya adalah vektor nol.

(e) Jika a dan u adalah vektor tak-nol, maka `||proj_a(u)||=||proj_u(a)||`.
**Answer:** False
**Penjelasan:** `||proj_a(u)|| = |u . a| / ||a||` dan `||proj_u(a)|| = |a . u| / ||u||`. Keduanya sama hanya jika `||a||=||u||`.

(f) Jika hubungan `proj_a u = proj_a v` berlaku untuk suatu vektor tak-nol a, maka `u=v`.
**Answer:** False
**Penjelasan:** `proj_a u = proj_a v` berarti `proj_a (u-v) = 0`. Ini hanya mengimplikasikan bahwa `u-v` ortogonal terhadap `a`, bukan bahwa `u-v=0`.

(g) Untuk semua vektor u dan v, berlaku `||u+v||=||u||+||v||`.
**Answer:** False
**Penjelasan:** Ini adalah ketidaksamaan segitiga: `||u+v|| <= ||u||+||v||`. Kesamaan hanya berlaku jika u dan v memiliki arah yang sama atau salah satunya adalah vektor nol.

---

## Exercise Set 3.4

(a) Persamaan vektor sebuah garis dapat ditentukan dari sembarang titik yang terletak pada garis dan sebuah vektor tak-nol yang paralel dengan garis tersebut.
**Answer:** True
**Penjelasan:** Ini adalah definisi standar persamaan vektor garis: `x = x_0 + tv`.

(b) Persamaan vektor sebuah bidang dapat ditentukan dari sembarang titik yang terletak pada bidang dan sebuah vektor tak-nol yang paralel dengan bidang tersebut.
**Answer:** False
**Penjelasan:** Dibutuhkan satu titik dan *dua* vektor tak-kolinear yang paralel dengan bidang, atau satu titik dan satu vektor normal yang tegak lurus bidang.

(c) Titik-titik yang terletak pada garis melalui titik asal di `R^2` atau `R^3` adalah semua kelipatan skalar dari sembarang vektor tak-nol pada garis tersebut.
**Answer:** True
**Penjelasan:** Persamaan vektor garis melalui titik asal adalah `x = 0 + tv = tv`.

(d) Semua vektor solusi dari sistem linear `Ax=0` ortogonal terhadap vektor-vektor baris matriks A jika dan hanya jika `Ax=0`.
**Answer:** True
**Penjelasan:** Persamaan `Ax=0` secara eksplisit menyatakan bahwa dot product dari setiap vektor baris A dengan vektor solusi x adalah nol.

(e) Solusi umum sistem linear non-homogen `Ax=b` dapat diperoleh dengan menambahkan `b` ke solusi umum sistem linear homogen `Ax=0`.
**Answer:** False
**Penjelasan:** Solusi umum `Ax=b` adalah `x_p + x_h`, di mana `x_p` adalah satu solusi *partikular* (khusus) dari `Ax=b` dan `x_h` adalah solusi umum dari `Ax=0`.

(f) Jika `x_1` dan `x_2` adalah dua solusi dari sistem linear non-homogen `Ax=b`, maka `x_1-x_2` adalah solusi dari sistem linear homogen yang bersesuaian.
**Answer:** True
**Penjelasan:** `A(x_1-x_2) = Ax_1 - Ax_2 = b - b = 0`.

---

## Exercise Set 3.5

(a) Hasil kali silang (cross product) dari dua vektor tak-nol u dan v adalah vektor tak-nol jika dan hanya jika u dan v tidak paralel.
**Answer:** True
**Penjelasan:** Magnitudo `||u x v|| = ||u|| ||v|| sin(theta)`. Ini nol jika dan hanya jika `sin(theta) = 0` (untuk u, v tak-nol), yang berarti `theta=0` atau `theta=pi`, yaitu u dan v paralel.

(b) Vektor normal terhadap bidang dapat diperoleh dengan mengambil hasil kali silang dari dua vektor tak-nol dan tak-kolinear yang terletak pada bidang.
**Answer:** True
**Penjelasan:** Hasil kali silang `u x v` menghasilkan vektor yang ortogonal (tegak lurus) terhadap u dan v, dan oleh karena itu ortogonal terhadap bidang yang direntang oleh u dan v.

(c) Hasil kali triple skalar (scalar triple product) dari u, v, dan w menentukan vektor yang panjangnya sama dengan volume paralelepiped yang ditentukan oleh u, v, dan w.
**Answer:** False
**Penjelasan:** Scalar triple product `u . (v x w)` adalah sebuah *skalar*, bukan vektor. Nilai absolut dari skalar ini adalah volume paralelepiped.

(d) Jika u dan v adalah vektor di ruang-3, maka `||u x v||` sama dengan luas jajaran genjang yang ditentukan oleh u dan v.
**Answer:** True
**Penjelasan:** Ini adalah interpretasi geometris standar dari magnitudo cross product.

(e) Untuk semua vektor u, v, dan w di ruang-3, vektor `(u x v) x w` dan `u x (v x w)` sama.
**Answer:** False
**Penjelasan:** Cross product tidak bersifat asosiatif.

(f) Jika u, v, dan w adalah vektor di `R^3`, di mana u tak-nol dan `u x v = u x w`, maka `v=w`.
**Answer:** False
**Penjelasan:** `u x v = u x w` mengimplikasikan `u x (v-w) = 0`. Ini berarti `v-w` paralel dengan `u` (bisa jadi `v-w = ku` untuk suatu skalar k), tidak harus `v-w=0`.

---

## Exercise Set 4.1

(a) Vektor adalah segmen garis berarah (panah).
**Answer:** False
**Penjelasan:** Ini hanyalah salah satu representasi geometris vektor di `R^2` atau `R^3`, bukan definisi umum vektor dalam konteks ruang vektor abstrak.

(b) Vektor adalah n-tuple bilangan real.
**Answer:** False
**Penjelasan:** n-tuple adalah *contoh* vektor (elemen dari `R^n`), tetapi definisi vektor lebih umum dan abstrak, mencakup objek lain seperti matriks, polinomial, fungsi, dll.

(c) Vektor adalah sembarang elemen dari ruang vektor.
**Answer:** True
**Penjelasan:** Ini adalah definisi vektor dalam konteks teori ruang vektor abstrak. Apa pun yang memenuhi aksioma ruang vektor bisa disebut vektor.

(d) Terdapat ruang vektor yang terdiri dari tepat dua vektor berbeda.
**Answer:** False
**Penjelasan:** Setiap ruang vektor harus mengandung vektor nol `0`. Jika ada vektor lain `v != 0`, maka `kv` juga harus ada di ruang vektor untuk semua skalar `k`. Jika skalar berasal dari field tak hingga (seperti bilangan real), maka akan ada tak hingga vektor. Minimal ruang vektor adalah ruang vektor nol `{0}`.

(e) Himpunan polinomial berderajat tepat 1 adalah ruang vektor di bawah operasi yang didefinisikan dalam Latihan 12 (operasi standar).
**Answer:** False
**Penjelasan:** Himpunan ini tidak tertutup terhadap penjumlahan (misalnya, `(x+1) + (-x+2) = 3`, hasilnya bukan polinomial derajat 1) dan tidak mengandung vektor nol (polinomial nol).

---

## Exercise Set 4.2

(a) Setiap subruang dari ruang vektor adalah ruang vektor itu sendiri.
**Answer:** True
**Penjelasan:** Definisi subruang mensyaratkan bahwa ia adalah himpunan bagian tak kosong yang tertutup terhadap operasi penjumlahan dan perkalian skalar dari ruang vektor induknya, yang menjadikannya ruang vektor.

(b) Setiap ruang vektor adalah subruang dari dirinya sendiri.
**Answer:** True
**Penjelasan:** Ruang vektor V adalah himpunan bagian dari V, mengandung vektor nol, dan tertutup terhadap operasinya sendiri.

(c) Setiap subset dari ruang vektor V yang mengandung vektor nol di V adalah subruang dari V.
**Answer:** False
**Penjelasan:** Subset tersebut juga harus tertutup terhadap penjumlahan dan perkalian skalar. Contoh: `{(0,0), (1,0)}` di `R^2` mengandung nol tapi bukan subruang.

(d) Himpunan `R^2` adalah subruang dari `R^3`.
**Answer:** False
**Penjelasan:** Elemen `R^2` adalah pasangan `(x,y)`, sedangkan elemen `R^3` adalah triple `(x,y,z)`. `R^2` bukan subset dari `R^3`. Bidang `xy` di `R^3` (yaitu himpunan `{(x,y,0) | x, y in R}`) adalah subruang dari `R^3` yang *isomorfik* dengan `R^2`.

(e) Himpunan solusi dari sistem linear konsisten `Ax=b` dari m persamaan dalam n variabel adalah subruang dari `R^n`.
**Answer:** False
**Penjelasan:** Ini hanya benar jika `b=0` (sistem homogen). Jika `b != 0`, himpunan solusi tidak mengandung vektor nol `0` (karena `A0=0 != b`), sehingga tidak bisa menjadi subruang.

(f) Span dari sembarang himpunan vektor hingga dalam ruang vektor tertutup terhadap penjumlahan dan perkalian skalar.
**Answer:** True
**Penjelasan:** Span dari suatu himpunan S didefinisikan sebagai himpunan semua kombinasi linear dari vektor-vektor di S. Ini adalah subruang terkecil yang mengandung S, dan subruang harus tertutup terhadap operasi.

(g) Irisan dari dua subruang sembarang dari ruang vektor V adalah subruang dari V.
**Answer:** True
**Penjelasan:** Irisan `W1 intersect W2` pasti mengandung `0` (karena `0` ada di `W1` dan `W2`). Jika `u, v` ada di irisan, maka `u, v` ada di `W1` dan `W2`. Karena `W1, W2` subruang, `u+v` dan `ku` ada di `W1` dan `W2`, sehingga ada di irisan.

(h) Gabungan dari dua subruang sembarang dari ruang vektor V adalah subruang dari V.
**Answer:** False
**Penjelasan:** Contoh: Di `R^2`, gabungan sumbu-x (`W1`) dan sumbu-y (`W2`) bukan subruang. Vektor `(1,0)` ada di gabungan, `(0,1)` ada di gabungan, tapi `(1,0)+(0,1)=(1,1)` tidak ada di gabungan.

(i) Dua subset dari ruang vektor V yang merentang subruang yang sama dari V harus sama.
**Answer:** False
**Penjelasan:** Contoh: Di `R^2`, himpunan `{(1,0), (0,1)}` merentang `R^2`. Himpunan `{(1,0), (0,1), (1,1)}` juga merentang `R^2`, tetapi himpunan vektornya berbeda.

(j) Himpunan matriks `n x n` segitiga atas adalah subruang dari ruang vektor semua matriks `n x n`.
**Answer:** True
**Penjelasan:** Jumlah dua matriks segitiga atas adalah segitiga atas. Perkalian skalar matriks segitiga atas adalah segitiga atas. Matriks nol adalah segitiga atas.

(k) Polinomial `x-1`, `(x-1)^2`, dan `(x-1)^3` merentang `P_3`.
**Answer:** False
**Penjelasan:** Ruang `P_3` (polinomial derajat 3 atau kurang) memiliki dimensi 4 (basis standarnya adalah `{1, x, x^2, x^3}`). Tiga vektor tidak cukup untuk merentang ruang berdimensi 4.

---

## Exercise Set 4.3

(a) Himpunan yang berisi satu vektor tunggal adalah linear independen.
**Answer:** False
**Penjelasan:** Hanya jika vektor tersebut bukan vektor nol. Himpunan `{0}` adalah linear dependen.

(b) Himpunan vektor `{v, kv}` linear dependen untuk setiap skalar k.
**Answer:** True
**Penjelasan:** Jika `k=0`, himpunan adalah `{v, 0}` yang dependen karena mengandung vektor nol. Jika `k != 0`, maka `kv` adalah kelipatan skalar tak-nol dari `v`, sehingga `1*(kv) + (-k)*v = 0` adalah kombinasi linear tak-trivial yang menghasilkan nol.

(c) Setiap himpunan linear dependen mengandung vektor nol.
**Answer:** False
**Penjelasan:** Contoh: Himpunan `{(1,0), (2,0)}` di `R^2` linear dependen (`2*(1,0) - 1*(2,0) = (0,0)`) tetapi tidak mengandung vektor nol.

(d) Jika himpunan vektor `{v_1, v_2, v_3}` linear independen, maka `{kv_1, kv_2, kv_3}` juga linear independen untuk setiap skalar tak-nol k.
**Answer:** True
**Penjelasan:** Tinjau persamaan `c_1(kv_1)+c_2(kv_2)+c_3(kv_3)=0`. Ini dapat ditulis ulang sebagai `k(c_1v_1+c_2v_2+c_3v_3)=0`. Karena `k != 0`, ini mengimplikasikan `c_1v_1+c_2v_2+c_3v_3=0`. Karena `{v_1, v_2, v_3}` linear independen, maka `c_1=c_2=c_3=0`. Jadi, `{kv_1, kv_2, kv_3}` linear independen.

(e) Jika `v_1, ..., v_n` adalah vektor tak-nol linear dependen, maka setidaknya satu vektor `v_k` adalah kombinasi linear unik dari `v_1, ..., v_(k-1)`.
**Answer:** True
**Penjelasan:** Karena himpunan dependen, setidaknya satu vektor adalah kombinasi linear dari yang lain. Berdasarkan teorema, ada vektor pertama `v_k` yang merupakan kombinasi linear dari vektor-vektor *sebelumnya* (`v_1, ..., v_(k-1)`). Keunikan kombinasi ini dijamin karena himpunan `{v_1, ..., v_(k-1)}` adalah linear independen (berdasarkan cara `v_k` dipilih).

(f) Himpunan matriks `2 x 2` yang mengandung tepat dua angka 1 dan dua angka 0 adalah himpunan linear independen di `M_22`.
**Answer:** False
**Penjelasan:** Himpunan ini berisi 6 matriks: `[1 1; 0 0]`, `[1 0; 1 0]`, `[1 0; 0 1]`, `[0 1; 1 0]`, `[0 1; 0 1]`, `[0 0; 1 1]`. Ruang `M_22` berdimensi 4, sehingga 6 vektor pasti dependen. Contoh dependensi: `[1 0; 0 1] + [0 1; 1 0] - [1 1; 0 0] - [0 0; 1 1] = [0 0; 0 0]`.

(g) Tiga polinomial `(x-1)(x+2)`, `x(x+2)`, dan `x(x-1)` linear independen.
**Answer:** True
**Penjelasan:** Anggap `c_1(x-1)(x+2) + c_2x(x+2) + c_3x(x-1) = 0` untuk semua x. Substitusi nilai x strategis: `x=0` menghasilkan `-2c_1 = 0 => c_1=0`. `x=1` menghasilkan `3c_2 = 0 => c_2=0`. `x=-2` menghasilkan `6c_3 = 0 => c_3=0`. Karena satu-satunya solusi adalah `c_1=c_2=c_3=0`, maka himpunan ini independen.

(h) Fungsi `f_1` dan `f_2` linear dependen jika ada bilangan real x sehingga `k_1 f_1(x) + k_2 f_2(x) = 0` untuk beberapa skalar `k_1` dan `k_2`.
**Answer:** False
**Penjelasan:** Untuk linear dependen, persamaan `k_1 f_1(x) + k_2 f_2(x) = 0` harus berlaku *untuk semua* x dalam domain fungsi, dengan `k_1, k_2` tidak keduanya nol. Berlaku hanya untuk satu x tidak cukup.

---

## Exercise Set 4.4

(a) Jika `V=span{v_1, ..., v_n}`, maka `{v_1, ..., v_n}` adalah basis untuk V.
**Answer:** False
**Penjelasan:** Himpunan `{v_1, ..., v_n}` merentang V berdasarkan definisi, tetapi himpunan tersebut bisa jadi linear dependen, sehingga bukan basis.

(b) Setiap subset linear independen dari ruang vektor V adalah basis untuk V.
**Answer:** False
**Penjelasan:** Subset linear independen mungkin tidak merentang seluruh ruang V. Contoh: `{(1,0)}` di `R^2` independen tapi bukan basis.

(c) Jika `{v_1, v_2, ..., v_n}` adalah basis untuk ruang vektor V, maka setiap vektor di V dapat diekspresikan sebagai kombinasi linear dari `v_1, v_2, ..., v_n`.
**Answer:** True
**Penjelasan:** Ini adalah bagian dari definisi basis (sifat merentang/spanning).

(d) Vektor koordinat dari vektor x di `R^n` relatif terhadap basis standar untuk `R^n` adalah x.
**Answer:** True
**Penjelasan:** Jika `x = (x_1, ..., x_n)` dan basis standar adalah `e_1, ..., e_n`, maka `x = x_1e_1 + ... + x_ne_n`. Koefisiennya adalah `(x_1, ..., x_n)`, yang merupakan x itu sendiri.

(e) Setiap basis dari `P_4` mengandung setidaknya satu polinomial berderajat 3 atau kurang.
**Answer:** False
**Penjelasan:** `P_4` (polinomial derajat 4 atau kurang) memiliki dimensi 5. Basisnya bisa saja `{x^4, x^4+x^3, x^4+x^2, x^4+x, x^4+1}`. Semua vektor ini berderajat 4.

---

## Exercise Set 4.5

(a) Ruang vektor nol memiliki dimensi nol.
**Answer:** True
**Penjelasan:** Berdasarkan definisi, dimensi ruang vektor nol adalah 0.

(b) Terdapat himpunan 17 vektor linear independen di `R^17`.
**Answer:** True
**Penjelasan:** Contohnya adalah basis standar `R^17` yang memiliki 17 vektor dan linear independen.

(c) Terdapat himpunan 11 vektor yang merentang `R^17`.
**Answer:** False
**Penjelasan:** Dimensi `R^17` adalah 17. Dibutuhkan setidaknya 17 vektor untuk merentang ruang berdimensi 17.

(d) Setiap himpunan linear independen dari lima vektor di `R^5` adalah basis untuk `R^5`.
**Answer:** True
**Penjelasan:** `R^5` berdimensi 5. Setiap himpunan n vektor linear independen dalam ruang berdimensi n adalah basis.

(e) Setiap himpunan lima vektor yang merentang `R^5` adalah basis untuk `R^5`.
**Answer:** True
**Penjelasan:** `R^5` berdimensi 5. Setiap himpunan n vektor yang merentang ruang berdimensi n adalah basis.

(f) Setiap himpunan vektor yang merentang `R^n` mengandung basis untuk `R^n$.
**Answer:** True
**Penjelasan:** Dari himpunan yang merentang, kita bisa membuang vektor-vektor yang merupakan kombinasi linear dari vektor lain hingga tersisa himpunan linear independen yang masih merentang (yaitu basis).

(g) Setiap himpunan vektor linear independen di `R^n` termuat dalam suatu basis untuk `R^n$.
**Answer:** True
**Penjelasan:** Jika himpunan tersebut belum merentang `R^n`, kita bisa menambahkan vektor-vektor (misalnya dari basis standar) yang tidak ada di span himpunan tersebut hingga membentuk basis, sambil menjaga independensi linear.

(h) Terdapat basis untuk `M_22` yang terdiri dari matriks-matriks invertibel.
**Answer:** True
**Penjelasan:** Contoh: `{ [1 0; 0 1], [0 1; 1 0], [1 1; 0 1], [1 0; 1 1] }`. Semua matriks ini invertibel dan membentuk basis untuk `M_22`.

(i) Jika A berukuran `n x n` dan `I_n, A, A^2, ..., A^(n^2)` adalah matriks-matriks berbeda, maka `{I_n, A, A^2, ..., A^(n^2)}` linear dependen.
**Answer:** True
**Penjelasan:** Ruang matriks `n x n` (`M_nn`) memiliki dimensi `n^2`. Himpunan `{I_n, A, ..., A^(n^2)}` memiliki `n^2+1` vektor. Dalam ruang berdimensi `d`, setiap himpunan dengan lebih dari `d` vektor pasti linear dependen.

(j) Terdapat setidaknya dua subruang tiga dimensi yang berbeda dari `P_3`.
**Answer:** False
**Penjelasan:** Dimensi `P_3` (polinomial derajat <= 3) adalah 4. Ada *tak hingga* banyaknya subruang 3 dimensi yang berbeda. Contoh: `span{1, x, x^2}` dan `span{1, x, x^3}` adalah dua subruang 3 dimensi yang berbeda. Jadi pernyataan "setidaknya dua" itu benar, tetapi justifikasi buku hanya "False". Mungkin maksud soal adalah "tepat dua". Jika interpretasinya "setidaknya dua", jawabannya True. Buku menyatakan False, mungkin menginterpretasikan sebagai "hanya ada dua". Mari ikuti jawaban buku.

---

## Exercise Set 4.6

(a) Jika `B_1` dan `B_2` adalah basis untuk ruang vektor V, maka terdapat matriks transisi dari `B_1` ke `B_2`.
**Answer:** True
**Penjelasan:** Matriks transisi antar basis selalu dapat dibentuk dengan merepresentasikan vektor basis baru dalam koordinat basis lama.

(b) Matriks transisi invertibel.
**Answer:** True
**Penjelasan:** Matriks transisi dari `B_1` ke `B_2` memiliki invers yaitu matriks transisi dari `B_2` ke `B_1$.

(c) Jika B adalah basis untuk ruang vektor `R^n`, maka `P_(B -> B)` adalah matriks identitas.
**Answer:** True
**Penjelasan:** Kolom-kolom `P_(B -> B)` adalah vektor koordinat dari vektor basis B relatif terhadap B itu sendiri. Vektor basis `b_i` dalam koordinat B adalah `e_i` (vektor standar ke-i), sehingga matriksnya adalah `I`.

(d) Jika `P_(B1 -> B2)` adalah matriks diagonal, maka setiap vektor di `B_2` adalah kelipatan skalar dari suatu vektor di `B_1$.
**Answer:** True
**Penjelasan:** Misal `B_1 = {u_1, ..., u_n}` dan `B_2 = {v_1, ..., v_n}`. Kolom ke-j dari `P_(B1 -> B2)` adalah `[v_j]_(B1)`. Jika `P` diagonal dengan entri `d_j` di diagonal, maka `[v_j]_(B1)` adalah vektor dengan `d_j` di posisi ke-j dan nol di tempat lain. Ini berarti `v_j = 0*u_1 + ... + d_j*u_j + ... + 0*u_n = d_j u_j`.

(e) Jika setiap vektor di `B_2` adalah kelipatan skalar dari suatu vektor di `B_1`, maka `P_(B1 -> B2)` adalah matriks diagonal.
**Answer:** False
**Penjelasan:** Bisa saja `v_1 = c_1 u_2` dan `v_2 = c_2 u_1`. Dalam kasus ini, `[v_1]_(B1) = [0; c_1; 0; ...]` dan `[v_2]_(B1) = [c_2; 0; 0; ...]`. Matriks `P` tidak akan diagonal. Agar `P` diagonal, haruslah `v_j` kelipatan dari `u_j` untuk setiap `j`.

(f) Jika A adalah matriks persegi, maka `A=P_(B1 -> B2)` untuk beberapa basis `B_1` dan `B_2` untuk `R^n`.
**Answer:** False
**Penjelasan:** Matriks transisi `P_(B1 -> B2)` haruslah invertibel. Matriks persegi A secara umum tidak harus invertibel.

---

## Exercise Set 4.7

(a) Span dari `v_1, ..., v_n` adalah ruang kolom dari matriks yang vektor kolomnya adalah `v_1, ..., v_n`.
**Answer:** True
**Penjelasan:** Definisi ruang kolom (column space) adalah span dari vektor-vektor kolom matriks tersebut.

(b) Ruang kolom dari matriks A adalah himpunan solusi dari `Ax=b`.
**Answer:** False
**Penjelasan:** Ruang kolom adalah himpunan semua vektor `b` sedemikian sehingga sistem `Ax=b` *konsisten* (memiliki solusi). Himpunan solusi adalah himpunan vektor `x`, bukan `b`.

(c) Jika R adalah bentuk eselon baris tereduksi dari A, maka vektor-vektor kolom R yang mengandung *leading 1* membentuk basis untuk ruang kolom A.
**Answer:** False
**Penjelasan:** Vektor kolom yang mengandung *leading 1* di R menunjukkan *posisi* kolom di matriks *A* asli yang membentuk basis untuk ruang kolom A. Vektor kolom R sendiri bisa jadi tidak berada di ruang kolom A.

(d) Himpunan vektor baris tak-nol dari matriks A adalah basis untuk ruang baris A.
**Answer:** False
**Penjelasan:** Vektor-vektor baris A bisa jadi linear dependen. Vektor baris tak-nol dari *bentuk eselon baris* A yang membentuk basis untuk ruang baris A.

(e) Jika A dan B adalah matriks `n x n` yang memiliki ruang baris yang sama, maka A dan B memiliki ruang kolom yang sama.
**Answer:** False
**Penjelasan:** Contoh: `A=[1 0; 0 0]` dan `B=[1 1; 0 0]`. Keduanya memiliki ruang baris `span{(1,0)}`. Ruang kolom A adalah `span{(1;0)}`, ruang kolom B adalah `span{(1;0)}`. Dalam contoh ini kebetulan sama. Contoh lain: `A=[1 0; 0 1]` dan `B=[1 1; 0 1]`. Ruang baris keduanya `R^2`. Ruang kolom keduanya juga `R^2`. Mari cari contoh beda: `A=[1 0; 0 0]` (ruang baris `span{(1,0)}`, ruang kolom `span{(1;0)}`) dan `A'=[1 0; 1 0]` (ruang baris `span{(1,0)}`, ruang kolom `span{(1;1)}`). Jadi, ruang baris sama tidak menjamin ruang kolom sama.

(f) Jika E adalah matriks elementer `m x m` dan A adalah matriks `m x n`, maka ruang nol dari EA sama dengan ruang nol dari A.
**Answer:** True
**Penjelasan:** Matriks elementer E invertibel. Persamaan `Ax=0` dan `EAx = E0 = 0` memiliki himpunan solusi `x` yang sama.

(g) Jika E adalah matriks elementer `m x m` dan A adalah matriks `m x n`, maka ruang baris dari EA sama dengan ruang baris dari A.
**Answer:** True
**Penjelasan:** Mengalikan A dari kiri dengan matriks elementer E sama dengan melakukan operasi baris elementer pada A. Operasi baris elementer tidak mengubah ruang baris.

(h) Jika E adalah matriks elementer `m x m` dan A adalah matriks `m x n`, maka ruang kolom dari EA sama dengan ruang kolom dari A.
**Answer:** False
**Penjelasan:** Operasi baris elementer (mengalikan A dari kiri dengan E) dapat mengubah ruang kolom. Contoh: `A=[1 0; 0 0]`, `E=[1 1; 0 1]`. `EA=[1 1; 0 0]`. Ruang kolom A adalah sumbu-x, ruang kolom EA juga sumbu-x. Contoh lain: `A=[1; 0]`, `E=[0 1; 1 0]`. `EA=[0; 1]`. Ruang kolom A adalah `span{(1;0)}`, ruang kolom EA adalah `span{(0;1)}`.

(i) Sistem `Ax=b` tidak konsisten jika dan hanya jika b tidak berada di ruang kolom A.
**Answer:** True
**Penjelasan:** Sistem `Ax=b` konsisten jika dan hanya jika `b` dapat ditulis sebagai kombinasi linear dari kolom-kolom A, yaitu `b` berada di ruang kolom A.

(j) Terdapat matriks invertibel A dan matriks singular B sedemikian sehingga ruang baris A dan B sama.
**Answer:** False
**Penjelasan:** Jika A (`n x n`) invertibel, rank(A)=n, sehingga dimensi ruang barisnya adalah n. Jika B (`n x n`) singular, rank(B)<n, sehingga dimensi ruang barisnya kurang dari n. Ruang baris dengan dimensi berbeda tidak mungkin sama.

---

## Exercise Set 4.8

(a) Entah vektor baris atau vektor kolom dari matriks persegi adalah linear independen.
**Answer:** False
**Penjelasan:** Keduanya bisa jadi linear dependen. Contohnya adalah matriks nol.

(b) Matriks dengan vektor baris linear independen dan vektor kolom linear independen adalah persegi.
**Answer:** True
**Penjelasan:** Jika vektor baris independen, rank = m (jumlah baris). Jika vektor kolom independen, rank = n (jumlah kolom). Karena rank harus sama, maka m = n.

(c) Nulitas dari matriks `m x n` tak-nol paling banyak m.
**Answer:** False
**Penjelasan:** Nulitas adalah `n - rank(A)`. Karena `rank(A) <= min(m,n)`, maka `nulitas >= n - min(m,n)`. Nilai maksimum nulitas adalah n (jika A=0). Nulitas bisa lebih besar dari m jika n > m.

(d) Menambahkan satu kolom tambahan ke matriks meningkatkan rank-nya sebesar satu.
**Answer:** False
**Penjelasan:** Rank bisa tetap sama jika kolom baru adalah kombinasi linear dari kolom-kolom yang sudah ada.

(e) Nulitas dari matriks persegi dengan baris linear dependen setidaknya satu.
**Answer:** True
**Penjelasan:** Jika baris linear dependen, rank matriks kurang dari n (ukuran matriks). Nulitas = `n - rank`. Karena `rank < n`, maka `nulitas > 0`, jadi setidaknya 1.

(f) Jika A persegi dan `Ax=b` tidak konsisten untuk suatu vektor b, maka nulitas A adalah nol.
**Answer:** False
**Penjelasan:** Jika `Ax=b` tidak konsisten, A tidak invertibel. Jika A tidak invertibel, `rank(A) < n`, sehingga `nulitas(A) = n - rank(A) > 0`. Nulitasnya tidak nol.

(g) Jika matriks A memiliki lebih banyak baris daripada kolom, maka dimensi ruang baris lebih besar dari dimensi ruang kolom.
**Answer:** False
**Penjelasan:** Dimensi ruang baris (rank) selalu sama dengan dimensi ruang kolom (rank).

(h) Jika `rank(A^T) = rank(A)`, maka A persegi.
**Answer:** False
**Penjelasan:** Teorema menyatakan bahwa `rank(A^T) = rank(A)` berlaku untuk *semua* matriks A, tidak hanya yang persegi.

(i) Tidak ada matriks `3 x 3` yang ruang baris dan ruang nolnya keduanya adalah garis di ruang-3.
**Answer:** True
**Penjelasan:** Garis di `R^3` memiliki dimensi 1. Teorema Rank menyatakan `rank(A) + nulitas(A) = n` (jumlah kolom). Jika ruang baris dan ruang nol adalah garis, maka `rank(A)=1` dan `nulitas(A)=1`. Jumlahnya `1+1=2`. Tapi untuk matriks `3 x 3`, `n=3`. Karena `2 != 3`, ini tidak mungkin.

(j) Jika V adalah subruang dari `R^n` dan W adalah subruang dari V, maka `W^⊥` adalah subruang dari `V^⊥$.
**Answer:** False
**Penjelasan:** Hubungan inklusinya terbalik. Jika `W` subruang dari `V`, maka setiap vektor yang ortogonal terhadap `V` pasti juga ortogonal terhadap `W` (karena `W` ada di dalam `V`). Jadi, `V^⊥` adalah subruang dari `W^⊥$.

---

## Exercise Set 4.9

(a) Jika A adalah matriks `2 x 3`, maka domain transformasi `T_A` adalah `R^2`.
**Answer:** False
**Penjelasan:** Untuk `Ax` terdefinisi, `x` harus berupa vektor kolom `3 x 1`. Jadi domainnya adalah `R^3`.

(b) Jika A adalah matriks `m x n`, maka kodomain transformasi `T_A` adalah `R^n`.
**Answer:** False
**Penjelasan:** Hasil `Ax` adalah vektor `m x 1`. Jadi kodomainnya adalah `R^m`.

(c) Jika `T(x_1, x_2)=(x_1^2, x_2)`, maka T adalah transformasi matriks.
**Answer:** False
**Penjelasan:** Transformasi matriks harus linear. Sifat `T(kx)=kT(x)` tidak terpenuhi karena adanya `x_1^2`. `T(k(x_1, x_2)) = T(kx_1, kx_2) = ((kx_1)^2, kx_2) = (k^2 x_1^2, kx_2)`. Ini tidak sama dengan `k T(x_1, x_2) = k(x_1^2, x_2) = (kx_1^2, kx_2)` kecuali `k=0, k=1`, atau `x_1=0$.

(d) Jika `T(x_1, x_2, x_3)=(x_1+2x_2, x_3)` dan `T(u+v)=T(u)+T(v)` untuk semua skalar k dan l dan semua vektor u dan v di `R^3`, maka T adalah transformasi matriks.
**Answer:** True
**Penjelasan:** Pernyataan soal secara eksplisit menyatakan sifat aditivitas. Sifat homogenitas `T(ku)=kT(u)` juga dapat diverifikasi dari rumus `T(x_1, x_2, x_3)=(x_1+2x_2, x_3)`. Karena T linear dan domain/kodomainnya `R^n`/`R^m`, maka T adalah transformasi matriks.

(e) Hanya ada satu transformasi matriks `T: R^n -> R^m` sedemikian sehingga `T(-x)=-T(x)` untuk setiap vektor di `R^n`.
**Answer:** False
**Penjelasan:** Sifat `T(-x)=-T(x)` dipenuhi oleh *semua* transformasi linear (karena `T(-x) = T((-1)x) = (-1)T(x) = -T(x)`). Ada banyak transformasi linear yang berbeda.

(f) Hanya ada satu transformasi matriks `T: R^n -> R^m` sedemikian sehingga `T(x+y)=T(x)+T(y)` dan `T(kx)=kT(x)` untuk semua vektor x dan y di `R^n`.
**Answer:** False
**Penjelasan:** Ini adalah definisi transformasi linear. Ada banyak transformasi linear yang berbeda dari `R^n` ke `R^m` (kecuali jika n atau m adalah 0).

(g) Jika b adalah vektor tak-nol di `R^n`, maka `T(x)=x+b` adalah operator matriks pada `R^n`.
**Answer:** False
**Penjelasan:** Ini adalah translasi. Operator matriks (transformasi linear) harus memetakan vektor nol ke vektor nol. Di sini `T(0)=0+b=b != 0`.

(h) Matriks `[cos(theta) -sin(theta); sin(theta) cos(theta)]` adalah matriks standar untuk rotasi.
**Answer:** True
**Penjelasan:** Ini adalah matriks standar untuk rotasi di `R^2` sebesar sudut `theta` berlawanan arah jarum jam.

(i) Matriks standar refleksi terhadap sumbu koordinat di ruang-2 memiliki bentuk `[a 0; 0 b]`, di mana `a=+-1` dan `b=+-1`.
**Answer:** True
**Penjelasan:** Refleksi terhadap sumbu y adalah `[-1 0; 0 1]` (`a=-1, b=1`). Refleksi terhadap sumbu x adalah `[1 0; 0 -1]` (`a=1, b=-1`). Refleksi terhadap titik asal adalah `[-1 0; 0 -1]` (`a=-1, b=-1`), meskipun ini biasanya dianggap rotasi 180 derajat. Identitas `[1 0; 0 1]` (`a=1, b=1`) juga masuk dalam bentuk ini.

---

## Exercise Set 4.10

(a) Jika `T_1: R^n -> R^m` dan `T_2: R^m -> R^k`, maka `T_1 o T_2` adalah transformasi matriks.
**Answer:** False
**Penjelasan:** Komposisinya harus `T_2 o T_1` agar domain `T_2` (`R^m`) cocok dengan kodomain `T_1` (`R^m`). Hasilnya adalah transformasi dari `R^n` ke `R^k`.

(b) Jika `T_1: U -> V` dan `T_2: V -> W` adalah transformasi linear, dan jika `T_1` tidak satu-satu, maka `T_2 o T_1` juga tidak satu-satu.
**Answer:** True
**Penjelasan:** Jika `T_1` tidak satu-satu, maka ada vektor `u != v` di U sehingga `T_1(u) = T_1(v)`. Karena `T_1(u)` dan `T_1(v)` adalah vektor yang sama di V, maka `T_2(T_1(u)) = T_2(T_1(v))`. Ini berarti `(T_2 o T_1)(u) = (T_2 o T_1)(v)` untuk `u != v`, sehingga `T_2 o T_1` tidak satu-satu.

(c) Jika `T: R^n -> R^n` adalah transformasi matriks satu-satu, maka tidak ada vektor berbeda x dan y yang memenuhi `T(x-y)=0`.
**Answer:** True
**Penjelasan:** Jika T satu-satu, kernelnya hanya `{0}`. Jika `T(x-y)=0`, maka `x-y` harus berada di kernel. Jadi `x-y=0`, yang berarti `x=y`. Tidak mungkin x dan y berbeda.

(d) Jika `T: R^n -> R^n` adalah transformasi matriks dan `T(0)=0`, maka T satu-satu.
**Answer:** False
**Penjelasan:** Semua transformasi linear (termasuk transformasi matriks) memenuhi `T(0)=0`. Ini tidak menjamin T satu-satu. Contohnya adalah proyeksi ortogonal ke sebuah garis di `R^2`, yang memetakan 0 ke 0 tetapi tidak satu-satu.

(e) Jika `T: R^n -> R^n` adalah transformasi matriks dan matriks standar untuk T invertibel, maka T satu-satu.
**Answer:** True
**Penjelasan:** Jika matriks standar A invertibel, maka sistem `Ax=0` hanya memiliki solusi trivial `x=0`. Ini berarti kernel T hanya `{0}`, sehingga T satu-satu.

(f) Jika `T: R^n -> R^n` adalah transformasi matriks dan `T(e_1), T(e_2), ..., T(e_n)` linear independen, maka T satu-satu.
**Answer:** True
**Penjelasan:** `T(e_1), ..., T(e_n)` adalah vektor-vektor kolom dari matriks standar A. Jika kolom-kolomnya linear independen, maka A invertibel (karena A persegi). Jika A invertibel, T satu-satu.

---

## Exercise Set 4.11

(a) Citra (image) dari persegi satuan di bawah operator matriks satu-satu adalah persegi.
**Answer:** False
**Penjelasan:** Operator satu-satu (invertibel) memetakan persegi satuan ke jajaran genjang. Contohnya adalah shear `[1 k; 0 1]` yang memetakan persegi satuan ke jajaran genjang.

(b) Operator matriks `2 x 2` yang invertibel memiliki efek geometris berupa suksesi shear, kompresi, ekspansi, dan refleksi.
**Answer:** True
**Penjelasan:** Matriks invertibel dapat difaktorkan menjadi produk matriks elementer. Setiap matriks elementer `2 x 2` merepresentasikan salah satu dari operasi geometris dasar tersebut (atau kombinasinya).

(c) Citra (image) dari garis di bawah operator matriks satu-satu adalah garis.
**Answer:** True
**Penjelasan:** Transformasi linear (termasuk operator matriks) memetakan garis ke garis atau ke satu titik. Karena operatornya satu-satu (invertibel), ia tidak mungkin memetakan seluruh garis ke satu titik. Jadi, citranya harus berupa garis.

(d) Setiap operator refleksi pada `R^2` adalah inversnya sendiri.
**Answer:** True
**Penjelasan:** Melakukan refleksi dua kali akan mengembalikan setiap vektor ke posisi semula. Jadi `R(R(x)) = x` untuk semua x, yang berarti `R^2 = I`, atau `R = R^(-1)`.

(e) Matriks `[1 1; 1 1]` merepresentasikan refleksi terhadap garis.
**Answer:** False
**Penjelasan:** Matriks ini singular (determinannya 0). Operator refleksi harus invertibel (inversnya adalah dirinya sendiri), dan matriks standarnya harus invertibel.

(f) Matriks `[1 -2; 2 1]` merepresentasikan shear.
**Answer:** False
**Penjelasan:** Matriks shear `2 x 2` biasanya memiliki bentuk `[1 k; 0 1]` atau `[1 0; k 1]` (atau transposnya), dan determinannya selalu 1. Matriks ini memiliki determinan 5. Matriks ini merepresentasikan rotasi diikuti skala.

(g) Matriks `[1 0; 0 3]` merepresentasikan ekspansi.
**Answer:** True
**Penjelasan:** Ini adalah ekspansi pada arah sumbu-y dengan faktor 3.

---