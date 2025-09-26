#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(int i, int j, vector<vector<int>> &image, int newColor, int initialColor){
            image[i][j] = newColor;
    
            vector<pair<int, int>> directions = {{-1,0}, {0,1}, {0,-1},{1,0}};
            for(auto d:directions){
                if(i+d.first >=0 && j+d.second >=0 && i+d.first < image.size() && j+d.second < image[i].size() &&
                    image[i+d.first][j+d.second]==initialColor){
                    dfs(i+d.first, j+d.second, image, newColor, initialColor);
                }
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            if(image[sr][sc]==color) return image;
            dfs(sr, sc, image, color, image[sr][sc]);
            return image;
        }
    };