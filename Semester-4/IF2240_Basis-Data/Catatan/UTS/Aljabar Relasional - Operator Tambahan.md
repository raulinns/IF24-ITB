## Set-Intersection ($\cap$)
**Set-Intersection** berfungsi untuk menemukan baris-baris data (tuple) yang ada di dalam kedua tabel (irisan).

Set-Intersection didefinisikan dengan

$$r \cap s = \{ t | t \in r \land t \in s \}$$

di mana $r$ dan $s$ adalah relasi yang kompatibel (harus memiliki jumlah atribut yang sama atau ariti yang sama, dan tipe data pada atribut yang bersesuaian harus selaras).

## Natural Join ($\bowtie$)
**Natural Join** berfungsi untuk menggabungkan baris-baris dari dua tabel dengan mencocokkan nilai pada semua atribut yang memiliki nama yang sama persis pada kedua tabel tersebut, serta menyisakan hanya satu salinan untuk setiap kolom yang sama.

Natural Join secara ekuivalen dapat didefinisikan menggunakan operasi dasar sebagai:

$$r \bowtie s = \Pi_{R \cup S} (\sigma_{r.A_1 = s.A_1 \land \dots \land r.A_n = s.A_n} (r \times s))$$

di mana $r$ dan $s$ adalah relasi pada skema $R$ dan $S$, serta $A_1, A_2, \dots, A_n$ adalah atribut-atribut yang beririsan (sama-sama ada) di dalam skema $R$ dan $S$.

Terdapat juga **theta join** yang didefinisikan sebagai berikut.
$$
r \bowtie_{\theta} s = \sigma_{\theta} (r \times s)
$$

## Assignment ($\leftarrow$)
**Assignment** berfungsi untuk memecah kueri aljabar relasional yang kompleks menjadi bagian-bagian yang lebih kecil dengan memberikan nama sementara pada hasil dari suatu evaluasi ekspresi.

Assignment didefinisikan dengan
$$
<\text{nama variabel}>\leftarrow E
$$

di mana hasil dari ekspresi aljabar relasional $E$ disimpan ke dalam variabel relasi sementara yang bernama $\text{nama variabel}$.

## Outer Join ($\sqsubset\bowtie, \bowtie\sqsupset, \sqsubset\bowtie\sqsupset$)
**Outer Join** berfungsi sebagai ekstensi dari operasi _join_ untuk menghindari hilangnya informasi. Operator ini mempertahankan baris-baris data (tuple) yang tidak memiliki pasangan pada relasi lainnya, dengan cara menggunakan nilai _null_ pada atribut yang tidak memiliki nilai.

Outer Join terbagi ke dalam tiga bentuk operasi:
- **Left Outer Join (**$\sqsubset\bowtie$**)**: Mempertahankan semua baris data dari tabel di sisi kiri.
- **Right Outer Join (**$\bowtie\sqsupset$**)**: Mempertahankan semua baris data dari tabel di sisi kanan.
- **Full Outer Join (**$\sqsubset\bowtie\sqsupset$**)**: Mempertahankan semua baris data dari kedua belah tabel.

## Division ($\div$)
**Division** berfungsi untuk mengekstrak data dari relasi pertama yang berpasangan dengan _semua_ baris data yang ada pada relasi kedua (cocok untuk kueri yang mensyaratkan kondisi kelengkapan).

Division didefinisikan dengan
$$
r \div s
$$
di mana jika diberikan relasi $r(R)$ dan $s(S)$, sedemikian sehingga himpunan atribut $S \subset R$, maka $r \div s$ adalah relasi terbesar $t(R-S)$ sedemikian sehingga berlaku $t \times s \subseteq r$.

## Nilai Kosong (Null)
**Null** bukanlah sebuah operator, melainkan representasi dari sebuah nilai yang tidak diketahui atau tidak ada. Operasi yang melibatkan perbandingan (seperti $<, >, =$) dengan nilai _null_ tidak menghasilkan _true_ atau _false_, melainkan menghasilkan nilai kebenaran khusus yaitu **unknown** (tidak diketahui).

Sistem menggunakan logika tiga nilai (_three-valued logic_) untuk menangani _unknown_:
- **OR**: (_unknown_ $\lor$ _true_) = _true_, (_unknown_ $\lor$ _false_) = _unknown_, (_unknown_ $\lor$ _unknown_) = _unknown_
- **AND**: (_true_ $\land$ _unknown_) = _unknown_, (_false_ $\land$ _unknown_) = _false_, (_unknown_ $\land$ _unknown_) = _unknown_
- **NOT**: ($\lnot$ _unknown_) = _unknown_

Catatan: Pada operasi $\sigma$ (Select), baris data akan dianggap _false_ dan tidak disertakan ke dalam hasil jika predikat evaluasinya bernilai _unknown_.

![[Pasted image 20260224161846.png]]