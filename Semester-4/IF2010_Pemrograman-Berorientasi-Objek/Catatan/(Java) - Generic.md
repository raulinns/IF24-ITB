# Java Generic
### Outline Konsep Fundamental

- Motivasi & definisi Generic
  - Masalah tanpa Generic: kelas spesifik per tipe vs Object casting
  - Solusi: type parameter
- Type parameter
  - Konvensi penamaan (T, E, K, V, N, S, U)
- Generic Class
  - Deklarasi dengan `<T>`
  - Instansiasi dengan tipe konkret
  - Pembatasan: tidak bisa pakai tipe primitif
- Generic Method
  - Deklarasi `<T>` sebelum return type
  - Type inference
- Generic Interface
- Bounded Type Parameter
  - Upper bound dengan `extends`
  - Mengapa dibutuhkan
- Multiple Bounds
  - Operator `&`
  - Aturan urutan: Class dahulu, baru Interface
- Generic & Inheritance
  - `Box<Integer>` **bukan** subtype dari `Box<Number>`
  - Alasan: menjaga type safety
  - Solusi: Wildcard (dibahas di materi berikutnya)

---

### Penjelasan Materi

#### Motivasi & Definisi Generic

**TL;DR:** *Generic memungkinkan kode yang sama bekerja untuk berbagai tipe data tanpa mengorbankan type safety.*

Tanpa Generic, ada dua pilihan yang sama-sama bermasalah untuk membuat struktur data yang fleksibel:

- **Kelas spesifik per tipe** (`StringBox`, `IntegerBox`, dst.) — kode berulang, tidak OOP
- **Menggunakan tipe `Object`** — fleksibel, tetapi *type safety* hilang karena:
  - Memerlukan *casting* manual: `(String) box.getValue()`
  - Jika tipe tidak cocok, baru ketahuan saat *runtime* → `ClassCastException`

Generic menyelesaikan kedua masalah ini sekaligus: kode satu kali, berlaku untuk banyak tipe, dan kesalahan tipe terdeteksi saat **kompilasi** (*compile-time checking*), bukan saat runtime.

#### Perbandingan: Object Casting vs Generic

**TL;DR:** *Generic memindahkan pengecekan tipe dari runtime ke compile-time, menghilangkan kebutuhan casting manual.*

| Aspek | Tanpa Generic (`Object`) | Dengan Generic |
|---|---|---|
| Type safety | Tidak ada | Ada (*compile-time checked*) |
| Casting manual | Wajib dilakukan | Ditangani otomatis oleh Java |
| Error terdeteksi | Saat *runtime* (`ClassCastException`) | Saat *kompilasi* (compile error) |
| Fleksibilitas tipe | Sangat fleksibel (tapi tidak aman) | Fleksibel **dan** aman |

#### Konvensi Penamaan Type Parameter

**TL;DR:** *Nama type parameter adalah satu huruf kapital; ada konvensi standar yang dipakai Java.*

- `T` — Type (tipe data umum)
- `E` — Element (dipakai Java Collections Framework)
- `K` — Key
- `V` — Value
- `N` — Number
- `S`, `U`, `V`, ... — untuk parameter tipe ke-2, ke-3, dst.

#### Generic Class

**TL;DR:** *Tambahkan `<T>` setelah nama kelas untuk mendeklarasikan generic class.*

```java
// Deklarasi Generic Class
class Box<T> {
    private T value;

    public void setValue(T newVal) {
        value = newVal;
    }

    public T getValue() {
        return value;
    }
}

// Instansiasi: gunakan tipe konkret
public class Main {
    public static void main(String[] args) {
        Box<String> stringBox = new Box<>();     // diamond notation <>
        stringBox.setValue("Abc123");
        String kata = stringBox.getValue();      // tidak perlu casting manual

        Box<Integer> intBox = new Box<>();       // Integer, bukan int (primitif)
        intBox.setValue(100);
        Integer score = intBox.getValue();
    }
}
```

Aturan penting:
- Saat instansiasi, **tidak bisa menggunakan tipe primitif** (`int`, `double`, dst.)
- Wajib menggunakan *wrapper class*: `Integer`, `Double`, `Character`, dst.
- Gunakan *diamond notation* `<>` saat instansiasi — Java akan meng-*infer* tipenya

#### Generic Method

**TL;DR:** *Letakkan `<T>` sebelum return type untuk mendeklarasikan generic method — berlaku juga untuk constructor.*

```java
public class Element {
    // Generic method: <T> sebelum void
    public static <T> void printArray(T[] array) {
        for (T item : array) {
            System.out.println(item);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        String[] names = {"Ayu", "Budi"};
        Integer[] scores = {90, 85, 100};

        Element.printArray(names);                  // type inference: Java tebak tipe otomatis
        Element.<Integer>printArray(scores);        // explicit type specification
    }
}
```

#### Generic Interface

**TL;DR:** *Interface juga bisa dideklarasikan generik; kelas yang mengimplementasikannya menyuplai tipe konkret.*

```java
// Deklarasi Generic Interface
interface NamaInterface<T1, T2> {
    public T1 doSomething(T2 item);
}

// Implementasi dengan tipe konkret
class Implementasi implements NamaInterface<String, Integer> {
    public String doSomething(Integer item) {
        return "Angkanya adalah " + item;
    }
}
```

#### Bounded Type Parameter

**TL;DR:** *Gunakan `extends` di dalam `<>` untuk membatasi tipe apa saja yang boleh dipakai sebagai type parameter.*

Dibutuhkan ketika algoritma di dalam kelas/method generik hanya valid untuk tipe tertentu — misalnya kalkulasi matematika hanya untuk angka (`Number`), atau jus buah hanya untuk tipe `Buah`.

Keyword `extends` dipakai untuk upper bound, berlaku baik untuk **class** maupun **interface**.

```java
// T dibatasi: hanya Buah atau subclass-nya
class JusBuah<T extends Buah> {
    private T buah;
    public JusBuah(T buah) { this.buah = buah; }
    public T getBuah() { return buah; }
}

public class Main {
    public static void main(String[] args) {
        JusBuah<Apel> jusApel     = new JusBuah<>(new Apel());    // OK
        JusBuah<Mangga> jusMangga = new JusBuah<>(new Mangga());  // OK
        // JusBuah<Sawi> jusSawi  = new JusBuah<>(new Sawi());    // COMPILE ERROR
    }
}
```

#### Multiple Bounds

**TL;DR:** *Gunakan `&` untuk menggabungkan beberapa bound; class wajib ditulis pertama sebelum interface.*

```java
// T harus: turunan Buah, DAN mengimplementasikan Washable, DAN Storable
class JusMaker<T extends Buah & Washable & Storable> {
    public void makeJuice(T buah) {
        buah.wash();
        buah.store();
        System.out.println("Membuat jus dari " + buah.getName());
    }
}

// Pada generic method
public <U extends Number & SomeInterface> void methodB(U u) { ... }
```

Aturan wajib:
- Jika ada kombinasi Class dan Interface: **Class ditulis pertama**
- Interface-interface ditulis sesudahnya, dipisahkan `&`

#### Generic & Inheritance

**TL;DR:** *`Box<Integer>` BUKAN subtype dari `Box<Number>`, meski `Integer` adalah subtype dari `Number`.*

Meskipun `Integer extends Number` berlaku dalam hierarki kelas biasa, **aturan ini tidak otomatis berlaku untuk tipe generiknya**:

```java
List<Integer> integers = new ArrayList<>();

// COMPILE ERROR — List<Integer> bukan subtype dari List<Number>
List<Number> numbers = integers;

// Mengapa dilarang? Karena jika diizinkan, ini bisa terjadi:
// numbers.add(3.14);  // memasukkan Double ke dalam List<Integer> — merusak type safety!
```

Ringkasan:
- `Integer` → subtype dari `Number` ✓
- `Box<Integer>` → **bukan** subtype dari `Box<Number>` ✗
- `List<String>` → **bukan** subtype dari `List<Object>` ✗

Namun, nilai yang dimasukkan ke dalam objek `Box<Number>` yang sudah dideklarasikan tetap bisa berupa `Integer` atau `Double` (karena *is-a* tetap berlaku pada *value*-nya).

> Untuk membuat generic lebih fleksibel tanpa melanggar type safety, Java menyediakan **Wildcard** (`<?>`, `<? extends T>`, `<? super T>`) — dibahas di materi berikutnya.

---

### Komponen Kunci

- **Generic / Type Parameter** — placeholder tipe (`T`, `E`, dll.) yang diganti tipe konkret saat instansiasi
- **`<T>`** — sintaks deklarasi type parameter; diletakkan setelah nama class/interface atau sebelum return type pada method
- **Diamond notation `<>`** — penulisan singkat saat instansiasi; Java meng-*infer* tipe secara otomatis
- **Type safety** — jaminan kesesuaian tipe yang dicek saat kompilasi, bukan runtime
- **Compile-time checking** — kesalahan tipe terdeteksi saat kompilasi, mencegah `ClassCastException`
- **Upper bound** — pembatasan type parameter dengan `extends`: `<T extends Buah>`
- **Multiple bounds** — kombinasi beberapa batasan dengan `&`: `<T extends Buah & Washable>`
- **Wrapper class** — pengganti tipe primitif saat instansiasi generik (`Integer`, `Double`, `Character`, dst.)
- **Type inference** — kemampuan Java menebak tipe secara otomatis dari konteks

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- Motivasi & definisi Generic
- Perbandingan Object casting vs Generic
- Konvensi penamaan type parameter
- Deklarasi & instansiasi Generic Class
- Deklarasi Generic Method (termasuk type inference)
- Generic Interface
- Bounded Type Parameter (upper bound dengan `extends`)
- Multiple Bounds (operator `&`, aturan urutan)
- Generic & Inheritance (`Box<Integer>` bukan subtype `Box<Number>`)

**Prioritas belajar:**

- 🔴 *Wajib dikuasai* — Mengapa Generic dibutuhkan (motivasi vs Object), perbedaan Object casting vs Generic (type safety, compile-time checking), sintaks deklarasi Generic Class & Method, bounded type parameter dengan `extends`, aturan `Box<Integer>` bukan subtype `Box<Number>`
- 🟡 *Cukup paham konsep* — Konvensi penamaan type parameter, multiple bounds (aturan urutan Class dahulu), Generic Interface, type inference, wrapper class
