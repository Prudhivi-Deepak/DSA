//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
        // 1 2 3 4 5 .. len
        // f f f f f

        // 5 1 2 4 1
        // 5
        // 5 >= .. 1
        // 4 >= .. 1+1 = 2
        // 3 >= .. 2+0 = 2
        // 2 >= .. 2+1 = 3
        // 1 >= .. 3+2 = 5

        // 3 0 5 3 0
        // 0 1 2 3 4
        // 1 2 3 4 5

        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        
        for (int c : citations) {
            if (c >= n)
                buckets[n]++; 
            else
                buckets[c]++;
        }

        int total = 0; 
        for (int i = n; i >= 0; --i) {
            total += buckets[i];
            if (total >= i)
                return i; 
        }
        return 0;


                // for(auto i : buckets){
        //     cout << i << " ";
        // }
        // cout << endl;
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
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends