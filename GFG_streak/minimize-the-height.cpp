//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int ans = arr[arr.size()-1] - arr[0];
        int maxv, minv;

        for(int i=1; i<arr.size(); i++){
            // if(arr[i]-k <0){
            //     continue;
            // }

            minv = min(arr[0]+k, arr[i]-k);
            maxv = max(arr[arr.size()-1]-k, arr[i-1]+k);

            ans = min(ans, maxv-minv);

        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends