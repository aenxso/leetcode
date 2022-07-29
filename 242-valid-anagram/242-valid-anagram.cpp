class Solution {
public:
    bool isAnagram(string s, string t) {
        // this code compiled on the first try :))))))))))
        // create a letter frequency vector for each string, populate vectors
        // compare vectors - if there is a difference they are not anagrams
        // time: O(N), space: O(N) - better time than sorting but more memory
        
        vector<char> sFreq(26);
        vector<char> tFreq(26);
        
        countLetters(sFreq, s);
        countLetters(tFreq, t);
        
        for(int i = 0; i < sFreq.size(); i++) {
            if(sFreq[i] != tFreq[i]) return false;
        }
        
        return true;
    }
    
    void countLetters(vector<char> &v, string &s) {
        for(int i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
        }
    }
};