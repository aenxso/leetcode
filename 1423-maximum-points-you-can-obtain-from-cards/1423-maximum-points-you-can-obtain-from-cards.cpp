class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // sliding window problem
        // make sure the number of elements outside the window is always k,
        // because we are creating the sum from the k outside elements
        // as the window moves to the right, add on the leftmost element and remove the rightmost element
        //  as they shift with the bounds of the window
        // Google's most asked question of 2021
        
        int n = cardPoints.size(), l = 0, r = n - k, cur = 0, ans = 0;
        for(int i = r; i < n; i++) { // get the current sum from the rightmost k elements
            cur += cardPoints[i];
        }
        ans = cur; // update answer
        
        while(r < n) { // while right window edge is in bounds
            cur += (cardPoints[l] - cardPoints[r]); // add the leftmost element and remove the rightmost -- update cur
            ans = max(cur, ans);
            l++; // increment window edges -- slide window
            r++;
        }
        return ans;
    }
};