class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i : nums) {
            result = result ^ i; // XOR order doesn't matter, so XORing al elements together causes duplicates 
                                 // to cancel each other out (become 0), and single number is left
            
        }
        return result;
    }
};