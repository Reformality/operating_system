/*  main.c  - main */

#include <xinu.h>

int32	nprocesses;

int32	total = 0;

int32	t1, t2, t3;

sid32 semid;

#ifndef NITER
#define	NITER	300000
#endif

void	incr1(void) {

	int32	i;

	wait(semid);
	for(i=0; i<NITER;i++) {
		t1 = ++total;
	}
	signal(semid);
	nprocesses--;
}

void	incr2(void) {

	int32	i;

	wait(semid);
	for(i=0; i<NITER;i++) {
		t2 = ++total;
	}
	signal(semid);
	nprocesses--;
}

void	incr3(void) {

	int32	i;

	wait(semid);
	for(i=0; i<NITER;i++) {
		t3 = ++total;
	}
	signal(semid);
	nprocesses--;
}


process timer(void) {

	int32	t;
	for(t=0;t<12;t++) {
		sleepms(1);
	}
	return(OK);

}


process	main(void)

{
	printf("\n\n");

	semid = semcreate(1);

	kill(2);

	resume(create(timer, 8192, 40, "timer", 0));

	kprintf("Expect %d, %d, %d, and total of %d\n\n", NITER, 2*NITER, 3*NITER, 3*NITER);

	resume(create(incr1, 8192, 10, "myproc1", 0));
	resume(create(incr2, 8192, 10, "myproc2", 0));
	resume(create(incr3, 8192, 10, "myproc3", 0));

	nprocesses = 3;

	while(nprocesses > 0) {
		sleepms(1);
	}

	kprintf("Got    %d, %d, %d, and total of %d\n\n",t1,t2,t3, total);

	kprintf("Main process exiting\n\n");

	return OK;
}
