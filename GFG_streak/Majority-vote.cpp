//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int cnt1 = 0, cnt2= 0;
        int ele1 = -1, ele2 = -1;
        for(int i=0; i < arr.size() ;i++){
            if(cnt1 == 0 && ele2 != arr[i]){
                cnt1 = 1;
                ele1 = arr[i];
            }
            else if(cnt2 == 0 && ele1 != arr[i]){
                cnt2 = 1;
                ele2 = arr[i];
            }
            else if(arr[i] == ele1){
                cnt1++;
            }
            else if(arr[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        // cout << cnt1 << cnt2 << endl;
        // cout << ele1 << ele2 << endl;
        cnt1 = 0, cnt2=0;
        for(int i=0; i < arr.size() ;i++){
            if(arr[i] == ele1){
                cnt1++;
            }

            if(arr[i] == ele2){
                cnt2++;
            }
        }
        int n = (int)arr.size()/3+1;
        arr.clear();
        cout << cnt1 << cnt2 << endl;
        if(cnt1>=n){
            if(cnt2>=n){                
                if(ele1 < ele2){
                    arr.push_back(ele1);
                    arr.push_back(ele2);
                    return arr;
                }
                else{                    
                    arr.push_back(ele2);
                    arr.push_back(ele1);
                    return arr;
                }
            }
            else{
                arr.push_back(ele1);
                return arr;
            }
        }
        else{
            return arr;
        }

        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends