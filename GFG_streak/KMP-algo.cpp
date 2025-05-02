//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
          // onion
        // 00012
        // m m m m m m
        // m m
        // o n i o n i o l o n i o n
        // 0 0 0 1 2 3 4 0 1 2 i
        // m m m
        // m m m
        // a a b a a a c
        // 0 1 0 1 2 0 0
        // m m
        // a a b a a a c
        // 0 1 i
        //  m
        //  e d u
        //  0 0 0
    vector<int> ComputeLPS(string &pat){
        int n = pat.size();
        vector<int> lps (n, 0);
        int i=1, match=0;
        while(i < n){
            // cout << pat[i] << match << pat[match] << endl;
            if(pat[i] == pat[match]){
                lps[i++] = ++match;
            }
            else{
                // if(match == 0){
                //     // lps[i++] = 0;
                //     i++;
                // }
                // else{
                //     match = match-1;
                // }

                if(match!=0){
                    match = lps[match-1];
                }
                else{
                    i++;
                }
            }
        }

        return lps;
    }
    vector<int> search(string& pat, string& txt) {
        // code here

        vector<int> lps = ComputeLPS(pat);
        vector<int> ans;
        int n = txt.size(), pn = pat.size(), i = 0, j=0;
        while(i < n){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i+=1;
                }
            }

            if(j==pn){
                ans.push_back(i-j);
                j = lps[j-1];
            }
            // i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends