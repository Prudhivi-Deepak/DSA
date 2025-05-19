#include <bits/stdc++.h>
using namespace std;


class Solution {

    public:
        bool IsPossible(int n, vector<int> bloomDay, int k, int m, int day){
            int bloomed = 0, no_of_bloomed_groups = 0;
            for(int i=0; i<n; i++){
                if(bloomDay[i]<=day) bloomed++;
                else{
                    no_of_bloomed_groups+= floor((double)bloomed/k);
                    bloomed = 0;
                }
            }
            no_of_bloomed_groups+= floor((double)bloomed/k);
            return no_of_bloomed_groups>=m;
        }
        int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();
            if((long)k*m > n) return -1;
            int left = bloomDay[0], right = bloomDay[0], mid;
            for(int i=1; i<n; i++){
                left = min(left, bloomDay[i]);
                right = max(right, bloomDay[i]);
            }
    
            while(left <= right){
                mid = left+(right-left)/2;
                if(IsPossible(n, bloomDay,k, m,mid)) right = mid-1;
                else left = mid+1;
            }
            return left; 
        }
    };