Model anallisis adalah jembatan antara deskripsi sistem dan model desain. Model harus difokuskan pada kebutuhan yang ada dalam domain masalah/bisnis. Tiap elemen digunakan untuk mengerti kebutuhan sistem dan harus dibuat sederhana. 

Untuk model analisis dapat dibuat berdasarkan beberapa perspektif, yaitu:
>[!img-caption] ![[Pasted image 20251022032630.png]]

# Scenario-Based Model
Pemodelan berbasis skenario (*scenario-based model*) memodelkan cara pengguna berinteraksi dengan perangkat lunak dan cara perangkat lunak berinteraksi dengan sistem lain. Pemodelan dapat dilakukan dengan:
1. Diagram *use-case*
2. Diagram aktivitas
3. Diagram interaksi (*sequence diagram*)

# Use-Case Diagram
_Use-case_ adalah deskripsi hubungan interaksi antara aktor (*actor*) dan sistem. 

Ivar Jacobson mendefinisikan _use-case_ sebagai bantuan untuk mendefinisikan apa yang ada di luar sistem (aktor) dan apa yang harus dilakukan oleh sistem (*use-cases*).

# Konsep Pemodelan Use-Case
### Aktor
Aktor mewakili semua yang berinteraksi dengan sistem. Aktor adalah unsur eksternal. Use-case_ adalah urutan aksi-aksi dalam sistem yang melakukan suatu pekerjaan dan memberikan suatu hasil untuk aktor.Use-case bertindak sebagai penghubung dan alat komunikasi yang baik antara pengguna dan pengembang. Use-case biasanya dinamai dengan *kata kerja* karena menggambarkan sekumpulan aksi yang lengkap atau dapat "berdiri sendiri". Aktor dan *use-case* dihubungkan dengan relasi. 

Aktor bukanlah bagian dari sistem dan mungkin secara aktif bertukar informasi dengan sistem. Aktor mungkin pasif juga sebagai penerima informasi. Aktor bisa merepresentasikan manusia, mesin, atau sistem lain. 

Seorang pengguna mungkin memiliki peran berbeda. Dengan *use-case* peran harus digambarkan berbeda walau penggunanya sama.

### Use-Case
Use-case merepresentasikan dialog antara aktor dengan sistem. *Use-case* diinisiasi oleh aktor untuk melakukan suatu fungsi dalam sistem, sebaliknya sistem juga dapat mengembalikan suatu nilai ke aktor. *Use-case* perlu mengambarkan *event* yang lengkap dan memiliki makna bagi sistem. 

Gambar *use-case* perlu disertai dengan keterangan yang membantu menjelaskan gambaran yang diberikan.

# Aluran Kejadian
Deskripsi _use-case_ (skenario) harus mencakup beberapa bagian, termasuk:
- Kondisi Awal (*Pre-condition/Initial State*): Menjelaskan bagaimana dan kapan _use-case_ dimulai.
- Aliran Dasar (*Basic Flow/Happy Path*): Urutan aksi yang terjadi pada umumnya (normal) ketika suatu _use-case_ dilakukan.
- Aliran Alternatif (*Alternative Path*): Varian yang reguler atau penanganan kasus khusus (misalnya, barang terjepit di mesin).
- Kondisi Akhir (*Post-condition/Final State*): Menjelaskan bagaimana dan kapan _use-case_ selesai.

# Langkah Pemodelan
Langkah-langkah umum yang diikuti adalah :
1. Identifikasi Aktor
2. Identifikasi *Use-Case* (aktivitas yang dilakukan aktor).
3. Gambarkan Diagram *Use-Case* (termasuk hubungan `<<include>>` dan `<<extends>>`).
4. **Buat Skenario** (aliran kejadian) untuk setiap _use-case_.

> `<<include>>` dipakai jika sebuah *use-case* pasti selalu menyertakan fungsi  lain sebagai bagian wajib dari alurnya. `<<extends>>` dipakai jika sebuah *use-case* merupakan perluasan dari *use-case* lain jika kondisi atau syarat lain terpenuhi (`if` atau opsional).

Panah dari `<<extends>>` mengarah dari fungsi *extend* ke fungsi utama. Sebaliknya, panah dari `<<include>>` mengarah dari fungsi utama ke fungsi *include*-nya.

>[!img-caption] ![[Pasted image 20251022034446.png]]

Untuk mengelompokkan elemen-elemen yang terkait secara semantik, kita dapat menggunakan paket. Kegunaannya, agar *use-case* lebih terstruktur dan sebagai batasan lingkup dari satu atau beberapa *use-case*. 

>[!img-caption] ![[Pasted image 20251022040231.png]]

# Skenario
Skenario adalah hasil instansiasi dari *use-case*, Berisi satu aliran (*flow*) dalam suatu *use-case*. Setiap *use-case* akan memiliki sekumpulan *flow-event* dengan skenario sebagai bagian dari instansiasi suatu aliran *event*. Skenario mungkin melibatkan *basic flow* dan *alternative flow*. 

Skenario adalah contoh nyata tentang bagaimana suatu sistem dapat digunakan untuk tugas tertentu. Karena didasarkan pada situasi praktis, _stakeholder_ dapat memahaminya dan mengomentari alur tersebut. Skenario dapat digunakan untuk memahami, memvalidasi aliran _event_ dalam _use-case_, dan memudahkan pengembangan kasus pengujian (_test case_).

>[!img-caption] ![[Pasted image 20251022040926.png]]
>![[Pasted image 20251022040931.png]]
>![[Pasted image 20251022040941.png]]

Model analisis berbasis skenario ini dapat direpresentasikan menggunakan Diagram _Use-Case_, Diagram Aktivitas (dengan atau tanpa _swimlane_), dan Diagram Interaksi (seperti _sequence diagram_).

# Activity Diagram
Diagram aktivitas menjelaskan tentang urutan proses prosedural, bisnis proses, dan urutan kerja (*work flow*).Dalam hierarki _system engineering_, _Activity Diagram_ dikategorikan sebagai _World View_.  Activity diagram ini mirip dengan *flow chart*, tetapi *flow chart* tidak mengenal perilaku paralel/konkuren

>[!img-caption] ![[Pasted image 20251022041144.png]]
>![[Pasted image 20251022041200.png]]
> ![[Pasted image 20251022041211.png]]

