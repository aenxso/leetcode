class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, num = nums[0];
        for(int i = 0; i < nums.size() - 1; i++) {
            
            if(num == nums[i + 1]) {
                count++;
                
                if(count >= 2) {
                    int j = i;
                    while(num == nums[j] && j < nums.size()) {
                        cout<<"j: "<<j<<endl;
                        nums.erase(nums.begin() + j);
                        j++;
                    }
                    // cout<<count<<endl;
                    // cout<<"i: "<<i<<endl;
                    // nums.erase(nums.begin() + i);
                    // cout<<"Deleted\n";
                    i--;
                    cout<<"size: "<<nums.size()<<endl;
                }
            } else {
                count = 0;
                num = nums[i + 1];
            }
            cout<<"i: "<<i<<", count: "<<count<<", num: "<<num<<endl;
        }
        return nums.size();
    }
};