## Definisi Siklus Hidup Objek
Siklus hidup objek (_Object Lifecycle_) adalah rangkaian tahapan yang dilalui oleh sebuah objek di dalam memori komputer. Tahapan ini dimulai dari **penciptaan** (alokasi memori dan inisialisasi state), diikuti oleh masa **penggunaan**, hingga akhirnya **pemusnahan** (dealokasi memori).

Dalam paradigma Pemrograman Berbasis Objek (PBO), objek bukan sekadar struktur data pasif. Objek adalah entitas yang memiliki tanggung jawab dan _state_ (keadaan internal). Desain kelas yang baik harus menjamin bahwa _state_ objek selalu valid selama masa hidupnya. Pengelolaan lifecycle yang tepat sangat krusial untuk mencegah kebocoran memori (_memory leak_) dan perilaku program yang tidak terdefinisi (_undefined behavior_).

## Konstruktor
_Constructor_ (atau sering disebut **ctor**) adalah mekanisme khusus yang dipanggil saat objek lahir untuk memastikan objek tersebut berada dalam keadaan valid atau memenuhi **invariant**-nya.

Jenis-Jenis Constructor:
- *Default Constructor*: Constructor yang tidak menerima parameter. Digunakan saat objek dideklarasikan tanpa argumen (misal: `Stack s;`).
- *User-Defined Constructor*: Constructor yang menerima parameter untuk memberikan nilai awal secara spesifik (misal: `Stack s(100);`).

Teknik Inisialisasi Anggota: Terdapat dua cara untuk memberikan nilai pada atribut kelas di dalam ctor:
1. *Initialization List*: Menggunakan sintaks `: variabel{nilai}` sebelum badan fungsi. Ini membangun anggota objek secara langsung dengan nilai final. Wajib digunakan untuk anggota bertipe `const` dan _reference_ karena mereka harus diberi nilai saat diciptakan.
2. *Assignment di Body*:  Memberikan nilai di dalam kurung kurawal `{}`. Cara ini kurang efisien untuk tipe data kompleks karena objek dibangun terlebih dahulu dengan nilai default, baru kemudian ditimpa (di-assign) dengan nilai baru.

## Destruktor
_Destructor_ (**dtor**) memastikan bahwa saat objek "mati", ia melepaskan semua tanggung jawab dan sumber daya yang dikelolanya.

Karakteristik Utama:
- Namanya sama dengan nama kelas, diawali tanda tilde (`~`).
- Tidak memiliki parameter dan tidak mengembalikan nilai (_no return value_).
- Secara otomatis dieksekusi saat objek keluar dari lingkup (_scope_) atau secara eksplisit melalui operator `delete` untuk objek di _heap_.

Implementasi dtor sangat wajib jika kelas mengelola _raw resource_ seperti memori dinamis (array yang dibuat dengan `new`) agar tidak terjadi kebocoran memori.

## Pengelolaan Sumber Daya
Konsep **RAII** (*Resource Acquisition Is Initialization*) adalah pilar utama C++. Intinya, kepemilikan sumber daya (memori, file, koneksi jaringan) diikat pada masa hidup objek: ctor mengambil sumber daya, dtor melepaskannya.

Manajemen Aturan (Rule of...):
- **Rule of 3 (C++ Klasik):** Jika sebuah kelas mendefinisikan salah satu dari tiga fungsi berikut, maka kemungkinan besar ia harus mendefinisikan ketiganya:    
	1. *Destructor*: Untuk menghapus data di heap.
	2. *Copy Constructor*: Untuk melakukan _Deep Copy_ saat objek baru dibuat dari objek lama.
    3. *Copy Assignment Operator*: Untuk melakukan _Deep Copy_ saat objek yang sudah ada diberi nilai dari objek lain.
- **Rule of 5 (C++ Modern/C++11):** Dengan adanya fitur _Move Semantics_, aturan ini ditambah dua lagi agar program lebih efisien: 
	1. *Move Constructor*: "Mencuri" sumber daya dari objek temporer.
	2. *Move Assignment Operator*: "Mencuri" sumber daya saat operasi _assignment_ objek temporer.
- **Rule of 0:** Pendekatan modern yang menyarankan penggunaan tipe data RAII standar (seperti `std::vector` atau `std::string`). Jika kita menggunakan tipe standar, kita tidak perlu menulis dtor/cctor/dst secara manual karena kelas-kelas tersebut sudah mengelolanya sendiri.

## Copy & Move
*Copy Constructor* (**cctor**) membuat objek baru sebagai duplikat dari objek yang ada (*state*-nya sama).

*Copy Assignment* (`operator=`): Digunakan ketika objek sudah ada dan ingin diisi dengan data dari objek lain. Harus menangani pelepasan sumber daya lama sebelum menyalin yang baru dan waspada terhadap _self-assignment_.

*Move Semantics*: Fitur efisiensi untuk menghindari penyalinan mahal. Alih-alih menyalin data (misal array yang besar), objek baru "mencuri" pointer data dari objek temporer (_rvalue_). Objek lama dikosongkan secara valid tanpa proses alokasi ulang yang berat.

## Anggota Kelas Khusus (Static & Const)
Anggota Statik (`static`) merupakan anggota yang dimiliki oleh **kelas secara kolektif**, bukan oleh instansiasi objek individual. Atribut statik digunakan bersama oleh semua objek dari kelas tersebut (misal: penghitung jumlah objek). Method statik hanya bisa mengakses anggota statik lainnya dan tidak memiliki pointer `this`.

Konstanta (`const`):
- Atribut Const: Nilainya tetap selama masa hidup objek. Harus diinisialisasi melalui _initialization list_.
- Method Const: Menjamin bahwa method tersebut tidak akan mengubah keadaan (_state_) objek. Objek yang ditandai sebagai `const` hanya boleh memanggil method yang bertanda `const`.

## Enkapsulasi Tingkat Lanjut (Friend & Nested Class)
- **Friend:** Memberikan hak akses khusus kepada fungsi atau kelas lain untuk mengakses bagian `private` atau `protected`. Gunakan secara bijak hanya untuk pasangan abstraksi yang sangat erat (seperti operator overloading).
- **Nested Class:** Kelas yang didefinisikan di dalam kelas lain. Tujuannya adalah untuk menyembunyikan detail implementasi internal (seperti kelas `Node` di dalam `List`) agar tidak terlihat oleh pengguna kelas luar, sesuai prinsip _information hiding_.