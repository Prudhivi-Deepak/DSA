#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxside = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int height = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                maxside = max(maxside, min(width,height));
            }
        }
        return 1LL*maxside*maxside;
    }
};