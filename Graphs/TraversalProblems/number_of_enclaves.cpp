class Solution{
public:
    vector<pair<int,int>> dir = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
        visited[i][j] = 1;
        int m =grid.size(), n = grid[0].size();

        for(auto d: dir){
            int n_i = i+d.first, n_j = j+d.second;

            if(n_i>=0 && n_j>=0 && n_i<m && n_j<n &&
                visited[n_i][n_j]==0 && grid[n_i][n_j]==1){
                    dfs(n_i, n_j, grid, visited);
                }
        }

    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // find all 1's connected to boundary and dfs to remove all 1'S or marke them visited
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && visited[i][0]==0) dfs(i, 0, grid, visited);
            if(grid[i][n-1]==1 && visited[i][n-1]==0) dfs(i, n-1, grid, visited);
        }

        for(int j=0; j<n; j++){
            if(grid[0][j]==1 && visited[0][j]==0) dfs(0, j, grid, visited);
            if(grid[m-1][j]==1 && visited[m-1][j]==0) dfs(m-1, j, grid, visited);
        }

        int cnt = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
