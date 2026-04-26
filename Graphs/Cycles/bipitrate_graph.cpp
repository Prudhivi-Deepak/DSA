class Solution{
public:
    bool dfs(int i, int p, vector<int> &visited, vector<int> &code, int color,  int V, vector<int> adj[]){
        visited[i] = 1;

        for(auto neg: adj[i]){
            if(p!=neg){
                if(visited[neg]==0){
                    code[neg] = color;
                    if(!dfs(neg, i, visited, code, !color, V, adj)) return false;
                }
                else if(code[neg]!=-1 && code[neg]!=color){
                    return false;
                }
                
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])  {
        vector<int> visited(V, 0);
        vector<int> code(V, -1);
        for(int i=0; i<V; i++){
            if(visited[i]==0){
                // cout << i << endl;
                // int i=0;
                code[i] = 0;
                if(!dfs(i, -1, visited, code, 1, V, adj)) return false;
                // if(bfs(i, visited, V, adj)) return true;
            }
        }
        return true;
    }
};
