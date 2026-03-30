#include <stdio.h>
#include <string.h>


void printInt(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void printDouble(double arr[], int n) {
    for (int i = 0; i < n; i++) printf("%.4f ", arr[i]);
    printf("\n");
}

void printChar(char arr[], int n) {
    for (int i = 0; i < n; i++) printf("'%c' ", arr[i]);
    printf("\n");
}

// ALGORITMI PENTRU INT 
void bubbleSortInt(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
        }
    }
}

// ALGORITMI PENTRU DOUBLE 
void selectionSortDouble(double arr[], int n) {
    int i, j, min_idx;
    double temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
}

// ALGORITMI PENTRU CHAR 
void quickSortChar(char arr[], int low, int high) {
    if (low < high) {
        char pivot = arr[high];
        int i = (low - 1);
        char temp;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
        int pi = i + 1;
        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

// ALGORITM INSERTION PENTRU INT 
void insertionSortInt(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ALGORITM MERGE PENTRU DOUBLE 
void mergeDouble(double arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    double L[n1], R[n2];
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

void mergeSortDouble(double arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortDouble(arr, l, m);
        mergeSortDouble(arr, m + 1, r);
        mergeDouble(arr, l, m, r);
    }
}

int main() {
    // 1. Vector INT
    int vInt[] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10};
    int nInt = 10;
    
    // 2. Vector DOUBLE
    double vDouble[] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
    int nDouble = 10;
    
    // 3. Vector CHAR
    char vChar[] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'};
    int nChar = 10;

   


    bubbleSortInt(vInt, nInt);
    printf("Vector INT (Bubble):    "); 
    printInt(vInt, nInt);

 
    selectionSortDouble(vDouble, nDouble);
    printf("Vector DOUBLE (Select): "); printDouble(vDouble, nDouble);
    
  
    quickSortChar(vChar, 0, nChar - 1);
    printf("Vector CHAR (Quick):    "); printChar(vChar, nChar);

    
    double vDouble2[] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169};
    mergeSortDouble(vDouble2, 0, nDouble - 1);
    printf("Vector DOUBLE (Merge):  ");
    printDouble(vDouble2, nDouble);

    return 0;
}
