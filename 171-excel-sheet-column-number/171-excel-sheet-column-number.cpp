class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        
        for(char c : columnTitle) {
            int letterVal = c - 'A' + 1;
            ans = ans * 26 + letterVal;
        }
        return ans;
    }
};