
class Solution {
public:
    int timer = 0;
    void dfs(int i, int parent, vector<int> &time, vector<int> &low, vector<vector<int>> &adj, vector<int> &visited, vector<vector<int>> &Bridges){
        visited[i] = 1;
        time[i] = low[i] = timer;timer++;

        for(int k : adj[i]){
            if(k==parent) continue;
            if(!visited[k]){
                dfs(k, i, time, low, adj, visited, Bridges);
                low[i] = min(low[i], low[k]);
                // chcek if it's bridge
                if(low[k] > time[i]){
                    Bridges.push_back({i,k});
                }
            }
            else{
                low[i] = min(low[i], low[k]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& E) {
        // do a dfs and assign start visiting time to node and 
        // traverse the adjacent nodes 
        // and after coming back from dfs get the min time from its adjacent node and
        // try to check if its the bridge or not

        // convert E to adj
        vector<vector<int>> adj(V, vector<int>{}), Bridges;

        for(int e=0; e<E.size(); e++){
            adj[E[e][0]].push_back(E[e][1]);
            adj[E[e][1]].push_back(E[e][0]);
        }

        vector<int> visited(V, 0), time(V,0), low(V,0);

        // for(int i=0; i<V; i++){
            // if(!visited[i]){
        dfs(0, -1, time, low, adj, visited, Bridges);
            // }
        // }

        return Bridges;

    }
};


