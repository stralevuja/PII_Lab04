#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Err01: Neispravan argument.");
        return 1;
    }

    FILE *fp = fopen(argv[1], "w"); //otvara dat

    if (fp == NULL) {
        printf("Err02: Neuspjelo otvaranje datoteke.");
        return 2;
    }

    int n;

    do {
        printf("Unesite broj: ");
        scanf("%d", &n);
    } while (n < 0);

    //header
    fprintf(fp, "=== ===== ==================== ======\n");
    fprintf(fp, "RB. SIFRA NAZIV                CIJENA\n");
    fprintf(fp, "=== ===== ==================== ======\n");

    for (int i = 0; i < n; i++) {
        int rb;
        char sifra[5];
        char naziv[20];
        float cijena;

        printf("Unesite redni broj: ");
        scanf("%d", &rb);
        printf("Unesite sifru: ");
        scanf("%s", sifra);
        printf("Unesite naziv: ");
        scanf("%s", naziv);
        printf("Unesite cijenu: ");
        scanf("%f", &cijena);

        fprintf(fp, "%2d. %-5s %-20s %6.2f\n", rb, sifra, naziv, cijena); //unosi svaki art posebno u dat
    }

    fprintf(fp, "=== ===== ==================== ======\n");

    fclose(fp); //zatvara dat
    return 0;
}