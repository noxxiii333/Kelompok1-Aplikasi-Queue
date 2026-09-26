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

/* type Loket = < id: integer,                                 {id loket}
                  status: integer,                             {status loket 1=melayani, 0=kosong}
                  jenisLayanan: array [1..2] of character,     {kode layanan yang ditangani}
                  pengunjungAktif: Pengunjung,                 {pengunjung yang sedang dilayani}
                  listPengunjung: array [1..10] of Pengunjung, {pengunjung yang sudah dilayani}
                  countRiwayat: integer                        {jumlah riwayat pengunjung} >
{cara akses: L: Loket, L.id = id(L), L.status = status(L), L.countRiwayat = countRiwayat(L) ...} */
typedef struct { 
    int id; 
    int status; 
    char jenisLayanan[MAX_LAYANAN + 1];         // kapasitas 2 elemen, indeks 0 tidak dipakai
    Pengunjung pengunjungAktif; 
    Pengunjung listPengunjung[MAX_RIWAYAT + 1]; // kapasitas 10 elemen, indeks 0 tidak dipakai
    int countRiwayat;                           // melacak jumlah pengunjung di listPengunjung
} Loket;

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
    
#endif