#include<bits/stdc++.h>

using namespace std;

struct edge {
    int node;
    int weight;
    edge(int n, int wt){
        node = n;
        weight = wt;
    }
};

void bellManFord(vector<vector<edge>>& adjList, int numOfNodes, int source){
    vector<int> dist(numOfNodes, INT_MAX);
    dist[source] = 0;
    for(int i = 0; i < numOfNodes - 1; ++i) {
        for(int j = 0; j < numOfNodes; ++j) {
            if(dist[j] == INT_MAX)
                continue;
            for(int k = 0; k < adjList[j].size(); ++k) {
                int currNode = adjList[j][k].node;
                int currDist = adjList[j][k].weight + dist[j];
                if(dist[currNode] > currDist)
                    dist[currNode] = currDist;
            }
        }
    }
    for(auto x: dist){
        cout << x << " ";
    }
}

int main(){
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;
    vector<vector<edge>> adjList(numOfNodes);
    while(numOfEdges--){
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        adjList[node1].push_back(edge(node2, weight));
        //adjList[node2].push_back(edge(node1, weight));
    }
    bellManFord(adjList, numOfNodes, 0);
}
