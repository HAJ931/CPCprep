bool solve(int n, vector<vector<int>>& friends) {
    vector<bool> hasFriend(n, false);
    for(int i = 0; i < friends.size(); ++i){
        if(!hasFriend[friends[i][0]])
            hasFriend[friends[i][0]] = true;
        if(!hasFriend[friends[i][1]])
            hasFriend[friends[i][1]] = true;
    }
    for(int i = 0; i < n; ++i){
        if(!hasFriend[i])
        return false;
    }
    return true;
}
