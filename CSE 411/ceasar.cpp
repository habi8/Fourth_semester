#include <iostream>
#include<cstring>
using namespace std;
 string input;
 string encrypt="";
 string decrypt="";
    int key;

string encryption(string input,int key){
    for(int i=0;i<input.size();i++){
        if(input[i]==' ')
            encrypt+=" ";
            if(input[i]+key>122){
            int en=(input[i]+key-122);
                encrypt+=toupper('a'+ en);
            }
            else
                encrypt+=toupper(input[i]+key);
    }
    return encrypt;
}

void decryption(){

}
int main()
{

    cout << "Enter the planetext: ";
    getline(cin,input);

    cout<<"enter key value:";
    cin>>key;
     int len=input.size();
       for(int i=0;i<len;i++){
        if(input[i]==' ')
            encrypt+=" ";
        else if(input[i]+key>122) {
                encrypt+=toupper((input[i]+key-123)+'a');
       }
       else encrypt+=toupper(input[i]+3);
       }
    cout << "encrypted text is:";
    cout<<encrypt<<endl;;

    for(int i=0;i<len;i++){
        if(encrypt[i]==' ')
            decrypt+=" ";
        else if(encrypt[i]-key<65) {
               decrypt+=tolower((input[i]-key+130)+'a');

       }
       else decrypt+=tolower(encrypt[i]-key);
       }
       cout<< "decrypted text is: ";
       cout << decrypt;
    return 0;
}
