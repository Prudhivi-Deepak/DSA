class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        unordered_map<char, int> umap;

        int l=0, r=0, maxLength = 0, n = s.size();

        while(r<n){
            umap[s[r]]++;

            while(umap.size()>k){
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