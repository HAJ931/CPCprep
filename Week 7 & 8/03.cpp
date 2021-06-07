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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adjMatrix(N + 1, vector<int>(N + 1, 0));
    while(M--){
        int A, B;
        cin >> A >> B;
        if(A <= N && B <= N){
            adjMatrix[A][B] += 1;
            if(A != B)
                adjMatrix[B][A] += 1;
        }
    }
    
    int Q;
    cin >> Q;
    while(Q--){
        int A, B, i;
        cin >> A >> B;
        if(adjMatrix[A][B] > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
