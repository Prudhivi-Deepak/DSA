class Solution {
public:
    int numberOfSubstrings(string s) {
        //your code goes here
        // 0 1 2 3 4
        // a b c b a
        //         r
        // a = 4, b = 3, c = 2
        // minimum index is 0 so 0+1 = 1 substring 
        // min is still 0 + 1  = 1 substring 
        // min is 2, so 2+1 = 3 substrings

        // so 1+1+3 is 5 substrings 

        int alp[3] = {-1,-1,-1}, r = 0, n = s.size(), total_substrings = 0;
        while(r < n){
            alp[s[r]-'a'] = r;
            if(alp[0]!=-1 && alp[1]!=-1 && alp[2]!=-1){
                int min_index = min({alp[0], alp[1], alp[2]});
                total_substrings += min_index+1;
            }
            r++;
        }
        return total_substrings;
    }
};