class Solution {
  public:

    void DFS(int i, vector<vector<int>> &adj, vector<int> &visited){
      visited[i] = 1;
      for(int neg: adj[i]){
        if(visited[neg]==0){
          DFS(neg, adj, visited);
        }
      }
    }
    
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {

      vector<vector<int>> adj(V, vector<int>{} );

      for(auto edge: edges){  
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }

      vector<int> visited(V, 0);
      int cnt = 0;

      for(int i=0; i<V; i++){
        if(visited[i]==0){
          DFS(i, adj, visited);
          cnt++;
        }
      }
  
      return cnt;
    }
};