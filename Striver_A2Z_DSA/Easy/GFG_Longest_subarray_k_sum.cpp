//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=frf7qxiN2qU


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        // unordered_map<int, int> umap;
        // int currsum = 0, maxlen = 0;
        // for(int i=0; i<arr.size(); i++){
        //     currsum += arr[i];
        //     if(currsum == k){
        //         maxlen = max(maxlen, i+1);
        //     }
        //     if(umap.find(currsum-k)!=umap.end()){
        //         maxlen = max(maxlen, i-umap[currsum-k]);
        //     }
        //     if(umap.find(currsum) == umap.end()){
        //         umap[currsum] = i;   
        //     }
        // }
        // return maxlen;
        
        int left=0, right=0, currsum = 0, maxlen = 0;
        while(right<arr.size()){
            currsum += arr[right];
            
            while(left<=right && currsum > k){
                currsum -= arr[left++];
            }
            
            if(currsum == k){
                maxlen = max(maxlen, right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends