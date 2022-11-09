#include <xinu.h>

devcall pipe_read(struct dentry *devptr, char *buffer, int32 length) {
    struct pipecblk *piptr;
    int32 outcnt;
    char rtnmsg;

    if (length == 0) {
        return 0;
    }

    piptr = &pipetab[devptr->dvminor];

    if (piptr->pstate == PIPE_FREE) {
		/* The pipe is not available */
		return SYSERR;
	}

    outcnt = 0;
    while (outcnt < length) {
        rtnmsg = pipe_getc(devptr);
        if (rtnmsg == SYSERR || rtnmsg == EOF) {
            break;
        }
        outcnt++;
    }

    if (outcnt == 0) {
        if (rtnmsg == SYSERR) {
            return SYSERR;
        } else if (rtnmsg == EOF) {
            return EOF;
        }
    }

    return outcnt;
}