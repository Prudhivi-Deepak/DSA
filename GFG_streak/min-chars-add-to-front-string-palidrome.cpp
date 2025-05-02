//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string lps_string = s;
        int n = s.size();
        reverse(s.begin(), s.end());
        lps_string += '*'+s;
        // cout << lps_string << endl;
        int lps_n = lps_string.size();
        vector<int> lps (lps_n, 0);
        int i=1, match=0;
        while(i < lps_n){
            if(lps_string[i] == lps_string[match]){
                lps[i++] = ++match;
            }
            else{
                if(match!=0){
                    match = lps[match-1];
                }
                else{
                    i++;
                }
            }
        }

        return n-lps[lps_n-1];

        // cout << n << endl;

        // for(auto j : lps){
        //     cout << j << " ";
        // }
        // cout << endl;
        // return n-lps[lps_n-1];

        // aacecaacacecaaa*aaacecacaacecaa
        //
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends