/* bb_insert.c - bb_insert() */

#include <xinu.h>
#include <bb.h>
#include <bb_prototypes.h>

int32 bb_extract() {
	/* Your code here */
	intmask mask;
	int32 retByte;

	mask = disable();

	if (bb.bbState != BB_RUN && bb.bbState != BB_OUTONLY) {
		restore(mask);
		return SYSERR;
	}

	if (bb.bbCount == 0) {
		restore(mask);
		return EOF;
	}

	wait(bb.bbCsem);

	retByte = bb.bbList[bb.bbListHead];
	bb.bbList[bb.bbListHead] = '\0';
	bb.bbListHead++;

	if (bb.bbListHead == BB_SIZE) {
		bb.bbListHead = 0;
	}

	bb.bbCount--;

	signal(bb.bbPsem);
	
	// kprintf("Head: %d\n", bb.bbListHead);

	restore(mask);
	return retByte;
}
