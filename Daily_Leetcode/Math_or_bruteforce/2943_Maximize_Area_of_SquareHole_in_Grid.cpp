#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxcontinuousSubArray(vector<int> &bars){
        int maxLen = 1, currLen = 1, i=1, prev = bars[0];
        while(i<bars.size()){
            if(prev+1 == bars[i]) currLen++;
            else currLen=1;

            if(maxLen < currLen) maxLen = currLen;
            prev = bars[i];
            i++;
        }
        return maxLen+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // n = 2+2 = 4
        // m = 3+2 = 5

        // diff between the hbars & vbars after removing the bars from the given array
        // find maxhbar dist
        // find maxvbar dist

        // [2, 3, 4, 5, 6, 8, 9, 10, 13, 14, 15, 16]
        // 2, 3, 4, 5, 6
        // 8, 9, 10
        // 13, 14, 15, 16
        // vector<int> bars = {2, 3, 4, 5, 6, 7, 9, 10, 13, 14, 15, 16};

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hBarDiff = maxcontinuousSubArray(hBars);
        int vBarDiff = maxcontinuousSubArray(vBars);

        // cout << hBarDiff << " : " << vBarDiff << endl;

        if(hBarDiff < vBarDiff){
            return hBarDiff*hBarDiff;
        }
        return vBarDiff*vBarDiff;
    }
};