class Solution {
  public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
      int n = arr.size();
      vector<int> count(n+1, 0), parent(n+1, 0);
      int last_index = 0;

      for(int i=0; i<n; i++){
        parent[i] = i;
        for(int prev=0; prev<i; prev++){

          if(arr[prev] < arr[i] && count[i] < count[prev]+1){
            count[i] = count[prev]+1;
            parent[i] = prev;
          }
        }

        if(count[i] > count[last_index]){
          last_index = i;
        }

      }

      // for(int k=0; k<n; k++){
      //   cout << parent[k] << " ";
      // }
      // cout << endl;

      vector<int> ans;
      while(last_index!=parent[last_index]){
        ans.push_back(arr[last_index]);
        last_index = parent[last_index];
      }

      ans.push_back(arr[last_index]);
      reverse(ans.begin(), ans.end());

      return ans;

    }
    vector<int> longestIncreasingSubsequence1(vector<int>& arr) {
        int n = arr.size();

        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        vector<int> prev(n+1, 0), curr(n+1, 0);

        // i goes from n-2 to 0
        // base case : for any prev index  arr[prev_index] > arr[0] 

        
        for(int i=0; i<n; i++){
          cout << arr[i] << " ";
        }
        cout << endl;

        for(int prev_index=0; prev_index<=n; prev_index++){
            // if(arr[prev_index] > arr[0]) dp[0][prev_index] = 1;
            if(prev_index==arr.size() || arr[prev_index] > arr[0]) prev[prev_index] += 1;
            cout << prev[prev_index] << "  ";
        }
        cout << endl;

        for(int i=1; i<n; i++){
            for(int prev_index=0; prev_index<=n; prev_index++){
                // int notTake = dp[i-1][prev_index];
                int notTake = prev[prev_index];
                int Take = 0;
                if(prev_index==arr.size() || arr[prev_index] > arr[i]) 
                    // Take = 1 + dp[i-1][i];
                    Take = 1 + prev[i];

                // dp[i][prev_index] = max(notTake, Take);
                curr[prev_index] = max(notTake, Take);
                cout << curr[prev_index] << "  ";
            }
            prev = curr;
            cout << endl;
        }
        // return dp[n-2][n-1]+1;
        // return prev[n];
        return {};
        // return f(n-1, n, arr, dp) ;
    }
};