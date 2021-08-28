class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= 1 || numRows <= 1) return s;
        string ans = "";
        vector<string> zigzag(numRows, "");
        
        int row = 0, step = 1;
        for(int i = 0; i < s.length(); i++) {
            zigzag[row].push_back(s[i]);
            if(row == 0) step = 1; // if we are back at row 0, reset step to 1
            if(row == numRows - 1) step = -1; // if we are at the last row, set step to -1 to move back one row each iteration
            row += step; // either adding or subtracting 1 to move rows
        }
        
       for(string s : zigzag) {
           ans += s;
       }
        
        return ans;
    }
};
