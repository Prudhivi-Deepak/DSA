class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size(), m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<pair<int,int>> dir = {{-1,0}, {0,-1}, {0,1}, {1,0}};
        int distance = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    grid[i][j] = distance;
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){

            int qSize = q.size();
            distance++;

            for(int t=0; t<qSize; t++){
                auto [i,j] = q.front(); q.pop();

                for(auto d: dir){
                    int n_i = i+d.first, n_j=j+d.second;
                    if(n_i>=0 && n_j>=0 && n_i<n && n_j<m &&
                        grid[n_i][n_j]==0 && visited[n_i][n_j]==0){
                            visited[n_i][n_j] = 1;
                            grid[n_i][n_j] = distance;
                            q.push({n_i, n_j});
                        }
                }
            }
        }

        return grid;
    }
};