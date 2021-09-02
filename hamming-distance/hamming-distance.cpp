class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0, diff = (x ^ y); //get the XOR to create int with all the different bits
        
        while(diff) { //loop will only run for as many set bits as there are
            distance++;
            diff = diff & (diff - 1); //remove right-most set bit every iteration (subtracting 1 flips all bits starting from right-most set bit)
        }
        return distance;
    }
};