class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        if(nums.size() == 0) return ans;
        
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        subset(nums, ans, sub, 0);
        
        return ans;
    }
    
private:
    void subset(vector<int>& nums, vector<vector<int>>& ans, vector<int>& sub, int n) {
        ans.push_back(sub);
        for(int i = n; i < nums.size(); i++) {
            if(i > n && nums[i] == nums[i - 1]) continue; // skip the duplicates in this case
            sub.push_back(nums[i]);
            subset(nums, ans, sub, i + 1);
            sub.pop_back();
        }
    }
};