//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getOperations(string s) {
        // code here
        // cout << "================" << endl;
        unordered_map<char, int> umap;
        for(char alp: s){
            umap[alp]++;
        }

        int count = 0;

        for(pair<char, int> alp: umap){
            if(alp.second >= 3){
                count += alp.second/3;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        int res = obj.getOperations(s);

        cout << res << endl;
    }
}

// } Driver Code Ends