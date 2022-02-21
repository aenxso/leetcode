class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's algorithm
        // keep a count and cancel out every occurrence of an element if the next element is different
        // the only element that will still be left by the end is the majority element
        
        int majorityIndex = 0;
        for(int count = 1, i = 1; i < nums.size(); i++) {
            nums[majorityIndex] == nums[i] ? count++ : count--;
            if(count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }
        return nums[majorityIndex];
    }
};