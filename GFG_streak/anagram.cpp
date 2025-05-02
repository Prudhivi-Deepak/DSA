//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int sum1 = 0, pro1 = 1, sum2 = 0, pro2 = 1;
        if(s1.size() != s2.size()){
            return false;
        }
        else{
            for(int i=0; i<s1.size(); i++){
                sum1 += s1[i]-96;
                pro1 *= s1[i]-96;
                sum2 += s2[i]-96;
                pro2 *= s2[i]-96;
            }
        }

        if(sum1 == sum2 && pro1 == pro2){
            return true;
        }

        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends