Sebuah sistem operasi modern adalah sistem yang besar dan kompleks, sehingga harus direkayasa dengan hati-hati agar berfungsi dengan baik dan mudah dimodifikasi. Pendekatan umum untuk mencapai hal ini adalah dengan mempartisi tugas menjadi komponen-komponen atau modul-modul kecil. Setiap modul harus merupakan bagian yang terdefinisi dengan baik, dengan antarmuka dan fungsi yang ditentukan secara cermat.

>[!img-caption] ![[Pasted image 20251020015452.png]]

# Monolithic Structure
Struktur ini adalah yang paling sederhana untuk mengorganisir sistem operasi. Semua fungsionalitas _kernel_ ditempatkan dalam **satu file biner tunggal yang statis** dan berjalan dalam **satu ruang alamat tunggal** (_single address space_). 
- \+ Efisiensi dan Performa Tinggi
- \- Sulit dimodifikasi, tightly coupled

>[!img-caption] ![[Pasted image 20251020020327.png]]

# Layered Approach
Pendekatan ini berupaya menciptakan sistem yang terkopel secara longgar (_loosely coupled_). Sistem operasi dipecah menjadi sejumlah lapisan (*layers*). Lapisan paling bawah (lapisan 0) adalah *hardware*. Lapisan tertinggi (lapisan $N$) adalah *antarmuka pengguna*. Setiap lapisan diimplementasikan hanya dengan menggunakan fungsi-fungsi (operasi) yang disediakan oleh lapisan di bawahnya
- \+ Sederhana untuk dikonstruksi dan di-debug.
- \- Sulit menentukan lapisan yang tepat.
- \- Performa dapat buruk karena layer traversal.

>[!img-caption] ![[Pasted image 20251020020354.png]]

# Microkernels
Metode ini memodularisasi _kernel_ dengan mengurangi fungsinya menjadi seminimal mungkin.
Komponen-komponen non-esensial dikeluarkan dari _kernel_ dan diimplementasikan sebagai program tingkat pengguna (*user-level programs*) yang berada di ruang alamat terpisah. _Microkernel_ biasanya menyediakan manajemen proses dan memori minimal, ditambah dengan fasilitas komunikasi. Fungsi utama _microkernel_ adalah menyediakan komunikasi antar client dan berbagai layanan yang berjalan di ruang pengguna, umumnya melalui pengiriman pesan (*message passing*).
- \+ Lebih mudah dikembangkan/dimodifikasi tanpa recompile kernel
- \- Performa paling buruk karena overhead message passing dan context switch

> [!img-caption] ![[Pasted image 20251020020421.png]]

# Modules
Ini dianggap sebagai metodologi _current_ terbaik untuk desain sistem operasi. Kernel memiliki serangkaian komponen inti dan dapat menautkan (_link in_) layanan tambahan melalui modul (*loadable kernel modules* atau LKM), baik saat _boot time_ atau saat _run time_.

# Hybrid
Hampir semua OS modern adalah sistem hybrid yang menggabungkan beberapa pendekatan.  
- **macOS & iOS**: Menggunakan arsitektur hybrid yang disebut Darwin. Intinya adalah kernel XNU yang menggabungkan microkernel Mach (untuk IPC, penjadwalan) dengan komponen dari kernel monolitik BSD (untuk networking, sistem file) dan mendukung modul yang dapat dimuat (_kernel extensions_).
- **Android**: Didasarkan pada kernel Linux (monolitik dengan modul) yang telah dimodifikasi. Namun, aplikasi berjalan di atas _runtime environment_ (ART/Dalvik VM) dan serangkaian pustaka C/C++ yang luas, membuatnya terlihat seperti sistem berlapis.
- **Windows**: Sebagian besar monolitik, tetapi menggunakan beberapa konsep dari microkernel untuk subsistem yang menjalankan aplikasi dari lingkungan OS lain (seperti WSL, *Windows Subsystem for Linux*).