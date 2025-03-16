#include <stdio.h>

int main () {

    int n, t;
    scanf("%d %d", &n, &t);

    int tahun;

    for (int i = 0; i < t; i++) {
        n += 9;
        printf("tahun ke-%d = %d\n",i+1,n);
    }

    return 0;

}