class Solution {
public:
    int characterReplacement(string s, int k) {
        //your code goes here
        // k = 2
        // 0 1 2 3 4 5 6 7 8 9 10 11
        // B A A B A A B B B A  A A
        //   l     r 
        // B : 1
        // A : 3
        // maxFreq = 3
        // currwin = 4
        // rem = 4-2 = 2 <= k  no --> so shrink it
        // 
        // always keep the maxFreq variable
        // and other currWindow - maxFreq = that many times we need to replace = whihc should be <= k
        // else shrink the currWindow

        unordered_map<char,int> umap;
        int l = 0, r = 0, maxFreq = 0, maxLength = 0, n = s.size();

        while(r<n){
            umap[s[r]]++;
            if(umap[s[r]] > maxFreq) maxFreq = umap[s[r]];
            
            // shrink if windowlen-maxfreq > k
            while(r-l+1-maxFreq > k){
                umap[s[l]]--;
                if(umap[s[l]]==0) umap.erase(s[l]);
                l++;
            }

            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};