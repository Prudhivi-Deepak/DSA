class Solution{
    public:
    vector<pair<int,int>> dir = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};
                                // {-1,-1}, {-1, 1}, {1, -1}, {1,1}};
    void dfs(int i, int j, int cellColor, int newColor, vector<vector<int>> &image){
        image[i][j] = newColor;
        int m = image.size(), n = image[0].size();

        for(auto d: dir){
            int n_i = d.first+i, n_j = d.second+j;

            if(n_i>=0 && n_j >=0 && n_i<m && n_j <n &&
                image[n_i][n_j]==cellColor){
                    dfs(n_i, n_j, image[n_i][n_j], newColor, image);
                }

        }

    }
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {

        if(image[sr][sc] == newColor) return image;
        
        dfs(sr, sc, image[sr][sc], newColor, image);

        return image;

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(image[i][j]==1) return false;
        //     }
        // }

    }
};
