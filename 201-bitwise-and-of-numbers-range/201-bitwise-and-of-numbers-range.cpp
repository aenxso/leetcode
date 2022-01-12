class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*
            comparing left and right, perform a right shift until they are equal. This removes the least significant bit, and every bit
            that has been removed represents a bit that flipped at some point during the journey from left, to becoming right.
            A bit that flips will always return 0 when &'d, so we can disregard all these positions and add them back at the end
            by performing a left shift for the number of times we originally had to right shift. This will add in all the missing 0's.
        */
        
        int numOfShifts = 0;
        
        while(left != right) {
            left >>= 1;
            right >>= 1;
            numOfShifts++;
        }
        
        return right <<= numOfShifts; // can use either left or right
    }
};