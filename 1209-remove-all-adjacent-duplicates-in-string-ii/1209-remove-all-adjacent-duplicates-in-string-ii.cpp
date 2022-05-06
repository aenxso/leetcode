class Solution {
public:
    string removeDuplicates(string s, int k) {
        // use a stack to store a char/count pair
        
        vector<pair<char, int>> stk;
        string ans = "";
        
        for(char c : s) {
            if(!stk.empty() && stk.back().first == c) {
                stk.back().second++;
            } else {
                stk.push_back({c, 1});
            }
            
            if(stk.back().second == k) { // duplicates reached the necessary amount
                stk.pop_back();
            }
        }
        
        for(auto l : stk) {
            ans.append(l.second, l.first);
        }
        
        return ans;
    }
};