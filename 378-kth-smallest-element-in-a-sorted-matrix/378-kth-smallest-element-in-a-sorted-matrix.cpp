class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n - 1][n - 1];
        while(l < r){
            int mid = l + (r - l)/2;
            int posi = solve(matrix, mid);
            if(posi < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    
private:
    int solve(vector<vector<int>>& matrix, int mid) {
        int count = 0, n = matrix.size(), i = n - 1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] > mid) {
                i--;
            } else {
                count += (i + 1);
                j++;
            }
        }
        return count;
    }
};