class Solution {
public:
    long long gethoursPerKbananas(vector<int> nums, int k){
        long long hours = 0;

        for(auto i: nums){
            // cout << ceil((double)i/k) << " " ;
            hours += ceil((double)i/k);
        }

        // cout << k << " : " << hours << endl;

        return hours;
    }

    int findmax(vector<int> &nums){
        int maxi = INT_MIN;
        for(auto i : nums){
            maxi = max(i, maxi);
        }
        // cout << maxi << endl;
        return maxi;
    }

    int minimumRateToEatBananas(vector<int> nums, int h) {

        // we have to find how many bananas monkey should eat per hr given h hours
        // it can be 1, 2, 3, 4, 5.............max bananas(nums) in 1 hr to satisfy with in h hours
        // range based search --> BS 
        // what is the range 1 to how many bananas (max bananas in nums constraint in problem)

        int l = 1, r = findmax(nums), miniBananas = INT_MAX;

        while(l<=r){
            int mid = l+(r-l)/2;

            long long hoursPerKbananas = gethoursPerKbananas(nums, mid);

            if(hoursPerKbananas <= h ){
                miniBananas = min(miniBananas, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return miniBananas;
    }
};
