/* bb_insert.c - bb_insert() */

#include <xinu.h>
#include <bb_prototypes.h>
#include <bb.h>

int32 bb_insert(byte b) {
	/* Your code here */
	intmask mask;

	mask = disable();

	if (bb.bbState != BB_RUN) {
		restore(mask);
		return SYSERR;
	}

	wait(bb.bbPsem);

	bb.bbList[bb.bbListTail] = b;
	bb.bbListTail++;
	
	if (bb.bbListTail == BB_SIZE) {
		bb.bbListTail = 0;
	}

	bb.bbCount++;
	
	signal(bb.bbCsem);

	// kprintf("Tail: %d\n", bb.bbListTail);

	restore(mask);
	return OK;
}
