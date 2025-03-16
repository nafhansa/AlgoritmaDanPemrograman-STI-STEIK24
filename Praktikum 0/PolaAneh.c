#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == N / 2 - i || j == N / 2 + i || j == i - N / 2 || j == 3 * (N / 2) - i) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    return 0;
}
