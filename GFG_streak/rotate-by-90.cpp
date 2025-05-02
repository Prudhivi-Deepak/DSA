//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here4
        int n = mat.size();
        for(int i=0; i<n-1; i++){
            for(int j=i; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int j=0; j<n; j++){
            for(int i=0; i<n/2; i++){
                swap(mat[i][j], mat[n-i-1][j]);
            }
        }

        // 590 507 38 612 287 749 239 183 252 928 821 839 
        // 520 267 62 1 738 187 671 810 648 79 228 345 
        // 187 533 101 912 315 859 923 660 382 446 636 24 
        // 393 497 300 940 413 872 396 220 607 880 525 830 
        // 573 942 437 903 405 137 762 297 67 456 830 492 
        // 315 503 823 479 731 383 65 764 285 42 206 88 
        // 188 173 747 750 288 641 400 443 501 367 999 331 
        // 849 130 920 598 436 920 126 839 883 914 647 120 
        // 774 295 116 851 759 294 214 741 524 848 656 289 
        // 657 990 532 158 821 948 346 876 882 985 728 367 
        // 151 955 85 918 375 474 308 862 133 704 533 301 
        // 787 959 309 299 843 765 173 802 840 949 631 745 

        // 1 4 7 
        // 2 5 8 
        // 3 6 9 
        // ~
        // 1 4 7 13 
        // 2 5 6 14 
        // 3 8 9 15 
        // 10 11 12 16 
        // ~
        // 10 
        // ~
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends