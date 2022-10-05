/*  main.c  - main */

#include <xinu.h>

process	main(void)
{
	/* PART 1 */
	// resume(create(dx, 8192, 10, "dx1", 0));
	// resume(create(dx, 8192, 10, "dx2", 0));
	// resume(create(dx, 8192, 10, "dx3", 0));
	// resume(create(dx, 8192, 10, "dx4", 0));

	// int32 numMessage = 4;

	// while(numMessage){
	// 	receive();
	// 	numMessage--;
	// }

	// kprintf("all four messages received\n");

	/* PART 2 */

	// pid32 dx2P1 = create(dx2, 8192, 50, "dx2_1", 3, 20, 10, 14);
	// resume(dx2P1);
	// pid32 dx2P2 = create(dx2, 8192, 50, "dx2_2", 3, 20, 10, 14);
	// resume(dx2P2);
	// pid32 dx2P3 = create(dx2, 8192, 50, "dx2_3", 3, 20, 10, 14);
	// resume(dx2P3);
	// pid32 dx2P4 = create(dx2, 8192, 50, "dx2_4", 3, 20, 10, 14);
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
			
	// 	} else {
	// 		msgCount++;
	// 	}
		
	// }
	// kprintf("received all four PIDs   total messages received is %d\n",msgCount);
	
	/* PART 3 Step 5 */

	// pid32 msgprintP1 = create(msgprint, 8192, 12, "dx2_1", 0);
	// resume(msgprintP1);
	// pid32 msgprintP2 = create(msgprint, 8192, 12, "dx2_2", 0);
	// resume(msgprintP2);

	// int32 mnum = 0;
	// int i;
	// for (i = 0; i < 5; i++) {
	// 	send(msgprintP1, mnum);
	// 	mnum++;
	// 	send(msgprintP2, mnum);
	// 	mnum++;
	// }
	// kprintf("main process exits\n");

	/* PART 3 Step 5 */

	pid32 msgprintP1 = create(msgprint, 8192, 12, "dx2_1", 0);
	resume(msgprintP1);
	pid32 msgprintP2 = create(msgprint, 8192, 12, "dx2_2", 0);
	resume(msgprintP2);

	int32 mnum = 0;
	int i;
	for (i = 0; i < 5; i++) {
		sendlm(msgprintP1, mnum);
		mnum++;
		sendlm(msgprintP2, mnum);
		mnum++;
	}
	kprintf("main process exits\n");

	return OK;
}
