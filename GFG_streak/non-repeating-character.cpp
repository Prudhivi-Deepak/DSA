//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        int allpos = 0;
        int duplicatepos = 0;
        for(int i=0; i< s.size(); i++){
            // cout << s[i] << " : " << s[i]-'a' << endl;
            // check if pos is 1 in allpos (and op for pos and allpos)
            //  true : make duplicatepos as 1
            //  false : make allpos as 1
            int pos = 1 << s[i]-'a'; // position of the alphabet in bits
            if(pos & allpos){
                // cout <<  "if : " << s[i] << endl;
                if(!(duplicatepos & pos)){
                    // cout <<  "if duplicate : " << s[i] << endl;
                    duplicatepos = duplicatepos | pos;
                }
            }
            else{
                // cout <<  "else : " << s[i] << endl;
                allpos = allpos | pos;
            }
        }

        for(int i=0; i< s.size(); i++){
            // s[i] not in duplicatepos but in allpos
            int pos = 1 << s[i]-'a';
            if(!(pos & duplicatepos)){
                return s[i];
            }
        }

        return '$';

        //zyxwvutsrqponmlkjihgfedcba
        // 0000001100100010001110000 << 0 - allpos
        // 0000001000000010001010000 << 0 - duplicatepos
        // 
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends