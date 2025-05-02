//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// 4
// 5
// 6
// 1 2 3 4 5 6
// 7 8 9 10 11 12
// 13 14 15 16 17 18
// 19 20 21 22 23 24
// 25 26 27 28 29 30
// 4
// 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// 3
// 6
// 1 2 3 4 5 6
// 7 8 9 10 11 12
// 13 14 15 16 17 18
// 2
// 4
// 32 44 27 23
// 54 28 50 62

// } Driver Code Ends
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here

        vector<int> ans;

        int n = mat.size();
        int m = mat[0].size();
        int i = 0, j = 0, round = 1, round_i = 1, round_j = 1, prev_i = n-1, prev_j = m-1;
        while (round < 10){
            cout << "--------------" << endl;
            cout << "round : " << round << endl;
            cout << "b i : " << i << " j : " << j << endl;
            
            // odd trverse j
            // even traverse i
            if (round % 2 == 0)
            {
                cout << "round_i : " << round_i << endl;
                if(round_i%2 == 0){
                    while (mat[i][j] > 0 && (i-1)>0 && (i+1)<n ){
                        cout << mat[i][j] << " i " << i <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];
                        if(mat[i-1][j] > 0){
                            i--;
                        }
                        // i--;
                    }

                    if(mat[i][j] > 0){
                        cout << mat[i][j] << " i " << i <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];
                    }
                    j++;

                }
                else{
                    while (mat[i][j] > 0 && i>=0 && (i+1)<n){
                        cout << mat[i][j] << " i " << i <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];
                        if(mat[i+1][j] > 0){
                            i++;
                        }
                        // i++;
                    }
                    if(mat[i][j] > 0){
                        cout << mat[i][j] << " i " << i <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];
                    }
                    j--;
                }

                // if(i==n){
                //     i--;
                // }
                // if(i<0){
                //     i=0;
                // }

                round_i++;
            }
            else{//traverse j
                // odd increse
                // even decrease
                cout << "round_j : " << round_j << endl;
                if(round_j%2 == 0){
                    while (mat[i][j] > 0 && j>0 ){
                        cout << mat[i][j] << " j " << j <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];
                        if(mat[i][j-1] > 0){
                            j--;
                        }
                        // j--;
                    }
                    if(mat[i][j] > 0){
                        cout << mat[i][j] << " j " << j <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];
                    }
                    i--;
                }
                else{
                    while (mat[i][j] > 0 && (j+1)<m ){
                        cout << mat[i][j] << " j " << j <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];

                        if(mat[i][j+1] > 0){
                            j++;
                        }
                        // cout << " i j " << mat[i][j] << endl;
                    }
                    if(mat[i][j] > 0){
                        cout << mat[i][j] << " j " << j <<  " " << endl;
                        ans.push_back(mat[i][j]);
                        mat[i][j] = -mat[i][j];
                    }
                    i++;
                }

                // if(j==m){
                //     j--;
                // }
                // if(j<0){
                //     j=0;
                // }

                round_j++;
            }
            round++;
            cout << "A i : " << i << " j : " << j << endl;
            cout << " | "<< endl;
        }
        cout << "end" << endl;
        return ans;

        // 1 2 3 4
        // 5 6 7 8
        // 9 10 11 12
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends