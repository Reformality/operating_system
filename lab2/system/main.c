/*  main.c  - main */

#include <xinu.h>

bool8 doit = FALSE;

void pr(char x) {
	while (TRUE) {
		if (doit) {
			kprintf("%c",x);
		}
		int i;
		int count = 0;
		for (i=0; i<100000000; i++) {
			count++;
		}
	}
}

void prsusp(char x) {
	while (TRUE) {
		kprintf("%c",x);
		int i;
		int count = 0;
		for (i=0; i<100000000; i++) {
			count++;
		}
	}
}

process	main(void)
{
	resume(create(pr, 8192, 10, "myproc1", 1, 'A'));
	resume(create(pr, 8192, 10, "myproc2", 1, 'B'));
	
	while (TRUE) {
		char str1[128];
		read(CONSOLE, str1, 128);
		if(strncmp(str1,"print",5) == 0) {
			doit = TRUE;
		} else if (strncmp(str1, "quit",4) == 0) {
			break;
		} else {
			doit = FALSE;
		}
	}

	pid32 p1;
	pid32 p2;
	p1 = create(prsusp, 8192, 11, "myproc3", 1, 'C');
	resume(p1);
	p2 = create(prsusp, 8192, 11, "myproc4", 1, 'D');
	resume(p2);

	while (TRUE) {
		char str1[128];
		read(CONSOLE, str1, 128);
		if(strncmp(str1,"print",5) == 0) {
			resume(p1);
			resume(p2);
		} else if (strncmp(str1, "quit",4) == 0) {
			break;
		} else {
			suspend(p1);
			suspend(p2);
		}
	}

	return OK;
}
