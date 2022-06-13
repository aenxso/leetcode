class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // bottom up dynamic programming
        // start from the bottom layer and work our way up while keeping track of the minimum 
        //  path in a dp array. Every element in the bottom row of the triangle (triangle[end]) will be a 
        //  new starting point on the path, so we will find the value from each possible end point
        
        if(triangle.size() == 0) return 0;
        if(triangle.size() == 1) return triangle[0][0];
        vector<int> minPaths(triangle.back()); // .back() returns a reference to the last element of the vector (opposite of front)
        
        for(int layer = triangle.size() - 2; layer >= 0; layer--) { // traverse the layers/rows of triangle
            for(int i = 0; i <= layer; i++) { // traverse every element in that layer/row
                minPaths[i] = min(minPaths[i], minPaths[i + 1]) + triangle[layer][i]; // take previous sum or new one and add new element
            }
        }
        return minPaths[0];
    }
};