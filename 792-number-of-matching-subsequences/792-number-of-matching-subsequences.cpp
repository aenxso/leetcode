class Solution {
public:

    int numMatchingSubseq(string s, vector<string>& words) {
        // hashmap with string and bool pair - store whether a string is subsequence or not
        int count = 0;
        map<string, bool> mp;
        
        for(auto x: words) {
            if(mp.find(x) != mp.end()) { // if the string has already occurred then don't compute again
                if(mp[x] == true) { // if that string has value true that means it is subsequence, count++
                    count++;
                }
                continue; //if not, go for next string
            }
            mp[x] = isSubsequence(s, x, s.size(), x.size()); // if not calculated previously, compute the value 
                                                             // and assign to x(current string from words)
            if(mp[x]) count++;
            // count += (mp[x] == true);
        }
        return count;
    }
    
private:
    bool isSubsequence(string s1, string s2, int m, int n) {
        int j = 0;
        for(int i = 0; i < m && j < n; i++) {
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
};