/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> adjList[N + 1];
    while(M--){
        int A, B;
        cin >> A >> B;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }
    
    int Q;
    cin >> Q;
    while(Q--){
        int A, B, i;
        bool flag = false;
        cin >> A >> B;
        for(i = 0; i < adjList[A].size(); ++i){
            if(adjList[A][i] == B){
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "NO" << endl;
    }
}
