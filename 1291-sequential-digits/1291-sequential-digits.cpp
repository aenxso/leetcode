class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for(int i = 1; i < 9; i++) { // get a starting number
            int num = i;
            for(int j = i + 1; j <= 9; j++) { // j = i + 1 to maintain sequentialness
                num = num * 10 + j;           // add a bigger digit and move up a ten's place every itr
                if(num <= high && num >= low) {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};