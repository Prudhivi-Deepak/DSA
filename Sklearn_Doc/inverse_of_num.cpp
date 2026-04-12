
#include<bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

int inverse(int x){
    // return quickMul(x, mod-2);
    int result = 1, curr = x, y = mod-2;

    while(y){
        if(y&1) result = (long long)result *curr % mod;
        curr = ((long long) curr * curr) % mod;
        y >>= 1;
    }
    return result;
}

int main(){
    int n;
    cin >> n;

    cout << inverse(n) << endl;
    return 0;
}