#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}


void countPrime(int A, int B, int *total) {
    *total = 0;
    for (int i = A; i <= B; i++) {
        if (isPrime(i)) {
            (*total)++;
        }
    }
}

int main() {
    int A, B, total;

    scanf("%d %d", &A, &B);

    countPrime(A, B, &total);

    printf("%d\n", total);

    return 0;
}
