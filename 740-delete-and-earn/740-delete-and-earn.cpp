class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // similar to house robber
        // use a frequency vector to store occurrences of numbers in nums
        // if we pick one number, i, we can safely pick all occurrence of that number and
        //  add the points
        // now. we cannot pick i-1 but we can pick i-2 which we call prevMax
        
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