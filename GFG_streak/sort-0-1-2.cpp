//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int i = 0, f = 0, b = arr.size()-1;
        while(f <= b){
            if(arr[f] == 0){
                if(f==i){
                    i++;
                    f++;
                }
                else{
                    swap(arr[i++], arr[f]);
                }
            }
            else if(arr[f] == 1){
                f++;
            }
            else{
                swap(arr[f],arr[b--]);
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

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends