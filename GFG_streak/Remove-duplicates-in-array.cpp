//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_map<int, int> umap;
        int index = 0;
        for(int i : arr){
            if(umap[i] == 0){
                arr[index] = i;
                umap[arr[index]]++;
                index++;
            }            
        }

        while(arr.size()>index){
            arr.pop_back();
        }

        return arr;








        
        // cout << umap[0] << endl;
        // for(<int,int> i : umap){
        //     cout << i.first << i.second << endl;
        // }

        // for(auto i = arr.begin(); i<arr.end(); i++){
        //     if(arr[i] == 0)
        // }        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends