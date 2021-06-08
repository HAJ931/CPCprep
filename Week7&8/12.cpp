class Solution {
private:
    void addEdge(int a, int b, vector<vector<int>>& adjList){
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    void DFS(int comp, vector<vector<int>>& adjList, vector<bool>& visited){
        visited[comp] = true;
        for(auto comp2: adjList[comp]){
            if(!visited[comp2])
                DFS(comp2, adjList, visited);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adjList(n, vector<int>(0));
        for(int i = 0; i < connections.size(); ++i){
            addEdge(connections[i][0], connections[i][1], adjList);
        }
        vector<bool> visited(n, false);
        int numOfGroups = 0;
        for(int i = 0; i < visited.size(); ++i){
            if(!visited[i]){
                ++numOfGroups;
                DFS(i, adjList, visited);
            }
        }
        return numOfGroups - 1;
    }
};
