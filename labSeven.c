#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void bubbleSort(int arr[], int size, int swapCount[]);
void selectionSort(int arr[], int size, int swapCount[]);
void printArray(int arr[], int size);
void printSwapCount(int arr[], int swapCount[], int size);
void resetSwapCount(int swapCount[], int size);

int main() {
    int array1b[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2b[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array1s[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2s[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swapCount1[SIZE] = {0};
    int swapCount2[SIZE] = {0};

    printf("Bubble Sort on array1:\n");
    bubbleSort(array1b, SIZE, swapCount1);
    printSwapCount(array1b, swapCount1, SIZE);
    resetSwapCount(swapCount1, SIZE); 

    printf("\nSelection Sort on array1:\n");
    selectionSort(array1s, SIZE, swapCount1);
    printSwapCount(array1s, swapCount1, SIZE);
    resetSwapCount(swapCount1, SIZE); 
  
    printf("\nBubble Sort on array2:\n");
    bubbleSort(array2b, SIZE, swapCount2);
    printSwapCount(array2b, swapCount2, SIZE);
    resetSwapCount(swapCount2, SIZE); 

    printf("\nSelection Sort on array2:\n");
    selectionSort(array2s, SIZE, swapCount2);
    printSwapCount(array2s, swapCount2, SIZE);

    return 0;
}

//Bubble sort - compairs pairs to sort.
void bubbleSort(int arr[], int size, int swapCount[]) {
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount[j]++;
                swapCount[j + 1]++;
                totalSwaps++;
            }
        }
    }
    printf("Total swaps: %d\n", totalSwaps);
}

//Selection sort - Loops to find min and sets it at current pos.
void selectionSort(int arr[], int size, int swapCount[]) {
    int i, j, min_idx, temp, totalSwaps = 0;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swapCount[i]++;
            swapCount[min_idx]++;
            totalSwaps++;
        }
    }
    printf("Total swaps: %d\n", totalSwaps);
}

void printSwapCount(int arr[], int swapCount[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d times\n", arr[i], swapCount[i]);
    }
}

void resetSwapCount(int swapCount[], int size) {
    for (int i = 0; i < size; i++) {
        swapCount[i] = 0;
    }
}