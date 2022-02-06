class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, num = nums[0]; // count keeps track of how many times we've seen num
        
        for(int i = 0; i < nums.size() - 1; i++) {     
            if(num == nums[i + 1]) {
                count++;
                if(count >= 2) {
                    int j = i; // create separate variable for while loop, otherwise main loop itrs get messed up
                    while(num == nums[j] && j < nums.size()) {
                        nums.erase(nums.begin() + j);
                        j++;
                    }
                    i--;
                }
            } else {
                count = 0; // reset count if num is different
                num = nums[i + 1];
            }
        }
        return nums.size();
    }
};