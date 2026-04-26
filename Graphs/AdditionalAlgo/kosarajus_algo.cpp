class Solution{
public:
    void dfs(int i, vector<int> adj[], stack<int> &st, vector<int> &visited){
        visited[i]=1;
        for(int k : adj[i]){
            if(!visited[k]){
                dfs(k, adj, st, visited);
            }
        }
        st.push(i);
    }
    void dfs2(int i, vector<int> adjT[], vector<int> &visited){
        visited[i]=1;
        for(int k : adjT[i]){
            if(!visited[k]){
                dfs2(k, adjT, visited);
            }
        }
    }
    int kosaraju(int V, vector<int> adj[]){
        //step 1 : da a dfs and store the nodes according to their finishing time in stack
        stack<int> st;
        vector<int> visited(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, adj, st, visited);
            }
        }

        // step 2 : reverse the edges - create a transpose graph adj 
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            visited[i]=0;
            for(int k : adj[i]){
                adjT[k].push_back(i);
            }
        }

        // step 3 : da a dfs again and count scc
        int scc = 0;
        while(!st.empty()){
            int node = st.top();st.pop();
            if(!visited[node]){
                scc++;
                dfs2(node, adjT, visited);
            }
        }
        return scc;
    }
};
