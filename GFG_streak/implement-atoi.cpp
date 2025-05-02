//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        
        int i=0, ans=-1, asci, neg = 0;
        // double n  = sizeof(s);
        // cout << i << ans << n << endl;
        while(s[i] != '\0'){
            asci = s[i];
            // cout << s[i] << endl;
            // cout << "asci : " << asci << endl;
            // cout << "asci : " << (48 <= asci && asci <= 57) << endl;
            if( (s[i] == ' ' && ( i==0 || s[i-1] == ' ' ) || asci == 43) ){
                // cout << "empty" << endl;
                i++;
                continue;
            }
            else if(asci == 45 && ans == -1){
                neg = 1;
            }
            else if(!(48 <= asci && asci <= 57) || (s[i] == ' ' && s[i-1] != ' ')){
                break;
            }
            else{
                if(ans == -1){
                    ans = 0;
                }
                ans *= 10;
                ans += asci-48;
                // cout << "asci - 48 : " << asci-48 << endl;
                // cout << "ans : " << ans << endl;
            }            
            i++;
        }
        
        if(neg == 1 && ans == -1){
            return 0;
        }
        else if(neg == 1){
            ans = -ans;
        }

        if(ans > pow(2,31)){
            return pow(2,31)-1;
        }
        else if(ans < pow(-2,31)){
            return pow(-2,31);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        // char s[20];
        // cin >> s;
        char s[] = {' ',' ',' ',' ',' ','1','2', '9','3','-', 'p', '2','3','1','2','3','1','3','1','1', '\0'};
        Solution ob;
        cout << s << endl;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends