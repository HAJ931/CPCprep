class Solution {
private:
    void floodFill(vector<vector<char>>& grid, int i, int j){
        if(!(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) || grid[i][j] == '0' || grid[i][j] == '2')
            return;
        grid[i][j] = '2';
        floodFill(grid, i + 1, j);
        floodFill(grid, i, j + 1);
        floodFill(grid, i - 1, j);
        floodFill(grid, i, j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        if (!grid.size())
            return 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == '1'){
                    ++num;
                    floodFill(grid, i, j);
                }
            }
        }
        return num;
    }
};
