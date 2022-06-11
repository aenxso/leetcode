class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // use two pointers
        // since input array is sorted in increasing order, either increase left pointer
        // or decrease right pointer to adjust sum to reach the target
        
        vector<int> ans;
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if(numbers[l] + numbers[r] == target) {
                ans.push_back(l + 1); // add 1 because array is 1-indexed
                ans.push_back(r + 1);
                return ans;
            } else if (numbers[l] + numbers[r] > target) {
                r--;
            } else if(numbers[l] + numbers[r] < target) {
                l++;
            }
        }
        return ans;
    }
};