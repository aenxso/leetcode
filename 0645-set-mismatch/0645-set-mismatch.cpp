class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // create a frequency vector to count number of times each number has occurred in nums
        // if >1, we found the first part of the answer
        // if == 0, we found the second part of the answer
        
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans;

        for(auto i : nums) {
            freq[i]++;
            if (freq[i] > 1) ans.push_back(i);
        }

        for(int i = 1; i < n + 1; i++) {
            if (freq[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};