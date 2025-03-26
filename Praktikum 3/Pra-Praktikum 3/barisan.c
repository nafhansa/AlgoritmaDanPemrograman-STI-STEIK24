#include <stdio.h>

// Fungsi untuk menghitung FPB (GCD) menggunakan algoritma Euclidean
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fungsi untuk menghitung KPK (LCM) berdasarkan FPB
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Fungsi untuk menghitung FPB dari seluruh elemen array
int findGCD(int arr[], int n) {
    if (n == 1) return arr[0];
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

// Fungsi untuk menghitung KPK dari seluruh elemen array
int findLCM(int arr[], int n) {
    if (n == 1) return arr[0];
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

// Fungsi untuk menghitung skor barisan Nimons
int calculateScore(int arr[], int n) {
    if (n == 0) return 0; // Jika tidak ada elemen, skor = 0
    if (n == 1) return arr[0] * arr[0]; // Jika hanya satu elemen, skor = elemennya * elemennya

    int maxScore = findGCD(arr, n) * findLCM(arr, n); // Skor tanpa menghapus elemen

    // Coba hapus satu elemen dan hitung skor ulang
    for (int i = 0; i < n; i++) {
        int tempArr[n - 1], index = 0;
        
        // Salin array tanpa elemen ke-i
        for (int j = 0; j < n; j++) {
            if (j != i) {
                tempArr[index++] = arr[j];
            }
        }

        // Hitung skor baru
        int newScore = findGCD(tempArr, n - 1) * findLCM(tempArr, n - 1);
        if (newScore > maxScore) {
            maxScore = newScore;
        }
    }

    return maxScore;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", calculateScore(arr, n));
    return 0;
}
