/* bb_endextract.c - bb_endextract() */

#include <xinu.h>
#include <bb_prototypes.h>
#include <bb.h>

int32 bb_endextract() {
    /* Your code here */
    if (bb.bbState != BB_OUTONLY) {
        return SYSERR;
    }

    int i;
	for (i = 0; i < BB_SIZE; i++) {
		bb.bbList[i] = '\0';
	}

    for (i = 0; i < bb.bbCount; i++) {
        wait(bb.bbCsem);
        signal(bb.bbPsem);
    }

    bb.bbState = BB_INIT;
    bb.bbCount = 0;

    return OK;
}
