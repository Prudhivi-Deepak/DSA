//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code        
        int front, back, calculatedSum;
        sort(arr.begin(), arr.end());
        for(int i=arr.size()-1; i>=2;i--){
            front = 0;
            back = i-1;
            while(front<back){
                calculatedSum = arr[front] + arr[back];
                if(calculatedSum == arr[i]){
                    return true;
                }
                else if(calculatedSum < arr[i]){
                    front++;
                }
                else if(calculatedSum > arr[i]){
                    back--;
                }
            }            
        }
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends