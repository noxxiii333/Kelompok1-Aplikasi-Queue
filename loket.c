/* Program   : loket.c */
/* Deskripsi : file BODY modul loket */
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "loket.h"

/* --- KONSTRUKTOR --- */
/* procedure makeLoket (output L: Loket, input id: integer, input lay1: character, input lay2: character)
{I.S.: L sembarang}
{F.S.: L terdefinisi dengan id sesuai parameter, status = 0, jenisLayanan berisi lay1 dan lay2, pengunjungAktif di-set kosong, countRiwayat = 0}
{Proses: Menginisialisasi nilai awal elemen-elemen struktur Loket} */
void makeLoket(Loket *L, int id, char lay1, char lay2);

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

/* function canServe (L: Loket, kodeLayanan: character) -> boolean 
{mengembalikan true (1) jika kodeLayanan cocok dengan salah satu layanan yang ada di array jenisLayanan loket L} */
boolean canServe(Loket L, char kodeLayanan);

/* --- OPERASI LAINNYA --- */
/* procedure printLoket (input L: Loket)
{I.S.: L terdefinisi}
{F.S.: Informasi id loket, status, jenis layanan, pengunjung aktif, serta daftar pengunjung di listPengunjung tercetak di layar}
{Proses: Menampilkan seluruh detail data pada ADT Loket ke layar konsol} */
void printLoket(Loket L);