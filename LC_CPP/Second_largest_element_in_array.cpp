#include<iostream>

using namespace std;


int second_largest_element_in_array(int *arr, int n){
    int first_largest = -1;
    int second_largest = -1;
    for(int i=0;i<n;i++){
        if(arr[i] > first_largest){
            second_largest = first_largest;
            first_largest = arr[i];
        }
        else if(arr[i] > second_largest && second_largest != first_largest){
            second_largest = arr[i];
        }
    }
    cout << "First largest : " << first_largest << endl;
    cout << "second largest : " << second_largest << endl;
}


int main(){
    int arr[100], n;
    cin >> n;
    for(int i=0;i<=n;i++){
        cin >> arr[i];
    }

    second_largest_element_in_array(arr, n);

}