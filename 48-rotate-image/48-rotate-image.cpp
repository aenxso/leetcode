class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), a = 0, b = (n - 1);
        while(a < b) {
            for(int i = 0; i < (b - a); i++) {
                swap(matrix[a][a + i], matrix[a + i][b]); // 1st iter, swap top left w/ top right
                swap(matrix[a][a + i], matrix[b][b - i]); // 1st iter, swap top left w/ bottom right
                swap(matrix[a][a + i], matrix[b - i][a]); // 1st iter, swap top left w/ bottom left
            }
            a++;
            b--;
        }
    }
};