//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int index = -1;
        for(int i=arr.size()-1; i>0;i--){
            if(arr[i-1]< arr[i]){
                index = i-1;
                break;
            }
        }
        
        if(index!=-1){
            for(int i=arr.size()-1; i>index;i--){
                if(arr[index]< arr[i]){
                    swap(arr[index], arr[i]);
                    break;
                }
            }
            reverse(arr.begin()+index+1, arr.end());
        }
        else{
            reverse(arr.begin(), arr.end());
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends