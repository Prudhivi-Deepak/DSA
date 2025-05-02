//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:    

    int merge(vector<int> &arr, int l, int mid, int mid_1, int r, int count){

        vector<int> temp;       
        
        // cout << "first array : " << endl;
        // for (int i = l; i <= mid; i++)
        // {
        //     cout << arr[i] << " " ;
        // }
        
        // cout << "\nsecond array : " << endl;
        // for (int i = mid_1; i <= r; i++)
        // {
        //     cout << arr[i] << " " ;
        // }
        // cout << endl;

        int i = l;
        int j = mid_1;

        while(i <= mid || j <=r){
            // cout << "\nelement-e : " <<arr[i] << "|" << arr[j] << endl;
            if(i <= mid && j > r){
                temp.push_back(arr[i++]);
            }
            else if(j <= r && i > mid){
                temp.push_back(arr[j++]);
            }
            else if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                // cout << "\nelement : " <<arr[i] << "|" << arr[j] << endl;
                temp.push_back(arr[j++]);
                // cout << "mid-i : " << mid-i << endl;
                count += mid-i+1;
            }
        }

        int index =  0;

        for(int i=l; i<=r; i++){
            arr[i] = temp[index++];
        }
        // cout << endl;

        // for(auto i : arr){
        //     cout << i << " ";
        // }
        
        // cout << endl;

        return count;
    }

    int mergesort(vector<int> &arr, int l, int r, int count){

        if(l==r){
            return 0;
        }

        int mid = (l+r)/2;        
        int count1 = mergesort(arr, l, mid, count);
        int count2 = mergesort(arr, mid+1, r, count);

        return merge(arr, l, mid, mid+1, r, count1+count2);
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        // 2 4 1 3 5
        return mergesort(arr, 0, arr.size()-1, 0);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends