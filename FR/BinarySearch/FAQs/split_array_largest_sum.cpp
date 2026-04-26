class Solution {
public:

    int subsetsCount(vector<int> &a, int largestSum){

        int subsets = 1, currSum = 0;

        for(int i=0; i<a.size(); i++){
            currSum += a[i];
            if(currSum > largestSum){
                subsets++;
                currSum = a[i];
            }
        }

        // if(currSum!=0 && currSum<largestSum) subsets++;

        return subsets;
    }

    int largestSubarraySumMinimized(vector<int> &a, int k) {

        // we can split the array into k times (k consecutive subsets)
        // given the largest sun they each subset can acehive try to return how many subsets formed
        // what is the range of sum - minimum element and max sum
        // subsets count <= k valid we need minimum r = mid-1;

        int l = 0, r = 0, mini = INT_MAX;

        for(int i : a){
            l = max(l, i);
            r += i;
        }

        mini = r;

        cout << l << " : " << r <<endl;

        while(l<=r){

            int mid = l+(r-l)/2;

            int subsets = subsetsCount(a, mid);

            if(subsets <= k){
                mini = min(mini, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return mini;
    }
};