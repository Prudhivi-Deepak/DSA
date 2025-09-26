#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> computeLPS(string s){
            int i=1, j=0, n = s.size();
            vector<int> lps(n,0);
    
            while(i<n){
                if(s[i]==s[j]){
                    lps[i] = j+1;j++; //how many prefix matched
                }
                else{
                    while(j>0 && s[i]!=s[j]){
                        j = lps[j-1];
                    }
                    if(s[i]==s[j]){
                        lps[i] =j+1;j++;
                    }
                }
                i++;
            }
            return lps;
    
        }
        vector<int> computeZ(string s){
            int l=0, r=0, i=1, n=s.size();
            vector<int> z(n,0);
            while(i<n){
                //out of window
                if(i>r){
                    while(i+z[i]< n && s[i+z[i]]==s[z[i]]) z[i]++;
                }
                else{//inside window
                    if(i+z[i-l] <= r){//under boundary
                        z[i] = z[i-l];
                    }
                    else{// out of boundary
                        z[i] = r-i+1; //take untill boundary
                        //now calculate the rest after boundary
                        while(i+z[i]< n && s[i+z[i]]==s[z[i]]) z[i]++;
                    }
                }
                l = i, r = i+z[i]-1;
                i++;
            }
            return z;
        }
        int strStr(string text, string pattern) {
            vector<int> ans;
            int n = text.size(), m = pattern.size();
            vector<int> lps = computeLPS(pattern+"$"+text);
    
            for(int i=m+1; i<=n+m; i++){
                if(lps[i]==m){
                    ans.push_back(i-2*m);
                }
            }
            return ans.size()>0 ? ans[0] : -1;
            // vector<int> res;
            // vector<int> z = computeZ(pattern+"$"+text);
            // int n = text.size(), m = pattern.size();
    
            // for(int i=m+1; i<n+m+1; i++){
            //     if(z[i]==m){
            //         // cout << " : " << i-m-1 << endl;
            //         res.push_back(i-m-1);
            //     }
            // }
            // return res.size()>0 ? res[0] : -1;
        }
    };