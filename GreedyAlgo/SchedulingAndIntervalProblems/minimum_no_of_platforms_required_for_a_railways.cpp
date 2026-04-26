class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        // Arrival   = [900, 940, 950, 1100, 1500, 1800] 
        // Departure = [910, 1200, 1120, 1130, 1900, 2000]
        
        // sort both array seperately

        // arrival = 900, 940, 950, 1100, 1500, 1800
        // dep     = 910, 1120, 1130, 1200, 1900, 2000

        // different times different events, i can simply count if A or D events happened in untill this time
        // like count  = 1 for first arrival then check for next event Arrival or Departure
        // if A cnt++ 
        // if D cnt--
        // take max cnt in the course of all events
        // return maxcnt

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int a=1, d = 0, currP = 1, maxP = 1, n = Arrival.size();

        while(a<n){

            if(Arrival[a] <= Departure[d]){
                currP++;
                a++;
            }
            else{
                currP--;
                d++;
            }
            maxP = max(maxP, currP);
        }
        return maxP;
    }
};