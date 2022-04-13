class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;
        int num = 1;
        
        while(rowStart <= rowEnd && colStart <= colEnd) {
            
            // first row forward
            for(int i = colStart; i <= colEnd; i++) {
                ans[rowStart][i] = num++;
            }
            rowStart++;
            
            // last column downward
            for(int i = rowStart; i <= rowEnd; i++) {
                ans[i][rowEnd] = num++;
            }
            colEnd--;
            
            // last row backwards
            for(int i = colEnd; i >= colStart; i--) {
                ans[rowEnd][i] = num++;
            }
            rowEnd--;
            
            // first column upwards
            for(int i = rowEnd; i >= rowStart; i--) {
                ans[i][colStart] = num++;
            }
            colStart++;
        }
        return ans;
    }
};