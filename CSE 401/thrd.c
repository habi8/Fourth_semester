/**
 * A pthread program illustrating how to
 * create a simple thread and some of the pthread API
 * This program implements the summation function where
 * the summation operation is run as a separate thread.
 *
 * Most Unix/Linux/OS X users
 * gcc thrd.c -lpthread
 *
 * Figure 4.11
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Tenth Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */
int sum1;
int sum2;
void *runner(void *param);
void *runnerr(void *param); /* the thread */

int main(int argc, char *argv[])
{
pthread_t tid;
pthread_t tid2; /* the thread identifier */
pthread_attr_t attr; /* set of attributes for the thread */

if (argc != 3) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	/*exit(1);*/
	return -1;
}

if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	/*exit(1);*/
	return -1;
}

/* get the default attributes */
pthread_attr_init(&attr);

/* create the thread */
pthread_create(&tid,&attr,runner,argv[1]);
pthread_create(&tid2,&attr,runnerr,argv[2]);

/* now wait for the thread to exit */
pthread_join(tid,NULL);
pthread_join(tid2,NULL);

printf("total sum = %d\n",sum1+sum2);
}

/**
 * The thread will begin control in this function
 */
void *runner(void *param) 
{
int i, upper = atoi(param);
sum1 = 0;

	if (upper > 0) {
		for (i = 1; i <= upper; i++)
			sum1 += i;
		
	}
	printf("Sum from thread 1:%d\n",sum1);

	pthread_exit(0);
}

void *runnerr(void *param) 
{
int i, upper = atoi(param);
sum2 = 0;

	if (upper > 0) {
		for (i = 1; i <= upper; i++)
			sum2 += i;
		
	}
	printf("Sum from thread 2:%d\n",sum2);

	pthread_exit(0);
}
