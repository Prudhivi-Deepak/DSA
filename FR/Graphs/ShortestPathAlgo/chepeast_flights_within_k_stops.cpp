class Solution{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int K) {

        // create adj list with pair {to, w}
        vector<vector<pair<int,int>>> adj(n);

        for(auto edge: flights){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // store minDist in vector
        vector<int> minDist(n, 1e9);

        // now store {node, cost, stops} in q and process only valid elements
        queue<pair<pair<int,int>, int>> q;

        q.push({{src, 0}, 0}); minDist[src] = 0;

        while(!q.empty()){
            auto [state, stops] = q.front(); q.pop();
            int node = state.first, cost = state.second;

            if(stops > K) continue;

            for(auto edge: adj[node]){

                int negNode = edge.first, negW = edge.second;
                int calDist = cost + negW;

                if(calDist < minDist[negNode]){
                    minDist[negNode] = calDist;
                    q.push({{negNode, calDist}, stops+1});
                }
            }

        }

        if(minDist[dst]==1e9) return -1;

        return minDist[dst];        
    }
};
