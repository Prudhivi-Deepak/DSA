class Solution {
	public:
		// 1 3 4 5 n = 7
		// 0 1 3 4 5 7
		// 
		// i=0 .... j=3
		// k=1 2 
		// 0 1   1 3   or  0 2  2 3
		// len = 1-0

		int f(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){

			// cout << i << " : " << j << endl;

			if(i+1==j) return 0;

			if(dp[i][j]!=-1) return dp[i][j];

			int min_cost = 1e9;

			for(int k=i+1; k<j; k++){
				min_cost = min(min_cost, cuts[j]-cuts[i] + f(i, k, cuts, dp) + f(k, j, cuts, dp));
				// cout << min_cost << endl;
			}

			return dp[i][j] = min_cost;
		}

		int minCost(int n, vector<int>& cuts){
            //your code goes here
			cuts.insert(cuts.begin(), 0);
			cuts.push_back(n);
			int cutSize = cuts.size();

			sort(cuts.begin(), cuts.end());

			vector<vector<int>> dp(cutSize+1, vector<int>(cutSize+1, 0));

			//  i, j goes from 0 to cutSize-1, cutSize-1 to i+1
			// base case: 0 when i+1==j 

			for(int i=cutSize-1; i>=0; i--){
				for(int j=i+2; j<cutSize; j++){
					int min_cost = 1e9;
					for(int k=i+1; k<j; k++){
						min_cost = min(min_cost, cuts[j]-cuts[i] + dp[i][k] + dp[k][j]);
					}

					dp[i][j] = min_cost;
				}
			}

			return dp[0][cutSize-1];


			// return f(0, cutSize-1, cuts, dp);
		}
};