//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here

         map<int,int>mpp;
        for(auto it:arr){
            mpp[it[0]]++;
            mpp[it[1]]--;
        }
        int cnt = 0;
        for(auto it:mpp){
            cout << it.first << " : " << it.second << endl;
            cnt+=it.second;
            if(cnt>1)return false;
        }
        return true;

        // sort(arr.begin(), arr.end());
        // int c = 0;
        // int i = 1;
        // while(i < arr.size()){
        //     if(arr[c][1] > arr[i][0]){
        //         return false;
        //     }
        //     c = i;
        //     i +=1;
        // }
        // return true;


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
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends