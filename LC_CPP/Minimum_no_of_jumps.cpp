//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here

        // if(arr[0] == 0){
        //     return -1;
        // }

        int destination = arr.size()-1;
        int maxreach = 0;
        int windowend = arr[0];
        int jump = 0;
        
        for(int i=0;i<arr.size();i++){
            maxreach = max(maxreach, arr[i] + i);
            if(windowend == i){
                jump++;
                windowend = maxreach;
            }

            if(windowend >= destination){
                return ++jump;
            }
        }

        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends