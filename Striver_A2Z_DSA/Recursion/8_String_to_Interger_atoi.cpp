#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int myAtoi(string s) {
            int i = 0, neg_sign = 0;
            long number = 0;
            //remove any leading whitespace
            while(s[i]==' ') i++;
    
            //find the sign if exists
            if(s[i] == '-') {neg_sign=1; i++;}
            else if(s[i] == '+') i++;
    
            //now the read the number;
            while(0 <= s[i]-'0' && s[i]-'0' <=9){
    
                int D = neg_sign ? pow(-2,31) : pow(2, 31)-1;
    
                if(neg_sign){
                    number = number*10 - (s[i]-'0');
                    if(number<D){ number = D; break;}
                }
                else{
                    number = number*10 + (s[i]-'0');
                    if(number>D){ number = D; break;}
                }
                i++;
            }
            
            return number;
        }
    };