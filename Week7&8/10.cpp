void DFS(int f, vector<vector<int>>& friends, vector<bool>& visited){
    visited[f] = true;
    for(auto fr: friends[f]){
        if(!visited[fr])
            DFS(fr, friends, visited);
    }
}

int solve(vector<vector<int>>& friends) {
    vector<bool> visited(friends.size(), false);
    int numOfGroups = 0;
    for(int i = 0; i < visited.size(); ++i){
        if(!visited[i]){
            ++numOfGroups;
            DFS(i, friends, visited);
        }
    }
    return numOfGroups;
}
