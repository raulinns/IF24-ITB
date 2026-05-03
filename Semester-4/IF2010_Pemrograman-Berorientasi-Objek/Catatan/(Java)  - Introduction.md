# Outline UTS Pemrograman Berbasis Objek

> **Catatan sumber:** Dokumen di NotebookLM tidak memuat data CPMK. Bagian *Hubungan dengan CPMK* diisi berdasarkan inferensi konteks mata kuliah PBO.

---

## ✅ Pendahuluan OOP di Java

> *Materi ini ditandai sudah dikuasai (dasar OOP + C++ sudah dikuasai). Bagian ini disajikan ringkas dengan fokus pada **perbedaan dan kekhasan Java** dibanding C++.*

### Hubungan dengan CPMK

Materi ini menjadi fondasi seluruh perkuliahan PBO. Relevan dengan CPMK pemahaman paradigma OOP dan penerapannya dalam bahasa Java — menjadi prasyarat untuk semua materi lanjutan (Interface, Generic, Collection).

---

### Outline Konsep Fundamental

- OOP di Java: Prinsip Dasar
  - Class & Object
  - Encapsulation
  - Inheritance (single inheritance)
  - Polymorphism
  - Abstraction
- Kekhasan Java vs C++
  - Deklarasi & definisi kelas
  - Constructor (tanpa copy constructor, tanpa destructor)
  - Access modifiers
  - Parameter passing
  - Tidak ada operator overloading, tidak ada pointer
- Elemen Sintaks Java
  - Deklarasi class & instansiasi object
  - Constructor & overloading constructor
  - Keyword `this`
  - Access modifiers: `private`, `protected`, `public`, default
  - Static member

---

### Penjelasan Materi

#### Class & Object

**TL;DR:** *Class adalah blueprint/cetak biru; object adalah instansiasi nyata dari class tersebut.*

Class merupakan definisi statik yang mendefinisikan tipe objek, atribut, dan metode — deklarasi dan definisinya **selalu disatukan dalam satu file** di Java. Object adalah satuan unit hasil instansiasi yang memiliki *state* (atribut) dan *behavior* (metode).

#### Empat Pilar OOP di Java ✅

**TL;DR:** *Sama dengan C++, namun Java memiliki batasan dan sintaks tersendiri.*

- **Encapsulation** — menyembunyikan representasi internal objek; melindungi data dari modifikasi sembarangan
- **Inheritance** — keyword `extends`; Java hanya mendukung **single inheritance** (max satu superclass per kelas)
- **Polymorphism** — eksekusi method yang tepat ditentukan saat *runtime* berdasarkan tipe objek sesungguhnya, bukan tipe referensi deklarasinya
- **Abstraction** — diwujudkan via `abstract class`; kelas yang terlalu umum untuk diinstansiasi

#### Perbedaan Kunci Java vs C++ ✅

**TL;DR:** *Java lebih sederhana dan aman; menghapus beberapa fitur C++ yang rawan error.*

| Aspek | Java | C++ |
|---|---|---|
| Deklarasi & Definisi kelas | Selalu satu file | Bisa dipisah (`.h` + `.cpp`) |
| Copy constructor | **Tidak ada** | Ada |
| Destructor | **Tidak ada** (Garbage Collection otomatis) | Ada |
| Multiple inheritance | **Tidak ada** (hanya via Interface) | Ada |
| Operator overloading | **Tidak ada** | Ada |
| Parameter passing | **Pass by value saja** (termasuk referensi objek) | Pass by value & pass by reference |
| Pointer | **Tidak ada** | Ada |
| Pemanggilan constructor super | `super()` di baris pertama | Initialization list |
| Penulisan access modifier | Per-anggota (`private int x;`) | Blok (`private:`) |

#### Constructor & Keyword `this`

**TL;DR:** *Constructor menginisialisasi objek; `this` merujuk ke objek itu sendiri untuk menghindari ambiguitas.*

Constructor adalah metode khusus inisialisasi objek dengan aturan: nama harus identik dengan nama kelas, tidak memiliki return type, dan boleh di-*overload* (lebih dari satu, selama parameternya berbeda).

Keyword `this`:
- Merujuk langsung ke objek saat ini
- Menghindari ambiguitas nama: `this.radius = radius;`
- `this()` — memanggil constructor lain dalam kelas yang sama (harus di baris pertama)

#### Access Modifiers

**TL;DR:** *Empat level akses yang mengontrol visibilitas anggota kelas.*

| Modifier | Kelas Sendiri | Subclass | Package Sama | Kelas Lain |
|---|---|---|---|---|
| `private` | ✓ | ✗ | ✗ | ✗ |
| `protected` | ✓ | ✓ | ✓ | ✗ |
| `public` | ✓ | ✓ | ✓ | ✓ |
| *(default)* | ✓ | ✗ | ✓ | ✗ |

#### Static Member

**TL;DR:** *Static member dimiliki oleh kelas itu sendiri, bukan oleh instans/objek.*

Static member (variabel atau method) dialokasikan satu kali untuk seluruh program dan dapat diakses langsung via nama kelas tanpa perlu membuat objek terlebih dahulu.

---

### Komponen Kunci

- **Class** — blueprint/cetak biru objek
- **Object** — instansiasi dari class; memiliki state & behavior
- **`extends`** — keyword untuk inheritance di Java
- **`super()`** — memanggil constructor superclass (harus di baris pertama constructor subclass)
- **`this`** — referensi ke objek saat ini
- **`new`** — keyword instansiasi objek, mengalokasikan memori & memanggil constructor
- **Single inheritance** — Java hanya mengizinkan satu superclass langsung per kelas
- **Garbage Collection** — mekanisme Java membersihkan memori otomatis (tidak ada destructor)
- **Static member** — anggota kelas (bukan objek), diakses via nama kelas

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- Class & Object
- Empat pilar OOP (Encapsulation, Inheritance, Polymorphism, Abstraction)
- Perbedaan Java vs C++
- Constructor & overloading
- Keyword `this`
- Access modifiers
- Static member

**Prioritas belajar:**

- ✅ *Sudah dikuasai* — Empat pilar OOP (konsep), Constructor, Access modifiers
- 🔴 *Wajib dikuasai* — Perbedaan Java vs C++ (terutama single inheritance, tidak ada operator overloading, parameter passing, Garbage Collection), penggunaan `super()`, penulisan access modifier per-anggota
- 🟡 *Cukup paham konsep* — Static member, keyword `this()`

---

---

## Abstract Class *(Fondasi Sebelum Interface)*

### Hubungan dengan CPMK

Merupakan jembatan antara OOP dasar dan konsep Interface. Relevan dengan CPMK penerapan abstraksi dan perancangan hierarki kelas — langsung menjadi prasyarat konseptual untuk memahami *mengapa* Interface diperlukan.

---

### Outline Konsep Fundamental

- Definisi & motivasi abstract class
- Keyword `abstract`
- Abstract method vs concrete method
- Aturan-aturan abstract class
- Mengapa tidak bisa diinstansiasi
- Inheritance dari abstract class (`extends`)
- Abstract class vs concrete class
- Kapan menggunakan abstract class

---

### Penjelasan Materi

#### Definisi & Motivasi

**TL;DR:** *Abstract class merepresentasikan konsep yang terlalu umum untuk dijadikan objek nyata.*

Abstract class adalah representasi kelas dari konsep murni yang masih terlalu umum dan belum memiliki spesifikasi cukup untuk diwujudkan sebagai objek. Analogi: kita bisa menggambar *Lingkaran* dengan jari-jari tertentu, tetapi kita tidak bisa menggambar gagasan umum *Bangun Datar* begitu saja tanpa tahu bentuknya.

#### Keyword `abstract` & Jenis Method

**TL;DR:** *`abstract` pada class mencegah instansiasi; `abstract` pada method berarti hanya deklarasi tanpa bodi.*

- **Abstract method** — dideklarasikan dengan keyword `abstract`, hanya berupa *signature* tanpa bodi, langsung diakhiri `;`
  - Dipakai ketika tidak ada rumus/algoritma universal yang bisa diterapkan di level abstrak ini
- **Concrete method** — method biasa yang sudah memiliki bodi dan implementasi penuh
  - Digunakan saat ada algoritma umum yang bisa langsung dibagikan ke semua subclass

#### Aturan-Aturan Abstract Class

**TL;DR:** *Abstract class boleh punya nol hingga banyak abstract method; concrete class dilarang punya abstract method.*

- Abstract class boleh memiliki **nol** abstract method (tetap tidak bisa diinstansiasi)
- Abstract class **boleh** memiliki concrete method
- **Concrete class dilarang keras** menyimpan abstract method
- Abstract class **tidak bisa diinstansiasi** — menciptakan objeknya langsung menghasilkan error
- Subclass yang `extends` abstract class dan ingin menjadi concrete class **wajib meng-override semua abstract method** dari superclass-nya

#### Inheritance dari Abstract Class

**TL;DR:** *Gunakan `extends`; subclass wajib mengimplementasikan semua abstract method agar bisa diinstansiasi.*

```java
// Abstract class
public abstract class Shape {
    public abstract double area();       // abstract method — wajib di-override
    public abstract double perimeter();  // abstract method — wajib di-override
}

// Concrete subclass
public class Circle extends Shape {
    private final double PI = 3.14159;
    private double radius;

    public Circle(double r) { radius = r; }

    @Override
    public double area() { return PI * radius * radius; }

    @Override
    public double perimeter() { return 2 * PI * radius; }
}
```

#### Kapan Menggunakan Abstract Class

**TL;DR:** *Gunakan saat kelas-kelas yang ada sekeluarga (closely related) dan berbagi algoritma umum.*

- Ada dua atau lebih kelas yang berbagi atribut/perilaku serupa (hubungan *is-a*)
- Konsep "kelas induk" terlalu umum untuk diinstansiasi
- Kelas-kelas turunan sangat erat berhubungan secara fungsional (contoh: `AbstractList` → `ArrayList`, `LinkedList`)
- Sudah ada bagian algoritma yang bisa dibakukan sebagai concrete method, tapi detail spesifik diserahkan ke subclass

---

### Komponen Kunci

- **`abstract class`** — kelas yang tidak dapat diinstansiasi secara langsung
- **`abstract method`** — deklarasi method tanpa bodi; wajib di-override oleh concrete subclass
- **Concrete method** — method dengan implementasi penuh dalam abstract class
- **`extends`** — keyword untuk mewarisi abstract class
- **Override** — subclass wajib mengimplementasikan *semua* abstract method superclass untuk menjadi concrete

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- Definisi & motivasi abstract class
- Abstract method vs concrete method
- Aturan-aturan abstract class
- Mengapa tidak bisa diinstansiasi
- Cara inheritance dari abstract class
- Kapan menggunakan abstract class
- Sintaks lengkap

**Prioritas belajar:**

- 🔴 *Wajib dikuasai* — Aturan abstract class (terutama: concrete class dilarang punya abstract method; subclass wajib override semua abstract method), mengapa tidak bisa diinstansiasi, sintaks deklarasi & inheritance
- 🟡 *Cukup paham konsep* — Kapan memilih abstract class vs konkrit, perbedaan abstract vs concrete method secara konseptual

---