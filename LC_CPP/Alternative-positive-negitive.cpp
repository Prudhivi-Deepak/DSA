//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int i = 0;
        int j = 0;
        int index = 0;

        while(i<arr.size() && j<arr.size()){
            cout << arr[i] << arr[j] << endl;
            if(arr[i] < 0 ){
                i++;                
            }
            else if(arr[j] >= 0){
                j++;
            }
            else if(arr[i] >=0 && arr[j] < 0){
                cout << "swaped" << endl;
                swap(arr[i++], arr[index++]);
                swap(arr[j++], arr[index++]);
                for(auto i:arr){
                    cout << i << " ";
                }
                cout << endl;
            }
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends