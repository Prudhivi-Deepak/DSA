//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& Intervals, vector<int>& newInterval){
        //your code goes here
        //  [ [1, 2] , [3, 5] , [6, 7] , [8,10] ]
        //             [4, 8]

// 4,8 ===> 1,2 ith second < new interval first ==> insert ith 
//          3,5 ith first < new interval second ==> insert new interval
//          6,7 else i means its between the intervals so take min(ith[0], new Interval[0]), max(ith[1], new Interval[1])
//          8,10

        int n = Intervals.size();
        vector<vector<int>> finalIntervals;
        vector<int> currInterval = newInterval;
        
        for(int i=0; i<n; i++){
            // curr interval last is less than new interval start so 
            if(Intervals[i][1] < newInterval[0]){
                finalIntervals.push_back(Intervals[i]);
            }
            else if(Intervals[i][0] > newInterval[1]){
                finalIntervals.push_back(newInterval);
                newInterval = Intervals[i];
            }
            else{
                newInterval[0] = min(Intervals[i][0], newInterval[0]);
                newInterval[1] = max(Intervals[i][1], newInterval[1]);
            }
        }
        finalIntervals.push_back(newInterval);
        return finalIntervals;
    }

    vector<vector<int>> insertFirstTry(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> newIntervals = newInterval;
        vector<vector<int>> ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        int flag = 1;
        for(auto i: intervals){
            if(i[1] < newInterval[0]){
                // cout << i[0] << ": "<< i[1] << endl;
                ans.push_back(i);
            }
            else if(newInterval[1] < i[0]){
                // cout << i[0] << ": "<< i[1] << endl;
                if(flag) ans.push_back(newIntervals);
                ans.push_back(i);
                flag=0;
            }
            else{
                newIntervals[0] = min(newIntervals[0], i[0]);
                newIntervals[1] = max(newIntervals[1], i[1]);
            }
        }
        if(flag) ans.push_back(newIntervals);
        return ans;
    }
};