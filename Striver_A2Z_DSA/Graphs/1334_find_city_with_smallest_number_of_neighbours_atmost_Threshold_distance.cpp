#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            vector<vector<int>> matrix(n, vector<int>(n, INT_MAX/2));
    
            for (int i = 0; i < n; ++i) {
                matrix[i][i] = 0; 
            }
    
            for(int e=0; e<edges.size(); e++){
                matrix[edges[e][0]][edges[e][1]] = edges[e][2];
                matrix[edges[e][1]][edges[e][0]] = edges[e][2];
            }
    
            int cnt = 0, cntMax = 1e9, city = -1;
    
            for(int k=0; k<n; k++){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(i==j) 
                            matrix[i][j] = 0;
                        else
                            matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                    }
                }
            }
    
            for(int i=0; i<n; i++){
                cnt = 0;
                for(int j=0; j<n; j++){
                    if(i!=j && matrix[i][j] <= distanceThreshold){
                        cnt++;
                    }
                }
                
                if(cnt  < cntMax){
                    cntMax = cnt;
                    city = i;
                }
                else if(cnt == cntMax){
                    // city = max(city, i);
                    city = i;
                }
            }
            return city;
        }
    };