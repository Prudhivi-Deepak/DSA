struct compare{
    bool operator()(pair< pair<int,int>, int> p1, pair< pair<int,int>, int> p2){
        return p1.second > p2.second;
    }
};

class Solution
{
public:
    int findByDijkstras(vector<vector<int>> &heights){
        int n = heights.size(), m = heights[0].size();
        vector<pair<int,int>> dir = {{-1,0}, {0, -1}, {0,1}, {1,0}};

        // use PQ for dijkstra's algo
        // store row, col, dist
        priority_queue< pair< pair<int,int>, int>, vector<pair< pair<int,int>, int> >,  compare> minHeap;
        vector<vector<int>> minEffort(n, vector<int>(m, 1e9));

        minHeap.push({{0,0}, 0});

        while(!minHeap.empty()){
            auto [currCell, effort] = minHeap.top(); minHeap.pop();
            // cout << effort << endl;

            if(currCell.first == n-1 && currCell.second == m-1) return effort;

            for(auto d: dir){
                int di = d.first;
                int dj = d.second;
                int ni = currCell.first+di, nj = currCell.second+dj;

                if( ni>=0 && nj>=0 && ni<n && nj<m 
                && abs(heights[currCell.first][currCell.second]  - heights[ni][nj]) < minEffort[ni][nj]){
                    int calEffort = abs(heights[currCell.first][currCell.second] - heights[ni][nj]);
                    minEffort[ni][nj] = calEffort;
                    minHeap.push({{ni, nj}, max(calEffort, effort)});
                }
            }
        }
        return minEffort[n-1][m-1];
    }



    int MinimumEffort(vector<vector<int>> &heights){
        return findByDijkstras(heights);
    }
};

