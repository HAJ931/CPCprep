class Solution {
private: 
    void DFS(vector<vector<int>>& grid, int i, int j, int& peri){
        if(!(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) || !grid[i][j])          {
            ++peri;
            return;
        }
        if(grid[i][j] == 2)
            return;
        grid[i][j] = 2;
        DFS(grid, i - 1, j, peri);
        DFS(grid, i, j + 1, peri);
        DFS(grid, i + 1, j, peri);
        DFS(grid, i, j - 1, peri);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0, inI = -1, inJ = -1;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j]){
                    inI = i, inJ = j;
                    break;
                }
            }
        }
        if(inI == -1 && inJ == -1)
            return 0;
        DFS(grid, inI, inJ, peri);
        return peri;
    }
};
