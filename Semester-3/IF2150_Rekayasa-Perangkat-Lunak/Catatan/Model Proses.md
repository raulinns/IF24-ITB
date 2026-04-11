# Software Development Life Cycle
SDLC (*Software Development Life Cycle*) adalah kerangka kerja yang mendefinisikan urutan aktivitas inti yang diperlukan untuk mengembangkan perangkat lunak. Kerangka kerja ini mencakup fase-fase utama yang dilakukan secara berurutan atau berulang, tergantung pada model proses yang digunakan
Aktivitas utama dalam kerangka kerja proses generik (SDLC) meliputi:
1. Komunikasi (*Communication*): Melibatkan komunikasi antara analis sistem dengan pengguna (_user_) dan analis sistem dengan pemrogram (_programmer_).
2. Perencanaan (*Planning***): Perencanaan proyek awal dan studi kelayakan, yang berfokus pada biaya (_cost_), waktu (_time_), dan sumber daya manusia (_human resources_).
3. Pemodelan (*Modeling*): Mencakup pendekatan terstruktur (_structured approach_) atau berorientasi objek (_object oriented approach_). Fase ini juga termasuk pengumpulan kebutuhan (_Requirements Gathering and Analysis_) dan perancangan sistem (_Design_).
4. Konstruksi (*Construction*): Melibatkan penulisan kode (_Development/Implementation_) dan pengujian (_Testing_).
5. Deployment: Penyerahan perangkat lunak kepada pelanggan (_Software delivery to customer_) atau merilisnya ke lingkungan produksi untuk pengguna.
6. Pemeliharaan (*Maintenance*): Dukungan berkelanjutan, perbaikan _bug_, dan peningkatan setelah _deployment_.

# Umbrella Activity
Umbrella Activity adalah aktivitas yang dilakukan secara terus menerus (_throughout_) selama proses perangkat lunak berlangsung, bukan hanya pada fase tertentu:
- Pelacakan dan Kontrol Proyek Perangkat Lunak: Memungkinkan tim menilai kemajuan terhadap rencana proyek dan mengambil tindakan yang diperlukan untuk menjaga jadwal.
- Manajemen Risiko (*Risk Management*): Menilai risiko yang dapat memengaruhi hasil proyek atau kualitas produk.
- Penjaminan Kualitas Perangkat Lunak (*SQA*): Mendefinisikan dan melakukan kegiatan yang diperlukan untuk memastikan kualitas perangkat lunak.
- Tinjauan Teknis (*Technical Reviews*): Menilai produk kerja rekayasa perangkat lunak untuk menemukan dan menghilangkan kesalahan sebelum kesalahan tersebut menyebar ke aktivitas berikutnya.
- Pengukuran (*Measurement*): Mendefinisikan dan mengumpulkan pengukuran proses, proyek, dan produk.
- Manajemen Konfigurasi Perangkat Lunak (*Software Configuration Management*): Mengelola efek perubahan di sepanjang proses perangkat lunak.
- Manajemen Penggunaan Kembali (*Reusability Management*): Mendefinisikan kriteria untuk penggunaan kembali produk kerja.
- Persiapan dan Produksi Produk Kerja: Mencakup pembuatan model, dokumen, formulir, dan daftar.

Proses rekayasa perangkat lunak harus bersifat *agile* dan *adaptable*). Proses dapat menyesuaikan dengan:
- Masalah (_to the problem_).
- Proyek (_to the project_).
- Tim (_to the team_).
- Budaya organisasi (_to the organizational culture_). Proses yang diadopsi untuk satu proyek mungkin sangat berbeda dari proses yang diadopsi untuk proyek lain.

Esensi dari RPL dapat diringkas menjadi:
- Memahami masalah (_Understand the problem_) melalui komunikasi dan analisis.
- Merencanakan solusi (_Plan a solution_) melalui pemodelan dan perancangan per7angkat lunak.
- Melaksanakan rencana (_Carry out the plan_) melalui pembuatan kode (_code generation_).
- Memeriksa hasil untuk akurasi (_Examine the result for accuracy_) melalui pengujian dan penjaminan kualitas (_quality assurance_).

Praktik RPL juga harus memenuhi prinsip:
1. The reason it all exist
2. Keep it simple stupid (KISS)
3. Maintain the vision
4. We produce, others will consume 
5. Open to the future
6. Plan for Reuse!
7. Think First!

# Process Flow
*Process flow* merupakan pengaturan urutan dan waktu aktivitas. *Process flow* dapat berjenis sebagai berikut.
1. *Linear Process Flow*
>[!img-caption] ![[Pasted image 20251021214352.png]]

2. *Iterative Process Flow*
>[!img-caption] ![[Pasted image 20251021214546.png]]

3. *Evolutionary Process Flow*
>[!img-caption] ![[Pasted image 20251021214607.png]]

4. *Parallel Process Flow*
>[!img-caption] ![[Pasted image 20251021214631.png]]

# Process Model
_Process Model_ (Model Proses) adalah  struktur atau kerangka kerja untuk mengorganisasi semua pekerjaan yang terlibat dalam pengembangan, pengoperasian, dan pemeliharaan perangkat lunak. Model proses RPL dikelompokkan menjadi tiga kategori utama: Model Proses Preskriptif, Model Proses Khusus, dan *Unified Process*.

# Prescriptive Process Model
Model ini seringkali memiliki urutan yang terstruktur dan terdefinisi (preskriptif):
## Linier Process Model
### Waterfall Model
>[!img-caption] ![[Pasted image 20251021215609.png]]
>

Model ini memiliki fase-fase yang teridentifikasi secara terpisah, yaitu analisis dan definisi kebutuhan (_Requirements analysis and definition_), desain sistem dan perangkat lunak (_System and software design_), implementasi dan pengujian unit (_Implementation and unit testing_), integrasi dan pengujian sistem (_Integration and system testing_), serta operasi dan pemeliharaan (_Operation and maintenance_). Kelemahan utama model ini adalah **kesulitannya mengakomodasi perubahan** setelah proses berjalan, karena secara prinsip, suatu fase harus selesai sebelum pindah ke fase berikutnya

### The V Model
>[!img-caption] ![[Pasted image 20251021215759.png]]

## Incremental Process Model
>[!img-caption] ![[Pasted image 20251021215848.png]]


## Evolutionary Process Model
### Prototyping Paradigm
>[!img-caption] ![[Pasted image 20251021215931.png]]

### Spiral Mode
>[!img-caption] ![[Pasted image 20251021220010.png]]

## Parallel Process Model
### Concurrent Model
>[!img-caption] ![[Pasted image 20251021220340.png]]

# Specialized Process Models

Model-model ini diterapkan untuk lingkungan dan kebutuhan yang sangat spesifik:
1. *Component-Based Development:* Model ini fokus pada pengembangan aplikasi dengan menyusunnya dari komponen perangkat lunak yang sudah dikemas sebelumnya (_prepackaged software components_).
2. *The Formal Methods Model*: Model ini mencakup serangkaian aktivitas yang menghasilkan spesifikasi matematis formal dari perangkat lunak. Pendekatan ini relevan bagi pengembang yang harus membangun perangkat lunak yang kritis keselamatan (*safety-critical software*), seperti perangkat avionik pesawat terbang dan perangkat medis, karena adanya potensi kerugian ekonomi yang parah jika terjadi kesalahan.
3. *Aspect-Oriented Software Development* (AOSD): Paradigma RPL yang relatif baru yang menyediakan proses dan pendekatan metodologis untuk mendefinisikan, menspesifikasikan, merancang, dan membangun _aspects_—mekanisme di luar _subroutines_ dan _inheritance_ untuk melokalisasi ekspresi dari _crosscutting concern_.

# Unified Process
*Unified Process* (UP) adalah model yang bersifat "didorong oleh _use case_, berpusat pada arsitektur, iteratif, dan inkremental". UP terkait erat dengan _Unified Modeling Language_ (UML) yang merupakan notasi kuat untuk pemodelan sistem berorientasi objek.

Model proses ini mengatur _process flow_ dari kerangka kerja inti (Komunikasi, Perencanaan, Pemodelan, Konstruksi, _Deployment_) sehubungan dengan urutan dan waktu, yang kemudian menghasilkan berbagai jenis model (linear, iteratif, evolusioner, atau paralel)

>[!img-caption] ![[Pasted image 20251021221648.png]]

# System Engineering
*Computer-based system* adalah suatu kumpulan elemen yang diatur untuk mencapai sebuah tujuan dengan memproses informasi.Tujuannya bisa mendukung fungsi bisnis tertentu atau mengembangkan produk untuk menghasilkan pendapatan. Sistem berbasis komputer terdiri dari berbagai elemen, termasuk: Perangkat Lunak (*Software*), Perangkat Keras (*Hardware*), Manusia (_People_), Data, Dokumentasi, dan Prosedur.

Proses rekayasa sistem (*system engineering*) bergerak dari pandangan tingkat tinggi hingga detail implementasi:
   - World View: Terdiri dari sekumpulan domain.
   - Domain View: Terdiri dari elemen spesifik (misalnya, elemen sistem).
   - Element View: Diimplementasikan dengan menentukan komponen teknis.
   - Detail View.

# Product Engineering
Rekayasa produk (*product engineering*)  bertujuan untuk menerjemahkan keinginan pelanggan menjadi produk yang berfungsi.Rekayasa produk memiliki hierarki sebagai berikut:
1. _Requirement engineering_ (World View).
2. _Component engineering_ (Domain View).
3. _Analysis and Design modeling_ (Element View).
4. _Construction and Integration_ (Detail View)

# Context Model
Fungsi utamanya adalah untuk **menunjukkan apa yang berada di luar batas sistem** (_system boundaries_). Model ini juga menunjukkan hubungan antara sistem yang sedang dikembangkan dengan sistem-sistem lain yang ada di lingkungannya. Dalam hierarki _system engineering_, model konteks termasuk dalam tingkatan "world *view*".

_System Boundaries_ atau Batas Sistem adalah garis yang ditetapkan untuk mendefinisikan apa yang ada di dalam sistem dan apa yang ada di luar sistem. Batas sistem menunjukkan sistem-sistem lain yang digunakan oleh, atau bergantung pada, sistem yang sedang dikembangkan. Penentuan posisi batas sistem ini sangat penting karena memiliki dampak besar terhadap kebutuhan sistem (_system requirements_).

*Context model* hanya menunjukkan sistem lain yang ada di sebuah lingkungan, bukan cara sistem itu digunakan. *UML activity diagram* dapat digunakan untuk menunjukkan proses model bisnis. 

# Activity Diagram
Diagram aktivitas menjelaskan tentang urutan proses prosedural, bisnis proses, dan urutan kerja (*work flow*).Dalam hierarki _system engineering_, _Activity Diagram_ dikategorikan sebagai _World View_.  Activity diagram ini mirip dengan *flow chart*, tetapi *flow chart* tidak mengenal perilaku paralel/konkuren

>[!img-caption] ![[Pasted image 20251022001543.png]]
>![[Pasted image 20251022001634.png]]

Selanjutnya, *activity diagram* akan dibahas lebih lanjut di materi [[Kebutuhan Perangkat Lunak]]
