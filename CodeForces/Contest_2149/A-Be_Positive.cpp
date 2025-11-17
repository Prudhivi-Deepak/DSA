#include<bits/stdc++.h>
using namespace std;

int countOperations(vector<int> arr){
    int count0 = 0, countneg1 = 0;
    for(auto i : arr){
        if(i==0) count0++;
        if(i==-1) countneg1++;
    }
    return count0 + (countneg1%2)*2;
}

int main(){
    int T, n;
    vector<int> arr;
    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << countOperations(arr) << endl;
        arr.clear();
    }
}