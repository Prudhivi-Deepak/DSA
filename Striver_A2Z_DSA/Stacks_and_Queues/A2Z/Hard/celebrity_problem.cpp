#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        //  row knows col = 1 neans row(followee count++) follows(follower of) col (follower count++)
        // celebrity is known by everyone n-1 followers, 0 followee
        // possibly only one celebrity exist or 0
        // n people
        int n = M.size();

          // 0 1 2 3

        // 0 // 0 1 1 0
        // 1 // 0 0 0 0
        // 2 // 1 1 0 0
        // 3 // 0 1 1 0

        int top = 0, down = n-1;

        while(top < down){
            if(M[top][down]==1) top++;
            else if(M[down][top]==1) down--;
            else {
                top++; down--;
            }
        }
        // check all col -> 0 should not know anyone
        for(int i=0; i<n; i++){
            if(M[top][i]!=0) return -1;
        }

        // check every row except top - 1 he should be known by others
        for(int i=0; i<n; i++){
            if(i!=top && M[i][top]!=1) return -1;
        }

        return top;


        // vector<int> followers(n, 0), followee(n,0);

        // for(int j=0; j<n; j++){
        //     for(int i=0; i<n; i++){
        //         if(M[i][j]==1 && i!=j){
        //             followers[j]++;
        //             followee[i]++;
        //         }
        //     }
        // }
        // for(int j=0; j<n; j++)
        //     if(followers[j]==n-1 && followee[j]==0) return j;

        // return -1;
    }
};
// p1 p2
// 0  1  p1
// 1  0  p2

