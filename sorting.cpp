#include <iostream>

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

void merge(int array[], int low, int mid, int high) {
    int numberOfElements = high - low + 1;
    int tempArray[numberOfElements];

    int leftPointer = low;
    int rightPointer = mid + 1;
    int i = 0;
    while (leftPointer <= mid && rightPointer <= high) {
        if (array[leftPointer] <= array[rightPointer]) {
            tempArray[i] = array[leftPointer];
            leftPointer++;
        }
        else {
            tempArray[i] = array[rightPointer];
            rightPointer++;
        }
        i++;
    }
    while (leftPointer <= mid) {
        tempArray[i] = array[leftPointer];
        i++;
        leftPointer++;
    }
    while (rightPointer <= high) {
        tempArray[i] = array[rightPointer];
        i++;
        rightPointer++;
    }

    for (int j = 0; j <= high - low; j++) {
        array[j + low] = tempArray[j];
    }
}

void mergeSort(int array[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, mid, high);
}



int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) std::cin >> array[i];
    mergeSort(array, 0, n - 1);
    for (int i = 0; i < n; i++) std::cout << array[i] << std::endl;
    return 0;
}