class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue == target) return 0;
        if(startValue > target) return startValue - target;
        int ans = 0;
        
        while(startValue < target) {
            if(target % 2 == 0) {
                target /= 2;
                ans++;
            } else {
                target += 1;
                ans++;
            }
        }
        
       return ans + (startValue - target);
    }
};