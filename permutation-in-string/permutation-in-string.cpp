class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // create vector to record occurrences if letters in s1
        // use 2 pointers to create a 'window' of size s1.length()
        
        if(s1.length() > s2.length()) return false;
        
        vector<int> s1freq(26, 0);
        vector<int> s2freq(26, 0);
        for(char c : s1) s1freq[c - 'a']++;
        
        int i = 0, j = 0, n = s1.length();
        
        while(i < s2.length()) {
            s2freq[s2[i] - 'a']++;
            if(i >= s1.length()) {
                j = i - n;
                s2freq[s2[j] - 'a']--;
            }
            if(s2freq == s1freq) return true;
            i++;
        }
        return false;
    }
};