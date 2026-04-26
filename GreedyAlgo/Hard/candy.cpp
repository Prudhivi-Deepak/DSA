class Solution {
public:
    int candy(vector<int>& ratings) {
        //your code goes here
        int i=1, downPeak = 0, upPeak = 1, n = ratings.size(), totalCandies = 1;

        while(i<n){

            // calculate for flat
            while(i<n && ratings[i-1] == ratings[i]){
                totalCandies += 1; i++;
            }

            // calculate for upward 
            upPeak = 1;
            while(i<n && ratings[i-1] < ratings[i]){
                upPeak++; i++;
                totalCandies += upPeak;
            }

            // calculate downward
            downPeak = 0;
            while(i<n && ratings[i-1] > ratings[i]){
                downPeak++; i++;
                totalCandies += downPeak;
            }

            if(downPeak+1 > upPeak) {
                totalCandies -= upPeak;
                totalCandies += downPeak+1;
            }
        }
        return totalCandies;
    }
};