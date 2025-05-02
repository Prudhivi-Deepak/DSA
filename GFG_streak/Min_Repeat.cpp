//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        int i=0, j=0, count=1, rotation=0;
        string temp_s1 = s1;

        int s1_size = s1.size();
        int s2_size = s2.size();

        while(s1_size < s2_size){
            s1 += temp_s1;
            s1_size = s1.size();
            count++;
        }

        if(s1.find(s2)!= std::string::npos){
            return count;
        }
        else{
            s1 = s1+temp_s1;
            if(s1.find(s2)!= std::string::npos){
                count++;
            }
            else{
                return -1;
            }
        }

        return count;





        // aabaaaabaa
        // aaab

        // while(rotation < 2 && j<s2_size){
        //     if(i>=s1_size){
        //         rotation++;
        //         s1 += temp_s1;
        //         s1_size = s1.size();
        //         count++;
        //         i=0;
        //     }
        //     else if(s1[i] == s2[j]){
        //         i++;
        //         j++;
        //     }
        //     else if(j!=0){
        //         j=0;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // if(rotation >= 2){
        //     return -1;
        // }
        // return count;


                    // cout << i << " " << j << endl;
            // cout << s1[i] << " " << s2[j] << endl;
        // cout << s1_size << endl;
        // cout << s2_size << endl;


        // for(auto s : s1){
        //     cout << s << "";
        // }
        // cout << endl;
        // for(auto s : s2){
        //     cout << s << "";
        // }
        // cout << endl;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends