/* Program   : queue.c */
/* Deskripsi : file BODY modul queue representasi kontigu untuk Pengunjung */
/* NIM/Nama  : 24060125120048/Joshua Briliant Suryana */
/* Tanggal   : 27 September 2026 */
/***********************************/

#include <stdio.h>
#include "boolean.h"
#include "queue.h"

/*procedure createQueue ( output Q:QueueP )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: menginisialisasi elemen wadah, head=tail=0 }*/
void CreateQueue(QueueP *Q)
{
    // Kamus Lokal
    int i;
    // Algoritma
    Q->head = 0;
    Q->tail = 0;
    for (i = 1; i <= 10; i++)
    {
        Q->wadah[i].id = -1;
        Q->wadah[i].nama[0] = '\0';
        Q->wadah[i].layanan = '-';
    }
}

/*function infoHead(Q:QueueP)-> Pengunjung
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoHead(QueueP Q)
{
    // Kamus Lokal
    Pengunjung p;
    // Algoritma
    if (!isEmptyQueue(Q))
    {
        return Q.wadah[Q.head];
    }
    else
    {
        p.id = -1;
        p.nama[0] = '\0';
        p.layanan = '-';
        return p;
    }
}

/*function infoTail(Q:QueueP)-> Pengunjung
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoTail(QueueP Q)
{
    // Kamus Lokal
    Pengunjung p;
    // Algoritma
    if (!isEmptyQueue(Q))
    {
        return Q.wadah[Q.tail];
    }
    else
    {
        p.id = -1;
        p.nama[0] = '\0';
        p.layanan = '-';
        return p;
    }
}

/*function sizeQueue(Q:QueueP)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(QueueP Q)
{
    // Kamus Lokal
    // Algoritma
    return Q.tail;
}

/*procedure printQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(QueueP Q)
{
    // Kamus Lokal
    int i;
    // Algoritma
    for (i = 1; i <= 10; i++)
    {
        if (Q.wadah[i].id != -1)
        {
            printf(" [%d, %s, %c] |", Q.wadah[i].id, Q.wadah[i].nama, Q.wadah[i].layanan);
        }
        else
        {
            printf(" [-] |");
        }
    }
}

/*procedure viewQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(QueueP Q)
{
    // Kamus Lokal
    int i;
    // Algoritma
    for (i = 1; i <= sizeQueue(Q); i++)
    {
        printf(" [%d, %s, %c] |", Q.wadah[i].id, Q.wadah[i].nama, Q.wadah[i].layanan);
    }
}

/*function isEmptyQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(QueueP Q)
{
    // Kamus Lokal
    // Algoritma
    return (Q.tail == 0);
}

/*function isFullQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(QueueP Q)
{
    // Kamus Lokal
    // Algoritma
    return (Q.tail == 10);
}

/*function isOneElement(Q:QueueP) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(QueueP Q)
{
    // Kamus Lokal
    // Algoritma
    return ((Q.tail == 1) && (Q.head == 1));
}

/*procedure enqueue( input/output Q:QueueP, input P: Pengunjung )
{I.S.: Q dan P terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void Enqueue(QueueP *Q, Pengunjung P)
{
    // Kamus Lokal
    // Algoritma
    if (!isFullQueue(*Q))
    {
        if (isEmptyQueue(*Q))
        {
            Q->head = 1;
        }
        Q->tail++;
        Q->wadah[Q->tail] = P;
    }
}

/*procedure deQueue( input/output Q:QueueP, output P: Pengunjung )
{I.S.: Q terdefinisi, mungkin kosong}
{F.S.: P=infoHead(Q) atau P kosong bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void Dequeue(QueueP *Q, Pengunjung *P)
{
    // Kamus Lokal
    int i;
    // Algoritma
    if (!isEmptyQueue(*Q))
    {
        *P = infoHead(*Q);
        if (isOneElement(*Q))
        {
            Q->wadah[Q->head].id = -1;
            Q->wadah[Q->head].nama[0] = '\0';
            Q->wadah[Q->head].layanan = '-';
            Q->head = 0;
            Q->tail = 0;
        }
        else
        {
            for (i = 1; i < Q->tail; i++)
            {
                Q->wadah[i] = Q->wadah[i + 1];
            }
            Q->wadah[Q->tail].id = -1;
            Q->wadah[Q->tail].nama[0] = '\0';
            Q->wadah[Q->tail].layanan = '-';
            Q->tail--;
        }
    }
    else
    {
        P->id = -1;
        P->nama[0] = '\0';
        P->layanan = '-';
    }
}

/* procedure tambahPengunjungInteraktif(input/output QA,QB,QI,QP: QueueP)
{I.S.: QA, QB, QI, QP terdefinisi, mungkin kosong}
{F.S.: jika input valid, satu Pengunjung baru ditambahkan ke antrean sesuai kode layanan;
       jika kode layanan tidak valid, tidak ada perubahan pada antrean}
{Proses: membaca id, nama, dan kode layanan dari keyboard, membentuk Pengunjung
         dengan MakePengunjung, lalu melakukan Enqueue ke antrean yang sesuai
         (A->QA, B->QB, I->QI, P->QP)} */
void tambahPengunjungInteraktif(QueueP *QA, QueueP *QB, QueueP *QI, QueueP *QP)
{
    int id;
    char nama[50];
    char layanan;
    Pengunjung P;

    printf("\n=== TAMBAH PENGUNJUNG ===\n");
    printf("ID Pengunjung   : ");
    scanf("%d", &id);
    printf("Nama Pengunjung : ");
    scanf("%s", nama);
    printf("Kode Layanan    : ");
    scanf(" %c", &layanan);

    MakePengunjung(&P, id, nama, layanan);

    switch (layanan)
    {
    case 'A':
    case 'a':
        Enqueue(QA, P);
        printf(">> %s masuk ke antrean A.\n", nama);
        break;
    case 'B':
    case 'b':
        Enqueue(QB, P);
        printf(">> %s masuk ke antrean B.\n", nama);
        break;
    case 'I':
    case 'i':
        Enqueue(QI, P);
        printf(">> %s masuk ke antrean I.\n", nama);
        break;
    case 'P':
    case 'p':
        Enqueue(QP, P);
        printf(">> %s masuk ke antrean P.\n", nama);
        break;
    default:
        printf(">> Kode layanan tidak valid! (Gunakan A/B/I/P)\n");
    }
}
