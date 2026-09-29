#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "pengunjung.h"
#include "queue.h"
#include "loket.h"
#include "simulasi.h"

/* ============================================================
   MAIN PROGRAM
   ============================================================ */
int main()
{
    /* --- KAMUS --- */
    Pengunjung P1, P2, P3, P4, P5;
    QueueP QA, QB, QI, QP;
    Loket L1, L2, L3, L4;

    /* --- 1. MEMBUAT DATA DUMMY PENGUNJUNG --- */
    MakePengunjung(&P1, 1, "Bilal", 'A');
    MakePengunjung(&P2, 2, "Joshua", 'B');
    MakePengunjung(&P3, 3, "Wendi", 'I');
    MakePengunjung(&P4, 4, "Radit", 'P');
    MakePengunjung(&P5, 5, "David", 'A');

    /* --- 2. MEMBUAT 4 LOKET --- */
    makeLoket(&L1, 1);

    makeLoket(&L2, 2);

    makeLoket(&L3, 3);

    makeLoket(&L4, 4);

    /* --- 3. INISIALISASI ANTREAN --- */
    CreateQueue(&QA);
    CreateQueue(&QB);
    CreateQueue(&QI);
    CreateQueue(&QP);

    /* --- 4. MEMASUKKAN DATA DUMMY KE ANTREAN --- */
    Enqueue(&QA, P1);
    Enqueue(&QB, P2);
    Enqueue(&QI, P3);
    Enqueue(&QP, P4);
    Enqueue(&QA, P5);

    /* --- 5. MENU INTERAKTIF --- */
    int pilihan;
    do
    {
        printf("\n========================================\n");
        printf("   SIMULASI ANTREAN LOKET LAYANAN\n");
        printf("========================================\n");
        printf("1. Tambah Pengunjung\n");
        printf("2. Tampilkan Kondisi Antrean\n");
        printf("3. Tampilkan Informasi Loket\n");
        printf("4. Jalankan Simulasi\n");
        printf("5. Selesaikan Layanan Loket\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambahPengunjungInteraktif(&QA, &QB, &QI, &QP);
            break;

        case 2:
            printf("\n--- ANTREAN A ---\n");
            viewQueue(QA);
            printf("\n--- ANTREAN B ---\n");
            viewQueue(QB);
            printf("\n--- ANTREAN I ---\n");
            viewQueue(QI);
            printf("\n--- ANTREAN P ---\n");
            viewQueue(QP);
            break;

        case 3:
            printf("\n--- LOKET 1 ---\n");
            printLoket(L1);
            printf("\n--- LOKET 2 ---\n");
            printLoket(L2);
            printf("\n--- LOKET 3 ---\n");
            printLoket(L3);
            printf("\n--- LOKET 4 ---\n");
            printLoket(L4);
            break;

        case 4:
            jalankanSimulasi(
                &QA, &QB, &QI, &QP,
                &L1, &L2, &L3, &L4);

            break;

        case 5:
            menuSelesaiLayanan(&L1, &L2, &L3, &L4);
            break;

        case 0:
            printf("Keluar dari program.\n");
            break;

        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}