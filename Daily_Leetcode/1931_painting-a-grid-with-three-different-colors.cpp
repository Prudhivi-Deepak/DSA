
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int mod = 1e9+7;
        int state_mem[1002][1023]; // for every col we store all the rows values (5 rows = 10 bits);
        // [col][state] = no of ways;
    
        int count_no_of_ways(int m, int n, int curr_state, int prev_state, int curr_row, int curr_col){
            if(curr_col == n) return 1; //we know n cols are there so all states are filled so retrun 1 way is possible;
            //if curr row is done filling go to next row and start fresh and change prev_state;
            if(curr_row == m) return count_no_of_ways(m, n, 0, curr_state, 0, curr_col+1);
    
            // check if subproblems are already solved by checking the state_mem array;
            //curr_state is already calculated 
            if(curr_row==0 && state_mem[curr_col][prev_state]!=-1) return state_mem[curr_col][prev_state]; 
    
            int curr_state_prev = 0;
            if(curr_row>0) curr_state_prev = curr_state & 3; //get the last 2 bits of the number;
            int prev_state_row = (prev_state >> ((m-curr_row-1)*2)) & 3; // get the prev state corresponding value;
    
            int total_ways_to_fill = 0;
    
            for(int color=1; color<4; color++){
                if(color != curr_state_prev && color != prev_state_row)
                    total_ways_to_fill = (total_ways_to_fill + count_no_of_ways(m, n, ((curr_state<<2) + color), prev_state, curr_row+1, curr_col)) % mod;
            }
    
            if(curr_row==0)
                return state_mem[curr_col][prev_state] = total_ways_to_fill;
    
            return total_ways_to_fill;
    
        }
    
        int colorTheGrid(int m, int n) {
            memset(state_mem, -1, sizeof(state_mem));
            return count_no_of_ways(m, n, 0, 0, 0, 0);
        }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        int total_count = 0;
        unordered_set<string> unique_states;
        void gridToString(vector<vector<int>> grid){
            string res;
            for(auto &row: grid){
                for(int cell : row){
                    res += to_string(cell)+",";
                }
            }
            unique_states.insert(res);
        }
        void printGrid(vector<vector<int>> grid) {
            // cout << endl;
            total_count++;
            for (int k = 0; k < grid.size(); k++) {
                for (int l = 0; l < grid[0].size(); l++) {
                    cout << grid[k][l] << " ";
                }
                cout << endl;
            }
            gridToString(grid);
            // cout << "-----------------" << total_count << endl;
        }
        bool IsAdjacentSame(vector<vector<int>>& grid, int i, int j, int color) {
            // cout << endl << "IsAdjacentSame : (" << i << "," << j << ") color : " << color;
            // printGrid(grid);
            int up = 0, down = 0, left = 0, right = 0;
            if (j - 1 >= 0 && grid[i][j - 1] == color)
                return true; // up
            if (j + 1 < grid[0].size() && grid[i][j + 1] == color)
                return true;
            if (i - 1 >= 0 && grid[i - 1][j] == color)
                return true;
            if (i + 1 < grid.size() && grid[i + 1][j] == color)
                return true;
    
            // cout << "false " << endl;
            return false;
        }
    
        void f(int i, int j, vector<vector<int>> grid, int prev, int count, vector<vector<vector<int>>> &dp) {
    
            // cout << "i - j - count = " << i << " : " << j << " : " << count << " : "
                //  << grid.size() * grid[0].size() << " grid[i][j] : " << grid[i][j];
            // if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ||
            // grid[i][j]!=-1) return ;
    
            if (count == grid.size() * grid[0].size()) {
                for (int color = 0; color < 3; color++) {
                    if (color != prev) {
                        if (IsAdjacentSame(grid, i, j, color)) {
                            // cout << "true " << endl;
                            continue;
                        }
                        // cout << "-----------------" << endl;
                        grid[i][j] = color;
                        gridToString(grid);
                        dp[i][j][color] = 1;
                        // printGrid(grid);
                    }
                }
                return;
            }
    
    
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != -1) return;
    
            for (int color = 0; color < 3; color++) {
                if (color != prev) {
    
                    if(dp[i][j][color]!=-1) continue;
    
                    if (IsAdjacentSame(grid, i, j, color)) {
                        // cout << "true " << endl;
                        continue;
                    }
                    // cout << "-----------------" << endl;
    
                    grid[i][j] = color;
                    // printGrid(grid);
    
                    if (j - 1 >= 0 && grid[i][j - 1] == -1) {
                        // cout << " left "<< endl;
                        f(i, j - 1, grid, color, count + 1, dp); // left
                    }
                    if (j + 1 < grid[0].size() && grid[i][j + 1] == -1) {
                        // cout << " right "<< endl;
                        f(i, j + 1, grid, color, count + 1, dp); // right
                    }
                    if (i - 1 >= 0 && grid[i - 1][j] == -1) {
                        // cout << " up"<< endl;
                        f(i - 1, j, grid, color, count + 1, dp); // up
                    }
                    if (i + 1 < grid.size() && grid[i + 1][j] == -1) {
                        // cout << " down "<< endl;
                        f(i + 1, j, grid, color, count + 1, dp); // down
                    }
                }
                // dp[i][j][color] = 1;
            }
    
            return;
        }
    
        int colorTheGrid1(int m, int n) {
            // return no of ways with no 2 adjacent having same color definetly a dp
            // problem
            vector<vector<int>> grid(m, vector<int>(n, -1));
    
            vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1)));
    
            f(m - 1, n - 1, grid, -1, 1, dp);
    
            // cout << "completed " << endl;
            // cout << total_count << endl;
            // cout << unique_states.size() << endl;
            return unique_states.size();
    
            // for(int color=0; color<3; color++){
            //     grid[m-1][n-1] = color;
            // f(i, j, grid, i);
            // }
    
            return -1;
        }
    };