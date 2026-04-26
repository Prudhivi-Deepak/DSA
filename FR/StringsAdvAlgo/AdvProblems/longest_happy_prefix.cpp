class Solution{
  public:
    void KMP(string s, vector<int> &lps){
        int i=1, j = 0, n = s.size();
        while(i<n) {
            bool flag = true;
            while(i<n && s[j]==s[i]){
                lps[i] = j+1;
                i++;
                j++;
                flag = false;
            }

            while(j>0 && s[j]!=s[i]){
                j = lps[j-1];
            }
            if(flag) i++;
        }
        // cout << lps[n-1] << endl;
    }

	string lps(string s) {
        // a b a b a b 
        // 0 0 1 2 3 4
        int n = s.size();
        vector<int> lps(n, 0);
        KMP(s, lps);

        return s.substr(0, lps[n-1]);        
	}
};