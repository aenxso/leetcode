class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each individual string in strs vector
        // use each sorted string (the same ones will all be the same now) as key
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;
        
        
        // for each string (key) add the vector element (anagram string)
        for(string s : strs) {
            string tmp = s; // create a tmp so as not to mess up the original
            sort(tmp.begin(), tmp.end()); // sort it and use as key to add original string
            umap[tmp].push_back(s);
        }
        
        for(auto key : umap) {
            ans.push_back(key.second);
        }
        
        return ans;
    }
};