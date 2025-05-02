//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        int i=0, index=0, n = arr.size();
        
        while(i<n){
            if(min_heap.size()<k+1){
                min_heap.push(arr[i]);
                i++;
            }
            else{
                arr[index] = min_heap.top();
                index++;
                min_heap.pop();
                min_heap.push(arr[i]);
                i++;
            }
        }
        
        while(!min_heap.empty()){
            arr[index] = min_heap.top();
            min_heap.pop();
            index++;
        }
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
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends