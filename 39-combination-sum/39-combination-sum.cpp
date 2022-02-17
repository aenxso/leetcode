class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo; // vector to store possible combinations of numbers
        int sum = 0;
        backtrack(candidates, ans, combo, target, 0, sum);
        
        return ans;
    }
    
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& combo, int target, int begin, int sum) {
        // keep track of accumulating sum
        // when it reaches target perfectly, we have a valid combination
        // if it goes over target, there is no combination - return
        
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(combo);
        }
        
        for(int i = begin; i < nums.size(); i++) {
            combo.push_back(nums[i]);
            backtrack(nums, ans, combo, target, i, sum + nums[i]);
            combo.pop_back();
        }
    }
};