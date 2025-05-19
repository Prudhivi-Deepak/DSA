#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int IsPossibleDays(vector<int>& weights, int days, int capacity){
            int days_count=0, w=0,prev_w=0, i; 
            for(i=0; i<weights.size(); i++){
    
                if(weights[i] > capacity) return false;
    
                w += weights[i];
    
                if(w==capacity){
                    days_count +=1;
                    w = 0;
                }
                else if(w > capacity){
                    days_count +=1;
                    w -= prev_w;
                }
                prev_w = w;
            }
            //hanlding the rem part of weight
            if(w!=0 && w<capacity){
                days_count +=1;
                // w = 0;
            }
            // else if(w > capacity){
            //     days_count +=1;
            //     w = weights[i];
            // }
            // cout << "days count : " << days_count << " capacity : " << capacity << endl;
            return days_count <= days;
    
        }
        int shipWithinDays(vector<int>& weights, int days) {
            int min_weight = weights[0], max_weight = weights[0], mid;
    
            for(int i=1; i<weights.size(); i++){
                min_weight = min(min_weight, weights[i]);
                max_weight += weights[i];
            }
    
            if(days == 1 ) return max_weight;
    
            while(min_weight <= max_weight){
                mid = min_weight + (max_weight - min_weight)/2;
                // cout << min_weight << " : " << max_weight << endl;
                if(IsPossibleDays(weights, days, mid)) max_weight = mid-1;
                else min_weight = mid+1;
            }
            return min_weight;
        }
    };