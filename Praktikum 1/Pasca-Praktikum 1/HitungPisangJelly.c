#include <stdio.h>

int main() {
    long n, a, pisang = 0, jelly = 0, sebelumbukannol = 1;

    scanf("%ld", &n);

    for (long i = 0; i < n && sebelumbukannol; i++) {    
        scanf("%ld", &a);
        
        if (a == 0) {
            sebelumbukannol = 0;
        } else if (a % 2 == 0) {
            pisang += a;
        } else {
            jelly += a;
        }
    }

    printf("%ld %ld\n", pisang, jelly);
    return 0;
}
