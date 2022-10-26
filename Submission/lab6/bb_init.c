/* bb_init.c - bb_init() */

#include <xinu.h>
#include <bb.h>
#include <bb_prototypes.h>

struct bbStruct bb;

int32 bb_init() {
	/* Your code here */
	if (bb.bbState == BB_INIT || bb.bbState == BB_RUN || bb.bbState == BB_OUTONLY) {
		return SYSERR;
	}

	int i;
	for (i = 0; i < BB_SIZE; i++) {
		bb.bbList[i] = '\0';
	}

	bb.bbListHead = 0;
	bb.bbListTail = 0;
	bb.bbPsem = semcreate(BB_SIZE);
	bb.bbCsem = semcreate(0);
	bb.bbState = BB_INIT;
	bb.bbCount = 0;

	return OK;
}
