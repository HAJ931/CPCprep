class Solution {
    private:
    struct edge{
        int dest;
        int time;
        edge(int d, int t){
            dest = d;
            time = t;
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<edge>> adjList(n + 1);
        vector<int> dist(n + 1, INT_MAX);
        
        dist[k] = 0;
        
        for(auto time: times) {
            int node1 = time[0];
            int node2 = time[1];
            int weight = time[2];
            adjList[node1].push_back(edge(node2, weight));
        }
        
        for(int i = 0; i < n - 1; ++i) {
            bool flag = false;
            for(int j = 1; j <= n; ++j) {
                if(dist[j] == INT_MAX)
                    continue;
                for(int k = 0; k < adjList[j].size(); ++k) {
                    int destNode = adjList[j][k].dest;
                    int newTime = adjList[j][k].time + dist[j];
                    if(newTime < dist[destNode]){
                        dist[destNode] = newTime;
                        flag = true;
                    }
                }
            }
            if(!flag)
                break;
        }
        
        int max = -1;
        
        for(int i = 1; i < dist.size(); ++i){
            if(dist[i] == INT_MAX){
                max = -1;
                break;
            }
            max = dist[i] > max ? dist[i]: max;
        }
        return max;
    }
};
