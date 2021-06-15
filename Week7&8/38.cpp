#define pi pair<int, int>

int solve(vector<vector<int>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int nr = matrix.size(), nc = matrix[0].size();
    queue<pi> q;
    vector<vector<int>> dis(nr, vector<int>(nc, -1));
    for(int i = 0; i < nr; ++i){
        for(int j = 0; j < nc; ++j){
            if(matrix[i][j] == 2){
                q.push(make_pair(i, j));
                dis[i][j] = 0;
            }
            if(matrix[i][j] == 0)
                dis[i][j] = 0;
        }
    }
    vector<int> diff = {-1, 0, 1, 0, -1};
    while(!q.empty()){
        pi curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;
        for(int dir = 0; dir < diff.size() - 1; ++dir){
            int r = i + diff[dir];
            int c = j + diff[dir + 1];
            if(r >= 0 && c >= 0 && r < nr && c < nc && matrix[r][c] == 1 && dis[r][c] == -1){
                q.push(make_pair(r, c));
                dis[r][c] = dis[i][j] + 1;
            }
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < nr; ++i){
        for(int j = 0; j < nc; ++j){
            if(dis[i][j] == -1 && matrix[i][j] == 1)
                return -1;
            if(dis[i][j] > max)
                max = dis[i][j];
        }
    }
    return max;
}
