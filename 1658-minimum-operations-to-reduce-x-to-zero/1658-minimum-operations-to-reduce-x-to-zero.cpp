class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // find a window of the longest length which has a sum equal to (sum - x)
        // when such a window is found, all the elements outside this window will sum 
        //   to x and the number of operations will be equal to their count
        
        int n = nums.size(), sum = 0, ans = 1000000;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i]; // create sum of all numbers in array
        }
        
        if(sum < x) return -1; // if all element don't even add up to x, then no solution is possible
        
        int l = 0, r = 0, windowSum = 0;
        
        while(r < n){            
            windowSum += nums[r];            
            while(windowSum > (sum - x)){
                windowSum -= nums[l]; // reducing window size
                l++;
            }            
            if(windowSum == (sum - x)){
                ans = min(ans, n - (r - l + 1));
            }            
            r++;            
        }
		
        return (ans == 1000000 ? -1 : ans);
        
    }
};