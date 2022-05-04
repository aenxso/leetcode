class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // one pass
        // time: O(N) space: O(N)
        // use a map to store the nums encountered, if a complement of the current number is found
        //   increase the answer and 'take it out' of the array by reducing the frequency in the map
        
        unordered_map<int, int> freq;
        int ans = 0;
        
        for(auto cur : nums) {
            int complement = k - cur;
            if(freq[complement] > 0) {
                ans++;
                freq[complement]--;
            } else {
                freq[cur]++;
            }
        }
        return ans;
    }
};