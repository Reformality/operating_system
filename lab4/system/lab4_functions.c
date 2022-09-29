#include <xinu.h>

/*************************
*  Your functions here  *
*************************/
void dx(void) {
    int32 ranVal;

    ranVal = rand() % 40 + 10;
    sleepms(ranVal);
}

void dx2(int32 sleep1, int32 sleep2, int32 maxmsg){
    int32 ranVal;
    uint32 M;
    pid32 P;

    uint32 t;
    srand((uint32) gettime(&t));
    
    P = receive();
    ranVal = rand() % sleep1;
    sleepms(ranVal);
    M = rand() % maxmsg;
    send(P, M);
    ranVal = rand() % sleep2;
    sleepms(ranVal);
}

void msgprint(void) {
    pid32 P = getpid();
    // int32 msgCnt = 4;

    while(1) {
        int32 temp;
        temp = receive();
        // msgCnt--;
        kprintf("%d got %d\n", P, temp);
        if (temp > 4) {
            kprintf("%d exits\n", P);
            return;
        }
    }
}