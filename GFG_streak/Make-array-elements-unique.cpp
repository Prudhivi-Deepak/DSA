//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        int cost = 0;
        sort(arr.begin(), arr.end());
        int min_ele = arr[0];
        int i=1;
        while(i<arr.size()){
            min_ele +=1;
            if(min_ele - arr[i] < 0){
                min_ele = arr[i++];
            }
            else{
                cost += min_ele - arr[i++];
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends