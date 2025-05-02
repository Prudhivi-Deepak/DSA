//{ Driver Code Starts
// here

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int i1=0,i2=0,i3=0,min_v;
        vector<int> ans;
        while(i1<arr1.size() && i2<arr2.size() && i3<arr3.size()){
            // cout << arr1[i1] << arr2[i2] << arr3[i3] << endl;


            if(arr1[i1] == arr2[i2] && arr2[i2] == arr3[i3]){
                // cout << "Equal : " << arr1[i1] << arr2[i2] << arr3[i3] << endl;
                if((ans.size()!=0 && ans[ans.size()-1] != arr1[i1]) || ans.size()==0){
                    ans.push_back(arr1[i1]);                    
                }
                i1++;i2++;i3++;
                continue;
            }

            min_v = arr1[i1];
            if(arr2[i2] <= min_v){
                min_v = arr2[i2];
            }

            if(arr3[i3] <= min_v){
                min_v = arr3[i3];
            }

            if(arr1[i1] == min_v){
                i1++;
            }

            if(arr2[i2] == min_v){
                i2++;
            }

            if(arr3[i3] == min_v){
                i3++;
            }
        }

        if(ans.size()==0){
            ans.push_back(-1);            
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr, crr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        string input3;
        getline(cin, input3);
        stringstream ss3(input3);
        int number3;
        while (ss3 >> number3) {
            crr.push_back(number3);
        }
        Solution ob;
        vector<int> res = ob.commonElements(arr, brr, crr);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl << "~\n";
    }
}
// } Driver Code Ends