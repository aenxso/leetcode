class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // 3 cases to check for:
        // - seats in the beginning of row are empty
        // - seats inbetween filled seats are empty
        // - seats at the end of the row are empty
        if(seats.size() < 3) return 1;
        
        int maxDistance = 0, l = -1, r = 0;
        
        for(; r < seats.size(); r++) {
            if(seats[r] == 1) {
                if(l == -1) { // beginning section of seats is zeroes, hence no need to move left pointer up
                    maxDistance = max(maxDistance, r); // get distance of empty seats at beginning
                } else {
                    maxDistance = max(maxDistance, (r - l) / 2); // empty seat is surrounded by filled seats, get distance inbetween them
                }
                l = r; // update left to the newest found filled seat
            }
        }
        
        // get empty seats at the end
        if(seats[seats.size() - 1] == 0) {
            maxDistance = max(maxDistance, r - l - 1); // minus extra 1 for 0 indexing
        }
        
        return maxDistance;
    }
};