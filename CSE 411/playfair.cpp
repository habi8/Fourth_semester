#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    string input;
    string plain;
    char filler;
    char alpha[25]={'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    bool x[25];
    for(int q=0;q<25;q++) x[q]=false;

    cout << "Enter keyword:";
    cin >> input;
    char mat[5][5];
    int i=0;
    int j=0;
    int k=0;
    int o=0;
        for(int m=0;m<25;m++){
                for(int n=0;n<input.size();n++){
                    if(alpha[m]==input[n]){
                        x[m]=true;
                        break;
                    }
                    }
                    }

            int p=0 ;
           for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(input[k]!=NULL){
                mat[i][j]=input[k];
                k++;
            }
                else{
                   if(x[p]==false) {
                    mat[i][j]=alpha[p];
                    x[p]=true;
                     p++;
                     continue;
                   }
                    else {
                        while(p<25){
                            if(x[p]==false) {
                        mat[i][j]=alpha[p];
                        x[p]=true;
                        break;
                            }
                             p++;
                   }
                    }
                    }
            }
        }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<mat[i][j]<<" ";
        }
        cout <<endl;
    }

    cout<<"Enter plain text:";
    cin>>plain;

    cout<<"enter filler letter:";
    cin>>filler;
    string newstring="";
     int len=plain.size();


    for(int i=0;i<plain.size();i+=2){

        if (i < len - 1 && plain[i] == plain[i + 1]) {
            newstring +=plain[i];
            newstring +=filler;
            newstring+=plain[i];
            i++;
            newstring+=plain[i+1];

        }
        else{
        newstring+=plain[i];
        newstring+=plain[i+1];
        }

    }
    int len2=newstring.size();

    int row1=0;
    int row2=0;
    int col1=0;
    int col2=0;
    string encrypted="";
    for(int k=0;k<len2;k+=2){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                    if(newstring[k]==mat[i][j]){
                        row1=i;
                        col1=j;
                    }
                    if(newstring[k+1]==mat[i][j]){
                        row2=i;
                        col2=j;
                    }
            }
        }

        if(row1==row2){
                if(col1!=4)
            newstring[k]=toupper(mat[row1][col1+1]);
        else
            newstring[k]=toupper(mat[row1][0]);
        if(col2!=4)
            newstring[k+1]=toupper(mat[row2][col2+1]);
        else
            newstring[k+1]=toupper(mat[row2][0]);
        }


        else if(col1==col2){
                if(row1!=4)
            newstring[k]=toupper(mat[row1+1][col1]);
        else
            newstring[k]=toupper(mat[0][col1]);
        if(row2!=4)
            newstring[k+1]=toupper(mat[row2+1][col2]);
        else
            newstring[k+1]=toupper(mat[0][col2]);
        }


        else{
            newstring[k]=toupper(mat[row1][col2]);
            newstring[k+1]=toupper(mat[row2][col1]);

        }
    }

    cout<<"Encrypted word is: "<< newstring;
    return 0;
}
