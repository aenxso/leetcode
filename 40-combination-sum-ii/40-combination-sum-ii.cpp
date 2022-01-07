class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        vector<int> comb;
        
        backtrack(nums, ans, comb, target, 0);
        
        return ans;
    }
    
private:
    void backtrack(vector<int> nums, vector<vector<int>>& ans, vector<int>& comb, int target, int begin) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(comb);
        }
        
        for(int i = begin; i < nums.size(); i++) {
            if(i != begin && nums[i] == nums[i - 1]) continue; // if not in first itr AND elements are the same, skip dups
                                                               // opposite would be: if(i == begin || nums[i] != nums[i - 1])
                                                               //   - if it is first itr OR they are not the same
            comb.push_back(nums[i]);
            backtrack(nums, ans, comb, target - nums[i], i + 1);
            comb.pop_back();
        }
    }
};