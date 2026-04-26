class Solution{
public:
    void dfs(int i, int p, vector<int> &visited, vector<int> &topo, int V, vector<int> adj[]){
        visited[i] = 1;

        for(auto neg: adj[i]){
            if(p!=neg){
                if(visited[neg]==0){
                    dfs(neg, i, visited, topo, V, adj);
                }
            }
        }

        topo.push_back(i);
    }

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


    vector<int> topoSort(int V, vector<int> adj[]){
        // vector<int> topo;
        // vector<int> visited(V, 0);
        // for(int i=0; i<V; i++){
        //     if(visited[i]==0){
        //         dfs(i, -1, visited, topo, V, adj);
        //     }
        // }
        // reverse(topo.begin(), topo.end());

        // for(auto j: topo){
        //     cout << j << " ";
        // }
        // cout << endl;
        // return topo;


        vector<int> indegree(V, 0);

        for(int edge=0; edge<V; edge++){
            for(int e: adj[edge]){
                indegree[e]++;
            }
        }

        vector<int> topo;

        bfs(indegree, topo, V, adj);

        return topo;
    }
};
d