---
cssclasses:
  - callouts-outlined
---
>[!notes] Latar Belakang
Bahasa pemrograman C++ diciptakan oleh Bjarne Stroustrup pada awal dekade 1980-an di AT&T Bell Laboratories sebagai bentuk pengembangan dari bahasa C. Pada masa inkubasinya, bahasa ini dikenal dengan nama "C with Classes" karena inovasi utamanya adalah menyuntikkan konsep kelas dari bahasa Simula67 ke dalam kerangka kerja bahasa C. 

## C vs C++
`C` merupakan bahasa pemrograman yang menggunakan paradigma prosedural. Sedangkan, `C++` merupakan bahasa pemrograman yang dirancang khusus untuk pemodelan objek secara eksplisit. C++ memiliki perbedaan dengan bahasa C, yaitu di antaranya adalah:
1. *Typecasting* sebagai Fungsi. Selain format tradisional `(int)x`, C++ memungkinkan penulisan gaya fungsi seperti `int(x)`.
2. *Function Name Overloading*. Kemampuan untuk mendefinisikan beberapa fungsi dengan nama yang sama, asalkan memiliki _signature_ (jumlah atau tipe parameter) yang berbeda. 
3. **Nilai Default pada Parameter**: Parameter formal fungsi dapat diberi nilai default (misalnya `int f(int a, int b = 2)`). Jika parameter kedua tidak diisi saat pemanggilan, nilai 2 akan digunakan secara otomatis.
4. **Operator Baru**:
    - `::` (_Scope Resolution Operator_): Digunakan untuk mengakses variabel global atau mendefinisikan implementasi metode di luar kelas.
    - `new` dan `delete`: Digunakan untuk manajemen memori dinamis (menggantikan `malloc` dan `free` di C).

### Reference Variable
_Reference variable_ adalah nama alias untuk variabel yang sudah ada. Berbeda dengan pointer, sebuah referensi harus segera diinisialisasi saat didefinisikan dan tidak dapat diubah untuk mengacu pada variabel lain di kemudian hari. Simbol `&` digunakan untuk mendeklarasikannya (contoh: `int& alias = original;`). Referensi sangat berguna dalam pemanggilan fungsi (_call by reference_) untuk meningkatkan efisiensi karena tidak perlu melakukan penyalinan data yang besar.

### Kompabilitas dengan C
Adapula beberapa kesamaan bahasa C dengan C++ sebagai berikut.
1. Program C yang dikompilasi oleh C++ tidak dapat menggunakan kata kunci (misal, `class`, `new`, `delete`) dari C++ sebagai nama *identifier* (variabel, dll.).
2. Dalam C++, Setiap fungsi harus dideklarasikan (memiliki *prototype*). Di C, hanya dijadikan *best practice*. 
3. Dalam C++, fungsi yang bukan bertipe `void`, harus memiliki instruksi `return`. Dalam C, hanya mengakibatkan *warning*.

## Konsep Kelas
Dalam paradigma PBO, sebuah sistem dipandang sebagai jaringan entitas (objek) yang saling berinteraksi. Kelas (_class_) adalah cetak biru atau abstraksi desain yang menentukan bagaimana objek-objek tersebut akan hidup. Kelas mendefinisikan tanggung jawab, perilaku yang tersedia, dan *state*/data yang diperlukan untuk mendukung perilaku tersebut.

Perancang kelas berfungsi untuk menentukan *interface*/kontrak dan representasi internal objek. 

Terdapat dua jenis *member*/anggota dalam sebuah *class*, yaitu
1. Function Member (_Methods_): Kumpulan operasi atau layanan yang dapat dilakukan oleh objek. Ini merupakan antarmuka (_interface_) objek terhadap dunia luar.
2. Data Member (*Fields*): Representasi internal atau informasi yang dimiliki oleh objek (_state_).

Perbedaan `struct` dan `class` Meskipun keduanya digunakan untuk mengelompokkan data, terdapat perbedaan prinsip:
- **`struct`**: Digunakan untuk kumpulan data pasif. Semua anggota bersifat `public` secara default. Fokusnya adalah pada data, dan tidak bertanggung jawab menjaga konsistensinya sendiri.
- **`class`**: Dirancang sebagai entitas aktif yang memiliki perilaku. Semua anggota bersifat `private` secara default untuk menyembunyikan detail implementasi. Kelas menjaga _invariants_ (aturan internal) agar datanya tetap konsisten.

Desain kelas yang baik dimulai dengan menentukan operasi apa yang dibutuhkan oleh pengguna kelas (kontrak perilaku). _Fields_ atau data baru ditambahkan hanya jika diperlukan untuk mendukung operasi tersebut. Singkatnya, data tanpa perilaku bukanlah sebuah objek yang baik.

## Pengaturan Akses Member
Enkapsulasi adalah proses penyembunyian detail implementasi internal dari pihak luar. Di C++, hal ini diatur melalui tiga kata kunci akses:
1. **`public`**: Anggota kelas dapat diakses secara bebas dari luar kelas menggunakan operator selektor (`.` untuk objek langsung atau `->` untuk pointer).
2. **`private`**: Anggota hanya dapat diakses oleh fungsi anggota (_methods_) dari kelas itu sendiri. Sangat disarankan untuk menempatkan semua _data members_ di bagian privat guna menjaga keamanan data.
3. **`protected`**: Mirip dengan privat, namun anggota tetap dapat diakses oleh kelas turunan (_subclasses_).

## Penulisan Kode
Penulisan kode kelas biasanya dipisahkan menjadi dua bagian untuk mendukung modularitas:
1. *Interface*/*Specification*: Berupa deklarasi kelas yang ditempatkan dalam file header (`.h` atau `.hpp`). Bagian ini memberitahu pengguna tentang apa saja layanan yang tersedia tanpa memperlihatkan kodenya.
2. *Implementation*/*Body*: Berupa definisi detail dari metode yang ditempatkan dalam file sumber (`.cpp` atau `.cc`). Untuk menghubungkan definisi metode dengan kelasnya, digunakan operator `::` (contoh: `void Stack::push(int x) { ... }`).    

## Pointer This
Setiap metode non-statis di dalam kelas secara otomatis memiliki pointer implisit bernama `this`. Pointer ini menunjuk ke alamat objek yang sedang menjalankan metode tersebut.
- **Kegunaan**: Membedakan antara variabel anggota kelas dan variabel lokal/parameter fungsi jika keduanya memiliki nama yang sama (_name shadowing_).
- **Contoh**: `this->data = data;` berarti kita mengisi data member kelas dengan nilai dari parameter fungsi yang juga bernama `data`.
