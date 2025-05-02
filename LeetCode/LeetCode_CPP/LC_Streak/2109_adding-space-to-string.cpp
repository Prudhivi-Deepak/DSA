#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // string ans = "";
        // int index = 0;
        // for(int i=0; i<s.size(); i++){
        //     if(index<spaces.size() && spaces[index] == i){
        //         ans = ans + ' ' + s[i];
        //         // cout << i  << " | " << index << " | " << s[i] << " | "  << spaces[index] << " | "  << ans << endl;
        //         index++;
        //     }
        //     else{
        //         ans += s[i];
        //     }
        // }
                    // cout << s.substr(index,spaces[i]-index) << endl;
            // cout << i << " | " << index << " | " << ans << endl;
        // string ans = "";
        // int index = 0;
        // for(int i=0; i < spaces.size(); i++){
        //     ans += s.substr(index,spaces[i]-index) + ' ';
        //     index = spaces[i];
        // }
        // ans += s.substr(index);
        // return ans;
        int s_n = s.size(), space_n = spaces.size(), index = 0;; 
        string ans(s_n + space_n, ' ');
        for (int i = 0; i < s_n; i++) {
            if (index < space_n && i == spaces[index]) {
                ans[i + index] = ' '; 
                index++; 
            }
            ans[i + index] = s[i]; 
        }
        return ans; 

    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        cin >> str;
        // getline(cin, str);
        // getline(cin, pat);
        // cin.ignore();
        Solution ob;
        int n;
        cin >> n;
        vector<int> spaces(n);
        for (int i = 0; i < n; ++i) {
            cin >> spaces[i];
        }
        string result = ob.addSpaces(str, spaces);
        cout << result << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}