class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq; // freq. map denotes no. of elements left to be placed in subseq.
        unordered_map<int,int> need; // hypothetical map which denotes the "next" number req. by subsequences
        
        for(int x : nums) {
            freq[x]++;
        }
        
        for(int n : nums) {
            if(freq[n] == 0) continue; // all occurences of cur num is already taken
            
            if(need[n] > 0) {  // "n" can be a part of some existing subseq.
                need[n]--;
                freq[n]--;
                need[n + 1]++; // next req. num is now "N+1"
            } else if(freq[n] > 0 && freq[n + 1] > 0 && freq[n + 2] > 0) { // try creating a new subsequence of length 3
                freq[n]--;
                freq[n + 1]--;
                freq[n + 2]--;
                
                need[n + 3]++; // next num needed in subsequence
            } else {           // above both condtn is false
                return false;
            }
        }
        
        return true; 
    }
};