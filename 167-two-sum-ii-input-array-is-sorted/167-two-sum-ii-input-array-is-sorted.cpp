class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // two pointer method. Adjust pointer position based on calculated sum vs. target
        vector<int> ans;
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if((numbers[l] + numbers[r]) == target) {
                ans.push_back(l + 1);   // add one because indices are 1-indexed
                ans.push_back(r + 1);
                return ans;
            } else if (numbers[l] + numbers[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};