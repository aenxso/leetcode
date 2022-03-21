class Solution {
public:
    vector<int> partitionLabels(string s) {
        // create array to keep track of ending index of every letter in the string
        // go through the string char by char and if we find a letter inbetween the starting and ending
        //  of another letter, we increase the partition to avoid splitting the newly found letter into two partitions
        //  since the requirement is having any letter appear at most once in a partition
        
        vector<int> endings(26, 0), ans; // size 26 for all letters in alphabet
        int start = 0, last = 0, n = s.length();
        
        for(int i = 0; i < n; i++) {     // add last element for all letters present in s
            endings[s[i] - 'a'] = i; 
        }
        
        for(int i = 0; i < n; i++) {
            last = max(last, endings[s[i] - 'a']); // finding the maximum end index for all letters currently encountered
              
            if(i == last) {      // if we're at the last max found index, create partition here
                ans.push_back(i - start + 1);
                start = i + 1;   // adjust start for next partition
            }
        }
        return ans;
    }
};