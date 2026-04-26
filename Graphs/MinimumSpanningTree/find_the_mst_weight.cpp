
class DisJointSet{
    public:
        vector<int> parent, size, rank;

        DisJointSet(int n){
            size.resize(n, 1);
            rank.resize(n, 0);
            parent.resize(n);
            for(int i=0; i<n; i++) parent[i] = i;
        }

        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u] = findParent(parent[u]);
        }

        bool sameParent(int u, int v){
            return findParent(u) == findParent(v);
        }

        void unionByRank(int u, int v){
            int ultimateParent_u = findParent(u);
            int ultimateParent_v = findParent(v);

            if(ultimateParent_u == ultimateParent_v) return;

            if(rank[ultimateParent_u] < rank[ultimateParent_v]){
                parent[ultimateParent_u] = ultimateParent_v;
            }
            else{
                parent[ultimateParent_v] = ultimateParent_u;
                if(rank[ultimateParent_u] == rank[ultimateParent_v]) rank[ultimateParent_u]++;
            }

        }

        bool unionBySize(int u, int v){
            int ultimateParent_u = findParent(u);
            int ultimateParent_v = findParent(v);

            if(ultimateParent_u == ultimateParent_v) return false;

            if(size[ultimateParent_u] < size[ultimateParent_v]){
                parent[ultimateParent_u] = ultimateParent_v;
                size[ultimateParent_v]+=size[ultimateParent_u];
            }
            else{
                parent[ultimateParent_v] = ultimateParent_u;
                size[ultimateParent_u]+=size[ultimateParent_v];
            }
            return true;
        }
};

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> visited(V, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> min_heap;

        min_heap.push({0, 0}); //et, node
        int sum = 0;

        while(!min_heap.empty()){
            auto [wt, node] = min_heap.top(); min_heap.pop();
            // cout << node << " : " << wt << endl;

            if(visited[node]==1) continue;

            sum += wt;
            visited[node] = 1;

            for(auto neg: adj[node]){
                if(!visited[neg[0]]){
                    min_heap.push({neg[1], neg[0]});
                }
            }
        }
        return sum;
    }
    int spanningTreeUsingDJS(int V, vector<vector<int>> adj[]) {
       DisJointSet djs(V);

       vector<pair<int, pair<int,int> > > edges; // wt, u, V

       for(int i=0; i<V; i++){
        for(auto edge: adj[i]){
            int u = i;
            int v = edge[0];
            int wt = edge[1];
            if(u<v){
                edges.push_back({wt, {u,v}});
                // cout << wt << u << v << endl;
            }
        }
       }

       sort(edges.begin(), edges.end());

       int sum = 0, edgesCount = 0;

       for(int i=0; i<edges.size(); i++){
        auto [wt, nodes] = edges[i];
        int u = nodes.first, v = nodes.second;

        if(!djs.sameParent(u,v)){
        // if(djs.unionBySize(u,v)){
            // if(edgesCount==V-1) break;
            // cout << u << " : " << v << endl;
        // if(djs.findParent(u)!=djs.findParent(v)){
            djs.unionBySize(u,v);
            sum += wt;
            // edgesCount++;
        }        
       }

       return sum;
    }
};
