//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    double f(vector<int>& val, vector<int>& wt, int capacity, int i, int n, vector<vector<double>> &dp){
    
        if(i >= n){
            return 0.0;
        }
        
        if(capacity < wt[i]){
            return (val[i]/wt[i])*capacity;
        }
        
        if (dp[i][capacity] != -1){
            return dp[i][capacity];  
        } 
        
        double pick = val[i] + f(val, wt, capacity-wt[i], i+1, n, dp);
        double notpick = 0.0 + f(val, wt, capacity, i+1, n, dp);
        
        return dp[i][capacity] = max(pick, notpick);
    }
    
    bool static customComparator(pair<int,int> p1, pair<int,int> p2){
        return ((double)p1.first/p1.second) > ((double)p2.first/p2.second);
    }

  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        double ans = 0;
        // vector<vector<double>> dp(n+1, vector<double>(capacity+1, -1));
        // vector<double> prev(capacity+1, 0), curr(capacity+1, 0);
        // vector<pair<int,int>> pairs;
        priority_queue<pair<double, pair<int,int>>> pq;
        for(int i=0; i<n; i++){
            // pq.push_back(make_pair(val[i], wt[i]));
            pq.push({(double)val[i]/wt[i], {val[i], wt[i]}});
        }
        
        // sort(pairs.begin(), pairs.end(), customComparator);
        
        // for(int i=0; i<n; i++){
        //     // cout << pairs[i].first << " --> " << pairs[i].second << endl;
        //     if(capacity < pairs[i].second){
        //         ans = ans + (pairs[i].first/pairs[i].second)*capacity;
        //         break;
        //     }
        //     else{
        //         ans = ans + pairs[i].first;
        //         capacity = capacity - pairs[i].second;
        //     }
        // }
        
        while(!pq.empty()){
            double ratio = pq.top().first;
            int v = pq.top().second.first;
            int w = pq.top().second.second;
            if(capacity < w){
                ans = ans + ratio*capacity;
                break;
            }
            else{
                ans = ans + v;
                capacity = capacity - w;
            }
            pq.pop();
        }
        
        return ans;
        
        
        
        // for(int i=n-1; i>=0; i--){
        //     for(int c=capacity; c>=0; c--){
        //         if(c < wt[i]) 
        //             curr[c] = (val[i]/wt[i])*c;
        //         else{
        //             double pick = val[i] + prev[c-wt[i]];
        //             double notpick = 0.0 + prev[c];
                    
        //             curr[c] = max(pick, notpick);
        //         }
        //         prev = curr;
        //     }
        // }
        
        // return prev[capacity];
        
        

        // return f(val, wt, capacity, 0, n, dp);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends