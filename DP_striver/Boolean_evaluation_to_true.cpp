
#include<bits/stdc++.h>
using namespace std;
// https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM
int mod = 1000000007;
int f(int i, int j, int isTrue, string &A, vector<vector<vector<int>>> &dp) {
    if(i>j) return 0;
    if(i==j){
        if(isTrue == 1) return A[i]=='T';
        else return A[i]=='F';
    }
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    long long ways = 0;
    for(int ind=i+1; ind<=j; ind+=2){
        long long LT = f(i, ind-1, 1, A, dp);
        long long LF = f(i, ind-1, 0, A, dp);
        long long RT = f(ind+1, j, 1, A, dp);
        long long RF = f(ind+1, j, 0, A, dp);
        
        // cout << A[ind] << " : " << LT << " " << LF << " " << RT << " " << RF << " " << endl;
        
        if(isTrue == 1){
            if(A[ind] == '&'){
                ways = (ways + (LT*RT) % mod)%mod;
            }
            else if(A[ind] == '|'){
                ways = (ways + ((LT*RF) % mod)+((LF*RT) % mod)+((LT*RT) % mod))%mod;
            }
            else if(A[ind] == '^'){
                ways = (ways + ((LT*RF) % mod)+((LF*RT) % mod))%mod;
            }
        }
        else{
            if(A[ind] == '&'){
                ways = (ways + ((LF*RF) % mod)+((LF*RT) % mod)+((LT*RF) % mod))%mod;
            }
            else if(A[ind] == '|'){
                ways = (ways + ((LF*RF) % mod)) %mod;
            }
            else if(A[ind] == '^'){
                ways = (ways + ((LT*RT) % mod)+((LF*RF) % mod)) % mod;
            }
        }
        
        // cout << ways << endl;
    }
    
    return dp[i][j][isTrue] = ways % mod;
}

int evaluateExp(string & A) {
    // Write your code here.
    int n = A.size();
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, vector<long long>(2, 0)));

    for(int i=0; i<n; i++){
        dp[i][i][1] = A[i] == 'T';
        dp[i][i][0] = A[i] == 'F';
    }

    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            // if(i>j) continue;
            for(int isTrue=1; isTrue>=0; isTrue--){
                // if(i>j) continue;
                // if(i==j){
                //     if(isTrue == 1) dp[i][j][isTrue] == A[i]=='T';
                //     else dp[i][j][isTrue] = A[i]=='F';
                // }

                long long ways = 0;
                for(int ind=i+1; ind<=j; ind+=2){
                    long long LT = dp[i][ind-1][1];
                    long long LF = dp[i][ind-1][0];
                    long long RT = dp[ind+1][j][1];
                    long long RF = dp[ind+1][j][0];
                    
                    
                    // cout << A[ind] << " : " << LT << " " << LF << " " << RT << " " << RF << " " << endl;
                    
                    if(isTrue == 1){
                        if(A[ind] == '&'){
                            ways = (ways + (LT*RT) % mod)%mod;
                        }
                        else if(A[ind] == '|'){
                            ways = (ways + ((LT*RF) % mod)+((LF*RT) % mod)+((LT*RT) % mod))%mod;
                        }
                        else if(A[ind] == '^'){
                            ways = (ways + ((LT*RF) % mod)+((LF*RT) % mod))%mod;
                        }
                    }
                    else{
                        if(A[ind] == '&'){
                            ways = (ways + ((LF*RF) % mod)+((LF*RT) % mod)+((LT*RF) % mod))%mod;
                        }
                        else if(A[ind] == '|'){
                            ways = (ways + ((LF*RF) % mod)) %mod;
                        }
                        else if(A[ind] == '^'){
                            ways = (ways + ((LT*RT) % mod)+((LF*RF) % mod)) % mod;
                        }
                    }
                }
                dp[i][j][isTrue] = ways;
                // cout << dp[i][j][isTrue] << " ";
            }
        }
        // cout << endl;
    }
    return dp[0][n-1][1];


    // return f(0, n-1, 1, exp, dp);
}