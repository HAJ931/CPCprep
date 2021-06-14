#include<bits/stdc++.h>
using namespace std;

void topoSortUtil(int i, vector<vector<int>>& adjList, vector<bool>& vis, stack<int>& s){
    vis[i] = true;
    for(auto x: adjList[i]){
        if(!vis[x])
            topoSortUtil(x, adjList, vis, s);
    }
    s.push(i);
}

vector<int> topoSort(vector<vector<int>>& adjList){
    vector<bool> vis(adjList.size(), false);
    stack<int> s;
    for(int i = 0; i < adjList.size(); ++i){
        if(!vis[i]){
            topoSortUtil(i, adjList, vis, s);
        }
    }
    vector<int> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

void additionalEdges(vector<vector<int>>& adjList, vector<int>& res){
    cout << "Old Adjacency List: " << endl;
    for(int i = 0; i < adjList.size(); ++i){
        cout << i << ": ";
        for(auto x: adjList[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < res.size(); ++i){
        vector<bool> pres(res.size(), false);
        for(auto x: adjList[res[i]]){
            pres[x] = true;
        }
        for(int j = i + 1; j < res.size(); ++j){
            if(!pres[res[j]])
                adjList[res[i]].push_back(res[j]);
        }
    }
    cout << "Updated Adjacency List: " << endl;
    for(int i = 0; i < adjList.size(); ++i){
        cout << i << ": ";
        for(auto x: adjList[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>(0));
    while(m--){
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
    }
    vector<int> res = topoSort(adjList);
    cout << "Topological Order: ";
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    additionalEdges(adjList, res);
}
