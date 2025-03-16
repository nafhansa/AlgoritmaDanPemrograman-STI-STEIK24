#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2; 
    int dh, dm, ds;
    
    scanf("%d %d %d", &h1, &m1, &s1);
    scanf("%d %d %d", &h2, &m2, &s2);

    ds = s2 - s1;
    if (ds < 0) {
        ds += 60;
        m2 -= 1;
    }
    dm = m2 - m1;
    if (dm < 0) {
        dm += 60;
        h2 -= 1;
    }

    dh = h2 - h1;

    printf("%d %d %d\n", dh, dm, ds);

    return 0;
}
