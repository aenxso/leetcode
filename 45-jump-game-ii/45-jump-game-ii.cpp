class Solution {
public:
    int jump(vector<int>& nums) {
        // sort of like a BFS on a 1D array
        // create a 'window' using two pointers, rightmost pointer is set to the farther we can jump from current window
        // each window represents one jump
        
        if(nums.size() == 1) return 0;
        
        int left = 0, right = 0, ans = 0, target = nums.size() - 1;
        
        while(right < nums.size()) {
            ans++;
            int farthest = 0;
            for(int i = left; i <= right; i++) { // iterating through window
                if(i + nums[i] >= target) return ans; // return if we've reach target
                farthest = max(farthest, i + nums[i]);
            }
            left = right + 1; // increment left pointer to be right + 1 -- one step over from right's old pos
            right = farthest; // right pointer incrememnts to further possible jump position
        }
        return ans;
    }
};