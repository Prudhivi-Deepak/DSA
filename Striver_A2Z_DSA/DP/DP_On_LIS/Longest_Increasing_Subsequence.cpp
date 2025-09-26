#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, vector<int> &nums, int prev, vector<vector<int>> &dp){
        if(i==0){
            if(prev==nums.size()) return 1;
            if (prev < nums.size()) return nums[prev] > nums[0] ? 1 : 0;
        }

        if(dp[i][prev]!=-1) return dp[i][prev];

        int NT = f(i-1, nums, prev, dp);
        int T = (prev==nums.size() || nums[prev] > nums[i]) ? 1+f(i-1, nums, i, dp) : 0;
        
        
        return dp[i][prev] = max(NT, T);

    }

    int LIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // vector<int> next(n+1, 0), curr(n+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int p=i; p>=0; p--){
                int NT = dp[i+1][p];
                // int T = (p==0 || nums[i]>nums[p-1]) ? 1+dp[i+1][i+1]:0;
                int T = 0;
                if(p==0 || nums[i]>nums[p-1]){
                    T = 1+dp[i+1][i+1];
                }

                dp[i][p] = max(NT, T);

                // int NT = next[p];
                // int T = (p==0 || nums[i]>nums[p-1]) ? 1+next[i+1]:0;
                // curr[p] = max(NT, T);
            }
            // next = curr;
        }

        for(int i=0; i<n; i++){
            cout << nums[i] << " ";
        }
        cout << endl;

        for(int i=n-1; i>=0; i--){
            cout << dp[i][0] << " ";
        }

        cout << endl;

        return dp[0][0];

        // return next[0];
    }


    int LISFirstTry(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, 0));
        vector<int> last(n+1, 0), curr(n+1, 0);

        // return f(n-1, nums, n, dp);

        last[n] = 1;
        for(int prev = n-1; prev>=0; prev--){
            if(nums[prev]>nums[0]) last[prev] = 1;
        }

        for(int i=1; i<n; i++){
            for(int prev = 0; prev<=n; prev++){
                int NT = last[prev];
                int T = (prev==nums.size() || nums[prev] > nums[i]) ? 1+last[i] : 0;
                curr[prev] = max(NT, T);
            }
            last = curr;
        }

        return last[n];
        // [-39,-14,94,34,-19,-70,-1,-62,-64,28,99,-24,74,-71,13,78,-85,51,-70,-70,-63,51,42,71,31,-70,100,-47]
    }

    int lower_bound_index(vector<int> &lis, int k){
        // 0 1 2 3 4
        // 1 4 6 7 9
        // 5

        // 

        int l=0, r=lis.size()-1, lb_index = r+1;

        while(l<=r){
            int mid = r-((r-l)/2);
            // cout << " ----- mid : " << mid << " k : " << k << endl;

            if(lis[mid]>=k){
                // cout << lis[mid] << ">=" << k <<endl;
                lb_index = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        // cout << l << "]-[" << r << "}-{"<< lb_index << endl;
        return lb_index;
    }


    int LISFinal(vector<int>& nums) {

        int n = nums.size();

        vector<int> lis;
        lis.push_back(nums[0]);

        for(int i=1; i<n; i++){
            int lb_index = lower_bound_index(lis, nums[i]);
            // cout << lb_index << endl;
            if(lb_index < lis.size()){
                lis[lb_index] = nums[i];
            }
            else{
                lis.push_back(nums[i]);
            }

            // for(int j : lis){
            //     cout << j << " " ;
            // }
            // cout << endl;
        }

        return lis.size();
    }

};