struct compare{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        return p1.first > p2.first;
    }
};

class Solution{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> distance(n+1, 1e9);
        vector<int> parentPath(n+1);

        for(int i=0; i<=n; i++){
            parentPath[i]= i;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> minHeap;
        minHeap.push({0, 1}); distance[1] = 0;

        while(!minHeap.empty()){
            auto [currDist, currNode] = minHeap.top(); minHeap.pop();

            // if(currNode == m) return 

            for(auto neg: adj[currNode]){
                int negNode =  neg.first;
                int negW = neg.second;
                int calDist = currDist + negW;

                // cout << calDist << endl;
                
                if(calDist < distance[negNode]){
                    distance[negNode] = calDist;
                    minHeap.push({calDist, negNode});
                    parentPath[negNode] = currNode;
                }
            }
        }

        if(distance[n]==1e9) return {-1};

        vector<int> ans;
        int index = n;
        while(parentPath[index] != index){
            ans.push_back(index);
            index = parentPath[index];
        }
        ans.push_back(index);
        ans.push_back(distance[n]);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};