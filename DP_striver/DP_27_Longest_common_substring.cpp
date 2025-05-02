#include<bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2){
    // Write your code here.
    int n = str1.size();
    int m = str2.size();
    int maxi = 0;
    // vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    vector<int> curr(m+1,0);

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
    //         maxi = max(maxi, dp[i][j]);
    //         cout << dp[i][j] << " ";
    //     }
    //     // for(auto c : curr) cout << c << " ";
    //     cout << endl;
    //     // prev = curr;
    // }
    // cout << endl;
    for(int i=1; i<=n; i++){
        for(int j=m; j>0; j--){
            if(str1[i-1]==str2[j-1]) curr[j] = 1 + curr[j-1];
            else curr[j] = 0;
            maxi = max(maxi, curr[j]);
        }
    }
    return maxi;
}