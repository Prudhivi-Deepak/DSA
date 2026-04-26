class Solution{
public:

    void bfs(vector<int> &indegree, vector<int> &topo, int V, vector<int> adj[]){

        queue<int> q;

        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i = q.front(); q.pop();
            topo.push_back(i);

            for(auto neg: adj[i]){
                indegree[neg]--;
                if(indegree[neg]==0){
                    q.push(neg);
                }
            }
        }

    }

    bool dfs(int i, vector<int> &visited, vector<int> &path, int V, vector<int> adj[]){
        visited[i] = 1;
        path[i] = 1;

        for(auto neg: adj[i]){
            // if(neg!=p){
            if(visited[neg]==0){
                if(dfs(neg, visited, path, V, adj)) return true;
            }
            else if(path[neg]==1){
                return true;
            }
            // }
        }
        path[i]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {

        vector<int> visited(V, 0);
        vector<int> path(V, 0);

        for(int i=0; i<V; i++){
            if(visited[i]==0){
                if(dfs(i, visited, path, V, adj)) return true;
            }
            else if(path[i]==1){
                return true;
            }
        }

        return false;

        // vector<int> indegree(V, 0);
        // for(int edge=0; edge<V; edge++){
        //     for(int e: adj[edge]){
        //         indegree[e]++;
        //     }
        // }

        // vector<int> topo;
        // bfs(indegree, topo, V, adj);
        // return topo.size()<V;
   
    }
};
