## Exceptions

#### Hubungan dengan CPMK

> **CPMK tidak disebutkan** - Materi ini tetap relevan sebagai fondasi kemampuan menulis program Java yang robust, mampu memisahkan alur normal dari alur penanganan kesalahan, serta memahami kontrak method melalui `throw`, `throws`, dan hierarki `Throwable`.

#### Outline Konsep Fundamental

- Konsep dasar exception
  - *Exceptional event*
  - *Exception object*
  - *Throwing an exception*
  - *Exception handler*
- Hierarki `Throwable`
  - `Error`
  - `Exception`
  - `RuntimeException`
  - *checked exception* dan *unchecked exception*
- Mekanisme penanganan
  - `try`
  - `catch`
  - `finally`
  - multi-`catch`
  - `try-with-resources`
- Melempar exception
  - `throw`
  - `throws`
  - propagasi melalui *call stack*
- Teknik lanjutan
  - *chained exception*
  - *custom exception*
  - tujuan arsitektural exception

#### Penjelasan Materi

**Konsep Dasar Exception**

> **TL;DR:** Exception adalah mekanisme Java untuk merepresentasikan kejadian abnormal saat runtime tanpa mencampur kode utama dengan kode penanganan error.

*Exceptional event* adalah kejadian saat eksekusi program yang mengganggu alur normal instruksi. Ketika sebuah method mengalami kondisi error, method tersebut dapat membuat *exception object* dan melemparkannya ke *runtime system*. Objek ini membawa informasi tentang error, termasuk tipe error dan keadaan program ketika error terjadi.

Istilah *throwing an exception* merujuk pada proses menciptakan objek exception dan menyerahkannya ke runtime system. Setelah exception dilempar, runtime system mencari *exception handler*, yaitu kode yang cocok untuk menangkap dan merespons exception tersebut.

- Alur dasar exception:
  - Method mengalami kondisi error.
  - Method membuat objek turunan `Throwable`.
  - Objek dilempar menggunakan `throw` atau oleh sistem.
  - Runtime system mencari handler yang sesuai.
  - Handler yang cocok menjalankan blok `catch`.

**Hierarki `Throwable`**

> **TL;DR:** Semua objek yang bisa dilempar di Java berada di bawah `Throwable`, lalu terbagi menjadi `Error` dan `Exception`.

`Throwable` adalah akar hierarki objek yang dapat dilempar. Dua cabang utamanya adalah `Error` dan `Exception`. `Error` menunjukkan masalah serius yang secara umum tidak layak ditangani oleh aplikasi normal, misalnya masalah fatal pada sistem. `Exception` menunjukkan kondisi abnormal yang masih wajar untuk ditangani oleh aplikasi.

- Klasifikasi utama:
  - `Error`
    - Masalah serius dan umumnya *irrecoverable*.
    - Bersifat *unchecked*.
    - Tidak disarankan ditangkap oleh aplikasi normal.
  - `Exception`
    - Kondisi error yang masih mungkin dipulihkan.
    - Dapat berupa *checked exception* atau *unchecked exception*.
  - `RuntimeException`
    - Subclass dari `Exception`.
    - Bersifat *unchecked*.

- Perbedaan *checked* dan *unchecked*:
  - *Checked exception*
    - Semua `Exception` selain `RuntimeException`.
    - Wajib ditangkap dengan `try-catch` atau dideklarasikan dengan `throws`.
  - *Unchecked exception*
    - Meliputi `Error` dan `RuntimeException`.
    - Tidak wajib ditangkap atau dideklarasikan.

**`try`, `catch`, dan `finally`**

> **TL;DR:** `try-catch-finally` memisahkan kode berisiko, kode penanganan, dan kode pembersihan yang harus tetap dijalankan.

`try` berisi kode yang mungkin memunculkan exception. `catch` berisi handler untuk tipe exception tertentu. Satu blok `try` dapat diikuti lebih dari satu blok `catch` untuk menangani tipe exception berbeda. `finally` berisi kode yang selalu dieksekusi setelah `try` selesai, baik exception terjadi maupun tidak.

- Peran tiap blok:
  - `try`: tempat kode yang berpotensi gagal.
  - `catch`: menangani exception yang cocok dengan tipe parameternya.
  - `finally`: menjalankan pembersihan, misalnya menutup resource.

- Aturan penting:
  - `finally` tetap dijalankan walaupun di dalam `try` atau `catch` ada `return`.
  - `finally` juga tetap dijalankan sebelum exception baru dari `throw` dilanjutkan.
  - Urutan `catch` perlu memperhatikan hierarki tipe: tipe yang lebih spesifik sebaiknya ditaruh sebelum tipe yang lebih umum.

**`try-with-resources`**

> **TL;DR:** `try-with-resources` menutup resource otomatis selama objeknya mengimplementasikan `AutoCloseable`.

Sejak Java 7, resource dapat dideklarasikan langsung pada bagian pembuka `try`. Setelah blok selesai, Java memanggil `close()` secara otomatis sehingga tidak perlu menulis `finally` hanya untuk menutup resource.

- Syarat dan langkah:
  - Resource harus mengimplementasikan `AutoCloseable`.
  - Deklarasikan resource di dalam tanda kurung `try`.
  - Gunakan resource di dalam blok `try`.
  - Java otomatis memanggil `close()` setelah blok selesai.

```java
try (Scanner scanner = new Scanner(file)) {
    System.out.println(scanner.nextLine());
}
```

**`throw` dan `throws`**

> **TL;DR:** `throw` melempar objek exception, sedangkan `throws` mendeklarasikan bahwa method dapat melempar exception.

`throw` adalah statement untuk melempar objek turunan `Throwable`. Biasanya digunakan setelah validasi state atau parameter. `throws` berada pada deklarasi method dan menyatakan bahwa method tersebut dapat meneruskan exception kepada pemanggilnya.

- Perbedaan utama:
  - `throw`
    - Dipakai di dalam badan method.
    - Diikuti objek exception.
    - Contoh: `throw new IllegalArgumentException();`
  - `throws`
    - Dipakai pada deklarasi method.
    - Diikuti tipe exception.
    - Wajib untuk *checked exception* yang tidak ditangani di method tersebut.

```java
void readFile(String path) throws IOException {
    if (path == null) {
        throw new IllegalArgumentException("path tidak boleh null");
    }
}
```

**Propagasi Exception dan Call Stack**

> **TL;DR:** Jika method tidak menangani exception, runtime system mencari handler ke method pemanggil di call stack.

*Call stack* adalah tumpukan pemanggilan method yang sedang berjalan. Ketika exception muncul dan method saat ini tidak memiliki handler yang cocok, exception diteruskan ke method pemanggil. Runtime system menelusuri call stack secara mundur sampai menemukan handler yang sesuai.

- Mekanisme pencarian handler:
  - Exception muncul di method terdalam.
  - Jika tidak ada `catch` yang cocok, exception diteruskan ke caller.
  - Pencarian terus naik di call stack.
  - Jika handler ditemukan, exception ditangkap.
  - Jika tidak ada handler, program berakhir dengan pesan error.

**Chained Exception**

> **TL;DR:** Chained exception membungkus exception asal ke exception baru agar konteks error menjadi lebih bermakna.

Sebuah method dapat menangkap exception lalu melempar exception baru yang menyimpan exception lama sebagai penyebab. Teknik ini berguna saat layer program ingin memberi pesan yang lebih sesuai dengan domain tanpa menghilangkan akar masalah.

```java
try {
    loadConfig();
} catch (IOException e) {
    throw new ConfigurationException("Gagal memuat konfigurasi", e);
}
```

**Custom Exception**

> **TL;DR:** Custom exception dibuat ketika exception bawaan tidak cukup merepresentasikan kesalahan domain program.

Programmer dapat membuat kelas exception sendiri dengan mewarisi `Exception` atau subclass lain yang sesuai. Konvensinya, nama kelas diakhiri dengan kata `Exception`, misalnya `LinkedListException` atau `ConfigurationException`.

- Alasan membuat custom exception:
  - Exception yang dibutuhkan tidak tersedia di platform Java.
  - Kode client menjadi lebih mudah memahami jenis kegagalan.
  - Exception dipakai berulang di banyak bagian program.
  - Package menjadi lebih mandiri dan jelas kontraknya.

```java
class LinkedListException extends Exception {
    public LinkedListException(String message) {
        super(message);
    }
}
```

**Tujuan Arsitektural Exception**

> **TL;DR:** Exception membuat penanganan error lebih terstruktur dibanding mengembalikan kode error seperti `-1` atau `null`.

Exception membantu memisahkan kode reguler dari kode penanganan error, meneruskan error ke layer yang lebih tepat, dan mengelompokkan error berdasarkan hierarki tipe. Ini membuat kode lebih mudah dibaca, diuji, dan dipelihara.

- Kelebihan utama:
  - Memisahkan *regular code* dan *error handling code*.
  - Memungkinkan propagasi error ke caller.
  - Mengelompokkan error melalui inheritance.
  - Mendukung kontrak method melalui *checked exception*.

#### Komponen Kunci

- `Throwable`: akar semua objek yang bisa dilempar.
- `Error`: masalah serius yang biasanya tidak ditangani aplikasi normal.
- `Exception`: kondisi abnormal yang dapat ditangani aplikasi.
- `RuntimeException`: exception unchecked untuk kesalahan runtime.
- *Checked exception*: exception yang wajib ditangani atau dideklarasikan.
- *Unchecked exception*: exception yang tidak wajib ditangani atau dideklarasikan.
- `try`: blok kode berisiko.
- `catch`: blok handler exception.
- `finally`: blok yang selalu dijalankan setelah `try`.
- `throw`: statement untuk melempar exception object.
- `throws`: deklarasi bahwa method dapat melempar exception.
- *Call stack*: tumpukan pemanggilan method tempat runtime mencari handler.
- *Chained exception*: exception baru yang menyimpan exception asal.
- *Custom exception*: exception buatan sendiri untuk kebutuhan domain program.
- `AutoCloseable`: interface yang memungkinkan resource ditutup otomatis oleh `try-with-resources`.

#### Checklist Pemahaman

1. **Sub-materi yang dibahas**
   - Konsep dasar exception
   - Hierarki `Throwable`
   - `Error`, `Exception`, `RuntimeException`
   - *checked* vs *unchecked exception*
   - `try`, `catch`, `finally`
   - `try-with-resources`
   - `throw` vs `throws`
   - propagasi exception dan *call stack*
   - *chained exception*
   - *custom exception*

2. **Prioritas belajar**
   - 🔴 Wajib dikuasai
     - Hierarki `Throwable`
     - *checked* vs *unchecked exception*
     - `try-catch-finally`
     - `throw` vs `throws`
     - propagasi melalui *call stack*
   - 🟡 Cukup paham konsep
     - `try-with-resources`
     - *chained exception*
     - alasan membuat *custom exception*
     - tujuan arsitektural exception
   - ✅ Sudah dikuasai
     - Tidak ditandai sebagai sudah dikuasai pada daftar awal.
