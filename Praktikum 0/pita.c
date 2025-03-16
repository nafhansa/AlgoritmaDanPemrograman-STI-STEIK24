#include <stdio.h>


int fpb(int a, int b) {
    if (b == 0)
        return a;
    return fpb(b, a % b);
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    
    printf("%d\n", fpb(A, B)); 
    
    return 0;
}
