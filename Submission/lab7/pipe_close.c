#include <xinu.h>

devcall pipe_close(struct dentry *devptr) {
    struct pipecblk *piptr;

    piptr = &pipetab[devptr->dvminor];

    if (piptr->pstate == PIPE_FREE) {
        return SYSERR;
    }

    if (piptr->pstate == PIPE_OPEN) {
        piptr->pstate = PIPE_EOF;
        resched_cntl(DEFER_START);
        if (semcount(piptr->pcsem) < 0) {
            semreset(piptr->pcsem, 0);
        }
        if (semcount(piptr->ppsem) < 0) {
            semreset(piptr->ppsem, 0);
        }
        resched_cntl(DEFER_STOP);
        return OK;
    }

    if (piptr->pstate == PIPE_EOF) {
        piptr->pstate = PIPE_FREE;
        semdelete(piptr->pcsem);
        semdelete(piptr->ppsem);
        return OK;
    }
}