#include<stdio.h>
#include<unistd.h>
int numbers[10]={4,12,12,10,9,4,7,22,69,53};
void frequency(){
	int freq[100]={0};
	printf("Frequency of numbers:\n");
	for(int i=0;i<10;i++){
		freq[numbers[i]]++;
	}
	
	for(int i=0;i<100;i++){
		if(freq[i] > 0)
		printf("%d occurs %d times\n",i,freq[i]);
	}
	printf("\n");
}

void evenSum(){
	int sum=0;
	
	for(int i=0;i<10;i++){
		if(numbers[i]%2==0)
		sum+=numbers[i];
	}
	
	printf("Sum of even numbers is: %d\n\n",sum);
}

void evenCount(){
	int count =0;
	
	for(int i=0;i<10;i++){
		if(numbers[i]%2==0)
		count++;
	}
	printf("Total even number count is: %d\n\n",count);
}

void sortArray(){
	for(int i=0;i<10;i++){
		for(int j=i+1;j<10;j++){
			if(numbers[i] > numbers[j]){
				int temp=numbers[i];
				numbers[i]=numbers[j];
				numbers[j]=temp;
			}
		}
	}
	
	printf("The sorted array is: ");
	for(int i=0;i<10;i++){
		printf("%d ",numbers[i]);
	}
	printf("\n\n");
}
int main(){

	
	int parentID=getpid();
	int pid1 = fork();
	int pid2 = fork();
	int child1ID,child2ID;
	
	if(pid1!=0 && getpid()==parentID){
		printf("This is the parent process with PID %d and PPID %d .\n",getpid(),getppid());
		printf("It shows frequency\n");
		frequency();
	}
	
	if(pid1!=0 && getppid()==parentID){
		int prent2ID=getpid();
		printf("This is the child 1 process with PID %d and PPID %d. It calculates the sum of even numbers.\n",getpid(),getppid());
		evenSum();
	}
	if(getppid()==parentID && pid2==0){
		printf("This is the child 2 process with PID %d and PPID %d .It calculates total even numbers .\n",getpid(),getppid());
		evenCount();
	}
	
	if(pid2==0 && getppid()==parentID){
		printf("This is the child 3 process with PID %d and PPID %d .It sorts the array.\n",getpid(),getppid());
		sortArray();
		
	}
	
}
