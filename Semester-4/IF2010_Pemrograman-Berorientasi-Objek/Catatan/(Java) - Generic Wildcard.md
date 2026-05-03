# Java Generic Wildcard
### Outline Konsep Fundamental

- Mengapa wildcard dibutuhkan
  - Keterbatasan invariance pada Generic
  - Masalah: `List<Integer>` bukan subtype `List<Number>`
- Tiga jenis wildcard
  - Unbounded Wildcard `<?>`
  - Upper Bounded Wildcard `<? extends T>`
  - Lower Bounded Wildcard `<? super T>`
- Prinsip PECS *(Producer Extends, Consumer Super)*
- Ringkasan: kapan pakai extends, super, atau tidak pakai wildcard

---

### Penjelasan Materi

#### Mengapa Wildcard Dibutuhkan

**TL;DR:** *Wildcard mengatasi kekakuan hierarki Generic yang melarang `List<Integer>` dianggap sebagai `List<Number>`.*

Seperti dibahas di materi Generic, Java menerapkan aturan *invariance* pada tipe generik: `List<Integer>` **bukan** subtype dari `List<Number>`, meskipun `Integer extends Number`. Aturan ini menjaga type safety, tetapi membuat kode tidak fleksibel.

Masalah konkret: bagaimana membuat satu method yang bisa menerima `List<Integer>`, `List<Double>`, dan `List<Float>` sekaligus (yang semuanya turunan `Number`)? Dengan `List<Number>` tidak bisa, karena `List<Integer>` bukan `List<Number>`. Di sinilah **Wildcard** — dilambangkan dengan `?` — menjadi solusi: merepresentasikan *tipe yang belum diketahui* secara fleksibel, tetapi tetap type-safe.

---

#### Unbounded Wildcard `<?>`

**TL;DR:** *`<?>` berarti "tipe apa saja" — hanya boleh dibaca, hasilnya selalu `Object`.*

`List<?>` adalah *ancestor* (leluhur) dari semua jenis `List`. Tipe spesifik di dalamnya tidak diketahui.

- **Kapan digunakan:** Ketika tidak peduli dengan tipe spesifik isi koleksi
- **Boleh:** Membaca elemen — tetapi hasilnya hanya bisa diperlakukan sebagai `Object`
- **Tidak boleh:** Menambah elemen baru (kecuali `null`) — karena tipe pastinya tidak diketahui, memasukkan data apapun bisa merusak type safety

```java
public void printListOfUnknowns(List<?> l) {
    for (Object e : l) {
        System.out.println(e);  // hanya bisa dibaca sebagai Object
    }
}

// Bisa menerima List tipe apapun
List<String> ls = new ArrayList<>();
ls.add("hello");
printListOfUnknowns(ls);   // OK

List<Integer> li = new ArrayList<>();
li.add(42);
printListOfUnknowns(li);   // OK

// l.add("something");  // COMPILE ERROR — tidak boleh menulis
```

---

#### Upper Bounded Wildcard `<? extends T>`

**TL;DR:** *`<? extends T>` = "T atau subclass-nya" — aman untuk **dibaca**, tidak boleh ditulis.*

Membatasi tipe agar hanya menerima `T` atau turunannya. Sesuai prinsip PECS, wildcard ini dipakai saat koleksi bertindak sebagai **Producer** (menyediakan data untuk dibaca).

- **Kapan digunakan:** Method hanya perlu **membaca** data dari koleksi
- **Boleh:** Membaca elemen — dikembalikan sebagai tipe `T`
- **Tidak boleh:** Menambah/menulis elemen baru — kompiler tidak tahu tipe spesifik di balik `?` (bisa `List<Integer>`, `List<Double>`, dll.), sehingga menulis nilai apapun berisiko merusak type safety

```java
// Menerima List<Integer>, List<Double>, List<Float>, dll.
public static double sum(List<? extends Number> numbers) {
    double total = 0;
    for (Number n : numbers) {   // aman DIBACA sebagai Number
        total += n.doubleValue();
    }
    return total;
}

List<Integer> ints = List.of(1, 2, 3);
List<Double>  dbls = List.of(1.5, 2.5);

System.out.println(sum(ints));  // OK
System.out.println(sum(dbls));  // OK

// numbers.add(10);  // COMPILE ERROR — tidak boleh menulis
```

---

#### Lower Bounded Wildcard `<? super T>`

**TL;DR:** *`<? super T>` = "T atau superclass-nya" — aman untuk **ditulis**, dibaca hanya sebagai `Object`.*

Membatasi tipe agar hanya menerima `T` atau leluhurnya (superclass). Sesuai prinsip PECS, wildcard ini dipakai saat koleksi bertindak sebagai **Consumer** (menerima/menyimpan data yang ditulis).

- **Kapan digunakan:** Method hanya perlu **menulis/menambah** data ke koleksi
- **Boleh:** Menambah elemen bertipe `T` — aman karena `T` pasti kompatibel dengan semua tipe di atas `T`
- **Tidak boleh** (secara aman): Membaca elemen sebagai tipe spesifik — kompiler hanya mengembalikan sebagai `Object`, karena tidak tahu tipe pasti di balik `?`

```java
// Menerima List<Integer>, List<Number>, atau List<Object>
public static void addIntegers(List<? super Integer> numbers) {
    numbers.add(1);   // aman DITULIS
    numbers.add(2);
    numbers.add(3);

    // Integer x = numbers.get(0);  // COMPILE ERROR — tidak bisa dibaca sbg Integer
    Object o = numbers.get(0);      // OK, hanya bisa dibaca sbg Object
}

List<Number> numList = new ArrayList<>();
addIntegers(numList);  // OK

List<Object> objList = new ArrayList<>();
addIntegers(objList);  // OK
```

---

#### Prinsip PECS *(Producer Extends, Consumer Super)*

**TL;DR:** *PECS adalah panduan memilih jenis wildcard berdasarkan peran koleksi.*

| Peran Koleksi | Wildcard yang Dipakai | Operasi yang Aman |
|---|---|---|
| **Producer** (menyediakan data → dibaca) | `<? extends T>` | Read ✓ / Write ✗ |
| **Consumer** (menerima data → ditulis) | `<? super T>` | Write ✓ / Read sebagai Object saja |
| Tidak peduli tipe | `<?>` | Read sebagai Object ✓ / Write ✗ |
| Perlu baca **dan** tulis | Tidak pakai wildcard — gunakan `<T>` biasa | Read ✓ / Write ✓ |

Ringkasan praktis:
- Hanya **dibaca** → `<? extends T>`
- Hanya **ditulis** → `<? super T>`
- Perlu keduanya → **jangan pakai wildcard**, gunakan type parameter `<T>` biasa
- Tidak peduli tipe sama sekali → `<?>`

---

### Komponen Kunci

- **Wildcard `?`** — merepresentasikan tipe yang belum diketahui (*unknown type*)
- **`<?>`** — unbounded wildcard; tipe apapun; hanya bisa dibaca sebagai `Object`
- **`<? extends T>`** — upper bounded wildcard; T atau subclass-nya; aman untuk dibaca
- **`<? super T>`** — lower bounded wildcard; T atau superclass-nya; aman untuk ditulis
- **PECS** — *Producer Extends, Consumer Super*; panduan memilih jenis wildcard
- **Invariance** — sifat Generic di Java: `List<Integer>` bukan subtype `List<Number>` meski `Integer extends Number`
- **`List<?>`** — ancestor dari semua `List<T>`; lebih fleksibel dari `List<Object>`

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- Mengapa wildcard dibutuhkan (invariance problem)
- Unbounded wildcard `<?>` — definisi, kapan digunakan, batasan read/write
- Upper bounded wildcard `<? extends T>` — definisi, kapan digunakan, batasan read/write
- Lower bounded wildcard `<? super T>` — definisi, kapan digunakan, batasan read/write
- Prinsip PECS
- Ringkasan: kapan pilih extends, super, atau tidak pakai wildcard

**Prioritas belajar:**

- 🔴 *Wajib dikuasai* — Ketiga jenis wildcard (sintaks & kapan digunakan), perbedaan `extends` vs `super` wildcard, apa yang boleh/tidak boleh dilakukan (read vs write) untuk setiap jenis wildcard, prinsip PECS
- 🟡 *Cukup paham konsep* — Mengapa `List<?>` berbeda dari `List<Object>`, kapan tidak perlu pakai wildcard sama sekali
