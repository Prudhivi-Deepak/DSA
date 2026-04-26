class Solution{
public:
    bool DFS(int i, vector<int> &visited, vector<int> &path, int N, vector<int> adj[]){
        visited[i]=1;
        path[i]=1;

        for(auto neg: adj[i]){
            if(visited[neg]==0){
                if(DFS(neg, visited, path, N, adj)) return true;
            }
            else if(path[neg]==1){
                return true;
            }
        }
        path[i]=0;
        // topo.push_back(neg);
        return false;
    }

    bool BFS(vector<int> &indegree, int N, vector<int> adj[]){
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
        return topo.size()< N; //cycle exist (true) or not(false)
    }


    bool canFinish(int N, vector<vector<int>> arr) {

        vector<int> adj[N];
        vector<int> visited(N, 0);
        vector<int> path(N, 0);

        vector<int> indegree(N, 0);

        for(int e=0; e<arr.size(); e++){
            adj[arr[e][1]].push_back(arr[e][0]);
            // b->a;

            indegree[arr[e][0]]++;
        }

        

        return !BFS(indegree, N, adj);

        // for(int i=0; i<N; i++){
            // if(visited[i]==0){
                // if(DFS(i, visited, path, N, adj)) return false;

            // }
        // }

        // return true;
        
    }
};