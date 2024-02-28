#include<iostream>
using namespace std;

string process[5]={"P1","P2","P3","P4","P5"};
float burst[5]={2,1,8,4,5};
int priority[5]={2,1,4,2,3};
float waitingTime[5];
float turnaroundTime[5];

void GantChart(){
	float firstTime=0;
	cout<<"Gantt Chart"<<endl;
	cout<<firstTime;
	for(int i=0;i<5;i++){
	firstTime+=burst[i];
		cout<<"--"<<process[i]<<"--"<<firstTime;
		}
		
		cout<<endl;
}

void TurnaroundTime(){
	float firstTurn=0;
	for(int i=0;i<5;i++){
	firstTurn+=burst[i];
		cout<<"Turnaround time for "<<process[i]<<" is "<<firstTurn<<endl;
		turnaroundTime[i]=firstTurn;
	}
}

void WaitingTime(){
	float firstWait=0;
	cout<<endl;
	for(int i=0;i<5;i++){
		cout<<"Waiting time for "<<process[i]<<" is "<<firstWait<<endl;
		waitingTime[i]=firstWait;
		firstWait+=burst[i];
	}

}

void AvgTurn(){

	cout<<"Average turnaround time is: ";
	float sum=0;
	float avg;
	
	for(int i=0;i<5;i++)
		sum+=turnaroundTime[i];
		
		avg=sum/5;
		
		cout<<avg<<endl;;
}

void AvgWait(){
	cout<<"Average waiting time is: ";
	float sum=0;
	float avg;
	
	for(int i=0;i<5;i++)
		sum+=waitingTime[i];
		
		avg=sum/5;
		
		cout<<avg<<endl;;

}





int main(){
	GantChart();
	TurnaroundTime();
	WaitingTime();
	AvgTurn();
	AvgWait();
	
}
