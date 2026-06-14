## Reflection

#### Hubungan dengan CPMK

> **CPMK tidak disebutkan** - Materi ini relevan untuk memahami kemampuan Java melakukan inspeksi dan eksekusi struktur kelas saat runtime, termasuk bagaimana konsep OOP seperti interface, collections, dan generics dipakai untuk membangun sistem plugin.

#### Outline Konsep Fundamental

- Eksekusi Java
  - bytecode
  - JVM
  - class loader
  - custom class loader
- Reflection API
  - inspeksi kelas saat runtime
  - eksekusi method dinamis
  - kelas `Class`
  - kelas `Field`
  - kelas `Method`
- Mendapatkan objek `Class`
  - `Class.forName("NamaKelas")`
  - `NamaKelas.class`
  - `obj.getClass()`
- Instansiasi dan inspeksi
  - `newInstance()`
  - casting dari `Object`
  - `getInterfaces()`
  - `getMethods()` dan `getFields()`
  - `getMethod()` dan `getField()`
- Sistem plugin
  - interface kontrak
  - pemuatan kelas dari direktori
  - collections dan generics
  - stream dan `Optional`
- Passing code
  - lambda expression
  - function pointer
  - object/interface
  - nama string melalui Reflection

#### Penjelasan Materi

**Bytecode dan Class Loader**

> **TL;DR:** Java mengeksekusi bytecode yang dimuat ke memori oleh class loader.

Program Java dikompilasi menjadi bytecode, yaitu bahasa mesin untuk JVM. Bytecode umumnya tersimpan sebagai file `.class`, tetapi tidak harus selalu berasal dari filesystem; ia dapat juga dimuat dari `.jar`, jaringan, atau sumber lain.

Class loader adalah bagian JVM yang memuat kelas ke memori. Secara default, Java mampu memuat kelas dari filesystem, file `.jar`, dan jaringan. Programmer juga dapat membuat custom class loader dengan menurunkan `java.lang.ClassLoader` untuk memuat kelas dari sumber tidak standar atau bahkan menciptakan kelas saat runtime.

- Klasifikasi:
  - Class loader bawaan
    - Memuat kelas dari sumber umum.
    - Digunakan oleh JVM secara normal.
  - Custom class loader
    - Dibuat programmer.
    - Berguna untuk sumber bytecode khusus atau pemuatan dinamis.

**Reflection API**

> **TL;DR:** Reflection memungkinkan program melihat dan memakai struktur kelas saat runtime, termasuk kelas yang belum dikenal saat compile time.

Reflection API adalah fitur Java untuk menginspeksi dan mengeksekusi isi sebuah kelas saat program berjalan. Program dapat membaca field, method, signature, interface, bahkan membuat instance dan memanggil method secara dinamis.

Reflection dipakai pada IDE, application server, dan sistem plugin. Dalam IDE, Reflection membantu mendesain GUI tanpa harus mengetahui semua komponen sejak awal. Dalam application server, Reflection membantu pengaturan komponen aplikasi. Dalam plugin system, Reflection memungkinkan aplikasi memuat ekstensi tanpa rekompilasi aplikasi utama.

- Kegunaan utama:
  - Inspeksi struktur kelas.
  - Membaca field dan method.
  - Membuat objek dinamis.
  - Mengeksekusi method secara dinamis.
  - Membangun arsitektur plugin.

**Kelas `Class`, `Field`, dan `Method`**

> **TL;DR:** `Class` merepresentasikan kelas, `Field` merepresentasikan atribut, dan `Method` merepresentasikan method.

`java.lang.Class` adalah kelas yang objeknya merepresentasikan sebuah kelas yang dikenal Java. Objek `Class` tidak dibuat dengan `new Class()`. Setelah objek `Class` diperoleh, program dapat mengakses metadata kelas dan membuat instance baru.

`Field` digunakan untuk mengakses atribut dalam kelas. Melalui `Field`, program dapat mengetahui nama, tipe, membaca nilai, dan mengubah nilai field. `Method` digunakan untuk mengakses method, mengetahui signature seperti nama, parameter, return value, dan memanggil method secara dinamis.

- Peran:
  - `Class`: representasi kelas.
  - `Field`: representasi atribut.
  - `Method`: representasi method/fungsi.

**Mendapatkan Objek `Class`**

> **TL;DR:** Objek `Class` diperoleh dengan `Class.forName`, class literal, atau `getClass()`.

Ada tiga cara utama mendapatkan objek `Class`. `Class.forName("NamaKelas")` memakai nama kelas dalam bentuk string dan class loader mencarinya di classpath. `NamaKelas.class` memakai literal kelas yang sudah diketahui saat compile time. `obj.getClass()` mengambil kelas dari objek yang sudah ada.

- Perbandingan:
  - `Class.forName("NamaKelas")`
    - Cocok untuk nama kelas dari string.
    - Penting untuk plugin.
  - `NamaKelas.class`
    - Cocok jika kelas sudah diketahui di source code.
  - `obj.getClass()`
    - Cocok jika sudah punya instance objek.

```java
Class<?> c1 = Class.forName("MyPlugin");
Class<?> c2 = String.class;
Class<?> c3 = "hello".getClass();
```

**Instansiasi Dinamis dan Casting**

> **TL;DR:** `newInstance()` membuat objek runtime, tetapi hasilnya perlu di-cast dari `Object`.

Setelah memiliki objek `Class`, program dapat membuat instance dengan `newInstance()`. Hasil dari instansiasi dinamis bertipe umum `Object`, sehingga perlu casting ke kelas atau interface yang spesifik.

Proses ini dapat gagal. Materi menekankan penanganan `InstantiationException` dan `IllegalAccessException`, misalnya ketika kelas tidak dapat diinstansiasi karena abstrak atau konstruktornya tidak bisa diakses.

```java
Class<?> c = Class.forName("CsvLoader");
FileLoader loader = (FileLoader) c.newInstance();
```

- Hal penting:
  - `newInstance()` mengembalikan `Object`.
  - Casting diperlukan agar method spesifik dapat dipanggil.
  - Perlu `try-catch` untuk kemungkinan gagal instansiasi.

**Inspeksi Interface, Field, dan Method**

> **TL;DR:** Reflection menyediakan method jamak untuk daftar elemen dan method tunggal untuk elemen yang namanya diketahui.

`getInterfaces()` mengembalikan daftar interface yang diimplementasikan kelas. Ini penting untuk memeriksa apakah kelas plugin memenuhi kontrak yang disyaratkan.

Materi juga membedakan method tunggal dan jamak. `getMethods()` dan `getFields()` mengembalikan array seluruh method atau field. `getMethod()` dan `getField()` dipakai ketika nama method atau field tertentu sudah diketahui.

- Pola penggunaan:
  - `getInterfaces()`: cek kontrak plugin.
  - `getMethods()`: ambil semua method.
  - `getFields()`: ambil semua field.
  - `getMethod(name, ...)`: ambil method tertentu.
  - `getField(name)`: ambil field tertentu.

**Sistem Plugin dengan Reflection**

> **TL;DR:** Reflection memungkinkan aplikasi memuat plugin baru tanpa rekompilasi aplikasi utama.

Plugin adalah kelas atau komponen ekstensi yang dapat ditambahkan ke aplikasi tanpa rekompilasi. Agar aman digunakan, aplikasi utama biasanya mendefinisikan interface kontrak, misalnya `FileLoader`. Setiap plugin wajib mengimplementasikan interface tersebut agar aplikasi tahu method apa yang tersedia.

- Langkah pemuatan plugin:
  - Ambil daftar file dari direktori plugin.
  - Ambil nama kelas dari file.
  - Gunakan `Class.forName("NamaKelas")` untuk mendapatkan objek `Class`.
  - Gunakan `getInterfaces()` untuk memastikan kelas mengimplementasikan interface wajib.
  - Jika valid, buat instance dengan `newInstance()`.
  - Cast hasilnya ke interface, misalnya `FileLoader`.
  - Simpan ke `List<FileLoader>`.
  - Panggil method plugin melalui interface.

```java
private final List<FileLoader> fileLoaders = new ArrayList<>();
```

Dalam integrasi dengan collections dan generics, plugin yang valid disimpan dalam `List<FileLoader>`. Hasil array seperti `getInterfaces()` atau `File.list()` dapat dikonversi dengan `Arrays.asList(...)` agar mudah diiterasi. Untuk memilih plugin yang cocok, materi menyinggung penggunaan Stream API dan `Optional`.

```java
Optional<FileLoader> anyLoader = fileLoaders.stream()
    .filter(loader -> loader.supports(fileName))
    .findAny();
```

Jika tidak ada plugin yang mendukung file tertentu, program dapat melempar `UnsupportedOperationException`.

**Passing Code**

> **TL;DR:** Java tidak memakai function pointer seperti C/C++, tetapi dapat melewatkan perilaku lewat lambda, object/interface, atau nama yang diproses Reflection.

Passing code adalah teknik melewatkan instruksi atau perilaku sebagai argumen. Ini berguna agar program tidak perlu menulis rangkaian `if` panjang untuk memilih aksi, misalnya pada sorting atau filter.

- Pendekatan passing code:
  - Lambda expression
    - Fungsi tanpa nama.
    - Didukung Java sejak Java 8.
  - Function pointer
    - Melewatkan alamat fungsi statik.
    - Ada di C/C++, tidak didukung Java.
  - Object/interface
    - Cara umum OOP.
    - Objek mengimplementasikan interface tertentu.
  - Nama string dengan Reflection
    - Program menerima nama kelas atau method.
    - Nama tersebut diinspeksi, dibuat objeknya, lalu dieksekusi.

#### Komponen Kunci

- Bytecode: hasil kompilasi Java yang dieksekusi JVM.
- JVM: mesin virtual yang menjalankan bytecode.
- Class loader: pemuat kelas ke memori.
- Custom class loader: class loader buatan programmer.
- Reflection API: API untuk inspeksi dan eksekusi struktur kelas saat runtime.
- `Class`: representasi kelas dalam Java.
- `Field`: representasi atribut.
- `Method`: representasi method.
- `Class.forName(...)`: memperoleh `Class` dari nama string.
- `.class`: literal untuk memperoleh `Class` dari kelas yang diketahui.
- `getClass()`: memperoleh `Class` dari objek yang sudah ada.
- `newInstance()`: membuat instance dinamis dari `Class`.
- `getInterfaces()`: mengambil daftar interface yang diimplementasikan.
- `getMethods()` / `getFields()`: mengambil daftar method atau field.
- `getMethod()` / `getField()`: mengambil method atau field tertentu.
- Plugin: ekstensi yang ditambahkan tanpa rekompilasi aplikasi utama.
- Interface kontrak: interface wajib yang menjamin method plugin tersedia.
- `List<FileLoader>`: contoh penggunaan collections dan generics untuk menyimpan plugin.
- `Optional`: pembungkus hasil pencarian yang mungkin kosong.
- `UnsupportedOperationException`: exception untuk operasi yang tidak didukung.

#### Checklist Pemahaman

1. **Sub-materi yang dibahas**
   - bytecode dan JVM
   - class loader dan custom class loader
   - Reflection API
   - `Class`, `Field`, `Method`
   - `Class.forName`, `.class`, `getClass()`
   - `newInstance()` dan casting
   - `getInterfaces()`
   - `getMethods`, `getFields`, `getMethod`, `getField`
   - plugin system
   - interface kontrak plugin
   - integrasi collections, generics, stream, dan `Optional`
   - passing code

2. **Prioritas belajar**
   - 🔴 Wajib dikuasai
     - definisi Reflection API
     - cara memperoleh objek `Class`
     - `Class`, `Field`, `Method`
     - `newInstance()` dan casting
     - alur pemuatan plugin
     - fungsi interface sebagai kontrak plugin
   - 🟡 Cukup paham konsep
     - custom class loader
     - `getMethods` vs `getMethod`
     - Stream API dan `Optional` pada pemilihan plugin
     - passing code
   - ✅ Sudah dikuasai
     - Tidak ditandai sebagai sudah dikuasai pada daftar awal.
