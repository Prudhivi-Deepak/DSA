//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here

        // 1 2
        // 1   3
        // 1 2
        //   2 3
        //     3 4
        sort(intervals.begin(),intervals.end());
        int overlapping_count = 0;

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <  intervals[i-1][1]){
                intervals[i][1] = min(intervals[i-1][1], intervals[i][1]);
                overlapping_count++;
            }
        }
        return overlapping_count;
        
        // cout << intervals[i][0] << intervals[i][1] << endl;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends