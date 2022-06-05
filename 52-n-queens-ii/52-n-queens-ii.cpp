class Solution {
public:
    int totalNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));  // creating an empty board
	    solve(board, 0); // calling the recursive function
	    return sols.size(); 
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
		    // No need to traverse more since the lower rows below current row attribute will always be safe.
			/* if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
			if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false; */
	    }
	    return true;
    }
    // backtracking func to try all possible placement of queen for the current row & recurses for its next row
    void solve(vector<string>& board, int row) {
	// base condition - reached the last row, so we have a solution - add it to the solution vector
	    if(row == size(board)) { 
		    sols.push_back(board);
		    return;
    	}            
	    // try placing a queen on each column for a given row
        // explore next row by placing Q at each valid column for the current row
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    // queen placed on a valid cell
			    solve(board, row + 1);    // exploring next row
			    board[row][col] = '.';    // backtracking to get all possible solutions
		    }
        }
    }
    
private:
    vector<vector<string>> sols;
};