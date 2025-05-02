
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i=0;i<arr.size();i++){
             if(m[2*arr[i]] == 1 || (arr[i]%2==0 && m[arr[i]/2]==1)){
                    return true;
            }
            else{
                m[arr[i]] = 1;
            }
        }
        return false;
    }
};