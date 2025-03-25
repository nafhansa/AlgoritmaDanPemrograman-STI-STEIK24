#include <stdio.h>

int main(){

    int N, hari, pilihan;
    scanf("%d", &N);

    int mentah = 0; int matang = 0; int terlalu_matang = 0; int total = 0;

    while (total < N){
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            scanf(" %d", &hari);
            if (hari >= 0 && hari <= 2){
                printf("Kategori: Mentah\n");
                mentah++;
            }
            else if (hari >= 3 && hari <= 5){
                printf("Kategori: Matang\n");
                matang++;
            }
            else if (hari > 5){
                printf("Kategori: Terlalu Matang\n");
                terlalu_matang++;
            }
            total++;
        }
        else if (pilihan == 2) {
            printf("Laporan Kematangan Pisang\nMentah: %d\nMatang: %d\nTerlalu Matang: %d\n", mentah, matang, terlalu_matang);
        }
        else {
            printf("Input salah. Masukkan kembali input dengan benar.\n");
        }
    }

    printf("Program selesai\n");
}