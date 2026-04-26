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

	string shortestPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        string str = s + "$" + temp;
        int n = str.size();
        vector<int> lps(n, 0);
        KMP(str, lps);

        int diff = s.size() -  lps[n-1];
        return temp.substr(0, diff) + s;
	}
};