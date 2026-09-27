#ifndef PENGUNJUNG_H
#define PENGUNJUNG_H

#include "boolean.h"
#include <string.h>
#include <stdio.h>

/* Program   : pengunjung.h */
/* Deskripsi : ADT Pengunjung untuk merepresentasikan data pengunjung instansi. */
/*             Memuat struktur id, nama pengunjung, dan kode layanan yang dipilih. */
/***********************************/

/* type Pengunjung = < id: integer,          {id pengunjung}
                       nama: string,         {nama pengunjung}
                       layanan: character >  {kode layanan yang dipilih pengunjung}
{cara akses: P: Pengunjung, P.id = id(P), P.nama = nama(P) ...} */
typedef struct
{
    int id;
    char nama[50];
    char layanan;
} Pengunjung;

/**********KONSTRUKTOR**********/
/* procedure MakePengunjung(output P:Pengunjung, input id:integer, nama:string, layanan:character) */
/* {I.S.: -} */
/* {F.S.: P terdefinisi} */
/* {proses: mengisi nilai komponen id dengan id, nama dengan nama, dan layanan dengan layanan} */
void MakePengunjung(Pengunjung *P, int id, char nama[], char layanan);

/**********SELEKTOR**********/
/* function getID(P:Pengunjung)->integer */
/* {mengembalikan nilai komponen id P} */
int getID(Pengunjung P);

/* function getNama(P:Pengunjung)->string */
/* {mengembalikan nilai komponen nama P} */
char *getNama(Pengunjung *P);

/* function getLayanan(P:Pengunjung)->character */
/* {mengembalikan nilai komponen layanan P} */
char getLayanan(Pengunjung P);

/**********MUTATOR**********/
/* procedure setID(input/output P:Pengunjung, input NewID:integer) */
/* {I.S.: P terdefinisi} */
/* {F.S.: nilai komponen id P berubah menjadi NewID} */
void setID(Pengunjung *P, int NewID);

/* procedure setNama(input/output P:Pengunjung, input NewNama:string) */
/* {I.S.: P terdefinisi} */
/* {F.S.: nilai komponen nama P berubah menjadi NewNama} */
void setNama(Pengunjung *P, char NewNama[]);

/* procedure setLayanan(input/output P:Pengunjung, input NewLayanan:character) */
/* {I.S.: P terdefinisi} */
/* {F.S.: nilai komponen layanan P berubah menjadi NewLayanan} */
void setLayanan(Pengunjung *P, char NewLayanan);

/**********PROSEDUR BACA/TULIS**********/
/* procedure PrintPengunjung(input P:Pengunjung) */
/* {I.S.: P terdefinisi} */
/* {F.S.: menampilkan nilai komponen id, nama, dan layanan P} */
void PrintPengunjung(Pengunjung *P);

#endif