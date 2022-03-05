class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ans = 0, prevMax = 0;
        vector<int> freq(10001, 0);
        
        for(int num : nums) {
            freq[num] += 1;
        }
        
        for(int i = 0; i <= 10000; i++) {
            int curMax = max(ans, prevMax + (i * freq[i]));
            prevMax = ans;
            ans = curMax;
        }
        return ans;
    }
};