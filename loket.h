#ifndef LOKET_H
#define LOKET_H

#include "boolean.h"
#include "pengunjung.h"

/* Definisi elemen dan koleksi */
#define IDX_UNDEF -1
#define MAX_LAYANAN 2
#define MAX_RIWAYAT 10

/* Program   : loket.h */
/* Deskripsi : ADT Loket untuk merepresentasikan loket layanan antrean. */
/*             Memuat struktur id, status ketersediaan, batas layanan, */
/*             pengunjung aktif, serta array riwayat pengunjung. */
/***********************************/

/* type Loket = < id: integer,                                  {id loket}
                  status: integer,                              {status loket 1=melayani, 0=kosong}
                  jenisLayanan: array [1..2] of character,      {kode layanan yang ditangani}
                  pengunjungAktif: Pengunjung,                  {pengunjung yang sedang dilayani}
                  listPengunjung: array [1..10] of Pengunjung > {pengunjung yang sudah dilayani}
{cara akses: L: Loket, L.id = id(L), L.status = status(L), L.countRiwayat = countRiwayat(L) ...} */
typedef struct { int id; 
                 int status; 
                 char jenisLayanan[MAX_LAYANAN + 1];         // kapasitas 2 elemen, indeks 0 tidak dipakai
                 Pengunjung pengunjungAktif; 
                 Pengunjung listPengunjung[MAX_RIWAYAT + 1]; // kapasitas 10 elemen, indeks 0 tidak dipakai
                } Loket;

/* --- KONSTRUKTOR --- */
/* procedure makeLoket (output L: Loket, input id: integer)
{I.S.: L sembarang}
{F.S.: L terdefinisi dengan id sesuai parameter, status = 0, jenisLayanan berisi sesuai porsinya, pengunjungAktif di-set kosong}
{Proses: Menginisialisasi nilai awal elemen-elemen struktur Loket} */
void makeLoket(Loket *L, int id);

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

#endif