#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1), temp;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 10000;
    int *v = malloc(n * sizeof(int));
    int sumaCautata, gasit = 0;

   
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20001 - 10000;
    }


    quickSort(v, 0, n - 1);
   
    printf("Introduceti numarul (suma) pe care o cautati: ");
    scanf("%d", &sumaCautata);

  
    int stanga = 0;
    int dreapta = n - 1;

    while (stanga < dreapta) {
        int sumaCurenta = v[stanga] + v[dreapta];

        if (sumaCurenta == sumaCautata) {
            printf("Am gasit perechea: %d + %d = %d\n", v[stanga], v[dreapta], sumaCautata);
            gasit = 1;
            break;
        } 
        else if (sumaCurenta < sumaCautata) {
            stanga++;
        } 
        else {
            dreapta--;
        }
    }

    
    if (!gasit) {
        printf("Nu s-a gasit nicio pereche in vector care sa dea suma %d.\n", sumaCautata);
    }

    free(v);
    return 0;
}
