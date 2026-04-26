int mod = 1e9+7;
class Solution{
	public:
	int f(int i, int k, vector<int>&arr, vector<vector<int>> &dp){

		if(k==0) return 1;
		if(k<0) return 0;

		if(i==0){
			if(arr[0]==k) return 1;
			else return 0;
		}

		if(dp[i][k]!=-1) return dp[i][k];

		int NotTake = f(i-1, k, arr, dp);
		int Take = f(i-1, k-arr[i], arr, dp);

		return dp[i][k] = NotTake+Take;
	}

	int perfectSum(vector<int>&arr, int K){
		int n = arr.size();

		vector<vector<int>> dp(n, vector<int>(K+1, 0));

		vector<int> prev(K+1, 0), curr(K+1, 0);

		// i goes from n-1 to 0 in f 
		// base case dp[i][0] = 1;
		// dp[0][arr[0]] = 1

		// for(int i=0; i<n; i++){
			// dp[i][0] = 1;
			prev[0] = 1;
		// }

		if(K>= arr[0]) prev[arr[0]] = 1;

		for(int i=1; i<n; i++){
			for(int k=0; k<=K; k++){
				// int NotTake = dp[i-1][k];
				int NotTake = prev[k];
				int Take = 0;
				if(k>=arr[i]) 
					// Take = dp[i-1][k-arr[i]];
					Take = prev[k-arr[i]];

				// dp[i][k] = (NotTake+Take)%mod;
				curr[k] = (NotTake+Take)%mod;
			}
			prev = curr;
		}
		// return dp[n-1][K]%mod;
		return prev[K]%mod;
		
		// return f(n-1, K, arr, dp);
	}
};