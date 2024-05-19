#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string t[5] = {"t0", "t1", "t2", "t3", "t4"};

vector<string> safe;

int allocation[5][3] = {{0, 1, 0}, {3, 0, 2}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
int need[5][3] = {{7, 4, 3}, {0, 2, 0}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1}};
int available[3] = {2, 3, 0};
bool finished[5] = {false, false, false, false, false};  

int main() {
    int safeNum = 0;
    bool found;
    
    while (safeNum < 5) {
        found = false;
        
        for (int i = 0; i < 5; i++) {
            if (!finished[i] && need[i][0] <= available[0] && need[i][1] <= available[1] && need[i][2] <= available[2]) {
                
                available[0] += allocation[i][0];
                available[1] += allocation[i][1];
                available[2] += allocation[i][2];
                
                safe.push_back(t[i]);
                finished[i] = true; 
                safeNum++;
                found = true;
            }
        }
        
        if (!found) {
            cout<<"No process in the safe sequence"<<endl;
            break;
        }
    }

    if (safeNum < 5) {
        cout << "Not in a safe sequence" << endl;
    } else {
        cout<<"The safe sequence is: ";
        for (int i = 0; i < 5; i++) {
            cout << safe[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
