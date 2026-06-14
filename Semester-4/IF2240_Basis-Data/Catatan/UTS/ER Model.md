## Entity-Relationship Model

### Hubungan dengan CPMK

Materi **Database Design Entity-Relationship Model** terutama berkaitan dengan CPMK berikut:
- **Melakukan pemodelan data skala kecil-menengah dengan menggunakan model entity-relationship.**  
  Materi ini menjadi dasar utama untuk mengidentifikasi entitas, atribut, relasi, batasan kardinalitas, partisipasi, serta konstruksi ER diagram.
- **Membuat rancangan skema basis data relasional.**  
  ER model berperan sebagai rancangan konseptual sebelum model tersebut diturunkan menjadi skema relasional.
- **Menjelaskan peranan sistem basis data dalam pemenuhan kebutuhan akan informasi.**  
  ER model membantu menerjemahkan kebutuhan informasi dunia nyata ke dalam struktur data yang terorganisasi dan dapat diimplementasikan.

---

### Outline Konsep Fundamental

1. **Konsep Dasar ER Model**
   - Definisi ER model
   - Tujuan ER model
   - Peran ER diagram dalam desain basis data

2. **Entity dan Entity Set**
   - Entity
   - Entity set
   - Representasi entity melalui atribut

3. **Attribute**
   - Simple attribute
   - Composite attribute
   - Single-valued attribute
   - Multivalued attribute
   - Derived attribute

4. **Relationship dan Relationship Set**
   - Relationship
   - Relationship set
   - Binary relationship
   - Ternary atau n-ary relationship
   - Role dalam relationship

5. **Constraints dalam ER Model**
   - Mapping cardinality
   - Participation constraint
   - Key constraint

6. **Keys**
   - Superkey
   - Candidate key
   - Primary key
   - Discriminator pada weak entity

7. **Weak Entity Set**
   - Entitas lemah
   - Identifying strong entity
   - Identifying relationship
   - Total participation pada weak entity

8. **Design Issues dalam ER Model**
   - Entity set vs attribute
   - Entity set vs relationship set
   - Binary vs n-ary relationship
   - Penempatan atribut pada relationship
   - Redundansi dan desain buruk

9. **Specialization dan Generalization**
   - Specialization
   - Generalization
   - Inheritance
   - Disjoint dan overlapping constraint
   - Total dan partial completeness

10. **Aggregation**
    - Relasi terhadap relasi
    - Relationship set sebagai entitas abstrak

11. **Notasi ER Diagram**
    - Persegi panjang
    - Belah ketupat
    - Garis tunggal, ganda, dan berpanah
    - Persegi panjang ganda
    - Belah ketupat ganda
    - Garis putus-putus untuk discriminator
    - ISA triangle atau hollow arrow

---

### Penjelasan Materi

#### Konsep Dasar ER Model

**TL;DR:** *ER model adalah model konseptual untuk memetakan objek, hubungan, dan karakteristik dunia nyata ke dalam rancangan basis data.*

Entity-Relationship Model atau **ER model** merupakan kerangka kerja konseptual tingkat tinggi dalam desain basis data. Model ini digunakan untuk merepresentasikan makna dan interaksi dari suatu *enterprise* atau dunia nyata ke dalam bentuk yang dapat dijadikan dasar perancangan skema basis data.

ER model berfokus pada tiga konsep utama, yaitu **entity set**, **relationship set**, dan **attribute**. Dengan ketiga konsep tersebut, perancang basis data dapat memahami objek apa saja yang perlu disimpan, informasi apa yang melekat pada objek tersebut, serta bagaimana objek-objek itu saling berhubungan.

Secara praktis, ER model biasanya divisualisasikan dalam bentuk **ER diagram**. Diagram ini membantu perancang, pengguna, dan pengembang sistem untuk memiliki pemahaman bersama sebelum basis data diimplementasikan pada DBMS relasional.

---

#### Entity dan Entity Set

**TL;DR:** *Entity adalah objek nyata yang dapat dibedakan, sedangkan entity set adalah kumpulan entity sejenis.*

**Entity** adalah objek atau benda di dunia nyata yang dapat dibedakan dari objek lainnya. Contohnya adalah mahasiswa, dosen, mata kuliah, departemen, perusahaan, atau suatu kejadian tertentu. Suatu entity direpresentasikan melalui atribut-atribut yang menjelaskan karakteristiknya.

**Entity set** adalah kumpulan entity dengan tipe yang sama dan memiliki atribut yang sama. Misalnya, seluruh mahasiswa dalam suatu universitas dapat membentuk entity set `student`, sedangkan seluruh dosen dapat membentuk entity set `instructor`.

Dalam ER diagram:

- **Entity set** direpresentasikan dengan **persegi panjang**.
- Nama entity set biasanya ditulis sebagai kata benda.
- Setiap entity dalam entity set harus dapat dibedakan dari entity lainnya, umumnya melalui key.

---

#### Attribute

**TL;DR:** *Attribute adalah properti deskriptif yang menjelaskan entity atau relationship.*

**Attribute** adalah karakteristik atau properti yang dimiliki oleh entity dalam suatu entity set. Misalnya, entity `student` dapat memiliki atribut `student_id`, `name`, `tot_cred`, atau `dept_name`.

Jenis-jenis atribut dalam ER model:

- **Simple attribute**
  - Atribut yang tidak dapat dibagi lagi menjadi bagian yang lebih kecil.
  - Contoh: `student_id`, `salary`.

- **Composite attribute**
  - Atribut yang dapat dipecah menjadi beberapa sub-atribut.
  - Contoh: `name` dapat terdiri dari `first_name`, `middle_initial`, dan `last_name`.

- **Single-valued attribute**
  - Atribut yang hanya memiliki satu nilai untuk setiap entity.
  - Contoh: satu mahasiswa memiliki satu `student_id`.

- **Multivalued attribute**
  - Atribut yang dapat memiliki lebih dari satu nilai untuk satu entity.
  - Contoh: seorang dosen dapat memiliki lebih dari satu nomor telepon.

- **Derived attribute**
  - Atribut yang nilainya dapat diturunkan atau dihitung dari atribut lain.
  - Contoh: `age` dapat dihitung dari `date_of_birth`.

Dalam ER diagram, atribut biasanya ditulis di dalam kotak entity. Atribut yang menjadi **primary key** diberi garis bawah.

---

#### Relationship dan Relationship Set

**TL;DR:** *Relationship merepresentasikan asosiasi antar-entity, sedangkan relationship set adalah kumpulan relationship sejenis.*

**Relationship** adalah asosiasi yang terjadi antara beberapa entity. Misalnya, mahasiswa mengambil mata kuliah, dosen mengajar kelas, atau mahasiswa memiliki dosen pembimbing.

**Relationship set** adalah kumpulan relationship yang memiliki tipe yang sama. Jika `student` dan `course` dihubungkan oleh relationship `takes`, maka setiap pasangan mahasiswa dan mata kuliah yang diambil merupakan relationship individual dalam relationship set tersebut.

Jenis relationship berdasarkan jumlah entity set yang terlibat:

- **Binary relationship**
  - Melibatkan dua entity set.
  - Merupakan bentuk relationship yang paling umum.
  - Contoh: `student` mengambil `course`.

- **Ternary relationship**
  - Melibatkan tiga entity set.
  - Digunakan jika keterlibatan tiga entity dalam satu relasi tidak dapat direpresentasikan secara tepat oleh beberapa relasi biner.

- **n-ary relationship**
  - Melibatkan lebih dari dua entity set.
  - Dapat disederhanakan menjadi relasi biner dengan entitas buatan, tetapi tidak selalu mempertahankan constraint asli secara sempurna.

Dalam ER diagram, relationship set direpresentasikan dengan **belah ketupat**.

---

#### Mapping Cardinality

**TL;DR:** *Mapping cardinality menyatakan berapa banyak entity yang dapat berhubungan dengan entity lain melalui suatu relationship.*

Mapping cardinality atau kardinalitas pemetaan menjelaskan batas jumlah keterhubungan antar-entity dalam relationship set. Konsep ini penting karena menentukan struktur relasi ketika ER model diturunkan menjadi skema relasional.

Jenis mapping cardinality:

- **One-to-one**
  - Satu entity di A berhubungan paling banyak dengan satu entity di B.
  - Satu entity di B juga berhubungan paling banyak dengan satu entity di A.

- **One-to-many**
  - Satu entity di A dapat berhubungan dengan banyak entity di B.
  - Satu entity di B hanya dapat berhubungan dengan paling banyak satu entity di A.

- **Many-to-one**
  - Banyak entity di A dapat berhubungan dengan satu entity di B.
  - Setiap entity di A hanya berhubungan dengan paling banyak satu entity di B.

- **Many-to-many**
  - Banyak entity di A dapat berhubungan dengan banyak entity di B.
  - Contoh umum: mahasiswa mengambil banyak mata kuliah, dan satu mata kuliah diambil banyak mahasiswa.

Dalam notasi ER, garis berpanah menunjukkan sisi dengan batasan **one**, sedangkan garis tanpa panah menunjukkan sisi **many**.

---

#### Participation Constraint

**TL;DR:** *Participation constraint menyatakan apakah semua entity wajib ikut serta dalam relationship atau hanya sebagian.*

Participation constraint menjelaskan keterlibatan entity dalam suatu relationship set. Constraint ini penting untuk menunjukkan apakah keberadaan suatu entity harus selalu disertai hubungan tertentu.

Jenis participation constraint:

- **Total participation**
  - Setiap entity dalam entity set wajib berpartisipasi dalam setidaknya satu relationship.
  - Dalam ER diagram direpresentasikan dengan **garis ganda**.
  - Contoh: setiap entitas lemah harus berhubungan dengan entitas kuat yang mengidentifikasinya.

- **Partial participation**
  - Hanya sebagian entity yang berpartisipasi dalam relationship.
  - Dalam ER diagram direpresentasikan dengan **garis tunggal**.

---

#### Keys

**TL;DR:** *Key digunakan untuk mengidentifikasi entity secara unik dalam entity set.*

Key adalah atribut atau himpunan atribut yang digunakan untuk membedakan satu entity dari entity lainnya. Tanpa key, basis data tidak dapat menjamin identifikasi entity secara tepat.

Jenis key yang perlu dipahami:

- **Superkey**
  - Himpunan satu atau lebih atribut yang dapat mengidentifikasi entity secara unik.
  - Superkey dapat mengandung atribut berlebih.

- **Candidate key**
  - Superkey minimal.
  - Tidak ada atribut yang dapat dihapus tanpa menghilangkan kemampuan identifikasi unik.

- **Primary key**
  - Candidate key yang dipilih sebagai identitas utama entity.
  - Dalam ER diagram biasanya diberi garis bawah.

- **Discriminator**
  - Atribut pembeda pada weak entity set.
  - Tidak cukup menjadi primary key sendiri, tetapi dapat membedakan entitas lemah dalam konteks entitas kuatnya.

---

#### Weak Entity Set

**TL;DR:** *Weak entity set adalah entity set yang tidak dapat membentuk primary key sendiri dan bergantung pada strong entity.*

**Weak entity** adalah entitas yang tidak memiliki atribut cukup untuk membentuk primary key secara mandiri. Entitas ini bergantung secara eksistensial pada entitas lain yang disebut **identifying strong entity**.

Ciri-ciri weak entity set:

- Tidak memiliki primary key lengkap sendiri.
- Memiliki **discriminator** sebagai atribut pembeda.
- Bergantung pada **strong entity set**.
- Terhubung ke strong entity melalui **identifying relationship**.
- Biasanya memiliki **total participation** dalam identifying relationship.

Dalam ER diagram:

- Weak entity set direpresentasikan dengan **persegi panjang ganda**.
- Identifying relationship direpresentasikan dengan **belah ketupat ganda**.
- Discriminator diberi **garis bawah putus-putus**.

---

#### Design Issues dalam ER Model

**TL;DR:** *Desain ER yang baik harus menghindari redundansi, ambiguitas, dan representasi hubungan yang tidak tepat.*

Dalam perancangan ER model, desainer perlu membuat beberapa keputusan penting. Kesalahan desain dapat menyebabkan redundansi data, kesulitan query, atau struktur basis data yang tidak merepresentasikan dunia nyata secara tepat.

Isu desain utama:

- **Entity set vs attribute**
  - Suatu konsep dijadikan atribut jika hanya berupa properti sederhana.
  - Suatu konsep dijadikan entity set jika memiliki struktur sendiri, banyak nilai, atau informasi tambahan.
  - Contoh: nomor telepon dapat menjadi atribut sederhana, tetapi jika perlu menyimpan banyak nomor beserta lokasi atau tipe, lebih tepat dijadikan entity set.

- **Entity set vs relationship set**
  - Relationship set digunakan untuk merepresentasikan aksi atau asosiasi antar-entity.
  - Jika suatu konsep terutama menjelaskan hubungan antar-objek, sebaiknya dimodelkan sebagai relationship.

- **Binary vs n-ary relationship**
  - Relasi biner lebih sederhana dan umum digunakan.
  - Relasi n-ary digunakan ketika hubungan antarlebih dari dua entity tidak dapat direpresentasikan secara akurat oleh beberapa relasi biner.

- **Penempatan atribut relationship**
  - Atribut harus ditempatkan pada entity atau relationship sesuai maknanya.
  - Jika atribut menjelaskan hubungan, maka atribut tersebut sebaiknya diletakkan pada relationship.
  - Contoh: tanggal mulai pembimbingan lebih tepat menjadi atribut relationship `advisor`, bukan atribut murni milik `student`.

- **Menghindari desain buruk**
  - Hindari redundansi informasi.
  - Hindari merepresentasikan relationship sebagai atribut biasa jika hubungan tersebut penting secara konseptual.
  - Hindari desain yang membuat query menjadi tidak alami atau sulit.

---

#### Specialization dan Generalization

**TL;DR:** *Specialization dan generalization membentuk hierarki superclass-subclass dalam ER model.*

**Specialization** adalah proses desain *top-down*, yaitu memecah entity set umum menjadi beberapa entity set yang lebih khusus. Misalnya, entity `person` dapat dispesialisasi menjadi `student` dan `instructor`.

**Generalization** adalah proses desain *bottom-up*, yaitu menggabungkan beberapa entity set yang memiliki kesamaan atribut menjadi entity set yang lebih umum.

Konsep penting:

- **Superclass**
  - Entity set tingkat atas yang memiliki atribut umum.

- **Subclass**
  - Entity set tingkat bawah yang memiliki atribut khusus.

- **Inheritance**
  - Subclass mewarisi atribut dan partisipasi relationship dari superclass.

Constraint pada specialization:

- **Disjoint constraint**
  - Satu entity hanya boleh menjadi anggota satu subclass.

- **Overlapping constraint**
  - Satu entity boleh menjadi anggota lebih dari satu subclass.

- **Total completeness**
  - Setiap entity pada superclass harus menjadi anggota setidaknya satu subclass.

- **Partial completeness**
  - Tidak semua entity pada superclass harus menjadi anggota subclass.

Dalam ER diagram, specialization/generalization dapat digambarkan dengan segitiga bertuliskan **ISA** atau panah berongga yang menunjuk ke superclass.

---

#### Aggregation

**TL;DR:** *Aggregation memungkinkan suatu relationship diperlakukan sebagai entitas abstrak agar dapat berelasi dengan entity lain.*

Aggregation digunakan ketika suatu relationship perlu berhubungan dengan entity lain. Dalam ER model biasa, relationship tidak dapat langsung menjadi peserta relationship lain. Untuk mengatasi hal tersebut, relationship dapat diabstraksikan sebagai satu unit yang diperlakukan seperti entity.

Aggregation berguna untuk:

- Merepresentasikan relasi terhadap relasi.
- Menghindari redundansi desain.
- Menjaga makna konseptual ketika hubungan kompleks tidak cukup direpresentasikan dengan relationship biasa.

Dalam ER diagram, aggregation direpresentasikan dengan **kotak besar** yang membungkus entity set dan relationship set yang diagregasi.

---

#### Notasi ER Diagram

**TL;DR:** *Notasi ER diagram menyediakan simbol standar untuk menggambarkan entity, relationship, atribut, key, constraint, dan abstraksi.*

Notasi yang perlu diingat:

- **Persegi panjang**
  - Entity set.

- **Belah ketupat**
  - Relationship set.

- **Atribut bergaris bawah**
  - Primary key.

- **Garis berpanah**
  - Menunjukkan sisi dengan kardinalitas one.

- **Garis tanpa panah**
  - Menunjukkan sisi many.

- **Garis ganda**
  - Total participation.

- **Garis tunggal**
  - Partial participation.

- **Persegi panjang ganda**
  - Weak entity set.

- **Belah ketupat ganda**
  - Identifying relationship.

- **Garis bawah putus-putus**
  - Discriminator pada weak entity.

- **Segitiga ISA atau hollow arrow**
  - Specialization/generalization.

- **Kotak besar yang membungkus relationship**
  - Aggregation.

---

### Komponen Kunci

- **Entity**: Objek dunia nyata yang dapat dibedakan dari objek lain.
- **Entity set**: Kumpulan entity sejenis dengan atribut yang sama.
- **Attribute**: Properti deskriptif dari entity atau relationship.
- **Simple attribute**: Atribut yang tidak dapat dipecah lagi.
- **Composite attribute**: Atribut yang dapat dibagi menjadi sub-atribut.
- **Single-valued attribute**: Atribut dengan satu nilai untuk setiap entity.
- **Multivalued attribute**: Atribut yang dapat memiliki banyak nilai untuk satu entity.
- **Derived attribute**: Atribut yang nilainya dihitung dari atribut lain.
- **Relationship**: Asosiasi antar-entity.
- **Relationship set**: Kumpulan relationship sejenis.
- **Mapping cardinality**: Batas jumlah entity yang dapat berhubungan dalam relationship.
- **Participation constraint**: Ketentuan apakah entity wajib atau opsional ikut dalam relationship.
- **Superkey**: Himpunan atribut yang dapat mengidentifikasi entity secara unik.
- **Candidate key**: Superkey minimal.
- **Primary key**: Candidate key yang dipilih sebagai identitas utama.
- **Weak entity set**: Entity set yang tidak dapat memiliki primary key sendiri.
- **Discriminator**: Atribut pembeda pada weak entity.
- **Identifying relationship**: Relationship yang menghubungkan weak entity dengan strong entity.
- **Specialization**: Pemecahan entity umum menjadi subclass yang lebih khusus.
- **Generalization**: Penggabungan entity khusus menjadi superclass yang lebih umum.
- **Inheritance**: Pewarisan atribut dan relationship dari superclass ke subclass.
- **Aggregation**: Abstraksi relationship agar dapat diperlakukan sebagai entity.

---

### Checklist Pemahaman

**List sub-materi yang telah dibahas:**

- Konsep dasar ER model
- Entity dan entity set
- Attribute dan jenis-jenisnya
- Relationship dan relationship set
- Mapping cardinality
- Participation constraint
- Keys
- Weak entity set
- Design issues dalam ER model
- Specialization dan generalization
- Aggregation
- Notasi ER diagram

**Prioritas belajar:**

🔴 **Wajib dikuasai**

- Definisi dan tujuan ER model
- Entity, entity set, attribute, relationship, relationship set
- Jenis-jenis atribut
- Mapping cardinality: one-to-one, one-to-many, many-to-one, many-to-many
- Total dan partial participation
- Primary key, candidate key, superkey
- Weak entity set, discriminator, identifying relationship
- Notasi dasar ER diagram
- Perbedaan entity, attribute, dan relationship dalam desain

🟡 **Cukup paham konsep**

- Binary vs ternary atau n-ary relationship
- Penempatan atribut pada relationship
- Design issues dan contoh desain buruk
- Specialization/generalization
- Disjoint vs overlapping constraint
- Total vs partial completeness
- Aggregation

✅ **Sudah dikuasai**

- Introduction to Database
- Data Model
- Relational Algebra, Relational Calculus
- SQL
