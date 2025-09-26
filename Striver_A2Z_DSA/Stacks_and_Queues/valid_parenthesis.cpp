#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            int i=0;
            while(i < s.size()){
                if(s[i] == ')'){
                    if(!st.empty() && st.top() == '(') st.pop();
                    else return false;
                } 
                else if (s[i] == '}'){
                    if(!st.empty() && st.top() == '{') st.pop();
                    else return false;
                } 
                else if(s[i] == ']' ){
                    if(!st.empty() && st.top() == '[') st.pop();
                    else return false;
                }
                else{
                    st.push(s[i]);
                }
                i++;
            }
    
            if(st.empty()) return true;
            return false;
        }
        bool isValid1(string s) {
            // this solution is not possible for multiple types of brackets if it's single bracket we can do this
            int p1 = 0, p2 = 0, p3 = 0, pt = 0, i=0;
            while(i < s.size()){
                if(s[i] == '(') { p1 = p1+1;}
                else if(s[i] == ')'){ p1 = p1-1;}
    
                // else if(s[i] == '{') {p2 = p2+1;}
                // else if(s[i] == '}'){ p2 = p2-1;}
    
                // else if(s[i] == '[') {p3 = p3+1;}
                // else if(s[i] == ']'){ p3 = p3-1;}
    
                if(p1<0 
                    // || p2<0 || p2<0
                ) return false;
                i++;
            }
    
            if(p1==0 
                // && p2==0 & p3==0
            ) return true;
            
            return false;
        }
    };