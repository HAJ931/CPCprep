#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>& adjList, vector<bool>& visited){
    stack<int> s;
    s.push(node);
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        if(visited[curr])
            continue;
        
        visited[curr] = true;
        cout << curr;
        for(auto newNode: adjList[curr]){
            if(!visited[newNode])
                s.push(newNode);
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adjList(N, vector<int>(0));
    vector<bool> visited(N, false);
    
    while(M--){
        int A, B;
        cin >> A >> B;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }
    
    DFS(0, adjList, visited);
}
