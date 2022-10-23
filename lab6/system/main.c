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
	bb_endinsert();
}

void consumer1(void) {
	int32 b = bb_extract();
	if (b == EOF) {
		kprintf("Test 1 Sucessful\n");
	} else {
		kprintf("Test 1 Failed\n expected: EOF actual: %c\n", b);
	}
}

