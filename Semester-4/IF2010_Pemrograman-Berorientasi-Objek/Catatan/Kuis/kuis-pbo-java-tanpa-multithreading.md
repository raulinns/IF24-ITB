# Kuis IF2010 Pemrograman Berbasis Objek Java

Semester: II 2025/2026  
Durasi: 60 menit  
Total poin: 100  
Jumlah soal: 50 soal pilihan ganda, masing-masing 2 poin

## Soal

1. Dalam Java, relasi paling tepat antara class dan object adalah ...

   A. Class menyimpan state runtime, object hanya menyimpan method statik  
   B. Class adalah definisi type, object adalah instansiasi yang memiliki state dan behavior  
   C. Class hanya dipakai untuk inheritance, object hanya untuk polymorphism  
   D. Class dan object selalu identik setelah dikompilasi

2. Prinsip Single Responsibility Principle paling dilanggar oleh desain berikut ketika satu class ...

   A. memiliki satu constructor dan banyak getter  
   B. menangani validasi input, akses database, dan format laporan sekaligus  
   C. memiliki banyak method private untuk memecah algoritma internal  
   D. mengimplementasikan satu interface

3. Open/Closed Principle paling tepat berarti class sebaiknya ...

   A. selalu final agar tidak bisa dimodifikasi  
   B. terbuka untuk ekstensi, tetapi tertutup untuk modifikasi langsung  
   C. hanya menggunakan public method agar mudah diperluas  
   D. tidak boleh memakai inheritance sama sekali

4. Pelanggaran Liskov Substitution Principle terjadi jika ...

   A. subclass dapat digunakan di tempat superclass tanpa mengubah kebenaran program  
   B. subclass memperkuat invariant sehingga semua method superclass tetap valid  
   C. subclass melempar exception untuk method yang secara logis valid pada superclass  
   D. superclass memiliki abstract method yang wajib diimplementasikan

5. Interface Segregation Principle menyarankan agar ...

   A. semua behavior digabung dalam satu interface besar  
   B. class tidak dipaksa mengimplementasikan method yang tidak dibutuhkannya  
   C. semua interface harus memiliki constructor  
   D. interface hanya boleh dipakai oleh class dalam package yang sama

6. Dependency Inversion Principle paling tepat diterapkan dengan ...

   A. modul tingkat tinggi bergantung pada abstraksi, bukan implementasi konkret  
   B. semua class dibuat static agar tidak bergantung pada object  
   C. subclass selalu memanggil constructor superclass secara manual  
   D. semua dependency dibuat public agar mudah diakses

7. Manakah pernyataan yang benar tentang manajemen memori Java?

   A. Java mewajibkan destructor eksplisit seperti C++  
   B. Java memiliki copy constructor bawaan untuk semua class  
   C. Object yang tidak lagi reachable dapat dibersihkan oleh Garbage Collector  
   D. Programmer wajib memanggil delete untuk setiap object

8. Apa efek utama modifier `private`?

   A. Member hanya dapat diakses dari class yang sama  
   B. Member hanya dapat diakses dari subclass di package lain  
   C. Member dapat diakses semua class  
   D. Member hanya dapat diakses class dalam package yang sama

9. Perhatikan kode berikut.

   ```java
   class Box {
       int value;
   }
   static void ubah(Box b) {
       b = new Box();
       b.value = 9;
   }
   ```

   Jika `ubah(x)` dipanggil, apa asumsi yang salah bila berharap `x` ikut menunjuk object baru?

   A. Java melakukan pass by reference murni  
   B. Java melakukan dynamic binding pada field  
   C. Java menyalin seluruh object saat parameter dikirim  
   D. Java menghapus object lama segera setelah method selesai

10. Untuk parameter object di Java, pernyataan paling tepat adalah ...

    A. object dikirim by reference sehingga parameter dapat diganti dari dalam method  
    B. referensi object dikirim by value, sehingga state object dapat diubah tetapi referensi caller tidak otomatis berubah  
    C. object selalu disalin seperti copy constructor C++  
    D. parameter object selalu immutable

11. Fitur C++ yang tidak tersedia langsung di Java adalah ...

    A. method overriding  
    B. interface  
    C. operator overloading untuk class buatan sendiri  
    D. dynamic dispatch

12. Java tidak mendukung multiple inheritance untuk class karena ...

    A. semua class Java harus final  
    B. Java menghindari ambiguitas pewarisan implementasi, dan memakai interface untuk kontrak majemuk  
    C. Java tidak memiliki superclass  
    D. Java tidak memiliki polymorphism

13. Perhatikan kode berikut.

    ```java
    class A {}
    class B {}
    class C extends A, B {
    }
    ```

    Apa masalah utama desain/kode tersebut dalam Java?

    A. Java tidak mengizinkan lebih dari satu constructor  
    B. Java tidak mengizinkan multiple inheritance antar-class  
    C. Java tidak mengizinkan class kosong  
    D. Java tidak mengizinkan subclass dari class non-abstract

14. Mengapa `friend` dari C++ tidak memiliki padanan langsung di Java?

    A. Java tidak memiliki konsep encapsulation  
    B. Java mengatur akses lewat modifier seperti `private`, `protected`, `public`, dan package-private  
    C. Java selalu membuka semua field untuk package lain  
    D. Java hanya memiliki global function

15. Tentang `String` di Java, pernyataan yang benar adalah ...

    A. `String` adalah primitive type  
    B. `String` mutable sehingga method `replace` mengubah object yang sama  
    C. `String` adalah class, dan nilainya immutable  
    D. `String` harus selalu dibuat dengan `new`

16. Perhatikan kode berikut.

    ```java
    String s = "IF";
    s.concat("2010");
    System.out.println(s);
    ```

    Output yang dihasilkan adalah ...

    A. IF  
    B. IF2010  
    C. 2010  
    D. error karena `concat` tidak valid

17. Untuk manipulasi teks berulang dalam loop, pilihan yang paling tepat biasanya ...

    A. `StringBuilder`, karena mutable dan mendukung method chaining  
    B. `String`, karena selalu mengubah object lama  
    C. array `char` tanpa alokasi  
    D. `Object`, karena semua string adalah object

18. Perhatikan kode berikut.

    ```java
    StringBuilder sb = new StringBuilder("PBO");
    sb.append(" Java")
      .replace(0, 3, "IF2010");
    System.out.println(sb);
    ```

    Konsep yang paling tampak dari kode tersebut adalah ...

    A. operator overloading  
    B. fluent interface / method chaining pada object mutable  
    C. pass by reference murni  
    D. multiple inheritance

19. Perbedaan utama array Java dibanding array C adalah ...

    A. array Java adalah object dan dialokasikan eksplisit dengan `new`  
    B. array Java selalu bertipe `String`  
    C. array Java tidak memiliki panjang  
    D. array Java selalu disimpan di stack dan tidak perlu inisialisasi

20. Perhatikan kode berikut.

    ```java
    int[] nilai;
    nilai[0] = 80;
    ```

    Apa masalah utama kode tersebut?

    A. array belum dialokasikan sebagai object dengan `new`  
    B. `int` tidak boleh disimpan di array  
    C. indeks array Java dimulai dari 1  
    D. array Java harus selalu generic

21. Interface di Java terutama digunakan untuk ...

    A. menyimpan state object yang diwariskan ke semua implementor  
    B. menyatakan kontrak behavior yang wajib dipenuhi class implementor  
    C. menggantikan semua class konkret  
    D. membuat constructor bersama lintas class

22. Manakah yang BUKAN karakteristik interface klasik di Java?

    A. dapat diimplementasikan oleh banyak class tidak berhubungan  
    B. dapat memuat abstract method sebagai kontrak  
    C. dapat memiliki constructor untuk menginisialisasi state  
    D. dapat menjadi solusi untuk kebutuhan multiple behavior

23. Perhatikan kode berikut.

    ```java
    interface Printable {
        void print();
    }
    class Invoice implements Printable {
        public void print() {
            System.out.println("invoice");
        }
    }
    ```

    Relasi desain yang paling tepat adalah ...

    A. `Invoice` mewarisi state dari `Printable`  
    B. `Invoice` memenuhi kontrak behavior `Printable`  
    C. `Printable` adalah superclass konkret dari `Invoice`  
    D. `Printable` membuat object `Invoice` otomatis

24. Kapan abstract class lebih cocok daripada interface?

    A. Ketika class turunannya berada dalam hierarki yang berhubungan dan dapat berbagi implementasi umum  
    B. Ketika ingin class tidak punya superclass sama sekali  
    C. Ketika ingin menghindari semua method abstract  
    D. Ketika ingin satu class meng-extend banyak abstract class

25. Generics di Java terutama membantu ...

    A. membuat class baru per tipe seperti template C++  
    B. memperketat pengecekan tipe saat compile-time  
    C. menghapus kebutuhan inheritance  
    D. mengubah semua primitive menjadi object otomatis

26. Perhatikan kode berikut.

    ```java
    List raw = new ArrayList();
    raw.add("PBO");
    Integer x = (Integer) raw.get(0);
    ```

    Masalah utama yang ingin dicegah oleh generics adalah ...

    A. `NullPointerException` saat compile-time  
    B. `ClassCastException` saat runtime akibat tipe koleksi tidak aman  
    C. garbage collection pada list  
    D. immutable object dalam list

27. Arti `<U extends Number>` pada deklarasi generic adalah ...

    A. `U` harus persis `Number`, tidak boleh subclass  
    B. `U` dapat berupa `Number` atau turunannya  
    C. `U` harus superclass dari `Number`  
    D. `U` akan selalu dihapus menjadi `String`

28. Type erasure pada Java berarti ...

    A. JVM membuat class bytecode terpisah untuk setiap tipe generic  
    B. informasi tipe generic dibuang saat kompilasi dan diganti dengan `Object` atau bound tertentu  
    C. generic hanya berlaku saat runtime  
    D. generic mengubah semua tipe menjadi primitive

29. Perhatikan kode berikut.

    ```java
    class Box<T> {
        T value;
    }
    Box<String> a = new Box<>();
    Box<Integer> b = new Box<>();
    ```

    Manakah pernyataan paling tepat?

    A. Java membuat dua class bytecode berbeda untuk `String` dan `Integer`  
    B. Pada runtime, detail tipe generic terkena type erasure  
    C. `Box<T>` tidak boleh menyimpan field  
    D. `Box<Integer>` adalah subclass dari `Box<String>`

30. Mengapa `List<Integer>` tidak dapat langsung dianggap sebagai subtype dari `List<Number>`?

    A. karena `Integer` bukan turunan `Number`  
    B. karena generic Java invariant; relasi subtype elemen tidak otomatis menjadi relasi subtype list  
    C. karena `List` hanya menerima `String`  
    D. karena `Number` adalah interface

31. Wildcard `List<?>` paling tepat dibaca sebagai ...

    A. list yang pasti berisi `Object`  
    B. list of unknown, dapat menerima list dengan tipe elemen berbeda  
    C. list yang boleh ditambah elemen tipe apa pun  
    D. list yang tidak bisa dibaca sama sekali

32. Prinsip umum bounded wildcard `? extends T` adalah ...

    A. cocok ketika koleksi terutama dibaca sebagai sumber data  
    B. cocok ketika koleksi terutama ditulis dengan superclass apa pun  
    C. sama persis dengan `? super T`  
    D. hanya berlaku untuk primitive type

33. Prinsip umum bounded wildcard `? super T` adalah ...

    A. cocok untuk menambahkan object bertipe `T` atau turunannya ke koleksi tujuan  
    B. membuat isi list pasti bertipe `T` saat dibaca  
    C. mencegah semua operasi tulis  
    D. hanya dipakai pada interface

34. Perhatikan kode berikut.

    ```java
    static double total(List<? extends Number> data) {
        double sum = 0;
        for (Number n : data) {
            sum += n.doubleValue();
        }
        return sum;
    }
    ```

    Asumsi desain method tersebut adalah ...

    A. method hanya perlu membaca elemen sebagai `Number`  
    B. method perlu menambahkan `Number` baru ke `data`  
    C. method hanya menerima `List<Number>`  
    D. method mengubah tipe generic saat runtime

35. Reflection API memungkinkan program Java untuk ...

    A. mengubah bytecode JVM menjadi C++  
    B. menginspeksi class, method, field, atau interface pada runtime  
    C. menonaktifkan garbage collector  
    D. membuat operator overloading

36. Perhatikan kode berikut.

    ```java
    Class<?> c = Class.forName(namaClass);
    Object obj = c.getDeclaredConstructor().newInstance();
    for (Class<?> itf : c.getInterfaces()) {
        System.out.println(itf.getName());
    }
    ```

    Kegunaan desain yang paling sesuai adalah ...

    A. sistem plugin yang memuat class ekstensi secara dinamis  
    B. compile-time template specialization  
    C. multiple inheritance class konkret  
    D. penghapusan checked exception

37. Risiko utama penggunaan reflection yang berlebihan adalah ...

    A. semua object menjadi immutable  
    B. banyak kesalahan bergeser dari compile-time ke runtime dan kode lebih sulit dipahami  
    C. Java berhenti memakai dynamic binding  
    D. semua method otomatis menjadi static

38. Tiga cara umum "passing code" di Java yang relevan adalah ...

    A. pointer function, macro, dan destructor  
    B. interface/object, nama via reflection, dan lambda expression  
    C. friend class, template, dan pointer  
    D. goto, union, dan operator overloading

39. `Map` dalam Java Collections paling tepat digunakan untuk ...

    A. menyimpan pasangan key-value tanpa duplicate keys  
    B. menyimpan elemen berurutan yang selalu boleh duplicate key  
    C. menggantikan semua array primitive  
    D. mengatur pewarisan class konkret

40. `ArrayList` adalah implementasi dari ...

    A. `Map`  
    B. `List`  
    C. `Throwable`  
    D. `ClassLoader`

41. Perhatikan kode berikut.

    ```java
    List<String> names = List.of("Ana", "Budi", "Ali");
    names.stream()
         .filter(s -> s.startsWith("A"))
         .map(String::toUpperCase)
         .forEach(System.out::println);
    ```

    Konsep utama yang ditunjukkan kode tersebut adalah ...

    A. pemrosesan koleksi secara fluent dengan Stream API dan lambda  
    B. manual memory management  
    C. operator overloading  
    D. checked exception hierarchy

42. Operasi `reduce` pada Stream API umumnya digunakan untuk ...

    A. mengubah setiap elemen menjadi elemen lain satu per satu  
    B. menyaring elemen berdasarkan predicate  
    C. menggabungkan banyak elemen menjadi satu hasil agregat  
    D. menutup resource secara otomatis

43. Dalam Java, exceptional event direpresentasikan sebagai ...

    A. kode angka global seperti `errno`  
    B. object exception yang dilempar ke runtime system  
    C. perintah preprocessor  
    D. pointer null yang wajib dikembalikan

44. Peran blok `finally` adalah ...

    A. hanya berjalan jika tidak ada exception  
    B. dijamin dieksekusi setelah `try/catch` untuk cleanup, kecuali kondisi ekstrem seperti terminasi JVM  
    C. menggantikan semua `catch`  
    D. hanya menangani `RuntimeException`

45. Try-with-resources digunakan untuk ...

    A. membuat resource tidak perlu mengimplementasikan interface apa pun  
    B. otomatis memanggil `close()` pada object `AutoCloseable`  
    C. menangkap semua `Error`  
    D. menghapus kebutuhan checked exception

46. Manakah pasangan yang paling tepat?

    A. `Error` checked dan selalu recoverable  
    B. `RuntimeException` unchecked, sedangkan `Exception` standar umumnya checked  
    C. semua `Throwable` wajib ditangkap  
    D. `AssertionError` adalah checked exception

47. Keyword `assert` paling tepat digunakan untuk ...

    A. validasi parameter public method dari user  
    B. memeriksa asumsi internal/invariant saat debugging  
    C. menggantikan semua unit test  
    D. menangani kegagalan file I/O

48. Mengapa assertion tidak boleh memiliki side effect penting?

    A. karena assertion dapat dinonaktifkan, sehingga perubahan state di dalamnya bisa hilang  
    B. karena assertion selalu dijalankan dua kali  
    C. karena assertion hanya boleh dipakai di constructor  
    D. karena assertion mengubah checked exception menjadi unchecked

49. Perhatikan kode berikut.

    ```java
    public void setUmur(int umur) {
        assert umur >= 0;
        this.umur = umur;
    }
    ```

    Apa masalah utama desain ini jika `setUmur` adalah public method?

    A. parameter public method sebaiknya divalidasi dengan exception, bukan bergantung pada assertion  
    B. `assert` hanya boleh dipakai untuk membandingkan object dengan `equals`  
    C. field `umur` tidak boleh diubah dalam method public  
    D. `assert` otomatis mengubah `umur` menjadi immutable

50. Perhatikan kode berikut.

    ```java
    try {
        bacaFile();
    } catch (Exception e) {
        System.out.println("gagal");
    }
    ```

    Apa masalah desain yang paling mungkin muncul dari pola ini?

    A. `catch (Exception e)` terlalu umum sehingga detail kegagalan spesifik mudah tertutup  
    B. `try` hanya boleh dipakai bersama try-with-resources  
    C. checked exception tidak boleh ditangkap  
    D. method `bacaFile` harus selalu mengembalikan `boolean`

## Kunci Jawaban

1. B
2. B
3. B
4. C
5. B
6. A
7. C
8. A
9. A
10. B
11. C
12. B
13. B
14. B
15. C
16. A
17. A
18. B
19. A
20. A
21. B
22. C
23. B
24. A
25. B
26. B
27. B
28. B
29. B
30. B
31. B
32. A
33. A
34. A
35. B
36. A
37. B
38. B
39. A
40. B
41. A
42. C
43. B
44. B
45. B
46. B
47. B
48. A
49. A
50. A
