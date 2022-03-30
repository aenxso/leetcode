class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // index = ((m + 1) * (n + 1)) - 1 for 0-indexed
        // index = (m * n) - 1 when using .size()
        // treat it as one long array and perform binary search
        
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = (m * n - 1);
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(matrix[mid / n][mid % n] == target) { // divide row by col.size and mod cols by col.size
                return true;
            } else if(matrix[mid / n][mid % n] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};