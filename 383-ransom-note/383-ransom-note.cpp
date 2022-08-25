class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        
        for(auto letter : magazine) {
            mp[letter]++;
        }
        
        for(auto letter : ransomNote) { // if the letter of ransomnote is found, decrease the freq from the map
            if(!mp[letter]--) { 
                return false; // return false once we reach 0
            }
        }
        return true;
    }
};