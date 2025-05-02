//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// 3
// -3 -1 -1 0 1 2
// -2
// -2 0 1 1 5
// 1

// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        // arr[i] + arr[j] + arr[k] = target
        // arr[j] + arr[k] = target - arr[i]
        //   0  1  2 3 4 5
        //  -3 -1 -1 0 1 2
        //   i  j  j j j j
        //   -3 -1  = -2 -variable
        //  
        // 
        // -2 0 1 1 5
        for(int i=0; i < arr.size(); i++){
            for(int j=i; j < arr.size(); j++){

            }
        }

    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends