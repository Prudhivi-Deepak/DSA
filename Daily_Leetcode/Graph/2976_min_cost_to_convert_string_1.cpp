
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // for index in source
            // if equal to index in target continue
            // else
                // we need to replace with minimum path
                // use recursion to take multiple paths and return the min cost
                // then use memo then dp
        
        // construct graph using a to b with weight c --> if multiple edges keep only smallest one
        // after graph created --> find shotest path from source diff char to target diff character
        // add all shortest path and return
        int V = 26;

        vector<vector<long long>> adjMatrix(V, vector<long long>(V, 1e9)); // to store all weight from node to node

        // cost of converting same letter is 0 --> no convertion actually--> -1 not reachable
        // for(int i=0; i<V; i++){
        //     adjMatrix[i][i] = 1e9;// but we are not updating this to 0/-1 because we apply floyed warshal algorithm later
        // }
        // iterate the original and changed arrays to get edges with cost as weight
        for(int i=0; i< original.size(); i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            long long w = cost[i];
            // cout << u << " " << v << " " << w << endl;
            if(u!=v){
                adjMatrix[u][v] = min(adjMatrix[u][v], w);
            }
        }

        // apply floyed warshall algo

        for(int k=0; k<V; k++){
            for(int i=0; i<V; i++){
                for(int j=0; j<V; j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k]+adjMatrix[k][j]);
                }
            }
        }

        // for(int i=0; i<V; i++){
        //     for(int j=0; j<V; j++){
        //         if(adjMatrix[i][j] == 1e9) adjMatrix[i][j] = -1;
        //     }
        // }

        long long totalCost = 0;
        for(int i=0; i< source.size(); i++){
            int u = source[i]-'a';
            int v = target[i]-'a';
            if(u!=v){
                if(adjMatrix[u][v] == 1e9) return -1;
                totalCost += adjMatrix[u][v];
            }
        }
        return totalCost;        
    }
};