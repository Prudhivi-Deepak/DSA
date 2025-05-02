#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {

        int count_L = 0, count_R =0, n = start.size(), i=0, j=0;
        while(i < n){
            if(start[i]=='L'){
                count_L++;
            }
            if(start[i]=='R'){
                count_R++;
            }

            if(target[i]=='L'){
                count_L--;
            }
            if(target[i]=='R'){
                count_R--;
            }

            if(start[i]!='_'){
                while(j < n && target[j] == '_'){
                    j++;
                }
                if(start[i] != target[j] || (start[i] == 'R' && i > j) || (start[i] == 'L' && i < j)){
                    return false;
                }
                j++;
            }
            i++;
        }

        if(count_L == 0 && count_R == 0){
            return true;
        }
        return false;

        // if(start.size() != target.size()){
        //     return false;
        // }

        // for(auto i : start){
        //     if(i == 'L'){
        //         count_L++;
        //     }
        //     if(i == 'R'){
        //         count_R++;
        //     }
        // }

        // for(auto i : target){
        //     if(i == 'L'){
        //         count_L--;
        //     }
        //     if(i == 'R'){
        //         count_R--;
        //     }
        // }

        // int index = 0;
        // if(count_L == 0 && count_R == 0){
        // int count_L = 0, count_R =0;
        // while(count_L < start.size() || count_R < target.size()){
        //     while(start[count_L]=='_'){
        //         count_L++;
        //     }
        //     while(target[count_R]=='_'){
        //         count_R++;
        //     }

        //     if(start[count_L] != target[count_R] || (start[count_L] == 'R' && count_L > count_R) || (start[count_L] == 'L' && count_L < count_R)){
        //         return false;
        //     }
        //     else{
        //         count_L++;
        //         count_R++;
        //     }
        // }
        // return true;
        // }
        // else{
        //     return false;
        // }
        // return true;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string start, target;
        cin >> start >> target;
        Solution sol;
        if (sol.canChange(start, target)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}