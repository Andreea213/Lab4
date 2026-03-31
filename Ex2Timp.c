#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10000


void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
}


void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


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


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        int n1 = m - l + 1, n2 = r - m;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++) L[i] = arr[l + i];
        for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
}

int main() {
    int *original = malloc(N * sizeof(int));
    int *copie = malloc(N * sizeof(int));
    clock_t start, end;
    double timp;

    
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        original[i] = rand() % 50000; 
    }

    const char *names[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Merge Sort"};
    
    printf("Performanta pentru %d elemente:\n", N);
    printf("----------------------------------------\n");

    for (int alg = 0; alg < 5; alg++) {
        memcpy(copie, original, N * sizeof(int)); 
        
        start = clock();
        if (alg == 0) bubbleSort(work, N);
        else if (alg == 1) selectionSort(copie, N);
        else if (alg == 2) insertionSort(copie, N);
        else if (alg == 3) quickSort(copie, 0, N - 1);
        else if (alg == 4) mergeSort(copie, 0, N - 1);
        end = clock();

        timp = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%-15s: %f secunde\n", names[alg], timp);
    }

    free(original);
    free(copie);
    
    

    return 0;
}
