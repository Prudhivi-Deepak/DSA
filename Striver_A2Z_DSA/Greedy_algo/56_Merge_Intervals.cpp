
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            // int1 int2 int3
            // 1,3 | 2,6 | 4, 7 | 5,10 | 8, 10 | 15, 18
            //  1 3
            sort(intervals.begin(), intervals.end());
            // vector<int> interval = intervals[0];
            vector<vector<int>> new_intervals;
            new_intervals.push_back(intervals[0]);
            int n = intervals.size();
            for(int i=1; i<n; i++){
                //compare interval with every ith interval and modify if overlaps else push to new intervals
    
                if(new_intervals.back()[1] >= intervals[i][0]){
                    new_intervals.back()[0] = min(new_intervals.back()[0], intervals[i][0]);
                    new_intervals.back()[1] = max(new_intervals.back()[1], intervals[i][1]);
                }
                else{
                    new_intervals.push_back(intervals[i]);
                }
    
                // if(interval[1] >= intervals[i][0]){
                //     interval[0] = min(interval[0], intervals[i][0]);
                //     interval[1] = max(interval[1], intervals[i][1]);
                // }
                // else{
                //     new_intervals.push_back(interval);
                //     interval = intervals[i];
                // }
            }
            // new_intervals.push_back(interval);
    
            return new_intervals;
        }
    };