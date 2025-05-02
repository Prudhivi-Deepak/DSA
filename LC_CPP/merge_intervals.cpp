//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        int temp0, temp1;
        temp0 = arr[0][0];
        temp1 = arr[0][1];
        int i=1;
        while(i<arr.size()){
            if(temp1 < arr[i][0]){
                ans.push_back(vector<int>{{temp0, temp1}});
                temp0 = arr[i][0];
                temp1 = arr[i][1];
                i++;
            }
            else{
                temp1 = max(temp1, arr[i][1]);
                i++;
            }            
        }
        ans.push_back(vector<int>{{temp0, temp1}});
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends