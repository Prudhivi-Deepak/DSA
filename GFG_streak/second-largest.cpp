//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int firstlargest;
        int secondlargest;
        if(arr[0] >= arr[1]){
            firstlargest = arr[0];
            secondlargest = arr[1];
        }
        else{
            firstlargest = arr[1];
            secondlargest = arr[0];
        }

        for(int i=2;i<arr.size();i++){
            // cout << "firstlargest : " << firstlargest <<endl;
            // cout << "secondlargest : " << secondlargest <<endl;
            // cout << "arr[i] : " << arr[i] << endl;
            if(arr[i] > firstlargest){
                secondlargest = firstlargest;
                firstlargest = arr[i];
            }
            else if(arr[i] > secondlargest and arr[i]!=firstlargest){
                secondlargest = arr[i];
            }
        }

        if(firstlargest == secondlargest){
            return -1;
        }
        else{
            return secondlargest;
        }

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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends