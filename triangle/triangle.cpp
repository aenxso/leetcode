class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // dynamic programming bottom up
        // the values in the bottom 'row' are the starting points (since we are working from bottom to top) 
        //   so every possible paths starting min path sum starts at each index in triangle[end]
        
        if(triangle.size() == 1) return triangle[0][0];
        vector<int> minPaths(triangle.back());
        
        for(int layer = triangle.size() - 2; layer >= 0; layer--) {
            for(int i = 0; i <= layer; i++) {
                minPaths[i] = min(minPaths[i], minPaths[i + 1]) + triangle[layer][i];
            }
        }
        
        return minPaths[0];
    }
};