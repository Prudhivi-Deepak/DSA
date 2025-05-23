//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here


        int i=0, n=arr.size(), j=n-1, ls=arr[i], rs = arr[j],ms,ts=0;
        for(int ele : arr){
            ts += ele;
        }

        ms = ts - (ls+rs);
        while(i<j && !(ls == ms && ls == rs)){
            if(ls < rs){
                ls +=arr[++i];
            }
            else{
                rs += arr[--j];
            }

            ms = ts - (ls+rs);            
            if(ls == rs && ls == ms){
                break;
            }
        }        
        
        if(i>j-1){
            return vector<int>{{-1,-1}};
        }
        else{
            return vector<int>{{i,j-1}};
        }
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends