class Solution {
public:

    bool isValid(int i, int j, vector<vector<char> >& board, int value){

        // check in row
        for(int row=0; row<board.size(); row++){
            if(board[row][j]-'0'==value) return false;
        }

        // check in col
        for(int col = 0; col<board[0].size(); col++){
            if(board[i][col]-'0'==value) return false;
        }

        // check in it's 3x3 box
        // given any cell how to find it's 3x3 left top cell

        // 7,5 %3 = 1, 2
        // 8,3 %3 = 2, 0

        int si = i-i%3, sj = j-j%3;

        for(int row = si; row<si+3; row++){
            for(int col = sj; col<sj+3; col++){
                if(board[row][col]-'0'==value) return false;
            }
        }
        return true;
    }

    bool f(vector<vector<char> >& board){

        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++){
                if(board[row][col]=='.'){
                    for(int value=1; value<10; value++){
                        if(isValid(row, col, board, value)){
                            board[row][col] = (value+'0');
                            if(f(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char> >& board) {
        //your code goes here
        f(board);
    }
};