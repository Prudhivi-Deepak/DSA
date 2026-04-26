class Solution {
  public:
    void DFS(int i, int V, vector<int> adj[], vector<int> &visited, vector<int> &ans){
      visited[i] = 1;
      ans.push_back(i);

      for(int neg: adj[i]){
        if(visited[neg]==0){
          DFS(neg, V, adj, visited, ans);
        }
      }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
      vector<int> visited(V, 0);
      vector<int> ans;

      for(int i=0; i<V; i++){
        if(visited[i]==0){
          DFS(i, V, adj, visited, ans);
        }
      }
      return ans;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> ans;
        vector<int> visited(V, 0);

        q.push(0); visited[0] = 1;

        while(!q.empty()){
          int currNode = q.front(); q.pop();
          ans.push_back(currNode);
          for(int neg: adj[currNode]){
            if(visited[neg]==0){
              q.push(neg); 
              visited[neg]=1;
            }
          }
        }
        return ans;
    }
};
