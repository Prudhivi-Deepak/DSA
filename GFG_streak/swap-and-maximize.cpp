//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        int last = arr.size()-1;
        int mid = (0+last)/2;

        int sum = 0;



        // if(arr.size()>=2){
        //     sum += abs(arr[0]-arr[mid+1]);
        // }

        // if(mid+mid+1 <= last){
        //     sum += abs(arr[0]-arr[mid+mid+1]);
        // }
        // else{
        //     sum += abs(arr[0]-arr[mid]);
        // }

        // for(int i=1; i<=mid; i++){
            
        //     if(mid+i+1 <= last){
        //         sum += abs(arr[i]-arr[mid+i+1]);
        //     }

        //     if(mid+i <= last){
        //         sum += abs(arr[i]-arr[mid+i]);
        //     }            
        // }

        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends