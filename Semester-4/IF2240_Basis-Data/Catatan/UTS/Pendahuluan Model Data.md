**Data Modeling** merupakan teknik yang mengoptimasisasi cara informasi disimpan dan digunakan dalam sebuah organisasi. Proses ini dimulai dengan mengidentifikasi kelompok-kelompok data utama, kemudian dilanjutkan dengan mendefinisikan isi detail dari setiap kelompok tersebut. Hasilnya adalah definisi terstruktur untuk semua informasi yang disimpan. Terdapat tiga tipe *data model* yang berbeda untuk membuat sebuah *database* dari sebuah *requirement*. 
1. *Conceptual Data Model*. Model ini merupakan model yang independen dengan teknologi. Tujuannya adalah untuk mendiskusikan dan memvalidasi kebutuhan data awal dengan para pemangku kepentingan bisnis, tanpa membicarakan detail teknis implementasi.
- *Logical Data Model*. Model ini berisi struktur dari data yang dapat diimplementasikan dalam *database*. 
- *Physical Data Model*. Model ini mengorganisasi data ke dalam tabel dan memerhatikan akses ke *database*, performa, dan detail penyimpanan.

**Data Model** adalah sebuah kumpulan alat yang digunakan untuk mendeskripsikan hubungan antar data, semantik data, batasan-batasan data, dan data itu sendiri. Beberapa tipe model data adalah.
1. **Entity-Relationship Model**
2. **Relational Model**
3. *Object-Oriented Data Model*. Mengenkapsulasi kode dan objek yang berhubungan dengan data menjadi satu unit.
4. *Object Structure*. Sebuah objek memiliki variabel, *message*, dan *methods* masing-masing.
5. *Object-Relational Data Model*. Menggunakan OO Data Model dengan menambahkan *inheritance* dengan subtipe dan subtabel dengan tetap menggunakan pemodelan *relational*.
6. *Semi Structured Data Model* (misal, XML). Digunakan untuk melakukan pertukaran data. Setiap objek tidak perlu memiliki format kolom dan baris yang sama.
7. *Hierarchical Model*. Merepresentasikan data dan relasi dengan struktur pohon (*tree*).
8. *Network Model*. Merepresentasikan data dan relasi seperti graf.

## Entity-Relationship Model
Sebelum data diubah menjadi bentuk implementasi teknis berupa tabel, model ini pertama-tama memetakan kebutuhan bisnis. Model ini merupakan kumpulan dari *entity* dan *relationship*. *Entity* merupakan sebuah objek dasar yang berbeda dari objek lainnya. Sedangkan, *relationship* adalah hubungan antar entitas.
![[Pasted image 20260221125608.png]]

## Relational Model
Model ini merepresentasikan data dalam kumpulan tabel dua dimensi. Setiap tabel mewakili kelompok data, di mana kolomnya mendefinisikan atribut atau properti dan barisnya menyimpan satu jenis data spesifik.

![[Pasted image 20260221125751.png]]

