#include<bits/stdc++.h>

using namespace std;

//Floyd Warshall finds the shortest distance between every pair of vertices

void floydWarshall(vector<vector<int>>& weight, int numOfNodes) {
    vector<vector<int>> dist(numOfNodes, vector<int>(numOfNodes, INT_MAX));
    
    for(int i = 0; i < dist.size(); ++i) {
        for(int j = 0; j < dist[i].size(); ++j) {
            dist[i][j] = i == j ? 0: (weight[i][j] ? weight[i][j]: dist[i][j]);
        }
    }
    
    for(int k = 0; k < numOfNodes; ++k) {
        for(int i = 0; i < numOfNodes; ++i) {
            for(int j = 0; j < numOfNodes; ++j) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
    
    for(int i = 0; i < numOfNodes; ++i) {
        for(int j = 0; j < numOfNodes; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;
    vector<vector<int>> adjMatrix(numOfNodes, vector<int>(numOfNodes, 0));
    while(numOfEdges--){
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        adjMatrix[node1][node2] = weight;
        //adjMatrix[node2][node1] = weight;
    }
    floydWarshall(adjMatrix, numOfNodes);
}
