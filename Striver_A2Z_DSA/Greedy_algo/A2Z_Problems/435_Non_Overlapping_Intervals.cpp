#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& Intervals) {
        //your code goes here

        // (1,2), (2,3), (3,4), (1,3)
        // sort by starting times
        // (1,2), (1,3), (2,3), (3,4)
        // si = 1, ei = 2 keep
        // si = 1, ei = 3 remove overlapping so keep the lesser one
        //     si = 2, ei = 3  keep
        // si = 3, ei = 4 keep

        // (1,3), (1,4), (3,4), (3,5), (4,5)
        
        // (1,3)
        // (1,3)    (1,4)  ==> 3>1 so overlapping, 


        sort(Intervals.begin(), Intervals.end());
        // vector<vector<int>> finalIntervals;
        int n = Intervals.size(), cnt = 0;
        vector<int> prev;

        for(int i=0; i<n; i++){
            // if(finalIntervals.empty() || finalIntervals.back()[1] <= Intervals[i][0] ){
            if(prev.empty() ||prev[1] <= Intervals[i][0] ){
                // finalIntervals.push_back(Intervals[i]);
                prev = Intervals[i];
                cnt++;
            }
            else{
                // finalIntervals.back()[1] = min(finalIntervals.back()[1], Intervals[i][1]);
                prev[1] = min(prev[1], Intervals[i][1]);
            }
        }

        // for(auto p : finalIntervals){
        //     cout << "(" << p[0] << " " << p[1] << "), ";
        // }
        // cout << endl;
        return n - cnt;
    }

    bool static customcomparator(vector<int> v1, vector<int> v2){
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervalsFirstTry(vector<vector<int>>& intervals) {
        int cnt = 1, n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2){
            return v1[1] < v2[1];
        });
        int last_meeting_end_time = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= last_meeting_end_time){ //curr interval start time should be after last meeting end time
                cnt++;
                last_meeting_end_time = intervals[i][1];
            }
        }
        return n-cnt;
    }
};