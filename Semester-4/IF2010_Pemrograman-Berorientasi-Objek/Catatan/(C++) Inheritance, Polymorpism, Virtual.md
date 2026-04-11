## Inheritance
Pewarisan adalah mekanisme dalam Pemrograman Berbasis Objek (PBO) yang memungkinkan kita mendefinisikan sebuah kelas baru berdasarkan kelas yang sudah ada. Tujuan utamanya adalah **Reuse** (penggunaan kembali kode). Dengan pewarisan, kelas baru akan memiliki sifat (data member) dan perilaku (member function) dari kelas induknya tanpa harus menulis ulang kode tersebut.
- **Base Class (Kelas Dasar/Superclass):** Kelas yang menjadi acuan atau sumber pewarisan.
- **Derived Class (Kelas Turunan/Subclass):** Kelas baru yang mewarisi sifat dari kelas dasar.
- **Struktur Objek:** Objek dari kelas turunan secara internal terdiri dari dua bagian: bagian yang diwarisi dari kelas dasar dan bagian spesifik yang didefinisikan oleh kelas turunan itu sendiri.

**Penting:** Tidak semua komponen diwariskan. Komponen yang **TIDAK** diwariskan meliputi:
1. Konstruktor (_ctor_)
2. Destruktor (_dtor_)
3. Copy Constructor (_cctor_)
4. Assignment Operator (`operator=`)

Deklarasi pewarisan di C++ menggunakan tanda titik dua (`:`). `class NamaTurunan : mode_pewarisan NamaDasar { ... };`

**Tingkat Akses `protected`:** Atribut `protected` berada di antara `public` dan `private`. Anggota yang dideklarasikan sebagai `protected` tidak dapat diakses dari luar kelas (seperti `private`), namun **dapat diakses** oleh kelas turunannya.

![[Pasted image 20260309161612.png]]
_Catatan: Anggota `private` kelas dasar tetap tidak dapat diakses secara langsung oleh kelas turunan dalam mode apa pun._

Manajemen objek turunan memerlukan pemahaman tentang urutan eksekusi fungsi spesial:
- Konstruksi: Saat objek turunan dibuat, C++ akan memanggil konstruktor kelas dasar terlebih dahulu, baru kemudian konstruktor kelas turunan. Kita dapat memilih konstruktor dasar mana yang dipanggil melalui _Constructor Initialization List_.
- Destruksi: Kebalikan dari konstruksi. Destruktor kelas turunan dijalankan terlebih dahulu untuk membersihkan bagian spesifiknya, baru kemudian destruktor kelas dasar dipanggil secara otomatis.

*Copy constructor* dan *assignment operator*  ini tidak diwariskan, ada aturan khusus jika kita mendefinisikannya secara manual di kelas turunan:
1. *Copy Constructor* (`cctor`): Jika kelas turunan mendefinisikan `cctor`, ia **wajib** memanggil `cctor` kelas dasar secara eksplisit melalui _initialization list_. Jika tidak, kelas dasar akan diinisialisasi menggunakan _default constructor_, yang bisa menyebabkan hilangnya data pada bagian "warisan". _Sintaks:_ `Derived(const Derived& other) : Base(other) { ... }`
2. *Assignment Operator* (`operator=`): Sama seperti `cctor`, kita harus memanggil `operator=` milik kelas dasar secara eksplisit di dalam fungsi agar bagian data kelas dasar ikut tersalin. _Sintaks:_ 

```cpp 
Derived& operator=(const Derived& other) { 
	if (this != &other) { 
		Base::operator=(other); 
	   // Panggil versi base 
	   // Salin anggota data milik Derived di sini 
	} 
	return *this; 
}
```

## Polymorphism
Secara etimologi, _Polymorphism_ berasal dari bahasa Yunani yang berarti "banyak bentuk". Dalam PBO, ini merujuk pada kemampuan sebuah objek untuk merespons pesan (pemanggilan metode) yang sama dengan cara yang berbeda-beda tergantung pada tipe asli objek tersebut. Polimorfisme memungkinkan objek dari kelas turunan diperlakukan sebagai objek dari kelas dasar.

Binding adalah proses menghubungkan pemanggilan fungsi dengan implementasi fungsi yang tepat.
1. *Static Binding* (*Early Binding*): Terjadi saat kompilasi. Fungsi yang dipanggil ditentukan berdasarkan tipe _pointer_ atau _reference_-nya. Secara default, C++ menggunakan cara ini.
2. *Dynamic Binding* (*Late Binding*): Terjadi saat eksekusi (_runtime_). Fungsi yang dipanggil ditentukan berdasarkan objek asli yang ditunjuk oleh _pointer_, bukan tipe _pointer_-nya. Hal ini dimungkinkan melalui kata kunci `virtual`.

Fungsi Virtual & Virtual Destructor:
- `virtual`: Memberitahu kompiler agar tidak melakukan _static binding_. Kompiler akan menggunakan _Virtual Table_ (V-Table) untuk mencari fungsi yang benar saat program berjalan.
- Virtual Destructor: Sangat krusial. Jika Saudara menghapus objek turunan melalui pointer kelas dasar (`delete pointerBase`), tanpa `virtual destructor`, hanya destruktor kelas dasar yang akan dipanggil. Ini menyebabkan bagian objek kelas turunan tidak terhapus dan mengakibatkan kebocoran memori (_memory leak_).

## Abstract Base Class (ABC)
Kelas yang mengandung minimal satu **Pure Virtual Function** (fungsi dengan akhiran `= 0`). Kelas ini berfungsi sebagai "kontrak" atau standar bagi semua turunannya dan tidak dapat dibuat objeknya secara langsung.