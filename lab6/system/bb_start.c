/* bb_start.c - bb_start() */

#include <xinu.h>
#include <bb_prototypes.h>
#include <bb.h>

int32 bb_start() {
	/* Your code here */
	if (bb.bbState != BB_INIT) {
		return SYSERR;
	}

	bb.bbState = BB_RUN;
}
