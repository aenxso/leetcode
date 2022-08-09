class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};    // row[5][0] means whether number 1('0'+1) in row 5 has appeared
                                // 9x9 table full of 0's
        int col[9][9] = {0};    // col[3][8] means whether number 9('8'+1) in col 3 has appeared
                                // 9x9 table full of 0's
        int box[3][3][9] = {0}; // box[0][2][5] means whether number '6' in box 0,2 (row 0~2,col 6~8) has appeared
                                // 9 3x3 tables full of 0's
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1'; // calculate the number's index (board's number minus 1)
                    if(row[i][num]++ || col[num][j]++ || box[i/3][j/3][num]++) return false;
                }
            }
        }
        return true;
    }
};