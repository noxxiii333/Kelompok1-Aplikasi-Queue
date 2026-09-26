/* Program   : loket.c */
/* Deskripsi : file BODY modul loket */
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "loket.h"

/* --- KONSTRUKTOR --- */
/* Membentuk loket kosong dengan id dan jenis layanan tertentu */
void MakeLoket(Loket *L, int id, char lay1, char lay2);

/* --- SELEKTOR & MUTATOR --- */
/* Mengubah status loket menjadi 1 (melayani) dan memasukkan pengunjung ke pengunjungAktif */
void MulaiLayanan(Loket *L, Pengunjung P);

/* Mengubah status loket menjadi 0, memindahkan pengunjungAktif ke listPengunjung */
void SelesaiLayanan(Loket *L);

/* --- PREDIKAT --- */
/* Mengembalikan true jika loket statusnya 0 (kosong/siap melayani) */
boolean IsLoketKosong(Loket L);

/* Mengembalikan true jika loket bisa melayani kode layanan yang diberikan */
boolean CanServe(Loket L, char kodeLayanan);

/* --- OPERASI LAINNYA --- */
/* Menampilkan informasi loket dan antrean riwayat ke layar */
void PrintLoket(Loket L);