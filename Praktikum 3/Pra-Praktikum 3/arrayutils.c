#include "arrayutils.h"
#include <stdio.h>

// Fungsi untuk mengurutkan array secara ascending (Bubble Sort)
void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk mencari indeks pertama dari elemen target dalam array
int find(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Jika elemen tidak ditemukan
}

// Fungsi untuk menghitung rata-rata elemen dalam array
double calculateAverage(int arr[], int n) {
    if (n == 0) return 0; // Hindari pembagian dengan nol
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

// Fungsi untuk mencari median dari array
int findMedian(int arr[], int n) {
    sort(arr, n); // Pastikan array terurut
    if (n % 2 == 1) {
        return arr[n / 2]; // Jika jumlah elemen ganjil
    } else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2; // Jika jumlah elemen genap
    }
}

// Fungsi untuk mencari modus dalam array
int findMode(int arr[], int n) {
    sort(arr, n); // Pastikan array terurut
    int mode = arr[0], maxCount = 1, count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }

    return mode;
}

// Fungsi untuk mencari elemen maksimum dalam array
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Fungsi untuk mencari elemen minimum dalam array
int findMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// Fungsi untuk membalikkan array
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
