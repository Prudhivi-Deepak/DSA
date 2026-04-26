class Solution {
  public:
    

    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
      vector<int> distance(N, 1e9);

      vector<vector<int>> adj(N);

      for(auto edge: edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }

      queue<int> q;

      q.push(0);
      distance[0] = 0;

      while(!q.empty()){
        int i = q.front(); q.pop();

        for(auto neg: adj[i]){
          if(distance[neg] > distance[i]+1){
            distance[neg] = distance[i]+1;
            q.push(neg);
          }
        }
      }

      for(int i=0; i<N; i++){
        if(distance[i]==1e9) distance[i]=-1;
      }

      return distance;
    }
};
