// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  /* Use binary search to reduce calls to isBadVersion, and incorporate a checker to keep track of the 
    lowest bad version found. The loop will go until the 'end' because there is no return statement */
  
    int firstBadVersion(int n) {
        int high = n, low = 0, lowest = n, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(isBadVersion(mid)) {
                high = mid - 1;
                lowest = min(lowest, mid);
            } else {
                low = mid + 1;
            }
        }
        return lowest;
    }
};
