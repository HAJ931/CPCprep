void floodfill(vector<vector<string>>& m, int r, int c, string target, string old){
    if(r < 0 || r >= m.size() || c < 0 || c >= m[0].size() || m[r][c] != old || m[r][c] == target)
    return;
    m[r][c] = target;
    if(r < m.size() - 1)
        floodfill(m, r + 1, c, target, old);
    if(c > 0)
        floodfill(m, r, c - 1, target, old);
    if(r > 0)
        floodfill(m, r - 1, c, target, old);
    if(c < m[r].size() - 1)
        floodfill(m, r, c + 1, target, old);
}

vector<vector<string>> solve(vector<vector<string>>& matrix, int r, int c, string target) {
    string old = matrix[r][c];
    floodfill(matrix, r, c, target, old);
    return matrix;
}
