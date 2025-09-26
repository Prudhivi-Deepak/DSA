#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        void f(int i, int n, string s, vector<string> &result, string &digits, string combos[]){
            if(i==n){
                result.push_back(s);
                return;
            }
            
            for(auto ss : combos[digits[i]-'0'])
                f(i+1, n, s+ss, result, digits, combos);
            return;
        }
    
        vector<string> letterCombinations(string digits) {
    
            if(digits == "") return vector<string>{};
            string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            vector<string> result;
    
            f(0, digits.size(), "", result, digits, combos);
            
            return result;
        }
    };