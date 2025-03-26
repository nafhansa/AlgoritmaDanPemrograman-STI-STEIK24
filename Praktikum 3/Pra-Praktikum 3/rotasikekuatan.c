#include <stdio.h>

void rotateRight(int arr[], int n, int k) {
    int temp[n];  
    k = k % n; // Pastikan k tidak lebih besar dari n

    // Rotasi ke kanan sebanyak k langkah
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }

    // Cetak hasil rotasi
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", temp[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n, r;

    // Input jumlah elemen dalam barisan Nimons
    scanf("%d", &n);
    int arr[n];

    // Input jumlah rotasi yang akan dilakukan
    scanf("%d", &r);
    int rotasi[r];

    // Input barisan Nimons
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input daftar nilai k untuk rotasi
    for (int i = 0; i < r; i++) {
        scanf("%d", &rotasi[i]);
    }

    // Proses setiap nilai rotasi
    for (int i = 0; i < r; i++) {
        rotateRight(arr, n, rotasi[i]);
    }

    return 0;
}
