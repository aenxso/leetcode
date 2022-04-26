class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // use minimum spanning tree and Prim's algorithm
        // for every node, add its frontier to the min heap (all nodes not yet connected)
        // every itr, pop the smallest value from the heap and add node to visited
        // add the manhattan distance when adding node
        
        int n = points.size(), ans = 0, i = 0, connected = 0;
        vector<bool> visited(n);           // keep track of visited nodes
        priority_queue<pair<int, int>> pq; // min heap
        
        while(++connected < n) {
            visited[i] = true;
            for(int j = 0; j < n; j++) {
                if(!visited[j]) {
                    pq.push({-(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), j});
                }
            }
             while(visited[pq.top().second]) {
                    pq.pop();
            }
            ans -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};