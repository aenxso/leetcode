class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0);
        string shortest = "";
        
        for(int i = 0; i < licensePlate.size(); i++) { // add frequency of all letters to a vector
            if(isalpha(licensePlate[i])) {
                freq[tolower(licensePlate[i]) - 'a']++;
            }
        }
        
        for(int i = 0; i < words.size(); i++) {
            vector<int> tmp = freq;                    // copy freq vector to use for each word in words
            for(int j = 0; j < words[i].size(); j++) {
                tmp[tolower(words[i][j]) - 'a']--;
            }
            bool flag = true;
            for(int j = 0; j < tmp.size(); j++) {      // frequency doesn't match, not a suitable word
                if(tmp[j] > 0) flag = false;
            }
            
            if(flag && (shortest == "" || words[i].length() < shortest.length())) { // check for new shortest word
                shortest =  words[i];
            }
        }
        return shortest;
    }
};