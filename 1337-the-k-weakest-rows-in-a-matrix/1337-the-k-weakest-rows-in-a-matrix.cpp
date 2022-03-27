class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // create a set of pairs - first element in pair is the count of ones in the row,
        //    second element is index
        // pairs automatically get sorted in ascending order based on first element (count of ones in this case)
        // using stl function count to count ones in rows
        
        vector<int> ans;
        set<pair<int, int>> s;
        
        for(int i = 0; i < mat.size(); i++) {
            int ones = count(mat[i].begin(), mat[i].end(), 1); // stl function
            s.insert({ones, i}); // insert new pair into set
        }
        
        for(auto x : s) { // add elements to answer k number of times
            if(k == 0) break;
            ans.push_back(x.second);
            k--;
        }
        return ans;
    }
};