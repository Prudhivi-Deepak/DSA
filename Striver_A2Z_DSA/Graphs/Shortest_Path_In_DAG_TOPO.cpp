#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:

    void TopoSort(int i, vector<int> &visited, vector<vector<pair<int,int>>> &adj, stack<int> &st){
        visited[i] = 1;

        for(pair<int,int> k : adj[i]){
            int node = k.first;
            int weight = k.second;
            if(visited[node]==0){
                TopoSort(node, visited, adj, st);
            }
        }
        st.push(i);
    }


    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        //create adj list; e1 - {(e2, w)}
        // N - Vertex, M-edges

        vector<vector<pair<int,int>>> adj(N, vector<pair<int,int>>{});

        for(int e=0; e<edges.size(); e++){
            int u = edges[e][0];
            int v = edges[e][1];
            int w = edges[e][2];
            adj[u].push_back({v,w});
        }

        //Now call dfs for topoSort in directed graph (insert children into stack first)
        vector<int> visited(N, 0);
        stack<int> st;
        for(int i=0; i<N; i++){
            if(visited[i]==0)
                TopoSort(i, visited, adj, st);
        }

        //now relax the edges by compareing the distances
        vector<int> dist(N, 1e9);
        // cout << st.top() << endl
        dist[0]=0; //src node;

        while(!st.empty()){
            int node = st.top(); st.pop();
            //compare weight for all adjacent weights
            for(pair<int,int> k : adj[node]){
                int n = k.first;
                int w = k.second;
                if(dist[node]+w < dist[n]){
                    dist[n] =dist[node]+w;
                }
            }
        }

        for(int i=0; i<N; i++){
            if(dist[i]==1e9) dist[i]=-1;
        }

        return dist;
    }
};

