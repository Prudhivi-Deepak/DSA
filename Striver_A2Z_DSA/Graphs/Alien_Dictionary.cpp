#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> BFS_Topo(int V, vector<vector<int>> adj){
        //find inDegree
        vector<int> indegree(V,0);

        for(int i=0; i<V; i++){
            for(int k : adj[i]){
                indegree[k]++;
            }
        }

        //push 0 indegree
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> Topo;

        while(!q.empty()){
            int currnode = q.front(); q.pop();
            Topo.push_back(currnode);

            for(int k : adj[currnode]){
                indegree[k]--;
                if(indegree[k]==0) q.push(k);
            }
        }
        return Topo;
    }

	string findOrder(string dict[], int N, int K) {
		vector<vector<int>> adj(K, vector<int>{});

        //make adj list - compare string by string and find it
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int j=0; j<len; j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');break;
                }
            }
        }

        vector<int> Topo = BFS_Topo(K, adj);

        string topo_string = "";
        for(int i=0; i<Topo.size(); i++){
            topo_string += char(Topo[i]+'a');
        }
        // cout << topo_string << endl;
        return topo_string;
	}
};
