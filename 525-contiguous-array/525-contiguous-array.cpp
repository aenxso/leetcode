class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // use a prefix sum, += 1 if nums[i] == 1, -= 1 if nums[i] == 0
        // add the sum/index pair to hashmap to keep track of previously found sums and their index
        // if a the same sum is encountered again, then there is an equal amount of 1's and 0's in the space i - map[sum]
        
        int longest = 0, sum = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            
            if(map.find(sum) != map.end()) {
                longest = max(longest, i - map[sum]);
            } else {
                map[sum] = i;
            }
        }
        return longest;
    }
};