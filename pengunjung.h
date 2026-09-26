#ifndef PENGUNJUNG_H
#define PENGUNJUNG_H

#include "boolean.h"

/* Program   : pengunjung.h */
/* Deskripsi : ADT Pengunjung untuk merepresentasikan data pengunjung instansi. */
/*             Memuat struktur id, nama pengunjung, dan kode layanan yang dipilih. */
/***********************************/

/* type Pengunjung = < id: integer,          {id pengunjung} 
                       nama: string,         {nama pengunjung}
                       layanan: character >  {kode layanan yang dipilih pengunjung} 
{cara akses: P: Pengunjung, P.id = id(P), P.nama = nama(P) ...} */
typedef struct {
    int id;
    char nama[50];
    char layanan;
} Pengunjung;

#endif