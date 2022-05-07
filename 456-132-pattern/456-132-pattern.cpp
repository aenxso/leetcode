class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // use a stack and go through the array from right to left
        // we are looking for the "32" sequence, and then finding a suitable "1"
        // add nums to the stack until something less than the latest num is added -- then pop everything less than off the stack
        //   and the max becomes the value for "2" (always the most recently popped num from the stack)
        // continue going through the array until a number smaller than "2" is found -- this implies a sequence exists
        
        stack<int> stk;
        int s2 = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--) { // start at end of array
            if(nums[i] < s2) { // sequence exists
                return true;
            } else {
                while(!stk.empty() && stk.top() < nums[i]) { // pop numbers smaller than current number
                    s2 = stk.top(); // s2 will always be the biggest encountered number other than current num (nums[i])
                    stk.pop();
                }
            }
            stk.push(nums[i]); // otherwise just add num to stack
        }
        return false; // no sequence was found
    }
};