class Solution{
    public:

    void f(int i, int j, string path, vector<string> &Allpaths, vector<vector<bool>> &visited, vector<vector<int>> &grid){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0) return;
        
        if(i==grid.size()-1 && j==grid[0].size()-1){
            Allpaths.push_back(path); return;
        }

        visited[i][j] = true;

        // go up
        f(i-1, j, path+'U', Allpaths, visited, grid);
        
        // go to bottom
        f(i+1, j, path+'D', Allpaths, visited, grid);

        // go to L
        f(i, j-1, path+'L', Allpaths, visited, grid);

        // go to right
        f(i, j+1, path+'R', Allpaths, visited, grid);

        visited[i][j] = false;
    }
    
    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here

        // we need to return the path as well
        // so we start from 0,0 thengo U D L R dir
        // maintain a visited matrix then if we reached n,n --> add the path to ans
        // return ans

        string path;
        vector<string> Allpaths;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        f(0, 0, path, Allpaths, visited, grid);
        return Allpaths;
    }
};