//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix) {
    // Your code goes here    
    for(int i=0; i<=matrix.size()-1; i++){
        for(int j=i+1; j<matrix[i].size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size()/2; j++){
            swap(matrix[i][j], matrix[i][matrix[i].size()-1-j]);
        }
    }

        // for(int i=0; i<matrix.size(); i++){
    //     for(int j=0; j<matrix[i].size(); j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
   
}


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends