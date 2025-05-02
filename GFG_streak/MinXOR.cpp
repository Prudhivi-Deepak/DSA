//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minXOR(int n, int k, vector<int> &arr) {
        // code here
        // 0000000000 - 1
        // 1010101010 - 0
        // 1111111111 - 0

        xor - 0 0 = 0
              0 1 = 1
              1 1 = 0


            8421
        1 - 01
        2 - 10
        ------
            11

        3 - 11 - 0001
        ---------
            00 - 0
    -----------------          
        1
        1
        0
        ---------
        0 - 0
        ----------

        3 4 6 1 7 7 3



    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int k;
        scanf("%d", &k);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.minXOR(n, k, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends