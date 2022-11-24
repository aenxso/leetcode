class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i ++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        if(index == word.size() - 1) return true; // found last char in the word == word found
        
        char c = board[i][j];
        board[i][j] = '.'; // mark as visited
        bool ans = dfs(board, word, i + 1, j, index + 1) || // search 4-directionally
                   dfs(board, word, i - 1, j, index + 1) || 
                   dfs(board, word, i, j + 1, index + 1) || 
                   dfs(board, word, i, j - 1, index + 1);
        board[i][j] = c; // return to normal
        return ans;
    }
};