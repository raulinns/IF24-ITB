> Kebutuhan (*requirements*) dan pernyataan kebutuhan (*requirements statement*) adalah hal yang sama

Kebutuhan dapat berbentuk kalimat yang abstrak/umum (*high level*) atau kalimat yang rinci. Pernyataan kebutuhan ini memiliki dua manfaat:
1. Dasar untuk membuka/mengikuti tender
2. Dasar untuk pembuatan kontrak pekerjaan

Kebutuhan dapat didefinisikan dalam dua tingkat abstraksi yang berbeda, yaitu:
1. Kebutuhan pengguna (*user requirements*). Kebutuhan ini merupakan kebutuhan yang keluar dari pengguna atau *stakeholder*. Bahasa yang digunakan adalah bahasa sehari-hari (natural). Kebutuhan ini berisi harapan apa yang dapat diberikan sistem, juga kadang batasan-batasan operasional. 
2. Kebutuhan sistem (*system requirements*). Kebutuhan ini berisi deskripsi rinci fungsi, layanan, dan batasan operasional sistem. Bahasa yang digunakan adalah bahasa yang teknis. Kebutuhan ini mendefinisikan apa yang harus diimplementasikan, hingga kemungkinan menjadi bagian dari kontrak antara *client* dan kontraktor. Biasanya berupa dokumentasi kebutuhan sistem. 

Terdapat beberapa *rule of thumbs* terkait dengan *requirement*:
1. Tidak semua elemen harus didigitalisasikan (perlu memerhatikan waktu pengembangan, biaya pengembangan, dan lingkup masalahnya).
2. Berbagai elemen mungkin masih tidak lengkap, tidak jelas, ambigu, dan saling konflik.
3. Penjelasan *user* cenderung bersifat umum, *developer*/analis yang harus menerjemahkan keinginan menjadi bahasa yang mudah dimengerti oleh *programmer*.

# Karakteristik Pengguna
Pengguna memiliki berbagai karakteristik, sehingga pernyataan kebutuhan menjadi:
1. Terlalu umum, tidak rinci, tidak sederhana
2. Terlalu rinci, tidak menggambarkan sistem secara keseluruhan
3. Terjadi konflik antara bagian yang berbeda dalam satu sistem
4. Tidak konsisten
5. Mungkin tidak realistis

Dari karakteristik pengguna, kita dapat membagi tipe-tipe *user* menjadi beberapa kategori pekerjaan:
1. *Operational User*. Biasanya memiliki pandangan lokal, menjalankan fungsi sistem, dan memiliki pandangan fisik terhadap sistem.
2. *Supervisory User*. Mungkin memiliki pandangan lokal, familier dengan operasional, didorong oleh pertimbangan anggaran, dan sering bertindak sebagai perantara pengguna dan manajemen tingkat atas.
3. *Executive User*. Memiliki pandangan global, memberikan inisiatif untuk proyek, memiliki kepentingan strategis,  dan belum tentu memiliki pengalaman operasional langsung.

# Sifat Kebutuhan
Spesifikasi Kebutuhan Perangkat Lunak (SKPL) harus membedakan kedua sifat kebutuhan:
1. Kebutuhan Fungsional (*Functional Requirement*/KF)
2. Kebutuhan Nonfungsional (*Nonfunctional Requirement*/KNF)

## Kebutuhan Fungsional
Kebutuhan fungsional berisi tentang pernyataan kebutuhan tentang layanan yaang harus diberikan oleh sistem, bagaimana sistem memberikan respon terhadap input, dan (kadang) apa yang tidak perlu dilakukan sistem. 

## Kebutuhan Nonfungsional
Kebutuhan NF kadang-kadang bisa lebih kritis dibanding kebutuhan fungsional. Kebutuhan nonfungsional berisi tentang pernyataan tentang batasan (*constraint*) dari layanan yang ditawarkan oleh sistem. KNF kadang bisa berakibat pada sistem secara keseluruhan (tidak hanya satu komponen tunggal). Satu kebutuhan NF bisa menghasilkan beberapa kebutuhan fungsional. 

Secara umum, KNF dapat dikategorikan sebagai berikut:
1. Kebutuhan produk. Kebutuhan ini menjelaskan tentang perilaku dari *software* atau pembatasan perilaku. Contoh: besar memori yang dibutuhkan, kebutuhan *security*, kebutuhan *usability*.
2. Kebutuhan organisasional. Diturunkan dari aturan dalam lingkungan pengguna dan pengembang.
3. Kebutuhan eksternal. Kebutuhan ini berasal dari luar sistem dan juga di luar proses pengembangan. Contoh: memerhatikan aturan/hukum yang berlaku, seperti undang-undang.
>[!img-caption] ![[Pasted image 20251022012101.png]]

KNF harus semaksimal mungkin terkuantifikasi agar dapat diuji/*testable*. Untuk mengukur kebutuhan NF dapat menggunakan:
1. Kecepatan, misal jumlah transaksi/detik, waktu respon pengguna/*event*
2. Ukuran, misal MiB, GB
3. Kemudahan pakai, misal *training time*, jumlah layar bantu/*help*
4. Keandalan (*reliability*), misal rata-rata waktu kegagalan, *availability*
5. Robustness, misal waktu *restart* sesudah *failure*, presentasi kegagalan
6. Portability, misal jumlah target sistem

# Kebutuhan Berdasarkan Domain
Setiap domain memiliki kebutuhan yang berbeda-beda. Kebutuhan domain berisi penjelasan karakteristik dan fitur sistem yang memberikan gambaran tentang domain itu. Kebutuhan berdasarkan domain ini bisa menjadi kebutuhan fungsional baru, batasan terhadap kebutuhan yang sudah ada, atau mendefinisikan komputasi yang spesifik. 

# Kelengkapan Kebutuhan
Suatu kebutuhan harus lengkap dan konsisten, dalam artian kebutuhan harus mencangkup semua deskripsi yang diperlukan dan tidak ada konflik atau kontradiksi. Dalam prakteknya, pasti kebutuhan tidak lengkap dan konsisten, tetapi kita harus harus dapat berusaha membuatnya.

