
class DisJointSet{
public:
    vector<int> size, parent;
    DisJointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    bool isSameParent(int u, int v){
        return findParent(u) == findParent(v);
    }

    void unionBySize(int u, int v){
        int up = findParent(u);
        int vp = findParent(v);

        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }

};

class Solution{
public:
    int solve(int n, vector<vector<int>> &Edge){

        DisJointSet djs(n);
        int extraEdge = 0;

        for(auto edge: Edge){
            int u = edge[0], v = edge[1];
            if(djs.isSameParent(u, v)) extraEdge++;
            else{
                djs.unionBySize(u,v);
            }
        }

        int totalComponents = 0;
        for(int i=0; i<n; i++){
            if(djs.findParent(i)==i) totalComponents++;
        }

        if(extraEdge >= totalComponents-1) return totalComponents-1;
        return -1;
    }
};
