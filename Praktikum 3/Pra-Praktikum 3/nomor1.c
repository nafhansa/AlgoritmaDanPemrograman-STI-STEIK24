#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Waktu {
    int jam;
    int menit;
    int detik;
} Time;

void setTime(Time *t, int jamBaru, int menitBaru, int detikBaru) {
    t->jam = jamBaru;
    t->menit = menitBaru;
    t->detik = detikBaru;
}

int getJam(Time t){return t.jam;}

int getMenit(Time t){return t.menit;}

int getDetik(Time t){return t.detik;}

void tambahDetik(Time *t, int detikTambahan){
    t->detik += detikTambahan;

    t->menit += t->detik / 60;
    t->detik %= 60;

    t->jam += t->menit / 60;
    t->menit %= 60;

    t->jam %= 24;
}

void printTime(Time t){
    printf("%02d:%02d:%02d", t.jam, t.menit, t.detik);
}

main(){
    Time t;
    setTime(&t, 10, 30, 45);
    tambahDetik(&t, 200);
    printTime(t);
    return 0;
}