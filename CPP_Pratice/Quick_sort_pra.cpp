
#include <bits/stdc++.h>
using namespace std;


int partition(int *arr,int left,int right){
    int pivot = arr[right];
    int index = left;
    int i;

    cout << "---partition---" << endl;
    for(int j=left; j<=right;j++){
        cout << arr[j] << " ";
    }

    for(i=left; i<=right;i++){        
        cout << endl;
        cout << i << " " << arr[i] << " " << pivot << endl;
        if(arr[i] < pivot){
            // temp = arr[index];
            // arr[index] = arr[i];
            // arr[i] =temp;
            // index++;
            cout << endl;
            cout << i << " " << index << " " << endl;
            swap(arr[i], arr[index++]);
            cout << i << " " << index << " " << endl;
        }
        cout << "--" << endl;
        for(int j=left; j<=right;j++){
            cout << arr[j] << " ";
        }
    }    
    cout << "=" << endl;
    cout << index << right << endl;
    swap(arr[index], arr[right]);

    for(int j=left; j<=right;j++){
        cout << arr[j] << " ";
    }
    cout << endl;


    return index;
}

void quicksort(int *arr, int left, int right){
    if (left < right){        
        int pivot = partition(arr, left, right);

        quicksort(arr, left, pivot-1);
        quicksort(arr, pivot+1, right);
    }

}

int main(){

    // int arr[] = {4, 3, 1, 2, 5, 9, 7, 10, 6};
    // 4 9 1 10 5 2 3 7 6
    int arr[] = {4, 9, 1, 10, 6, 2, 3, 7, 5};
    cout << sizeof(arr)/sizeof(arr[0]);  
    int n = sizeof(arr)/sizeof(arr[0]);  
    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    
    return 0;
}