class Solution {
public:
	void compareStrings(string &s1, string &s2, vector<int> adj[], vector<int> &indegree, int k){
		for(int i=0; i<min(s1.size(), s2.size()); i++){
			if(s1[i] != s2[i]){
				// s1[i] comes before s2[i] s1-->s2
				indegree[s2[i]-'a']++;
				adj[s1[i]-'a'].push_back(s2[i]-'a');break;

			}
		}
	}

	bool DFS(int i, vector<int> &visited, vector<int> &path, string &topo, int N, vector<int> adj[]){
        visited[i]=1;
        path[i]=1;

        for(auto neg: adj[i]){
            if(visited[neg]==0){
                if(DFS(neg, visited, path, topo, N, adj)) return true;
            }
            else if(path[neg]==1){
                return true;
            }
        }
        path[i]=0;
        // topo.push_back(i);
		topo += (i+'a');
        return false;
    }

    string BFS(vector<int> &indegree, int N, vector<int> adj[]){
        queue<int> q;
        // vector<int> topo;
        string topo;

        for(int i=0; i<N; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i = q.front(); q.pop();
            // topo.push_back(i);
            topo += (i+'a');

            for(auto neg: adj[i]){
                indegree[neg]--;
                if(indegree[neg]==0){
                    q.push(neg);
                }
            }
        }
        return topo.size() == N ? topo : ""; //cycle exist (true) or not(false)
    }

	string findOrder(string dict[], int N, int K) {
		vector<int> adj[K];

		vector<int> visited(K, 0);
        vector<int> path(K, 0);
        string topo;

		vector<int> indegree(K, 0);

		for(int i=0; i<N-1; i++){
			compareStrings(dict[i], dict[i+1], adj, indegree, K);
		}

		// now adj list is ready indegree

        

        return BFS(indegree, K, adj);

        // for(int i=0; i<K; i++){
        //     if(visited[i]==0){
        //         if(DFS(i, visited, path, topo, K, adj)) return "";
        //     }
        // }

        // reverse(topo.begin(), topo.end());

		// for(int i=0; i<topo.size(); i++){
		// 	cout << topo[i] << " ";
		// }
		// cout << endl;

        // return topo;

        // return true;

		



	}
};
