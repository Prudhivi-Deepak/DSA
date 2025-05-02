//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int min_i = 0;
        int max_i = -1;
        int profit = 0;

        for(int i=1; i<prices.size();i++){
            if(prices[i] < prices[min_i]){
                min_i = i;
                max_i = -1;
            }
            else if(i > max_i && prices[i] > prices[max_i]){
                max_i = i;
            }

            profit = max(profit, prices[max_i] - prices[min_i]);
        }

        return profit;

        // cout << min_i << max_i << endl;
        // cout << prices[min_i] << prices[max_i] << endl;
        // cout << prices[max_i] - prices[min_i] << endl;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends