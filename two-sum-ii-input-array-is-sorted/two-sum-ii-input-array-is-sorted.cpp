class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            if(numbers[left] + numbers[right] == target) {
                ans[0] = ++left;
                ans[1] = ++right;
                return ans;
            } else if(numbers[left] + numbers[right] > target) {
                right--;
            } else if(numbers[left] + numbers[right] < target) {
                left++;
            }
        }
        return ans;
    }
};