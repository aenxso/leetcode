class Solution {
public:
    int countOrders(int n) {
        long mod = 1e9 + 7, ans = 1;
        
        for(int i = 1; i <= n; i++) {
            ans = ans * (i * 2 - 1) * i % mod;
        }
        return (int)ans;
    }
};