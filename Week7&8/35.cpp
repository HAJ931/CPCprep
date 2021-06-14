class Solution {
#define WHITE 0
#define GRAY 1
#define BLACK 2
private:
    bool isCycle(int i, vector<vector<int>>& adjList, vector<bool>& vis, vector<bool>& recStack){
        vis[i] = true;
        recStack[i] = true;
        for(auto x: adjList[i]){
            if(!vis[x] && isCycle(x, adjList, vis, recStack)){
               return true;
            }
            else if(recStack[x])
                return true;
        }
        recStack[i] = false;
        return false;
    }
private:
    void topoSort(int course, vector<vector<int>>& adjList, vector<bool>& vis, stack<int>& s){
        vis[course] = true;
        for(auto x: adjList[course]){
            if(!vis[x])
                topoSort(x, adjList, vis, s);
        }
        s.push(course);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<vector<int>> adjList(numCourses, vector<int>(0));
        for(int i = 0; i < prerequisites.size(); ++i){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> recStack(numCourses, false);
        for(int i = 0; i < numCourses; ++i){
            if(!vis[i] && isCycle(i, adjList, vis, recStack))
                return {};
        }
        for(int i = 0; i < numCourses; ++i){
            vis[i] = false;
        }
        stack<int> s;
        for(int i = 0; i < numCourses; ++i){
            if(!vis[i])
                topoSort(i, adjList, vis, s);
        }
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};
