class Solution {
   public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        vector<vector<int>> adjmatrix(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            adjmatrix[i][i] = 0;
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjmatrix[u][v] = w;
            adjmatrix[v][u] = w;
        }

		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					adjmatrix[i][j] = min(adjmatrix[i][j], adjmatrix[i][k]+adjmatrix[k][j]);
				}
			}
		}

        // now find the less neg with in <= distanceThreshold
        // check for all vertices one by one
        int maxCitywithMinReachableNeg = 1e9, minCitiesCount = 1e9;
        for (int i = 0; i < n; i++) {
            // if adj matrix value 1e9 means no edge not neg
            int count = 0;
            for (int j = 0; j < n; j++) {
				// cout << i << j << " = " << adjmatrix[i][j] << endl;
                if (adjmatrix[i][j] != 1e9 && i != j &&
                    adjmatrix[i][j] <= distanceThreshold) {
                    count++;
                }
            }
			// cout << i << ": " << count << endl;

            if (count < minCitiesCount) {
                minCitiesCount = count;
                maxCitywithMinReachableNeg = i;
            } else if (count == minCitiesCount) {
                maxCitywithMinReachableNeg = i;
            }
        }
        return maxCitywithMinReachableNeg;
    }
};
