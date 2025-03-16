#include <stdio.h>

int main() {
    int N, nol = 0;
    scanf("%d", &N);

    for (int i = 5; i <= N; i *= 5) {
        nol += N / i;
    }

    printf("%d\n", nol);
    return 0;
}
