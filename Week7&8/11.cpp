class Solution {
private:
    void DFS(int city, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[city] = true;
        for(int city2 = 0; city2 < isConnected[city].size(); ++city2){
            if(isConnected[city][city2] && !visited[city2])
                DFS(city2, isConnected, visited);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfProv = 0;
        vector<bool> visited(isConnected.size(), false);
        for(int i = 0; i < visited.size(); ++i){
            if(!visited[i]){
                ++numOfProv;
                DFS(i, isConnected, visited);
            }
        }
        return numOfProv;
    }
};
