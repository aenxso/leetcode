class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        if(nums.size() == 0) return ans;
        
        subset(ans, nums, sub, 0);
        
        return ans;
    }
    
private:
    void subset(vector<vector<int>>& ans, vector<int>& nums, vector<int>& sub, int n) {
        ans.push_back(sub);
        for(int i = n; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            subset(ans, nums, sub, i + 1);
            sub.pop_back();
        }
    }
};

/*
    Pick a starting point.
    while(Problem is not solved)
        For each path from the starting point.
            check if selected path is safe, if yes select it
            and make recursive call to rest of the problem
            before which undo the current move.
        End For
    If none of the move works out, return false, NO SOLUTON.

*/