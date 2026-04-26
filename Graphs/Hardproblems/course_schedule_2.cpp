class Solution {
   public:
    bool DFS(int i, vector<int> &visited, vector<int> &path, vector<int> &topo, int N, vector<int> adj[]){
        visited[i]=1;
        path[i]=1;

        for(auto neg: adj[i]){
            if(visited[neg]==0){
                if(DFS(neg, visited, path, topo, N, adj)) return true;
            }
            else if(path[neg]==1){
                return true;
            }
        }
        path[i]=0;
        topo.push_back(i);
        return false;
    }

    vector<int> BFS(vector<int> &indegree, int N, vector<int> adj[]){
        queue<int> q;
        vector<int> topo;

        for(int i=0; i<N; i++){
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
        return topo.size() == N ? topo : vector<int>{}; //cycle exist (true) or not(false)
    }
    
    vector<int> findOrder(int N, vector<vector<int>> arr) {
        vector<int> adj[N];
        vector<int> visited(N, 0);
        vector<int> path(N, 0);
        vector<int> topo;

        vector<int> indegree(N, 0);

        for(int e=0; e<arr.size(); e++){
            adj[arr[e][1]].push_back(arr[e][0]);
            // b->a;

            // indegree[arr[e][0]]++;
        }

        

        // return BFS(indegree, N, adj);

        for(int i=0; i<N; i++){
            if(visited[i]==0){
                if(DFS(i, visited, path, topo, N, adj)) return vector<int>{};
            }
        }

        reverse(topo.begin(), topo.end());

        return topo;

        // return true;

    }
};
