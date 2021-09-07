class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int longest = releaseTimes[0];
        int ans = 0;
        for(int i = 1; i < releaseTimes.size(); i++) {
            int diff = releaseTimes[i] - releaseTimes[i - 1];
            if(diff > longest || (diff == longest && keysPressed[i] > keysPressed[ans])) { //if times are the same, check for lexicographically bigger char
                longest = diff;
                ans = i;
            }
            
        }
        return keysPressed[ans];
    }
};
