#include "NimonsBruteforce.h"

/**
 * Fungsi untuk mendapatkan panjang angka
 */
int length(int angka) {
    if (angka == 0) return -1;
    int count = 0;
    while (angka > 0) {
        count++;
        angka /= 10;
    }
    return count;
}

/**
 * Fungsi untuk mendapatkan digit ke-i dari kanan
 */
int getDigit(int angka, int index) {
    int panjang = length(angka);
    if (index < 0 || index >= panjang) return -1;
    while (index--) {
        angka /= 10;
    }
    return angka % 10;
}

/**
 * Fungsi untuk menghapus digit ke-i dari kanan
 */
int removeDigit(int angka, int index) {
    int panjang = length(angka);
    if (index < 0 || index >= panjang) return angka;

    int hasil = 0, faktor = 1;
    for (int i = 0; i < panjang; i++) {
        int digit = angka % 10;
        angka /= 10;
        if (i != index) {
            hasil += digit * faktor;
            faktor *= 10;
        }
    }
    return hasil;
}

/**
 * Fungsi rekursif untuk mencari semua kombinasi angka dengan panjang tetap
 */
void cariKombinasi(int angka, int current, int panjangAwal) {
    // Jika panjang angka yang sedang dibentuk sudah sama dengan panjang input, cetak hasilnya
    if (length(current) == panjangAwal) {
        printf("%d\n", current);
        return;
    }

    int panjang = length(angka);
    for (int i = 0; i < panjang; i++) {
        int digit = getDigit(angka, i);
        int angkaBaru = removeDigit(angka, i);
        cariKombinasi(angkaBaru, current * 10 + digit, panjangAwal);
    }
}

/**
 * Fungsi untuk menginisialisasi pemanggilan cariKombinasi
 */
void NimonBruteforce(int angka) {
    cariKombinasi(angka, 0, length(angka));
}
