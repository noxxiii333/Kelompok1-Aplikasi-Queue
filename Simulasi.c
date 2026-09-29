/* Program   : main.c */
/* Deskripsi : Program Utama Simulasi Antrean Layanan Instansi */
/* NIM/Nama  : 24060125140179 / Benedictus David Purnomo */
/* Tanggal   : September 2026 */
/************************************************************/

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "pengunjung.h"
#include "queue.h"
#include "loket.h"
#include "Simulasi.h"

/* Prosedur untuk menjalankan siklus simulasi alokasi antrean ke loket */
void jalankanSimulasi(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP, Loket *L1, Loket *L2, Loket *L3, Loket *L4)
{
    Pengunjung P;
    int adaPerubahan = 0;

    printf("\n========================================\n");
    printf("       MENJALANKAN SIKLUS SIMULASI\n");
    printf("========================================\n");

    /* Aturan Prioritas & Alokasi Loket (ID Terkecil didahulukan):
       - Loket 1 (ID 1): Bisa A dan B. Prioritas cek antrean A, lalu B.
       - Loket 2 (ID 2): Bisa B. Cek antrean B.
       - Loket 3 (ID 3): Bisa I dan P. Prioritas cek antrean I, lalu P.
       - Loket 4 (ID 4): Bisa P. Cek antrean P.
    */

    /*  LOKET 1  */
    if (isLoketKosong(*L1))
    {
        if (!isEmptyQueue(*QA))
        {
            Dequeue(QA, &P);
            mulaiLayanan(L1, P);
            printf(">> [Loket 1] Memulai layanan 'A' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
        else if (!isEmptyQueue(*QB))
        {
            Dequeue(QB, &P);
            mulaiLayanan(L1, P);
            printf(">> [Loket 1] Memulai layanan 'B' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    /*  LOKET 2  */
    if (isLoketKosong(*L2))
    {
        if (!isEmptyQueue(*QB))
        {
            Dequeue(QB, &P);
            mulaiLayanan(L2, P);
            printf(">> [Loket 2] Memulai layanan 'B' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    /*  LOKET 3  */
    if (isLoketKosong(*L3))
    {
        if (!isEmptyQueue(*QI))
        {
            Dequeue(QI, &P);
            mulaiLayanan(L3, P);
            printf(">> [Loket 3] Memulai layanan 'I' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
        else if (!isEmptyQueue(*QP))
        {
            Dequeue(QP, &P);
            mulaiLayanan(L3, P);
            printf(">> [Loket 3] Memulai layanan 'P' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    /*  LOKET 4  */
    if (isLoketKosong(*L4))
    {
        if (!isEmptyQueue(*QP))
        {
            Dequeue(QP, &P);
            mulaiLayanan(L4, P);
            printf(">> [Loket 4] Memulai layanan 'P' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    if (!adaPerubahan)
    {
        printf(">> Tidak ada alokasi baru (Antrean kosong atau semua loket sedang sibuk).\n");
    }
}

/* Prosedur untuk menyelesaikan layanan pada loket tertentu */
void menuSelesaiLayanan(Loket *L1, Loket *L2, Loket *L3, Loket *L4)
{
    int pilihanLoket;
    printf("\n=== SELESAIKAN LAYANAN LOKET ===\n");
    printf("Pilih Loket yang selesai melayani (1-4): ");
    scanf("%d", &pilihanLoket);

    switch (pilihanLoket)
    {
    case 1:
        if (!isLoketKosong(*L1))
        {
            selesaiLayanan(L1);
            printf(">> Layanan di Loket 1 telah selesai. Pengunjung masuk riwayat.\n");
        }
        else
        {
            printf(">> Loket 1 sedang kosong.\n");
        }
        break;
    case 2:
        if (!isLoketKosong(*L2))
        {
            selesaiLayanan(L2);
            printf(">> Layanan di Loket 2 telah selesai. Pengunjung masuk riwayat.\n");
        }
        else
        {
            printf(">> Loket 2 sedang kosong.\n");
        }
        break;
    case 3:
        if (!isLoketKosong(*L3))
        {
            selesaiLayanan(L3);
            printf(">> Layanan di Loket 3 telah selesai. Pengunjung masuk riwayat.\n");
        }
        else
        {
            printf(">> Loket 3 sedang kosong.\n");
        }
        break;
    case 4:
        if (!isLoketKosong(*L4))
        {
            selesaiLayanan(L4);
            printf(">> Layanan di Loket 4 telah selesai. Pengunjung masuk riwayat.\n");
        }
        else
        {
            printf(">> Loket 4 sedang kosong.\n");
        }
        break;
    default:
        printf(">> Nomor loket tidak valid!\n");
    }
}
