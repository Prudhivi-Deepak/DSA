class Solution{
public:

    int bfs(pair<int, int> source, pair<int, int> destination, vector<vector<int>> &grid){

        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> dir = {{-1,0}, {0, -1}, {0,1}, {1,0}};

        if(source.first == destination.first && source.second == destination.second) return 0;

        if(grid[source.first][source.second] == 0 || grid[destination.first][destination.second]==0) return -1;

        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        queue<pair<pair<int,int>, int>> q;

        q.push({{source.first, source.second}, 0}); 
        distance[source.first][source.second] = 0;

        while(!q.empty()){
            auto [currCell, dist] = q.front(); q.pop();
            // cout << currCell.first << endl;

            for(auto d: dir){
                int di = d.first;
                int dj = d.second;
                // cout << currCell.first << endl;
                int ni = currCell.first+di, nj = currCell.second+dj; 
                // cout << ni << nj << endl;

                if( ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj] && distance[ni][nj]==1e9){
                    distance[ni][nj] = dist + 1;
                    q.push({{ni, nj}, dist+1});
                }

            }
        }

        if(distance[destination.first][destination.second] == 1e9) return -1;
        return distance[destination.first][destination.second];
    }

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        return bfs(source, destination, grid);
    }
};