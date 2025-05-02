#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int> bannedset(banned.begin(), banned.end());
        int sum = 0;
        int elements = 0;
        for(int i=1; i<=n; i++){
            if(!bannedset.count(i)){
                sum += i;
                elements++;
            }
            if(sum > maxSum){
                elements--;
                break;
            }
        }
        return elements;

        // unordered_map<int,int> umap;
        // for(int i : banned){
        //     umap[i] = 1;
        // }

        // int nums_count_taken = 0;
        // int sum = 0;

        // for(int i=1; i<= n; i++){
        //     if(umap[i]!=1){
        //         sum += i;
        //         nums_count_taken++;
        //     }

        //     if(sum > maxSum){
        //         nums_count_taken--;
        //         break;
        //     }
        // }
        // return nums_count_taken;



        // cout << "------------" << endl;
        // for(auto i : banned){
        //     cout << i << endl;
        // }
        // cout << " n : " << n << endl;
        // cout << "maxSum : " << maxSum << endl;
        // int nums_count_taken = 0;
        // int sum = 0;

        // sort(banned.begin(),banned.end());

        // int index_b = 0;
        // for(int i=1; i<= n; i++){
        //     cout <<  " i : " << i  << " banned : "<< index_b << ":" << banned[index_b]<<  " sum : " << sum << endl;
        //     if(i!=banned[index_b]){
        //         sum += i;
        //         nums_count_taken++;
        //         cout <<  "inside i : " << i <<  " sum : " << sum  << " nums_count_taken : " << nums_count_taken << endl;
        //     }
        //     else if(index_b < banned.size()-1){
        //         while(banned[index_b] == banned[index_b+1]){
        //             index_b++;
        //         }
        //         index_b++;
        //     }

        //     if(sum > maxSum){
        //         nums_count_taken--;
        //         break;
        //     }
        // }
        // return nums_count_taken;


        // cout << n << maxSum << endl;
        // int calculated_sum = 0;
        // int nums_in_range_count = 0;
        // int temp_n = n;
        // for(int i : banned){
        //     if(i < temp_n){
        //         nums_in_range_count +=1;
        //         calculated_sum += i;
        //     }
        // }
        // int formulated_sum = temp_n*(temp_n+1)/2 - calculated_sum;

        // while(formulated_sum > maxSum && temp_n > 0){
        //     temp_n--;
        //     formulated_sum = temp_n*(temp_n+1)/2 - (temp_n+1);
        // }

        // cout << formulated_sum << " | " << temp_n << endl;
        // cout << " ------------ " << endl;
        return 0;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, maxSum;
        cin >> n >> maxSum;
        cin.ignore();
        vector<int> banned;
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            banned.push_back(num);
        }
        Solution sol;
        cout << sol.maxCount(banned, n, maxSum) << endl;
    }
    return 0;
}