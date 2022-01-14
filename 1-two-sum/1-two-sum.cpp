class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map; // key = number, value = index;
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(map.find(complement) != map.end()) { // complement found in map - return comp's index (map[complement]) and i
                ans.push_back(map[complement]);
                ans.push_back(i);
                return ans;
            } else {
                map[nums[i]] = i; // complement not found, add to the map
            }
        }
        return ans;
    }
};