//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here

        priority_queue<int> pq; //max heap
        for(int i:arr){
            if(pq.size()==k ){
                if(pq.top()>i){
                    pq.pop();
                    pq.push(i);   
                }                         
            }
            else{
                pq.push(i);
            }
        }

        return pq.top();

    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

int main1(){
    int arr[8] = {15,5,20,1,17,16,30,8};
    int n = 8;
    int k = 5;

    // To find k th min value
    // max heap - 5 = k
    // 15 5 20 1 17 
    // 16
    // 15 5 20 1 17 -> 20 > 16 -> T --> push value smaller than max heap
    // 15 5 1 17 16
    // 30
    // 15 5 1 17 16 -> 17 > 30 -> F --> push value greater than max heap
    // 15 5 1 17 16
    // 8
    // 15 5 1 17 16 -> 17 > 8 -> T --> push value smaller than max heap
    // 15 5 1 16 8
    // no elements to push 
    // so pop first elements for max element
    // 15 5 1 16 8 -> 16

    // To find k th max value
    //min heap - 5 = k
    // 15 5 20 1 17 
    // 16
    // 15 5 20 1 17 -> 1 < 16 -> T --> push value is greater than min heap
    // 15 5 20 17 16
    // 30
    // 15 5 20 17 16 -> 5 < 30 -> T -> push value is greater than min heap
    // 15 20 17 16 30
    // 8
    // 15 20 17 16 30 -> 15 < 8 -> F -> push value is smaller than min heap
    // 15 20 17 16 30
    // no elements to push 
    // so pop first elements for min element
    // 15

    
    // sorted order =  1 5 8  15 16 17 20 30 
    // index        =  0 1 2  3  4  5  6  7
    // pos(k min)   =  1 2 3  4  5  6  7  8
    // pos(k max)   =  8 7 6  5  4  3  2  1
    // kth min = 16 (min heap of size k)
    // kth max = 15 (max heap of size k)


    

    for (int i:arr)
    {
        cout << i << " ";
    }

    
        
    return 0;
}