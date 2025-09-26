#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int computeLPS(string s){
            int j=0, i=1, n = s.size();
            vector<int> lps(n,0);
    
            while(i<n){
                if(s[i]==s[j]){
                    lps[i] = j+1;j++;
                }
                else{
                    while(j>0 && s[i]!=s[j]){
                        j = lps[j-1];
                    }
                    if(s[i]==s[j]){
                        lps[i] = j+1; j++;
                    }
                }
                i++;
            }
            return lps[n-1];
        }
        string shortestPalindrome(string s) {
             string reverse_s = s;
            reverse(reverse_s.begin(), reverse_s.end());
            int match_count = s.size() - computeLPS(s+"$"+reverse_s);
            // cout << match_count << " : " << s.size()<< endl;
            string palindrome = reverse_s.substr(0, match_count);
            // while(match_count>0){
            //     palindrome = s[s.size() - match_count] + palindrome;
            //     match_count--;
            // }
            return palindrome+s;
        }
    };