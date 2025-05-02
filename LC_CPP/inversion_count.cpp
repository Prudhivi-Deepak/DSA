//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    // int inversionCount(vector<int> &arr) {
        // Your Code Here
        // 2 4 1 3 5
        // 0 0 1 1 1
        
        //2, 3, 4, 5, 6
        // 0 0  0  0  0

        // 0 1 2 3 4 5 6 7 8 
        // 1 2 3 4 6 6 7 9 12

        //  
        // 

        //  0 1  2 3 4 5 6 7 8 
        //  6 12 7 1 3 6 9 4 2

        //  1 1  1 0 1 1 1 1
        //  1 1  1 0 0 1 1
        //  0 1  0 0 0 0
        //  0 1  1 0 0
        //  1 1  1 0
        //  1 1  1
        //  0 1
        //  0

        //  
        
    // }

    int merge(vector<int>& arr, int p, int r) 
    {
        int count = 0;
        if (p < r) 
        {
            int mid = (p + r) / 2;
            count += merge(arr, p, mid);        
            count += merge(arr, mid + 1, r);   
            count += mergeAndCountInversions(arr, p, mid, r);            
        }
        return count;
    }

    int mergeAndCountInversions(vector<int>& arr, int p, int mid, int r) {
        int n1 = mid - p + 1;
        int n2 = r - mid;

        vector<int> leftarr(n1);
        vector<int> rightarr(n2);

        for (int i = 0; i < n1; i++) 
        {
            leftarr[i] = arr[p + i];
        }
        for (int i = 0; i < n2; i++) 
        {
            rightarr[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = p, count = 0;
        while (i < n1 && j < n2) 
        {
            if (leftarr[i] <= rightarr[j]) 
            {
                arr[k] = leftarr[i];
                i++;
            } 
            else 
            {
                arr[k] = rightarr[j];
                count += (n1 - i);  
                j++;
            }
            k++;
        }

        while (i < n1) 
        { 
            arr[k] = leftarr[i];
            i++;
            k++;
        }

        while (j < n2) 
        { 
            arr[k] = rightarr[j];
            j++;
            k++;
        }

        return count;
    }


    int inversionCount(vector<int>& arr) 
    {
        return merge(arr, 0, arr.size() - 1);
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

int merge(vector<int> &arr, int l, int mid, int mid_1, int r, int count){

        vector<int> temp;       

        int i = l;
        int j = mid_1;

        while(i <= mid || j <=r){
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
                temp.push_back(arr[j++]);
                count += mid-i+1;
            }
        }

        int index =  0;

        for(int i=l; i<=r; i++){
            arr[i] = temp[index++];
        }

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