class Solution{
    public:
    bool static comparator(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }

    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        //          0  1  2  3  4  5 
        // Start = [1, 3, 0, 5, 8, 5]
        // End   = [2, 4, 6, 7, 9, 9]

        // sort by start time or end time
        // 0, 6
        // 1, 2
        // 3, 4
        // 5, 7
        // 5, 9
        // 8, 9

        // sort by end time prev end time  = 0
        // 1, 2 --> end in less time so take it  +1 prev end = 2
        // 3, 4 --> start time is 3 sur etake it +1 prev end = 4
        // 0, 6 --> start at 0, prev end is > curr start -- dont take
        // 5, 7 --> start at 5, prev end is 4 take it +1 prev end  = 7
        // 5, 9 --> start at 5 prev end is 7 -- dont take
        // 8, 9 --> start at 8 prev end is 7 take it +1
        // return 4

        vector<pair<int,int>> meetings;
        for(int i=0; i<start.size(); i++){
            meetings.push_back({start[i], end[i]});
        }

        sort(meetings.begin(), meetings.end(), comparator);

        int prev_end = 0, meetings_cnt = 0;
        for(int i=0; i<meetings.size(); i++){
            if(prev_end < meetings[i].first){
                prev_end = meetings[i].second;
                meetings_cnt++;
            }
        }
        return meetings_cnt;
    }
};