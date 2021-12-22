class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++) {  // 32 bits, so runs 32 times
            result <<= 1;              // move result over to left each itr - eventually results in backwards n
            if(n & 1 == 1) result++;   // add 1 if there is a 1
            n >>= 1;                   // shift n to the right by one to work through all 32 bits
        }
        return result;
    }
};