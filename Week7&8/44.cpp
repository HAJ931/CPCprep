#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define INF INT_MAX

void djikstra(int src, vector<vector<pi>>& adjList){
    int n = adjList.size();
    vector<int> dis(n, INF);
    vector<bool> vis(n, false);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dis[src] = 0;
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        pi curr = pq.top();
        pq.pop();
        int d = curr.first;
        int u = curr.second;
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto x: adjList[u]){
            int v = x.first;
            int wt = x.second;
            if(!vis[v] && dis[v] > d + wt){
                dis[v] = d + wt;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << "Vertex " << i << ": " << dis[i] << "\n";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adjList(n, vector<pi>(0));
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back(make_pair(b, c));
        adjList[b].push_back(make_pair(a, c));
    }
    djikstra(0, adjList);
}
