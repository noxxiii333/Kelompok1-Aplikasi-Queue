#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"

/* Program   : queue.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array untuk Pengunjung, */
/*             model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060125120048/Joshua Briliant Suryana */
/* Tanggal   : 27 September 2026 */
/***********************************/

/* Definisi ADT Pengunjung */
#ifndef PENGUNJUNG_H
#define PENGUNJUNG_H

/* type Pengunjung = < id: integer,          {id pengunjung} 
                       nama: string,         {nama pengunjung}
                       layanan: character >  {kode layanan yang dipilih pengunjung} 
{cara akses: P: Pengunjung, P.id, P.nama, P.layanan ...} */
typedef struct {
    int id;
    char nama[50];
    char layanan;
} Pengunjung;

#endif

/* Definisi ADT QueueP */
/* type QueueP = < wadah: array [1..10] of Pengunjung,
                   head: integer,
                   tail: integer >
{cara akses: Q: QueueP, Q.head=head(Q) ...} */
typedef struct {
    Pengunjung wadah[11]; // kapasitas 10 elemen, indeks 0 tidak dipakai
    int head;
    int tail;
} QueueP;

typedef QueueP queueP;

/*procedure createQueue ( output Q:QueueP )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: menginisialisasi elemen wadah, head=tail=0 }*/ 
void createQueue(QueueP *Q);

/*function Head(Q:QueueP)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(QueueP Q);
#define head(Q) (Q).head //implementasi fisik macro
#define Head(Q) (Q).head

/*function infoHead(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoHead(QueueP Q);

/*function Tail(Q:QueueP)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(QueueP Q);
#define tail(Q) (Q).tail //implementasi fisik macro
#define Tail(Q) (Q).tail

/*function infoTail(Q:QueueP)-> Pengunjung 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Pengunjung infoTail(QueueP Q);

/*procedure enqueue( input/output Q:QueueP, input P: Pengunjung )
{I.S.: Q dan P terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(QueueP *Q, Pengunjung P);

/*procedure deQueue( input/output Q:QueueP, output P: Pengunjung )
{I.S.: Q terdefinisi, mungkin kosong}
{F.S.: P=infoHead(Q) atau P elemen kosong bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(QueueP *Q, Pengunjung *P);

/*function isEmptyQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(QueueP Q);

/*function isFullQueue(Q:QueueP) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(QueueP Q);

/*function isOneElement(Q:QueueP) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(QueueP Q);

/*procedure printQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(QueueP Q);

/*procedure viewQueue(input Q:QueueP)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(QueueP Q);

/*function sizeQueue(Q:QueueP)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(QueueP Q);

/* Macro alias pemanggilan fungsi (fleksibilitas penamaan PascalCase & camelCase) */
#define CreateQueue  createQueue
#define InfoHead     infoHead
#define InfoTail     infoTail
#define SizeQueue    sizeQueue
#define PrintQueue   printQueue
#define ViewQueue    viewQueue
#define IsEmptyQueue isEmptyQueue
#define IsFullQueue  isFullQueue
#define IsOneElement isOneElement
#define Enqueue      enqueue
#define Dequeue      dequeue

#endif
#include "pengunjung.h"

typedef struct
{
    Pengunjung wadah[50];
    int head;
    int tail;
} QueueP;
