#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // 98 99 100 ..........122
        // 98        122%122+98 123
        // cout << i << "-" << j << " " << str1[i] << " | " <<  (char)((str1[i]+1)>122 ? 97 : (str1[i]+1)) << "==" << str2[j] << endl;
        int s1_n = str1.size(), s2_n = str2.size();
        if(s1_n < s2_n){
            return false;
        }
        else{
            int i=0, j=0;
            while(i < s1_n){
                if(str1[i] == str2[j] || (char)((str1[i]+1)>122 ? 97 : (str1[i]+1)) == str2[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
                if(j==s2_n){
                    return true;
                }
            }
        }
        return false;

        // abc
        // ad

        // abcdbhdefghij
        // iiiiiiiiiiiii
        // bdhj
        // jjjj
        // 

    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution sol;
        cout << (sol.canMakeSubsequence(str1, str2) ? "true" : "false") << endl;
    }
    return 0;
}