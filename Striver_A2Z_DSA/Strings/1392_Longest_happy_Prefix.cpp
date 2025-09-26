#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string longestPrefix(string s) {
            int i=1, j=0, n=s.size();
            vector<int> lps(n, 0);
    
            while(i<n){
                if(s[i]==s[j]){
                    lps[i] = j+1;j++;
                }
                else{
                    while(j>0 && s[i]!=s[j]) j = lps[j-1];
                    if(s[i]==s[j]){
                        lps[i] = j+1;j++;
                    }
                }
                i++;
            }
            // cout << lps[n-1] << endl;
            return lps[n-1] >0 ? s.substr(0, lps[n-1]) : "";
        }
    };