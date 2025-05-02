//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int, int> umap;
        for(int i: a){
            umap[i] = 1;
        }

        for(int i: b){
            umap[i] = 1;
        }

        return umap.size();

        
        // for(int i: a){
        //     cout << umap[i] << endl;
        // }

                // for(int i: a){
        //     cout << i << " " << umap[i] << endl;
        // }

        // int count =0 ;
        // for(pair<int, int>i : umap){
        //     if(i.second > 1){
        //         count++;
        //     }            
        // }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a.
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.findUnion(a, b) << endl;
        cout << '~' << endl;
    }

    return 0;
}
// } Driver Code Ends