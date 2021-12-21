class Solution {
public:
    bool isPowerOfTwo(int n) {
        // negative numbers cannot be a power of 2
        if(n <= 0) return false;
        
        // powers of two only have one '1' in their binary form. Subract 1 from n to flip all bits. &ing these two will result in no &s
        return ((n & (n - 1)) == 0) ? true : false;
    }
};