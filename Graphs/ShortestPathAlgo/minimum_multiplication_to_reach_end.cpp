class Solution{
int MOD = 1e5;
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {

        vector<int> visited(1e5, 0);

        queue<pair<int,int>> q;

        q.push({0, start});visited[start] = 0;

        while(!q.empty()){
            auto [steps, node] = q.front(); q.pop();

            if(node == end) return steps;

            for(auto neg: arr){
                int nextNode = (node*neg)%MOD;
                if(visited[nextNode]==0){
                    visited[nextNode] = 1;
                    q.push({steps+1, nextNode});
                }
            }
        }
        return -1;
    }
};
