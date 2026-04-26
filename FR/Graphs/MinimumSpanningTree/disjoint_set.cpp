class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        // vector<int> rank(n+1, 0);
        // vector<int> parent(n+1, 0);
        // for(int i=0; i<=n; i++) parent[i]=i;

        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    bool find(int u, int v) {
        // if parent of both u and v are equal or not
        return findParent(u) == findParent(v);
    }

    void unionByRank(int u, int v) {

        int u_ultimateParent = findParent(u);
        int v_ultimateParent = findParent(v);

        // if parents are same no need to merge
        if(u_ultimateParent == v_ultimateParent) return;

        // rank of ultimate parent of u <  rank of ultimate parent of v 
        if(rank[u_ultimateParent] < rank[v_ultimateParent]){
            parent[u_ultimateParent] = v_ultimateParent;
        }
        else{
            parent[v_ultimateParent] = u_ultimateParent;
            if(rank[v_ultimateParent]  == rank[u_ultimateParent]) rank[u_ultimateParent]++;
        }

        // cout << "rank : ";

        // for(int i=0; i<rank.size(); i++){
        //     cout << rank[i] << " ";
        // }
        // cout << endl;
    }

    void unionBySize(int u, int v) {
        int u_ultimateParent = findParent(u);
        int v_ultimateParent = findParent(v);

        // if parents are same no need to merge
        if(u_ultimateParent == v_ultimateParent) return;

        // rank of ultimate parent of u <  rank of ultimate parent of v 
        if(size[u_ultimateParent] < size[v_ultimateParent]){
            parent[u_ultimateParent] = v_ultimateParent; 
            size[v_ultimateParent] += size[u_ultimateParent] ;
        }
        else{
            parent[v_ultimateParent] = u_ultimateParent;
            size[u_ultimateParent] += size[v_ultimateParent];
        }

        // cout << "size : ";

        // for(int i=0; i<size.size(); i++){
        //     cout << size[i] << " ";
        // }
        // cout << endl;

       
    }
};
