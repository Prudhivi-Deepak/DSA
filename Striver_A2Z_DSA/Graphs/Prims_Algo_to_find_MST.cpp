#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;

       q.push({0,0}); // wt, node, parent(optional not asked in qns)
       vector<int> visited(V+1, 0);
       int sum = 0;

       while(!q.empty()){
            auto currNode = q.top(); q.pop();
            if(visited[currNode.second]==1) continue;

            //priority queue will return the smallest edge wt 
            // add it to the sum and mark as visited
            sum += currNode.first;
            visited[currNode.second] = 1;
            // now traverse all the adjacent nodes and add htem to PQ to get the smallest edge in the next round
            for(auto k : adj[currNode.second]){
                if(visited[k[0]]==0){
                    q.push({k[1], k[0]});
                }
            }
       }
       return sum;
    }
};
