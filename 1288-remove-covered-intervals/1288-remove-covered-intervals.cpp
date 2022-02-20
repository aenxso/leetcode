class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       // sort intervals and keep track of previous left and right bounds
       // if interval[0] > left && right < interval[1] then a new larger (uncovered) interval has been found
        
        int ans = 0, left = -1, right = -1;
        sort(intervals.begin(), intervals.end());
        
        for(auto &interval : intervals) {
            if(interval[0] > left && right < interval[1]) {
                left = interval[0];
                ans++;
            }
            right = max(right, interval[1]);
        }
        return ans;
    }
};