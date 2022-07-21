bool isValid(int row, int col, int nRows, int nCols) {
    if(row < 0 || row >= nRows || col < 0 || col >= nCols)
        return false;
    return true;
}

int solve(vector<vector<int>>& matrix) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(nRows, vector<int>(nCols, -1));
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] == 0){
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    if(!q.size() || q.size() == nRows * nCols)
        return -1;
    while(q.size()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        vector<int> dir = {-1, 0, 1, 0, -1};
        for(int i = 0; i < dir.size(); ++i){
            int newRow = row + dir[i];
            int newCol = col + dir[i + 1];
            if(isValid(newRow, newCol, nRows, nCols) && dist[newRow][newCol] == -1){
                dist[newRow][newCol] = dist[row][col] + 1;
                q.push({newRow, newCol});
            }
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < dist.size(); ++i){
        for(int j = 0; j < dist[0].size(); ++j){
            if(dist[i][j] == -1)
                return -1;
            if(dist[i][j] > max)
                max = dist[i][j];
        }
    }
    return max;
}
