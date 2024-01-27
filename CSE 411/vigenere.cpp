#include<iostream>
#include<cstring>
using namespace std;

int main(){
    
    char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string plaintext;
	string key;
	string newkey="";
	
	cout << "Enter input string:";
	cin >> plaintext;
	
	cout << "Enter key:";
	cin >> key;
	
	int k =0;
	int len=plaintext.size();
	for(int i=0;i<len;i++){
		again:
		newkey+=key[k];
		k++;
		if(key[k]=='\0' && i!=len-1){
		    i++;
			k=0;
			goto again;
		}
	}	
	
	
	char mat[27][27];
	mat[0][0]='X';
	for(int i=1;i<27;i++){
	        mat[0][i]=alpha[i-1];
	        mat[i][0]=alpha[i-1];
	}
	int l;
	       
	for(int i=1;i<27;i++){
	    l=i-1;
	    for(int j=1;j<27;j++){
	        //l=j-1;
	        onceagain:
	        mat[i][j]=alpha[l];
	        l++;
	        
	       if(l>=25 && j !=26){
	           l=0;
	           j++;
	           goto onceagain;
	       }
	       
	    }
	}
	for(int i=0;i<27;i++){
	cout <<endl;
	for(int j=0;j<27;j++){
	    cout<<mat[i][j]<<" ";
	}
	}
	int row1,row2,col1,col2;
	
	string encrypted="";
	for(int i=0;i<len;i++){
	    for(int j=0;j<27;j++){
	        if(plaintext[i]==mat[0][j]) col1=j;
	        if(newkey[i]==mat[j][0])  row1=j;
	    }
	    encrypted+=toupper(mat[row1][col1]);
	}
	
	cout<<endl <<"Encryptted word is: "<<encrypted;
}
