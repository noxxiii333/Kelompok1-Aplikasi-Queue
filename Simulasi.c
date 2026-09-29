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

/* Prosedur untuk menjalankan siklus simulasi alokasi antrean ke loket */
void jalankanSimulasiSimultan(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP, Loket *L1, Loket *L2, Loket *L3, Loket *L4) {
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
    if (isLoketKosong(*L1)) {
        if (!isEmptyQueue(*QA)) {
            dequeue(QA, &P);
            mulaiLayanan(L1, P);
            printf(">> [Loket 1] Memulai layanan 'A' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        } else if (!isEmptyQueue(*QB)) {
            dequeue(QB, &P);
            mulaiLayanan(L1, P);
            printf(">> [Loket 1] Memulai layanan 'B' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    /*  LOKET 2  */
    if (isLoketKosong(*L2)) {
        if (!isEmptyQueue(*QB)) {
            dequeue(QB, &P);
            mulaiLayanan(L2, P);
            printf(">> [Loket 2] Memulai layanan 'B' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    /*  LOKET 3  */
    if (isLoketKosong(*L3)) {
        if (!isEmptyQueue(*QI)) {
            dequeue(QI, &P);
            mulaiLayanan(L3, P);
            printf(">> [Loket 3] Memulai layanan 'I' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        } else if (!isEmptyQueue(*QP)) {
            dequeue(QP, &P);
            mulaiLayanan(L3, P);
            printf(">> [Loket 3] Memulai layanan 'P' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    /*  LOKET 4  */
    if (isLoketKosong(*L4)) {
        if (!isEmptyQueue(*QP)) {
            dequeue(QP, &P);
            mulaiLayanan(L4, P);
            printf(">> [Loket 4] Memulai layanan 'P' untuk pengunjung: %s (ID: %d)\n", P.nama, P.id);
            adaPerubahan = 1;
        }
    }

    if (!adaPerubahan) {
        printf(">> Tidak ada alokasi baru (Antrean kosong atau semua loket sedang sibuk).\n");
    }
}

/* Prosedur untuk menyelesaikan layanan pada loket tertentu */
void menuSelesaiLayanan(Loket *L1, Loket *L2, Loket *L3, Loket *L4) {
    int pilihanLoket;
    printf("\n=== SELESAIKAN LAYANAN LOKET ===\n");
    printf("Pilih Loket yang selesai melayani (1-4): ");
    scanf("%d", &pilihanLoket);

    switch (pilihanLoket) {
        case 1:
            if (!isLoketKosong(*L1)) {
                selesaiLayanan(L1);
                printf(">> Layanan di Loket 1 telah selesai. Pengunjung masuk riwayat.\n");
            } else {
                printf(">> Loket 1 sedang kosong.\n");
            }
            break;
        case 2:
            if (!isLoketKosong(*L2)) {
                selesaiLayanan(L2);
                printf(">> Layanan di Loket 2 telah selesai. Pengunjung masuk riwayat.\n");
            } else {
                printf(">> Loket 2 sedang kosong.\n");
            }
            break;
        case 3:
            if (!isLoketKosong(*L3)) {
                selesaiLayanan(L3);
                printf(">> Layanan di Loket 3 telah selesai. Pengunjung masuk riwayat.\n");
            } else {
                printf(">> Loket 3 sedang kosong.\n");
            }
            break;
        case 4:
            if (!isLoketKosong(*L4)) {
                selesaiLayanan(L4);
                printf(">> Layanan di Loket 4 telah selesai. Pengunjung masuk riwayat.\n");
            } else {
                printf(">> Loket 4 sedang kosong.\n");
            }
            break;
        default:
            printf(">> Nomor loket tidak valid!\n");
    }
}

int main() {
    /*  KAMUS  */
    Pengunjung P1, P2, P3, P4, P5;
    QueueP QA, QB, QI, QP;          
    Loket L1, L2, L3, L4;           
    int pilihan;

    /*  1. MEMBUAT DATA DUMMY PENGUNJUNG  */
    MakePengunjung(&P1, 1, "Bilal",  'A');
    MakePengunjung(&P2, 2, "Joshua", 'B');
    MakePengunjung(&P3, 3, "Wendi",  'I');
    MakePengunjung(&P4, 4, "Radit",  'P');
    MakePengunjung(&P5, 5, "Faza",   'A');

    /*  2. MEMBUAT 4 LOKET (Otomatis set tipe layanan sesuai ID via makeLoket)  */
    makeLoket(&L1, 1);
    makeLoket(&L2, 2);
    makeLoket(&L3, 3);
    makeLoket(&L4, 4);

    /*  3. INISIALISASI ANTREAN  */
    createQueue(&QA);
    createQueue(&QB);
    createQueue(&QI);
    createQueue(&QP);

    /*  4. MEMASUKKAN DATA DUMMY KE ANTREAN  */
    enqueue(&QA, P1);  
    enqueue(&QB, P2);  
    enqueue(&QI, P3);  
    enqueue(&QP, P4);   
    enqueue(&QA, P5);   

    /*  5. MENU UTAMA / INTERAKTIF SIMULASI  */
    do {
        printf("\n========================================\n");
        printf("   SIMULASI ANTREAN LOKET LAYANAN\n");
        printf("========================================\n");
        printf("1. Tambah Pengunjung Baru (Enqueue)\n");
        printf("2. Tampilkan Status Antrean\n");
        printf("3. Tampilkan Informasi Status Loket\n");
        printf("4. Jalankan Siklus Simulasi (Alokasi Loket)\n");
        printf("5. Selesaikan Layanan Loket\n");
        printf("0. Keluar Program\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahPengunjungInteraktif(&QA, &QB, &QI, &QP);
                break;

            case 2:
                printf("\n ANTREAN ADMINISTRASI (A) \n");
                viewQueue(QA);
                printf("\n ANTREAN PEMBAYARAN (B) \n");
                viewQueue(QB);
                printf("\n ANTREAN INFORMASI (I) \n");
                viewQueue(QI);
                printf("\n ANTREAN PENGADUAN (P) \n");
                viewQueue(QP);
                printf("\n");
                break;

            case 3:
                printf("\n================ STATUS LOKET ================\n");
                printf("[ LOKET 1 ]\n"); printLoket(L1);
                printf("\n[ LOKET 2 ]\n"); printLoket(L2);
                printf("\n[ LOKET 3 ]\n"); printLoket(L3);
                printf("\n[ LOKET 4 ]\n"); printLoket(L4);
                break;

            case 4:
                jalankanSimulasiSimultan(&QA, &QB, &QI, &QP, &L1, &L2, &L3, &L4);
                break;

            case 5:
                menuSelesaiLayanan(&L1, &L2, &L3, &L4);
                break;

            case 0:
                printf("Keluar dari program simulasi. Terima kasih!\n");
                break;

            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}