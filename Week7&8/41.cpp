class Solution {
#define pi pair<int, int>
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int nr = grid.size(), nc = grid[0].size();
        vector<vector<int>>dis(nr, vector<int>(nc, -1));
        if(grid[0][0] != 0 || grid[nr - 1][nc - 1] != 0)
            return -1;
        dis[0][0] = 1;
        queue <pi> q;
        q.push(make_pair(0, 0));
        vector<vector<int>> diff = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
;        while(!q.empty()){
            pi curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            for(int dir = 0; dir < diff.size(); ++dir){
                int r = i + diff[dir][0];
                int c = j + diff[dir][1];
                if(r >= 0 && c >= 0 && r < nr && c < nc && dis[r][c] == -1 && grid[r][c] == 0){
                    dis[r][c] = dis[i][j] + 1;
                    q.push(make_pair(r, c));
                }
            }
        }
        return dis[nr - 1][nc - 1];
    }
};
