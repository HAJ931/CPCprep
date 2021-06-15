class Solution {
#define pi pair<int, int>
public:
    int maxDistance(vector<vector<int>>& grid) {
        int nr = grid.size(), nc = grid[0].size();
        vector<vector<int>> dis(nr, vector<int>(nr, -1));
        queue <pi> q;
        bool flag1 = false, flag2 = false;
        for(int i = 0; i < nr; ++i){
            for(int j = 0; j < nc; ++j){
                if(grid[i][j] == 1){
                    dis[i][j] = 0;
                    q.push(make_pair(i, j));
                    if(!flag1) 
                        flag1 = true;
                }
                if(grid[i][j] == 0)
                    if(!flag2)
                        flag2 = true;
            }
        }
        if(!flag1 || !flag2)
            return -1;
        vector<int> diff = {-1, 0, 1, 0, -1};
        int max = INT_MIN;
        while(!q.empty()){
            pi curr = q.front();
            int i = curr.first;
            int j = curr.second;
            q.pop();
            for(int dir = 0; dir < diff.size() - 1; ++dir){
                int r = i + diff[dir];
                int c = j + diff[dir + 1];
                if(r >= 0 && c >= 0 && r < nr && c < nc && grid[r][c] == 0 && dis[r][c] == -1){
                    dis[r][c] = dis[i][j] + 1;
                    if(max < dis[r][c])
                        max = dis[r][c];
                    q.push(make_pair(r, c));
                }
            }
        }
        return max;
    }
};
