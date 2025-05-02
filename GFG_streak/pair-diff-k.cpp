//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        int count = 0;
        int something1, something2;
        unordered_map<int,int> umap;
        for(int i : arr){
            if(umap[i] == 0){
                umap[i] = 1;
            }
            else{
                umap[i]++;
            }
        }

        for(int i : arr){
            // something - i = k | something = k+i
            // i - something = k | something = i-k

            something1 = k+i;
            something2 = i-k;

            if(something1>=0 && umap[something1]>0){
                cout << "pair1 : " << something1 << " " << i << endl; 
                count += umap[something1];
            }
            if(something2>=0 && umap[something2]>0){
                cout << "pair2 : " << i << " "<< something2 << endl;
                count += umap[something2];
            }
        }

        // cout << count << endl;
        // cout << count/2 << endl;

        return count/2;

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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends