//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        // 1 1 2 2 2 2 3
        // 0 1 2 3 4 5 6
        
        // (0+6)/2 = 3
        // <= 2 go to left and go to right to count

        int i=0, j=arr.size()-1, mid, count=0, temp_mid;

        while(i<=j){
            mid = (i+j)/2;
            if(arr[mid]==target){
                temp_mid = mid-1;
                while(temp_mid >= i && arr[temp_mid] == target){
                    count++;
                    temp_mid--;
                }
                while(mid <= j && arr[mid] == target){
                    count++;
                    mid++;
                }
                return count;
            }
            else if(arr[mid] < target){
                i = ++mid;
            }
            else{
                j = --mid;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
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
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends