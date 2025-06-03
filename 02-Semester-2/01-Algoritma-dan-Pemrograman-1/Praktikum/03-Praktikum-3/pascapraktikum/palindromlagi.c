// Soal Nomor 1

#include <stdio.h>
#include <string.h>

int isPalindrome(char s[], int len);

int main() {
    char s[1001];
    int len;

    scanf("%s", s);
    len = strlen(s);
    if (isPalindrome(s, len)) {
        printf("YES\n");
        return 0;
    }
    int freq[127] = {0}; // 127 adalah jumlah karakter ASCII berdasarkan website devdocs.io
    for(int i = 0; i < len; i++) {
        freq[s[i]]++;
    }
    int odd = 0;
    for (int i = 0; i < 126; i++) {
        if (freq[i] % 2 == 1) {
            odd++;
        }
    }
    if ((len % 2 == 0 && odd == 0) || (len % 2 == 1 && odd == 1)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
    // Jika panjang string ganjil, maka hanya boleh ada satu karakter yang memiliki frekuensi ganjil
    // Sebaliknya, jika panjang string genap, maka semua frekuensi harus genap atau nol
}

int isPalindrome(char s[], int len) {
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}