/*  main.c  - main */

#include <xinu.h>
void pr(char *chArg) {
	int i;
	for (i=0; i<1000; i++) {
		printf("%s\n",chArg);
	}
}
process	main(void)
{
	pid32	shpid;		/* Shell process ID */

	printf("\n\n");

	/* Create a local file system on the RAM disk */

	lfscreate(RAM0, 40, 20480);

	kprintf("Hello there this is YOUR NAME\n");
	resume(create(pr, 8192, 10, "myproc1", 1, "A"));
	resume(create(pr, 8192, 10, "myproc2", 1, "B"));
	resume(create(pr, 8192, 10, "myproc3", 1, "C"));
	sleep(4);

	/* Run the Xinu shell */

	recvclr();
	resume(shpid = create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
	    if (receive() == shpid) {
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(shpid = create(shell, 4096, 20, "shell", 1, CONSOLE));
	    }
	}
	return OK;
}
