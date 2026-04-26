class Solution{
public:
    vector<pair<int,int>> dir = {{-1,0}, {0, -1}, {1, 0}, {0, 1},
                                {-1,-1}, {-1, 1}, {1, -1}, {1,1}};


    void dfs(int i, int j, vector<vector<int>> &vis_grid, vector<vector<char>> &grid){
        vis_grid[i][j] = 1;
        int m = grid.size(), n = grid[0].size();
        for(auto d: dir){
            int n_i = i+d.first, n_j = j+d.second;

            if(n_i>=0 && n_j>=0 && n_i < m && n_j < n && vis_grid[n_i][n_j]==0 && grid[n_i][n_j]=='1'){
                dfs(n_i, n_j, vis_grid, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis_grid(m, vector<int>(n, 0));
        int cnt = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && vis_grid[i][j]==0){
                    dfs(i, j, vis_grid, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
