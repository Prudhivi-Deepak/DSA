//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool static customComparator(int a, int b){
        return a>b;
    }
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        
        // sorting make sure we get maximum k items quickly instead of iterating all elements in both arrays
        sort(A.begin(), A.end(), customComparator);
        sort(B.begin(), B.end(), customComparator);
        
        priority_queue< pair<int, pair<int,int> > > max_heap;
        int i=0, j=0;
        max_heap.push({A[i]+B[j], {i,j}});
        
        vector<int> ans;
        pair<int, pair<int, int>> curr;
        
        set<pair<int,int>> visited;
        
        while(K>0){
            curr = max_heap.top();
            max_heap.pop();
            ans.push_back(curr.first);
            
            i = curr.second.first;
            j = curr.second.second;
            
            // cout << i << j << endl;
            
            if(visited.find({i,j+1}) == visited.end()) {
                max_heap.push({A[i]+B[j+1], {i, j+1}});
                visited.insert({i,j+1});
            }
            if(visited.find({i+1,j}) == visited.end()) {
                max_heap.push({A[i+1]+B[j], {i+1, j}});
                visited.insert({i+1,j});
            }
            if(visited.find({i+1,j+1}) == visited.end()) {
                max_heap.push({A[i+1]+B[j+1], {i+1, j+1}});
                visited.insert({i+1,j+1});
            }
            
            K--;
        }
        
        return ans;
        
        // priority_queue<int> max_heap;
        // int sum;
        // for(int i=0; i<N; i++){
        //     for(int j=0; j<N; j++){
        //         sum = A[i]+B[j];
        //         max_heap.push(sum);
        //     }
        // }
        // vector<int> ans;
        // while(!max_heap.empty() && ans.size()<K){
        //     ans.push_back(max_heap.top());
        //     max_heap.pop();
        // }
        // return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends