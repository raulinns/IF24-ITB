Sebuah sistem operasi (*operating system*/OS) adalah perangkat lunak yang mengelola perangkat keras komputer. Sistem operasi juga menyediakan basis untuk program dan bekerja sebagai penghubung antara perangkat keras komputer dengan pengguna komputer. 

Sebuah sistem komputer dapat dibagi menjadi empat komponen: perangkat keras, sistem operasi, program aplikasi, dan pengguna. 

>[!img-caption] ![[Pasted image 20251016145221.png]]

## Perspektif Pengguna
Dalam perspektif pengguna, sistem operasi didesain untuk memastikan pengguna dapat memanfaatkan sumber daya yang dimiliki komputer secara eksklusif. Tujuannya untuk memaksimalkan pekerjaan yang dilakukan oleh pengguna. Dalam perspektif pengguna, sistem operasi didesain untuk kemudahan penggunaan, dengan tetap memerhatikan kinerja dan keamanan, tetapi tidak memandang pemanfaatan sumber daya (bagaimana pemanfaatan *hardware* dan *software* tersebar).

## Perspektif Sistem
Dari sudut pandang komputer, OS merupakan program yang paling sering berhubungan dengan perangkat keras. Dalam konteks ini, kita memandang OS sebagai *resource allocator* atau pengelola sumber daya. Sebuah sistem komputer memiliki sumber daya yang mungkin digunakan dalam menyelesaikan sebuah masalah, misal CPU, ruang memori, ruang penyimpanan, perangkat I/O, dan lain-lain. OS dalam konteks ini menjadi pengelola dari sumber daya ini.

Dengan banyaknya sumber daya ini yang mungkin membuat konflik, OS harus dapat memutuskan bagaimana mengalokasikan *request* dari pengguna untuk masing-masing program dan pengguna agar sistem komputer dapat berjalan secara efisien dan adil.

# Sistem Operasi
Pada dasarnya, perangkat keras sulit untuk digunakan, sehingga dibutuhkan sebuah jembatan untuk menggunakannya, yaitu sistem operasi. Secara umum, kita tidak memiliki definisi yang sepenuhnya memadai tentang sistem operasi. Intinya, OS adalah sebuah perangkat lunak yang mengelola *hardware*, serta mengontrol program dan menjebatani antara pengguna dengan *hardware* komputer. Salah satu definisi yang diterima dari sebuah OS adalah sastu program yang berjalan di komputer sepanjang waktu, yang biasanya disebut kernel (bukan definisi formal, lebih ke definisi kernel). Dalam sistem operasi terdapat komponen-komponen, seperti berikut:
1. Kernel, program yang **selalu berjalan** (_always-running_) di komputer.
2. Program sistem (*system programs*), program yang sudah ada secara *default* di OS, tetapi bukan kernel.
3. Program aplikasi (*application programs*), program selain yang ada di OS (yang dibuat atau di-*install* oleh user).

Secara umum (yang saya simpulkan), OS memiliki tujuan sebagai berikut:
1. Menyediakan lingkungan di mana pengguna dapat **mengeksekusi program** dengan cara yang nyaman dan efisien (*ease of use*)
2. Bertindak sebagai **pengalokasi sumber daya** (_resource allocator_)
3. Mengelola dan mengoordinasikan sumber daya _hardware_ (*resource utilization*)
4. Berfungsi sebagai **program kontrol** (_control program_), memastikan eksekusi program pengguna dan sistem berjalan dengan baik

# Aspek Utama Desain OS
1. **Virtualisasi (Virtualization)**: Proses membuat setiap aplikasi seolah-olah memiliki perangkat kerasnya sendiri secara eksklusif. OS “menipu” aplikasi agar berpikir ia memiliki CPU, memori, dan disk pribadi, padahal sebenarnya semua itu dibagi-pakai dengan aplikasi lain. Ini adalah inti dari abstraksi.
2. **Konkurensi (Concurrency)**: Kemampuan OS untuk menangani banyak kejadian (event) atau tugas yang seolah-olah berjalan pada saat yang bersamaan. OS harus bisa mengelola interaksi dan koordinasi antar tugas-tugas ini agar tidak terjadi konflik atau kekacauan data.
3. **Persistensi (Persistence)**: Kemampuan untuk menyimpan informasi (data) secara permanen, bahkan setelah komputer dimatikan. OS menyediakan abstraksi (seperti sistem file) agar aplikasi dapat menyimpan dan mengakses data tanpa perlu tahu detail teknis bagaimana data ditulis ke disk fisik.

# Organisasi Sistem Komputer
Sistem komputer modern secara umum terdrii dari satu atau lebih CPU dan beberapa *device controllers* yan terhubung dalam sebuah *common bus* yang menyediakan akses untuk beberapa komponen dan memori bersama.

>[!img-caption] ![[Pasted image 20251019042409.png]]

Tiap *device controller* bertanggungjawab atas suatu tipe perangkat spesifik (lihat pada gambar di atas yang memiliki kotak berwarna abu-abu, kecuali CPU). Setiap *controller* memiliki penyimpanan *buffer* lokal dan sejumlah *register* khusus. *Controller* bertanggung jawab untuk memindahkan data di antara perangkat periferal (*peripheral devices*) yang dikontrolnya dengan penyimpanan *buffer* lokal. 

Biasanya sebuah OS memiliki *device driver* untuk tiap *device controller*. *Device driver* ini memahami *device controller* dan menyediakan antarmuka yang seragam untuk sisa sistem operasi. CPU dan *driver controller* dapat bekerja secara paralel dan saling berkompetisi untuk memori. Untuk memastikan akses yang teratur terhadap memori bersama, *memory controller* menyinkronkan akses ke memori. 