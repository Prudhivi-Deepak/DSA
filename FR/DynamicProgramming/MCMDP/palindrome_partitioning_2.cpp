class Solution {
	public:
        bool isPalindrome(string &t){
            int l=0, r = t.size()-1;

            while(l<r){
                if(t[l]!=t[r]) return false;
                l++; r--;
            }
            return true;
        }

        int f(int i, string s, vector<int> &dp){
            if(i==s.size()) return 0;

            if(dp[i]!= -1) return dp[i];

            int min_partitions = 1e9, cost = 0;
            string substr = "";

            for(int j=i; j<s.size(); j++){
                substr += s[j];

                if(isPalindrome(substr)){
                    cost = 1 + f(j+1, s, dp);
                    min_partitions = min(min_partitions, cost);
                }
            }
            return dp[i] = min_partitions;
        }

    	int minCut(string s){
    		//your code goes here

            vector<int> dp(s.size()+1, 0);

            int n = s.size();

            dp[n]=0;

            for(int i=n-1; i>=0; i--){
                int min_partitions = 1e9;
                //  cost = 0;
                string substr = "";

                for(int j=i; j<s.size(); j++){
                    substr += s[j];

                    if(isPalindrome(substr)){
                        int cost = 1 + dp[j+1];
                        min_partitions = min(min_partitions, cost);
                    }
                }
                dp[i] = min_partitions;
            }

            return dp[0]-1;

            // return f(0, s, dp)-1;
	    }
};
