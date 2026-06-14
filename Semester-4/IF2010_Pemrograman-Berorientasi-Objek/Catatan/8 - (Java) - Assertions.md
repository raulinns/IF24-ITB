5## Assertions

#### Hubungan dengan CPMK

> **CPMK tidak disebutkan** - Materi ini relevan untuk memahami validasi asumsi internal program, membedakan bug programmer dari kondisi error runtime, dan memilih mekanisme yang tepat antara `assert` dan exception.

#### Outline Konsep Fundamental

- Konsep dasar assertion
  - `assert`
  - `AssertionError`
  - asumsi boolean
- Sintaks assertion
  - `assert Expression1;`
  - `assert Expression1 : Expression2;`
- Aktivasi runtime
  - default disabled
  - opsi `-ea`
- Penggunaan yang disarankan
  - *internal invariant*
  - *control-flow invariant*
  - *class invariant*
  - precondition dan postcondition pada method nonpublic
- Penggunaan yang dilarang
  - validasi argumen public method
  - operasi penting dengan *side effects*
- Perbandingan dengan exception
  - assertion untuk programmer error
  - exception untuk kontrak publik dan error runtime yang perlu ditangani

#### Penjelasan Materi

**Konsep Dasar Assertion**

> **TL;DR:** Assertion adalah pernyataan untuk menguji asumsi internal program selama development.

Assertion adalah statement Java yang membantu programmer memeriksa apakah asumsi terhadap program benar. Setiap assertion memuat ekspresi boolean yang diasumsikan bernilai `true` saat dieksekusi. Jika ekspresi tersebut bernilai `false`, Java melempar `AssertionError`.

Assertion terutama dipakai untuk mendeteksi bug logika internal dan mendokumentasikan asumsi program. Karena ditujukan untuk debugging, assertion bukan pengganti validasi input yang wajib berjalan di production.

- Karakteristik penting:
  - Mengecek asumsi internal programmer.
  - Dapat dinonaktifkan saat runtime.
  - Gagal dengan `AssertionError`.
  - Tidak sebaiknya ditangkap dengan `try-catch`.

**Sintaks Assertion**

> **TL;DR:** Java menyediakan dua bentuk `assert`: tanpa pesan dan dengan pesan detail.

Bentuk pertama adalah `assert Expression1;`. `Expression1` harus berupa ekspresi boolean. Jika bernilai `false`, sistem melempar `AssertionError` tanpa pesan detail.

Bentuk kedua adalah `assert Expression1 : Expression2;`. `Expression2` menghasilkan nilai yang digunakan sebagai pesan detail ketika assertion gagal. `Expression2` tidak boleh berupa pemanggilan method bertipe `void`.

```java
assert speed < 300000;
assert speed < 300000 : "kecepatan melebihi batas";
```

- Perbandingan bentuk:
  - `assert Expression1;`
    - Lebih ringkas.
    - Tidak memberi pesan detail.
  - `assert Expression1 : Expression2;`
    - Memberi konteks kegagalan.
    - Cocok untuk debugging.
    - `Expression2` harus menghasilkan nilai.

**Aktivasi Assertion**

> **TL;DR:** Assertion tidak dievaluasi secara default; harus diaktifkan dengan `-ea`.

Secara default, JVM tidak memeriksa assertion. Ini berarti ekspresi di dalam `assert` tidak dijalankan ketika assertion disabled. Untuk menjalankan assertion, program perlu dieksekusi dengan opsi `-ea` atau *enable assertions*.

```bash
java -ea Speed
```

- Implikasi penting:
  - Tanpa `-ea`, baris assertion dilewati.
  - Assertion tidak boleh memuat aksi yang dibutuhkan program.
  - Assertion cocok untuk development dan debugging, bukan validasi kontrak publik.

**Penggunaan yang Disarankan**

> **TL;DR:** Assertion tepat untuk memeriksa kondisi yang seharusnya mustahil salah jika kode internal benar.

Assertion paling tepat dipakai untuk invariant dan kontrak internal. Ia membantu menangkap bug programmer sedini mungkin tanpa menjadikan kode produksi bergantung pada pengecekan tersebut.

- Penggunaan yang direkomendasikan:
  - *Internal invariant*
    - Mengecek asumsi internal alur logika.
    - Contoh: cabang `else` terakhir dari rangkaian kondisi yang seharusnya hanya mungkin satu nilai.
  - *Control-flow invariant*
    - Mengecek jalur kontrol yang seharusnya tidak pernah dicapai.
    - Contoh: `default` pada `switch` yang secara desain mustahil.
  - *Class invariant*
    - Menjamin properti objek tetap valid.
    - Contoh: jam berada pada rentang `0..23`.
  - Precondition method nonpublic
    - Cocok untuk method privat karena pemanggilnya dikendalikan oleh kelas itu sendiri.
  - Postcondition
    - Cocok untuk memverifikasi hasil sebelum `return`.

```java
switch (status) {
    case READY:
        start();
        break;
    case STOPPED:
        stop();
        break;
    default:
        assert false : "status tidak dikenal";
}
```

**Penggunaan yang Dilarang**

> **TL;DR:** Jangan gunakan assertion untuk validasi public method atau operasi yang wajib terjadi.

Validasi argumen public method adalah bagian dari kontrak method. Karena kontrak publik harus selalu ditegakkan, pengecekan ini tidak boleh bergantung pada assertion yang bisa dimatikan. Untuk public method, gunakan runtime exception yang sesuai seperti `IllegalArgumentException`, `IndexOutOfBoundsException`, atau `NullPointerException`.

Assertion juga tidak boleh memuat *side effects* yang penting bagi program. Jika assertion disabled, ekspresi tidak dievaluasi sehingga operasi tersebut tidak terjadi.

- Pola salah:

```java
assert names.remove(null);
```

- Pola benar:

```java
boolean nullsRemoved = names.remove(null);
assert nullsRemoved;
```

- Catatan detail:
  - Secara umum, ekspresi assertion harus bebas *side effects*.
  - Pengecualian teoretis: state boleh diubah jika state tersebut hanya digunakan oleh assertion lain dan tidak memengaruhi perilaku program utama.

**Assertion vs Exception**

> **TL;DR:** Assertion menandai bug internal programmer, sedangkan exception menangani kondisi error yang menjadi bagian dari kontrak runtime.

Walaupun assertion gagal dengan melempar `AssertionError`, assertion bukan mekanisme utama penanganan error aplikasi. `AssertionError` adalah turunan `Error`, bukan `Exception`, sehingga bersifat unchecked dan tidak disarankan untuk ditangkap.

- Gunakan assertion untuk:
  - asumsi internal yang seharusnya selalu benar;
  - debugging;
  - dokumentasi asumsi logika.
- Gunakan exception untuk:
  - validasi argumen public method;
  - input user yang salah;
  - kondisi runtime yang memang perlu ditangani;
  - kontrak API yang harus selalu berlaku.

**Perbandingan Singkat dengan C++**

> **TL;DR:** Java mengaktifkan assertion dengan `-ea`, sedangkan C++ mematikan assertion dengan `NDEBUG`.

Pada C++, assertion berasal dari makro `<cassert>` atau `<assert.h>`. Jika assertion gagal, program menulis pesan ke standard error lalu memanggil `abort`. Assertion C++ dapat dimatikan dengan `#define NDEBUG` sebelum menyertakan header assertion. Detail ini penting agar tidak tertukar dengan Java yang menggunakan opsi runtime `-ea`.

#### Komponen Kunci

- `assert`: statement Java untuk memeriksa asumsi boolean.
- `AssertionError`: error yang dilempar ketika assertion gagal.
- `Expression1`: ekspresi boolean utama dalam assertion.
- `Expression2`: nilai pesan detail saat assertion gagal.
- `-ea`: opsi runtime untuk mengaktifkan assertion.
- *Internal invariant*: asumsi internal yang harus selalu benar.
- *Control-flow invariant*: asumsi bahwa jalur kontrol tertentu tidak akan dicapai.
- *Class invariant*: kondisi konsistensi objek.
- *Precondition*: syarat sebelum method dijalankan.
- *Postcondition*: syarat setelah method selesai.
- *Side effect*: perubahan state akibat evaluasi ekspresi.
- `IllegalArgumentException`: runtime exception umum untuk argumen public method yang tidak valid.
- `NullPointerException`: runtime exception untuk nilai `null` yang tidak diizinkan.
- `IndexOutOfBoundsException`: runtime exception untuk indeks di luar rentang.

#### Checklist Pemahaman

1. **Sub-materi yang dibahas**
   - Definisi assertion
   - `AssertionError`
   - dua bentuk sintaks `assert`
   - aktivasi dengan `-ea`
   - internal, control-flow, dan class invariant
   - precondition/postcondition
   - larangan public method
   - larangan side effects
   - perbedaan assertion dan exception
   - perbandingan singkat Java dan C++

2. **Prioritas belajar**
   - 🔴 Wajib dikuasai
     - Sintaks `assert`
     - default disabled dan opsi `-ea`
     - kapan memakai assertion
     - kapan memakai exception
     - larangan side effects
   - 🟡 Cukup paham konsep
     - `AssertionError` sebagai turunan `Error`
     - postcondition sebelum `return`
     - perbandingan dengan C++
   - ✅ Sudah dikuasai
     - Tidak ditandai sebagai sudah dikuasai pada daftar awal.
