

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define n 7
int sum; /* this data is shared by the thread(s) */
int sum1;
int sum2;
void *runner1(void *param);
void *runner2(void *param);
void *runner3(void *param);
void *runner4(void *param);
char* arr[n];
int arr2[n];

int main(int argc, char *argv[])
{
pthread_t tid;
pthread_t tid2;
pthread_t tid3; 
pthread_t tid4; 
pthread_attr_t attr; /* set of attributes for the thread */

if (argc != n+1) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	
	return -1;
}
for(int i=0;i<n;i++){
	arr[i]=argv[i+1];
}
if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	
	return -1;
}


pthread_attr_init(&attr);


pthread_create(&tid,&attr,runner1,*arr);
pthread_create(&tid2,&attr,runner2,*arr);
pthread_create(&tid3,&attr,runner3,*arr);
pthread_create(&tid4,&attr,runner4,*arr);


pthread_join(tid,NULL);
pthread_join(tid2,NULL);
pthread_join(tid3,NULL);
pthread_join(tid4,NULL);


}


void *runner1(void *param) 
{
int i;
	for(int i=0;i<n;i++){
	arr2[i]=atoi(arr[i]);
	}
	sum1 = 0;

	
		for (i = 0; i < n; i++)
			sum1 += arr2[i];
		
	
	printf("Sum from thread 1:%d\n",sum1);

	pthread_exit(0);
}

void *runner2(void *param) 
{
	for(int i=0;i<n;i++){
	arr2[i]=atoi(arr[i]);
}
	int max=0;
	for(int i=0;i<n;i++){
		if(arr2[i]>max)
			max=arr2[i];
	}
	printf("Max from thread 2:%d\n",max);

	pthread_exit(0);
}

void *runner3(void *param) 
{
	
	for(int i=0;i<n;i++){
	arr2[i]=atoi(arr[i]);
}
	int min=100000;
	for(int i=0;i<n;i++){
		if(arr2[i]<min)
			min=arr2[i];
	}
	printf("Min from thread 3:%d\n",min);

	pthread_exit(0);
}
void *runner4(void *param) 
{
	int sum=0;
	for(int i=0;i<n;i++){
	arr2[i]=atoi(arr[i]);
}

	for(int i=0;i<n;i++){
		sum+=arr2[i];
	}
	int avg=sum/n;
	printf("Avg from thread 4:%d\n",avg);

	pthread_exit(0);
}

