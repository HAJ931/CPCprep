class Solution {
#define pi pair<int, int>
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int nr = mat.size(), nc = mat[0].size();
        vector<vector<int>> dis(nr, vector<int>(nc, -1));
        queue <pi> q;
        for(int i = 0; i < nr; ++i){
            for(int j = 0; j < nc; ++j){
                if(mat[i][j] == 0){
                    q.push(make_pair(i, j));
                    dis[i][j] = 0;
                }
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
                if(r >= 0 && c >= 0 && r < nr && c < nc && mat[r][c] == 1 && dis[r][c] == -1){
                    dis[r][c] = dis[i][j] + 1;
                    q.push(make_pair(r, c));
                }
            }
        }
        return dis;
    }
};
