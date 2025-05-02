#include <bits/stdc++.h>
using namespace std;

int checkclash(int *arr, int *dep, int i, int j){
    if((arr[i]<= arr[j] && arr[j] <=dep[i]) || (arr[i]<= dep[j] && dep[j] <= dep[i])) return true;
    return false;
}

int countPlatforms(int n, int *arr, int *dep){

    int currP=1, maxP = 1, i=1, j=0;

    sort(arr, arr+n);
    sort(dep, dep+n);

    while(i<n){
        if(arr[i] < dep[j]){
            currP++;
            i++;
        }
        else{
            currP--;
            j++;
        }
        maxP = max(maxP, currP);
    }

    return maxP;


    // int cnt=0, maxtracks = 0;
    // for(int i=0; i<n-1; i++){
    //     cnt = 0;
    //     for(int j=i+1; j<n; j++){
    //         if(checkclash(arr, dep, i, j)){
    //             cnt++;
    //         }
    //     }
    //     maxtracks = max(maxtracks, cnt);
    // }
    // return maxtracks+1;
}

int main()
{
   int arr[]={900,945,955,1100,1500,1800};
   int dep[]={920,1200,1130,1150,1900,2000};
   int n=sizeof(dep)/sizeof(dep[0]);
   cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
}