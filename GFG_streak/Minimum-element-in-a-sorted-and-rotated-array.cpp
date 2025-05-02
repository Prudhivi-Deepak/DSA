//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here

        int n = arr.size();
        if(arr[0] < arr[n-1]){
            return arr[0];
        }
        else{
            int min = arr[n-1], i=0, j=n-1, mid;
            while(i <= j){
                mid = (i+j)/2;
                if(arr[mid] <= min){
                    min = arr[mid];
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
            return min;
        }

        // 13 3 5 7 9 11
        // 0  1 2 3 4 5
        
        //min = 11 
        // 0+5/2 = 2
        // 5 < 11 -> left sub array min =5 0 to 1
        // 0+1/2 = 0
        //  13 < 5 -> right sub array 1 to 1



        // 5 6 1 2 3 4
        
        // [0] >= [-1] rotation present - min value is in somewhere between [0] and [-1]
        // [0] < [-1]  rotation not present - min value is [0] - return [0]
        
        
        
        
        
        // 5 6 1 2 3 4
        // 0 1 2 3 4 5
        
        // 0+5/2 = 2
        //  1
        //  1 > left side element = false = go to left part of array
        // 0+1/2 = 0
        // 5 
        
        
        
        // 3 2 2 2
        
        // 4 4 4
        // 0 1 2
        
        // 0+2/2 = 1
        // 4 > left side element = 
        
         //              i i i i      i
        // 12 12 11 10 9 9 1 1 1 2 2  2  2  3  3  3  4  4  5  6  7  8  8  8
        // 0  1  2  3  4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
        
        // 0 to 23
        //  min = 8| 2
        // 0+23/2 = 11
        // 2 < 8 -> go to left sub array min = 2 0 to 10
        // j = 10
        // 
        // 0+10/2 = 5
        //  9 > 2 -> go to right sub array 6 to 10
        //  6+10/2 = 8
        //      1 < 2 -> go to left sub array min = 1 6 to 7
        // 6+7/2 = 6
        //      1 < 1 -> got to right sub array 7 to 7
        // 7+7/2 = 7
        //      1 < 1 -> go to right sub array 8 to 7

        // 8>7 retunr min
        
        
        
        
        
        // 1 1 1 2 2 2 3 3 3 3 4  4  5  6  7  8  8  8
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
        
        // (0+17)/2 = 8
        //  3
        // 
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends