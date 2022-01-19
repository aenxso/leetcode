class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& nums, vector<bool>& visited, int i) {
        visited[i] = true;
        for(int j = 0; j < visited.size(); j++) {
            if(i != j && nums[i][j] == 1 && !visited[j]) {
                dfs(nums, visited, j);
            }
        }
    }
};