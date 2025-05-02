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
    int isPossible(int n, vector<int> &arr) {
        // code here
        // 5 2 = 1 zero
        // 10 = 1 zero
        //     [p1, p2]
        // 1000
        // i=0 2, 500
        // i=1 10,100
        // i=2 10,100

        int total_product = 1;
        int left_product = 1;
        int right_product = 1;

        for(int i : arr){
            total_product *=i;
        }

        for(int i : arr){
            left_product *= i;
            right_product = total_product/ left_product;
        }

        int left_count = 0;
        int right_count = 0;

        while(left_product%10 == ){
            left_product = left_product%10;

        }


        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.isPossible(n, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends