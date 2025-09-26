#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            pair<int,int> source = {0,0}, destination = {heights.size()-1, heights[0].size()-1};
            vector<pair<int,int>> adj = {{-1,0}, {0,1}, {1,0}, {0,-1}};
            // queue<pair<int, pair<int,int>>> q;
            priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
            q.push({0, source});
            vector<vector<int>> grid_visited(heights.size(), vector<int>(heights[0].size(), 1e9));
            grid_visited[0][0] = 0;
            // grid_visited[source.first][source.second] = 1;
            // int MinEffort = 1e9;
    
            while(!q.empty()){
                    // auto [dist, pr] = q.front(); q.pop();
                    auto [dist, pr] = q.top(); q.pop();
                    // cout << dist << endl;
                    int row = pr.first, col = pr.second;
                    // cout << row << " : " << col << " : " << dist << endl;
                    if(row == destination.first && col == destination.second) {
                        return dist;
                        // MinEffort = min(MinEffort, dist);
                        // cout << MinEffort << endl;
                        // // break;
                        // continue; 
                    }
    
                    for(auto p : adj){
                        int nextRow = row+p.first, nextCol = col+p.second;
    
                        if(nextRow >=0 && nextRow < heights.size() && nextCol >=0 && nextCol<heights[row].size()){
                            int cal_dist = abs(heights[row][col]-heights[nextRow][nextCol]);
    
                            if( max(cal_dist, dist) < grid_visited[nextRow][nextCol]){
                                grid_visited[nextRow][nextCol] = cal_dist;
                                q.push({max(cal_dist,dist), {nextRow, nextCol}});
                            }
                            // else if(cal_dist < grid_visited[nextRow][nextCol]){
                            //     grid_visited[nextRow][nextCol] = cal_dist;
                            //      if(cal_dist < dist){
                            //         cal_dist = dist;
                            //     }
                            //     q.push({cal_dist, {nextRow, nextCol}});
                            // }
                        }
                    }
            }
            return -1;
        }
    };