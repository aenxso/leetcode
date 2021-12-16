class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        /* 
            - basically like the bucket tool in a photo editing program
            - first check if there is any work to be done - is newColor different than image[sr][sc]?
            - use DFS recursive call 
        */
        
        if(newColor == image[sr][sc]) return image; // new and current are the same -- no work to be done
        
        color_fill(image, sr, sc, image[sr][sc], newColor);
        return image;
       
    }

private:
    void color_fill(vector<vector<int>>& image, int i, int j, int color, int newColor) {
        // base cases - in bounds left/right, top/bottom, color is different
        
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != color) {
            return;
        }
        
        image[i][j] = newColor;
        
        color_fill(image, i + 1, j, color, newColor); // move down
        color_fill(image, i - 1, j, color, newColor); // move up
        color_fill(image, i, j + 1, color, newColor); // move right
        color_fill(image, i, j - 1, color, newColor); // move left
    }
};