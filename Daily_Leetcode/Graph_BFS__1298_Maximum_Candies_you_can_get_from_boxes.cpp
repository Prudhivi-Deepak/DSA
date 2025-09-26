#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
            
            vector<int> hashKeys = status;
            vector<int> visited(status.size(), 0), hasBoxes(status.size(), 0);
            int totalCandies = 0;
            queue<int> q; // to store all boxes
    
            //push initial boxes
            for(int i : initialBoxes){
                hasBoxes[i]=1;
                q.push(i);
            }
    
            while(!q.empty()){
                int currBox = q.front(); q.pop();
    
                // if(visited[currBox]==1) continue;
    
                if(hashKeys[currBox]==1 && visited[currBox]==0){
                    visited[currBox] = 1;
                    totalCandies += candies[currBox];
    
                    //push next boxes inside this box
                    for(int k : containedBoxes[currBox]){
                        if(visited[k]==0 && hasBoxes[k]==0){
                            hasBoxes[k] =1;
                            q.push(k);
                        }
                    }
    
                    //push the keys if they are not opened or visited yet
                    for(int k : keys[currBox]){
                        hashKeys[k]=1;
                        if(visited[k]==0 && hasBoxes[k]==1){
                            q.push(k);
                        }
                    }
                }
            }
            return totalCandies;
        }
    };