Anda meminta Glosarium (Daftar Istilah) komprehensif yang mencakup SEMUA terminologi dalam lingkup Teori Matriks dan Vektor, berdasarkan HANYA pada salindia (PPT) dan kutipan buku yang telah Anda unggah.

Berikut adalah daftar istilah yang disusun dari sumber-sumber tersebut, diurutkan berdasarkan bab atau topik kemunculannya untuk memudahkan peninjauan teoretis.

---

## Glosarium Komprehensif: Teori Matriks dan Vektor

### I. Matriks dan Sistem Persamaan Linier (SPL)

|No.|Terminologi (Istilah)|Definisi/Penjelasan Teoritis|Sumber Rujukan|
|:-:|:--|:--|:--|
|1.|**Matriks**|Susunan bilangan berbentuk persegi panjang atau larik persegi panjang bilangan riil. Merupakan representasi data yang sangat penting di bidang informatika, antara lain untuk representasi graf dan citra digital.||
|2.|**Ukuran Matriks ($m \times n$)**|Matriks yang memiliki $m$ baris (horizontal) dan $n$ kolom (vertikal).||
|3.|**Entri ($a_{ij}$)**|Bilangan di dalam larik matriks, terletak di baris $i$ dan kolom $j$.||
|4.|**Matriks Persegi (Square Matrix)**|Matriks yang memiliki jumlah baris ($m$) dan jumlah kolom ($n$) yang sama ($m=n$). Juga disebut ordo $n$.||
|5.|**Diagonal Utama (Main Diagonal)**|Entri-entri matriks persegi dari kiri atas ke kanan bawah.||
|6.|**Skalar (Scalar)**|Kuantitas numerik (bilangan).||
|7.|**Matriks Nol (Zero Matrix)**|Matriks yang seluruh elemennya bernilai nol. Dilambangkan dengan $0$.||
|8.|**Matriks Identitas (Identity Matrix, $I$)**|Matriks persegi yang semua elemen bernilai 1 pada diagonal utamanya dan bernilai 0 pada posisi lainnya. Sifat: $AI = IA = A$.||
|9.|**Matriks Balikan (Inverse, $A^{-1}$)**|Matriks $B$ (dengan ukuran yang sama) sedemikian sehingga $AB = BA = I$. Matriks yang memiliki balikan disebut **invertibel** (nonsingular).||
|10.|**Matriks Singular (Singular Matrix)**|Matriks persegi yang **tidak memiliki balikan** (_not invertible_). Ini terjadi jika determinannya sama dengan nol ($ad - bc = 0$ untuk $2 \times 2$).||
|11.|**Transpose Matriks ($A^T$)**|Matriks yang dihasilkan dengan mempertukarkan baris dan kolom $A$. Entry di baris $i$ dan kolom $j$ dari $A^T$ adalah entry di baris $j$ dan kolom $i$ dari $A$.||
|12.|**Trace Matriks ($tr(A)$)**|Jumlah semua elemen pada diagonal utama matriks persegi $A$. Tidak terdefinisi jika $A$ bukan matriks persegi.||
|13.|**Kombinasi Linier Matriks (Linear Combination)**|Ekspresi dari bentuk $c_1 A_1 + c_2 A_2 + \dots + c_k A_k$, di mana $A_1, \dots, A_k$ adalah matriks berukuran sama dan $c_1, \dots, c_k$ adalah skalar. Perkalian matriks dapat dipandang sebagai kombinasi linier.||
|14.|**Sistem Persamaan Linier (SPL)**|Sistem persamaan di mana pangkat tertinggi di dalam variabelnya sama dengan 1. Dapat dinyatakan dalam bentuk matriks $Ax = b$.||
|15.|**SPL Homogen (Homogeneous Linear System)**|SPL di mana semua konstanta di ruas kanan (suku $b$) adalah nol ($Ax = 0$).||
|16.|**Solusi Trivial (Trivial Solution)**|Solusi $x_1 = 0, x_2 = 0, \dots, x_n = 0$ yang selalu dimiliki oleh SPL homogen.||
|17.|**Solusi Non-trivial (Nontrivial Solution)**|Solusi lain selain solusi trivial pada SPL homogen.||
|18.|**SPL Konsisten (Consistent SPL)**|SPL yang memiliki paling sedikit satu solusi (baik tunggal atau banyak).||
|19.|**SPL Inkonsisten (Inconsistent SPL)**|SPL yang tidak memiliki solusi sama sekali.||
|20.|**Matriks Diperluas (Augmented Matrix)**|Matriks yang terdiri dari matriks koefisien ($A$) yang digabung dengan kolom konstanta di ruas kanan ($b$), dilambangkan $[A|b]$.|
|21.|**Operasi Baris Elementer (OBE)**|Tiga operasi dasar pada baris matriks augmented: perkalian baris dengan konstanta tak nol, pertukaran baris, dan penambahan kelipatan baris lain. OBE tidak mengubah solusi SPL.||
|22.|**Matriks Eselon Baris (MEB)**|Matriks yang memenuhi tiga sifat (memiliki 1 utama/leading one, baris nol di bawah, dan 1 utama yang lebih rendah terletak lebih ke kanan).||
|23.|**1 Utama (Leading One)**|Bilangan tidak nol pertama di dalam baris tak nol pada MEB yang bernilai 1.||
|24.|**Matriks Eselon Baris Tereduksi (MEBT)**|MEB yang memenuhi sifat tambahan: setiap kolom yang memiliki 1 utama, memiliki nol di tempat lain (di bawah dan di atas 1 utama).||
|25.|**Variabel Utama (Leading Variables)**|Variabel dalam SPL yang berkorespondensi dengan kolom yang memiliki 1 utama pada MEBT.||
|26.|**Variabel Bebas (Free Variables)**|Variabel yang tersisa (tidak berkorespondensi dengan 1 utama).||
|27.|**Solusi Umum (General Solution)**|Sekumpulan persamaan parametrik yang menyatakan solusi tak berhingga banyaknya dari SPL konsisten dengan menetapkan nilai numerik pada parameter.||
|28.|**Eliminasi Gauss (Gaussian Elimination)**|Metode penyelesaian SPL di mana OBE diterapkan sampai matriks augmented terbentuk MEB, lalu diselesaikan dengan penyulihan mundur (backward substitution).||
|29.|**Eliminasi Gauss-Jordan (Gauss-Jordan Elimination)**|Metode penyelesaian SPL di mana OBE diterapkan sampai matriks augmented terbentuk MEBT.||

### II. Determinan

|No.|Terminologi (Istilah)|Definisi/Penjelasan Teoritis|Sumber Rujukan|
|:-:|:--|:--|:--|
|30.|**Determinan ($det(A)$)**|Nilai skalar yang diasosiasikan dengan matriks persegi $A$ ($n \times n$). Matriks $A$ invertibel jika dan hanya jika $det(A) \neq 0$.||
|31.|**Minor ($M_{ij}$)**|Determinan dari submatriks yang tersisa setelah baris $i$ dan kolom $j$ dihapus dari $A$.||
|32.|**Kofaktor ($C_{ij}$)**|$C_{ij} = (-1)^{i+j} M_{ij}$. Kofaktor dan minor memiliki nilai yang sama atau negatifnya, tergantung tanda checkerboard.||
|33.|**Ekspansi Kofaktor (Cofactor Expansion)**|Cara menghitung determinan dengan menjumlahkan hasil kali entri dalam satu baris/kolom dengan kofaktor yang bersesuaian.||
|34.|**Matriks Segitiga (Triangular Matrix)**|Matriks persegi di mana semua entri di atas diagonal utama nol (bawah) atau semua entri di bawah diagonal utama nol (atas). $det(A)$ adalah hasil kali diagonal utama.||
|35.|**Matriks Kofaktor (Cofactor Matrix)**|Matriks yang entrinya adalah kofaktor $C_{ij}$ dari matriks $A$.||
|36.|**Adjoin ($adj(A)$)**|Transpose dari matriks kofaktor. Digunakan untuk mencari invers matriks: $A^{-1} = \frac{1}{det(A)} adj(A)$.||
|37.|**Kaidah Cramer (Cramer's Rule)**|Formula yang memberikan solusi unik $x_j = \frac{det(A_j)}{det(A)}$ untuk SPL $Ax=b$, asalkan $det(A) \neq 0$. $A_j$ adalah matriks yang kolom ke-$j$-nya diganti dengan $b$.||

### III. Vektor di Ruang Euclidean ($R^n$)

|No.|Terminologi (Istilah)|Definisi/Penjelasan Teoritis|Sumber Rujukan|
|:-:|:--|:--|:--|
|38.|**Vektor**|Kuantitas fisik yang memiliki **besar (magnitude)** dan **arah (direction)**. Dapat direpresentasikan secara geometri sebagai garis berarah, atau secara aljabar sebagai n-tupel.||
|39.|**Skalar**|Kuantitas fisik yang dapat dijelaskan dengan nilai numerik saja (besar).||
|40.|**Komponen Vektor**|Koordinat titik terminal vektor yang berawal dari titik asal.||
|41.|**Ruang Euclidean ($R^n$)**|Himpunan semua n-tupel berurutan bilangan riil. Disebut juga $n$-space.||
|42.|**Vektor Nol ($0$)**|Vektor yang semua komponennya 0.||
|43.|**Vektor Ekuivalen (Equal/Equivalent Vectors)**|Dua vektor yang memiliki panjang dan arah yang sama; atau, jika dan hanya jika komponen-komponen yang bersesuaian sama.||
|44.|**Vektor Sejajar/Koliner (Parallel/Collinear)**|Dua vektor di $R^n$ dikatakan sejajar/koliner jika salah satu vektor adalah perkalian skalar dari yang lain.||
|45.|**Norma (Norm, $\|v\|$ )**|
|46.|**Vektor Satuan (Unit Vector)**|Vektor dengan norma (panjang) sama dengan 1.||
|47.|**Menormalisasi Vektor (Normalizing)**|Proses membagi vektor tak nol dengan panjangnya (mengalikan vektor dengan kebalikan dari panjangnya) untuk mendapatkan vektor satuan.||
|48.|**Vektor Satuan Standar (Standard Unit Vectors)**|Vektor satuan di sepanjang sumbu koordinat positif, dilambangkan $e_1, e_2, \dots, e_n$ di $R^n$.||
|49.|**Jarak Euclidean (Distance, $d(u, v)$)**|Jarak antara dua titik $u$ dan $v$ di $R^n$, didefinisikan sebagai $d(u, v) = \|u - v\|
|50.|**Perkalian Titik (Dot Product, $\mathbf{u} \cdot \mathbf{v}$)**|Juga disebut **Euclidean Inner Product**. Didefinisikan: $\mathbf{u} \cdot \mathbf{v} = u_1v_1 + u_2v_2 + \dots + u_nv_n$. Secara geometris: $\mathbf{u} \cdot \mathbf{v} = \|\mathbf{u}\|
|51.|**Vektor Ortogonal (Orthogonal Vectors)**|Dua vektor $u$ dan $v$ tak nol di $R^n$ yang tegak lurus, yaitu jika dan hanya jika $\mathbf{u} \cdot \mathbf{v} = 0$. Vektor nol ortogonal terhadap setiap vektor.||
|52.|**Himpunan Ortogonal (Orthogonal Set)**|Himpunan vektor di mana semua pasangan vektor berbeda di dalamnya ortogonal.||
|53.|**Himpunan Ortonormal (Orthonormal Set)**|Himpunan ortogonal di mana setiap vektornya adalah vektor satuan.||
|54.|**Proyeksi Ortogonal (Orthogonal Projection)**|Vektor $\text{proj}_{\mathbf{a}} \mathbf{u}$ yang sejajar $\mathbf{a}$ dalam dekomposisi $\mathbf{u} = \mathbf{w}_1 + \mathbf{w}_2$, di mana $\mathbf{w}_1$ adalah proyeksi pada $\mathbf{a}$ dan $\mathbf{w}_2$ ortogonal pada $\mathbf{a}$.||
|55.|**Vektor Normal (Normal Vector)**|Vektor $n$ yang tegak lurus (ortogonal) dengan garis di $R^2$ atau bidang di $R^3$.||
|56.|**Perkalian Silang (Cross Product, $\mathbf{u} \times \mathbf{v}$)**|Operasi yang hanya didefinisikan di $R^3$ yang menghasilkan vektor ortogonal terhadap kedua vektor input. Magnitudonya sama dengan luas jajar genjang yang dibentuk oleh $u$ dan $v$.||
|57.|**Perkalian Triple Skalar (Scalar Triple Product)**|$\mathbf{u} \cdot (\mathbf{v} \times \mathbf{w})$. Nilai mutlaknya sama dengan volume parallelepiped yang dibentuk oleh $u, v, w$.||
|58.|**Ketidaksamaan Cauchy-Schwarz**|Untuk vektor $u, v$ di $R^n$, berlaku $|\mathbf{u} \cdot \mathbf{v}|
|59.|**Teorema Pythagoras (di $\mathbf{R}^n$)**|Jika $u$ dan $v$ ortogonal, maka $\|\mathbf{u} + \mathbf{v}\|

### IV. Ruang Vektor Umum (General Vector Spaces)

|No.|Terminologi (Istilah)|Definisi/Penjelasan Teoritis|Sumber Rujukan|
|:-:|:--|:--|:--|
|60.|**Ruang Vektor (Vector Space)**|Himpunan objek $V$ (disebut vektor), dilengkapi dengan operasi penjumlahan dan perkalian skalar, yang memenuhi 10 aksioma.||
|61.|**Aksioma Ruang Vektor (Vector Space Axioms)**|Sepuluh syarat yang harus dipenuhi $V$. Aksioma 1 (Closure/Tertutup terhadap penjumlahan) dan Aksioma 6 (Closure/Tertutup terhadap perkalian skalar) adalah yang paling dasar.||
|62.|**Subruang (Subspace)**|Subset $W$ dari ruang vektor $V$ yang juga merupakan ruang vektor di bawah operasi yang sama seperti di $V$. $W$ adalah subruang jika dan hanya jika ia tertutup di bawah penjumlahan dan perkalian skalar.||
|63.|**Ruang Nol (Zero Subspace)**|Subruang yang hanya terdiri dari vektor nol, ${0}$.||
|64.|**Kombinasi Linier (Linear Combination)**|Vektor $w$ dapat dinyatakan sebagai $w = k_1 v_1 + k_2 v_2 + \dots + k_r v_r$, di mana $k_i$ adalah skalar.||
|65.|**Himpunan Membangun (Spanning Set, Span)**|Himpunan vektor $S$ dikatakan **membangun** ($span(S)$) subruang $W$ jika setiap vektor di $W$ dapat dinyatakan sebagai kombinasi linier vektor di $S$.||
|66.|**Kebebasan Linier (Linear Independence)**|Himpunan vektor $S = {v_1, \dots, v_r}$ bebas linier jika persamaan $k_1 v_1 + \dots + k_r v_r = 0$ hanya memiliki **solusi trivial** ($k_1 = \dots = k_r = 0$).||
|67.|**Ketergantungan Linier (Linear Dependence)**|Himpunan $S$ tidak bebas linier, yang berarti setidaknya satu vektor di $S$ dapat dinyatakan sebagai kombinasi linier dari vektor-vektor lainnya.||
|68.|**Basis**|Himpunan vektor $S$ adalah basis untuk $V$ jika $S$ **bebas linier** dan $S$ **membangun** $V$. Setiap vektor $v$ di $V$ dapat dinyatakan dalam basis secara **tepat dengan satu cara**.||
|69.|**Basis Standar (Standard Basis)**|Basis yang terdiri dari vektor-vektor satuan standar (misalnya $e_1, \dots, e_n$ untuk $R^n$).||
|70.|**Dimensi ($dim(V)$)**|Banyaknya vektor di dalam basis ruang vektor $V$.||
|71.|**Vektor Koordinat (Coordinate Vector)**|Vektor di $R^n$ yang entrinya adalah skalar $c_i$ yang diperlukan untuk menyatakan vektor $v$ sebagai kombinasi linier dari vektor basis $S$, dilambangkan $(v)_S$ atau $[v]_S$.||
|72.|**Matriks Transisi (Transition Matrix, $P_{B' \to B}$)**|Matriks yang menghubungkan vektor koordinat relatif terhadap basis lama $B$ dengan basis baru $B'$, di mana $[v]_B = P [v]_{B'}$.||
|73.|**Ruang Baris (Row Space)**|Subruang dari $R^n$ yang direntang oleh vektor-vektor baris matriks $A$.||
|74.|**Ruang Kolom (Column Space)**|Subruang dari $R^m$ yang direntang oleh vektor-vektor kolom matriks $A$. SPL $Ax=b$ konsisten jika dan hanya jika $b$ di dalam ruang kolom $A$.||
|75.|**Ruang Null (Null Space)**|Ruang solusi SPL homogen $Ax = 0$ (subruang dari $R^n$). Juga disebut **kernel** dari transformasi $T_A$.||
|76.|**Rank ($rank(A)$)**|Dimensi umum dari ruang baris dan ruang kolom matriks $A$. Rank sama dengan jumlah 1 utama pada MEBT.||
|77.|**Nulitas ($nullity(A)$)**|Dimensi ruang null matriks $A$.||
|78.|**Teorema Dimensi (Dimension Theorem)**|$rank(A) + nullity(A) = n$ (jumlah kolom).||