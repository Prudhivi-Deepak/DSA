//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // Your code goes here
        int front_pointer = 0;
        int end_pointer = s.length()-1;
        char temp ='a';
        
        while(front_pointer < end_pointer){
            temp = s[front_pointer];
            s[front_pointer] = s[end_pointer];
            s[end_pointer] = temp;
            
            front_pointer++;
            end_pointer--;
        }
        return s;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob = Solution();
        cout << ob.reverseString(s) << endl;
    }
    return 0;
}

// } Driver Code Ends