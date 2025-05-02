//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> min_heap(arr.begin(), arr.end());
        int final_sum = 0, top1, top2, sum;
        
        while(min_heap.size()>1){
            top1 = min_heap.top();
            min_heap.pop();
            top2 = min_heap.top();
            min_heap.pop();
            
            sum = top1+top2;
            min_heap.push(sum);
            
            final_sum += sum;
        }
        
        return final_sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends