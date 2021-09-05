class Solution {
public:
    int myAtoi(string s) {
        int i = 0, result = 0;
        bool isNeg = false;
        
        while(i < s.length() && s[i] == ' ') i++;
        
        if(i < s.length()) {
            if(s[i] == '-' || s[i] == '+') {
                isNeg = s[i] == '-' ? true : false;
                i++;
            }
        }
        
        while(i < s.length() && isdigit(s[i])) {
            if(result > (INT_MAX - (s[i] - '0')) / 10) {
                return isNeg ? INT_MIN : INT_MAX;
            }
            result = result * 10 + (s[i] - '0');
            i++;

        }
        
        return isNeg ? -result : result;
        
    }
};
