class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;
        
        //sort each individual string in strs vector
        //use each sorted string (the same ones will all be the same now) as key
        //for each string (key) add the vector element (anagram string)
        for(string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(s);
        }
        
        for(auto key : umap) {
            ans.push_back(key.second);
        }
        
        return ans;
    }
};
