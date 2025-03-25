#include <stdio.h>
#include <string.h>

int IsPrime(int A) {
    int check = 1;
    for(int i = 2; i < A; i++) {
        if(A % i == 0) {
            check = 0;
            break;
        }
    }
    return check;
}

int countDigit(int A) {
    int sum = 0;
    while(A > 0) {
        sum += A % 10;
        A /= 10;
    }
    return sum;
}

int countPrime(int A, int B, int total)
{
    int check = 1;
    for (int i=A; i<= B; i++) {
        check = 1;
        for (int j=2; j<i;j++) {
            if (i%j==0) {
                check = 0;
                break;
            }
        }
        if (check ==1 && i != 1 && IsPrime(countDigit(i)) == 1) {
            total++;
        }
    }
    return total;
}

int bingro(int A) {
    int result = 0;
    while(A > 0) {
        if(A % 2 == 1) {
            result += 1;
        } else {
            result += 0;
        }
        if(A > 1) result *= 10;
        A /= 2;
    }
    return result;
}

int main()
{
    int A, B, total=0;
    scanf("%d %d", &A, &B);
    int num = countPrime(A, B, total);
    int sum = bingro(num);
    printf("%d\n", sum);

    return 0;
}