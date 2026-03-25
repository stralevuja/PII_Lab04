#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int slovo(char c) {
    if ((c>='a' && c<='z') || (c>='A' && c<='Z')) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!=3) {
        printf("Err01: Niste unijeli sve potrebne argumente. <prog.exe fileA.txt fileB.txt>\n");
        return 1;
    }

    FILE *ulazna = fopen(argv[1], "r"); //otvara ulaznu
    FILE *izlazna = fopen(argv[2], "w"); //otvara izlaznu

    if (ulazna == NULL) {
        printf("Err02: Ulazna datoteka nije uspjesno otvorena.\n");
        return 2;
    }

    if (izlazna == NULL) {
        printf("Err03: Izlazna datoteka nije uspjesno otvorena.\n");
        return 3;
    }

    char rijec[MAX]; //trenutna
    char najduza[MAX]; //najduza
    int c, i = 0; //c - trenutni znak, i - counter
    najduza[0] = '\0'; //nulira najduzu rijec

    while ((c = fgetc(ulazna)) != EOF) {
        if (slovo(c)) {
            rijec[i++] = c; //dodaje znak u rijec
        } else {
            if (i > 0) { //ako je rijec popunjena
                rijec[i] = '\0'; //nulira rijec

                fprintf(izlazna, "%s\n", rijec); //upisuje rijec u izlaznu datoteku

                if (strlen(rijec) > strlen(najduza)) { //ako je trenutna duza od najduze
                    strcpy(najduza, rijec); //kopira trenutnu u najduzu
                }

                i = 0; //resetuje counter
            }
        }
    }

    //zadnja rijec (ako nema separator)
    if (i > 0) {
        rijec[i] = '\0'; //nulira rijec

        fprintf(izlazna, "%s\n", rijec); //upisuje rijec u izlaznu datoteku

        if (strlen(rijec) > strlen(najduza)) { //ako je trenutna duza od najduze
            strcpy(najduza, rijec); //kopira trenutnu u najduzu
        }
    }

    printf("Najduza rijec je: %s", najduza);

    //zatvara dat
    fclose(ulazna);
    fclose(izlazna);
    return 0;
}