class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sliding window problem
        // create vectors to store frequency of letter appearance in both strings, then compare them in a loop 
        //    while changing window size
        // window size can only be the size of p
        
        int n = s.size(), windowSz = p.size();
        if(n < windowSz) return {}; // can't compare a string that is smaller than the necessary window size
        vector<int> ans, sFreq(26, 0), pFreq(26, 0);
        int right = 0, left = 0;
        
        // for first itr ONLY, fill frequency arrays of both up to the window size
        while(right < windowSz) {
            sFreq[s[right] - 'a'] += 1;
            pFreq[p[right] - 'a'] += 1;
            right++;
        }
        
        right--;
        while(right < n) {
            if(sFreq == pFreq) {            // if frequencies are a match, add to answer
                ans.push_back(left);
            }
            right++;                        // increase window opening by one to the right
            if(right != n) {
                sFreq[s[right] - 'a'] += 1; // adjust frequency of newly added letter by increasing
                sFreq[s[left] - 'a'] -= 1;  // adjust frequency of letter that is to be removed by decreasing
            }
            left++;                         // increase window closing by one to the right (cutting off last letter)
        }
        return ans;
    }
};