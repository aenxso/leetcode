class Solution {
public:
    int titleToNumber(string columnTitle) {
        // multiply by 26 for every letter in string (base 26 basically, aside from first letter)
        // add on numerical value of each individual letter for every itr
        
        int ans = 0;
        
        for(char c : columnTitle) {
            int addValue = c - 'A' + 1;
            ans = ans * 26 + addValue;
        }
        
        return ans;
    }
};