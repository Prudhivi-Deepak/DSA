#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
    public: 
        vector<int> parent, size;
        DisJointSet(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++) parent[i] = i;
        }
    
        int findParent(int u){
            if(parent[u]==u) return u;
            return parent[u] = findParent(parent[u]);
        }
    
        void unionBySize(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
    
            if(ulp_u == ulp_v) return;
    
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    
    };
    
    class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            int n = accounts.size();
            DisJointSet djs(n);
            unordered_map<string, int> emailsMap;
            for(int i=0; i<n; i++){
                for(int mailid=1; mailid<accounts[i].size(); mailid++){
                    if(emailsMap.find(accounts[i][mailid])==emailsMap.end()){
                        emailsMap[accounts[i][mailid]] = i;
                    }
                    else{
                        //already in the map so merge the current index with the one in the map
                        djs.unionBySize(i, emailsMap[accounts[i][mailid]]);
                    }
                }
            }
    
            // Now Iterate though all index and get ultimate parent and assign the mails to that index
            // Iterating through map fits better
    
            vector<vector<string>> modified_emails(n, vector<string>{});
            // for(int i=0; i<n; i++){
            //     for(int mailid=1; mailid<accounts[i].size(); mailid++){
            //         int index = djs.findParent(emailsMap[accounts[i][mailid]]);
            //         modified_emails[index].push_back(accounts[i][mailid]);
            //     }
            // }
    
            for(auto kv : emailsMap){
                int mailid = kv.second;
                int index = djs.findParent(kv.second);
                modified_emails[index].push_back(kv.first);
            }
    
            // now add name and sort the emails and return
            vector<vector<string>> modified_accounts;
            for(int i=0; i<n; i++){
                if(modified_emails[i].empty()) continue;
                vector<string> temp_account;
                temp_account.push_back(accounts[i][0]);
                sort(modified_emails[i].begin(), modified_emails[i].end());
                temp_account.insert(temp_account.end(), modified_emails[i].begin(), modified_emails[i].end());
                modified_accounts.push_back(temp_account);
            }
            return modified_accounts;
        }
    };