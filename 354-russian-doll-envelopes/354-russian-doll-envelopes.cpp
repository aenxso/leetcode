class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort the array to turn it from a 2D array problem to a 1D array problem (becomes longest increasing subsequence)
        // sort by width increasing, and if 2 widths are the same, sort by height decreasing
        //  reason for this is, we want to avoid duplicates and if both are increasing, it will
        //  be considered an increasing subsequence, but ultimately will give the wrong answer because
        //  it has duplicates. Encountering an equal width paired with a smaller height will break that
        //  hence we make a custom comparator function
        // use binary search to avoid TLE
        
        int maxFits = 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(envelopes.size(), 0);
        for(int i = 0; i < envelopes.size(); i++){
            int l = 0, r = maxFits;
			//binary search
            while(l < r){
                int mid = l + (r - l) / 2;
                if(envelopes[i][1] > dp[mid])
                    l = mid + 1;
                else
                    r = mid;
            }
            dp[l] = envelopes[i][1];
            if(l == maxFits) {
                maxFits++;
            }
        }
        
       return maxFits;
    }
    
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
};