class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // create window of size p
        // two pointers to maintain window size
        
        if(s.size() < p.size()) return {};
        
        vector<int> ans, freqS(26, 0), freqP(26, 0);
        int l = 0, r = 0;
        
        // for ONLY the first window of size p
        int window = p.size();
        while(r < window) {
            
            freqS[s[r] - 'a'] += 1;
            freqP[p[r] - 'a'] += 1;
            r++;
        }
        
        r--;
        while(r < s.size()) {
            
            if(freqS == freqP) ans.push_back(l);
            r++;
            if(r != s.size()) {
                freqS[s[l] - 'a'] -= 1;
                freqS[s[r] - 'a'] += 1;
            }
            l++;
        }
        return ans;
    }
};