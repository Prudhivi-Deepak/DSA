class Solution{
public:
    bool f(int i, vector<int>arr, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i<0 || target<0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        int notTake = f(i-1, arr, target, dp);
        int take = f(i-1, arr, target-arr[i],  dp);

        return dp[i][target] = notTake || take;
    }

    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        vector<int> prev(target+1, 0), curr(target+1, 0);

        // i goes from n-1 to 0 in f
        // base case is d[i][target] = true or 1;
        // for(int i=0; i<n; i++){
            // dp[i][0] = 1;
            prev[0] = 1;
        // }

        if(arr[0] <= target) 
        // dp[0][arr[0]] = 1;
            prev[arr[0]] = 1;

        for(int i=1; i<n; i++){
            for(int currSum=0; currSum<=target; currSum++){
                // int notTake = dp[i-1][currSum];
                int notTake = prev[currSum];
                int take = 0;
                if(currSum>=arr[i])
                    // take = dp[i-1][currSum-arr[i]];
                    take = prev[currSum-arr[i]];

                // dp[i][currSum] = notTake || take;
                curr[currSum] = notTake || take;
            }
            prev = curr;
        }
        // return dp[n-1][target];
        return prev[target];

        // return f(n-1, arr, target, dp);
    }
    bool equalPartition(int n, vector<int> arr) {
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += arr[i];
        }

        if(totalSum%2) return false;
        else return isSubsetSum(arr, totalSum/2);

    }
};
