#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countsetbits(int n) {
        int i=0, total_ones = 0;
        n=n+1;
        while(pow(2,i) <=n){
            cout << "i : " << i << endl;
            int fill = pow(2,i);
            cout << "fill : " << fill << endl;
            int odd_or_even = n/fill;
            cout << " odd or even : " << odd_or_even << endl;
            int grps = odd_or_even/2;
            cout << " grps : " << grps << endl;
            int ones = grps*fill;
            cout << " ones : " << ones << endl;
            int value = n%(fill);

            cout << "value : "<< value << endl;

            if(odd_or_even%2 == 1){
                ones += value;
            }
            total_ones += ones;
            cout << "i : " << i << " fil : " << fill << " ones : " << ones << " total_ones : " << total_ones << endl;
            i++;
            // break;
        }
        cout << "returning : " << total_ones << endl;
        return total_ones;
    }
};

int main(){
    Solution sol;
    int n;
    cin >>n;
    int out = sol.countsetbits(n);
    cout << " final total ones : " << out << endl;
    return 0;
}