#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool static customComparator(pair<int,int> p1, pair<int,int> p2){
        return p1.second < p2.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here

        // end sort and get small start

        // 1 3 0 5 8 5
        // 2 4 6 7 9 9

        // (1,2), (3,4), (0,6), (5,7), (8,9), (5,9)

        // (1,2), (3,4), (0,6), (5,7), (8,9), (5,9)

        // [0 1 2 3 4 5]
        // (1,2)
        // si = 1, ei = 2
        // si = 3, ei = 4
        // 0 6 ===> 4>0 so we cant have this meeting
        // si = 5, ei = 7
        // si = 8, ei = 9
        // 5 9 ===> 9>5 so we cant have this meeting

        int count = 1;

        vector<pair<int,int>> intervals;
        int n = start.size();
        for(int i=0; i<n; i++){
            intervals.push_back({start[i], end[i]});
        }

        sort(intervals.begin(), intervals.end(), customComparator);

        int si = intervals[0].first, ei = intervals[0].second;

        for(int i=1; i<n; i++){
            if(ei<intervals[i].first){
                count++;
                si = intervals[i].first;
                ei = intervals[i].second;
            }
        }
        return count;        
    }
};