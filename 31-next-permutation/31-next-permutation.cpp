class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the section of nums that is strictly decreasing as this indicates the area that is on its
        // final permutation. Then find the index RIGHT BEFORE that, and the element in the decreasing section
        // that is smallest in that section but still greater than nums[i], as this is the next element that will 
        // take nums[i]'s spot in the next permutation. Then reverse the decreasing section as without reversing it,
        // it will be in the form of its final permutation. Reversing it will put it in its first run which is what we want
        
        int i = nums.size() - 2; // get index of the second last element in the array
        
        while(i >= 0 && nums[i + 1] <= nums[i]) { // find the position in current permutation where the sequence becomes strictly decreasing
            i--;
        }
        
        /*
            if i isn't the first element we need to find smallest element that is greater than nums[i].
            if i had been the first element, we could skip and just reverse the whole arr since it would be on 
              its last permutation as everything would be decreasing
        */
        if(i >= 0) { 
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // reverse decreasing section. i + 1 because i sits right before the decreasing section
        reverse(nums.begin() + i + 1, nums.end());
    }
};