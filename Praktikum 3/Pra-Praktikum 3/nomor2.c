#include <stdio.h>

typedef struct Waktu{
    int jam;
    int menit;
    int detik;
} Time;

void setTimeMulai(Time *t, int jamMulai, int menitMulai, int detikMulai){
    t->jam = jamMulai;
    t->menit = menitMulai;
    t->detik = detikMulai;
}

void setTimeSelesai(Time *t, int jamSelesai, int menitSelesai, int detikSelesai){
    t->jam = jamSelesai;
    t->menit = menitSelesai;
    t->detik = detikSelesai;
}

int getJam(Time t){return t.jam;}

int getMenit(Time t){return t.menit;}

int getDetik(Time t){return t.detik;}

void hitungSelisih(TimeMulai, TimeSelesai){
    int selisihJam = getJam(TimeSelesai) - getJam(TimeMulai);
    int selisihMenit = getMenit(TimeSelesai) - getMenit(TimeMulai);
    
}





main(){
    Time t;
    setTimeMulai(&t, 8, 15, 30);
    setTimeSelesai(&t, 10, 45, 15);
}
