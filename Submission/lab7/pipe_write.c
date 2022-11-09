#include <xinu.h>

devcall pipe_write(struct dentry *devptr, char *buffer, int32 length) {
    struct pipecblk *piptr;
    int32 incnt;

    if (length == 0) {
        return 0;
    }
    
    piptr = &pipetab[devptr->dvminor];

    if (piptr->pstate != PIPE_OPEN) {
		return SYSERR;
	}

    incnt = 0;
    while(incnt < length) {
        if (pipe_putc(devptr, buffer[incnt]) == OK) {
            incnt++;
        } else {
            break;
        }
    }

    if (incnt != length) {
        if (incnt == 0) {
            return SYSERR;
        } else {
            return incnt;
        }
    }

    return incnt;
}