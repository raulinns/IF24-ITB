Manajemen Sumber Daya adalah peran kunci dari sistem operasi (OS), di mana OS bertindak sebagai manajer untuk berbagai sumber daya yang dimiliki sistem komputer. Sumber daya yang dimaksud meliputi CPU, ruang memori, ruang penyimpanan file, dan perangkat I/O

# Process Management
Proses adalah program yang sedang dieksekusi. Sebuah proses memerlukan sumber daya tertentu, termasuk waktu CPU, memori, _file_, dan perangkat I/O, untuk menyelesaikan tugasnya

- Membuat dan menghapus proses (baik proses pengguna maupun proses sistem).
- Menjadwalkan proses dan _thread_ pada CPU.
- Menangguhkan (_suspending_) dan melanjutkan (_resuming_) proses.
- Menyediakan mekanisme untuk sinkronisasi proses.
- Menyediakan mekanisme untuk komunikasi antarproses.

Penting untuk dicatat bahwa program itu sendiri adalah entitas pasif (_passive entity_), seperti _file_ yang disimpan di disk, sedangkan proses adalah entitas aktif (_active entity_) yang dieksekusi.

# Memory Management
Memori utama adalah komponen sentral dalam sistem komputer modern. Memori utama adalah _array_ besar dari _byte_ yang merupakan tempat penyimpanan data yang dapat diakses dengan cepat oleh CPU dan perangkat I/O.

Untuk meningkatkan utilisasi CPU dan kecepatan respons sistem, komputer _general-purpose_ harus menyimpan **beberapa program di dalam memori** secara bersamaan, yang menciptakan kebutuhan akan manajemen memori.

- Melacak bagian memori mana yang sedang digunakan dan proses mana yang menggunakannya.
- Mengalokasikan dan mendealokasikan ruang memori sesuai kebutuhan.
- Memutuskan proses mana (atau bagian dari proses) dan data mana yang harus dipindahkan ke dalam dan ke luar memori (_swapping_)

# File-System Management
Sistem operasi menyediakan pandangan logis yang seragam tentang penyimpanan informasi. OS mengabstraksikan properti fisik perangkat penyimpanan menjadi unit penyimpanan logis, yaitu _file_. OS memetakan _file_ ini ke media fisik dan mengaksesnya melalui perangkat penyimpanan.

• Membuat dan menghapus _file_.
• Membuat dan menghapus direktori untuk mengorganisir _file_.
• Mendukung primitif untuk memanipulasi _file_ dan direktori.
• Memetakan _file_ ke penyimpanan massal (_mass storage_).
• Mencadangkan (_backing up_) _file_ di media penyimpanan yang stabil (_stable storage_).

# Mass-Storage Management
Penyimpanan sekunder (HDD dan NVM) berfungsi untuk mendukung memori utama (yang bersifat *volatile*).

Karena penyimpanan sekunder digunakan secara luas, manajemennya harus efisien, sebab keseluruhan kecepatan operasi komputer dapat bergantung pada kecepatan subsistem penyimpanan sekunder dan algoritmanya.
* *Mounting* dan *unmounting* volume.
* Manajemen ruang bebas (*free-space management*).
* Alokasi penyimpanan.
* Penjadwalan disk (*disk scheduling*).
* Partisi.
* Proteksi.
# Cache Management
*Caching* adalah prinsip penting di mana informasi (data atau instruksi) disalin dari sistem penyimpanan yang lebih lambat ke sistem penyimpanan yang lebih cepat (*cache*) secara sementara.

*Cache* memiliki ukuran terbatas, sehingga **manajemen cache** adalah masalah desain yang penting. Pemilihan ukuran *cache* yang cermat dan kebijakan penggantian (*replacement policy*) dapat menghasilkan peningkatan kinerja yang besar.

Transfer informasi antara *cache* dan CPU/register biasanya merupakan fungsi *hardware* tanpa intervensi OS, tetapi transfer data antara disk dan memori utama biasanya dikendalikan oleh OS.

# I/O System Management
Salah satu tujuan OS adalah menyembunyikan keunikan perangkat *hardware* tertentu dari pengguna. Subsistem I/O kernel menangani keunikan perangkat ini, dan subsistem ini terdiri dari beberapa komponen:

* Komponen manajemen memori yang mencakup *buffering*, *caching*, dan *spooling*.
* Antarmuka *device driver* umum.
* *Driver* untuk perangkat *hardware* tertentu.

Hanya *device driver* yang mengetahui keunikan perangkat yang ditanganinya. OS menggunakan *interrupt handler* dan *device driver* untuk membangun subsistem I/O yang efisien.