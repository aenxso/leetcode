class Solution {
public:
    int fib(int n) {
        // recursion
        if(n <= 1) { // base condition
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};