#include <stdio.h>

int main() {
    float v;
    int t; 
    float jaraktempuh;

    scanf("%f %d", &v, &t);

    jaraktempuh = v * t;

    // Output dengan format 2 angka di belakang koma
    printf("%.2f\n", jaraktempuh);

    return 0;
}
