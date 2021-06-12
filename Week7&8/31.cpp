#include<bits/stdc++.h>
using namespace std;

void topoSortUtil(vector<vector<int>>& adjList, vector<bool>& vis, vector<int>& inDeg, vector<int>& res){
    bool flag = false;
    for(int i = 0; i < adjList.size(); ++i){
        if(!inDeg[i] && !vis[i]){
            for(auto x: adjList[i])
                --inDeg[x];
            vis[i] = true;
            res.push_back(i);
            topoSortUtil(adjList, vis, inDeg, res);
            
            flag = true;
            res.erase(res.end() - 1);
            for(auto x: adjList[i])
                ++inDeg[x];
            vis[i] = false;
        }
    }
    if(!flag){
        for(int i = 0; i < res.size(); ++i){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

void topoSort(int V, vector<vector<int>>& adjList){
    vector<bool> vis(V, false);
    vector<int> inDeg(V, 0);
    for(int i = 0; i < V; ++i){
        for(auto x: adjList[i]){
            ++inDeg[x];
        }
    }
    vector<int> res;
    topoSortUtil(adjList, vis, inDeg, res);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>(0));
    while(m--){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    topoSort(n, adjList);
}
