class Solution {
private:
    void findArea(vector<vector<int>>& grid, int i, int j, int& sum){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == 2)
            return;
        ++sum;
        grid[i][j] = 2;
        findArea(grid, i -1, j, sum);
        findArea(grid, i, j + 1, sum);
        findArea(grid, i + 1, j, sum);
        findArea(grid, i, j - 1, sum);
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0, maxArea = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 1){
                    area = 0;
                    findArea(grid, i, j, area);
                    if(area > maxArea)
                        maxArea = area;
                }
            }
        }
        return maxArea;
    }
};
