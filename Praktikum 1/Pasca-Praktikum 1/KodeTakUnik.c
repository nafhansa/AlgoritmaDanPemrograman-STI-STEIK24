#include <stdio.h>

long akhir(long n) {
    while (n >= 10) {
        long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int main() {
    long kode;
    scanf("%ld", &kode);
    printf("%ld\n", akhir(kode));
    return 0;
}
