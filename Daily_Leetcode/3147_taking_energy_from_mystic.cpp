#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n+k, 0);

        // dp[i] denote the energy starting from index i
        int maxSum = INT_MIN;

        for(int i=n-1; i>=0; i--){
            dp[i] = dp[i+k]+energy[i];
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
    void maximumEnergy1(vector<int>& energy, int k) {
        // 0 1  2   3 4
        // 5 2 -10 -5 1
        // k=3
        // 
        // 0 to n
        // all the starting points from 0 to n
        // n = 10**5 not a O(n**2) solution
        // 0 1  2   3 4
        // 5 2 -10 -5 1
        // l=0 r=3
        // 

        // -2 -3 -1
        // 0  1  2

        // 5 2 -10 -5 1

        // indices to track valid window or k multiple dist from source
        // ind : 0 adj {0 : {k+0, 2*k+0, 2*k+1.....}}
        // 
        // vector<int> sum(k, 0)
        // 0 to k
        // store all values from 0 to k to sum array
        // 5 2 -10 -5 1
        // 
        // 5 2 -10
        // another for loop iterates from i+k to n
        // -5 = 3%k = 3%3 = 0 (index)
        // 0 2 -10
        // 1 = 4%k = 4%3 = 1 (index)
        // 0 3 -10 ==> maxvalue
        // O(k) + (n-k) + O(k)

        // int maxSum = INT_MIN, n = energy.size();
        // for(int i=0; i<n; i++){
        //     int j = i, sum = 0;
        //     while(j<n){
        //         sum += energy[j];
        //         j+=k;
        //     }
        //     maxSum = max(maxSum, sum);
        // }
        // return maxSum;

        
        // 0  1  2
        // -2 -3 -1
        // -1  0
        // 
        // 2%2 = 0

        // starting points from 0 to k
        // after k may also contain some k values
        
        // all ele ==> -ve get a maxSum = 0 not valid anyPos = 
        // 0 0 0 => output ==> 0 valid

        // 0 0 0 -2 -3 -4 0 -5
        // k = 2

        // 0

        // 0 0 0 -2 0 -4 0 -5
        // 0

        // don't compute the last k values

        // -2 -3 -1
        // -2 -3 -1 -2 -1 -3 -9
        // -2 -3
        // 0 0
        // -1 -2
        //  0 0
        // -1 0 ==> 0 0

        // 0  1 2 3 4  5 6  7 
        // 7,-9,4,1,10,7,9,-3
        //  k = 6
        // 7 0 4 1 10 7
        // 6%6 = 0
        // 

        //  0  1 2  3  4  5  6 7 8
        // -1 -2 -8 6 -6 -6 -6 5 5

        // k=8

        // 0 1 2  3  4  5 6
        // 1 3 4 10 -6 -2 4
        // k = 4
        
        // 1  3 4 10
        //-5  1 8 10

        // 0   1  2
        // -2 -3 -1
        // 0 0
        // index = 2
        // 3-2 = 1

        // n-k compute
        // 

        // 4 -4 -9
        // 4 -4
        // 




        // vector<int> sum(k, 0);
        // int n = energy.size(), maxSum = INT_MIN, index = n-k;
        // for(int i=0; i<k; i++){
        //     sum[i] = energy[i];
        //     if(sum[i]<0) sum[i] = 0;
        //     if(i>=n-k) index = i+1;
        // }
        // // cout << index << endl;
        // if(index<=n-k)
        //     for(int i=k; i<n-k; i++){
        //         sum[i%k] += energy[i];
        //         if(sum[i%k]<0) sum[i%k] = 0;
        //     }

        // int j = index%k;
        // while(index<n){
        //     sum[index%k] += energy[index]; index++;
        //     j = index%k;
        // }

        // -8
        // 0
        // 10

        // for(int i=0; i<k ; i++){
        //     cout << sum[i] << " ";
        // }
        // cout << endl;

        // while(j<k && k!=1){
        //     if(sum[j]==0) sum[j]=INT_MIN; j++;
        // }

        // 5 -10 4 3 5 -9 9 -7
        // 5 0
        // 9 3
        // 14 0

        // 23 -7

        // 

        // for(int i=0; i<k; i++){
        //     maxSum = max(maxSum, sum[i]);
        // }

        // computed untill n-k values Now don't alter the sum

        // return maxSum;
    }
};