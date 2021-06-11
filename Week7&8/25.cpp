bool DFS(int i, vector<vector<int>>& adjList, vector<bool>& vis, vector<bool>& recStack){
    vis[i] = true;
    recStack[i] = true;
    for(auto x: adjList[i]){
        if(!vis[x] && DFS(x, adjList, vis, recStack))
            return true;
        else if(recStack[x])
            return true;
    }
    recStack[i] = false;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adjList(A + 1, vector<int>(0));
    for(auto x: B){
        int u = x[0];
        int v = x[1];
        adjList[u].push_back(v);
    }
    vector<bool> vis(A + 1, false);
    vector<bool> recStack(A + 1, false);
    for(int i = 1; i <= A; ++i){
        if(!vis[i]){
            if(DFS(i, adjList, vis, recStack))
                return 1;
        }
    }
    return 0;
}
