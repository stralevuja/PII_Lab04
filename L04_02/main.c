#include <stdio.h>

#define PI 3.1415926

double povrsina(double r) {
    return PI * r * r;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Err01: Neispravan argument.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); //otvara fajl

    if (fp == NULL) {
        printf("Err02: Datoteka nije otvorena.\n");
        return 2;
    }

    double x, y, r;
    double maxpov = 0.0;
    double maxx, maxy, maxr;

    while (fscanf(fp, "(%lf,%lf,%lf)\n", &x, &y, &r) == 3) { //parsiranje
        double p = povrsina(r);

        if (p > maxpov) { //setovanje max vrijednosti
            maxpov = p;
            maxx = x;
            maxy = y;
            maxr = r;
        }
    }

    if (maxpov > 0) {
        printf("Najvecu povrsinu (P=%lf) ima krug: (%.3lf,%.3lf,%.3lf)\n", maxpov, maxx, maxy, maxr);
    } else {
        printf("Nema kruga.\n");
    }

    fclose(fp); //zatvaranje dat
    return 0;
}