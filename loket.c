/* Program   : loket.c */
/* Deskripsi : file BODY modul loket */
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "loket.h"

/* --- KONSTRUKTOR --- */
/* procedure makeLoket (output L: Loket, input id: integer)
{I.S.: L sembarang}
{F.S.: L terdefinisi dengan id sesuai parameter, status = 0, jenisLayanan berisi sesuai porsinya, pengunjungAktif di-set kosong ('-')}
{Proses: Menginisialisasi nilai awal elemen-elemen struktur Loket} */
void makeLoket(Loket *L, int id) {
    // kamus
    int i;

    // algoritma
    L->id = id;
    L->status = 0;
    if (id == 1){
        L->jenisLayanan[1] = 'A';
        L->jenisLayanan[2] = 'B';
    } else if (id == 2){
        L->jenisLayanan[1] = 'B';
        L->jenisLayanan[1] = '-';
    } else if (id == 3){
        L->jenisLayanan[1] = 'I';
        L->jenisLayanan[2] = 'P';
    } else if (id == 4){
        L->jenisLayanan[1] = 'P';
        L->jenisLayanan[1] = '-';
    } else {
        printf("id Loket tidak valid");
    }
    L->pengunjungAktif = '-';
    for (i = 1; i <= MAX_RIWAYAT; i++){
        L->listPengunjung[i] = '-';
    }
}

/* --- SELEKTOR & MUTATOR --- */
/* procedure mulaiLayanan (input/output L: Loket, input P: Pengunjung)
{I.S.: L terdefinisi dan dalam keadaan kosong (status = 0), P terdefinisi}
{F.S.: status L menjadi 1 (melayani), pengunjungAktif L berisi data P}
{Proses: Mengubah status loket menjadi melayani dan menugaskan pengunjung P ke loket tersebut} */
void mulaiLayanan(Loket *L, Pengunjung P);

/* procedure selesaiLayanan (input/output L: Loket)
{I.S.: L terdefinisi dan sedang melayani pengunjung (status = 1)}
{F.S.: status L kembali menjadi 0 (kosong), pengunjungAktif sebelumnya dimasukkan ke dalam listPengunjung, countRiwayat bertambah}
{Proses: Menyelesaikan layanan pengunjung saat ini dan mencatatnya ke dalam riwayat loket} */
void selesaiLayanan(Loket *L);

/* --- PREDIKAT --- */
/* function isLoketKosong (L: Loket) -> boolean 
{mengembalikan true (1) jika status loket adalah 0, dan false (0) jika statusnya 1} */
boolean isLoketKosong(Loket L);

/* function isBisaMelayani (L: Loket, kodeLayanan: character) -> boolean 
{mengembalikan true (1) jika kodeLayanan cocok dengan salah satu layanan yang ada di array jenisLayanan loket L} */
boolean isBisaMelayani(Loket L, char kodeLayanan);

/* --- PRINT --- */
/* procedure printLoket (input L: Loket)
{I.S.: L terdefinisi}
{F.S.: Informasi id loket, status, jenis layanan, pengunjung aktif, serta daftar pengunjung di listPengunjung tercetak di layar}
{Proses: Menampilkan seluruh detail data pada ADT Loket ke layar konsol} */
void printLoket(Loket L);