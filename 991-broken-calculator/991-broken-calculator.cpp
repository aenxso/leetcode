class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // works backwards - treat startValue as target, and target as startValue
        // decrement target until it is LESS THAN startValue
        // if target is even: /= 2, if target is odd += 1
        // once it's less than the only operation that makes sense is adding 1
        // so answer will be ans plus the difference between startValue and target as we have to make up
        //  that difference by +1'ing, and each +1 counts as one operation that counts towards the answer total
        
        if(startValue == target) return 0;
        if(startValue > target) return startValue - target; // return diff as only operation is -1
        int ans = 0;
        
        while(startValue < target) {
            if(target % 2 == 0) { // if even then divide by 2
                target /= 2;
                ans++;
            } else {              // if odd, add one to make it even
                target += 1;
                ans++;
            }
        }
        
       return ans + (startValue - target);
    }
};