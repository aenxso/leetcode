class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // choice, constraint, goal
        // sort to clear dups
        
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        
        perm(nums, ans, 0);
        
        return ans;
    }
    
private:
    void perm(vector<int>& nums, vector<vector<int>>& ans, int begin) {
        if(begin >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        // explore all possibilities 
        for(int i = begin; i < nums.size(); i++) {
           if(i > begin && nums[begin] == nums[i]) continue; // skip duplicates // i > begin bcuz it could be at 0 and begin at 2 - don't want to repeat checks
            swap(nums[begin], nums[i]);
            perm(nums, ans, begin + 1);
        }
        
        // reverse the mixed up values back to sorted order
        for(int i = nums.size() - 1; i > begin; i--) {
            swap(nums[begin], nums[i]);
        }
    }
};