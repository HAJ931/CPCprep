class Solution {
private:
    bool isCycle(int i, vector<vector<int>>& adjList, vector<bool>& vis, vector<bool>& recStack){
        vis[i] = true;
        recStack[i] = true;
        for(auto x: adjList[i]){
            if(!vis[x] && isCycle(x, adjList, vis, recStack))
                return true;
            else if(recStack[x])
                return true;
        }
        recStack[i] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>(0));
        for(auto x: prerequisites){
            adjList[x[0]].push_back(x[1]);
        }
        vector<bool> vis(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for(int i = 0; i < numCourses; ++i){
            if(!vis[i]){
                if(isCycle(i, adjList, vis, recStack))
                    return false;
            }
        }
        return true;
    }
};
