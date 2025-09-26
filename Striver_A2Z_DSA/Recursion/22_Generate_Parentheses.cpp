#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void f(string s, int open, int close, int n, vector<string> &ans){
    
            if(close > open || open > n) return;
            if(open+close == 2*n && open == close) ans.push_back(s);
    
            f(s+"(", open+1, close, n, ans);
            if(open > close) f(s+")", open, close+1, n, ans);
           
            return ;
        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            f("(", 1, 0, n, ans);
            return ans;
        }
    };