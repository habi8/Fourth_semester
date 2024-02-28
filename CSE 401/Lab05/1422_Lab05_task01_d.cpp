#include<iostream>
#include<vector>
using namespace std;

string process[5]={"P1","P2","P3","P4","P5"};
float burst[5]={2,1,8,4,5};
int priority[5]={2,1,4,2,3};
float waitingTime[5];
float turnaroundTime[5];
bool completed[5];
vector<string> result;
vector<float> rem1;
vector<string> rem2;
vector<float> gtime;

void GantChart(){
	float firstTime=0;
	cout<<"Gantt Chart"<<endl;
	cout<<firstTime;
	int i=0;
	for(auto t : result){
	firstTime=gtime[i];
		cout<<"--"<<t<<"--"<<firstTime;
		i++;
		}
		
		cout<<endl;
}

void TurnaroundTime(){
	float firstTurn=0;
	
	for(int i=0;i<5;i++){
	//firstTurn+=turnaroundTime[i];
		cout<<"Turnaround time for "<<process[i]<<" is "<<turnaroundTime[i]<<endl;
		//turnaroundTime[i]=firstTurn;
	
	}
	cout<<endl;
}

void WaitingTime(){
	float firstWait=0;
	cout<<endl;
	for(int i=0;i<5;i++){
		cout<<"Waiting time for "<<process[i]<<" is "<<waitingTime[i]<<endl;
		//waitingTime[i]=firstWait;
		//firstWait+=burst[i];
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
		completed[i]=false;
	}
	for(int i=0;i<5;i++){
		if(burst[i]<=quantum){
			result.push_back(process[i]);
			sum+=burst[i];
			completed[i]=true;
			turnaroundTime[i]=sum;
			if(i==0) waitingTime[i]==0;
			else
			waitingTime[i]=burst[i-1];
			}
			else {
				result.push_back(process[i]);
				rem1.push_back(burst[i]-quantum);
				//burst[i]=burst[i]-quantum;
				rem2.push_back(process[i]);
				sum+=quantum;
			}
			gtime.push_back(sum);
			//i++;
			}
			for(auto element : rem1){
			cout<<element<<" ";
			}
			
			cout<<endl;
			//cout<<sum;
			int i=0;
			

			while(1){
			
			if(rem1[i]<=quantum){
			result.push_back(rem2[i]);
			sum+=rem1[i];
			float remain=rem1[i];
			rem1[i]=0;
				int k=0;
				string proc=rem2[i];
						for(int j=0;j<5;j++){
						if(proc==process[j]){
						completed[j]=true;
						turnaroundTime[j]=sum;
						waitingTime[j]=sum-remain;
						break;
						}
						}
						
			}
			else {
				//rem1[i]=rem1[i]-quantum;
				rem1.push_back(rem1[i]-quantum);
				rem1[i]=0;
				sum+=quantum;
				result.push_back(rem2[i]);
				rem2.push_back(rem2[i]);
				
			}
			gtime.push_back(sum);
			i++;
				/*int k=0;
				for(auto e:rem1){
					if(e==0){
						string proc=rem2[k];
						for(int j=0;j<5;j++){
						if(proc==process[i]){
						completed[i]=true;
						turnaroundTime[j]=sum;
						break;
						}
						}
						}
						k++;
					}
					*/
					
			cout<<endl;
			if (sum==20) break;
	}
	
	
	GantChart();
	TurnaroundTime();
	WaitingTime();
	AvgTurn();
	AvgWait();
	
	
}
