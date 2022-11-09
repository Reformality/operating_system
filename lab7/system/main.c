/*  main.c  - main */

#include <xinu.h>

process	main(void)
{
	// pid32	shpid;		/* Shell process ID */

	// printf("\n\n");

	// /* Create a local file system on the RAM disk */

	// lfscreate(RAM0, 40, 20480);

	// /* Run the Xinu shell */

	// recvclr();
	// resume(shpid = create(shell, 8192, 50, "shell", 1, CONSOLE));

	// /* Wait for shell to exit and recreate it */

	// while (TRUE) {
	//     if (receive() == shpid) {
	// 	sleepms(200);
	// 	kprintf("\n\nMain process recreating shell\n\n");
	// 	resume(shpid = create(shell, 4096, 20, "shell", 1, CONSOLE));
	//     }
	// }

	int16 p;

	p = open(PIPE,"","");

	if (PIPE0 <= p && PIPE9 >= p) {
		kprintf("12 Correct!\n");
	}

	write(p,"CS354 is great", 14);
	char* buffer;
	int32 n;
	n = read(p, buffer, 14);
	kprintf("size of n:%d\n",n);

	close(p);
	int32 retval;
	retval = getc(p);
	if (retval == EOF) {
		kprintf("retval is EOF\n");
	}
	close(p);
	


	return OK;
}
