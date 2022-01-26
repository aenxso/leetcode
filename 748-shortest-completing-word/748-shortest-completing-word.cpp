class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0);
        string shortest = "";
        
        for(int i = 0; i < licensePlate.size(); i++) {
            if(isalpha(licensePlate[i])) {
                freq[tolower(licensePlate[i]) - 'a']++;
            }
        }
        
        for(int i = 0; i < words.size(); i++) {
            vector<int> tmp = freq;
            for(int j = 0; j < words[i].size(); j++) {
                tmp[tolower(words[i][j]) - 'a']--;
            }
            bool flag = true;
            for(int j = 0; j < tmp.size(); j++) {
                if(tmp[j] > 0) flag = false;
            }
            
            if(flag && (shortest == "" || words[i].length() < shortest.length())) {
                shortest =  words[i];
            }
        }
        return shortest;
    }
};