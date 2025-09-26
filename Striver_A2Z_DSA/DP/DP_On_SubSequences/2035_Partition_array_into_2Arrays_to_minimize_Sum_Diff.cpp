#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumDifference(vector<int>& nums) {
            // idea is to find minimum diff of sums between 2 equal sized subsets from the given array
            // Now finding all subsets and sums and checking min diff took us n * 2^n which is more time when n is large - TLE
            // so we do one thing learn meet in the middle algorithm - it's simple
            // p1SubsetSum + p2SubsetSum  = TotalSum; ===> p2SubsetSum  = TotalSum - p1SubsetSum
            // we need p1SubsetSum - p2SubsetSum = to be minimum ==> p1SubsetSum - (TotalSum - p1SubsetSum) = 
            // p1SubsetSum - TotalSum + p1SubsetSum) ==> abs ( 2*p1SubsetSum, TotalSum)
            // Now to find p1SubsetSum and p2SubsetSum, we can't do it in one go, so divide the 2*n sized array to 2 (n sized arrays)
            // now individually calculate the sum of all subset in each n-sizedarray and store in vector<0 vector<int>(size1, size2...), 1, 2...n>
            // Now we have to find the possible values of a (p1SubsetSum) and b (p2SubsetSum) to find th e min Diff
            // for every size and value in leftside n-sized vector/array find the idea value of b that can be used to make the diff minimum
            //  ideal b(p2SubsetSum) = (TotalSum/2) - a(p1SubsetSum)
            // Now find a lower bound (>= b) and its (<) left side value so we find the min value of both and update them accordingly
    
            int TotalSum = 0;
            int N = nums.size();
            for(int i=0; i<N; i++){
                TotalSum += nums[i];
            }
    
            int n = N/2;
    
            vector<vector<int>> left(n+1), right(n+1);
    
            for(int mask=0; mask<(1<<n); mask++){
                int len = 0, l = 0, r = 0;
                for(int i=0; i<n; i++){
                    if(mask&(1<<i)){
                        len++;
                        l+=nums[i];
                        r+=nums[i+n];
                    }
                }
                left[len].push_back(l); right[len].push_back(r);
            }
    
    
            for(int i=0; i<n; i++){
                sort(right[i].begin(), right[i].end());
            }
    
            int minDiff = min(abs(TotalSum - 2*left[n][0]), abs(TotalSum - 2*right[n][0]));
    
            for(int i=1; i<n; i++){
                for(int a : left[i]){
                    int b = ((TotalSum-2*a)/2), rindex = n-i;
                    auto itr = lower_bound(right[rindex].begin(), right[rindex].end(), b);
                    if(itr!=right[rindex].end())
                        minDiff = min(minDiff, abs(TotalSum - 2*(a+*itr)));
                    if(itr!=right[rindex].begin()){
                        itr--; 
                        minDiff = min(minDiff, abs(TotalSum - 2*(a+*itr) ));
                    }
                }
            }
            return minDiff;
        }
    
        // dp won't work for neg elements and larger inputs here
        int f(int i, int ts, int totalSum, vector<int>&nums, vector<vector<int>> &dp){
    
            if(i==0){
                return dp[i][ts] = abs(totalSum-ts-ts);
            }
    
            if(dp[i][ts] != -1) return dp[i][ts];
    
            int NT = f(i-1, ts, totalSum, nums, dp);
            int T = ts>=nums[i] ? f(i-1, ts-nums[i], totalSum, nums, dp) : 1e8;
    
            return dp[i][ts] = min(NT, T);
           
        }
        int minimumDifferencePositiveNumbers(vector<int>& nums) {
            int n = nums.size();
            int totalSum = 0;
            for(int i : nums){
                totalSum += i;
            }
            totalSum = abs(totalSum);       
    
            // vector<vector<int>> dp(n, vector<int>(totalSum+1, 1e8));
            vector<unordered_map<int,int>> dp(n);
    
            for(int ts=-totalSum; ts<= totalSum; ts++){
                dp[0][ts] = abs(totalSum-ts-ts);
            }
    
            for(int i=1; i<n; i++){
                for(int ts = -totalSum; ts<=totalSum; ts++){
                    int NT = dp[i-1][ts];
                    int T = dp[i-1].find(ts-nums[i])!=dp[i-1].end() ? dp[i-1][ts-nums[i]] : 1e8;
                    dp[i][ts] = min(NT, T);
                }
            }
            return dp[n-1][totalSum];
            // return f(n-1, totalSum, totalSum, nums, dp);
        } 
    };