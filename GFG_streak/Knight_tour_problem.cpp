#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> dir = {
        // {-1,0},{1,0},{0,-1},{0,1},
        // {-1,-1},{-1,1},{1,1},{1,-1}
         {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    int f(int i, int j, int n, int step, vector<vector<int>> &path){
        // path[i][j] = step++;
        if(step == n*n) return true;
        
        for(auto d: dir){
            int di = i+d[0], dj = j+d[1];
            if(di>=0 && dj>=0 && di<n && dj<n && path[di][dj]==-1){
                path[di][dj] = step;
                if(f(di, dj, n, step+1, path)) return true;
                path[di][dj] = -1;
            }
        }
        return false;
    }
    
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> path(n, vector<int>(n,-1));
        path[0][0] = 0;
        if(f(0, 0, n, 1, path)){
            return path;
        }
        else{
            return {};
        }
    }
};