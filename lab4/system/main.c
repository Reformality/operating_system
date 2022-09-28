/*  main.c  - main */

#include <xinu.h>

process	main(void)
{
	resume(create(dx, 8192, 10, "dx1", 0));
	resume(create(dx, 8192, 10, "dx2", 0));
	resume(create(dx, 8192, 10, "dx3", 0));
	resume(create(dx, 8192, 10, "dx4", 0));

	int32 numMessage = 4;

	while(numMessage){
		receive();
		numMessage--;
	}

	kprintf("all four messages received\n");

	// pid32 dx2P1 = create(dx2, 8192, 10, "dx2_1", 3, 20, 10, 14);
	// resume(dx2P1);
	// pid32 dx2P2 = create(dx2, 8192, 10, "dx2_2", 3, 20, 10, 14);
	// resume(dx2P2);
	// pid32 dx2P3 = create(dx2, 8192, 10, "dx2_3", 3, 20, 10, 14);
	// resume(dx2P3);
	// pid32 dx2P4 = create(dx2, 8192, 10, "dx2_4", 3, 20, 10, 14);
	// resume(dx2P4);

	// pid32 mypid = getpid();

	// send(dx2P1, mypid);
	// send(dx2P2, mypid);
	// send(dx2P3, mypid);
	// send(dx2P4, mypid);

	// int32 dx2Num = 4;
	// int32 msgCount = 0;

	// // while(dx2Num && msgCount < 8) {
	// while(dx2Num) {
	// 	int32 temp;
	// 	temp = receive();
	// 	kprintf("%d\n", temp);
	// 	if (temp == dx2P1 || temp == dx2P2 || temp == dx2P3 || temp == dx2P4) {
	// 		kprintf("process: %d has exited!\n", temp);
	// 		dx2Num--;
	// 		kprintf("received all four PIDs   total messages received is %d\n",msgCount);
	// 	} else {
	// 		msgCount++;
	// 	}
		
	// }

	

	return OK;
}
