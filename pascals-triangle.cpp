class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1, 1)); //for each row, create i+1 size vector full of 1's
            for(int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]; //fill each individual cell with the two nums above it from the previous row. Leftmost+rightmost are already filled with '1'
            }
        }
        return ans;
    }
};
