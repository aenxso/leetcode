class Solution {
public:
    string getSmallestString(int n, int k) {
        // create a string of length n filled with all 'a'
        // starting from the back of the string, change the last letter to 'z'
        // see if the sum of letters is greater or less than k
        // adjust last letter as needed
        // adjust k to be k - n in the beginning, and accordingly after every itr
        
        string ans (n, 'a');
        int sum = 0, j = 27;
        k = k - n;
        
        for(int i = n - 1; i >= 0; i--) {
            sum = n;
            if(k == 0) break; // solution reached
            if(k > 25) {      // letter needed is z, therefore replace current index with 'z' and continue
                ans[i] = (char)('a' + 25);
                k = k - 25;
            } else {          // letter index neeeded is corresponding to k's value
                ans[i] = (char)('a' + k);
                k = k - k;
            }
            
        }
        
        return ans;
    }
};