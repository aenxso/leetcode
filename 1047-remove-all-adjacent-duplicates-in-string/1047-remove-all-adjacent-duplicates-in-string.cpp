class Solution {
public:
    string removeDuplicates(string s) {
        // create an ans string and append s' letters onto it
        // at each iteration, if there are letters in ans, compare the last letter to s[i]
        // if it matches (duplicate), just remove the last letter of ans
        
        string ans;
    
        for(int i = 0; i < s.size(); i++) {
            if(ans.size() && ans.back() == s[i]) { // if ans has letters in it and last letter matches s[i]
                ans.pop_back();
            } else { 
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};