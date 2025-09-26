
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int l=0, r=height.size()-1, lmax=0, rmax=0,total=0;
    
            while(l<r){
                // cout << l << " : " << r << endl;
                while(l<r && height[l]<=height[r]){
                    lmax = max(lmax, height[l]);
                    total += lmax-height[l];
                    l++;
                }
    
                while(l<r && height[l] > height[r]){
                    rmax = max(rmax, height[r]);
                    total += rmax-height[r];
                    r--;
                }
    
            }
    
            return total;
        }
    };