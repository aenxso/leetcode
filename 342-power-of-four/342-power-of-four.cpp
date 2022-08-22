class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        
        // divide by 4 while remainder == 0
        while(n % 4 == 0) n /= 4;

        return n == 1;
    }
};