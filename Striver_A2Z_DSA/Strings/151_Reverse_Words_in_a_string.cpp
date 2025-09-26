#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            reverse(s.begin(), s.end());
           int i=0, j=0, startindex=0;
    
           while(j<s.size()){
                while(j<s.size() && s[j]==' ') j++;
                while(j<s.size() && s[j]!=' ') swap(s[i++], s[j++]);
                reverse(s.begin()+startindex, s.begin()+i);
                startindex = i+1;
                s[i++] = ' ';
           }
    
           i=s.size()-1; 
           while(i>=0 && s[i]==' ') i--;
    
           if(i+1<s.size()) s.erase(i+1,s.size()-i);
           return s;
        }
    };