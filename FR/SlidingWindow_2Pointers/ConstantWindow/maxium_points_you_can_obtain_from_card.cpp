class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        //your code goes here
        int maxSum = 0, currSum = 0, n = cardScore.size();
        for(int i=0; i<k; i++){
            currSum += cardScore[i];
        }

        maxSum = max(maxSum, currSum);

        for(int i=0; i<k; i++){
            currSum -= cardScore[k-i-1];
            currSum += cardScore[n-i-1];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};