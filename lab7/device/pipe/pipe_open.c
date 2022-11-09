#include <xinu.h>

devcall pipe_open(struct dentry *devptr, char *ch1, char *ch2) {
    int32 i;
    struct pipecblk *piptr;

    for (i=0; i<Npip; i++) {
        piptr = &pipetab[i];
        if (piptr->pstate == PIPE_FREE) {
            piptr->pstate = PIPE_OPEN;
            break;
        }
    }

    if (piptr == NULL) {
        return SYSERR;
    }

    piptr->ppsem = semcreate(PIPE_BUF_SIZE);
    piptr->pcsem = semcreate(0);
    piptr->phead = 0;
    piptr->ptail = 0;
    
    return piptr->pdevid;
}