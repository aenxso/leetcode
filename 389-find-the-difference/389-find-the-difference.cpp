class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sFreq(26, 0);
        vector<int> tFreq(26, 0);
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        char ans;
        
        for(int i = 0; i < s.size(); i++) {
            sFreq[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            tFreq[t[i] - 'a']++;
        }
        for(int i = 0; i < tFreq.size(); i++){
            if(sFreq[i] != tFreq[i]) {
                ans = alphabet[i % 26]; // mod by 26 because string.length may be > 26
                break;
            }
        }
        return ans;
    }
};