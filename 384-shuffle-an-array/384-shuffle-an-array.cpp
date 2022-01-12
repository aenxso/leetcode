class Solution {
public:
    vector<int> original;
    
    Solution(vector<int>& nums) {
        srand(time(NULL));
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = original;
        
        int j;
        for(int i = original.size() - 1; i > 0; i--) {
            j = rand() % (i + 1);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */