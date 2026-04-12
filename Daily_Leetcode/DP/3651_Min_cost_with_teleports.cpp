#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> points; // all grid { r, c }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }

        // sorting the points using comparator based on grid values
        auto customGridComparator = [&](pair<int, int> &p1, pair<int, int> &p2){
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        };
        sort(points.begin(), points.end(), customGridComparator);

        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        // costs [[]] to store cost for each (i, j) pair/cell

        // for each t value teleports values from 0 to K (atmost k)
        for (int t = 0; t <= k; t++) {
            cout << "teleport : " << t << endl;
            int minCost = INT_MAX;
            // calculate minCost for every t teleports possible

            // iterate the points (asc order)
            for (int i = 0, j = 0; i < points.size(); i++) {

                int row = points[i].first, col = points[i].second;
                
                minCost = min(minCost, costs[row][col]);
                cout << "("<<row <<", "<< col << ") :" << grid[row][col] << " : costs : " << costs[row][col] << " minCost : " << minCost << endl;

                // if there are multiple grid cells with same values take the last one
                // continue the loop to take the last one
                if (i + 1 < m*n) {
                    int nextRow = points[i+1].first, nextCol = points[i+1].second;
                    if(grid[row][col] == grid[nextRow][nextCol]) continue;
                }

                // iterate from 0 to i and store the minCost in costs array
                for (int r = j; r <= i; r++) {
                    costs[points[r].first][points[r].second] = minCost;
                    cout << "--------------------------------------------------------->changed costs[" << points[r].first <<"][" << points[r].second << "]: " << minCost << endl;
                }

                // j should be i+1, because next time it iterates the above for loop
                // it should start from next value or cell
                j = i + 1;
            }

            // in the above for loop --> iterate through points {row, col} (sorted based on grid values)
                // calculate minCost by comparing with costs array
                // if next pair in points have same value as current just go to that element
                // we also iterate from [j = 0 until i] and then [prev j to current i]
                    // to update the costs array with the current minCost value untill i

            // after completing this above loop we have 
                // minCost for all points/cells for teleportation t in costs array
 
          for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    cout << "i,j : (" << i << "," << j<< ") : " << costs[i][j] << endl;

                    // iterate from destination cell (m-1, n-1) to (0, 0)
                    // if destination cell assign cost to 0
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        cout << "i,j : (" << i << "," << j<< ") : " << costs[i][j] << endl;
                        continue;
                    }

                    // if not last row 
                        // take minimum cost from [current cell cost, prev row cell cost + prev row grid cell]
                        // store that minimum value in cost array
                    
                    // if not last col 
                        // take minimum cost from [current cell cost, prev col cell cost + prev col grid cell]
                        // store that minimum value in cost array

                    if (i != m - 1) {
                        costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                        cout << "-------------------------------->take min from nextrow i,j : (" << i << "," << j<< ") : " << costs[i][j] << endl;
                    }
                    if (j != n - 1) {
                        costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                        cout << "-------------------------------->take min from nextcol i,j : (" << i << "," << j<< ") : " << costs[i][j] << endl;
                    }
                }
            }
        }
        return costs[0][0];
    }
};

// Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2
// Output: 7

// Input: grid = [[1,2],[2,3],[3,4]], k = 1
// Output: 9
