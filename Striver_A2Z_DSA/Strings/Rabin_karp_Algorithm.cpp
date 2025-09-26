#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector <int> search(string pat, string txt) {
            int n = txt.size(), m = pat.size();
            int hashtxt = 0, hashpat = 0, p = 7, mod = 107;
            vector<int> ans;
            // int temp_p = p;
            int pLeft = 1, pRight = 1;
            for(int i=0; i<m; i++){
                hashtxt += ((txt[i]-'a'+1)*pRight)%mod;
                hashpat += ((pat[i]-'a'+1)*pRight)%mod;
                pRight = (pRight*p)%mod;
            }

            for(int i=0; i<=n-m; i++){
                if(hashtxt==hashpat){
                    if(txt.substr(i, m) == pat) ans.push_back(i);
                }
                
                hashtxt = (hashtxt-((txt[i]-'a'+1)*pLeft)%mod+mod) % mod;
                hashtxt = (hashtxt+((txt[i+m]-'a'+1)*pRight)%mod) % mod;

                hashpat = (hashpat*p)%mod;

                pLeft = (pLeft*p) %mod;
                pRight = (pRight*p)% mod;

            }
            return ans;
        }
};