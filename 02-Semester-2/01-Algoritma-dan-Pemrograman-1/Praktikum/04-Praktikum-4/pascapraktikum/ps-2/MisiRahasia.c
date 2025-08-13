#include <stdio.h>
#include <stdlib.h>
#include "tester.h" // Perintah soal

void swap(int (*arr)[3], int i, int j) {
    int temp[3];
    temp[0] = arr[i][0];
    temp[1] = arr[i][1];
    temp[2] = arr[i][2];
    
    arr[i][0] = arr[j][0];
    arr[i][1] = arr[j][1];
    arr[i][2] = arr[j][2];
    
    arr[j][0] = temp[0];
    arr[j][1] = temp[1];
    arr[j][2] = temp[2];
}

int main() {
    init(); // Perintah soal
    FILE *data = fopen("input.txt", "r");
    FILE *query = fopen("query.txt", "r");
    int totalmisi = 0;
    int id, success, value;
    
    fscanf(data, "%d %d %d", &id, &success, &value);
    while (id != -1 || success != 0 || value != 0) {
        totalmisi++;
        fscanf(data, "%d %d %d", &id, &success, &value);
    }
    fclose(data);
    
    int arr[totalmisi][3];
    int sorted[totalmisi][3];
    
    data = fopen("input.txt", "r");
    for (int i = 0; i < totalmisi; i++) {
        fscanf(data, "%d %d %d", &id, &success, &value);
        arr[i][0] = id;
        arr[i][1] = success;
        arr[i][2] = value;
        sorted[i][0] = id;
        sorted[i][1] = success;
        sorted[i][2] = value;
    }
    
    for (int i = 0; i < totalmisi - 1; i++) {
        for (int j = 0; j < totalmisi - i - 1; j++) {
            if (sorted[j][1] > sorted[j+1][1]) {
                swap(sorted, j, j + 1);
            } else if (sorted[j][1] == sorted[j+1][1]) {
                if (sorted[j][2] > sorted[j+1][2]) {
                    swap(sorted, j, j+1);
                } else if (sorted[j][2] == sorted[j+1][2]) {
                    if (sorted[j][0] > sorted[j+1][0]) {
                        swap(sorted, j, j+1);
                    }
                }
            }
        }
    }
    
    int totalquery, index;
    fscanf(query, "%d", &totalquery);
    for (int i = 0; i < totalquery; i++) {
        fscanf(query, "%d", &index);
        printf("%d %d\n", sorted[index - 1][0], sorted[index - 1][2]);
    }

    fclose(data);
    fclose(query);
    return 0;
}