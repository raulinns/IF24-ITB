Rekayasa Kebutuhan adalah proses yang sangat bervariasi, bergantung pada domain aplikasi, _stakeholder_ yang terlibat, dan organisasi yang mengembangkan kebutuhan. RE adalah aktivitas yang **iteratif** dan proses-prosesnya saling terkait. Untuk membentuk proses rekayasa kebutuhan dibutuhkan empat aktivitas utama sebagai berikut:
1. _Requirements Elicitation_ (Penggalian)
2. _Requirements Analysis/Specification_ (Analisis/Spesifikasi)
3. _Requirements Validation_ (Validasi)
4. _Requirements Management_ (Manajemen)

# Requirements Elicitation
*Software engineer* bekerja sama dengan para *stakeholder* sistem untuk mempelajari:
- domain aplikasi,
- layanan yang harus disediakan sistem,
- kinerja sistem yang dibutuhkan,
- kendala perangkat keras, sistem lain, dll.

Proses *Requirements Elicitation* terdiri dari:
**a.** Requirements Discovery Aktivitas berinteraksi dengan _stakeholder_ untuk menggali dan menemukan kebutuhan mereka, termasuk kebutuhan domain.
**b.** Requirements Classification & Organisation Mengelompokkan kebutuhan terkait dan mengaturnya ke dalam klaster yang koheren.
**c.** Prioritisation and Negotiation Memprioritaskan kebutuhan dan menyelesaikan konflik antar kebutuhan yang mungkin ada.
**d.** Requirements Specification Mendokumentasikan kebutuhan untuk dilanjutkan ke iterasi spiral berikutnya.

**Masalah Umum dalam Penggalian Kebutuhan:** Menggali kebutuhan sering kali menemui tantangan:
- _Stakeholder_ mungkin tidak tahu apa yang sebenarnya mereka butuhkan.
- Mereka mengungkapkan kebutuhan dengan cara mereka sendiri (bukan bahasa teknis).
- _Stakeholder_ yang berbeda dapat memiliki kebutuhan yang saling bertentangan.
- Faktor organisasi dan politik dapat memengaruhi kebutuhan sistem.
- Kebutuhan cenderung berubah selama proses analisis (misalnya, munculnya _stakeholder_ baru atau perubahan lingkungan bisnis).

**Teknik Penggalian (Elicitation Techniques):** Beberapa teknik yang umum digunakan untuk _Requirements discovery_ dan _classification_ adalah:
- **Interviewing (Wawancara):** Bisa formal (_closed interviews_ dengan daftar pertanyaan) atau informal (_open interviews_ untuk eksplorasi isu).
- **Stories dan Scenarios:** Contoh nyata bagaimana sistem dapat digunakan untuk tugas tertentu. Skenario adalah bentuk terstruktur dari _user story_.
- **Use Cases:** Mengidentifikasi aktor yang terlibat dan interaksinya. _Use case_ dapat dilengkapi dengan deskripsi tekstual atau model grafis (seperti _sequence diagram_ atau _state diagram_ UML).

Itu adalah ringkasan yang sangat komprehensif, dan Anda telah menguasai bagian awal dengan sangat baik!

Berikut adalah rangkuman lengkap dari Rekayasa Kebutuhan (_Requirements Engineering_ - RE), yang mencakup definisi dan keempat aktivitas utamanya.

---

### Rangkuman Lengkap: Rekayasa Kebutuhan (_Requirements Engineering_)

Rekayasa Kebutuhan (RE) adalah proses yang **iteratif** dan proses-proses di dalamnya saling terkait. RE sangat bervariasi, bergantung pada domain aplikasi, _stakeholder_, dan organisasi pengembang. Tujuan utamanya adalah menjembatani harapan pengguna dengan spesifikasi sistem yang akan dikembangkan.

### Empat Aktivitas Utama dalam Rekayasa Kebutuhan

Secara umum, terdapat empat aktivitas utama yang harus dilakukan dalam proses RE:

|No.|Aktivitas|Tujuan Utama|
|:--|:--|:--|
|1|**Requirements Elicitation (Penggalian)**|Bekerja sama dengan _stakeholder_ untuk menggali dan menemukan kebutuhan.|
|2|**Requirements Analysis/Specification (Analisis/Spesifikasi)**|Menulis kebutuhan pengguna dan sistem ke dalam dokumen formal (SKPL).|
|3|**Requirements Validation (Validasi)**|Membuktikan bahwa kebutuhan yang telah didefinisikan benar-benar sesuai dengan keinginan pelanggan.|
|4|**Requirements Management (Manajemen)**|Mengelola perubahan kebutuhan yang tak terhindarkan selama pengembangan sistem.|

---

### 1. Requirements Elicitation (Penggalian)

Pada tahap ini, _software engineer_ bekerja sama dengan _stakeholder_ untuk mempelajari layanan yang dibutuhkan sistem, kinerja, dan kendala (seperti perangkat keras atau sistem lain).

**Masalah Umum:** Sering terjadi masalah karena _stakeholder_ mungkin tidak tahu persis apa yang mereka butuhkan, mengungkapkan kebutuhan dengan cara mereka sendiri, atau bahkan memiliki kebutuhan yang saling bertentangan. Kebutuhan juga cenderung berubah selama proses analisis.

**Teknik Penggalian:** Meliputi _Interviewing_ (wawancara formal atau informal), _Stories_ dan _scenarios_ (contoh nyata penggunaan sistem), dan _Use cases_.

### 2. Requirements Analysis/Specification (Analisis/Spesifikasi)
Ini adalah proses formal menulis kebutuhan pengguna (_user requirements_) dan kebutuhan sistem (_system requirements_) ke dalam dokumen SKPL (_Software Requirements Specification_).

**Prinsip Kunci:** Kebutuhan harus menyatakan **APA** yang seharusnya dilakukan sistem, sedangkan Desain menjelaskan **BAGAIMANA** sistem melakukannya.

**Kualitas SKPL yang Baik:** Dokumen SKPL adalah komitmen atau kontrak. Dokumen yang baik harus memenuhi 8 kriteria utama:

1. **Jelas/Lengkap** (_Clear, Complete, Concise_): Mencakup semua aspek dan tidak terduplikasi.
2. **Konsisten** (_Consistent_): Tidak ada kebutuhan yang saling konflik.
3. **Benar** (_Correct_): Akurat dan presisi.
4. **Mudah Diubah** (_Modifiable_): Memiliki struktur yang rapi agar perubahan mudah diakomodasi.
5. **Terurut** (_Ranked_): Diurutkan berdasarkan prioritas atau kepentingan untuk efisiensi pengembangan.
6. **Dapat Diuji** (_Testable_): Dapat dibuktikan atau dinilai secara kuantitatif. Pernyataan subjektif harus dikuantifikasi (misalnya, menetapkan ambang batas waktu respons).
7. **Dapat Ditelusuri** (_Traceable_): Setiap spesifikasi diberi nomor identifikasi unik (misalnya SRS001) agar mudah dilacak.
8. **Tidak Ambigu** (_Unambiguous_): Tidak ada interpretasi ganda, terutama saat menggunakan bahasa alami.

# Requirements Validation (Validasi)
Fokus utamanya adalah membuktikan bahwa definisi kebutuhan yang telah didokumentasikan adalah **benar-benar** yang diinginkan oleh pelanggan. Validasi sangat penting karena biaya memperbaiki kesalahan kebutuhan setelah sistem diimplementasikan bisa mencapai 100 kali lipat biaya perbaikan kesalahan implementasi.

**Pemeriksaan Kebutuhan (_Requirements Checking_)**:
- _**Validity**_: Apakah sistem menyediakan fungsi yang paling sesuai dengan kebutuhan pelanggan?
- _**Consistency**_: Apakah ada konflik antar kebutuhan?
- _**Completeness**_: Apakah sudah mencakup semua fungsi yang dibutuhkan pelanggan?
- _**Realism**_: Dapatkah kebutuhan diimplementasikan dengan anggaran dan teknologi yang tersedia?
- _**Verifiability**_: Dapatkah kebutuhan diperiksa atau diuji secara realistis?

**Teknik Validasi:** Termasuk _Requirements reviews_ (analisis manual sistematis), _Prototyping_ (menggunakan model sistem yang dapat dieksekusi), dan _Test-case generation_ (mengembangkan pengujian untuk memeriksa kemampuan uji).

# Requirements Management (Manajemen)
Manajemen kebutuhan adalah proses mengelola perubahan kebutuhan. Kebutuhan baru sering muncul selama proses pengembangan dan setelah sistem digunakan, misalnya karena adanya _hardware_ baru, perubahan prioritas bisnis, atau peraturan baru.

**Aktivitas Manajemen:**
- **Identifikasi Kebutuhan:** Setiap kebutuhan harus diidentifikasi secara unik (misalnya, dengan nomor) agar dapat direferensikan silang.
- **Proses Manajemen Perubahan:** Rangkaian kegiatan untuk menilai dampak dan biaya perubahan. Proses ini melibatkan _Analisis masalah dan spesifikasi perubahan_, _Analisis perubahan dan penetapan biaya_ (menggunakan informasi ketertelusuran), dan _Implementasi perubahan_.
- **Kebijakan Ketertelusuran (_Traceability_):** Mencatat hubungan antara setiap kebutuhan dan antara kebutuhan dan desain sistem, yang penting untuk menilai dampak perubahan.