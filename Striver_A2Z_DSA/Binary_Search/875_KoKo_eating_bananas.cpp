#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long calhrs(vector<int> &piles, int rate){
            // cout << "rate : " << rate << endl;
            long totalhrs = 0;
            for(int i=0; i<piles.size(); i++){
                // cout << ceil((double)piles[i]/rate) << endl;
                totalhrs += ceil((double)piles[i]/rate);
            }
            // cout << "totalhrs : " << totalhrs << endl;
            return totalhrs;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int max_ele = piles[0];
            for(int i=1; i<piles.size(); i++){
                max_ele = max(max_ele, piles[i]);
            }
    
            long left = 1, right = max_ele, mid;
    
            while(left <= right){
                mid = left+ (right-left)/2;
    
                long reqhrs = calhrs(piles, mid);
    
                // cout << mid << ": "<< reqhrs << endl;
    
                if(reqhrs <= h) right = mid-1;
                else left = mid+1;
            }
    
            return left;
        }
    };