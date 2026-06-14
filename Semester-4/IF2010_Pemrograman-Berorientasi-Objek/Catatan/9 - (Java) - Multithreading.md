## Multithreading

#### Hubungan dengan CPMK

> **CPMK tidak disebutkan** - Materi ini relevan untuk memahami eksekusi program Java secara konkuren, pembagian kerja antar-thread, sinkronisasi akses resource bersama, dan penanganan exception yang muncul pada operasi thread.

#### Outline Konsep Fundamental

- Konsep dasar
  - thread
  - multithreading
  - scheduler
  - resource bersama
- Pembuatan thread
  - subclass `Thread`
  - implementasi `Runnable`
  - anonymous class
  - lambda expression
- Eksekusi dan siklus hidup
  - `run()`
  - `start()`
  - state `New`, `Runnable`, `Not Runnable`, `Dead`
  - `sleep()`
  - priority
  - `Timer` dan `TimerTask`
- Sinkronisasi
  - collision
  - object lock
  - `synchronized` method
  - `synchronized` block
- Komunikasi antar-thread
  - busy waiting
  - `wait()`
  - `notify()`
  - `notifyAll()`
  - producer-consumer
- Masalah lanjutan
  - `InterruptedException`
  - deadlock
  - starvation

#### Penjelasan Materi

**Konsep Dasar Thread dan Multithreading**

> **TL;DR:** Multithreading memungkinkan beberapa thread berjalan independen dalam satu proses sambil berbagi resource.

Thread adalah sekuens instruksi terprogram terkecil yang dapat dikelola secara independen oleh scheduler. Multithreading adalah model eksekusi yang memungkinkan banyak thread hidup di dalam satu proses. Thread-thread tersebut berjalan secara independen, tetapi tetap berbagi resource proses seperti memori objek.

Multithreading digunakan agar aplikasi tetap responsif dan mampu menjalankan pekerjaan yang tampak bersamaan. Contohnya adalah GUI yang tidak hang saat memproses data besar, server yang menangani banyak koneksi, aplikasi chat, atau browser yang mengunduh dan merender halaman sekaligus.

- Tujuan utama:
  - Menjaga responsivitas aplikasi.
  - Menangani banyak event atau koneksi.
  - Mendukung eksekusi asinkron.
  - Memanfaatkan pembagian kerja antar-unit eksekusi.

**Membuat Thread: `Thread` vs `Runnable`**

> **TL;DR:** Thread dapat dibuat dengan mewarisi `Thread` atau mengimplementasikan `Runnable`, tetapi `Runnable` lebih fleksibel ketika kelas sudah mewarisi kelas lain.

Cara pertama adalah membuat subclass dari `Thread` lalu melakukan override pada `run()`. Cara kedua adalah mengimplementasikan `Runnable` dan mengisi method `run()`. Karena Java hanya mendukung single inheritance, `Runnable` wajib dipilih jika kelas sudah `extends` kelas lain.

- Perbandingan:
  - Subclass `Thread`
    - Langsung mewarisi utilitas thread.
    - Tidak bisa mewarisi kelas lain.
  - Implementasi `Runnable`
    - Lebih fleksibel karena berbentuk interface.
    - Tetap perlu dibungkus dalam objek `Thread`.
    - Cocok untuk anonymous class dan lambda expression.

```java
class Worker extends Thread {
    public void run() {
        System.out.println("bekerja");
    }
}

new Worker().start();
```

```java
Runnable job = () -> System.out.println("bekerja");
new Thread(job).start();
```

**`run()` vs `start()`**

> **TL;DR:** `run()` berisi pekerjaan, sedangkan `start()` benar-benar membuat thread baru.

`run()` adalah method yang memuat instruksi yang ingin dijalankan oleh thread. Memanggil `run()` secara langsung hanya menjalankan method biasa secara sinkron pada thread saat ini. Untuk menjalankan thread baru secara independen, panggil `start()` pada objek `Thread`.

- Jebakan umum:
  - `obj.run()` tidak membuat thread baru.
  - `obj.start()` membuat thread baru lalu menjalankan `run()` di thread tersebut.
  - Soal ujian sering menampilkan kode yang sengaja memanggil `run()` langsung.

**Siklus Hidup Thread**

> **TL;DR:** Thread berpindah dari dibuat, siap/jalan, tertunda, lalu selesai.

Sebuah thread hidup selama method `run()` masih berjalan. Thread dapat berhenti sementara karena menunggu I/O, menjalankan `sleep()`, atau menunggu event melalui `wait()`.

- State penting:
  - `New Thread`
    - Objek `Thread` baru dibuat, tetapi `start()` belum dipanggil.
  - `Runnable`
    - Thread siap dijalankan atau sedang dijalankan CPU.
    - Dapat terjadi `yield`, yaitu thread menyerahkan sisa waktunya ke thread lain.
  - `Not Runnable`
    - Thread tertunda karena `sleep()`, `wait()`, atau menunggu I/O.
  - `Dead`
    - Method `run()` selesai.

**`sleep()`, Priority, dan Timer**

> **TL;DR:** `sleep()` menunda thread, priority memengaruhi penjadwalan, dan `Timer` menyederhanakan pekerjaan berbasis waktu.

`sleep()` menunda eksekusi thread selama sejumlah milidetik. Method ini dapat melempar `InterruptedException`, sehingga perlu ditangani dengan `try-catch` atau dideklarasikan.

Thread priority berada pada rentang 1 sampai 10. Thread dengan prioritas lebih tinggi lebih sering dijadwalkan, tetapi tidak boleh dijadikan satu-satunya dasar kebenaran program karena detail penjadwalan bergantung pada runtime.

`Timer` dan `TimerTask` digunakan untuk menjadwalkan pekerjaan di masa depan tanpa membuat thread manual untuk setiap kasus. `TimerTask` dibuat dengan subclass dan override `run()`.

- Method penting `Timer`:
  - `schedule(task, delay)`: menjalankan task sekali setelah delay.
  - `scheduleAtFixedRate(task, delay, period)`: menjalankan task berulang tiap period.

**Sinkronisasi dan Object Lock**

> **TL;DR:** `synchronized` mencegah lebih dari satu thread memasuki bagian kritis objek pada saat yang sama.

Masalah utama multithreading muncul ketika beberapa thread mengakses atau mengubah resource yang sama secara bersamaan. Ini dapat menyebabkan collision atau data tidak konsisten. Java menyediakan object lock melalui keyword `synchronized`.

`synchronized` dapat ditaruh pada method atau blok. Menambahkan `synchronized` pada deklarasi method ekuivalen dengan membungkus seluruh isi method dalam `synchronized(this)`.

- Bentuk sinkronisasi:
  - `synchronized` method
    - Mengunci objek pemanggil untuk seluruh isi method.
  - `synchronized` block
    - Mengunci objek tertentu hanya untuk bagian kode yang diperlukan.

```java
public synchronized void put(Object value) {
    this.value = value;
}
```

```java
public void put(Object value) {
    synchronized (this) {
        this.value = value;
    }
}
```

**Busy Waiting dan Wait-Notify**

> **TL;DR:** Busy waiting membuang CPU; `wait()` dan `notifyAll()` membuat thread menunggu secara efisien.

Busy waiting terjadi ketika thread menunggu kondisi dengan loop kosong seperti `while (!available);`. Ini buruk karena CPU tetap dipakai tanpa pekerjaan produktif. Solusinya adalah komunikasi antar-thread menggunakan `wait()`, `notify()`, dan `notifyAll()`.

- Perbandingan:
  - Busy waiting
    - Thread terus berputar dalam loop.
    - Boros CPU.
    - Tidak efisien.
  - Wait-notify
    - Thread tidur dengan `wait()`.
    - Thread lain memberi sinyal dengan `notify()` atau `notifyAll()`.
    - Lebih efisien dan idiomatis.

- `notify()` vs `notifyAll()`:
  - `notify()` membangunkan satu thread yang sedang menunggu.
  - Thread mana yang dibangunkan bergantung pada implementasi runtime.
  - `notifyAll()` membangunkan semua thread yang sedang menunggu dan umumnya lebih direkomendasikan.

**Pola Producer-Consumer**

> **TL;DR:** Producer-consumer mengatur thread pembuat dan pengambil data agar tidak saling menimpa atau membaca data kosong.

Pola producer-consumer menggunakan objek penampung bersama. Producer menaruh data; consumer mengambil data. Jika penampung penuh, producer harus menunggu. Jika penampung kosong, consumer harus menunggu.

- Langkah method `get()` oleh consumer:
  - Masuk ke method tersinkronisasi.
  - Selama data belum tersedia, panggil `wait()`.
  - Setelah data tersedia, ambil data.
  - Set status menjadi kosong.
  - Panggil `notifyAll()` agar producer tahu tempat kosong.
  - Kembalikan data.

- Langkah method `put()` oleh producer:
  - Masuk ke method tersinkronisasi.
  - Selama data lama masih tersedia, panggil `wait()`.
  - Masukkan data baru.
  - Set status menjadi tersedia.
  - Panggil `notifyAll()` agar consumer tahu data siap.

**`InterruptedException`, Deadlock, dan Starvation**

> **TL;DR:** Operasi tunggu dapat diinterupsi, sedangkan deadlock dan starvation adalah risiko konkurensi yang perlu dikenali.

`InterruptedException` dapat muncul ketika thread yang sedang tidur atau menunggu melalui `sleep()` atau `wait()` diinterupsi. Karena termasuk checked exception, pemanggilan tersebut harus ditangani.

Deadlock terjadi ketika beberapa thread saling menunggu lock sehingga tidak ada yang bisa lanjut. Starvation terjadi ketika thread tidak memperoleh resource atau kesempatan eksekusi karena terus kalah prioritas atau kalah antrean.

- Fokus ujian:
  - `sleep()` dan `wait()` perlu menangani `InterruptedException`.
  - Deadlock adalah saling tunggu lock.
  - Starvation adalah kekurangan kesempatan eksekusi/resource.

#### Komponen Kunci

- `Thread`: unit instruksi terkecil yang dijadwalkan secara independen.
- Multithreading: beberapa thread dalam satu proses.
- Scheduler: pengelola eksekusi thread.
- `Runnable`: interface berisi kontrak `run()`.
- `run()`: pekerjaan yang dijalankan thread.
- `start()`: method untuk memulai thread baru.
- `sleep()`: menunda thread selama waktu tertentu.
- Priority: nilai prioritas thread dari 1 sampai 10.
- `Timer`: penjadwal pekerjaan berbasis waktu.
- `TimerTask`: task yang dijalankan oleh `Timer`.
- `synchronized`: mekanisme lock untuk menghindari collision.
- Object lock: kunci objek saat bagian sinkron dieksekusi.
- Busy waiting: menunggu dengan loop kosong.
- `wait()`: membuat thread menunggu event.
- `notify()`: membangunkan satu thread yang menunggu.
- `notifyAll()`: membangunkan semua thread yang menunggu.
- Producer-consumer: pola koordinasi pembuat dan pengambil data.
- `InterruptedException`: checked exception saat thread tertunda diinterupsi.
- Deadlock: thread saling menunggu lock.
- Starvation: thread kekurangan kesempatan memperoleh resource.

#### Checklist Pemahaman

1. **Sub-materi yang dibahas**
   - definisi thread dan multithreading
   - `Thread` vs `Runnable`
   - anonymous class dan lambda
   - `start()` vs `run()`
   - siklus hidup thread
   - `sleep()`, priority, `Timer`, `TimerTask`
   - `synchronized` method dan block
   - busy waiting
   - `wait()`, `notify()`, `notifyAll()`
   - producer-consumer
   - `InterruptedException`
   - deadlock dan starvation

2. **Prioritas belajar**
   - 🔴 Wajib dikuasai
     - `Thread` vs `Runnable`
     - `start()` vs `run()`
     - `synchronized`
     - `wait()`, `notify()`, `notifyAll()`
     - producer-consumer
     - `InterruptedException`
   - 🟡 Cukup paham konsep
     - state siklus hidup thread
     - priority
     - `Timer` dan `TimerTask`
     - deadlock dan starvation
   - ✅ Sudah dikuasai
     - Tidak ditandai sebagai sudah dikuasai pada daftar awal.
