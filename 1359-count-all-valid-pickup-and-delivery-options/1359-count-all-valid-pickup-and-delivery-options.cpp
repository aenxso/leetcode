class Solution {
public:
    int countOrders(int n) {
        long mod = 1e9 + 7, ans = 1;
        
        for(int i = 2; i <= n; i++) {
            int spaces = (i - 1) * 2 + 1;
            ans *= spaces * (spaces + 1) / 2;
            ans %= mod;
        }
        return (int)ans;
    }
};