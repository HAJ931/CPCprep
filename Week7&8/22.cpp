class Solution {
    void floodFill(vector<vector<char>>& grid, int r, int c, int nRows, int nCols, char oldColor, char newColor){
        if(r >= nRows || r < 0 || c >= nCols || c < 0 || grid[r][c] != oldColor)
            return;
        grid[r][c] = newColor;
        floodFill(grid, r + 1, c, nRows, nCols, oldColor, newColor);
        floodFill(grid, r, c + 1, nRows, nCols, oldColor, newColor);
        floodFill(grid, r - 1, c, nRows, nCols, oldColor, newColor);
        floodFill(grid, r, c - 1, nRows, nCols, oldColor, newColor);
    }
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size() || !board[0].size())
            return;
        int nRows = board.size();
        int nCols = board[0].size();
        for(int j = 0; j < nCols; ++j){
            if(board[0][j] == 'O'){
                floodFill(board, 0, j, nRows, nCols, board[0][j], '?');
            }
            if(board[nRows - 1][j] == 'O'){
                floodFill(board, nRows - 1, j, nRows, nCols, board[nRows - 1][j], '?');
            }
        }
        for(int i = 0; i < nRows; ++i){
            if(board[i][0] == 'O'){
                floodFill(board, i, 0, nRows, nCols, board[i][0], '?');
            }
            if(board[i][nCols - 1] == 'O'){
                floodFill(board, i, nCols - 1, nRows, nCols, board[i][nCols - 1], '?');
            }
        }
        for(int i = 0; i < nRows; ++i){
            for(int j = 0; j < nCols; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '?'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
