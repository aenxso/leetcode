class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result(nums.size());
        int front = 0, end = nums.size()-1;
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] & 1) && end >= front) {
                result[end] = nums[i];
                end--;
            } 
            if(!(nums[i] & 1) && front <= end) {
                result[front] = nums[i];
                front++;
            }
        }
        return result;
    }
};
