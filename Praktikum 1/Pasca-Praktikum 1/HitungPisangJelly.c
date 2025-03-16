#include <stdio.h>

int main() {
    int n, a, pisang = 0, jelly = 0, sebelumbukannol = 1;

    scanf("%d", &n);

    for (int i = 0; i < n && sebelumbukannol; i++) {    
        scanf("%d", &a);
        
        if (a == 0) {
            sebelumbukannol = 0;
        } else if (a % 2 == 0) {
            pisang += a;
        } else {
            jelly += a;
        }
    }

    printf("%d %d\n", pisang, jelly);
    return 0;
}