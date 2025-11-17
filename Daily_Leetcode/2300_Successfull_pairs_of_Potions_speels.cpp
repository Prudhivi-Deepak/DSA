#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(int spell, vector<int>& potions, long long success){
        int l=0, r = potions.size()-1;
        // cout << success << " : " << spell << " = " << ceil((long double)success/spell) << endl;
        // lower bound means find an minimum index element with that ele value >= given key
        while(l<=r){
            int mid = l+(r-l)/2;
            if(potions[mid]>=ceil((long double)success/spell)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sort mlogm ==> get (modified)lower bound index of success*pair[i] ==>
        //                                           pairs[i] = take (n-index) 
        // 5 1 3
        // 1 2 3 4 5
        // 0 1 2 3 4
        // 
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> pairs(n, 0);
        // cout << lowerBound(3, potions, success) << endl;

        for(int i=0; i<n; i++){
            int lb = lowerBound(spells[i], potions, success);
            // cout << lb << endl;
            // cout << m-lb << endl;
            pairs[i] = (m>=lb) ? m-lb : 0;
            // cout << pairs[i] << endl;
        }

        return pairs;
        
    }
};