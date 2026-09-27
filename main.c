#include "pengunjung.h"
#include "queue.h"
#include "loket.h"

int main()
{

    /* Kamus */
    Pengunjung P1, P2, P3, P4, P5;

    QueueP QA; /* antrean pengunjung di layanan administrasi(A)*/
    QueueP QB; /* antrean pengunjung di layanan pembayaran (B)*/
    QueueP QI; /* antrean pengunjung di layanan informasi (I)*/
    QueueP QP; /* antrean pengunjung di layanan pengaduan (B)*/

    Loket L1, L2, L3, L4; /* loket yang melayani antrean pengunjung */

    /* Algoritma */
    /* membuat sampel beberapa data pengunjung */
    MakePengunjung(&P1, 1, "Bilal", 'A');
    MakePengunjung(&P2, 2, " Joshua", 'C');
    MakePengunjung(&P3, 3, "Wendi", 'B');
    MakePengunjung(&P4, 4, "Radit", 'D');
    MakePengunjung(&P5, 5, "David", 'B');

    /* Membuat Loket*/
    makeLoket(&L1, 1);
    makeLoket(&L2, 2);
    makeLoket(&L3, 3);
    makeLoket(&L4, 4);

    /* inisialisasi Q untuk antrean pengunjung */
    createQueue(&QA);
    createQueue(&QB);
    createQueue(&QI);
    createQueue(&QP); 

    PrintPengunjung(&P1);
    printf("\n\n");
    PrintPengunjung(&P2);
    printf("\n\n");
    PrintPengunjung(&P3);
    printf("\n\n");
    PrintPengunjung(&P4);
    printf("\n\n");
    PrintPengunjung(&P5);
}