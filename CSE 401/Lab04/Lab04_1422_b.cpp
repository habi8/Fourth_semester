#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main(){
	int matA[3][3],matB[3][3],result[3][3];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			result[i][j]=0;
		}
	}
	
	cout<<"Enter the matrix elements:"<<endl;
	freopen("input.txt","r",stdin);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>matA[i][j];
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>matB[i][j];
		}
	}
	
	int sum;
	
	cout << "Resultant Matrix="<<endl;
	for(int i=0;i<3;i++){
		if(fork()==0) {
		int id=getpid();
		cout<<"Process id:"<<id<<endl;
			for(int j=0;j<3;j++){
	    			sum=0;
	    			
	    			
	    			for(int k=0;k<3;k++)
	     	   			sum+=(matA[i][k]*matB[k][j]);	
	     		   	result[i][j]=sum;
	     		   cout << result[i][j]<<" ";	
	     		
	     		}
	     		cout <<endl;	
			break;
		}
	}		
	
}
