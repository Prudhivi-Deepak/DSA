class Solution{
public:
    vector<int> BFS(vector<int> outdegree, int V, vector<int> adj1[]){
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<V; i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i = q.front(); q.pop();
            ans.push_back(i);

            for(auto neg: adj1[i]){
                outdegree[neg]--;
                if(outdegree[neg]==0){
                    q.push(neg);
                }
            }

        }

        sort(ans.begin(), ans.end());
        return ans;

    }

    bool DFS(int i, vector<int> &visited, vector<int> &path, vector<int> &check,int V, vector<int> adj[]){
        visited[i] = 1;
        path[i] = 1;
        check[i] = 0;

        for(auto neg: adj[i]){
            if(visited[neg]==0){
                if(DFS(neg, visited, path, check, V, adj)) return true;
            }
            else if(path[neg]==1){
                return true;
            }
        }

        path[i]=0;
        check[i] = 1;
        return false;

    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        // i have curr = 5
        // find which index uses 5 and decrement that outdegree count
        // or build an outdegree adj list

        // vector<int> adj1[V];
        // vector<int> outdegree(V, 0);

        // for(int e=0; e<V; e++){
        //     for(int k : adj[e]){
        //         // there is an edge from [i] to index
        //         adj1[k].push_back(e);
        //         outdegree[e]++;
        //     }
        // }

        // return BFS(outdegree, V, adj1);
        vector<int> visited(V, 0);
         vector<int> path(V, 0);
         vector<int> check(V, 0);


        for(int i=0; i<V; i++){
            if(visited[i]==0){
                DFS(i, visited, path, check, V, adj);
            }
        }

        vector<int> ans;

        for(int i=0; i<V; i++){
            if(path[i]==0){
                ans.push_back(i);
            }
        }

        return ans;

    }
};