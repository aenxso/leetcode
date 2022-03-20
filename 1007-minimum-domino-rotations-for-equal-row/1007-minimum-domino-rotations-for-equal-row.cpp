class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // create an array to track the frequency in tops, bottoms, and where they are the same
        // for numbers 1 to 6, check if the freq between top+bottom-same == n as this indicates a solution
        // to reach number of rotations needed, take the size and subtract max(topcnt[i], btmcnt[i])
        //   (because we are looking for least amount of flips, so obvs we wouldn't flip the side where
        //    majority need to be flipped)
        
        vector<int> topCount(7), bottomCount(7), sameCount(7); // init with 7 spaces because dominoes only go till 6
        int n = tops.size(), ans = 0;
        
        for(int i = 0; i < n; i++) {
            topCount[tops[i]]++;
            bottomCount[bottoms[i]]++;
            if(tops[i] == bottoms[i]) sameCount[tops[i]]++; //tops[i] or bottoms[i] would work, just getting value
        }
        
        for(int i = 1; i < 7; i++) { // starting with 1, ending with 6
            if(topCount[i] + bottomCount[i] - sameCount[i] == n) { // eg. n=6, tc[i]=4, bc[i]=3, sc[i]=1: 4+3-1=6
                ans = n - max(topCount[i], bottomCount[i]); // total size - whichever between top and bottom had more occurrences of  
                                                            // the special 
                return ans;
            }
        }
        return -1;
    }
};