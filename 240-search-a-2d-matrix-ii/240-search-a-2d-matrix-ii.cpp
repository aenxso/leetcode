class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int n = mat.size(), m = mat[0].size(), i = n - 1, j = 0;
        
        while (i >= 0 && j < m) {
            if(mat[i][j] == target) {
                return true;
            } else if(mat[i][j] < target) {
                j++;
            } else {
                i--;
            }
        }
            
        return false;
    }
};