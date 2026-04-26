

class DisJointSet{
public:
    vector<int> size, parent;
    DisJointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    bool isSameParent(int u, int v){
        return findParent(u) == findParent(v);
    }

    void unionBySize(int u, int v){
        int up = findParent(u);
        int vp = findParent(v);

        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }

};
class Solution{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts){
        int n = accounts.size();
        DisJointSet djs(n);
        unordered_map<string,int> accountsMap;

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(accountsMap.find(accounts[i][j]) != accountsMap.end()){
                    djs.unionBySize(i, accountsMap[accounts[i][j]]);
                }
                else{
                    accountsMap[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> modified_emails(n);

        for(auto kv : accountsMap){
            int mailid = kv.second;
            int index = djs.findParent(kv.second);
            modified_emails[index].push_back(kv.first);
        }
        // cout << endl;

        vector<vector<string>> finalAccounts;

        for(int i=0; i<n; i++){
            if(modified_emails[i].size()!=0){
                sort(modified_emails[i].begin(), modified_emails[i].end());
                vector<string> tempAcc;
                tempAcc.push_back(accounts[i][0]);
                tempAcc.insert(tempAcc.end(), modified_emails[i].begin(), modified_emails[i].end());
                finalAccounts.push_back(tempAcc);
            }
        }

        return finalAccounts;

    }
};