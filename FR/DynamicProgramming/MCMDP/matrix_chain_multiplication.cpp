class Solution{
	public:
		//10 15 20 25
		// A1*(A2*A3)

		// 0  1     1  2    2  3
		// 10x15 * (15x20 * 20x25 )
		

		// (A1*A2)*A3
		// (10x15 * 15x20) * 20x25
		//  0  1    1  2     2 3

		int f(int i, int j, vector<int>& nums, vector<vector<int>> dp){
			// 0<i<n

			if(i+1==j) return 0;

			if(dp[i][j]!=-1) return dp[i][j];

			int min_multiplication = 1e9;
			for(int k=i+1; k<j; k++){
				// k = 1, 2
				// k=1
				
				min_multiplication = min(min_multiplication, nums[i]*nums[k]*nums[j] + f(i, k, nums, dp) + f(k, j, nums, dp));
			}

			return dp[i][j] =  min_multiplication;
		}

		int matrixMultiplication(vector<int>& nums){
            //your code goes here
			int n = nums.size();

			vector<vector<int>> dp(n, vector<int>(n, 0));

			// i goes from 0 to j-1, j goes from n-1 to i+1
			// base case: dp[i+1][j] = 0

			for(int i=n-1; i>=0; i--){
				for(int j=i+2; j<n; j++){
					int min_multiplication = 1e9;
					for(int k=i+1; k<j; k++){
						min_multiplication = min(min_multiplication, nums[i]*nums[k]*nums[j] + dp[i][k] + dp[k][j]);
					}

					dp[i][j] =  min_multiplication;
				}
			}

			return dp[0][n-1];

			// return f(0, n-1, nums, dp);
    	}
};