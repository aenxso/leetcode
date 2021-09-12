class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++) { //if missing number is before end of arr
            if(nums[i] != i) {
                return i;
            }
        }
        return nums[size - 1] + 1; //if last number is the missing number
    }
};
