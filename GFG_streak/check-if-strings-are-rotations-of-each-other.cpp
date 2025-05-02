//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        // abcdabcd
        // cdab

        // aaaba aaaba

        // aaaab
        if(s1.size()!=s2.size()){
            cout << "length not equal" << endl;
            return false;
        }
        else{
            // s1 = s1+s1;
            int n = s2.size(), i = 1, match = 0;
            vector<int> lps(n,0);

            while(i < n){
                if(s2[i] == s2[match]){
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

            s1 = s1+s1;
            // cout << s1 << endl;
            // for(auto i : lps){
            //     cout << i << " ";
            // }

            i = 0;
            int j = 0;
            while(i < s1.size()){
                if(s1[i] == s2[j]){
                    // cout << "\n" << i << "|" << j << "|" << s1[i] << "|" << s2[j] << endl;
                    i++;
                    j++;
                }
                else{
                    if(j!=0){
                        j = lps[j-1];
                    }
                    else{
                        i++;
                    }
                }

                if(j == s2.size()){
                    return true;
                }
            }
            return false;
        }

        // ncwuvtaxcygwghcvrfpwfdlhyrszzcqxkdfmcvwscytvdnmmmdnkranafryefhhuoccpcukyfesucuanxjtupwsluadxrmujbgdmkyvmjcbpcgfhpcrwrqkeoryrdivyxvjzhxwjvrbrlgipoyxhgzjamrvhqzhguuwuapqincwuvtaxcygwghcvrfpwfdlhyrszzcqxkdfmcvwscytvdnmmmdnkranafryefhhuoccpcukyfesucuanxjtupwsluadxrmujbgdmkyvmjcbpcgfhpcrwrqkeoryrdivyxvjzhxwjvrbrlgipoyxhgzjamrvhqzhguuwuapqi
        // mmdnkranafryefhhuoccpcukyfesucuanxjtupwsluadxrmujbgdmkyvmjcbpcgfhpcrwrqkeoryrdivyxvjzhxwjvrbrlgipoyxhgzjamrvhqzhguuwuapqincwuvtaxcygwghcvrfpwfdlhyrszzcqxkdfmcvwscytvdnm

        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends