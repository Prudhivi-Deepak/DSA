#include <bits/stdc++.h>
using namespace std;

bool customComparator(int a, int b)
{
    return a > b;
}

int minCoins(vector<int> &coins, int sum)
{
    sort(coins.begin(), coins.end(), customComparator);
    int i = 0, n = coins.size(), cnt = 0;
    while (sum > 0 && i < n)
    {
        if (sum >= coins[i])
        {
            sum -= coins[i];
            cnt++;
        }
        else
        {
            i++;
        }
    }
    if (sum == 0)
        return cnt;
    else
        return -1;
}

int f(vector<int> &coins, int sum, int i, vector<vector<int>> &dp)
{

    if (sum == 0)
    {
        return 0;
    }
    else if (sum <0 || i >= coins.size())
    {
        return INT_MAX;
    }

    if (dp[i][sum]!= -1) return dp[i][sum];

    int pick = f(coins, sum - coins[i], i, dp);
    if (pick != INT_MAX)
        pick++;

    int notpick = f(coins, sum, i + 1, dp);

    return dp[i][sum] = min(pick, notpick);
}

int main()
{
    vector<int> coins =  {25, 10, 5};
    int sum = 30;

    // vector<int> coins =  {9, 6, 5, 1};
    // int sum = 19;

    // vector<int> coins =  {5, 1};
    // int sum = 0;

    // vector<int> coins = {4, 6, 2};
    // int sum = 5;
    int n = coins.size();
    vector<int> prev(sum+1, INT_MAX), curr(sum+1, INT_MAX);
    prev[0] = curr[0] =  0;
    for(int i = n-1; i>=0; i--){
        curr[0] = 0;
        for(int s=0; s<=sum; s++){
            // int pick = INT_MAX;
            // if(s>=coins[i]){
            //     if(curr[s-coins[i]] != INT_MAX)
            //         pick = curr[s - coins[i]]+1;
            // }
                
            // int notpick = prev[s];
            // curr[s] = min(pick, notpick);
            if(s>=coins[i] && curr[s-coins[i]]!=INT_MAX)
                curr[s] = min(curr[s - coins[i]]+1, curr[s]);
        }
        prev = curr;
    }

    int ans =  prev[sum];





    // int ans = f(coins, sum, 0, dp);
    // cout << ans << endl;
    if (ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}