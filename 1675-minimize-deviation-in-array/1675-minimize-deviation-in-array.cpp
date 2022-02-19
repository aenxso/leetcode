class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // multiply all odd numbers by 2 to make them even
        // find the max/min out of all numbers as this is used to find the min deviation
        // create priority queue (max heap) to store all values
        
        int minDev = INT_MAX, n = nums.size(), mx = INT_MIN, mn = INT_MAX;
        priority_queue<int> pq;
        
        for(int i = 0; i < n; i++) {
            if((nums[i] % 2) != 0) {
                nums[i] *= 2;
            }
            mn = min(mn, nums[i]);
            pq.push(nums[i]);
        }
        
        // add 
        // for(int i = 0; i < n; i++) {
        //     pq.push(nums[i]);
        // }
        mx = pq.top();
        while((pq.top() % 2) == 0) {
            int top = pq.top();
            pq.pop();
            
            minDev = min(minDev, top - mn);
            top /= 2;
            mn = min(mn, top);
            pq.push(top); // push to the top again to continually minimize the max
        }
        
        minDev = min(minDev, pq.top() - mn);
        
        return minDev;
    }
};