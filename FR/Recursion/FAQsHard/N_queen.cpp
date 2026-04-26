class Solution {
public:
    bool isValid(int row, int col, vector<string> &board){

         // check column (upwards)
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q') return false;
        }

        // check upper-left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        // check upper-right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<board[0].size(); i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void f(int i, vector<string> &board, vector<vector<string>> &ans){
        if(i == board.size()){
            ans.push_back(board);return;
        }

        for(int indj = 0; indj<board[0].size(); indj++){
            if(isValid(i, indj, board)){
                board[i][indj] = 'Q';
                f(i+1, board, ans);
                board[i][indj] = '.';
            }
        }
    }



    vector<vector<string> > solveNQueens(int n) {
        //your code goes here

        // create a function to take i, j = placing queen there is valid(return true) else false
        // we iterate each cell and try to place the queen if valid place it and move ahead
        // now after placing all queen return true
        // not possible to place at a position return false

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        // vector<string> ["...", "...", "...."]
        f(0, board, ans);
        return ans;
    }
};