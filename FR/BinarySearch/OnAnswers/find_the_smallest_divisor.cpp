class Solution {
public:

  int getDivisionSum(vector<int> &nums, int divisor){
    int sum = 0;
    for(auto i : nums){
        sum += ceil((double)i/divisor);
    }
    // cout << divisor << " : " << sum <<endl;
    return sum;
  }

  int smallestDivisor(vector<int> &nums, int limit) {

        // find sum of all division by a divisor  = sum 
        // this sum should be less < limit --> here divisor should be as small as possible

        // divisor range is from 1 to 1e6 (max number range)

        int l = 1, r = 1e6, divisor = INT_MAX;

        while(l<=r){

            int mid = l+(r-l)/2;
            int divisionSum = getDivisionSum(nums, mid);
            if(divisionSum <= limit ){
                divisor = min(divisor, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return divisor;
    }
};