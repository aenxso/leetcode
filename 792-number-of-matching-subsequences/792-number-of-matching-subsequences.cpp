class Solution {
public:

    int numMatchingSubseq(string s, vector<string>& words) {
        // hashmap with string and bool pair - store whether a string is subsequence or not
        int count = 0;
        map<string, bool> mp;
        
        for(auto word : words) {
            if(mp.find(word) != mp.end()) { // if string has already occurred then don't compute again
                if(mp[word] == true) {      // if string has value true it is subsequence - count++
                    count++;
                }
                continue; //if not go for next string
            }
            mp[word] = isSubsequence(s, word, s.size(), word.size()); // if not calculated previously, compute the value 
                                                                      // and assign to wword (current string from words)
            if(mp[word]) count++;
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