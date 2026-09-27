#include "pengunjung.h"
#include <stdio.h>

/**********KONSTRUKTOR**********/
/* procedure MakePengunjung(output P:Pengunjung, input id:integer, nama:string, layanan:character) */
/* {I.S.: -} */
/* {F.S.: P terdefinisi} */
/* {proses: mengisi nilai komponen id dengan id, nama dengan nama, dan layanan dengan layanan} */
void MakePengunjung(Pengunjung *P, int id, char nama[], char layanan)
{
    P->id = id;
    strcpy(P->nama, nama);
    P->layanan = layanan;
}

/**********SELEKTOR**********/
/* function getID(P:Pengunjung)->integer */
/* {mengembalikan nilai komponen id P} */
int getID(Pengunjung P)
{
    return P.id;
}

/* function getNama(P:Pengunjung)->string */
/* {mengembalikan nilai komponen nama P} */
char *getNama(Pengunjung *P)
{
    return P->nama;
}

/* function getLayanan(P:Pengunjung)->character */
/* {mengembalikan nilai komponen layanan P} */
char getLayanan(Pengunjung P)
{
    return P.layanan;
}

/**********MUTATOR**********/
/* procedure setID(input/output P:Pengunjung, input NewID:integer) */
/* {I.S.: P terdefinisi} */
/* {F.S.: nilai komponen id P berubah menjadi NewID} */
void setID(Pengunjung *P, int NewID)
{
    P->id = NewID;
}

/* procedure setNama(input/output P:Pengunjung, input NewNama:string) */
/* {I.S.: P terdefinisi} */
/* {F.S.: nilai komponen nama P berubah menjadi NewNama} */
void setNama(Pengunjung *P, char NewNama[])
{
    strcpy(P->nama, NewNama);
}

/* procedure setLayanan(input/output P:Pengunjung, input NewLayanan:character) */
/* {I.S.: P terdefinisi} */
/* {F.S.: nilai komponen layanan P berubah menjadi NewLayanan} */
void setLayanan(Pengunjung *P, char NewLayanan)
{
    P->layanan = NewLayanan;
}

/**********PROSEDUR BACA/TULIS**********/
/* procedure PrintPengunjung(input P:Pengunjung) */
/* {I.S.: P terdefinisi} */
/* {F.S.: menampilkan nilai komponen id, nama, dan layanan P} */
void PrintPengunjung(Pengunjung *P)
{
    printf("%-10s : %d\n", "ID", getID(*P));
    printf("%-10s : %s\n", "Nama", getNama(P));
    printf("%-10s : %c\n", "Layanan", getLayanan(*P));
}