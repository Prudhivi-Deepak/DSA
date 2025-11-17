#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {

        int n = skill.size(), m = mana.size();

        vector<long long> time(n+1, 0);

        for(int j=0; j<m; j++){
            // cout << "for 1 : " << endl;
            // for(int i=0; i<n; i++){
            //     cout << (long long) skill[i]*mana[j] << " ";
            // }
            // cout << endl;
            // cout << time[0] << " ";
            for(int i=0; i<n; i++){
                time[i+1] = max(time[i], time[i+1])+(long long) skill[i]*mana[j];
                // cout << time[i+1] << " ";
            }
            // cout << endl;
            // cout << "for 2 : " << endl;
            for(int i=n-1; i>0; i--){
                time[i] = time[i+1] - (long long) skill[i]*mana[j]; 
            }
            // for(int i=0; i<=n; i++){
            //     cout << time[i] << " ";
            // }
            // cout << endl;
            // cout << endl;
        }
        return time[n];
    }
};