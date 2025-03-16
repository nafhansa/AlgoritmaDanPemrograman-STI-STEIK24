#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0) {
        return 0;
    }

    int a = 0, b = 1, temp;

    for (int i = 0; i < N; i++) {
        printf("%d", a);
        if (i < N - 1) {
            printf(" ");
        }
        temp = a + b;
        a = b;
        b = temp;
    }

    printf("\n");
    return 0;
}
