
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // [[1,4,3,1,3,2],
        // [3,2,1,3,2,4],
        // [2,3,3,2,3,1]]

        // [[3,3,3,3,3],
        // [3,2,2,2,3],
        // [3,2,1,2,3],
        // [3,2,2,2,3],
        // [3,3,3,3,3]]

        // row 1 to n-2 row

        // [[1,4,3,1,3,2],
        // [3,2,1,3,2,4],
    //  lm  3 3 3 3 3 4
    //  rm  4 4 4 4 4 4
    //  um  
// min-val  
        // [2,3,3,2,3,1]]

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        int n = heightMap.size(), m = heightMap[0].size();
        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(int j=0; j<m; j++){
            min_heap.push({heightMap[0][j], 0, j});
            min_heap.push({heightMap[n-1][j], n-1, j});
            grid[0][j] = 1;
            grid[n-1][j] = 1;
        }

        for(int i=0; i<n; i++){
            min_heap.push({heightMap[i][0], i, 0});
            min_heap.push({heightMap[i][m-1], i, m-1});
            grid[i][0] = 1;
            grid[i][m-1] = 1;
        }

        int totalRain = 0;
        while(!min_heap.empty()){
            vector<int> currCell = min_heap.top(); min_heap.pop();

            for(auto d : dir){
                int di = currCell[1]+d[0], dj = currCell[2]+d[1];

                if(di>=1 && dj>=1 && di<n-1 && dj<m-1 && grid[di][dj]==0){
                    if(heightMap[di][dj] < currCell[0]){
                        totalRain += (currCell[0] - heightMap[di][dj]);
                        min_heap.push({currCell[0],di,dj});
                    }
                    else{
                        min_heap.push({heightMap[di][dj],di,dj});
                    }
                    grid[di][dj] = 1;
                }
            }
        }
        return totalRain;
    }
};