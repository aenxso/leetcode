class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vals;
        
        while(n != 1) {
            if(vals.find(n) == vals.end()) {
                vals.insert(n);
            } else {
                return false; 
            }
            int sum = 0;
            while( n != 0) {
                int remainder = n % 10;
                sum += remainder * remainder;
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};