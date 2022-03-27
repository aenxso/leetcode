class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        set<pair<int, int>> s;
        
        for(int i = 0; i < mat.size(); i++) {
            int ones = count(mat[i].begin(), mat[i].end(), 1);
            s.insert({ones, i});
        }
        
        for(auto x : s) {
            if(k == 0) break;
            ans.push_back(x.second);
            k--;
        }
        return ans;
    }
};