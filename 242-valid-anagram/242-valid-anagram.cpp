class Solution {
public:
    bool isAnagram(string s, string t) {
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