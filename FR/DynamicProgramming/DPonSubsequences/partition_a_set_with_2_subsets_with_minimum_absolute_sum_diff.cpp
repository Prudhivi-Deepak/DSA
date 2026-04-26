class Solution{
  public:
	int f(int i, int currSum, int totalSum, vector<int>&arr, int n, vector<vector<int>> &dp){

		if(i==0) return abs(2*currSum - totalSum);

		if(dp[i][currSum]!=-1) return dp[i][currSum];

		int NotTake = f(i-1, currSum, totalSum, arr, n, dp);
		int Take = 1e9;
		if(currSum>=arr[i]) Take =  f(i-1, currSum-arr[i], totalSum, arr, n, dp);

		return dp[i][currSum] = min(NotTake, Take);
	}

	int minDifference(vector<int>&arr, int n)  { 

		int totalSum = 0;
		for(int i=0; i<n; i++) totalSum += arr[i];

		vector<vector<int>> dp(n, vector<int>(totalSum+1, 0));

		// i goes from n-1 to 0 in f
		// base case is  dp[0][currSum] = abs(2*currSum-totalSum)
		for(int currSum=0; currSum<=totalSum; currSum++){
			dp[0][currSum] = abs(2*currSum - totalSum);
		}

		for(int i=1; i<n; i++){
			for(int currSum=0; currSum<=totalSum; currSum++){
				int NotTake = dp[i-1][currSum];
				int Take = 1e9;
				if(currSum>=arr[i]) Take =  dp[i-1][currSum-arr[i]];
				dp[i][currSum] = min(NotTake, Take);
			}
		}
		return dp[n-1][totalSum];

		// return f(n-1, totalSum, totalSum, arr, n, dp);
	} 
};
