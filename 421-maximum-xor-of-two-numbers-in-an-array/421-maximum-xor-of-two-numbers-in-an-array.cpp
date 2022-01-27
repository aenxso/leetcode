class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> check;
        for(int i = 31; i >= 0; i--) {
            ans <<= 1;
            for (auto n : nums) {
                check.insert(n >> i);
            }
            for(auto p : check) {
                if(check.find((ans ^ 1) ^ p) != check.end()) {
                    ans++;
                    break;
                }
            }
            check.clear();
        }
        return ans;
    }
};