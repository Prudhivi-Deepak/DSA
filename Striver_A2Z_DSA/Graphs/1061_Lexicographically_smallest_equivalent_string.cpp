#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/?envType=daily-question&envId=2025-06-05
class DisJointSet{

    public:
        vector<int> parent, rank;
        DisJointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1);
    
            for(int i=0; i<=n; i++){
                parent[i] = i; rank[i]=i;
            }
        }
    
        int findParent(int u){
            if(parent[u]==u){
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }
        
        void findUnionByLexicographically(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
    
            if(ulp_u==ulp_v) return;
    
            //we need lexicographically smaller element
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
            }
    
    
        }
    
    
        
    };
    class Solution {
    public:
    
        int BFS(vector<set<int>> adj, int num){
            queue<int> q;
            q.push(num);
            int currNum = num;
            int min_num = num;
            
            vector<int> visited(26,0);
    
            while(!q.empty()){
                currNum = q.front(); q.pop();
                // cout << currNum << endl;
                visited[currNum] = 1;
                if(currNum < min_num) min_num = currNum;
    
                for(int k : adj[currNum]){
                    // int k = *(adj[currNum].begin());
                    if(visited[k]==0){
                        q.push(k);
                        visited[k]=1;
                    }
                }
    
            }
            // cout << num << " : " << currNum << endl;
            return min_num;
    
        }
    
        string smallestEquivalentString1(string s1, string s2, string baseStr) {
            //create mappings (adj array)
            int n = s1.size();
            vector<set<int>> adj(26, set<int>{});
            for(int i=0; i<n; i++){
                // if((s1[i]-'a') > (s2[i]-'a')){
                    adj[s1[i]-'a'].insert(s2[i]-'a');
                    adj[s1[i]-'a'].insert(s1[i]-'a');
                // }
                // else if((s1[i]-'a') != (s2[i]-'a')){
                    adj[s2[i]-'a'].insert(s1[i]-'a');
                    adj[s2[i]-'a'].insert(s2[i]-'a');
                // }
            }
    
            // for(int k=0; k<26; k++){
            //     cout << k << char(k+'a') << " = ";
            //     for(int e: adj[k]){
            //         cout << e << char(e+'a') << ", ";
            //     }
            //     cout << endl;
            // }
    
            // for each word in baseStr 
            for(int i=0; i<baseStr.size(); i++){
                //find the lowest node connected in the same component
                baseStr[i] = char(BFS(adj, baseStr[i]-'a')+'a');
            }
            return baseStr;
        }
    
        string smallestEquivalentString(string s1, string s2, string baseStr) 
        {
            DisJointSet ds(26);
    
            int n = s1.size();
    
            for(int i=0; i<n; i++){
                ds.findUnionByLexicographically(s1[i]-'a', s2[i]-'a');
            }
    
            n = baseStr.size();
    
            for (int i = 0 ; i < n; i ++)
            {
                baseStr[i] = 'a'+ ds.findParent(baseStr[i] - 'a');
            }
    
            return baseStr;
    
        }
    
    
    };