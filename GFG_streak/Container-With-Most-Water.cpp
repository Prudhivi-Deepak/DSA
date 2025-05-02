//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// 3
// 1 5 4 3
// 3 1 2 4 5
// 2 1 8 6 4 6 5 5

// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends