class Solution {
public:
    bool static comparator(vector<int> &v1, vector<int> &v2){
        if(v1[1]==v2[1]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
        //your code goes here
        // prev end = 0
        // sort by end time always
        // 1, 2 --> 0 < 1 curr start okay prev end = 2
        // 1, 3 --> 2 <= 1 false +1
        // 2, 3 --> 2 <= 2 true okay prev end = 3
        // 3, 4 --> 3 <= 3 true okay
        // return 1

        sort(Intervals.begin(), Intervals.end(), comparator);
        int prev_end = 0, non_overlap_jobs = 0;
        for(int i=0; i<Intervals.size(); i++){
            if(prev_end > Intervals[i][0]){
                non_overlap_jobs++;
            }
            else{
                prev_end = Intervals[i][1];
            }
        }
        return non_overlap_jobs;
    }
};