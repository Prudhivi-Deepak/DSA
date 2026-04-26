class Solution{
	public:
	int f(int i, vector<int>& coins, int amount, vector<vector<int>> dp){
		if(amount==0) return 0;
		if(i==0){
			if(amount%coins[0]==0) return amount/coins[0];
			else return -1;
		}

		if(dp[i][amount] != -1) return dp[i][amount];

		int NotTake = f(i-1, coins, amount, dp);
		int take = 1e9;
		if(amount>=coins[i])
			take = 1+f(i, coins, amount-coins[i], dp);
		
		return dp[i][amount] = min(NotTake, take);
	}

	int MinimumCoins(vector<int>& coins, int Amount) {
		int n = coins.size();

		// vector<vector<int>> dp(n, vector<int>(Amount+1, 1e9));

		vector<int> prev(Amount+1, 1e9), curr(Amount+1, 1e9);

		// i goes from n-1 to 0 in f 
		// base case : for any amount amount%coins[0] dp[0][amount] = amount/coins[0]

		for(int amount=0; amount<=Amount; amount++){
			if(amount%coins[0]==0){
				// dp[0][amount] = amount/coins[0];
				prev[amount] = amount/coins[0];
			}
		}

		for(int i=1; i<n; i++){
			for(int amount=0; amount<=Amount; amount++){
				// int NotTake = dp[i-1][amount];
				int NotTake = prev[amount];
				int take = 1e9;
				if(amount>=coins[i])
					// take = 1+dp[i][amount-coins[i]];
					take = 1+curr[amount-coins[i]];
				
				// dp[i][amount] = min(NotTake, take);
				curr[amount] = min(NotTake, take);
			}
			prev = curr;
		}

		// return dp[n-1][Amount] == 1e9 ? -1 : dp[n-1][Amount];
		return prev[Amount] == 1e9 ? -1 : prev[Amount];

		// return f(n-1, coins, amount, dp);
    }
};