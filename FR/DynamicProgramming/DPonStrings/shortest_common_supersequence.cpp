class Solution{
    public: 

    string shortestCommonSupersequence(string str1, string str2){
        int n1=str1.size(), n2=str2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(str1[i]==str2[j]) dp[i][j] = 1+dp[i+1][j+1];
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }

        int i=0, j=0;

        string ans;

        while(i<n1 && j<n2){
            int right = dp[i][j+1], down = dp[i+1][j];
            
            if(down == dp[i][j]){
                ans += str1[i]; i++;
            }
            else if(right == dp[i][j]){
                ans += str2[j]; j++;
            }
            else{
                ans += str1[i]; i++; j++;
            }
        }

        while(i<n1){
            ans += str1[i]; i++;
        }

        while(j<n2){
            ans += str2[j]; j++;
        }

        // cout << ans << endl;

        return ans;

    }
    
    string shortestCommonSupersequenceFillingReverse(string str1, string str2){
        int n1=str1.size(), n2=str2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        dp[0][0] = str1[0]==str2[0] ? 1 : 0;

        // cout << dp[0][0] << " ";

        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(i==0 && j==0) continue;

                if(str1[i]==str2[j]) dp[i][j] = 1 + ((i>0 && j>0) ? dp[i-1][j-1] : 0);
                else dp[i][j] = max(
                    (i>0) ? dp[i-1][j] : 0, 
                    (j>0) ? dp[i][j-1] : 0);
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }

        int i=n1-1, j=n2-1;

        string ans;

        while(i>=0 && j>=0){

            int up = (i>0) ? dp[i-1][j] : 0;
            int left = (j>0) ? dp[i][j-1] : 0;
            
            if(left == dp[i][j]){
                ans += str2[j];
                j--;
            }
            else if(up == dp[i][j]){
                ans += str1[i];
                i--;
            }
            else{
                ans += str1[i];
                i--;
                j--;
            }
        }

        while(i>=0){
            ans += str1[i]; i--;
        }

        while(j>=0){
            ans += str2[j]; j--;
        }

        reverse(ans.begin(), ans.end());

        // cout << ans << endl;

        return ans;     
    }
};