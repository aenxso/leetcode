class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        if(graph.size() == 0) return ans;
        
        
        int target = graph.size() - 1; // last node, which we want to eventually land up on
        dfs(graph, ans, path, target, 0); // can use 0 as the starting position
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& ans, vector<int>& path, int target, int cur) {
        path.push_back(cur); // add current node to path
        if(cur == target) { // if we are at our target, add current node to answer
            ans.push_back(path);
        } else {
            for(int i : g[cur]) { // perform dfs on the rest of the indices from current node
                dfs(g, ans, path, target, i);
            }
        }
        path.pop_back(); // backtracking - remove last element of path so as not to keep unnecessary info
    }
};