class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // same logic as finding a loop in a linked list
        // instead of going to the next element in line, pointer uses values as indexes
        
        if(nums.size() < 2) return -1;
        
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};