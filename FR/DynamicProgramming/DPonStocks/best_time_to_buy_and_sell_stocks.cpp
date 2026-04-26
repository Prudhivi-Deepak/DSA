class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int runningMin = arr[0], maxProfit = 0;
        for(int i=0; i<n; i++){
            int currProfit = arr[i]-runningMin;
            maxProfit = max(maxProfit, currProfit);
            if(arr[i] < runningMin) runningMin = arr[i];
        }
        return maxProfit;
    }
};

