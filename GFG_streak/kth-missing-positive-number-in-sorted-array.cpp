//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// 3
// 2 3 4 7 11
// 5
// 1 2 3
// 2
// 3 5 9 10 11 12
// 2

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int kthMissing(vector<int> &arr, int k)
    {
        // Your code goes here

        int i = 0, j = arr.size() - 1, missing_count;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            int missing_count = arr[mid] - (mid + 1);
            if (missing_count < k)
                i = mid + 1;
            else
                j = mid - 1;
        }

        return i + k;
        // cout  << k <<endl;
        // 0 1 2 3 4  5 6 7 8 9 10 ...
        // 1 2 3 4 5 6 7 8 9 10 11....

        // 2 3 4 7 11
        // 1 2 3 4 5
        // 0 1 2 3 4

        // 0+4/2 = 2 => 4 (2+1=3) |  4-3 = 1 <= k(5) so go right
        // 3+4/2 = 3 => 7 (3+1=4) |  7-4 = 3 <= k(5) so go right
        // 4+4/2 = 4 =>11 (4+1=5) |  11-5 = 6 > k(5) so go left
        // 4 to 3 not possible

        // 11 10 9 8 7 6 5 4 3 2 1
        //    6  5 4   3 2       1

        // 1 2 3
        // 0 1 2

        // 0+2/2 = 1 (2<=2) | go to right
        // 2+2/2 = 2 (3<=3) && n == 2 | got to right n value + missing value count

        // 3 5 9 10 11 12 | k = 2
        // 0 1 2 3  4  5

        // 0+5/2 = 2 => 9 (2+1=3) | 9-3 = 6 > 2(k) so go to left
        // 0+1/2 = 1 => 5 (1+1=2) | 5-2 = 3 > 2(k) so go to left
        // 0+0/2 = 0 => 3 (0+1=1) | 3-1 = 2 <= 2 (k) so go to right

        // int i=0, n=arr.size(), j=n-1, mid, mid_value, actual_mid_value;
        // while(i<=j){
        //     mid = (i+j)/2;
        //     mid_value = arr[mid];
        //     actual_mid_value = mid+1;
        //     if(mid_value == actual_mid_value && mid == n-1){
        //         return mid_value+k;
        //     }

        //     if(mid_value <= )

        //     // if(arr[mid]-k == mid+1 && mid == n-1){
        //     //     return arr[n-1]+k;
        //     // }
        //     // if(arr[mid] <= mid+1)
        // }

        // return left index (4)

        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends