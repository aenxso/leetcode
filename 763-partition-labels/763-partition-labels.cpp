class Solution {
public:
    vector<int> partitionLabels(string s) {
        // create array to keep track of ending index of every letter in the string
        // go through the string char by char and if we find a letter inbetween the starting and ending
        //  of another letter, we increase the partition to avoid splitting the newly found letter into two partitions
        //  since the requirement is having any letter appear at most once in a partition
        
        vector<int> endings(26, 0), ans;
        int start = 0, last = 0, n = s.length();
        
        for(int i = 0; i < n; i++) {
            endings[s[i] - 'a'] = i; 
        }
        
        for(int i = 0; i < n; i++) {
            last = max(last, endings[s[i] - 'a']);
            
            if(i == last) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};