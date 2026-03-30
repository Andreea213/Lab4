#include <stdio.h>
#include <string.h>


struct Alergator {
    char nume[50];
    double timp;
};

int main() {
    
    struct Alergator lista[10] = {
        {"Alergator_1", 10.22}, {"Alergator_2", 8.75}, {"Alergator_3", 9.12}, 
        {"Alergator_4", 8.90}, {"Alergator_5", 11.05}, {"Alergator_6", 8.50}, 
        {"Alergator_7", 9.45}, {"Alergator_8", 10.10}, {"Alergator_9", 8.88}, {"Alergator_10", 9.30}
    };
    int n = 10;
    int i, j;
    struct Alergator temp;

    
    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (lista[j].timp < lista[min_idx].timp) {
                min_idx = j;
            }
        }
        
        temp = lista[min_idx];
        lista[min_idx] = lista[i];
        lista[i] = temp;
    }

    
    printf("--- CLASAMENT FINAL ---\n");
    printf("LOC   NUME\n");
    printf("-----------------------\n");
    
    for (i = 0; i < n; i++) {
       
        printf("%d.    %s\n", i + 1, lista[i].nume);
    }

    return 0;
}
