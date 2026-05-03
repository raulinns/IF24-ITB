# Java Collection
### Outline Konsep Fundamental

- Java Collections Framework — definisi & tiga elemen utama
- Hierarki interface
  - Hierarki `Collection`: `List`, `Set`, `Queue`, `Deque`
  - Hierarki `Map` (terpisah dari `Collection`)
- Interface `List`
  - Karakteristik
  - Implementasi: `ArrayList`, `LinkedList`, `Vector`
  - Array biasa vs `ArrayList`
- Interface `Set`
  - Karakteristik (no duplicate)
  - Implementasi: `HashSet`, `LinkedHashSet`, `TreeSet`
- Interface `Queue`
  - Karakteristik (FIFO)
  - Implementasi: `LinkedList` sebagai Queue, `PriorityQueue`
- Interface `Deque`
  - Karakteristik (double-ended)
  - Penggunaan sebagai Stack
- Interface `Map`
  - Karakteristik (key-value, no duplicate key)
  - Implementasi: `HashMap`, `LinkedHashMap`, `TreeMap`
- Operasi umum Collection (`add`, `remove`, `contains`, `size`, `isEmpty`)
- Iterasi: `for-each` vs `iterator()`
- `Collections` utility class (`sort()`, `shuffle()`)
- `Comparable` (sekilas)

---

### Penjelasan Materi

#### Java Collections Framework

**TL;DR:** *Collections Framework adalah arsitektur terpadu untuk merepresentasikan dan memanipulasi kumpulan objek.*

Java Collections Framework terdiri dari tiga elemen utama:

- **Interfaces** — kontrak abstrak yang mendefinisikan tipe koleksi (`List`, `Set`, `Map`, dst.)
- **Implementations** — kelas konkret yang mengimplementasikan interface tersebut (`ArrayList`, `HashSet`, `HashMap`, dst.)
- **Algorithms** — method utilitas untuk operasi pada koleksi (pencarian, pengurutan, pengacakan)

Hierarki besar dalam framework ini terbagi dua:

- **Hierarki `Collection`** — akar untuk koleksi sekuensial; di bawahnya: `List`, `Set`, `Queue`, `Deque`
- **Hierarki `Map`** — terpisah dari `Collection`; menangani struktur data *key-value*

---

#### Interface `List`

**TL;DR:** *List adalah koleksi berurutan yang mengizinkan duplikat dan akses berbasis indeks.*

Karakteristik:
- Mempertahankan *insertion order* (urutan elemen sesuai urutan dimasukkan)
- Mengizinkan elemen **duplikat**
- Mendukung akses posisional berbasis **indeks numerik**

Implementasi:

| Implementasi | Struktur Data Internal | Catatan |
|---|---|---|
| `ArrayList` | *Resizable array* (array dinamis) | Baik untuk akses acak (`get(i)`) |
| `LinkedList` | *Linked list* | Baik untuk penambahan/penghapusan cepat |
| `Vector` | *Resizable array* (mirip ArrayList) | *Thread-safe*, umumnya jarang dipakai |

```java
List<String> list = new ArrayList<String>();
list.add("Satu");
list.add("Dua");
list.add("Satu");           // duplikat diizinkan

String el = list.get(0);    // akses via indeks → "Satu"
System.out.println(list);   // [Satu, Dua, Satu]
```

#### Array Biasa vs `ArrayList`

**TL;DR:** *Array ukurannya tetap dan bisa menyimpan primitif; ArrayList ukurannya dinamis tetapi hanya menyimpan objek.*

| Aspek        | Array biasa                         | `ArrayList`                        |
| ------------ | ----------------------------------- | ---------------------------------- |
| Ukuran       | **Tetap** (tidak bisa diubah)       | **Dinamis** (otomatis berkembang)  |
| Tipe data    | Primitif & objek                    | Objek saja (gunakan wrapper class) |
| Resize       | Harus buat array baru + copy manual | Otomatis                           |
| Akses elemen | `arr[i]`                            | `list.get(i)`                      |

---

#### Interface `Set`

**TL;DR:** *Set adalah koleksi yang tidak mengizinkan elemen duplikat.*

Karakteristik:
- **Tidak ada elemen duplikat** — elemen yang sama (berdasarkan `equals()`) hanya akan ada satu
- Tidak menjamin urutan tertentu (kecuali implementasi tertentu)

Implementasi:

| Implementasi    | Struktur Data Internal       | Urutan                           |
| --------------- | ---------------------------- | -------------------------------- |
| `HashSet`       | *Hash table*                 | Tidak berurutan                  |
| `LinkedHashSet` | *Hash table* + *Linked list* | Mempertahankan *insertion order* |
| `TreeSet`       | *Tree* (Red-Black Tree)      | Terurut otomatis (*sorted*)      |

```java
Set<String> s = new HashSet<String>();
String[] args = {"Apple", "Banana", "Apple"};

for (String a : args) {
    s.add(a);   // "Apple" kedua diabaikan — tidak ada duplikat
}

System.out.println(s.size() + " distinct words: " + s);
// Output: 2 distinct words: [Banana, Apple]  (urutan tidak dijamin di HashSet)
```

---

#### Interface `Queue`

**TL;DR:** *Queue adalah koleksi FIFO — elemen pertama masuk adalah yang pertama keluar.*

Karakteristik:
- Prinsip **FIFO** (*First-In, First-Out*)
- Digunakan untuk menahan elemen sebelum diproses

Implementasi:
- **`LinkedList`** — implementasi Queue paling umum
- **`PriorityQueue`** — elemen dikeluarkan berdasarkan prioritas (natural ordering atau `Comparator`)

```java
Queue<Integer> queue = new LinkedList<Integer>();
queue.add(10);
queue.add(9);
queue.add(5);

while (!queue.isEmpty()) {
    System.out.println(queue.remove());  // FIFO: 10, 9, 5
}
```

---

#### Interface `Deque`

**TL;DR:** *Deque (Double-Ended Queue) mendukung penambahan dan penghapusan dari kedua ujung — bisa dipakai sebagai Stack.*

Karakteristik:
- Mendukung operasi di **head** (depan) maupun **tail** (belakang)
- Dapat difungsikan sebagai Stack (LIFO) menggunakan `push()` dan `pop()`

```java
Deque<String> deque = new LinkedList<String>();
deque.add("Element 1");         // masuk dari tail
deque.addFirst("Element 2");    // masuk dari head
deque.addLast("Element 3");     // masuk dari tail
deque.push("Element 4");        // masuk dari head (seperti Stack)

System.out.println("Pop: " + deque.pop());  // keluarkan dari head → "Element 4"

deque.removeFirst();   // hapus dari head
deque.removeLast();    // hapus dari tail
```

---

#### Interface `Map`

**TL;DR:** *Map memetakan key ke value — setiap key unik, satu key hanya bisa memiliki satu value.*

Karakteristik:
- Struktur **key-value** (pasangan kunci-nilai)
- **Tidak ada key duplikat** — setiap key terikat pada maksimal satu value
- `Map` **tidak** merupakan turunan dari `Collection` — hierarkinya terpisah

Implementasi:

| Implementasi | Struktur Data Internal | Urutan Key |
|---|---|---|
| `HashMap` | *Hash table* | Tidak berurutan |
| `LinkedHashMap` | *Hash table* + *Linked list* | Mempertahankan *insertion order* |
| `TreeMap` | *Tree* | Terurut otomatis (*sorted* by key) |

```java
Map<String, Integer> m = new HashMap<String, Integer>();
m.put("KunciA", 100);
m.put("KunciB", 200);

Integer val = m.get("KunciA");   // → 100
System.out.println(m);           // {KunciA=100, KunciB=200}
```

---

#### Operasi Umum Collection

**TL;DR:** *Semua Collection (List, Set, Queue) mewarisi operasi dasar dari interface `Collection`.*

| Method | Fungsi |
|---|---|
| `add(E e)` | Menambah elemen |
| `remove(Object o)` | Menghapus elemen |
| `contains(Object o)` | Mengecek apakah elemen ada |
| `size()` | Jumlah elemen |
| `isEmpty()` | Cek apakah koleksi kosong |
| `iterator()` | Mengembalikan objek `Iterator<E>` |

---

#### Iterasi: `for-each` vs `iterator()`

**TL;DR:** *`for-each` lebih simpel; `iterator()` lebih powerful tapi `for-each` tidak bisa memodifikasi elemen asli.*

`for-each`:
```java
for (String a : list) {
    System.out.println(a);   // hanya baca
}
```

Keterbatasan `for-each`:
- Menggunakan variabel **salinan** — tidak bisa memodifikasi elemen asli
- Selalu iterasi dari awal hingga akhir
- Tidak memberikan informasi **indeks**

`iterator()`:
```java
Iterator<String> it = list.iterator();
while (it.hasNext()) {
    String el = it.next();
    System.out.println(el);
}
```

Untuk `List`, tersedia juga `listIterator()` yang memanfaatkan sifat sekuensial list.

---

#### `Collections` Utility Class

**TL;DR:** *`Collections` (bukan `Collection`) adalah kelas utilitas berisi method statis untuk operasi pada koleksi.*

```java
List<Integer> nums = new ArrayList<>(Arrays.asList(3, 1, 4, 1, 5, 9));

Collections.sort(nums);                    // urutkan → [1, 1, 3, 4, 5, 9]
Collections.shuffle(nums, new Random());   // acak urutan elemen
```

> Metode lain seperti `min()`, `max()`, `frequency()` ada di Java API standar tetapi tidak dibahas dalam dokumen sumber.

---

#### `Comparable` (Sekilas)

**TL;DR:** *`Comparable` adalah interface yang memungkinkan kelas tidak berhubungan tetap bisa dibandingkan dan diurutkan.*

`Comparable` adalah contoh interface yang diimplementasikan oleh kelas-kelas yang sama sekali tidak berhubungan secara hierarki — seperti `Integer` dan `String` — untuk memberikan kemampuan perbandingan (*natural ordering*). Dipakai oleh `TreeSet`, `TreeMap`, dan `Collections.sort()`.

---

### Komponen Kunci

- **Collections Framework** — arsitektur terpadu: Interfaces + Implementations + Algorithms
- **`Collection`** — interface akar untuk `List`, `Set`, `Queue`, `Deque`
- **`Map`** — hierarki terpisah dari `Collection`; menyimpan pasangan key-value
- **`List`** — berurutan, boleh duplikat, akses via indeks
- **`Set`** — tidak boleh duplikat
- **`Queue`** — FIFO
- **`Deque`** — double-ended; bisa sebagai Stack (LIFO)
- **`ArrayList`** — `List` berbasis *resizable array*; ukuran dinamis
- **`LinkedList`** — `List` & `Queue` berbasis *linked list*
- **`HashSet`** — `Set` berbasis *hash table*; tidak berurutan
- **`TreeSet`** — `Set` berbasis *tree*; terurut otomatis
- **`HashMap`** — `Map` berbasis *hash table*; tidak berurutan
- **`TreeMap`** — `Map` berbasis *tree*; key terurut otomatis
- **`Collections`** — kelas utilitas statis (`sort()`, `shuffle()`, dst.)
- **`Comparable`** — interface untuk *natural ordering*; diimplementasikan `Integer`, `String`, dst.
- **`iterator()`** — method yang mengembalikan objek `Iterator<E>` untuk iterasi manual
- **`for-each`** — sintaks iterasi ringkas; tidak bisa memodifikasi elemen asli

---

### Checklist Pemahaman

**Sub-materi yang dibahas:**
- Java Collections Framework (definisi, tiga elemen, hierarki)
- Interface `List` — karakteristik, `ArrayList` vs `LinkedList` vs `Vector`
- Array biasa vs `ArrayList`
- Interface `Set` — karakteristik, `HashSet` vs `LinkedHashSet` vs `TreeSet`
- Interface `Queue` — karakteristik FIFO, `LinkedList` & `PriorityQueue`
- Interface `Deque` — double-ended, sebagai Stack
- Interface `Map` — karakteristik, `HashMap` vs `LinkedHashMap` vs `TreeMap`
- Operasi umum (`add`, `remove`, `contains`, `size`, `isEmpty`)
- Iterasi: `for-each` vs `iterator()`
- `Collections` utility class (`sort()`, `shuffle()`)
- `Comparable` (sekilas)

**Prioritas belajar:**

- 🔴 *Wajib dikuasai* — Hierarki Collections Framework (Collection vs Map), karakteristik setiap interface (List/Set/Queue/Map), perbedaan implementasi dalam satu interface (`HashSet` vs `TreeSet` vs `LinkedHashSet`; `HashMap` vs `TreeMap`), Array vs ArrayList, sintaks penggunaan `List`/`Set`/`Map`/`Queue`, operasi dasar Collection
- 🟡 *Cukup paham konsep* — `Deque` dan penggunaannya sebagai Stack, `for-each` vs `iterator()` (keterbatasan for-each), `Collections.sort()` dan `shuffle()`, `Comparable` sebagai interface lintas hierarki, `PriorityQueue`
