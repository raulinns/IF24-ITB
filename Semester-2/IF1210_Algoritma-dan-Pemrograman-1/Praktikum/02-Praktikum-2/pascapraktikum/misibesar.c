// Soal Nomor 3

#include <stdio.h>

int isLeapYear(int year);
int getDaysInMonth(int month, int year);
int isValidDate(int day, int month, int year);
int daysFromBeginning(int day, int month, int year);
int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2);

/**
 * Program utama:
 * - Menerima input d1,m1,y1
 * - Validasi tanggal pertama sampai input valid
 * - Menerima input d2,m2,y2
 * - Validasi tanggal kedua sampai input valid dan tanggal kedua lebih besar atau sama dengan dari tanggal pertama
 * - Mengeluarkan output selisih hari dari tanggal kedua - tanggal pertama
 */
int main() {
    int d1, m1, y1, d2, m2, y2;
    do {
        scanf("%d %d %d", &d1, &m1, &y1);
        if (isValidDate(d1, m1, y1) == 0) {
            printf("Tanggal tidak valid\n");
        }
    } while (isValidDate(d1, m1, y1) == 0);
    
    do {
        scanf("%d %d %d", &d2, &m2, &y2);
        if (isValidDate(d2, m2, y2) == 0) {
            printf("Tanggal tidak valid\n");
        } else if (dateDifference(d1, m1, y1, d2, m2, y2) < 0) {
            printf("Tanggal kedua lebih dulu\n");
        }
    } while ((isValidDate(d2, m2, y2) == 0 || dateDifference(d1, m1, y1, d2, m2, y2) < 0));
    printf("%d\n", dateDifference(d1, m1, y1, d2, m2, y2));
    return 0;
}

/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * Untuk tahun kelipatan 100, tahun kabisat harus habis dibagi 400
 * Untuk tahun selain kelipatan 100, tahun kabisat harus habis dibagi 4
 * @param year Tahun
 * @return Mengembalikan 1 jika tahun kabisat, 0 jika tidak
 */
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam suatu bulan
 * @param month Bulan (dalam rentang 1-12)
 * @param year Tahun
 * @return Mengembalikan jumlah hari dalam bulan tersebut
 */
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (isLeapYear(year) == 1) {
              return 29;
            } else {
              return 28;
            }
    }
}

/**
 * Mengembalikan apakah tanggal valid
 * Tanggal yang valid mengikuti aturan berikut:
 * - 1 <= day <= jumlah hari dalam bulan
 * - 1 <= month <= 12
 * - year >= 1
 * @param day The day
 * @param month The month
 * @param year The year
 * @return mengembalikan 1 jika tanggal valid, 0 jika tidak
 */

 int isValidDate(int day, int month, int year) {
    if (day >= 1 && day <= getDaysInMonth(month, year)) {
        if (month >= 1 && month <= 12) {
            if (year >= 1){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/**
 * Fungsi untuk menghitung jumlah hari sejak awal, yaitu day = 1, month = 1, year = 1
 * @param day Hari
 * @param month Bulan
 * @param year Tahun
 * @return Mengembalikan jumlah hari sejak awal
 */
int daysFromBeginning(int day, int month, int year) {
    int total = 0;    
    for (int i = 1; i <= year; i++) {
        if (i == year) {
            for (int j = 1; j < month; j++) {
                total += getDaysInMonth(j, i); 
            }
            total += day;
        } else {
            for (int j = 1; j <= 12; j++) {
                total += getDaysInMonth(j, i);
            }
        }
    }
    return total;
}

/**
 * Fungsi untuk menghitung perbedaan hari dari dua tanggal yang valid (tanggal 2 - tanggal 1)
 * Note: input tanggal sudah valid
 * @param d1 Hari dari tanggal pertama
 * @param m1 Bulan dari tanggal pertama
 * @param y1 Tahun dari tanggal pertama
 * @param d2 Hari dari tanggal kedua
 * @param m2 Bulan dari tanggal kedua
 * @param y2 Tahun dari tanggal kedua
 * @return Mengembalikan perbedaan hari dari tanggal 2 - tanggal 1
 */
int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    return (daysFromBeginning(d2, m2, y2) - daysFromBeginning(d1, m1, y1));
}

// Hasil kerja sama dengan 13524042 - Suryani Mulia Utami