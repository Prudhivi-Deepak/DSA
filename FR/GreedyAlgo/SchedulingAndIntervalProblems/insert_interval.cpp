class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
        //your code goes here

        vector<vector<int>> finalIntervals;

        for(int i=0; i<Intervals.size(); i++){
            auto currInterval = Intervals[i];
            if(currInterval[1] < newInterval[0] ){
                // means no overlapping push the currInterval
                finalIntervals.push_back(currInterval);
            }
            else if(newInterval[1] < currInterval[0]){
                // means no overlapping push the newInterval and make currInterval as newInterval
                finalIntervals.push_back(newInterval);
                newInterval = currInterval;
            }
            else{
                // there is a overlapping make a new Interval
                newInterval[0] = min(newInterval[0], currInterval[0]);
                newInterval[1] = max(newInterval[1], currInterval[1]);
            }
        }

        finalIntervals.push_back(newInterval);
        return finalIntervals;

        // create an empty array/vector to store the resulting meetings
        // if possible while inserting we can merge the otehr intervals too

        // // [1, 2] , [3, 5] , [6, 7] , [10,11]

        // 8, 9

        // 1, 2
        // 3, 5
        // 6, 7

        // 10, 11
        // 10<8 false get min(10, 8), max(9, 11) = 8, 11 --> which is wrong

        // instead push new interval if 
        // new interval end < curr start
        // and make curr Interval as new interval


        // take first one currInterval = 1, 2
        // new interval = 4, 8
        // 2<4 so insert into our result array [1,2]
        // second interval = 3, 5
        // 5<4 --> false so wait for valid entry
        // so new interval is min(3 (second interval start), max( 5 second interval end, 8), 8 ==> 3, 8 changed and don't push th second interval yet
        // third interval 6, 7, new interval = 3, 8
        // 7 < 3 --> false so take new interval again = min(6, 3), max(7, 8) = 3, 8
        // fourth interval 8, 10
        // 8 < 8 --> false so take new interval = min(8, 3), max(10, 8) = 3, 10
        // now we finished all interval push new interval as well


        

    }
};