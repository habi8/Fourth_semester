#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
float pointsIn;
float pointsTotal;
int number;
float pie;

void *runner1(void *param);
void *runner2(void *param);

int main(int argc, char *argv[]){

	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr; 
	pthread_attr_init(&attr);
	
	if (argc < 2) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	
	return -1;
	}
	
	number=atoi(argv[1]);
	
	if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-		  negative\n",atoi(argv[1]));
	
	return -1;
	}
	pthread_create(&tid1,&attr,runner1,argv[1]);
	//pthread_create(&tid2,&attr,runner2,*number);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pie=(float)4*((float)pointsIn/(float)pointsTotal);
	
	printf("Value of pie is: %lf",pie);
}

void *runner1(void *param){
	
		int n;
		float random1,random2;
		pointsIn=0;
		pointsTotal=0;
		 n=atoi(param);
			for(int i=0;i<n;i++){
				random1=((float)rand()/RAND_MAX)*2-1;
				random2=((float)rand()/RAND_MAX)*2-1;
				pointsTotal++;
				if(abs(random1)<1 && abs(random2)<1) pointsIn++;
			}
}

void *runner2(void *param){
		
}
