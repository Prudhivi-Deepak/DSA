class Solution{
public:
    void dfs(int i, vector<vector<int>> adj, vector<int> &visited){
        visited[i] = 1;

        for(int neg=0; neg<adj[i].size(); neg++){
            if(visited[neg]==0 && adj[i][neg]){
                dfs(neg, adj, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj) {
       int cnt = 0, v = adj.size();
       vector<int> visited(v, 0);
       for(int i=0; i<v; i++){
        if(visited[i]==0) {
            dfs(i, adj, visited);
            cnt++;
        }
       }
       return cnt;
    }
};
