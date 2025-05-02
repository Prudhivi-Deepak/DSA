//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// 3
// 5 6 7 8 9 10 1 2 3
// 3
// 3 5 1 2
// 6
// 33 42 72 99
// 42

// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int i=0, n=arr.size(), j=n-1, mid, min_index=0;
        if(arr[i] >= arr[j]){
            int min = arr[n-1], i=0, j=n-1, mid;
            while(i <= j){
                mid = (i+j)/2;
                if(arr[mid] <= arr[min_index]){
                    min_index = mid;
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
        }

        // binary search left array
        i=0,j=min_index-1;
        while(i<=j){
            mid = (i+j)/2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] < key){
                i = mid+1;
            }
            else{ 
                j = mid-1;
            }
        }

        // bianary search in right array
        i = min_index, j = n-1;
        while(i<=j){
            mid = (i+j)/2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] < key){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends