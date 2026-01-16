#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
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
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        int i=0, res = -1;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hset;

        for(int i=0; i<hFences.size(); i++){
            for(int j=i+1; j<hFences.size(); j++){
                hset.insert(hFences[j] - hFences[i]);
            }
        }

        for(int i=0; i<vFences.size(); i++){
            for(int j=i+1; j<vFences.size(); j++){
                // vset.push_back(vFences[j] - vFences[i]);
                int currLen = vFences[j] - vFences[i];
                if(hset.count(currLen) && res<currLen){
                    res = currLen;
                }
            }
        }
        if(res==-1) return -1;
        return 1ll*res*res%MOD;
    }
};