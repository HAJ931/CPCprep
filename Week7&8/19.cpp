class Solution {
private:
    bool DFS(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        if(grid[i][j] == 0){
            grid[i][j] = 2;
            bool b1 = DFS(grid, i + 1, j);
            bool b2 = DFS(grid, i, j - 1);
            bool b3 = DFS(grid, i - 1, j);
            bool b4 = DFS(grid, i, j + 1);
            return b1 && b2 && b3 && b4;
        }
        return true;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        int num = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 0){
                    if(DFS(grid, i, j))
                        ++num;
                }
            }
        }
        return num;
    }
};
