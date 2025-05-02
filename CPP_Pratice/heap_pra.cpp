#include<iostream>

using namespace std;

void heapify(int *arr, int i, int n){

    // 15, 5, 20, 1, 17, 16, 30
    // 1   2  3   4  5  6   7

    // n = 7 n//2 + 1 = 3+1 = 4

    // int i = (n/2 - 1);

    if(i<0){
        return;
    }


    int large_ind = i;
    int left_ind = 2*i + 1;
    int right_ind = 2*i + 2;

    if(left_ind < n){
        if(arr[left_ind] > arr[large_ind]){
            large_ind = left_ind;
        }
        }

    if(right_ind < n){
        if(arr[right_ind] > arr[large_ind]){
            large_ind = right_ind;
        }
    }

    // swaping parent and large
    if(large_ind != i){
        int temp = arr[large_ind];
        arr[large_ind] = arr[i];
        arr[i] = temp;
        if((2*large_ind)+1 < n || (2*large_ind)+2 < n) {
            heapify(arr, large_ind, n);
        }     
    }

    heapify(arr, i-1, n);
}

int main(){
    int arr[8] = {15,5,20,1,17,16,30,8};
    int n = 8;
    // for (int i = n/2 - 1; i >= 0; i--)
    // {
        //2 1 0
    heapify(arr, n/2, n);
    // }

    for (int i:arr)
    {
        cout << i << " ";
    }

    for(int i=0; i< n ; i++){
        int temp = arr[0];
        arr[0] = arr[n-i-1];
        arr[n-i-1] = temp;
        heapify(arr, (n-i-1)/2, n-i-1);
    }
    cout << endl;

    for (int i:arr)
    {
        cout << i << " ";
    }

    
        
    return 0;
}