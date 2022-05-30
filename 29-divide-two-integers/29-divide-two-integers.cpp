class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : +1;
        
        long long dd = abs(dividend), dv = abs(divisor);
        
        for(int i = 31; i >= 0; i--) {
            if((dv << i) > dd) continue;
            ans |= (1LL << i);
            dd -= (dv << i);
        }
        
        ans *= sign;
        if(ans < 0 and ans < INT_MIN) ans = INT_MIN;
        if(ans > 0 and ans > INT_MAX) ans = INT_MAX;
        return ans;
    }
};