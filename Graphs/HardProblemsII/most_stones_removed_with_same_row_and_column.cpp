
class DisJointSet{
    public:
        vector<int> size, parent;
        DisJointSet(int n){
            size.resize(n+1, 1);
            parent.resize(n+1);

            for(int i=0; i<=n; i++) parent[i] = i;
        }


        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u] = findParent(parent[u]);
        }

        bool isSameParent(int u, int v){
            return findParent(u) == findParent(v);
        }

        void unionBySize(int u, int v){

            int ulp_u = findParent(u);
            int ulp_v = findParent(v);

            if(ulp_u ==ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }

};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        
        // row is a node and col is also a node

        int maxRow = -1, maxCol = -1;

        for(int i=0; i<stones.size(); i++){
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        DisJointSet djs(maxRow+maxCol+1);

        set<int> stoneNodes;

        for(auto stone: stones){
            int rowNode = stone[0], colNode = maxRow+1+stone[1];
            djs.unionBySize(rowNode, colNode);
            stoneNodes.insert(rowNode);
            stoneNodes.insert(colNode);
        }

        set<int> unique_parents;

        for(auto node: stoneNodes){
            unique_parents.insert(djs.findParent(node));
        }

        return n-unique_parents.size();        
    }
};