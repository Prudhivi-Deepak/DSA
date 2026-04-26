class Solution{
    public:
        void KMP(string str, vector<int> &lps){
            // prefix and suffix

            int i=1, j=0, n = str.size();
            // cout << lps[0] << " ";

            while(i<n){
                // see if i and j matches assign j+1 and increment both
                if(i<n && str[i]==str[j]){
                    lps[i] = j+1;
                    j++;
                }
                else{
                    // if they are not equal assign back j to most possible index to compare 
                    while(j>0 && str[j]!=str[i]){
                        j = lps[j-1];
                    }

                    // compute the current i
                    if(str[j]==str[i]){
                        lps[i] = j+1;
                        j++;
                    }
                }
                // cout << lps[i] << " ";
                i++;
            }
            // cout << endl;
        }

        void KMP1(string str, vector<int> &lps){
            // prefix and suffix

            int i=1, j=0, n = str.size();
            // cout << lps[0] << " ";

            while(i<n){
                // see if i and j matches assign j+1 and increment both
                bool flag = true;
                while(i<n && str[i]==str[j]){
                    lps[i] = j+1;
                    j++;
                    i++;
                    flag = false;
                }
                // else{
                // if they are not equal assign back j to most possible index to compare 
                while(j>0 && str[j]!=str[i]){
                    j = lps[j-1];
                }

                if(flag) i++;

                // compute the current i
                // if(str[j]==str[i]){
                //     lps[i] = j+1;
                //     j++;
                // }
                // }
                // cout << i  << " : " << lps[i] << " ";
                // i++;
            }
            // cout << endl;
        }

        vector <int> search(string pat, string txt){
            string str = pat + "$" + txt;
            // cout << str << endl;
            int n = str.size(), m = pat.size();
            vector<int> lps(n, 0);
            KMP1(str, lps);

            vector<int> ans;

            // iterate from m+1 to n
            for(int i=m+1; i<n; i++){
                if(lps[i]==m){
                    // current index is m 
                    // means actual index in str is i-m 
                    // and actual index in txt is i-m-(m+1)
                    ans.push_back(i-m-m);
                }
            }
            return ans;
        }
};