class Solution {
public:
    bool compareTwoStrings(string &s1, string &s2){
        int n1 = s1.size();
        int n2 = s2.size(), diff=0;
        if(n1+1!=n2) return false;
        int i = 0, j=0;
        while(i<n1){
            if(s1[i]!=s2[j]) diff++;
            else i++;
            j++;
            if(diff>1) return false;
        }
        return true;
    }

    bool static comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }

    int longestStringChain(vector<string>& words) {
        if(words.size()==1) return 1;
        sort(words.begin(), words.end(), comp);

        int n = words.size();
        vector<int> dp(n, 1);
        // , parent(n, 0);
        int max_lscIndex = 0;

        for(int i=1; i<n; i++){
            // parent[i] = i;
            for(int j=i-1; j>=0; j--){
                if(compareTwoStrings(words[j], words[i])){
                    if(dp[i]< dp[j]+1){
                        dp[i] = dp[j]+1;
                        // parent[i] = j;
                    }
                }
            }
            // cout << dp[i] << endl;
            if(dp[i] > max_lscIndex){
                max_lscIndex = dp[i];
            }
        }

        // vector<int> LSC;
        // while(max_lscIndex!=dp[max_lscIndex]){
        //     LSC.push_back(parent[max_lscIndex]);
        //     max_lscIndex = parent[max_lscIndex];
        // }
        // LSC.push_back(parent[max_lscIndex]);
        // reverse(LSC.begin(), LSC.end());
        return max_lscIndex;
    }
};
