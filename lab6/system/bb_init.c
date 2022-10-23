/* bb_init.c - bb_init() */

#include <xinu.h>
#include <bb.h>
#include <bb_prototypes.h>

struct bbStruct bb;

int32 bb_init() {
	/* Your code here */

	bb.bbListHead = 0;
	bb.bbListTail = BB_SIZE - 1;
	bb.bbPsem = semcreate(BB_SIZE);
	bb.bbCsem = semcreate(0);
	

}
