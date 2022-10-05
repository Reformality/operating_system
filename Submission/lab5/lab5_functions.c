#include <xinu.h>

int32 cmpfnc (const void * min, const void * max) {
   return ( *(int32 *)max - *(int32 *)min );
}

void p1() {
	kprintf("\n\nBeginning part 1:\n\n");
	// Add step 4 implementation here
	// Use kprintf("min address: 0x%x, max address: 0x%x, num bytes: %<format specifier here>\n", your vars here); for step 4
	pid32 pidIter = 0;
	struct procent *prptr;
	char* prstklow;			/* 			*/
	char* prstkbase;		/* Base of run time stack		*/
	uint32	prstklen;	/* Stack length in bytes		*/
	int32 numPr = 0;

	while (pidIter < NPROC) {
		prptr = &proctab[pidIter];
		if (!isbadpid(pidIter) || (pidIter != NULLPROC)) {
			// kprintf("%x | ",prptr);
			prstkbase = prptr->prstkbase;
			prstklen = prptr->prstklen;
			prstklow = (char *)((uint32)prstkbase - prstklen + (uint32)sizeof(uint32));
			prstklen /= 1024;
			// kprintf("pid:%d | ", pidIter);
			if (prstklen > 0) {
				numPr++;
				kprintf("min address: 0x%x, max address: 0x%x, num bytes: %dKB\n", prstklow, prstkbase, prstklen);
			}
		}
		pidIter++;
	}

	// iterate again for step 5
	pidIter = 0;
	int32 minList[numPr];
	int32 maxList[numPr];
	int32 i = 0;

	while (pidIter < NPROC) {
		prptr = &proctab[pidIter];
		if (!isbadpid(pidIter) || (pidIter != NULLPROC)) {
			prstkbase = prptr->prstkbase;
			prstklen = prptr->prstklen;
			prstklow = (char *)((uint32)prstkbase - prstklen + (uint32)sizeof(uint32));
			if (prstklen > 0) {
				minList[i] = prstklow;
				maxList[i] = prstkbase;
				i++;
			}
		}
		pidIter++;
	}
	kprintf("\n");

	// Add step 5 implementation here
	kprintf("Sorted min addresses:\n");
	// Print sorted min addresses using kprintf("address: 0x%x\n", vars here);
	qsort(minList, numPr, sizeof(uint32), cmpfnc);
	
	for (i = 0; i < numPr; i++) {
		kprintf("address: 0x%x\n", minList[i]);
	}

	kprintf("\nSorted max addresses:\n");
	// Print sorted max addresses using kprintf("address: 0x%x\n", vars here);
	qsort(minList, numPr, sizeof(uint32), cmpfnc);
	
	for (i = 0; i < numPr; i++) {
		kprintf("address: 0x%x\n", maxList[i]);
	}

	kprintf("\n");
	return;
}

void p2() {
	kprintf("\n\nBeginning part 2:\n\n");

	// Add step 6 implementation here
	// Use kprintf("min address: 0x%x, max address: 0x%x, num bytes: %<format specifier here>\n", your vars here); for step 6
  // Use kprintf("calculated total: %<format specifier here>, memlist total: %<format specifier here>\n", your vars here); when printing total and memlist

	struct memblk *curr, *maxAddr;
	curr = memlist.mnext;
	uint32 nbytes;
	uint32 totalCalcBytes = 0;

	while (curr != NULL) {
		nbytes = curr->mlength;
		maxAddr = (struct memblk *)((uint32)curr + nbytes);
		kprintf("min address: 0x%x, max address: 0x%x, num bytes: %d\n", curr, maxAddr, nbytes);
		totalCalcBytes+= nbytes;
		curr = curr->mnext;
	}

	kprintf("calculated total: %d, memlist total: %d\n", totalCalcBytes, memlist.mlength);
	kprintf("\n");

	// step 7
	char * m1, m2, m3;

	m1 = getmem(2000);
	m2 = getmem(1000);
	m3 = getmem(2000);

	freemem(m1, 1000);

	
	// Add step 8 implementation here
	// Use kprintf("block address: 0x%x, block size: %<format specifier here>\n", your vars here); for step 8
	curr = memlist.mnext;
	while (curr != NULL) {
		kprintf("block address: 0x%x, block size: %d\n", curr, curr->mlength);
		curr = curr->mnext;
	}

	return;
}
