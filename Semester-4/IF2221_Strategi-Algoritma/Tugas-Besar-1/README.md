# Battlecode 2025 - IndonesiaSuksesLiatAkramManu

## 1) Penjelasan Singkat Algoritma Greedy

Algoritma menggunakan pendekatan greedy: pada tiap ronde bot memilih aksi valid dengan dampak lokal terbaik.

### Alternatif 1 - Greedy Territorial Expansion
- Fokus utama: ekspansi area cat secepat mungkin.
- Prioritas: tile kosong/area lawan terdekat, build tower diminimalkan.


### Alternatif 2 - Greedy Prioritas Aksi
- Tiap unit punya urutan prioritas aksi tetap (high impact dulu, fallback kemudian).
- Lebih hemat bytecode, tapi adaptasi situasi tidak sefleksibel Bot Utama.
  
### Greedy Pembagian Role (Bot Utama)
- Fase awal: `Searcher` + `Builder` untuk cari ruin dan bangun tower.
- Fase lanjut: `Scout`/`Connector` + unit tempur untuk rebut area dan jaga jalur cat.
- Semua role tetap greedy: pilih target terdekat/paling bernilai pada giliran itu.

## 2) Requirement dan Instalasi

### Requirement
- JDK 21 (wajib, karena `build.gradle` menetapkan Java 21)
- Git
- Gradle Wrapper (`gradlew` / `gradlew.bat`) sudah ada di repo

### Instalasi
- Tidak ada dependensi eksternal tambahan yang harus di-install manual.
- Pastikan artifact engine/client bawaan scaffold tersedia di folder proyek (sudah termasuk pada repo ini).

## 3) Command Build / Compile / Run

### Windows (PowerShell / CMD)

```bash
.\gradlew.bat build
.\gradlew.bat run --console=plain
.\client\Stima Battle Client
```

### Linux / macOS

```bash
./gradlew build
./gradlew run --console=plain
./client/<nama-client-anda>
```

## 4) Author

- Narendra Dharma Wistara Marpaung (13524044)
- Nashiruddin Akram (13524090)
- Manuel Thimoty Silalahi (13524102)
