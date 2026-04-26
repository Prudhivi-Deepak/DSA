

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
vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){

        int IslandsCounter = 0;
        vector<int> Islands;
        vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<int>> visited(n, vector<int>(m, 0));

        DisJointSet djs(n*m);

        for(int i=0; i<A.size(); i++){

            int row = A[i][0];
            int col = A[i][1];
            int currNode = m*row+col;

            if(visited[row][col]){
                cout << row  << " : "<< col << endl;
                cout << IslandsCounter << endl;
                Islands.push_back(IslandsCounter);
                continue;
            }

            IslandsCounter++;
            visited[row][col] = 1;

            for(int j=0; j<4; j++){

                int negRow = row+dir[j][0];
                int negCol = col+dir[j][1];

                if(negRow>=0 && negCol>=0 && negRow<n && negCol<m && visited[negRow][negCol]==1){
                    auto negNode = m*negRow+negCol;
                    if(djs.findParent(currNode)!=djs.findParent(negNode)){
                        djs.unionBySize(currNode, negNode);
                        IslandsCounter--;
                    }
                }   
            }
            Islands.push_back(IslandsCounter);
        }
        return Islands;
    }
};