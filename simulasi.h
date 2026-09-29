#ifndef SIMULASI_H
#define SIMULASI_H

#include "queue.h"
#include "loket.h"

void jalankanSimulasi(
    QueueP *QA,
    QueueP *QB,
    QueueP *QI,
    QueueP *QP,
    Loket *L1,
    Loket *L2,
    Loket *L3,
    Loket *L4
);

void menuSelesaiLayanan(
    Loket *L1,
    Loket *L2,
    Loket *L3,
    Loket *L4
);

#endif