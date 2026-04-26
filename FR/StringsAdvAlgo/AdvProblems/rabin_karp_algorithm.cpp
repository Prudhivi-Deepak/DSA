class Solution{
    public:
        vector <int> search(string pat, string txt) {
            int p = 7, ptxt = 1, ppat = 1, mod = 101, htxt = 0, hpat = 0;
            int n = txt.size(), m = pat.size();

            for(int i=0; i<m; i++){ //0 to m-1
                htxt = (htxt + (txt[i]-'a'+1)*ptxt) % mod;
                hpat = (hpat + (pat[i]-'a'+1)*ptxt) % mod;
                ptxt = (ptxt * p) % mod;
            }

            vector<int> ans;

            for(int i=0; i<=n-m; i++){
                // cout << htxt << " : " << hpat <<endl;
                // remove i-m index letter(i-m, i+1-m, . .)
                if(htxt == hpat){
                    if(txt.substr(i, m) == pat) ans.push_back(i);
                    // ans.push_back(i);
                }

                htxt = ((htxt - (txt[i]-'a'+1)*ppat) % mod + mod) % mod;
                htxt = (htxt + (txt[i+m]-'a'+1)*ptxt % mod ) % mod;

                hpat = (hpat*p) % mod;
                ptxt = (ptxt*p) % mod;
                ppat = (ppat*p) % mod;
                // add i index letter (m, m+1, m+2 ...)
            }
            return ans;
        }
};