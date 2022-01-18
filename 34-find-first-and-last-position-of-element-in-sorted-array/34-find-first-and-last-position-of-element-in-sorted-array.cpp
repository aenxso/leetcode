class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, up, down;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                int up = mid, down = mid;
                while(up < n - 1) {
                    if(nums[up + 1] == target) {
                        up++;
                    } else {
                        break;
                    }
                }
                while(down > 0) {
                    if(nums[down - 1] == target) {
                        down--;
                    } else {
                        break;
                    }
                }
                return {down, up};
            } else if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return {-1, -1};
    }
};