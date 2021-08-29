class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = sqrt(area); //width will always be <= to sqrt of area
        while(area % width) { //while the division is not perfect, reduce the square root (width) value
            width--;
        }
        
        vector<int> ans {area / width, width};
        return ans;
    }
};
