/* pipe_getc.c - pipe_getc */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  pipe_getc  -  read one character from a pipe device
 *------------------------------------------------------------------------
 */
devcall	pipe_getc(
	  struct dentry	*devptr		/* Entry in device switch table	*/
	)
{
	char	ch;			/* byte of data from the buffer	*/
	struct	pipecblk *piptr;	/* Pointer to pipe control block*/


	/* Get a pointer to the control block for this pipe */

	piptr = &pipetab[devptr->dvminor];

	/* Check if pipe is closed or at EOF */

	if (piptr->pstate == PIPE_FREE) {
		/* The pipe is not available */
		return SYSERR;

	}
	if (piptr->pstate == PIPE_EOF) {
		/* The writer has indicated EOF */
		if (semcount(piptr->pcsem) <= 0) {
			return EOF;
		}
	}

	/* Wait for a byte to be available */

	wait(piptr->pcsem);

	/* See if pipe was completely closed while we were blocked */

	if (piptr->pstate == PIPE_FREE) {
		/* Pipe is now closed */
		return SYSERR;
	}

	/* Pick up the byte */

	ch = piptr->pbuf[piptr->phead++];
	if (piptr->phead >= PIPE_BUF_SIZE) {
		piptr->phead = 0;
	}

	/* signal the producer semphore and return the byte */

	signal(piptr->ppsem);
	return 0xff & ch;
}
