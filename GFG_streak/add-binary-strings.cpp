//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        char carry = '0';
        char s1_char = '0';
        char s2_char = '0';
        int index;
        int n1 = s1.size()-1;
        int n2 = s2.size()-1;

        while(n1>=0 || n2>=0){
            if(n1<0){
                s1_char = '0';
            }
            else{
                s1_char = s1[n1];
            }

            if(n2<0){
                s2_char = '0';
            }
            else{
                s2_char = s2[n2];
            }

            // if(n1>n2){
            //     index = n1;
            // }
            // else{
            //     index = n2;
            // }

            // cout << carry << s1_char << s2_char << " || " << s1 << endl;
            if(carry == '1'){
                if(s1_char == '1' && s2_char == '1'){
                    if(n1<0){
                        s1 = '1' + s1;
                    }
                    else{
                        s1[n1] = '1';
                    }
                    carry = '1';
                }
                else if((s1_char == '0' && s2_char == '1') || (s1_char == '1' && s2_char == '0')){
                    if(n1<0){
                        s1 = '0' + s1;
                    }
                    else{
                        s1[n1] = '0';
                    }
                    carry = '1';
                }
                else{
                    if(n1<0){
                        s1 = '1' + s1;
                    }
                    else{
                        s1[n1] = '1';
                    }
                    carry = '0';
                }
            }
            else{
                if(s1_char == '1' && s2_char == '1'){
                    if(n1<0){
                        s1 = '0' + s1;
                    }
                    else{
                        s1[n1] = '0';
                    }
                    carry = '1';
                }
                else if((s1_char == '0' && s2_char == '1') || (s1_char == '1' && s2_char == '0')){
                    if(n1<0){
                        s1 = '1' + s1;
                    }
                    else{
                        s1[n1] = '1';
                    }
                    carry = '0';
                }
                else{
                    if(n1<0){
                        s1 = '0' + s1;
                    }
                    else{
                        s1[n1] = '0';
                    }
                    carry = '0';
                }
            }
            n1--;
            n2--;
        }

        if(carry == '1'){
            return carry+s1;
        }
        else{
            index = 0;
            while(s1[index]=='0'){
                index++;
            }
            if(index >= s1.size()){
                return "0";
            }
            return s1.substr(index,s1.size());
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends