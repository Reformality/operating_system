/*  main.c  - main */

#include <xinu.h>
#include <bb_prototypes.h>
#include <bb.h>


void producer1(void);
void consumer1(void);

process	main(void)
{
	bb_init();
	bb_start();

	resume(create((void *)producer1, INITSTK, 10, "Prodcuer", 0, NULL));
	resume(create((void *)consumer1, INITSTK, 10, "Consumer", 0, NULL));

	return OK;
}

void producer1(void) {
	uint32 i;
	for (i = 0; i < BB_SIZE; i++) {
		uint8 a = (uint8)(i % 256);
		bb_insert(a);
	}
	bb_endinsert();
	kprintf("sending %d bytes\n", i);
}

void consumer1(void) {
	int32 b = bb_extract();
	int32 c;
	if (b == EOF) {
		kprintf("EOF!! \n");
		return;
	}
	int32 count = 1;
	
	while(1) {
		c = bb_extract();
		if (c == EOF) {
			kprintf("EOF!! Received %d bytes \n", count);
			break;
		}
		if (c != b+1) {
			kprintf("not in order: %d -> %d\n", b, c);
			break;
		} else {
			kprintf("good: %d -> %d\n", b, c);
		}
		b = c;
		count++;
	}
	
	// int32 b = bb_extract();
	// if (b == EOF) {
	// 	kprintf("Test 1 Sucessful\n");
	// } else {
	// 	kprintf("Test 1 Failed\n expected: EOF actual: %c\n", b);
	// }
}

