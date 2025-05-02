//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        long long int min_ele = arr[0];
        long long int max_ele = arr[0];
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > max_ele){
                max_ele = arr[i];
            }
            if(arr[i] < min_ele){
                min_ele = arr[i];
            }
        }
        
        return make_pair(min_ele, max_ele);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends