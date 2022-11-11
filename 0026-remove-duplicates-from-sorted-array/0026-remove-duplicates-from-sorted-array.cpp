class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) { // compare one element to the one beside it
                i++;                 // move i up by one
                nums[i] = nums[j];   // replace current nums[i] with nums[j] (the next found non dup)
                                     // i is basically overwriting the dups so we have a sequence of unique numbers
            }
        }
        return i + 1; // this will give the number of unique numbers in nums
    }
};