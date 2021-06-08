class Solution {
private:
    void floodfill(vector<vector<int>>& image, int sr, int sc, int newColour, int oldColour){
        if(image[sr][sc] != oldColour)
            return;
        image[sr][sc] = newColour;
        if(sr < image.size() - 1) 
            floodfill(image, sr + 1, sc, newColour, oldColour);
        if(sc < image[0].size() - 1)
            floodfill(image, sr, sc + 1, newColour, oldColour);
        if(sc > 0)
            floodfill(image, sr, sc - 1, newColour, oldColour);
        if(sr > 0)
            floodfill(image, sr - 1, sc, newColour, oldColour);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        floodfill(image, sr, sc, newColor, image[sr][sc]);
            return image;
    }
};
