#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeKdigits(string num, int k) {
            vector<int> st;
            int i=0;
            while(i < num.size()){
                //'0' - 48 num-'0' gives number
                while(!st.empty() && st.back()-'0' > num[i]-'0' && k>0){
                    st.erase(st.begin()+st.size()-1, st.end());
                    k--;
                }
    
                st.push_back(num[i]);
                i++;
            }
    
            while(k>0 && !st.empty()){
                st.erase(st.begin()+st.size()-1, st.end());
                k--;
            }
    
            if(st.empty()) return "0";
            num="";
            i=0;
            while(i<st.size()){
                if(num.empty() && st[i]=='0'){
                }
                else{
                    num+=st[i];
                }
                i++;
            }
            if(num.empty()) return "0";
            return num;
        }
    };