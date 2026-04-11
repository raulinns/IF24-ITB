#include <stdio.h>
#include "mesinkata.h"

Word reverseWord() {
    Word revWord;
    
    revWord.Length = currentWord.Length;
    // printf("%d %d\n", revWord.Length, currentWord.Length);
    
    int len = revWord.Length;
    for (int i = 0; i < revWord.Length; i++) {
        revWord.TabWord[len - i - 1] = currentWord.TabWord[i];
    }
    return revWord;
}

int main() {
    STARTWORD();
    while (!EndWord) {
        Word revWord = reverseWord();
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", revWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }
}