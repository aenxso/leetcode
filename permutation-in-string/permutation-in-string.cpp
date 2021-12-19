class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // create vector to record occurrences of letters in s1 and s2
        // use 2 pointers to create a 'window' of size s1.length(), slide window along till permutation is found
        
        if(s1.length() > s2.length()) return false; // s2 cannot contain permutation of something bigger than it
        
        vector<int> s1freq(26, 0); // create two vectors to store letter freq for each string
        vector<int> s2freq(26, 0);
        for(char c : s1) s1freq[c - 'a']++; // populate for s1
        
        int i = 0, j = 0, n = s1.length();
        
        while(i < s2.length()) {
            s2freq[s2[i] - 'a']++; // raise value of whatever char s2 is currently at by 1
            if(i >= s1.length()) {
                j = i - n;        // j is the left/slower pointer which is n chars away from i (window size)
                s2freq[s2[j] - 'a']--; // decrease the value of i-jth char frequency as we move on from the window
            }
            if(s2freq == s1freq) return true; // window is now correctt size to compare the 2 freq vectors
            i++;
        }
        return false;
    }
};
