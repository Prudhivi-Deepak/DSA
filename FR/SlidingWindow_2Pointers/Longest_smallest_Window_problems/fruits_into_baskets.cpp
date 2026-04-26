class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        unordered_map<int,int> umap;

        int l = 0, r = 0, maxLength = 0, n = fruits.size();

        while(r<n){
            // shrink it if umap.size()>2
            umap[fruits[r]]++;
            while(umap.size()>2){
                umap[fruits[l]]--;
                if(umap[fruits[l]]==0){
                    umap.erase(fruits[l]);
                }
                l++;
            }
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};