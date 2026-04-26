int MOD = 1e9+7;
class Solution{
public:
    int countPaths(int n, vector<vector<int>> &roads) {

        // build a adj list
        vector<vector<pair<int,int>>> adj(n);

        for(auto edge: roads){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int ,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

        vector<long long> distance(n, LLONG_MAX), ways(n, 0);

        min_heap.push({0, 0}); //distance, node
        ways[0] = 1; // 1 way to reach 0 is just go to 0

        while(!min_heap.empty()){
            auto [currDist, currNode] = min_heap.top(); min_heap.pop();

            for(auto neg: adj[currNode]){
                int negNode = neg.first;
                long long negW = neg.second;
                long long calDist = currDist + negW;
                if(calDist < distance[negNode]){
                    distance[negNode] = calDist;
                    min_heap.push({calDist, negNode});
                    ways[negNode] = ways[currNode];
                }
                else if(calDist == distance[negNode]){
                    ways[negNode] = (ways[negNode] + ways[currNode])%MOD;
                }

            }
        }

        return ways[n-1]%MOD;

    }
};