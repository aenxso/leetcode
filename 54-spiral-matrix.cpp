class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // iterate through a loop for every direction: up down left right
        // decrease the direction int by one after every loop to close it in and create the spiral sequence
        //   and check to make sure we are still in bounds after adjusting.
        // add numbers to ans array as we go along
        
        int n = matrix.size(), m = matrix[0].size();
        int u = 0, d = n - 1, l = 0, r = m - 1, i = 0;
        vector<int> ans(n * m);
        
        while(u <= d && l <= r) {
            // travserse upper row
            for(int col = l; col <= r; col++) {
                ans[i++] = matrix[u][col];
            }
            if(++u > d) break; // close in upper boundary
            
            // traverse last col
            for(int row = u; row <= d; row++) {
                ans[i++] = matrix[row][r];
            }     
            if(--r < l) break; // close in right boundary
            
            // traverse bottom row (going backwards)
            for(int col = r; col >= l; col--) {
                ans[i++] = matrix[d][col];
            }
            if(--d < u) break; // close in lower boundary
            
            // traverse first col (going upwards, which is like backwards, hence row--)
            for(int row = d; row >= u; row--) {
                ans[i++] = matrix[row][l];
            }
            if(l++ > r) break; // close in left boundary
        }
        return ans;
    }
};
