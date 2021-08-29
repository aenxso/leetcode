class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = sqrt(area);
        while(area % width) {
            width--;
        }
        
        vector<int> ans {area / width, width};
        return ans;
    }
};