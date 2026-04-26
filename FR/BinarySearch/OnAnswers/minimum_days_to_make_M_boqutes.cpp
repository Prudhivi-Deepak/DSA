class Solution {
public:
    int makeBouquets(vector<int> &nums, int day, int k){

        // given the day which may be there some roses already bloomed
        // so day is 7 then all roses <7 is bloomed by 7th day

        int totalBouquets = 0, flowers = 0;
        // we need adjacent k roses
        // means we need k adjacent values where <= day
        for(int i : nums){
            if(i<=day) flowers++;
            else flowers = 0;
            if(flowers%k==0){
                // cout << flowers << "/" << k << endl;
                totalBouquets+=(flowers/k);
                flowers = 0;
            }
        }

        if(flowers!=0 && flowers%k==0) totalBouquets+=(flowers/k);
        // cout << day << " : " << totalBouquets << endl;
        return totalBouquets;
    }

    int findmax(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i: nums){
            maxi = max(maxi, i);
        }
        return maxi;
    }

    int roseGarden(int n,vector<int> nums, int k, int m) {

        // ith rose blooms on nums[i]th day
        // exactly k adjacent bloomed roses are required to make a single bouquet
        // asking us to find min no. of days required to make atleast m bouquets (1bouquet = k roses)
        // return -1 if not possible

        // now we know for m bouquets we need m*k roses (if nums.size() < m*k return -1)
        // it's asking how many days--> try all days in the range (1 to maximum day to rose to bloom (max value in nums))

        // try BS on days to find if that day is enough to make m*k bouquets


        int l = 1, r = findmax(nums), validDays = INT_MAX;

        if(m*k > nums.size()) return -1;

        while(l<=r){
            int mid = l+(r-l)/2;

            int bouquets = makeBouquets(nums, mid, k);

            if(bouquets>=m){
                validDays = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return validDays;
    }
};