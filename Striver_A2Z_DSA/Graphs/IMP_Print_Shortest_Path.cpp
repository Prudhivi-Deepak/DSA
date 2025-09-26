#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    
            vector<vector<vector<int>>> adj(n+1,vector<vector<int>> {}); // e1 : (e2, w), e1 : (e2, w)
            for(int e=0; e<edges.size(); e++){
                adj[edges[e][0]].push_back(vector<int>{edges[e][1], edges[e][2]});
                adj[edges[e][1]].push_back(vector<int>{edges[e][0], edges[e][2]});
            }
    
            // for(auto k : adj){
            //     for(auto kk : k){
            //         cout << kk[0] << " : " << kk[1] <<  " ";
            //     }
            //     cout << endl;
            // }
    
            //  [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
    
            //  [[], [[2,2],[4,1]], []]
    
            set<pair<int, int>> st;
            st.insert({0, 1});
            vector<int> dist(n+1, 1e9), parent(n+1);
            for (int i = 1; i <= n; i++)
                parent[i] = i;
            dist[1]=0;
    
            while(!st.empty()){
                auto [d, currNode] = *(st.begin()); st.erase(st.begin());
                // cout << currNode << " n & d = " << d << endl;
                // cout << adj[currNode][0][0] << endl;
    
                for(auto k : adj[currNode]){
                    int node = k[0];
                    int w = k[1];
                    // cout << "node : " << node << endl;
                    int cal_dist = w+d;
                    if(cal_dist < dist[node]){
                        if(dist[node]!=1e9)
                            st.erase({dist[node], node});
    
                        dist[node] = cal_dist;
                        parent[node] = currNode;
                        // cout << "parent of " << node << " is " << currNode << endl;
                        st.insert({dist[node], node});
                    }
                }
            }
            // cout << endl;
            // for(int k : dist){
            //     cout << k << " ";
            // }
            // cout << endl;
            // for(int k : parent){
            //     cout << k << "- ";
            // }
            // cout << endl;
    
            if(dist[n]==1e9) return {-1};
    
            int node = n;
            vector<int> path;
            // path.push_back(node);
            while(parent[node]!=node){
                // cout << parent[node] << " ";
                path.push_back(node);
                node = parent[node];
                // cout << path.back() << endl;
            }
            path.push_back(1);
    
            path.push_back(dist[n]);
    
            // if(path.empty()) return vector<int>(n, -1);
            
            reverse(path.begin(), path.end());
    
            return path;
    
        }
    };