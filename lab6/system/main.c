/*  main.c  - main */

#include <xinu.h>
#include <bb_prototypes.h>
#include <bb.h>


void producer1(void);
void producer2(pid32);
void consumer1(void);

process	main(void)
{
	bb_init();
	bb_start();

	pid32 pid1 = create((void *)producer1, INITSTK, 10, "Prodcuer1", 0, NULL);
	pid32 pid2 = create((void *)producer2, INITSTK, 10, "Prodcuer2", 1, pid1);
	resume(pid1);
	resume(pid2);
	resume(create((void *)consumer1, INITSTK, 10, "Consumer", 0, NULL));

	return OK;
}

void producer1(void) {
	uint32 i;
	for (i = 0; i < 2*BB_SIZE; i++) {
		bb_insert('A');
	}
	// bb_endinsert();
	receive();
	bb_endinsert();
	kprintf("sending %d As\n", i);
}

void producer2(pid32 pid1) {
	uint32 i;
	for (i = 0; i < BB_SIZE; i++) {
		bb_insert('B');
	}
	// bb_endinsert();
	send(pid1, 'a');
	kprintf("sending %d Bs\n", i);
}

void consumer1(void) {
	int32 x;
	int32 a = 0;
	int32 b = 0;
	while(1) {
		x = bb_extract();
		if (x == EOF) {
			kprintf("There are %d As and %d Bs.\n", a, b);
			break;
		}
		// kprintf("1\n");
		char temp = (char)x;
		if (temp == 'A') {
			a++;
		} else if (temp == 'B') {
			b++;
		} else {
			kprintf("ERROR!\n");
			return;
		}
		// kprintf("2\n");
	}

	bb_endextract();


	// int32 b = bb_extract();
	// int32 c;
	// if (b == EOF) {
	// 	kprintf("EOF!! \n");
	// 	return;
	// }
	// int32 count = 1;
	
	// while(1) {
	// 	c = bb_extract();
	// 	if (c == EOF) {
	// 		kprintf("EOF!! Received %d bytes \n", count);
	// 		break;
	// 	}
	// 	if (b == 255 && c == 0) {
	// 		kprintf("good: %d -> %d\n", b, c);
	// 	} 
	// 	else if (c != b+1) {
	// 		kprintf("not in order: %d -> %d\n", b, c);
	// 		break;
	// 	} 
	// 	else {
	// 		kprintf("good: %d -> %d\n", b, c);
	// 	}
	// 	b = c;
	// 	count++;
	// }
	
}

