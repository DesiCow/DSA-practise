#include <iostream>
//
// Created by Utkarsh Upadhyay on 29-09-2026.
//

// Move the Max to right extreme by adjacent swapping
void bubbleSort(int array[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i-1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        std::cout << array[n - i -1] << std::endl;
    }
}

// Move minimum to the left
void selectionSort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j <= n-1; j++ ) {
            if (array[j] < array[min_index]) min_index = j;
        }
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
        std::cout << array[i] << std::endl;
    }
}

// Insert the current element to the leftmost position possible
void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int j = array[i];
        while (j > 0 && array[j-1] > array[i]) {
            array[j] = array[j-1];
            j--;
        }
    }
    for (int i = 0; i < n-1; i++) std::cout << array[i] << " ";
}



int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) std::cin >> array[i];
    selectionSort(array, n);
    return 0;
}