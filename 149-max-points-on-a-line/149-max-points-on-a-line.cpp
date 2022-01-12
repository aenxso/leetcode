class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        double slope = 0;
        unordered_map<double, int> count; // hasmap to store count of slopes
        
        for(int i = 0; i < points.size(); i++) {
            count.clear();
            for(int j = 0; j < points.size(); j++) {
                if(i != j) {
                    int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                    slope = (double)(y2 - y1) / (x2 - x1);
                    count[slope]++;
                    ans = max(ans, count[slope]); // keep count of max repeated slope
                }
            }
        }
        return ans + 1; // + 1 because we are returning the number of points on the line
    }
};