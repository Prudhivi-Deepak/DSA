#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        //your code goes here
        
        // 0 1 2 3 4 5 6
        // 5 4 1 8 7 1 3
        // k = 3
        // either begining or end of the array not from any continous subarray
        int n = cardScore.size(), l = k-1, r = n-1, max_sum = 0, sum = 0;

        for(int i=0; i<k; i++){
            sum += cardScore[i];
        }

        max_sum = max(max_sum, sum);

        while(l>=0){
            sum += cardScore[r--];
            sum -= cardScore[l--];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};