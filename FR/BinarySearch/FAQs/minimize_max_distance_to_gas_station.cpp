class Solution {
public:
    int gasStations(vector<int> &arr, long double distance){

        int gas = 0;

        for(int i=0; i<arr.size()-1; i++){

            gas += ceil((arr[i+1]-arr[i])/distance)-1;

            // int new_gas = (arr[i+1]-arr[i])/distance;
            // long double double_new_gas = (arr[i+1]-arr[i])/distance;

            // if(new_gas == double_new_gas){
            //     // properly divisible not able to put that new_gas number gases
            //     // like 2-1 / 0.5 = 1/0.5 = 2 
            //     // but 1 1.5 2 --> only 1.5 is valid gas stations --> not 2
            //     new_gas--;
            // }
            // gas += new_gas;
        }

        return gas;
    }
    long double minimiseMaxDistance(vector<int> &arr, int k) {

        // we have to place k gas stations on x-axis
        // minimize the maximum distance between adj gas stations
        // the distance can be min dist to max dist 
        // create a function given x-axis position and distance how many gas stations can be placed?

        long double l = 0, r = INT_MIN;

        for(int i=1; i<arr.size(); i++){
            r = ((long double) arr[i]-arr[i-1] > r) ? (long double) arr[i]-arr[i-1] : r;
        }

        long double dist = r;

        // cout << r << endl;

        while((long double)r-l > 1e-6){

            long double mid = l+(r-l)/2.0;

            int gas = gasStations(arr, mid);

            // cout << gas << endl;

            if(gas <= k){
                dist = min(dist, mid);
                r = mid;
            }
            else l = mid;
        }
        // cout << l << r << endl;
        return dist;       
    }
};