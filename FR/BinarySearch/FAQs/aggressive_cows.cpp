class Solution {
public:

    int placeCows(vector<int> &nums, int dist){
        int totalCows = 1, prev_pos = 0;

        for(int i =1; i<nums.size(); i++){
            if(nums[i]-nums[prev_pos] >= dist){
                prev_pos = i;
                totalCows++;
            }
        }
        return totalCows;
    }

    int aggressiveCows(vector<int> &nums, int k) {

        // we need to maximize the minimum distance between the k cows placed at stalls/position in array
        // we have to return the distance right --> maximized(min dist between cows)
        // so try all distances to find the answer in the range (min diff in array, max diff in array)
        // so BS on the range above for every distance we calculate how many cows can be placed okay

        sort(nums.begin(), nums.end());

        int l = 0, r = nums[nums.size()-1]-nums[0], validDist = INT_MAX;

        while(l<=r){

            int mid = l+(r-l)/2;

            int cows = placeCows(nums, mid);
            if(cows >= k){
                validDist = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return validDist;        
    }
};