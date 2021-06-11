#define WHITE 0
#define GRAY 1
#define BLACK 2

class Solution {
private:
    bool noCycle(int i, vector<vector<int>>& adjList, vector<int>& colour){
        if(colour[i])
            return colour[i] == 2;
        colour[i] = GRAY;
        for(auto x: adjList[i]){
            if(colour[x] == BLACK)
                continue;
            if(colour[x] == GRAY || !noCycle(x, adjList, colour))
                return false;
        }
        colour[i] = BLACK;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), 0);
        vector<int> res;
        for(int i = 0; i < graph.size(); ++i){
            if(noCycle(i, graph, colour))
                res.push_back(i);
        }
        return res;
    }
};
