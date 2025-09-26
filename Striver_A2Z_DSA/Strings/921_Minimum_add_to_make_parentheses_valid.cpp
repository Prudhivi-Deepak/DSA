#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minAddToMakeValid(string s) {
            int open = 0, close = 0, i=0;
            while(i < s.size()){
                if(s[i++] == ')'){
                    if(open > 0) open--;
                    else close++;
                }
                else{
                    open++;
                }
            }
            return open+close;
            // if((open+close)%2!=0) return 1;
            // return (open%2)+(close%2)+open/2+close/2;
        }
    };