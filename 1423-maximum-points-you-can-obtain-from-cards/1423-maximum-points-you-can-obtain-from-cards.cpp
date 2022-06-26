class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), l = 0, r = n - k, cur = 0, ans = 0;
        for(int i = r; i < n; i++) {
            cur += cardPoints[i];
        }
        ans = cur;
        
        while(r < n) {
            cur += (cardPoints[l] - cardPoints[r]);
            ans = max(cur, ans);
            l++;
            r++;
        }
        return ans;
    }
};