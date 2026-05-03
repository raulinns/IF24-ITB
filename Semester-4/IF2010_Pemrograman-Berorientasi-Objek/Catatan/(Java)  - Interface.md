## Java Interface
### Outline Konsep Fundamental

- Definisi interface
- Motivasi: mengapa interface dibutuhkan
  - Batasan single inheritance
  - Ambiguity problem & run-time efficiency problem
  - Kasus lintas hierarki
- Interface vs Abstract Class
- Deklarasi interface (`interface`)
- Implementasi interface (`implements`)
- Aturan isi interface
  - Abstract method (wajib)
  - Konstanta statik
- Multiple interface implementation
- Interface inheritance (`extends` antar interface)
- Kapan memilih interface vs abstract class

---

### Penjelasan Materi

#### Definisi Interface

**TL;DR:** *Interface adalah kontrak perilaku murni — hanya mendefinisikan apa yang harus dilakukan, bukan bagaimana.*

Interface adalah representasi kontrak abstrak yang mirip dengan *pure abstract class*, namun **sama sekali tidak memiliki state internal** — tidak ada constructor, destructor, maupun variabel instans. Interface hanya mendefinisikan *behavior* (perilaku) melalui deklarasi method dan dapat memiliki konstanta statik.

#### Motivasi: Mengapa Interface Dibutuhkan

**TL;DR:** *Interface lahir karena Java melarang multiple inheritance, tetapi kebutuhan lintas hierarki tetap ada.*

Java sengaja melarang *multiple inheritance* untuk kelas guna menghindari dua masalah:

- **Ambiguity problem** — jika dua superclass punya method dengan nama sama, JVM tidak tahu method mana yang dipanggil
- **Run-time efficiency problem** — JVM lebih lambat menelusuri hierarki multiple inheritance

Namun, pelarangan ini menimbulkan masalah baru:

- `House` (turunan `Building`) dan `Car` (turunan `Vehicle`) sama-sama barang berharga, tetapi tidak punya superclass bersama selain `Object` — padahal tidak semua `Object` punya nilai
- Di game, `Paladin` bisa *attack* sekaligus *heal*, sementara `Mage` hanya bisa *attack* dan `Healer` hanya bisa *heal*. Jika fungsionalitas ini dipaksakan ke superclass `Character`, maka `Healer` akan mewarisi `attack` yang tidak relevan

Interface menawarkan **partial multiple inheritance yang aman** — memberikan kebebasan mendistribusikan fungsionalitas lintas hierarki tanpa merusak hierarki kelas murni.

#### Interface vs Abstract Class

**TL;DR:** *Abstract class untuk kelas sekeluarga + bisa berbagi implementasi; Interface untuk kontrak perilaku lintas hierarki.*

| Aspek | Abstract Class | Interface |
|---|---|---|
| Concrete method | **Boleh** | **Tidak boleh** (semua method harus abstract) |
| Variabel instans | Boleh | Tidak ada (hanya konstanta statik) |
| Constructor | Ada | **Tidak ada** |
| Jumlah yang bisa dipakai 1 kelas | Hanya **1** (single inheritance) | **Tak terbatas** |
| Keyword pewarisan | `extends` | `implements` |
| Hubungan antar kelas | Erat (*closely related*) | Tidak harus berhubungan |
| Contoh use case | `AbstractList` → `ArrayList`, `LinkedList` | `Comparable` diimplementasikan `Integer` & `String` |

#### Deklarasi & Implementasi Interface

**TL;DR:** *Gunakan keyword `interface` untuk deklarasi, `implements` untuk penerapan ke kelas.*

- **Deklarasi** — menggunakan keyword `interface` menggantikan `class`
- **Implementasi** — menggunakan keyword `implements` pada deklarasi kelas; jika lebih dari satu, dipisah koma
- Kelas yang mengimplementasikan interface wajib mengimplementasikan (override) **seluruh** abstract method yang ada di interface

```java
// Deklarasi interface
interface Setorable {
    public void setor(double uang);
}

interface Tarikable {
    public void tarik(double uang);
}

// Interface mewarisi interface lain (boleh multiple)
interface IRekening extends Tarikable, Setorable {
    public void update();
    public String getNama();
    public double getSaldo();
}

// Kelas mengimplementasikan interface (sekaligus extend class)
abstract class Rekening implements IRekening {
    protected String nama;
    protected double saldo;
    // wajib implementasikan semua method dari IRekening
}
```

#### Aturan Isi Interface

**TL;DR:** *Interface di Java (versi dokumen) hanya boleh berisi abstract method dan konstanta statik.*

- **Abstract method** — semua method instans di dalam interface wajib berupa abstract method (hanya signature, tanpa bodi)
- **Konstanta statik** — satu-satunya member variabel yang diizinkan; secara implisit bersifat `public static final`
- Tidak ada constructor, tidak ada variabel instans, tidak ada concrete method

> **Catatan:** Fitur `default method` dan `static method` pada interface (Java 8+) **tidak tercakup dalam dokumen sumber**. Verifikasi ke referensi Java modern jika diujikan.

#### Multiple Interface Implementation

**TL;DR:** *Satu kelas boleh mengimplementasikan banyak interface sekaligus — inilah solusi multiple inheritance Java.*

```java
// Kelas yang implements dua interface sekaligus
class Paladin extends Character implements Attackable, Healable {
    @Override
    public void attack() { /* implementasi */ }

    @Override
    public void heal() { /* implementasi */ }
}
```

Secara polimorfis, objek `Paladin` dapat diperlakukan sebagai tipe `Attackable` maupun `Healable` maupun `Character`.

#### Interface Inheritance

**TL;DR:** *Interface bisa meng-extend interface lain — bahkan boleh multiple, karena tidak ada bodi yang bisa konflik.*

```java
interface A { void methodA(); }
interface B { void methodB(); }

// Interface C mewarisi A dan B sekaligus (boleh, karena tidak ada implementasi yang konflik)
interface C extends A, B {
    void methodC();
}
```

#### Kapan Memilih Interface vs Abstract Class

- **Pilih Abstract Class** bila:
  - Kelas-kelas turunan sangat erat berhubungan secara struktural
  - Ada algoritma dasar yang bisa langsung dibagikan sebagai concrete method
- **Pilih Interface** bila:
  - Hanya ingin memberikan *contract behavior* murni tanpa implementasi
  - Ingin menyatukan kemampuan kelas-kelas yang **tidak** memiliki hubungan kekerabatan (contoh: `Integer` dan `String` sama-sama `Comparable`)
  - Butuh arsitektur *multiple inheritance*

---

### Komponen Kunci

- **`interface`** — keyword deklarasi interface; pengganti `class`
- **`implements`** — keyword untuk menerapkan interface ke kelas
- **`extends` (antar interface)** — interface mewarisi interface lain; boleh multiple
- **Kontrak (*contract*)** — kewajiban kelas pengimplementasi untuk mengimplementasikan seluruh abstract method interface
- **Konstanta statik** — satu-satunya variabel yang diizinkan dalam interface (`public static final` secara implisit)
- **Multiple implementation** — satu kelas boleh `implements` banyak interface sekaligus
- **Polymorphism via interface** — objek dapat diperlakukan sebagai tipe interface yang diimplementasikannya

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- Definisi interface
- Motivasi: single inheritance limitation, ambiguity problem, kasus lintas hierarki
- Interface vs abstract class (tabel perbandingan)
- Deklarasi (`interface`) & implementasi (`implements`)
- Aturan isi interface (abstract method + konstanta)
- Multiple interface implementation
- Interface inheritance (`extends` antar interface)
- Kapan memilih interface vs abstract class
- Sintaks lengkap

**Prioritas belajar:**

- 🔴 *Wajib dikuasai* — Mengapa interface dibutuhkan (motivasi single inheritance), perbedaan interface vs abstract class, keyword `interface`/`implements`/`extends`, aturan isi interface (semua method abstract, hanya konstanta), multiple interface implementation, sintaks deklarasi & implementasi
- 🟡 *Cukup paham konsep* — Interface inheritance (extends antar interface), polimorfisme via interface, kasus `Comparable` lintas hierarki
