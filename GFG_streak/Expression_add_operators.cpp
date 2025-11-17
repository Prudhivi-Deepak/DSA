
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void f(int i, long long expr, long long lastexp, string &s, int target, vector<string> &Allcomb, string comb){
        if(i==s.size()){
            if(expr==target)
                Allcomb.push_back(comb);
            return;
        }
        
        // if(i>s.size()) return;
        
        for(int j=i; j<s.size(); j++){
            
            if(j>i && s[i]=='0') break;
            
            string currNum = s.substr(i, j-i+1);
            long long num = stoll(currNum);
            
            if(i==0) f(j+1, num, num, s, target, Allcomb, currNum);
            else{
                f(j+1, expr+num, num, s, target, Allcomb, comb+"+"+currNum);
                f(j+1, expr-num, -num, s, target, Allcomb, comb+"-"+currNum);
                f(j+1, expr-lastexp+lastexp*num, lastexp*num ,s, target, Allcomb, comb+"*"+currNum);
            }
        }
        
        // int currNum = s[i]-'0';
        
        // comb += s[i];
        // f(i+1, exp*10+currNum, s, target, Allcomb, comb);
        // comb.pop_back();
        
        // comb += '+';
        // comb += s[i];
        // f(i+1, exp+currNum, s, target, Allcomb, comb);
        // comb.pop_back();
        // comb.pop_back();
        
        // comb += '-';
        // comb += s[i];
        // f(i+1, exp-currNum, s, target, Allcomb, comb);
        // comb.pop_back();
        // comb.pop_back();
        
        // comb += '*';
        // comb += s[i];
        // f(i+1, exp*currNum, s, target, Allcomb, comb);
        // comb.pop_back();
        // comb.pop_back();
        
    }
    
    vector<string> findExpr(string &s, int target) {
        // code here
        vector<string> Allcomb; string comb;
        f(0, 0, 0, s, target, Allcomb, comb+s[0]);
        sort(Allcomb.begin(), Allcomb.end());
        return Allcomb;
    }
};