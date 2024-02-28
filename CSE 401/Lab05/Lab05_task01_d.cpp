#include<iostream>
#include<vector>
using namespace std;

string process[5]={"P1","P2","P3","P4","P5"};
float burst[5]={2,1,8,4,5};
int priority[5]={2,1,4,2,3};
float waitingTime[5];
float turnaroundTime[5];
vector<string> result;
vector<float> rem1;
vector<string> rem2;

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
		
		cout<<avg<<endl;
}

void AvgWait(){
	cout<<"Average waiting time is: ";
	float sum=0;
	float avg;
	
	for(int i=0;i<5;i++)
		sum+=waitingTime[i];
		
		avg=sum/5;
		
		cout<<avg<<endl;

}





int main(){
	
	float quantum;
	cout<<"Enter quantum: ";
	cin>>quantum;
	
	
	float sum=0;
	
	for(int i=0;i<5;i++){
		if(burst[i]<=quantum){
			result.push_back(process[i]);
			sum+=burst[i];
			}
			else {
				result.push_back(process[i]);
				rem1.push_back(burst[i]-quantum);
				//burst[i]=burst[i]-quantum;
				rem2.push_back(process[i]);
				sum+=quantum;
			}
			//i++;
			}
			for(auto element : rem1){
			cout<<element<<" ";
			}
			
			cout<<endl;
			cout<<sum;
			int i=0;
			
			
			for(auto element : rem2){
			cout<<element<<" ";
			}
			cout<<endl;
			while(sum<=20){
			
			if(rem1[i]<=quantum){
			result.push_back(rem2[i]);
			sum+=rem1[i];
			rem1[i]=0;
			
			}
			else {
				rem1[i]=rem1[i]-quantum;
				rem1.push_back(rem1[i]);
				sum+=quantum;
				result.push_back(rem2[i]);
				rem2.push_back(rem2[i]);
				
			}
			
			i++;
			cout<<endl;
			for(auto element : rem1){
			cout<<element<<" ";
			}
			cout<<endl;
			for(auto element : rem2){
			cout<<element<<" ";
			}
			cout<<endl;
			cout<<sum;
	}
	
	
	//GantChart();
	//TurnaroundTime();
	//WaitingTime();
	//AvgTurn();
	//AvgWait();
	
	for(auto element : result){
		cout<<element<<" ";
	}
}
