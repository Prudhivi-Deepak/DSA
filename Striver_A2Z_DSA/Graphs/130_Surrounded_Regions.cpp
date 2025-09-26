#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void BFS(queue<pair<int,int>> &q, vector<vector<char>> &board, vector<vector<int>> &visited){
    
            while(!q.empty()){
                int size = q.size();
                for(int k=0; k<size; k++){
                    pair<int,int> currnode = q.front(); q.pop();
                    
                    int c_i = currnode.first;
                    int c_j = currnode.second;
    
                    //up 
                    if(c_i-1>=0 && visited[c_i-1][c_j]==0 && board[c_i-1][c_j]=='O'){
                        visited[c_i-1][c_j] = 1;
                        q.push({c_i-1, c_j});
                    }
                    //down
                    if(c_i+1<board.size() && visited[c_i+1][c_j]==0 && board[c_i+1][c_j]=='O'){
                        visited[c_i+1][c_j] = 1;
                        q.push({c_i+1, c_j});
                    }
                    //left
                    if(c_j-1>=0 && visited[c_i][c_j-1]==0 && board[c_i][c_j-1]=='O'){
                        visited[c_i][c_j-1] = 1;
                        q.push({c_i, c_j-1});
                    }
                    //right
                    if(c_j+1 < board[c_i].size() && visited[c_i][c_j+1]==0 && board[c_i][c_j+1]=='O'){
                        visited[c_i][c_j+1] = 1;
                        q.push({c_i, c_j+1});
                    }
                }
            }
        }
        void solve(vector<vector<char>>& board) {
            int n = board.size(), m = board[0].size();
           vector<vector<int>> visited(n, vector<int>(m, 0));
    
           queue<pair<int,int>> q;
    
           for(int i=0; i<n; i++){
                //0th col and 0th row
                if(board[i][0]=='O'){
                    visited[i][0] = 1;q.push({i,0});
                }
                if(board[i][m-1]=='O'){
                    visited[i][m-1] = 1;q.push({i,m-1});
                }
           }
    
           for(int j=0; j<m; j++){
                if(board[0][j] =='O') {
                    visited[0][j] = 1;q.push({0,j});
                }
                if(board[n-1][j] == 'O') {
                    visited[n-1][j] = 1;q.push({n-1,j});
                }
           }
    
           BFS(q, board, visited);
    
           for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j] = 'X';
                }
            }
           }
        //    return board;
        }
    };