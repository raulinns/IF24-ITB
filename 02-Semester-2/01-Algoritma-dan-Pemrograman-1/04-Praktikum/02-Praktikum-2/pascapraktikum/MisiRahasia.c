// Soal Nomor 4

#include <stdio.h>
#include <string.h>

int isLeapYear(int year);
int getDaysInMonth(int month, int year);
int isValidDate(int day, int month, int year);
const char* getDayOfWeek(int day, int month, int year);
const char* getZodiac(int day, int month);
long long daysFromBeginning(int day, int month, int year);
long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2);
const char* getPasaran(int day, int month, int year);

/**
 * Gunakan strcmp(string1, string2) untuk mengecek apakah kedua string sama
 * Contoh:
 * strcmp("sabtu", "sabtu") --> 0
 * strcmp("senin", "sabtu") --> 1
 */
int main() {
    char pilihan[10] = "";
    int d1, m1, y1, d2, m2, y2;
    while (strcmp(pilihan, "SELESAI") != 0) {
        scanf("%s", &pilihan);
        if (strcmp(pilihan, "SELISIH") == 0) {
            scanf("%d %d %d %d %d %d", &d1, &m1, &y1, &d2, &m2, &y2);
        } else if (strcmp(pilihan, "ZODIAK") == 0) {
            scanf("%d %d", &d1, &m1);
        } else if (strcmp(pilihan, "SELESAI") != 0) {
            scanf("%d %d %d", &d1, &m1, &y1);
        }
        if (strcmp(pilihan, "VALIDASI") == 0) {
            if (isValidDate(d1, m1, y1) == 0) {
                printf("TIDAK\n");
            } else {
                printf("YA\n");
            }
        } else if (strcmp(pilihan, "HARI") == 0) {
            printf("%s\n", getDayOfWeek(d1, m1, y1));
        } else if (strcmp(pilihan, "ZODIAK") == 0) {
            printf("%s\n", getZodiac(d1, m1));
        } else if (strcmp(pilihan, "SELISIH") == 0) {
            printf("%lld\n", dateDifference(d1, m1, y1, d2, m2, y2));
        } else if (strcmp(pilihan, "PASARAN") == 0) {
            printf("%s\n", getPasaran(d1, m1, y1));
        }
    }
    return 0;
}

/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * @param int year
 * @return 1 jika tahun kabisat, 0 jika bukan
 */
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam bulan tertentu
 * @param int month, year
 * @param int year
 * @return total hari dalam bulan tertentu
 */
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return daysInMonth[month] + 1;
    } else {
        return daysInMonth[month];
    }
}

/**
 * Fungsi untuk mengecek apakah suatu tanggal valid
 * @param int day
 * @param int month
 * @param int year
 * @return 1 jika valid, 0 untuk sebaliknya
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
 * Fungsi untuk mendapatkan hari dalam seminggu menggunakan Zeller’s Congruence
 * @param int day
 * @param int month
 * @param int year
 * @return string berupa hari apa pada tanggal tersebut
 */
const char* getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
    
    const char* days[] = {"Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    return days[h];
}

/**
 * Fungsi untuk mendapatkan zodiak berdasarkan tanggal
 * @param int day
 * @param int month
 * @return string berupa zodiak dari tanggal tersebut
 */
const char* getZodiac(int day, int month) {
    const char* zodiacSigns[] = {
        "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
        "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"
    };
    int zodiacStartDays[] = {20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22, 20};

    if (day < zodiacStartDays[month - 1]) return zodiacSigns[month - 1];
    return zodiacSigns[month];
}

/**
 * Fungsi untuk menghitung jumlah hari sejak 01-01-0001
 * @param int day
 * @param int month
 * @param int year
 * @return total hari sejak 01-01-0001 sampai tanggal yang diberikan
 */
long long daysFromBeginning(int day, int month, int year) {
    long long total = 0;    
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
 * Fungsi untuk menghitung selisih hari antara dua tanggal
 * @param int d1
 * @param int m1
 * @param int y1
 * @param int d2
 * @param int m2
 * @param int y2
 * @return total selisih hari dari tanggal ke 1 menuju tanggal ke 2
 */
long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2) {
    return (daysFromBeginning(d2, m2, y2) - daysFromBeginning(d1, m1, y1));
}

/**
 * Fungsi untuk menghitung hari pasaran Jawa
 * @param int day
 * @param int month
 * @param int year
 * @return string hari pasaran jawa berdasarkan tanggal yang diberikan
 */
const char* getPasaran(int day, int month, int year) {
    int daysCount = daysFromBeginning(day, month, year);
    int hariPasaran = daysCount % 5;
    const char* pasaran[] = {"Legi", "Pahing", "Pon", "Wage", "Kliwon"};
    return pasaran[hariPasaran];
}

// Credit to 13524037 - Nicholas Wise Saragih Sumbayak (https://github.com/nicholaswisee/) untuk bantuannya di fungsi getPasaran