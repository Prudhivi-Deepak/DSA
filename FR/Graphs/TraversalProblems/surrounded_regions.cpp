class Solution{
public:
    vector<pair<int,int>> dir = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(int i, int j, vector<vector<char>> mat, vector<vector<int>> &visited){
        visited[i][j] = 1;
        int n = mat.size(), m = mat[0].size();

        for(auto d : dir){
            int n_i = i+d.first, n_j = j+d.second;

            if(n_i>=0 && n_j>=0 &&n_i<n && n_j<m &&
                mat[n_i][n_j]=='O' && visited[n_i][n_j]==0){
                    dfs(n_i, n_j, mat, visited);
                }
        }

    }

    vector<vector<char>> fill(vector<vector<char>> mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==n-1 || j==m-1 ) && mat[i][j]=='O'){
                    dfs(i, j, mat, visited);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};