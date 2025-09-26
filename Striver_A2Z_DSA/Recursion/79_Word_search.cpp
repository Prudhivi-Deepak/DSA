#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        bool f(int i, int j, int sind, vector<vector<char> >& board, string &word){
    
            // cout << word[sind] << endl;
    
            if(sind == word.size()) return true;
            if(board[i][j]!=word[sind]) return false;
    
            board[i][j] = '.';
            
            //up
            bool up = false;
            if(i-1>=0) up = f(i-1, j, sind+1, board, word);
            //down
            bool down = false;
            if(i+1 < board.size()) down = f(i+1, j, sind+1, board, word);
            //left
            bool left = false;
            if(j-1>=0) left =  f(i, j-1, sind+1, board, word);
            //right
            bool right = false;
            if(j+1 < board[0].size()) right = f(i, j+1, sind+1, board, word);
    
    
            board[i][j] = word[sind];
            return (up || down || left || right);
    
        }
        bool exist(vector<vector<char>>& board, string word) {
    
            int m = board.size(), n = board[0].size();
    
            if(word.size() == 1 && m*n == 1) return word[0]==board[0][0];
    
            if(word.size() > m*n) return false;
    
            vector<int> counts(256, 0); // Array to store counts of each character
            
            // Count the occurrence of each character on the board
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    counts[board[i][j]]++;
                }
            }
    
            // Adjust the order of characters in the wordChar array based on their frequency counts to optimize search
            int len = word.size();
            for (int i = 0; i < len / 2; i++) {
                if (counts[word[i]] > counts[word[len - 1 - i]]) {
                    reverse(word.begin(), word.end());
                    break;
                }
            }
    
            for(int i=0; i<board.size(); i++){
                for(int j=0; j<board[i].size(); j++){
                    if(board[i][j] == word[0]){
                        if(f(i, j, 0, board, word)) return true;
                    }
                }
            }
    
            return false;
        }
    };