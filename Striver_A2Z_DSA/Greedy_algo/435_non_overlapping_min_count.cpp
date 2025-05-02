
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool static customcomparator(vector<int> v1, vector<int> v2){
            return v1[1] < v2[1];
        }
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            int cnt = 1, n = intervals.size();
            sort(intervals.begin(), intervals.end(), customcomparator);
            // sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2){
            //     return v1[1] < v2[1];
            // });
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