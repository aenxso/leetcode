class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using pipii = pair<int, pair<int, int>>;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        
        dist[0][0] = 0;
        
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            int weight = node.first;
            auto coords = node.second;
            int r = coords.first, c = coords.second;
            if(dist[r][c] < weight) continue;
            if(r == row - 1 && c == col - 1) return weight; // last cell reached
            
            for(auto &dir : dirs) {
                int dr = r + dir[0];
                int dc = c + dir[1];
                if(dr < 0 || dr >= row) continue;
                if(dc < 0 || dc >= col) continue;
                int newWeight = abs(heights[r][c] - heights[dr][dc]);
                newWeight = max(newWeight, weight);
                if(dist[dr][dc] <= newWeight) continue;
                dist[dr][dc] = newWeight;
                pq.push({newWeight, {dr, dc}});
            }
        }
        return 0;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};