/* bb_endinsert.c - bb_endinsert() */

#include <xinu.h>
#include <bb_prototypes.h>
#include <bb.h>

int32 bb_endinsert() {
	/* Your code here */
	if (bb.bbState != BB_RUN) {
		return SYSERR;
	}

	bb.bbState = BB_OUTONLY;
	

}
