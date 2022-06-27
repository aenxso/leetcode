class Solution {
public:
    int minPartitions(string n) {
        
        /* essentially picking out the max single digit in the string.
           eg. in 132, 3 is the biggest num
           eg. in 999, 9 is the biggest num
           eg. in 12, 2 is the biggest num 
           - think of how many 'ones' are needed to make this max single digit
           - can also picture the number as having columns, and subtracting 1 from each
             number until it reaches zero. This is why we just need to find the highest number,
             because going down the column, that will be the last to reach 0. 
             Taking x steps, x being the largest digit */
        
        char maxNum = '0';
        // sort(n.begin(), n.end());
        for(char c : n) {
            if(c > maxNum) {
                maxNum = c;
            }
        }
        return maxNum - '0';
        // return n[n.length()-1] - '0';
    }
};