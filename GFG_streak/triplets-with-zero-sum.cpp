//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        // cout << "==========" << endl;
        unordered_map<int, vector<vector<int>>> umap;
        vector<vector<int>> ans;
        vector<vector<int>> ans1;
        int diff;
        for(int i=0; i<arr.size()-1; i++){            
            for(int j=i+1; j<arr.size(); j++){                
                diff = arr[i] + arr[j];
                if(i!=j)       
                    umap[diff].push_back(vector<int>{{i, j}});
                // cout << "diff : " << diff << " ";
                // cout << i << j << endl;
            }
        }

        // cout << umap << endl;

        // for(pair<int, vector<vector<int>>> i : umap){
        //     cout << i.first << " : " ;
        //     for(vector<int> j : i.second){
        //         cout << j[0] << " " << j[1] << "\t";
        //     }
        //     cout << endl;
        // }

        for(int i=2; i<arr.size(); i++){
            diff = -arr[i];            
            for(auto j : umap[diff]){
                // cout << j[0] << j[1] << i << endl;
                if(i!=j[0] && i!=j[1]){
                    if(i < j[0]){
                        ans.push_back(vector<int>{{i, j[0], j[1]}});
                    }
                    else if(i > j[1]){
                        ans.push_back(vector<int>{{j[0], j[1], i}});
                    }
                    else{
                        ans.push_back(vector<int>{{j[0], i, j[1]}});
                    }
                }
            }
        }

        // cout << "----------" << endl;
        // for(auto j : ans){
        //     cout << j[0] << j[1] << j[2] << endl;
        // }

        int flag;
        for(int i=0; i<ans.size(); i++){
            flag = 0;
            for(int j=i+1; j<ans.size(); j++){
                // cout << i << j << " : " << ans[i][0] << ans[i][1] << ans[i][2]  << " : " <<  ans[j][0] << ans[j][1] << ans[j][2] << endl;
                if(ans[i][0] == ans[j][0] && ans[i][1] == ans[j][1] && ans[i][2] == ans[j][2] ){
                    flag = 1; 
                    break;
                }
            }

            if(flag == 0){
                ans1.push_back(vector<int>{{ans[i]}});
            }
        }
        return ans1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends