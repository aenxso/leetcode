class Solution {
 public:
    int longestCycle(vector<int>& edges) {
        int ans = -1, time = 1;
        vector<int> timeVisited(edges.size());

        // Iterate through each node in the graph
        for(int i = 0; i < edges.size(); ++i) {
            if(timeVisited[i]) continue;
            const int startTime = time; // Record the start time of the current traversal
            int u = i; // init the current node to the ith node

            // traverse the graph until the end of the path is reached or a visited node is encountered
            while(u != -1 && !timeVisited[u]) {
                timeVisited[u] = time++; // record the current time step and increment time
                u = edges[u]; // move to the next node in the path
            }
            // update ans if a cycle is found that includes the current node
            if(u != -1 && timeVisited[u] >= startTime) {
                ans = max(ans, time - timeVisited[u]);
            }
        }

        return ans;
    }
};
