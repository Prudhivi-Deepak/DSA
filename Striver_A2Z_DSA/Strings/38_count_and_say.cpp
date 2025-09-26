#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string countsay(string s){
            if(s.size()==1) return "1"+s;
            int i=0;
            string res = "";
            int cnt=1;
            char num=s[i++];
            while(i<s.size()){
                if(s[i]==num) cnt++;
                else {
                    res += to_string(cnt)+num;
                    cnt = 1;num = s[i];
                }
                i++;
            }
            res += to_string(cnt)+num;
            return res;
        }
        string countAndSay(int n) {
            string res = "1";
            for(int i=0; i<n-1; i++){
                res = countsay(res);
            }
    
            return res;
        }
    };