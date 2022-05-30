class Solution {
public:
    int divide(int dividend, int divisor) {
        /*
            Let's take two numbers a = 96 and b = 7. When we divide a by b, we are calculating how many times 
            b is equal to a or how many b's can fit inside a. In this case, we can fit 13 b's in a i.e. a / b = 13 
            (Note: here we calculate only the floor value)

            We know that each number can be represented as the sum of powers of 2 and also when we shift 
            a number towards left by n bits it is multiplied by 2 power n (2^n). Thus, what we do is shift the divisor 
            b towards the left and check if it is less than or equal to the dividend a. If it is less than or equal 
            to the dividend we subtract it from the dividend and add the value of 2 power n to our answer. 
            Doing so, we get our answer as the sum of powers of 2, which will give us the required quotient.

            And we repeat this process for the powers of two from 31 to 0. Here we have chosen 31 because in general, 
            the size of an integer data type is 32 bits i.e. it starts from 0 and goes till 31.
        */
        
        
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