class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(n == h) return *max_element(piles.begin(), piles.end()); // no extra time to eat slowly if h == num of piles
        
        int l = 1, r = *max_element(piles.begin(), piles.end()); // search range is between 0 and max element
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int hours = 0;
            for(int b : piles) {
                hours += (b + mid - 1) / mid; // calculating hours it will take to eat all bananas
                                              // add (mid - 1) to avoid dividing by 0
            }
            if(hours > h) { // if it takes too long
                l = mid + 1; 
            } else {        // can eat slower
                r = mid;
            }
        }
        return l;
    }
};