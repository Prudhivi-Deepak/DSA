class Solution {
public:
    int timer = 0;
    void dfs(int i, int parent, vector<int> &time, vector<int> &low, vector<int> adj[], vector<int> &visited, vector<int> &mark){
        visited[i] = 1;
        time[i] = low[i] = timer;timer++;
        int child = 0;
        for(int k : adj[i]){
            if(k==parent) continue;
            if(!visited[k]){
                dfs(k, i, time, low, adj, visited, mark);
                low[i] = min(low[i], low[k]);
                // chcek if it's bridge/ articulation point
                if(low[k] >= time[i] && parent!=-1){
                    // Bridges.push_back({i,k});
                    mark[i]=1; // i is AP
                }
                child++;
            }
            else{
                low[i] = min(low[i], time[k]);
            }
        }
        if(parent==-1 && child>1) mark[i]=1;
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // vector<vector<int>> adj(V, vector<int>{});

        // for(int e=0; e<E.size(); e++){
        //     adj[E[e][0]].push_back(E[e][1]);
        //     adj[E[e][1]].push_back(E[e][0]);
        // }
        int V = n;
        vector<int> visited(V, 0), time(V,0), low(V,0), mark(V,0);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, -1, time, low, adj, visited, mark);
            }
        }

        vector<int> AP;
        for(int i=0; i<n; i++){
            if(mark[i]==1) AP.push_back(i);
        }

        if(AP.empty()) return {-1};

        return AP;
    }
};