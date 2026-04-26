class Solution {
public:
    //  i goes from n-1 to 0
    int f(int i, int limit, vector<int>& money, vector<int> &dp){
        //  take i --> should not take i+1, go to i+2
        // not take i --> may or may not take i+1

        // if(i==0) return money[0];
        if(i<limit) return 0;

        if(dp[i]!=-1) return dp[i];

        int notTake = f(i-1, limit, money, dp);
        int take = money[i] + f(i-2, limit, money, dp);

        return dp[i] = max(take, notTake);
    }

    int houseRobber(vector<int>& money) {
        int n = money.size();
        if(n==1) return money[0];
        // vector<int> dp(n+2, 0);

        // circular first house and last house cannot be considered at once
        // int noFirst = f(n-1, 1, money, dp);
        // dp.assign(n+2, 0);
        // int noLast =  f(n-2, 0, money, dp);

        // i goes from n-1 to 1 1st time
        // i goes from n-2 to 0 2nd time

        // base case nothing --> handle -ve indices in for loop

        int prev1 = 0, prev2 = 0, curr = 0;
        for(int i=1; i<=n-1; i++){
            
            // int notTake = i-1<1 ? 0 : dp[i-1];
            // int take = money[i] + (i-2<1 ? 0 : dp[i-2]);

            // dp[i] = max(take, notTake);
            curr = max(prev1 , money[i]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        // int step1 = dp[n-1];
        int step1 = curr;
        // dp.assign(n+2, 0);

        prev1 = 0, prev2 = 0, curr = 0;

        for(int i=0; i<=n-2; i++){
            
            // int notTake = i-1<0 ? 0 : dp[i-1];
            // int take = money[i] + (i-2<0 ? 0 : dp[i-2]);

            // dp[i] = max(take, notTake);
            curr = max(prev1 , money[i]+prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        // return max(dp[n-2], step1);
        return max(curr, step1);

        // return max(noFirst, noLast);
    }
};