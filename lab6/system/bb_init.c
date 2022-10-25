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

	bb.bbListHead = 0;
	bb.bbListTail = BB_SIZE - 1;
	bb.bbPsem = semcreate(BB_SIZE);
	bb.bbCsem = semcreate(0);
	bb.bbState = BB_INIT;

}
