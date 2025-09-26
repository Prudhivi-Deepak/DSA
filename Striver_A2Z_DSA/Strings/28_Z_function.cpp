#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
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
            vector<int> res;
            vector<int> z = computeZ(pattern+"$"+text);
            int n = text.size(), m = pattern.size();
    
            for(int i=m+1; i<n+m+1; i++){
                if(z[i]==m){
                    // cout << " : " << i-m-1 << endl;
                    res.push_back(i-m-1);
                }
            }
            return res.size()>0 ? res[0] : -1;
        }
    };