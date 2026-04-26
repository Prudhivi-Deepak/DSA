class Solution{
public:
    bool dfs(int i, int p, vector<int> &visited, int V, vector<int> adj[]){
        visited[i] = 1;

        for(auto neg: adj[i]){
            if(p!=neg){
                if(visited[neg]==0){
                    if(dfs(neg, i, visited, V, adj)) return true;
                }
                else{
                    return true;
                }
            }
        }

        return false;
    }

    bool bfs(int sr, vector<int> &visited, int V, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({sr, -1}); visited[sr]=1;

        while(!q.empty()){
            auto [i, p] = q.front(); q.pop();

            for(int neg: adj[i]){
                if(neg!=p){
                    if(visited[neg]==0){
                        q.push({neg, i});
                        visited[neg] = 1;
                    }
                    else{
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++){
            if(visited[i]==0){
                // cout << i << endl;
                // if(dfs(i, -1, visited, V, adj)) return true;
                if(bfs(i, visited, V, adj)) return true;
            }
        }
        return false;
    }
};