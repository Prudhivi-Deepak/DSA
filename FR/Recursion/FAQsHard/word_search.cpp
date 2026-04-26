class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool f(int index, int i, int j, string &word, vector<vector<char> >& board, vector<vector<bool>> &visited){
        if(index == word.size()) return true;
    
        for(auto d : dir){
            int d_i = d[0]+i, d_j = d[1]+j;

            if(d_i>=0 && d_j>=0 && d_i<board.size() && d_j<board[0].size() && !visited[d_i][d_j]){
                if(board[d_i][d_j]==word[index]){
                    visited[d_i][d_j] = true;
                    if(f(index+1, d_i, d_j, word, board, visited)) return true;
                    visited[d_i][d_j] = false;
                }
            }
        }
        return false;        
    }

    bool exist(vector<vector<char> >& board, string word) {
        //your code goes here

        // check for word[0] in the matrix
        // if you find it do recursive top, down, left, right --> need to mantain a visited vector for sure
        // if word present return true

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]==word[0]){
                    visited[i][j] = true;
                    if(f(1, i, j, word, board, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};