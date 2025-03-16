#include <stdio.h>

int main() {
    int N, temp, balik = 0;
    scanf("%d", &N);
    
    temp = N;
    
    for (; temp > 0; temp /= 10) {
        balik = balik * 10 + (temp % 10);
    }

    
    printf("%d\n", (N == balik) ? 1 : 0);
    
    return 0;
}
